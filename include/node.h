#ifndef NODE_H
#define NODE_H

typedef struct ast_node NODE;

struct Token {
    unsigned int row;
    unsigned int col;
};

NODE* node_with_tok_line();

#endif // NODE_H
