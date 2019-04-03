#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "yyparser.h"
#include "sea_debug.h"

#include "sea.h"

#define YYACCEPT 0
#define YYABORT 1
#define YYNOMEM 2

int main(int argc, char** argv) {

    char const*const infile = argv[1];
    char const*const outfile = argv[2];

    yyin = fopen(infile, "r");
    if (yyin == NULL) {
        fprintf(stderr, SEA_ERR("Could not open file [%s]"), infile);
    }

    int parse = yyparse();
    fprintf(stdout, SEA_DBG("Parse completed with return value %d"), parse);
    fclose(yyin);

    switch (parse) {
        case YYACCEPT: {
            fprintf(stdout, SEA_DBG("Writing translation to [%s]"), outfile);
            FILE* out = fopen(outfile, "w");
            sea_write_translation(out);
            fclose(out);
            break;
        }
        case YYABORT:
            fprintf(stderr, SEA_ERR("Failed to parse input"));
            break;
            
        case YYNOMEM:
            fprintf(stderr, SEA_ERR("Exhausted memory"));
            break;
    }
}

void error_bad_token(const char* tok) {
    fprintf(stderr, SEA_ERR("Unrecognized input token [%s]"), tok);
}

void yyerror(const char* msg) {
    fprintf(stderr, SEA_ERR("%s"), msg);
}

int yywrap(void) {
    return 1;
}
