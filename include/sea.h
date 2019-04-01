#ifndef __SEA_H__
#define __SEA_H__

struct SeaTree {
    const char** includes;
    struct SeaNode* tree;
};

struct SeaNode {
    int id;
    struct SeaNode* parent;
    struct SeaNode** children;
};

struct SeaNode* sea_node_alloc();

void sea_tree_free(struct SeaTree*);

void error_bad_token(const char *tok);

int yylex(void);
void yyerror(const char* msg);
int yywrap(void);

#endif // __SEA_H__
