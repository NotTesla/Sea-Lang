#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include "sea_node.h"

#define SNPTR struct SeaNode*
#define SNNULL ((struct SeaNode*)0)

struct SeaNode* sea_node_alloc(
    enum SeaNT nonterminal,
    /* struct SeaNode* children */ ...) {

    struct SeaNode* node = (SNPTR) malloc(sizeof(struct SeaNode));
    assert (node != SNNULL);

    node->sea_type = nonterminal;

    size_t size = 4;

    node->children = (SNPTR*) malloc(sizeof(SNPTR) * size);
    assert(node->children != ((struct SeaNode**)0));

    size_t index = 0;

    va_list args;
    va_start(args, nonterminal);

    struct SeaNode* child;
    while ((child = va_arg(args, SNPTR)) != SNNULL) {
        node->children[index++] = child;
        if (index >= size) {
            size *= 2;
            node->children = (SNPTR*) realloc(node->children, sizeof(SNPTR) * size);
            assert (node->children != ((struct SeaNode**)0));
        }
    }

    node->children[index] = child;

    va_end(args);

    return node;
}
