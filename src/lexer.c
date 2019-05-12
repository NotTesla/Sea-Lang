#include "lexer.h"
#include "yyparser.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define TOKALLOC 256
#define LINEALLOC 512

struct lexer {
    FILE* file;
    size_t tlen;
    size_t tcap;
    char* token;
    int line_index;
    char line[LINEALLOC];
    int last_char;
    size_t line_number;
};

typedef struct Token {
    int id;
    char* prod;
} TOK;

void lex_tok(LEX* lexer, unsigned char c) {
    lexer->token[lexer->tlen++] = c;
    if (lexer->tlen >= lexer->tcap) {
        lexer->tcap *= 2;
        lexer->token = realloc(lexer->token, lexer->tcap * sizeof(char));
    }
    lexer->token[lexer->tlen] = '\0';
}

LEX* lex_with_file(FILE* input) {
    LEX* lexer = malloc(sizeof(LEX));
    *lexer = (LEX){
        .file=input,
        .tlen=0,
        .tcap=TOKALLOC,
        .token=malloc(TOKALLOC * sizeof(char)),
        .line_index=0,
        .line={0},
        .last_char=-1,
        .line_number=1,
    };
    lexer->token[0] = '\0';
    return lexer;
}

int lex_next_char(LEX* lexer) {
    int c = (int)lexer->line[lexer->line_index++];
    if (c != '\0') {
        lexer->last_char = c;
        return c;
    }

    char* out = fgets(lexer->line, LINEALLOC, lexer->file);
    if (out != NULL) {
        lexer->line_index = 1;
        lexer->last_char = (int)lexer->line[0];
        return lexer->last_char;
    }

    return EOF;
}

int parse_punc(LEX* lexer, TOK tokens, ...) {
    TOK* productions[10];
    int len = 0;
    va_list args;

    va_start(args, tokens);
    do {
        productions[len++] = &tokens;
        tokens = va_arg(args, TOK);
    } while (tokens.prod[0]=='\0');
    productions[len++] = &tokens;

    va_end(args);

    int reduce = EOF;
    int ptr = 0;
    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        int rem = 0;

        for (int i = 0; i < len; ++i) {
            if (productions[i] == NULL) continue;

            ++rem;
            char shift = productions[i]->prod[ptr];
            if (shift == '\0') {
                reduce = (int)productions[i]->id;
            }
            if (shift != c) {
                productions[i] = NULL;
            }
        }

        if (rem == 0) {
            break;
        }
        ++ptr;
    }

    return reduce;
}

void parse_comment(LEX* lexer, char* term) {
    int ptr = 0;
    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        if (c == '\n') {
            ++lexer->line_number;
        }
        if (c == term[ptr++]) {
            if (term[ptr] == '\0') {
                return;
            }
        } else {
            ptr = 0;
        }
    }
}

int parse_slash(LEX* lexer) {
    int c = lex_next_char(lexer);
    lexer->last_char = -1;

    switch(c) {
    case '/':
        parse_comment(lexer, "\n");
        return -1;
    case '*':
        parse_comment(lexer, "*/");
        return -1;
    case '=':
        return DIV_EQ;
    default:
        return '/';
    }
}

int parse_id(LEX* lexer) {
    lex_tok(lexer, lexer->last_char);
    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        if (isalnum(c) || c == '_') {
            lex_tok(lexer, c);
        } else {
            break;
        }
    }

    return IDENTIFIER;
}

int parse_keyword_id(LEX* lexer) {

    return IDENTIFIER;
}

void parse_dec(LEX* lexer) {
    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        if (isdigit(c)) {
            lex_tok(lexer, c);
        } else {
            return;
        }
    }
}

void parse_hex(LEX* lexer) {
    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        if (isxdigit(c)) {
            lex_tok(lexer, c);
        } else {
            return;
        }
    }
}

void parse_bin(LEX* lexer) {
    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        if (c == '0' || c == '1') {
            lex_tok(lexer, c);
        } else {
            return;
        }
    }
}

int parse_number(LEX* lexer) {

    int c = lexer->last_char;
    lex_tok(lexer, c);
    if (c == '0') {
        c = lex_next_char(lexer);
        if (c == 'b') {
            lex_tok(lexer, c);
            parse_bin(lexer);
        }
        else if (c == 'x') {
            lex_tok(lexer, c);
            parse_hex(lexer);
        }
        else if (isdigit(c)) {
            parse_dec(lexer);
        }
    } else {
        parse_dec(lexer);
    }

    return NUMBER;
}

int parse_qstring(LEX* lexer) {
    lex_tok(lexer, '"');
    lexer->last_char = -1;

    int c;
    while ((c = lex_next_char(lexer)) != EOF) {
        if (c == '\n') {
            return 0; // error parsing
        }
        lex_tok(lexer, c);
        if (c == '"') {
            return QSTRING;
        }
    }

    return 0; // error
}

int lex_next_token(LEX* lexer) {
    if (lexer == NULL) {
        return EOF;
    }

    lexer->tlen = 0;
    lexer->token[0] = '\0';

    int c = lexer->last_char;
    if (c == -1) {
        c = lex_next_char(lexer);
        if (c == EOF) return EOF;
    }

    do {
        if (isalpha(c)) {
            parse_keyword_id(lexer);
        }

        if (isdigit(c)) {
            parse_number(lexer);
        }

        switch(c) {
        case '_':
            return parse_id(lexer);
        case '"':
            return parse_qstring(lexer);
        case '.':
            return parse_punc(lexer, (TOK){VARGS,".."}, (TOK){'.',""}, NULL);
        case '=':
            return parse_punc(lexer, (TOK){IS_EQ,"="}, (TOK){'=',""}, NULL);
        case '!':
            return parse_punc(lexer, (TOK){NOT_EQ,"="}, (TOK){'!',""}, NULL);
        case '+':
            return parse_punc(lexer, (TOK){ADD_EQ,"="}, (TOK){'+',""}, NULL);
        case '-':
            return parse_punc(lexer, (TOK){SUB_EQ,"="}, (TOK){'-',""}, NULL);
        case '*':
            return parse_punc(lexer, (TOK){MUL_EQ,"="}, (TOK){'*',""}, NULL);
        case '/': {
            int ret = parse_slash(lexer);
            if (ret > 0) {
                return ret;
            }
        }
        case '%':
            return parse_punc(lexer, (TOK){MOD_EQ,"="}, (TOK){'%',""}, NULL);
        case '<':
            return parse_punc(lexer, (TOK){SHL_EQ,"<="}, (TOK){LESS_EQ,"="}, (TOK){'<',""}, NULL);
        case '>':
            return parse_punc(lexer, (TOK){SHR_EQ,">="}, (TOK){MORE_EQ,"="}, (TOK){'>',""}, NULL);
        case '&':
            return parse_punc(lexer, (TOK){AND_EQ,"&"}, (TOK){AND_EQ,"="}, (TOK){'&',""}, NULL);
        case '|':
            return parse_punc(lexer, (TOK){OR_EQ,"|"}, (TOK){OR_EQ,"="}, (TOK){'|',""}, NULL);
        case '^':
            return parse_punc(lexer, (TOK){XOR_EQ,"="}, (TOK){'^',""}, NULL);
        case '\n':
            ++lexer->line_number;
        case ' ':
        case '\t':
            continue;
        case '{':
        case '}':
        case ';':
        case ',':
        case '(':
        case ')':
        case '[':
        case ']':
            return c;
        }

        return 0; // unrecognized token
    } while ((c = lex_next_char(lexer)) != EOF);

    free(lexer->token);
    free(lexer);

    return EOF;
}
