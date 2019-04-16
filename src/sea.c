#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "yyparser.h"
#include "sea_debug.h"
#include "sea_translator.h"

#include "sea.h"

#define YYACCEPT 0
#define YYABORT 1
#define YYNOMEM 2

int main(int argc, char** argv) {

    char const*const infile = argv[1];
    char const*const outfile = argv[2];

    yyin = fopen(infile, "r");
    if (yyin == NULL) {
        fprintf(stderr, SEA_ERR("Could not open file (%s)"), infile);
    }

    int parse = yyparse();
    fprintf(stdout, SEA_DBG("Parse completed with return value %d"), parse);
    fclose(yyin);

    switch (parse) {
        case YYACCEPT: {
            fprintf(stdout, SEA_DBG("Writing translation to (%s)"), outfile);
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
    fprintf(stderr, SEA_ERR("Unrecognized input token (%s)"), tok);
}

void yyerror(const char* msg) {
    fprintf(stderr, SEA_ERR("%s"), msg);
}

int yywrap(void) {
    return 1;
}

char to_hex(int v) {
    if (v < 10) {
        return '0' + v;
    } else {
        return 'A' + v - 10;
    }
}

char* bin_to_hex(char const* bin_str) {
    unsigned long long val = 0;

    bin_str += 2;
    do {
        val <<= 1;

        if (*bin_str == '1') {
            val |= 1;
        }
    } while (*++bin_str != '\0');

    const int len = 100;
    char* hex_str = (char*)malloc(len * sizeof(char));

    //sprintf(hex_str, "0x%llX", val);
    hex_str[0] = '0';
    hex_str[1] = '\0';
    return hex_str;
}
