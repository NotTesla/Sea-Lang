#ifndef SEA_LEXER_H
#define SEA_LEXER_H

#include <stdio.h>

typedef struct lexer LEX;

// initialize a lexer with a file
LEX* lex_with_file(FILE*);

// retrieve the next token
// return token id, or EOF at end of input
int lex_next_token(LEX*);

#endif // SEA_LEXER_H
