#include "sea_translator.h"
#include "sea_internal.h"
#include "sea_debug.h"
#include "sea_stack.h"

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

struct LinkStr {
    const char* str;
    struct LinkStr* next;
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
