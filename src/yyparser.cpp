// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 1 "sea.y" // lalr1.cc:404

#include "sea.h"
#include "sea_translator.h"
#include "sea_scope.h"
#include <string>

#define EPSILON (sea_cstr(""))

#line 45 "./src/yyparser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "yyparser.hpp"

// User implementation prologue.

#line 59 "./src/yyparser.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 126 "./src/yyparser.cpp" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 8:
#line 65 "sea.y" // lalr1.cc:859
    {
        sea_c_dep(&(yystack_[0].value.str).s[1]);
        (yylhs.value.str) = EPSILON;
    }
#line 554 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 70 "sea.y" // lalr1.cc:859
    {
        sea_sea_dep(&(yystack_[0].value.str).s[1]);
        (yylhs.value.str) = EPSILON;
    }
#line 563 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 77 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 569 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 78 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I8); }
#line 575 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 79 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I16); }
#line 581 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 80 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I32); }
#line 587 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 81 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I64); }
#line 593 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 82 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I8); }
#line 599 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 83 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I16); }
#line 605 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 84 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I32); }
#line 611 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 85 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_fint(I64); }
#line 617 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 86 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("float"); }
#line 623 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 87 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("double"); }
#line 629 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 88 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("int"); }
#line 635 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 89 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("unsigned int"); }
#line 641 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 90 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("const char*"); }
#line 647 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 91 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("char"); }
#line 653 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 92 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("size_t"); }
#line 659 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 93 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("void"); }
#line 665 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 97 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 671 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 98 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_cstr("void"); }
#line 677 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 103 "sea.y" // lalr1.cc:859
    {
        struct SeaStr decl = sea_fndecl((yystack_[0].value.str).s, (yystack_[5].value.str).s, (yystack_[2].value.str).s);
        sea_forward_decl(&decl.s[1]);
        (yylhs.value.str) = std::string(decl.s);
    }
#line 687 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 111 "sea.y" // lalr1.cc:859
    { sea_func_def(&sea_hstr((yystack_[2].value.str).s, (yystack_[0].value.str).s, NULL).s[1]); }
#line 693 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 119 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[1].value.str) + (yystack_[0].value.str).s; }
#line 699 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 120 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = "void"; }
#line 705 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 124 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = ", " + (yystack_[1].value.str) + (yystack_[0].value.str)); }
#line 711 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 125 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = ""; }
#line 717 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 129 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_hstr((yystack_[1].value.str).s, " ", (yystack_[2].value.str).s, "...", NULL); }
#line 723 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 130 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_hstr((yystack_[0].value.str).s, " ", (yystack_[1].value.str).s, NULL); }
#line 729 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 131 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 735 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 135 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_hstr("{\n", (yystack_[1].value.str).s, "}\n", NULL); }
#line 741 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 139 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_hstr((yystack_[1].value.str).s, "\n", (yystack_[0].value.str).s, NULL); }
#line 747 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 140 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = EPSILON; }
#line 753 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 144 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = EPSILON; }
#line 759 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 145 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = EPSILON; }
#line 765 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 146 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = sea_hstr((yystack_[1].value.ing).s, ";", NULL); }
#line 771 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 147 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.ing); }
#line 777 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 148 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 783 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 152 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = sea_hstr(sea_getfndecl((yystack_[3].value.str).s).s, "(", (yystack_[1].value.ing).s, ")", NULL); }
#line 789 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 156 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = sea_hstr((yystack_[1].value.str).s, (yystack_[0].value.ing).s, NULL); }
#line 795 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 157 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = EPSILON; }
#line 801 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 161 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = sea_hstr(", ", (yystack_[1].value.str).s, (yystack_[0].value.ing).s, NULL); }
#line 807 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 162 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = EPSILON; }
#line 813 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 166 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = "return;"; }
#line 819 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 167 "sea.y" // lalr1.cc:859
    { (yylhs.value.ing) = "return " + (yystack_[1].value.str).s + ";" }
#line 825 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 171 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 831 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 172 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 837 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 173 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.str); }
#line 843 "./src/yyparser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 174 "sea.y" // lalr1.cc:859
    { (yylhs.value.str) = (yystack_[0].value.ing); }
#line 849 "./src/yyparser.cpp" // lalr1.cc:859
    break;


