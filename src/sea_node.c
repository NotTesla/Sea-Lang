#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include "sea_node.h"

enum seavalue_e {
    SVL_TOKEN,
    SVL_STRING,
    SVL_CHILDREN,
    SVL_EPSILON,
};

union seavalue_u {
    int token;
    char* string;
    struct SeaNode** children;
};

struct seavalue_t {
    enum seavalue_e type;
    union seavalue_u data;
};

struct SeaNode {
    enum NonTerminal type;
    // TODO: replace this with SeaValue for identifiers/qstrings
    struct seavalue_t val;
};

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
        if (child->val.type == SVL_EPSILON) {
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

void sn_free(struct SeaNode* node) {

    // TODO: use stack<struct SeaNode*> instead of recursion

    if (node->val.type == SVL_CHILDREN) {
        struct SeaNode* next;
        size_t index = 0;
        while ((next = node->val.data.children[index]) != SNNULL) {
            sn_free(next);
        }

    }
    else if (node->val.type == SVL_STRING) {
        free(node->val.data.string);
    }

    free(node);
}

struct SeaNode* sn_alloc_wtok(enum NonTerminal id, int tok) {
    return SNNULL;
}

struct SeaNode* sn_alloc_wstr(enum NonTerminal id, char* str) {
    return SNNULL;
}

struct SeaNode* sn_epsilon() {
    return SNNULL;
}
