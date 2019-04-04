#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "sea_node.h"
#include "sea_stack.h"
#include "sea_internal.h"
#include "sea_debug.h"

struct SeaNode EPSILON;

struct SeaNode* sn_alloc(
    enum NonTerminal nonterminal,
    /* struct SeaNode* children */ ...) {

    struct SeaNode* node
        = (struct SeaNode*) malloc(sizeof(struct SeaNode));
    assert (node != SNNULL);

    size_t size = 4, index = 0;

    node->type = nonterminal;
    node->val.type = SVL_CHILDREN;
    node->val.data.children
        = (struct SeaNode**) malloc(sizeof(struct SeaNode*) * size);
    assert(node->val.data.children != ((struct SeaNode**)0));

    va_list args;
    va_start(args, nonterminal);

    struct SeaNode* child;
    while ((child = va_arg(args, struct SeaNode*)) != SNNULL) {
        // don't add to the list if epsilon
        if (child == &EPSILON) {
            continue;
        }

        node->val.data.children[index++] = child;
        if (index >= size) {
            size *= 2;
            node->val.data.children
                = (struct SeaNode**) realloc(node->val.data.children, sizeof(struct SeaNode*) * size);
            assert (node->val.data.children != ((struct SeaNode**)0));
        }
    }

    node->val.data.children[index] = child;

    va_end(args);
    
    return node;
}

struct SeaNode* sn_alloc_wtok(enum NonTerminal id, int tok) {
    struct SeaNode* node
        = (struct SeaNode*) malloc(sizeof(struct SeaNode));
    assert (node != SNNULL);

    node->type = id;
    node->val.type = SVL_TOKEN;
    node->val.data.token = tok;

    return node;
}

struct SeaNode* sn_alloc_wstr(enum NonTerminal id, char* str) {
    struct SeaNode* node
        = (struct SeaNode*) malloc(sizeof(struct SeaNode));
    assert (node != SNNULL);

    node->type = id;
    node->val.type = SVL_STRING;
    node->val.data.string = str;

    return node;
}

struct SeaNode* sn_epsilon() {
    return &EPSILON;
}

void sn_free(struct SeaNode* node) {

    // TODO: benchmark stack-based algorithm
    struct SN_Stack* stack = sn_stack_alloc(10);
    struct SN_Frame frame = (struct SN_Frame) {
        .child_index = 0,
        .node = node,
    };
    sn_push(stack, frame);

    while (stack->index > 0) {
        node = sn_top(stack)->node;
        switch(node->val.type) {
        case SVL_CHILDREN: {
            struct SeaNode* next;
            if ((next = node->val.data.children[sn_top(stack)->child_index++]) != SNNULL) {
                frame.child_index = 0;
                frame.node = next;
                sn_push(stack, frame);
            }
            else {
                // only free this node once all of it's children have been freed
                free(node->val.data.children);
                free(sn_pop(stack)->node);
            }
            continue;
        }
        case SVL_STRING: {
            // free the string contained by the node, then free the node
            free(node->val.data.string);
            free(sn_pop(stack)->node);
            break;
        }
        case SVL_TOKEN: {
            // free the node
            free(sn_pop(stack)->node);
            break;
        }
        default:
            stack->index = 0;
            fprintf(stderr, SEA_ERR("Node with value type [%d] has no `free` handler"), node->val.type);
        }
    }

    sn_stack_free(stack);

    // TODO: benchmark recursive algorithm
    // if (node->val.type == SVL_CHILDREN) {
    //     struct SeaNode* next;
    //     size_t index = 0;
    //     while ((next = node->val.data.children[index++]) != SNNULL) {
    //         sn_free(next);
    //     }
    // }
    // else if (node->val.type == SVL_STRING) {
    //     free(node->val.data.string);
    // }

    // free(node);

    return;
}
