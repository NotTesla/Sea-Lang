#include "sea_translator.h"
#include "sea_debug.h"
#include "yyparser.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum includes {
    inc_stdint,
    inc_stdio,
    inc_num,
};

int includes[] = {
    [inc_stdint] = 0,
    [inc_stdio] = 0,
};

const char* INCLUDE[] = {
    [inc_stdint] = "<stdint.h>",
    [inc_stdio]  = "<stdio.h>",
};

#define DEP_SEA 0
#define DEP_C   1

typedef struct Dep {
    const char* file;
    int type;
    struct Dep* next;
} Dep;

// TODO: these should be linked lists
char* forward_decls[10] = { NULL };
char* func_defs[10] = { NULL };
Dep* dependencies = NULL;
// - - -

void sea_write_translation(FILE* out) {
    for (int i = 0; i < inc_num; ++i) {
        if (includes[i])
            fprintf(out, "#include %s\n", INCLUDE[i]);
    }

    Dep* d = dependencies;
    while (d != NULL) {
        if (d->type == DEP_SEA) {
            fputs("#define SEA_HEADER\n", out);
            fprintf(out, "#include \"%s.h\"\n", d->file);
        } else {
            fprintf(out, "#include %s\n", d->file);
        }
        d = d->next;
    }

    fputs("// headers\n\n", out);
    {
        char** f = forward_decls;
        while (*f != NULL) {
            fprintf(out, "%s;\n\n", *f);
            ++f;
        }
    }

    fputs("// source\n", out);
    fputs("#ifndef SEA_HEADER\n\n", out);

    {
        char** f = func_defs;
        while (*f != NULL) {
            fprintf(out, "%s\n", *f);
            ++f;
        }
    }

    fputs("\n#undef SEA_HEADER\n", out);
    fputs("#endif // SEA_HEADER\n", out);
}

void sea_c_dep(const char* file) {
    Dep* prev = dependencies;
    dependencies = malloc(sizeof(Dep));
    *dependencies = (Dep) {.file=file,.type=DEP_C,.next=prev};
}

void sea_sea_dep(const char* file) {
    Dep* prev = dependencies;
    dependencies = malloc(sizeof(Dep));
    *dependencies = (Dep) {.file=file,.type=DEP_SEA,.next=prev};
}

void sea_forward_decl(const char* decl) {
    char** f = forward_decls;
    while(*f++ != NULL);
    --f;
    *f = malloc(sizeof(char) * (strlen(decl) + 1));
    strcpy(*f, decl);
}

void sea_func_def(const char* def) {
    char** f = func_defs;
    while (*f++ != NULL);
    --f;
    *f = malloc(sizeof(char) * (strlen(def) + 1));
    strcpy(*f, def);
}

struct SeaStr sea_fint(int type) {
    includes[inc_stdint] = 1;
    switch(type) {
    case I8:
        return sea_cstr("int8_t");
    case I16:
        return sea_cstr("int16_t");
    case I32:
        return sea_cstr("int32_t");
    case I64:
        return sea_cstr("int64_t");
    case U8:
        return sea_cstr("uint8_t");
    case U16:
        return sea_cstr("uint16_t");
    case U32:
        return sea_cstr("uint32_t");
    case U64:
        return sea_cstr("uint64_t");
    default:
        fprintf(stderr, SEA_DBG("unrecognized fixed-with type id (%d)"), type);
        return sea_cstr("int");
    }
}
