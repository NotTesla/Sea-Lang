#ifndef __SEA_NODE_H__
#define __SEA_NODE_H__

#define SNNULL ((struct SeaNode*)0)

// SNT (sea non-terminals)
enum NonTerminal {
    SNT_PROGRAM,
    SNT_GLOBAL,
    SNT_METHOD,
    SNT_TYPE,
    SNT_FUNC,
    SNT_FUNC_DEF,
    SNT_FUNC_DECL,
    SNT_PARAMS,
    SNT_PARAM,
    SNT_BLOCK,
    SNT_STATEMENTS,
    SNT_FUNC_CALL,
    SNT_CALL_PARAMS,
    SNT_RETURN_STMT,
    SNT_EXPRESSION,
};

// id: `NonTerminal`
// ...: `SeaNode*`+ SNNULL
// allocates a node, stores a null terminated array of children
// returns the allocated node
// TODO: consider passing the len as an argument...... this could potentially
// reduce calls to realloc
struct SeaNode* sn_alloc(enum NonTerminal id, /* struct SeaNode* children */ ...);

// id: `NonTerminal`
// tok: the token associated with this node
struct SeaNode* sn_alloc_wtok(enum NonTerminal id, int tok);

// id: `Terminal`
// str: the string associated with this node
struct SeaNode* sn_alloc_wstr(enum NonTerminal id, char* str);

// don't alloc, just have a global epsilon struct
struct SeaNode* sn_epsilon();

void sn_free(struct SeaNode* node);

#endif // __SEA_NODE_H__
