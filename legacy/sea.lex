import java_cup.runtime.*;
%%

%implements Scanner
%type Symbol
%function next_token
%class SeaScanner
%eofval{ return null;
%eofval}

WHITESPACE = " "|\n|\r|\t

%state MULTI_COMMENT, SINGLE_COMMENT, INCLUDE

%%
<YYINITIAL>"/*" { yybegin(MULTI_COMMENT); }
<MULTI_COMMENT>"*/" { yybegin(YYINITIAL); }
<MULTI_COMMENT>.|\r|\n { }

<YYINITIAL>"//" { yybegin(SINGLE_COMMENT); }
<SINGLE_COMMENT>\r|\n { yybegin(YYINITIAL); }
<SINGLE_COMMENT>. { }

<YYINITIAL>"imp" { yybegin(INCLUDE); }
<INCLUDE>[^\r\n]*(\r|\n) { yybegin(YYINITIAL); return new Symbol(SeaSymbol.INCLUDE, yytext()); }

<YYINITIAL>\"[^\"]*\" { return new Symbol(SeaSymbol.QSTRING, yytext());}

<YYINITIAL>i64 { return new Symbol(SeaSymbol.I64); }
<YYINITIAL>i32 { return new Symbol(SeaSymbol.I32); }
<YYINITIAL>i16 { return new Symbol(SeaSymbol.I16); }
<YYINITIAL>i8 { return new Symbol(SeaSymbol.I8); }

<YYINITIAL>u64 { return new Symbol(SeaSymbol.U64); }
<YYINITIAL>u32 { return new Symbol(SeaSymbol.U32); }
<YYINITIAL>u16 { return new Symbol(SeaSymbol.U16); }
<YYINITIAL>u8 { return new Symbol(SeaSymbol.U8); }

<YYINITIAL>f64 { return new Symbol(SeaSymbol.F64); }
<YYINITIAL>f32 { return new Symbol(SeaSymbol.F32); }

<YYINITIAL>usize { return new Symbol(SeaSymbol.USIZE); }

<YYINITIAL>wchar { return new Symbol(SeaSymbol.WIDE_CHAR); }

<YYINITIAL>fn { return new Symbol(SeaSymbol.FN); }
<YYINITIAL>struct { return new Symbol(SeaSymbol.STRUCT); }
<YYINITIAL>static { return new Symbol(SeaSymbol.STATIC); }
<YYINITIAL>mut { return new Symbol(SeaSymbol.MUT); }
<YYINITIAL>let { return new Symbol(SeaSymbol.LET); }
<YYINITIAL>return { return new Symbol(SeaSymbol.RETURN); }
<YYINITIAL>if { return new Symbol(SeaSymbol.IF); }
<YYINITIAL>else { return new Symbol(SeaSymbol.ELSE); }
<YYINITIAL>"{" { return new Symbol(SeaSymbol.BEGIN); }
<YYINITIAL>"}" { return new Symbol(SeaSymbol.END); }

<YYINITIAL>[a-zA-Z_][a-zA-Z0-9_]* { return new Symbol(SeaSymbol.ID, yytext());}
<YYINITIAL>0x[0-9A-F]+ { return new Symbol(SeaSymbol.NUM, yytext()); }
<YYINITIAL>0b[01]+ { return new Symbol(SeaSymbol.NUM, yytext()); }
<YYINITIAL>[0-9]+(\.[0-9]+)? { return new Symbol(SeaSymbol.NUM, yytext()); }

<YYINITIAL>"(" { return new Symbol(SeaSymbol.LPAREN); }
<YYINITIAL>")" { return new Symbol(SeaSymbol.RPAREN); }
<YYINITIAL>";" { return new Symbol(SeaSymbol.SEMICOLON); }
<YYINITIAL>"," { return new Symbol(SeaSymbol.COMMA); }
<YYINITIAL>"+" { return new Symbol(SeaSymbol.PLUS); }
<YYINITIAL>"-" { return new Symbol(SeaSymbol.MINUS); }
<YYINITIAL>"*" { return new Symbol(SeaSymbol.STAR); }
<YYINITIAL>"/" { return new Symbol(SeaSymbol.DIVIDE); }
<YYINITIAL>"=" { return new Symbol(SeaSymbol.ASSIGN); }
<YYINITIAL>"&" { return new Symbol(SeaSymbol.GETPTR); }
<YYINITIAL>":" { return new Symbol(SeaSymbol.COLON); }
<YYINITIAL>"." { return new Symbol(SeaSymbol.DOT); }
<YYINITIAL>"!" { return new Symbol(SeaSymbol.NOT); }
<YYINITIAL>"~" { return new Symbol(SeaSymbol.COMPLEMENT); }
<YYINITIAL>"->" { return new Symbol(SeaSymbol.DEREF); }
<YYINITIAL>"<<" { return new Symbol(SeaSymbol.SHL); }
<YYINITIAL>">>" { return new Symbol(SeaSymbol.SHR); }
<YYINITIAL>"==" { return new Symbol(SeaSymbol.EQUALITY); }
<YYINITIAL>"!=" { return new Symbol(SeaSymbol.NEQUALITY); }

<YYINITIAL>{WHITESPACE} {  }
<YYINITIAL>. { return new Symbol(SeaSymbol.error); }
