#include "sea_scope.h"
#include "sea_debug.h"
#include "sea_str.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ID_BUFFER_LEN 100
#define SEA_FN "_SEA_fn_"

struct SeaFrame {
    char id[ID_BUFFER_LEN];
    int fn_len;
    char** fn;
    struct SeaFrame* prev;
};

struct SeaFrame* stack = NULL;

// call this when a block is detected
// id: a label for the stack frame
void sea_push_block() {

    struct SeaFrame* prev = stack;
    stack = (struct SeaFrame*)malloc(sizeof(struct SeaFrame));
    stack->prev = prev;
    stack->fn_len = 10;
    stack->fn = (char**)calloc(sizeof(char*), stack->fn_len);

    if (prev == NULL) {
        stack->id[0] = '\0';
        return;
    }

    static unsigned long long block_id = 0;

    int len = snprintf(
        stack->id, ID_BUFFER_LEN,
        "%s%llx", prev->id, block_id++);

    if (len > ID_BUFFER_LEN) {
        fprintf(stderr, SEA_DBG("block id exceeded buffer limit (%d)"), len);
    }
}

void sea_pop_block() {
    struct SeaFrame* prev = stack->prev;
    free(stack->fn);
    free(stack);
    stack = prev;
}

void sea_vardecl(char* type, char* id) {
    // TODO: we'll need this later to implement lambda captures
}

struct SeaStr sea_fndecl(char* type, char* id, char* params) {
    if (stack == NULL) {
        sea_push_block();
    }

    struct SeaStr fn_decl;
    if (stack->prev != NULL) {
        char** fn = stack->fn;
        while (*fn != NULL) {
            if (strcmp(*fn, id) == 0) {
                break;
            }
            ++fn;
        }
        *fn = malloc(strlen(id) + 1);
        strcpy(*fn, id);
        fn_decl = sea_hstr(type, " ", sea_getfndecl(id).s, "(", params, ")", NULL);
    } else {
        fn_decl = sea_hstr(type, " ", id, "(", params, ")", NULL);
    }

    return fn_decl;
}

void sea_fnanon(char* type, char* params) {

    // static unsigned long long anon_id = 0;

    printf("%s", type);
    printf("%s", params);

}

struct SeaStr sea_getfndecl(char* id) {

    struct SeaFrame* frame = stack;

    do {
        char** fn = stack->fn;

        while (*fn != NULL) {
            if (strcmp(*fn, id) == 0) {
                return sea_hstr(SEA_FN, stack->id, id, NULL);
            }
            ++fn;
        }
    } while ((frame = frame->prev) != NULL);

    return sea_hstr(id, NULL);
}
