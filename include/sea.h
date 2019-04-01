#ifndef __SEA_H__
#define __SEA_H__

typedef struct sea_node_t {
    int v;

} SeaNode;

SeaNode* sea_node_alloc();

//SeaNode* 

int yylex(void);
void error_bad_token(const char *tok);
void yyerror(const char* msg);
int yywrap(void);

#endif // __SEA_H__
