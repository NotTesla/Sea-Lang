#include "sea_str.h"

#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRLEN 20

static inline struct SeaStr sea_str_init(enum SeaStrMem alloc, char* str) {
    struct SeaStr s;
    s.alloc = alloc;
    s.s = str;

    return s;
}

struct SeaStr sea_hstr(char* str, ...) {

    size_t buff_len = 2;
    char* arr[ARRLEN];

    va_list args;
    va_start(args, str);

    int index = 0;
    do {
        buff_len += strlen(str);
        if (CHEAP == str[0]) {
            --buff_len;
        }

        arr[index++] = str;

    } while((str = va_arg(args, char*)) != NULL);

    va_end(args);

    char* buff = (char*)calloc(sizeof(char), buff_len);
    buff[0] = CHEAP;
    for(int i = 0; i < index; ++i) {
        if (CHEAP == arr[i][0]) {
            strcat(&buff[1], &arr[i][1]);
            free(arr[i]);
        } else {
            strcat(&buff[1], arr[i]);
        }
    }

    return sea_str_init(STR_HEAP, buff);
}

struct SeaStr sea_tstr(char* str) {
    return sea_str_init(STR_TOKEN, str);
}

struct SeaStr sea_cstr(const char* str) {
    return sea_str_init(STR_CONST, (char*)str);
}

void sea_str_free(struct SeaStr* str, ...) {
    va_list args;
    va_start(args, str);

    struct SeaStr* s;
    while((s = va_arg(args, struct SeaStr*)) != NULL) {
        if (s->alloc == STR_HEAP) {
            free(s->s);
        }
    }

    va_end(args);
}
