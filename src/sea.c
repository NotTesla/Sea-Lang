#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

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

char to_hex(int v) {
    if (v < 10) {
        return '0' + v;
    } else {
        return 'A' + v - 10;
    }
}

// TODO: finish this
char* bin_to_hex(const char* bin_str) {
    const int bin_len = strlen(bin_str) - 2;
    const int len = (bin_len - 1) / 4;
    const int hex_len = len + len % 4;

    char* hex_str = (char*) calloc(hex_len + 3, sizeof(char));
    char* hex_char = hex_str;

    *(hex_char++) = '0';
    *(hex_char++) = 'x';

    bin_str += 1;

    int hex = 0, count = 0, index = hex_len - 1;
    for (int i = 0; i < bin_len; ++i) {
        hex |= (bin_str[bin_len - i] == '1') ? (1 << count) : 0x0;
        ++count;

        if (count == 4) {
            hex_char[index--] = to_hex(hex);
            count = hex = 0;
        }
    }

    if (count > 0) {
        hex_char[index] = to_hex(hex);
    }

    // int v = 0;
    // int count = 0;
    // int i;
    // int cindex = hex_len-1;
    // for (i = hex_len - 1; i > 1; --i) {
    //     v |= (bin_str[i] == '1') ? (1 << count) : 0x0;
    //     ++count;

    //     if (count == 4) {
    //         hex_str[cIndex--] = to_hex(v);

    //         count = v = 0;
    //     }
    // }

    // if (count != 0) {
    //     hex_str[(i - 2) / 4 + 2] = to_hex(v);
    // }

    return hex_str;
}
