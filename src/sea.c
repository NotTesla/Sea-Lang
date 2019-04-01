#include <stdlib.h>
#include <stdio.h>

#include "yyparser.h"

#include "sea.h"


#define YYACCEPT 1
#define YYABORT 0

FILE *in, *out;

int main(int argc, char** argv) {

    in = fopen(argv[1], "r");

    if (yyparse() == YYACCEPT) {

    }
}

void error_bad_token(const char* tok) {
    fprintf(stderr, "Unrecognized Input Token (%s)\n", tok);
}

void yyerror(const char* msg) {
    fprintf(stderr, "E: Sea %s\n", msg);
}

int yywrap(void) {
    return 0;
}
