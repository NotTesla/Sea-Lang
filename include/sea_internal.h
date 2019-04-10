#ifndef __SEA_INTERNAL_H__
#define __SEA_INTERNAL_H__

#include "sea_node.h"
#include "sea_str.h"
#include <stddef.h>

struct SeaNode {
    struct SeaStr string;
    struct SeaNode* next;
};

struct SN_Stack {
    size_t index;
    size_t size;
    struct SeaNode* data;
};

#endif // __SEA_INTERNAL_H__
