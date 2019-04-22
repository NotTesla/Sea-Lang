#ifndef __SEA_SCOPE_H__
#define __SEA_SCOPE_H__

#include "sea_str.h"

// call this when a block is detected
// id: a label for the stack frame
void sea_push_block();

void sea_pop_block();

void sea_vardecl(char* type, char* id);

struct SeaStr sea_fndecl(char* type, char* id, char* params);

void sea_fnanon(char* type, char* params);

struct SeaStr sea_getfndecl(char* id);

#endif // __SEA_SCOPE_H__
