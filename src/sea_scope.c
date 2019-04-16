#include "sea_scope.h"
#include "sea_debug.h"
#include "sea_str.h"

#include <stdio.h>
#include <stdlib.h>

#define ID_BUFFER_LEN 100
#define SEA_FN "_SEA_"

struct SeaFrame {
    char id[ID_BUFFER_LEN];
    struct SeaFrame* prev;
};

struct SeaFrame base_frame
    = {.id="",.prev = NULL};

struct SeaFrame* stack = &base_frame;

// call this when a block is detected
// id: a label for the stack frame
void sea_push_block() {

    struct SeaFrame* prev = stack;
    stack = (struct SeaFrame*)malloc(sizeof(struct SeaFrame));
    stack->prev = prev;

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
    free(stack);
    stack = prev;
}

void sea_vardecl(char* type, char* id) {
    // TODO: we'll need this later to implement lambda captures
}

void sea_fndecl(char* id, char* type, char* params) {
    
    sea_hstr(type, sea_getfndecl(id), "(", params, ")", NULL);

    // sea_fndecl(sea_getfndecl());

}

void sea_fnanon(char* type, char* params) {

    // static unsigned long long anon_id = 0;

    printf("%s", type);
    printf("%s", params);

}

char* sea_getfndecl(char* id) {

    return id;

}
