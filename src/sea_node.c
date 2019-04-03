#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

#include "sea_node.h"
#include "sea_stack.h"
#include "sea_internal.h"

SeaNode* EPSILON = (SeaNode*)0;

SeaNode* sn_alloc(
    enum NonTerminal nonterminal,
    /* SeaNode* children */ ...) {

    SeaNode* node
        = (SeaNode*) malloc(sizeof(SeaNode));
    assert (node != SNNULL);

    size_t size = 4, index = 0;

    node->type = nonterminal;
    node->val.type = SVL_CHILDREN;
    node->val.data.children
        = (SeaNode**) malloc(sizeof(SeaNode*) * size);
    assert(node->val.data.children != ((SeaNode**)0));

    va_list args;
    va_start(args, nonterminal);

    SeaNode* child;
    while ((child = va_arg(args, SeaNode*)) != SNNULL) {
        // don't add to the list if epsilon
        if (child == EPSILON) {
            continue;
        }

        node->val.data.children[index++] = child;
        if (index >= size) {
            size *= 2;
            node->val.data.children
                = (SeaNode**) realloc(node->val.data.children, sizeof(SeaNode*) * size);
            assert (node->val.data.children != ((SeaNode**)0));
        }
    }

    node->val.data.children[index] = child;

    va_end(args);
    
    return node;
}

SeaNode* sn_alloc_wtok(enum NonTerminal id, int tok) {
    SeaNode* node
        = (SeaNode*) malloc(sizeof(SeaNode));
    assert (node != SNNULL);

    node->type = id;
    node->val.type = SVL_TOKEN;
    node->val.data.token = tok;

    return node;
}

SeaNode* sn_alloc_wstr(enum NonTerminal id, char* str) {
    SeaNode* node
        = (SeaNode*) malloc(sizeof(SeaNode));
    assert (node != SNNULL);

    node->type = id;
    node->val.type = SVL_STRING;
    node->val.data.string = str;

    return node;
}

SeaNode* sn_epsilon() {
    // if epsilon isn't allocted, create one and return it
    // note that epsilon isn't a valid SeaNode, it's just a pointer const
    if (EPSILON == (SeaNode*)0) {
        EPSILON = (SeaNode*) malloc(sizeof(char));
        assert (EPSILON != SNNULL);
    }

    return EPSILON;
}

void sn_free(SeaNode* node) {

    // TODO: use stack<SeaNode*> instead of recursion
    // SN_Stack* stack = sn_stack_alloc(10);
    // sn_push(stack, node);

    // while (stack->index > 0) {
    //     node = sn_top(stack);
    //     printf("enter %d\n", node->type);
    //     if (node->val.type == SVL_CHILDREN) {
    //         SeaNode* next;
    //         size_t index = 0;
    //         while ((next = node->val.data.children[index++]) != SNNULL) {
                // TODO: this algorithm will not work, `index` must be set on `sn_top(stack)`
    //             sn_push(stack, next);
    //             continue;
    //         }
    //     }
    //     else if (node->val.type == SVL_STRING) {
    //         free(node->val.data.string);
    //     }
    //     printf("free %d\n", node->type);
    //     free(sn_pop(stack));
    // }

    if (node->val.type == SVL_CHILDREN) {
        SeaNode* next;
        size_t index = 0;
        while ((next = node->val.data.children[index++]) != SNNULL) {
            sn_free(next);
        }
    }
    else if (node->val.type == SVL_STRING) {
        free(node->val.data.string);
    }

    free(node);

    return;
}
