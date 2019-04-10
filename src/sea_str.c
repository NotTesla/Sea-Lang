#include "sea_str.h"
#include "sea_node.h"
#include "sea_internal.h"
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRLEN 10

inline struct SeaStr sea_str_init(enum SeaStrMem alloc, char* str) {
    struct SeaStr s;
    s.alloc = alloc;
    s.str = str;

    return s;
}

struct SeaStr sea_hstr(struct SeaNode* node, ...) {

    size_t buff_len = 1;
    struct SeaNode* arr[ARRLEN];

    va_list args;
    va_start(args, node);

    int index = 0;
    struct SeaNode* node;
    while((node = va_arg(args, struct SeaNode*)) != NULL) {
        buff_len += strlen(node->string.str);
        arr[index++] = node;
    }

    va_end(args);

    char* buff = (char*)calloc(buff_len, sizeof(char));
    for(int i = 0; i < index; ++i) {
        strcat(buff, arr[i]->string.str);
        sn_free(arr[i]);
    }

    return sea_str_init(HEAP, buff);
}

struct SeaStr sea_tstr(char* str) {
    return sea_str_init(TOKEN, str);
}

struct SeaStr sea_cstr(const char* str) {
    return sea_str_init(CONST, (char*)str);
}

void sea_str_free(struct SeaStr* str, ...) {
    va_list args;
    va_start(args, str);

    struct SeaStr* s;
    while((s = va_arg(args, struct SeaStr*)) != NULL) {
        if (s->alloc == HEAP) {
            free(s->str);
        }
    }

    va_end(args);
}
