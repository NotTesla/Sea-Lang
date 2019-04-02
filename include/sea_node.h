#ifndef __SEA_NODE_H__
#define __SEA_NODE_H__

// SNT (sea non-terminals)
enum SeaNT {
    SNT_PROGRAM,
    SNT_METHOD,
    SNT_TYPE,
    SNT_FUNC
};

struct SeaNode {
    enum SeaNT sea_type;
    struct SeaNode** children;
};

// non-terminal id `SeaNT`
// `SNNULL`-terminated list of `SeaNode`s
struct SeaNode* seanode_alloc(enum SeaNT id, /* struct SeaNode* children */ ...);

#endif // __SEA_NODE_H__
