id [a-zA-Z_][a-zA-Z0-9_]*
hex_num 0x[0-9A-Fa-f]+
bin_num 0b[01]+
dec_num [0-9]*(\.[0-9]+(e(\+|\-)[0-9]+)?)?
str \"[^\"]*\"
single_line_comment \/\/[^\n\r]*
single_char_punc [-+*/%^|!&;,()\[\].<>]
whitespace [ \t]|(\r?\n)

%{
#include <stdio.h>
#include <string.h>
#include "yyparser.h"
#include "sea.h"
#include "sea_str.h"
#include "sea_scope.h"

// define `DEBUG_SCANNER` to print each token
// as it's scanned from the input file
// #define DEBUG_SCANNER
static inline void debug(const char* text) {
#ifdef DEBUG_SCANNER
    printf("%s", text);
#endif
}

static inline struct SeaStr copy_token(const char* yytext) {
    return sea_tstr(strcpy((char*)malloc(sizeof(char) * strlen(yytext) + 1), yytext));
}

// sets yylval to a token containing the scanned string
#define COPY_STRTOK(STR) (yylval.str = copy_token(STR));

%}

%x COMMENT

%%

<INITIAL>{single_line_comment} { debug(yytext); }

<INITIAL>"#include <".+".h>"\r?\n { debug(yytext); COPY_STRTOK(yytext); return CINCLUDE; }
<INITIAL>"i8"   { debug(yytext); return I8; }
<INITIAL>"i16"  { debug(yytext); return I16; }
<INITIAL>"i32"  { debug(yytext); return I32; }
<INITIAL>"i64"  { debug(yytext); return I64; }

<INITIAL>"u8"   { debug(yytext); return U8; }
<INITIAL>"u16"  { debug(yytext); return U16; }
<INITIAL>"u32"  { debug(yytext); return U32; }
<INITIAL>"u64"  { debug(yytext); return U64; }

<INITIAL>"f32"  { debug(yytext); return F32; }
<INITIAL>"f64"  { debug(yytext); return F64; }

<INITIAL>"word"     { debug(yytext); return WORD; }
<INITIAL>"cstr"     { debug(yytext); return CSTR; }
<INITIAL>"bool"     { debug(yytext); return BOOL; }
<INITIAL>"true"     { debug(yytext); return TRUE; }
<INITIAL>"false"    { debug(yytext); return FALSE; }
<INITIAL>"psize"    { debug(yytext); return PSIZE; }
<INITIAL>"void"     { debug(yytext); return VOID; }

<INITIAL>"cap"  { debug(yytext); return CAP; }
<INITIAL>"mut"  { debug(yytext); return MUT; }
<INITIAL>"ret"  { debug(yytext); return RET; }
<INITIAL>"if"   { debug(yytext); return IF; }
<INITIAL>"else" { debug(yytext); return ELSE; }

<INITIAL>"..." { debug(yytext); return VARGS; }

<INITIAL>"==" { debug(yytext); return IS_EQ; }
<INITIAL>"!=" { debug(yytext); return NOT_EQ; }
<INITIAL>"<=" { debug(yytext); return LESS_EQ; }
<INITIAL>">=" { debug(yytext); return MORE_EQ; }

<INITIAL>"+=" { debug(yytext); return ADD_EQ; }
<INITIAL>"-=" { debug(yytext); return SUB_EQ; }
<INITIAL>"*=" { debug(yytext); return MUL_EQ; }
<INITIAL>"/=" { debug(yytext); return DIV_EQ; }
<INITIAL>"%=" { debug(yytext); return MOD_EQ; }

<INITIAL>"<<=" { debug(yytext); return SHL_EQ; }
<INITIAL>">>=" { debug(yytext); return SHR_EQ; }
<INITIAL>"&=" { debug(yytext); return AND_EQ; }
<INITIAL>"|=" { debug(yytext); return OR_EQ; }
<INITIAL>"^=" { debug(yytext); return XOR_EQ; }

<INITIAL>{id}       { debug(yytext); COPY_STRTOK(yytext); return IDENTIFIER; }
<INITIAL>{hex_num}  { debug(yytext); COPY_STRTOK(yytext); return NUMBER; }
<INITIAL>{bin_num}  { debug(yytext); yylval.str = sea_tstr(bin_to_hex(yytext)); return NUMBER; }
<INITIAL>{dec_num}  { debug(yytext); COPY_STRTOK(yytext); return NUMBER; }
<INITIAL>{str}      { debug(yytext); COPY_STRTOK(yytext); return QSTRING; }

<INITIAL>"{"    { debug(yytext); sea_push_block(); return *yytext; }
<INITIAL>"}"    { debug(yytext); sea_pop_block(); return *yytext; }

<INITIAL>{single_char_punc} { debug(yytext); return *yytext; }
<INITIAL>{whitespace}       { debug(yytext); }

<INITIAL>. { error_bad_token(yytext); }

%%
