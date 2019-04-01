#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "yyparser.h"

#include "sea.h"

#define SNNULL ((struct SeaNode*)0)

#define YYACCEPT 1
#define YYABORT 0

FILE *in, *out;

int main(int argc, char** argv) {

    in = fopen(argv[1], "r");

    if (yyparse() == YYACCEPT) {

    }
}

struct SeaNode* sea_node_alloc() {
    struct SeaNode* node = (struct SeaNode*)malloc(sizeof(struct SeaNode));
    assert (node != SNNULL);
    return node;
}

void error_bad_token(const char* tok) {
    fprintf(stderr, "Sea E: Unrecognized Input Token (%s)\n", tok);
}

void yyerror(const char* msg) {
    fprintf(stderr, "Sea E: %s\n", msg);
}

int yywrap(void) {
    return 0;
}
