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

// Take the name prefix into account.
#define yylex   evallex

// First part of user declarations.

#line 39 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.

#line 53 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 33 "parser.yy" // lalr1.cc:413

# include "eval_context.h"

#line 59 "parser.cc" // lalr1.cc:413


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if EVALDEBUG

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

#else // !EVALDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !EVALDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "parser.yy" // lalr1.cc:479
namespace isc { namespace eval {
#line 145 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  EvalParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  EvalParser::EvalParser (EvalContext& ctx_yyarg)
    :
#if EVALDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      ctx (ctx_yyarg)
  {}

  EvalParser::~EvalParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  EvalParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  EvalParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  EvalParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  EvalParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  EvalParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  EvalParser::symbol_number_type
  EvalParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  EvalParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  EvalParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 60: // option_repr_type
        value.move< TokenOption::RepresentationType > (that.value);
        break;

      case 64: // pkt4_field
        value.move< TokenPkt4::FieldType > (that.value);
        break;

      case 65: // pkt6_field
        value.move< TokenPkt6::FieldType > (that.value);
        break;

      case 62: // pkt_metadata
        value.move< TokenPkt::MetadataType > (that.value);
        break;

      case 66: // relay6_field
        value.move< TokenRelay6Field::FieldType > (that.value);
        break;

      case 47: // "constant string"
      case 48: // "integer"
      case 49: // "constant hexstring"
      case 50: // "option name"
      case 51: // "ip address"
        value.move< std::string > (that.value);
        break;

      case 59: // option_code
        value.move< uint16_t > (that.value);
        break;

      case 58: // integer_expr
      case 63: // enterprise_id
        value.move< uint32_t > (that.value);
        break;

      case 61: // nest_level
        value.move< uint8_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  EvalParser::stack_symbol_type&
  EvalParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 60: // option_repr_type
        value.copy< TokenOption::RepresentationType > (that.value);
        break;

      case 64: // pkt4_field
        value.copy< TokenPkt4::FieldType > (that.value);
        break;

      case 65: // pkt6_field
        value.copy< TokenPkt6::FieldType > (that.value);
        break;

      case 62: // pkt_metadata
        value.copy< TokenPkt::MetadataType > (that.value);
        break;

      case 66: // relay6_field
        value.copy< TokenRelay6Field::FieldType > (that.value);
        break;

      case 47: // "constant string"
      case 48: // "integer"
      case 49: // "constant hexstring"
      case 50: // "option name"
      case 51: // "ip address"
        value.copy< std::string > (that.value);
        break;

      case 59: // option_code
        value.copy< uint16_t > (that.value);
        break;

      case 58: // integer_expr
      case 63: // enterprise_id
        value.copy< uint32_t > (that.value);
        break;

      case 61: // nest_level
        value.copy< uint8_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  EvalParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if EVALDEBUG
  template <typename Base>
  void
  EvalParser::yy_print_ (std::ostream& yyo,
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
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 47: // "constant string"

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 394 "parser.cc" // lalr1.cc:636
        break;

      case 48: // "integer"

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 401 "parser.cc" // lalr1.cc:636
        break;

      case 49: // "constant hexstring"

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 408 "parser.cc" // lalr1.cc:636
        break;

      case 50: // "option name"

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 415 "parser.cc" // lalr1.cc:636
        break;

      case 51: // "ip address"

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 422 "parser.cc" // lalr1.cc:636
        break;

      case 58: // integer_expr

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 429 "parser.cc" // lalr1.cc:636
        break;

      case 59: // option_code

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint16_t > (); }
#line 436 "parser.cc" // lalr1.cc:636
        break;

      case 60: // option_repr_type

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< TokenOption::RepresentationType > (); }
#line 443 "parser.cc" // lalr1.cc:636
        break;

