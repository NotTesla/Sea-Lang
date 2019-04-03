#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "yyparser.h"

#include "sea.h"

#define YYACCEPT 0
#define YYABORT 1
#define YYNOMEM 2

#define DBG_SEA(MSG) "Sea D: " MSG "\n"
#define ERR_SEA(MSG) "Sea E: " MSG "\n"

FILE *out;

int main(int argc, char** argv) {

    char const*const infile = argv[1];
    char const*const outfile = argv[2];

    yyin = fopen(infile, "r");
    if (yyin == NULL) {
        fprintf(stderr, ERR_SEA("Could not open file [%s]"), infile);
    }

    int parse = yyparse();
    fprintf(stdout, DBG_SEA("Parse completed with return value %d"), parse);
    fclose(yyin);

    switch (parse) {
        case YYACCEPT: {
            fprintf(stdout, DBG_SEA("Writing translation to [%s]"), outfile);
            out = fopen(outfile, "w");
            // TODO: get compiled program from sea_node.c
            fclose(out);
        }
            break;
        case YYABORT:
            fprintf(stderr, ERR_SEA("Failed to parse input"));
            break;
        case YYNOMEM:
            fprintf(stderr, ERR_SEA("Exhausted memory"));
            break;
    }
}

void error_bad_token(const char* tok) {
    fprintf(stderr, ERR_SEA("Unrecognized input token [%s]"), tok);
}

void yyerror(const char* msg) {
    fprintf(stderr, ERR_SEA("%s"), msg);
}

int yywrap(void) {
    return 1;
}
