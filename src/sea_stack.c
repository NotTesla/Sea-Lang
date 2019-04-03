#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "sea_stack.h"
#include "sea_internal.h"

struct SN_Stack* sn_stack_alloc(const size_t size) {
    struct SN_Stack* stack = (struct SN_Stack*) malloc(sizeof(struct SN_Stack));
    assert(stack != (struct SN_Stack*)0);

    stack->index = 0;
    stack->size = size;
    stack->data = (struct SN_Frame*)malloc(sizeof(struct SN_Frame) * stack->size);
    assert(stack->data != (struct SN_Frame*)0);

    return stack;
}

void sn_stack_free(struct SN_Stack* stack) {
    free(stack->data);
    free(stack);
}

void sn_push(struct SN_Stack* stack, struct SN_Frame node) {
    stack->data[++stack->index] = node;
    if (stack->index == (stack->size - 1)) {
        stack->size *= 2;
        stack->data = (struct SN_Frame*)realloc(stack->data, sizeof(struct SN_Frame) * stack->size);
        assert(stack->data != (struct SN_Frame*)0);
    }
}

struct SN_Frame* sn_pop(struct SN_Stack* stack) {
    struct SN_Frame* frame = stack->data + stack->index;
    --stack->index;
    return frame;
}

struct SN_Frame* sn_top(const struct SN_Stack* stack) {
    return stack->data + stack->index;
}