      case 61: // nest_level

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint8_t > (); }
#line 450 "parser.cc" // lalr1.cc:636
        break;

      case 62: // pkt_metadata

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< TokenPkt::MetadataType > (); }
#line 457 "parser.cc" // lalr1.cc:636
        break;

      case 63: // enterprise_id

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 464 "parser.cc" // lalr1.cc:636
        break;

      case 64: // pkt4_field

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< TokenPkt4::FieldType > (); }
#line 471 "parser.cc" // lalr1.cc:636
        break;

      case 65: // pkt6_field

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< TokenPkt6::FieldType > (); }
#line 478 "parser.cc" // lalr1.cc:636
        break;

      case 66: // relay6_field

#line 108 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< TokenRelay6Field::FieldType > (); }
#line 485 "parser.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  EvalParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  EvalParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  EvalParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if EVALDEBUG
  std::ostream&
  EvalParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  EvalParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  EvalParser::debug_level_type
  EvalParser::debug_level () const
  {
    return yydebug_;
  }

  void
  EvalParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // EVALDEBUG

  inline EvalParser::state_type
  EvalParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  EvalParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  EvalParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  EvalParser::parse ()
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

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

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
            symbol_type yylookahead (yylex (ctx));
            yyla.move (yylookahead);
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 60: // option_repr_type
        yylhs.value.build< TokenOption::RepresentationType > ();
        break;

      case 64: // pkt4_field
        yylhs.value.build< TokenPkt4::FieldType > ();
        break;

      case 65: // pkt6_field
        yylhs.value.build< TokenPkt6::FieldType > ();
        break;

      case 62: // pkt_metadata
        yylhs.value.build< TokenPkt::MetadataType > ();
        break;

      case 66: // relay6_field
        yylhs.value.build< TokenRelay6Field::FieldType > ();
        break;

      case 47: // "constant string"
      case 48: // "integer"
      case 49: // "constant hexstring"
      case 50: // "option name"
      case 51: // "ip address"
        yylhs.value.build< std::string > ();
        break;

      case 59: // option_code
        yylhs.value.build< uint16_t > ();
        break;

      case 58: // integer_expr
      case 63: // enterprise_id
        yylhs.value.build< uint32_t > ();
        break;

      case 61: // nest_level
        yylhs.value.build< uint8_t > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 8:
#line 134 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr neg(new TokenNot());
                    ctx.expression.push_back(neg);
                }
#line 749 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 139 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr neg(new TokenAnd());
                    ctx.expression.push_back(neg);
                }
#line 758 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 144 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr neg(new TokenOr());
                    ctx.expression.push_back(neg);
                }
#line 767 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 149 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr eq(new TokenEqual());
                    ctx.expression.push_back(eq);
                }
#line 776 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 154 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr opt(new TokenOption(yystack_[3].value.as< uint16_t > (), TokenOption::EXISTS));
                    ctx.expression.push_back(opt);
                }
#line 785 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 159 "parser.yy" // lalr1.cc:859
    {
                   switch (ctx.getUniverse()) {
                   case Option::V4:
                   {
                       TokenPtr opt(new TokenRelay4Option(yystack_[3].value.as< uint16_t > (), TokenOption::EXISTS));
                       ctx.expression.push_back(opt);
                       break;
                   }
                   case Option::V6:
                       // We will have relay6[123] for the DHCPv6.
                       // In a very distant future we'll possibly be able
                       // to mix both if we have DHCPv4-over-DHCPv6, so it
                       // has some sense to make it explicit whether we
                       // talk about DHCPv4 relay or DHCPv6 relay. However,
                       // for the time being relay4 can be used in DHCPv4
                       // only.
                       error(yystack_[5].location, "relay4 can only be used in DHCPv4.");
                   }
                }