#line 853 "./src/yyparser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -47;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -15,     6,     7,    18,    24,   -47,   -15,   -47,   -35,   -47,
     -47,     2,   -47,   -47,   -47,   -47,   -31,   -47,   -24,    -3,
     -47,    34,   -23,    -2,   -47,   -47,   -47,   -28,    -3,   -22,
     -47,    55,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -21,
     -25,     9,   -23,   -47,   -47,   -47,   -47,   -18,   -47,   -47,
     -47,   -47,     4,    55,    34,   -47,     5,     3,   -47,   -47,
     -47,   -47,   -25,   -47,     9,   -47,   -47,     3,   -47
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     0,     0,     0,     2,     4,     7,     0,     5,
       6,     0,     9,     8,     1,     3,     0,    31,     0,    41,
      30,    33,     0,     0,    43,    42,    46,     0,    41,     0,
      45,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    22,    21,    23,    24,    25,    26,    38,     0,
      35,    49,    54,    56,    55,    52,    57,     0,    39,    40,
      44,    10,    37,    28,     0,    32,     0,    51,    53,    36,
      27,    29,    35,    47,     0,    48,    34,    51,    50
  };

  const signed char
  parser::yypgoto_[] =
  {
     -47,   -47,    33,   -47,   -47,   -27,   -47,   -47,   -13,   -12,
     -47,     8,    11,    60,    51,   -47,   -11,   -47,    10,   -47,
     -46
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,    48,    71,     8,     9,    10,
      49,    65,    50,    26,    27,    28,    56,    66,    75,    30,
      57
  };

  const unsigned char
  parser::yytable_[] =
  {
      22,    52,    53,    54,    62,    67,    24,    25,    29,    11,
      12,     1,    52,    53,    54,    24,    25,    29,     2,     3,
      16,    17,    13,     1,    14,    23,    18,    19,    77,    21,
      51,    58,    64,    63,    60,    69,    70,    31,    68,    15,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    55,    19,    46,    47,    61,    73,
      74,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    72,    20,    46,    47,    59,
      76,     0,     0,     0,     0,     0,     0,    78
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     3,     4,     5,    31,    51,    19,    19,    19,     3,
       3,    26,     3,     4,     5,    28,    28,    28,    33,    34,
      55,    56,     4,    26,     0,    28,    24,    58,    74,    53,
      53,    59,    57,    54,    56,    31,    63,     3,    56,     6,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    56,    58,    22,    23,     3,    54,
      57,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    64,    16,    22,    23,    28,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    77
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    26,    33,    34,    61,    62,    63,    64,    67,    68,
      69,     3,     3,     4,     0,    62,    55,    56,    24,    58,
      73,    53,     3,    28,    68,    69,    73,    74,    75,    76,
      79,     3,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    22,    23,    65,    70,
      72,    53,     3,     4,     5,    56,    76,    80,    59,    74,
      56,     3,    65,    54,    57,    71,    77,    80,    56,    31,
      65,    66,    72,    54,    57,    78,    71,    80,    78
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    60,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      68,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     7,
       3,     2,     2,     0,     3,     0,     3,     2,     1,     3,
       2,     0,     1,     1,     2,     1,     1,     4,     2,     0,
       3,     0,     2,     3,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "IDENTIFIER", "QSTRING", "NUMBER", "I8",
  "I16", "I32", "I64", "U8", "U16", "U32", "U64", "F32", "F64", "UWORD",
  "WORD", "CSTR", "BOOL", "TRUE", "FALSE", "PSIZE", "VOID", "FN", "CAP",
  "DEF", "VAR", "RET", "IF", "ELSE", "VARGS", "NAMESPACE", "INC_SEA_DEP",
  "INC_C_DEP", "IS_EQ", "NOT_EQ", "LESS_EQ", "MORE_EQ", "ADD_EQ", "SUB_EQ",
  "MUL_EQ", "DIV_EQ", "MOD_EQ", "SHL_EQ", "SHR_EQ", "AND_EQ", "XOR_EQ",
  "OR_EQ", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'='", "';'", "','",
  "'{'", "'}'", "$accept", "program", "_global", "global", "include",
  "type", "option_type", "func", "func_def", "func_decl", "params",
  "_params", "param", "block", "_statement", "statement", "func_call",
  "call_params", "_call_params", "return_stmt", "expression", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    49,    49,    53,    54,    58,    59,    60,    64,    69,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    97,    98,   102,
     111,   115,   119,   120,   124,   125,   129,   130,   131,   135,
     139,   140,   144,   145,   146,   147,   148,   152,   156,   157,
     161,   162,   166,   167,   171,   172,   173,   174
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,    51,    49,    57,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    const unsigned int user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1238 "./src/yyparser.cpp" // lalr1.cc:1167
#line 177 "sea.y" // lalr1.cc:1168

