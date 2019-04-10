#ifndef __SEA_NODE_H__
#define __SEA_NODE_H__

#include "sea_str.h"

#define EPSILON ((struct SeaNode*)0)

// id: `NonTerminal`
// ...: `SeaNode*`+ SNNULL
// allocates a node, stores a null terminated array of children
// returns the allocated node
struct SeaNode* sea_nonterm(struct SeaStr str, struct SeaNode* next);

struct SeaNode* sea_term(struct SeaStr str);

struct SeaNode* sea_cterm(const char* str);

// returns the epsilon seanode
struct SeaNode* sea_epsilon();

void sn_free(struct SeaNode* node);

#endif // __SEA_NODE_H__