#line 809 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 179 "parser.yy" // lalr1.cc:859
    {
                    switch (ctx.getUniverse()) {
                    case Option::V6:
                    {
                        TokenPtr opt(new TokenRelay6Option(yystack_[8].value.as< uint8_t > (), yystack_[3].value.as< uint16_t > (), TokenOption::EXISTS));
                        ctx.expression.push_back(opt);
                        break;
                    }
                    case Option::V4:
                        // For now we only use relay6 in DHCPv6.
                        error(yystack_[10].location, "relay6 can only be used in DHCPv6.");
                    }
                }
#line 827 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 193 "parser.yy" // lalr1.cc:859
    {
                  // Expression: vendor-class[1234].exists
                  //
                  // This token will find option 124 (DHCPv4) or 16 (DHCPv6),
                  // and will check if enterprise-id equals specified value.
                  TokenPtr exist(new TokenVendorClass(ctx.getUniverse(), yystack_[3].value.as< uint32_t > (), TokenOption::EXISTS));
                  ctx.expression.push_back(exist);
              }
#line 840 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 202 "parser.yy" // lalr1.cc:859
    {
                  // Expression: vendor[1234].exists
                  //
                  // This token will find option 125 (DHCPv4) or 17 (DHCPv6),
                  // and will check if enterprise-id equals specified value.
                  TokenPtr exist(new TokenVendor(ctx.getUniverse(), yystack_[3].value.as< uint32_t > (), TokenOption::EXISTS));
                  ctx.expression.push_back(exist);
              }
#line 853 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 211 "parser.yy" // lalr1.cc:859
    {
                  // Expression vendor[1234].option[123].exists
                  //
                  // This token will check if specified vendor option
                  // exists, has specified enterprise-id and if has
                  // specified suboption.
                  TokenPtr exist(new TokenVendor(ctx.getUniverse(), yystack_[8].value.as< uint32_t > (), TokenOption::EXISTS, yystack_[3].value.as< uint16_t > ()));
                  ctx.expression.push_back(exist);
               }
#line 867 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 223 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr str(new TokenString(yystack_[0].value.as< std::string > ()));
                      ctx.expression.push_back(str);
                  }
#line 876 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 228 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr hex(new TokenHexString(yystack_[0].value.as< std::string > ()));
                      ctx.expression.push_back(hex);
                  }
#line 885 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 233 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr ip(new TokenIpAddress(yystack_[0].value.as< std::string > ()));
                      ctx.expression.push_back(ip);
                  }
#line 894 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 238 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr opt(new TokenOption(yystack_[3].value.as< uint16_t > (), yystack_[0].value.as< TokenOption::RepresentationType > ()));
                      ctx.expression.push_back(opt);
                  }
#line 903 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 243 "parser.yy" // lalr1.cc:859
    {
                     switch (ctx.getUniverse()) {
                     case Option::V4:
                     {
                         TokenPtr opt(new TokenRelay4Option(yystack_[3].value.as< uint16_t > (), yystack_[0].value.as< TokenOption::RepresentationType > ()));
                         ctx.expression.push_back(opt);
                         break;
                     }
                     case Option::V6:
                         // We will have relay6[123] for the DHCPv6.
                         // In a very distant future we'll possibly be able
                         // to mix both if we have DHCPv4-over-DHCPv6, so it
                         // has some sense to make it explicit whether we
                         // talk about DHCPv4 relay or DHCPv6 relay. However,
                         // for the time being relay4 can be used in DHCPv4
                         // only.
                         error(yystack_[5].location, "relay4 can only be used in DHCPv4.");
                     }
                  }
#line 927 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 264 "parser.yy" // lalr1.cc:859
    {
                     switch (ctx.getUniverse()) {
                     case Option::V6:
                     {
                         TokenPtr opt(new TokenRelay6Option(yystack_[8].value.as< uint8_t > (), yystack_[3].value.as< uint16_t > (), yystack_[0].value.as< TokenOption::RepresentationType > ()));
                         ctx.expression.push_back(opt);
                         break;
                     }
                     case Option::V4:
                         // For now we only use relay6 in DHCPv6.
                         error(yystack_[10].location, "relay6 can only be used in DHCPv6.");
                     }
                  }
