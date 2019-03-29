_id [a-zA-Z_][a-zA-Z0-9_]*
_num 0x[0-9A-Fa-f]+|0b[01]+|[0-9]*(\.[0-9]+)?
_str \"[^\"]*\"

%{
#include <stdio.h>
#include "symbol.h"

void count();
%}

%x COMMENT

%%

<INITIAL>i64 { count(); return I64; }
<INITIAL>i32 { count(); return I32; }
<INITIAL>i16 { count(); return I32; }
<INITIAL>i8 { count(); return I32; }

<INITIAL>u64 { count(); return U64; }
<INITIAL>u32 { count(); return U32; }
<INITIAL>u16 { count(); return U16; }
<INITIAL>u8 { count(); return U8; }

<INITIAL>UPTR { count(); return UPTR; }
<INITIAL>WCHR { count(); return WCHR; }

<INITIAL>f64 { count(); return F64; }
<INITIAL>f32 { count(); return F32; }

<INITIAL>inc { count(); return INC; }
<INITIAL>cdef { count(); return CDEF; }
<INITIAL>rdef { count(); return RDEF; }

<INITIAL>fun { count(); return FUN; }
<INITIAL>struct { count(); return STRUCT; }
<INITIAL>mut { count(); return MUT; }
<INITIAL>let { count(); return LET; }
<INITIAL>ret { count(); return RET; }
<INITIAL>if { count(); return IF; }
<INITIAL>else { count(); return ELSE; }
<INITIAL>for { count(); return FOR; }
<INITIAL>do { count(); return DO; }
<INITIAL>while { count(); return WHILE; }

<INITIAL>"{" { count(); return OB; }
<INITIAL>"}" { count(); return CB; }
<INITIAL>"(" { count(); return OP; }
<INITIAL>")" { count(); return CP; }

<INITIAL>{_id} { count(); return ID; }
<INITIAL>{_num} { count(); return NUM; }
<INITIAL>{_str} { count(); return STRING; }

<INITIAL>";" { count(); return SEMICOLON; }
<INITIAL>"," { count(); return COMMA; }
<INITIAL>"+" { count(); return ADD; }
<INITIAL>"-" { count(); return MIN; }
<INITIAL>"*" { count(); return MULT; }
<INITIAL>"/" { count(); return DIV; }
<INITIAL>"=" { count(); return ASSIGN; }
<INITIAL>":" { count(); return COLON; }
<INITIAL>"!" { count(); return DOT; }
<INITIAL>"?" { count(); return QMARK; }
<INITIAL>"~" { count(); return COMPLEMENT; }
<INITIAL>"<<" { count(); return SHL; }
<INITIAL>">>" { count(); return SHR; }
<INITIAL>"==" { count(); return EQUALITY; }
<INITIAL>"!=" { count(); return NEQUALITY; }

<INITIAL>"+=" { count(); return ADD_EQ; }
<INITIAL>"-=" { count(); return MIN_EQ; }
<INITIAL>"*=" { count(); return MUL_EQ; }
<INITIAL>"/=" { count(); return DIV_EQ; }

<INITIAL>"<<=" { count(); return SHL_EQ; }
<INITIAL>">>=" { count(); return SHR_EQ; }

<INITIAL>. { count(); return ERROR; }
