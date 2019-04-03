#include <assert.h>
#include <stdlib.h>
#include "sea_stack.h"
#include "sea_internal.h"

SN_Stack* sn_stack_alloc(const size_t size) {
    struct SN_Stack* stack = (SN_Stack*) malloc(sizeof(SN_Stack));
    assert(stack != (SN_Stack*)0);

    stack->index = 0;
    stack->size = size;
    stack->data = (SeaNode**)malloc(sizeof(SeaNode*) * stack->size);

    return stack;
}

void sn_stack_free(struct SN_Stack* stack) {
    free(stack->data);
    free(stack);
}

void sn_push(SN_Stack* stack, SeaNode* node) {
    
    stack->data[++stack->index] = node;
    if (stack->size == stack->index) {
        stack->size *= stack->size;
        stack->data = (SeaNode**)realloc(stack->data, sizeof(SeaNode*) * stack->size);
        assert(stack->data != (SeaNode**)0);
    }
}

SeaNode* sn_pop(SN_Stack* stack) {
    return stack->data[stack->index--];
}

SeaNode* sn_top(const SN_Stack* stack) {
    return stack->data[stack->index];
}
