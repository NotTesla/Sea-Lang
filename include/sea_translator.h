#ifndef __SEA_COMPILER_H__
#define __SEA_COMPILER_H__

#include <stdio.h>
#include "sea_str.h"

struct SeaNode;

void sea_translate(struct SeaNode* program);

void sea_write_translation(FILE* out);

// call this when a block is detected
// id: a label for the stack frame
void sea_push_block(char* id);

void sea_pop_block();

void sea_vardecl(char* type, char* id);

void sea_fndecl(char* type, char* id, char* params);

char* sea_getfndecl(char* id);

struct SeaStr sea_fint(int term);

#endif // __SEA_COMPILER_H__