#line 945 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 279 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr pkt_metadata(new TokenPkt(yystack_[0].value.as< TokenPkt::MetadataType > ()));
                      ctx.expression.push_back(pkt_metadata);
                  }
#line 954 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 284 "parser.yy" // lalr1.cc:859
    {
                     switch (ctx.getUniverse()) {
                     case Option::V4:
                     {
                         TokenPtr pkt4_field(new TokenPkt4(yystack_[0].value.as< TokenPkt4::FieldType > ()));
                         ctx.expression.push_back(pkt4_field);
                         break;
                     }
                     case Option::V6:
                         // For now we only use pkt4 in DHCPv4.
                         error(yystack_[2].location, "pkt4 can only be used in DHCPv4.");
                     }
                  }
#line 972 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 298 "parser.yy" // lalr1.cc:859
    {
                     switch (ctx.getUniverse()) {
                     case Option::V6:
                     {
                         TokenPtr pkt6_field(new TokenPkt6(yystack_[0].value.as< TokenPkt6::FieldType > ()));
                         ctx.expression.push_back(pkt6_field);
                         break;
                     }
                     case Option::V4:
                         // For now we only use pkt6 in DHCPv6.
                         error(yystack_[2].location, "pkt6 can only be used in DHCPv6.");
                     }
                  }
#line 990 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 312 "parser.yy" // lalr1.cc:859
    {
                     switch (ctx.getUniverse()) {
                     case Option::V6:
                     {
                         TokenPtr relay6field(new TokenRelay6Field(yystack_[3].value.as< uint8_t > (), yystack_[0].value.as< TokenRelay6Field::FieldType > ()));
                         ctx.expression.push_back(relay6field);
                         break;
                     }
                     case Option::V4:
                         // For now we only use relay6 in DHCPv6.
                         error(yystack_[5].location, "relay6 can only be used in DHCPv6.");
                     }
                  }
#line 1008 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 327 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr sub(new TokenSubstring());
                      ctx.expression.push_back(sub);
                  }
#line 1017 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 332 "parser.yy" // lalr1.cc:859
    {
                      TokenPtr conc(new TokenConcat());
                      ctx.expression.push_back(conc);
                  }
#line 1026 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 337 "parser.yy" // lalr1.cc:859
    {
                    // expression: vendor.enterprise
                    //
                    // This token will return enterprise-id number of
                    // received vendor option.
                    TokenPtr vendor(new TokenVendor(ctx.getUniverse(), 0, TokenVendor::ENTERPRISE_ID));
                    ctx.expression.push_back(vendor);
                }
#line 1039 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 346 "parser.yy" // lalr1.cc:859
    {
                    // expression: vendor-class.enterprise
                    //
                    // This token will return enterprise-id number of
                    // received vendor class option.
                    TokenPtr vendor(new TokenVendorClass(ctx.getUniverse(), 0,
                                                         TokenVendor::ENTERPRISE_ID));
                    ctx.expression.push_back(vendor);
                }
#line 1053 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 356 "parser.yy" // lalr1.cc:859
    {
                    // This token will search for vendor option with
                    // specified enterprise-id.  If found, will search
                    // for specified suboption and finally will return
                    // its content.
                    TokenPtr opt(new TokenVendor(ctx.getUniverse(), yystack_[8].value.as< uint32_t > (), yystack_[0].value.as< TokenOption::RepresentationType > (), yystack_[3].value.as< uint16_t > ()));
                    ctx.expression.push_back(opt);
                }
#line 1066 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 365 "parser.yy" // lalr1.cc:859
    {
                    // expression: vendor-class[1234].data
                    //
                    // Vendor class option does not have suboptions,
                    // but chunks of data (typically 1, but the option
                    // structure allows multiple of them). If chunk
                    // offset is not specified, we assume the first (0th)
                    // is requested.
                    TokenPtr vendor_class(new TokenVendorClass(ctx.getUniverse(), yystack_[3].value.as< uint32_t > (),
                                                               TokenVendor::DATA, 0));
                    ctx.expression.push_back(vendor_class);
                }
