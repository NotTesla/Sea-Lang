#include <stdlib.h>
#include <stdio.h>

#include "sea_node.h"
#include "sea_stack.h"
#include "sea_internal.h"
#include "sea_debug.h"

struct SeaNode* sea_nonterm(struct SeaStr str, struct SeaNode* next) {

    struct SeaNode* node
        = (struct SeaNode*) malloc(sizeof(struct SeaNode));
    assert (node != NULL);

    node->string = str;
    node->next = next;

    return node;
}

struct SeaNode* sea_term(struct SeaStr str) {
    
    struct SeaNode* node
        = (struct SeaNode*) malloc(sizeof(struct SeaNode));
    assert (node != NULL);

    node->string = str;
    node->next = EPSILON;

    return node;
}

struct SeaNode* sea_cterm(const char* str) {
    struct SeaNode* node
        = (struct SeaNode*) malloc(sizeof(struct SeaNode));
    assert (node != NULL);

    node->string.alloc = CONST;
    node->string.str = str;
    node->next = EPSILON;

    return node;
}

struct SeaNode* sea_epsilon() {
    return EPSILON;
}

void sn_free(struct SeaNode* node) {

    struct SN_Stack* stack = sn_stack_alloc(10);
    sn_push(stack, node);

    while (stack->index > 0) {
        node = sn_top(stack);
        if (node->string.alloc == HEAP) {
            free(node->string.str);
        }

        if (node->next != EPSILON && node->next != NULL) {
            struct SeaNode* frame = node->next;
            sn_push(stack, frame);
            node->next = EPSILON;
            continue;
        }
        else {
            // only free this node once all of it's children have been freed
            free(sn_pop(stack));
        }
    }

    sn_stack_free(stack);

    return;
}
