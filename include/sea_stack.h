#ifndef __SEA_STACK_H__
#define __SEA_STACK_H__

struct SN_Stack;
struct SN_Frame;

struct SN_Stack* sn_stack_alloc(const size_t size);

void sn_stack_free(struct SN_Stack* stack);

// push a node onto the stack
void sn_push(struct SN_Stack* stack, struct SN_Frame node);

// pop the top node off of the stack and return it
struct SN_Frame* sn_pop(struct SN_Stack* stack);

// get the node on the top of the stack
struct SN_Frame* sn_top(const struct SN_Stack* stack);

#endif // __SEA_STACK_H__