#line 1083 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 378 "parser.yy" // lalr1.cc:859
    {
                    // expression: vendor-class[1234].data[5]
                    //
                    // Vendor class option does not have suboptions,
                    // but chunks of data (typically 1, but the option
                    // structure allows multiple of them). This syntax
                    // specifies which data chunk (tuple) we want.
                    uint8_t index = ctx.convertUint8(yystack_[1].value.as< std::string > (), yystack_[1].location);
                    TokenPtr vendor_class(new TokenVendorClass(ctx.getUniverse(), yystack_[6].value.as< uint32_t > (),
                                                               TokenVendor::DATA, index));
                    ctx.expression.push_back(vendor_class);
                }
#line 1100 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 391 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr integer(new TokenInteger(yystack_[0].value.as< uint32_t > ()));
                    ctx.expression.push_back(integer);
                }
#line 1109 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 398 "parser.yy" // lalr1.cc:859
    {
                     yylhs.value.as< uint32_t > () = ctx.convertUint32(yystack_[0].value.as< std::string > (), yystack_[0].location);
                 }
#line 1117 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 404 "parser.yy" // lalr1.cc:859
    {
                     yylhs.value.as< uint16_t > () = ctx.convertOptionCode(yystack_[0].value.as< std::string > (), yystack_[0].location);
                 }
#line 1125 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 408 "parser.yy" // lalr1.cc:859
    {
                     yylhs.value.as< uint16_t > () = ctx.convertOptionName(yystack_[0].value.as< std::string > (), yystack_[0].location);
                 }
#line 1133 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 414 "parser.yy" // lalr1.cc:859
    {
                          yylhs.value.as< TokenOption::RepresentationType > () = TokenOption::TEXTUAL;
                      }
#line 1141 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 418 "parser.yy" // lalr1.cc:859
    {
                          yylhs.value.as< TokenOption::RepresentationType > () = TokenOption::HEXADECIMAL;
                      }
#line 1149 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 424 "parser.yy" // lalr1.cc:859
    {
                     yylhs.value.as< uint8_t > () = ctx.convertNestLevelNumber(yystack_[0].value.as< std::string > (), yystack_[0].location);
                 }
#line 1157 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 433 "parser.yy" // lalr1.cc:859
    {
                      yylhs.value.as< TokenPkt::MetadataType > () = TokenPkt::IFACE;
                  }
#line 1165 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 437 "parser.yy" // lalr1.cc:859
    {
                      yylhs.value.as< TokenPkt::MetadataType > () = TokenPkt::SRC;
                  }
#line 1173 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 441 "parser.yy" // lalr1.cc:859
    {
                      yylhs.value.as< TokenPkt::MetadataType > () = TokenPkt::DST;
                  }
#line 1181 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 445 "parser.yy" // lalr1.cc:859
    {
                      yylhs.value.as< TokenPkt::MetadataType > () = TokenPkt::LEN;
                  }
#line 1189 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 451 "parser.yy" // lalr1.cc:859
    {
                       yylhs.value.as< uint32_t > () = ctx.convertUint32(yystack_[0].value.as< std::string > (), yystack_[0].location);
                   }
#line 1197 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 455 "parser.yy" // lalr1.cc:859
    {
                       yylhs.value.as< uint32_t > () = 0;
                   }
#line 1205 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 461 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::CHADDR;
                }
#line 1213 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 465 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::HLEN;
                }
#line 1221 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 469 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::HTYPE;
                }
#line 1229 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 473 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::CIADDR;
                }
#line 1237 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 477 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::GIADDR;
                }
#line 1245 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 481 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::YIADDR;
                }
#line 1253 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 485 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::SIADDR;
                }
#line 1261 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 489 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::MSGTYPE;
                 }
