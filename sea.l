id [a-zA-Z_][a-zA-Z0-9_]*
num 0x[0-9A-Fa-f]+|0b[01]+|[0-9]*(\.[0-9]+(e(\+|\-)[0-9]+)?)?
str \"[^\"]*\"
single_line_comment \/\/[^\n\r]*
single_char_punc [-+*/;,{}()\[\]]
whitespace [ \t\n\r]

%{
#include <stdio.h>
#include "yyparser.h"
#include "sea.h"

// define `DEBUG_SCANNER` to print each token
// as it's scanned from the input file
#define DEBUG_SCANNER
static inline void debug(const char* text) {
#ifdef DEBUG_SCANNER
    printf("%s", text);
#endif
}

%}

%x COMMENT

%%

<INITIAL>{single_line_comment} { debug(yytext); }

<INITIAL>"#include"([^\n\r]*[\n\r]) { debug(yytext); }
<INITIAL>"int" { debug(yytext); return INT; }
<INITIAL>"void" { debug(yytext); return VOID; }
<INITIAL>"return" { debug(yytext); return RETURN; }

<INITIAL>{id} { debug(yytext); yylval.s = yytext; return IDENTIFIER; }
<INITIAL>{str} { debug(yytext); yylval.s = yytext; return STR; }

<INITIAL>{single_char_punc} { debug(yytext); return *yytext; }
<INITIAL>{whitespace} { debug(yytext); }

<INITIAL>. { error_bad_token(yytext); }

%%
