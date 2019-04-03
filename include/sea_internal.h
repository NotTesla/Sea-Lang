#ifndef __SEA_INTERNAL_H__
#define __SEA_INTERNAL_H__

#include "sea_node.h"
#include <stddef.h>

enum seavalue_e {
    SVL_TOKEN,
    SVL_STRING,
    SVL_CHILDREN,
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


struct SN_Frame {
    size_t child_index;
    struct SeaNode* node;
};

struct SN_Stack {
    size_t index;
    size_t size;
    struct SN_Frame* data;
};

#endif // __SEA_INTERNAL_H__