#line 1269 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 493 "parser.yy" // lalr1.cc:859
    {
                    yylhs.value.as< TokenPkt4::FieldType > () = TokenPkt4::TRANSID;
                 }
#line 1277 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 499 "parser.yy" // lalr1.cc:859
    {
                     yylhs.value.as< TokenPkt6::FieldType > () = TokenPkt6::MSGTYPE;
                 }
#line 1285 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 503 "parser.yy" // lalr1.cc:859
    {
                     yylhs.value.as< TokenPkt6::FieldType > () = TokenPkt6::TRANSID;
                 }
#line 1293 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 509 "parser.yy" // lalr1.cc:859
    {
                       yylhs.value.as< TokenRelay6Field::FieldType > () = TokenRelay6Field::PEERADDR;
                   }
#line 1301 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 513 "parser.yy" // lalr1.cc:859
    {
                       yylhs.value.as< TokenRelay6Field::FieldType > () = TokenRelay6Field::LINKADDR;
                   }
#line 1309 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 519 "parser.yy" // lalr1.cc:859
    {
                    TokenPtr str(new TokenString(yystack_[0].value.as< std::string > ()));
                    ctx.expression.push_back(str);
                }
#line 1318 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 526 "parser.yy" // lalr1.cc:859
    {
                     TokenPtr str(new TokenString(yystack_[0].value.as< std::string > ()));
                     ctx.expression.push_back(str);
                 }
#line 1327 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 531 "parser.yy" // lalr1.cc:859
    {
                     TokenPtr str(new TokenString("all"));
                     ctx.expression.push_back(str);
                 }
#line 1336 "parser.cc" // lalr1.cc:859
    break;


