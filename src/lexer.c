#include "lexer.h"
#include <stdlib.h>

struct lexer {
    FILE* file;
};

LEX* lex_with_file(FILE* input) {
    LEX* lexer = malloc(sizeof(LEX));
    *lexer = (LEX){.file=input};
    return lexer;
}

int lex_next_token(LEX* lexer) {

    while(1) {
        // - get next token from lexer
        // - parse it, drop it into a switch/case
        // - return an id if appropriate
        // - else repeat the loop (on things like tab, new line, etc)
        return EOF;
    }
}
