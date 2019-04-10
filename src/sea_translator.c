#include "sea_translator.h"
#include "sea_internal.h"
#include "sea_debug.h"
#include "sea_stack.h"
#include "yyparser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Includes {
    INC_STDINT  = 0x0001,
    INC_STDIO   = 0x0002,
    INC_STDDEF  = 0x0004,
    INC_STDMATH = 0x0008,

    INC_LEN     = 4,
};

const char* INCLUDE_STRS[] = {
    "#include <stdint.h>",
    "#include <stdio.h>",
    "#include <stddef.h>",
    "#include <stdmath.h>",
};

struct Program {
    enum Includes flags;
    struct LinkStr* func_decl;
    struct LinkStr* func_def;
} program;

void sea_translate(struct SeaNode* tree) {

    program.flags = 0;

    // switch/case `program->type`
    // struct SN_Stack* stack = sn_stack_alloc(10);
    // struct SN_Frame frame = (struct SN_Frame) {
    //     .child_index = 0,
    //     .node = tree,
    // };
    // sn_push(stack, frame);

    // while (stack->index > 0) {
    //     struct SeaNode* node = sn_top(stack)->node;
    //     switch(node->type) {
    //     case SNT_PROGRAM: {
    //         program.flags |= INC_STDIO;
    //         break;
    //     }
    //     case SNT_TYPE: {
    //         sea_type(&program, );
    //         program.flags |= INC_STDINT;

    //         break;
    //     }
    //     case SNT_FUNC: {

    //         break;
    //     }
    //     default:
    //         fprintf(stderr, SEA_ERR("Cannot translate undefined non-terminal (%d)"), node->type);
    //     }
    // }

    // // free the stack, and the nodes
    // sn_stack_free(stack);
    sn_free(tree);
}

void sea_write_translation(FILE* out) {
    // write includes to the file
    for (int i = 0; i < INC_LEN; ++i) {
        if (program.flags & (1 << i)) {
            char const*const include = INCLUDE_STRS[i];
            fwrite(include, sizeof(char), strlen(include), out);
        }
    }

    // write all function declarations to the file
    {
        // struct LinkStr* node = program.func_decl;
        // while (node != (struct LinkStr*)0) {
        //     fwrite(node->str, sizeof(char), strlen(node->str), out);
        //     node = node->next;

        //     free(node->str);
        //     free(node);
        // }
    }

    // write all function definitions

}

char const*const fwidth_ints[] {
    [I8]    = "int8_t",
    [I16]   = "int16_t",
    [I32]   = "int32_t",
    [I64]   = "int64_t",
    [U8]    = "uint8_t",
    [U16]   = "uint16_t",
    [U32]   = "uint32_t",
    [U64]   = "uint64_t",
};

struct SeaStr sea_fint(int term) {
    program.flags |= INC_STDINT;

    return sea_cstr(fwidth_ints[term]);
}

#define ID_BUFFER_LEN 100

struct SeaFrame {
    char id[ID_BUFFER_LEN];
    struct SeaFrame* prev;
};

struct SeaFrame base_frame
    = {.id="",.prev = NULL};

struct SeaFrame* stack = &base_frame;

// call this when a block is detected
// id: a label for the stack frame
void sea_push_block(char* id) {
    struct SeaFrame* prev = stack;
    stack = (struct SeaFrame*)malloc(sizeof(struct SeaFrame));
    stack->prev = prev;

    struct SeaFrame* this = stack;
    int len = 0;
    while (this != NULL) {
        len += snprintf(&stack->id[len], ID_BUFFER_LEN, "%s", this->id);
        if (len >= ID_BUFFER_LEN) {
            fprintf(stderr, SEA_ERR("Identifier longer than 100 characters %s"), this->id);
            stack->id[ID_BUFFER_LEN - 1] = '\0';
            break;
        }

        this = this->prev;
    }
}

void sea_pop_block() {
    struct SeaFrame* prev = stack->prev;
    free(stack);
    stack = prev;
}

void sea_vardecl(char* type, char* id) {

}

void sea_fndecl(char* type, char* id, char* params) {

}

char* sea_getfndecl(char* id) {

}