#line 1340 "parser.cc" // lalr1.cc:859
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
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

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
  EvalParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  EvalParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char EvalParser::yypact_ninf_ = -98;

  const signed char EvalParser::yytable_ninf_ = -1;

  const short int
  EvalParser::yypact_[] =
  {
     -23,    41,    41,    36,    41,    41,    28,    31,    35,    56,
      60,    92,    93,    84,    -8,    59,   -98,   -98,   -98,   -98,
     -98,    47,    55,   -98,   -98,    47,    55,   -98,    58,   -98,
      43,    43,    61,    17,   -14,    88,    88,    48,   -22,    73,
     -22,    74,    41,    41,    88,   -98,   -98,   -98,   107,   108,
     -98,   111,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   113,   116,   117,
      91,    96,    71,    98,   -98,   -98,   -98,   -98,   -98,   119,
     -98,   123,   -98,   -98,   126,   -98,   124,   125,   127,    43,
      43,    61,   -22,   -22,    94,    88,   128,   129,    52,    66,
      18,   131,   132,   133,   134,   135,   -98,   118,   147,   -15,
       2,   -98,   -98,   -98,   -98,   -98,   -98,   138,   -98,   -98,
     -98,   139,   140,   141,   142,   143,   -29,   -98,   -98,   146,
     148,   -98,    43,    62,    62,    20,   120,   145,   -98,   -98,
     157,   121,    43,   149,   151,   152,   -98,   153,   155,   156,
      43,    43,   -98,   158,    85,   160,   161,    97,   -98,   -98,
     162,   163,   -98,   -98,    62,    62
  };

  const unsigned char
  EvalParser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    36,    19,    20,
       2,     6,     0,    35,     3,     4,     5,     1,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,    37,    38,     0,     0,
      41,     0,    42,    43,    44,    45,    24,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    25,     0,     0,     0,
       0,     0,     0,     0,    57,    58,    26,    47,    46,     0,
      31,     0,    30,     9,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,    39,    40,    12,    21,    13,    22,     0,    59,    60,
      27,     0,     0,     0,     0,     0,     0,    29,    15,    33,
       0,    16,     0,     0,     0,     0,     0,     0,    63,    62,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,    14,    23,
       0,     0,    17,    32,     0,     0
  };

  const signed char
  EvalParser::yypgoto_[] =
  {
     -98,   -98,   -98,   -98,     5,    -1,   -98,   -31,   -97,    76,
     -98,   -37,   -98,   -98,   -98,   -98,   -98
  };

  const short int
  EvalParser::yydefgoto_[] =
  {
      -1,     3,    24,    20,    21,    22,    23,    48,   114,    51,
      56,    79,    66,    76,   120,   107,   140
  };

  const unsigned char
  EvalParser::yytable_[] =
  {
      49,    26,   116,    81,   128,   138,    38,    25,    39,    28,
      29,   130,    57,    58,    59,    60,    61,    62,    63,   139,
      77,   131,     1,     2,    64,    65,    78,   117,   129,   144,
     118,   119,   118,   119,    72,    73,    27,   116,    52,    53,
      54,    55,    30,    85,     4,    31,     5,    83,    84,    32,
       6,     7,     8,    42,    43,   104,   105,   159,   101,   102,
     163,     9,    45,    44,    42,    43,    10,   159,   163,   111,
     112,   113,    33,    40,    11,    41,    34,    12,    13,   111,
     112,    14,    15,   111,   112,   115,    74,    75,    16,    17,
      18,    46,    19,    47,   108,    35,    36,    67,    68,    69,
      37,   143,   111,   112,   158,    92,    94,    39,     9,    50,
      93,   148,    41,    10,   111,   112,   162,    80,    82,   155,
     156,    11,    86,    87,    12,    13,    88,    89,    70,    71,
      90,    91,    42,    95,    96,    16,    17,    18,    97,    19,
      98,    99,   106,   100,   109,   110,   121,   122,   123,   124,
     125,   127,   132,   126,   145,   133,   134,   135,   136,   137,
     141,   146,   142,   129,   149,   150,   151,   103,   152,   147,
     153,     0,   154,     0,   157,   160,   161,     0,   164,   165
  };

  const short int
  EvalParser::yycheck_[] =
  {
      31,     2,    99,    40,    19,    34,    14,     2,    16,     4,
       5,     9,    26,    27,    28,    29,    30,    31,    32,    48,
      42,    19,    45,    46,    38,    39,    48,     9,    43,     9,
      12,    13,    12,    13,    35,    36,     0,   134,    21,    22,
      23,    24,    14,    44,     3,    14,     5,    42,    43,    14,
       9,    10,    11,     6,     7,    92,    93,   154,    89,    90,
     157,    20,     4,     8,     6,     7,    25,   164,   165,    17,
      18,    19,    16,    14,    33,    16,    16,    36,    37,    17,
      18,    40,    41,    17,    18,    19,    38,    39,    47,    48,
      49,    48,    51,    50,    95,     3,     3,     9,    10,    11,
      16,   132,    17,    18,    19,    14,    35,    16,    20,    48,
      14,   142,    16,    25,    17,    18,    19,    44,    44,   150,
     151,    33,    15,    15,    36,    37,    15,    14,    40,    41,
      14,    14,     6,    35,    15,    47,    48,    49,    15,    51,
      16,    16,    48,    16,    16,    16,    15,    15,    15,    15,
      15,     4,    14,    35,     9,    16,    16,    16,    16,    16,
      14,     4,    14,    43,    15,    14,    14,    91,    15,    48,
      15,    -1,    16,    -1,    16,    15,    15,    -1,    16,    16
  };

  const unsigned char
  EvalParser::yystos_[] =
  {
       0,    45,    46,    53,     3,     5,     9,    10,    11,    20,
      25,    33,    36,    37,    40,    41,    47,    48,    49,    51,
      55,    56,    57,    58,    54,    56,    57,     0,    56,    56,
      14,    14,    14,    16,    16,     3,     3,    16,    14,    16,
      14,    16,     6,     7,     8,     4,    48,    50,    59,    59,
      48,    61,    21,    22,    23,    24,    62,    26,    27,    28,
      29,    30,    31,    32,    38,    39,    64,     9,    10,    11,
      40,    41,    57,    57,    38,    39,    65,    42,    48,    63,
      44,    63,    44,    56,    56,    57,    15,    15,    15,    14,
      14,    14,    14,    14,    35,    35,    15,    15,    16,    16,
      16,    59,    59,    61,    63,    63,    48,    67,    57,    16,
      16,    17,    18,    19,    60,    19,    60,     9,    12,    13,
      66,    15,    15,    15,    15,    15,    35,     4,    19,    43,
       9,    19,    14,    16,    16,    16,    16,    16,    34,    48,
      68,    14,    14,    59,     9,     9,     4,    48,    59,    15,
      14,    14,    15,    15,    16,    59,    59,    16,    19,    60,
      15,    15,    19,    60,    16,    16
  };

  const unsigned char
  EvalParser::yyr1_[] =
  {
       0,    52,    53,    53,    54,    54,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    59,    60,
      60,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    68,    68
  };

  const unsigned char
  EvalParser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     1,     1,     3,     2,     3,
       3,     3,     6,     6,    11,     6,     6,    11,     1,     1,
       1,     6,     6,    11,     3,     3,     3,     6,     8,     6,
       3,     3,    11,     6,     9,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const EvalParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"(\"", "\")\"", "\"not\"",
  "\"and\"", "\"or\"", "\"==\"", "\"option\"", "\"relay4\"", "\"relay6\"",
  "\"peeraddr\"", "\"linkaddr\"", "\"[\"", "\"]\"", "\".\"", "\"text\"",
  "\"hex\"", "\"exists\"", "\"pkt\"", "\"iface\"", "\"src\"", "\"dst\"",
  "\"len\"", "\"pkt4\"", "\"mac\"", "\"hlen\"", "\"htype\"", "\"ciaddr\"",
  "\"giaddr\"", "\"yiaddr\"", "\"siaddr\"", "\"substring\"", "\"all\"",
  "\",\"", "\"concat\"", "\"pkt6\"", "\"msgtype\"", "\"transid\"",
  "\"vendor-class\"", "\"vendor\"", "\"*\"", "\"data\"", "\"enterprise\"",
  "\"top-level bool\"", "\"top-level string\"", "\"constant string\"",
  "\"integer\"", "\"constant hexstring\"", "\"option name\"",
  "\"ip address\"", "$accept", "start", "string_expression", "expression",
  "bool_expr", "string_expr", "integer_expr", "option_code",
  "option_repr_type", "nest_level", "pkt_metadata", "enterprise_id",
  "pkt4_field", "pkt6_field", "relay6_field", "start_expr", "length_expr", YY_NULLPTR
  };

#if EVALDEBUG
  const unsigned short int
  EvalParser::yyrline_[] =
  {
       0,   117,   117,   118,   123,   124,   129,   132,   133,   138,
     143,   148,   153,   158,   178,   192,   201,   210,   222,   227,
     232,   237,   242,   263,   278,   283,   297,   311,   326,   331,
     336,   345,   355,   364,   377,   390,   397,   403,   407,   413,
     417,   423,   432,   436,   440,   444,   450,   454,   460,   464,
     468,   472,   476,   480,   484,   488,   492,   498,   502,   508,
     512,   518,   525,   530
  };

  // Print the state stack on the debug stream.
  void
  EvalParser::yystack_print_ ()
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
  EvalParser::yy_reduce_print_ (int yyrule)
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
#endif // EVALDEBUG


#line 14 "parser.yy" // lalr1.cc:1167
} } // isc::eval
#line 1817 "parser.cc" // lalr1.cc:1167
#line 537 "parser.yy" // lalr1.cc:1168

void
isc::eval::EvalParser::error(const location_type& loc,
                             const std::string& what)
{
    ctx.error(loc, what);
}
