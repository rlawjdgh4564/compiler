/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "expr.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "print.h"

#line 74 "expr.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "expr.tab.h".  */
#ifndef YY_YY_EXPR_TAB_H_INCLUDED
# define YY_YY_EXPR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTNUM = 258,
    FLOATNUM = 259,
    Id = 260,
    INT = 261,
    FLOAT = 262,
    COLON = 263,
    RETURN = 264,
    WHILE = 265,
    IF = 266,
    DO = 267,
    ELSE = 268,
    FOR = 269,
    SWITCH = 270,
    CASE = 271,
    DEFAULT = 272,
    BREAK = 273,
    COMMA = 274,
    SEMI = 275,
    INSERT = 276,
    EQLT = 277,
    RELA = 278,
    MULT = 279,
    UNOP = 280,
    L = 281,
    R = 282,
    LL = 283,
    RR = 284,
    LLL = 285,
    RRR = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 9 "expr.y" /* yacc.c:355  */

   struct PROGRAM *ptr_prog;
   struct DECLARATION *ptr_decl;
   struct FUNCTION *ptr_func;
   struct IDENTIFIER *ptr_ident;
   struct PARAMETER *ptr_param;
   struct COMPOUNDSTMT *ptr_comp;
   struct STMT *ptr_stmt;
   struct CASE *ptr_case;
   struct SWITCH_S *ptr_switch;
   struct ASSIGN *ptr_ass;
   struct CALL *ptr_call;
   struct ARG *ptr_arg;
   struct WHILE_S *ptr_while;
   struct FOR_S *ptr_for;
   struct IF_S *ptr_if;
   struct EXPR *ptr_expr;
   struct UNOP *ptr_unop;
   struct ADDIOP *ptr_addi;
   struct MULTOP *ptr_mult;
   struct RELAOP *ptr_rela;
   struct EQLTOP *ptr_eqlt;
   struct ID_S *ptr_id;
   int ptr_type;
   int intnum;
   float floatnum;
   char* id;

#line 175 "expr.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "expr.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    87,    95,   103,   113,   116,   122,   125,
     131,   142,   145,   151,   158,   167,   176,   187,   194,   204,
     207,   212,   219,   228,   231,   235,   242,   249,   256,   263,
     270,   277,   284,   291,   298,   306,   311,   320,   330,   335,
     341,   351,   354,   359,   367,   377,   388,   396,   406,   415,
     424,   433,   442,   451,   460,   469,   477,   488,   501,   514,
     525,   536,   548,   556,   563,   570,   579,   589,   598,   604
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTNUM", "FLOATNUM", "Id", "INT",
  "FLOAT", "COLON", "RETURN", "WHILE", "IF", "DO", "ELSE", "FOR", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "COMMA", "SEMI", "INSERT", "EQLT", "RELA",
  "'+'", "'-'", "MULT", "UNOP", "L", "R", "LL", "RR", "LLL", "RRR",
  "$accept", "Program", "DeclList", "FuncList", "Declaration", "IdentList",
  "Identifier", "Function", "ParamList", "Type", "CompoundStmt",
  "StmtList", "Stmt", "AssignStmt", "Assign", "CallStmt", "Call",
  "RetStmt", "WhileStmt", "ForStmt", "IfStmt", "SwitchStmt", "CaseList",
  "Expr", "ArgList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,   279,   280,   281,   282,
     283,   284,   285,   286
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     108,   -95,   -95,    12,   108,   108,   -95,   -95,    14,   -95,
     108,   -95,   -95,    22,    48,   106,   -95,     7,    -1,    42,
      43,   -95,    29,    -4,    43,    31,    39,   -95,   159,   -95,
     108,    29,   -95,   -95,   -12,   200,    51,    54,   186,    64,
      66,   -95,   159,    43,   -95,   107,   -95,   -95,    76,   -95,
      81,   -95,   -95,   -95,   -95,   -95,    43,   -95,    63,    58,
      63,   -95,   -95,    61,   -95,    63,    63,   -95,   211,    63,
      63,    89,   103,    43,   119,   -95,   -95,   -95,   -95,   -95,
     118,   -95,   118,     2,   185,    63,    93,   217,   -95,    63,
      63,    63,    63,    63,   225,   233,    95,    19,   112,   114,
     -95,    63,   -95,   125,   199,   -95,    46,    79,   109,    93,
      93,   186,   186,    63,    63,   131,   118,    63,   -95,   -95,
     135,   241,   249,   177,   118,   186,   143,   103,   152,   167,
     136,   -95,   -95,   147,   170,   186,   -95,   186,   186,   172,
     -95,   142,   160,   165,   -95,   -95,   177,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    19,    20,     0,     3,     4,     6,     8,     0,     1,
       2,     7,     9,     0,    13,     0,    11,     0,     0,     0,
       0,    10,     0,     0,     0,     0,    13,    12,    25,    15,
       0,     0,    17,    14,     0,     0,     0,     0,     0,     0,
       0,    34,    25,     0,    33,     0,    23,    26,     0,    27,
       0,    28,    29,    30,    31,    32,     0,    16,     0,     0,
       0,    63,    64,    65,    41,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,    21,    24,    35,    38,    18,
      36,    39,    68,     0,     0,     0,    56,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,    40,     0,     0,    67,    61,    60,    57,    59,
      58,     0,     0,     0,     0,     0,    69,     0,    66,    43,
      46,     0,     0,    55,    37,     0,     0,     0,     0,     0,
       0,    47,    44,     0,     0,    25,    48,     0,    25,    51,
      45,    49,     0,     0,    53,    52,    50,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   171,   184,     0,   -95,   -13,    34,   -95,     8,
      10,   -40,   -37,   -95,   -69,   -95,   -28,   -95,   -95,   -95,
     -95,   -95,   -94,   -36,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    15,    16,     7,    23,     8,
      44,    45,    46,    47,    48,    49,    67,    51,    52,    53,
      54,    55,   130,    68,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    71,    74,    98,    11,     1,     2,    27,    76,    58,
      50,    32,     9,    13,    50,    30,    59,    50,    13,    14,
      60,   101,    80,    82,    84,    31,    24,    17,    22,    86,
      87,   102,    29,    94,    95,    18,    43,    76,    56,    12,
      58,    57,    11,    79,    12,    25,    50,   144,    26,   104,
      43,    60,   147,   106,   107,   108,   109,   110,   133,    28,
      99,    61,    62,    63,    33,   116,    61,    62,    63,    90,
      91,    19,    92,    93,   119,   120,    18,   121,   122,    69,
      19,   124,    70,    50,    50,    65,    66,    81,   131,    59,
      65,    66,    72,    85,    73,   139,    77,    50,   141,    96,
     140,    78,    76,    91,    76,    92,    93,    50,    97,    50,
      50,    50,    34,    50,     1,     2,    35,    36,    37,    38,
      93,    39,    40,   113,    34,    20,    21,    41,    35,    36,
      37,    38,   114,    39,    40,    92,    93,    28,    75,    41,
      89,    90,    91,   115,    92,    93,   117,    34,   125,    28,
     100,    35,    36,    37,    38,   134,    39,    40,   128,   129,
     143,   123,    41,   132,    34,     1,     2,   136,    35,    36,
      37,    38,    28,    39,    40,   135,   137,    34,   138,    41,
     145,    35,    36,    37,    38,   146,    39,    40,    10,    28,
     142,    34,    41,   128,   129,    35,    36,    37,    38,    42,
      39,    40,    28,    61,    62,    63,    41,    89,    90,    91,
       0,    92,    93,     0,     0,     0,    28,     0,   103,     0,
      64,    89,    90,    91,     0,    92,    93,    65,    66,     0,
       0,    88,   118,    89,    90,    91,     0,    92,    93,    89,
      90,    91,     0,    92,    93,     0,   105,    89,    90,    91,
       0,    92,    93,     0,   111,    89,    90,    91,     0,    92,
      93,     0,   112,    89,    90,    91,     0,    92,    93,   127,
     126,    89,    90,    91,     0,    92,    93
};

static const yytype_int16 yycheck[] =
{
      28,    38,    42,    72,     4,     6,     7,    20,    45,    21,
      38,    24,     0,     5,    42,    19,    28,    45,    10,     5,
      32,    19,    58,    59,    60,    29,    18,     5,    29,    65,
      66,    29,    22,    69,    70,    28,    28,    74,    30,     5,
      21,    31,    42,    56,    10,     3,    74,   141,     5,    85,
      42,    32,   146,    89,    90,    91,    92,    93,   127,    30,
      73,     3,     4,     5,    33,   101,     3,     4,     5,    23,
      24,    32,    26,    27,   111,   112,    28,   113,   114,    28,
      32,   117,    28,   111,   112,    27,    28,    29,   125,    28,
      27,    28,    28,    32,    28,   135,    20,   125,   138,    10,
     137,    20,   139,    24,   141,    26,    27,   135,     5,   137,
     138,   139,     5,   141,     6,     7,     9,    10,    11,    12,
      27,    14,    15,    28,     5,    19,    20,    20,     9,    10,
      11,    12,    20,    14,    15,    26,    27,    30,    31,    20,
      22,    23,    24,    29,    26,    27,    21,     5,    13,    30,
      31,     9,    10,    11,    12,     3,    14,    15,    16,    17,
      18,    30,    20,    20,     5,     6,     7,    31,     9,    10,
      11,    12,    30,    14,    15,     8,    29,     5,     8,    20,
      20,     9,    10,    11,    12,    20,    14,    15,     4,    30,
      18,     5,    20,    16,    17,     9,    10,    11,    12,    28,
      14,    15,    30,     3,     4,     5,    20,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    30,    -1,    33,    -1,
      20,    22,    23,    24,    -1,    26,    27,    27,    28,    -1,
      -1,    20,    33,    22,    23,    24,    -1,    26,    27,    22,
      23,    24,    -1,    26,    27,    -1,    29,    22,    23,    24,
      -1,    26,    27,    -1,    29,    22,    23,    24,    -1,    26,
      27,    -1,    29,    22,    23,    24,    -1,    26,    27,    20,
      29,    22,    23,    24,    -1,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    35,    36,    37,    38,    41,    43,     0,
      37,    38,    41,    43,     5,    39,    40,     5,    28,    32,
      19,    20,    29,    42,    43,     3,     5,    40,    30,    44,
      19,    29,    40,    33,     5,     9,    10,    11,    12,    14,
      15,    20,    36,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    43,    44,    21,    28,
      32,     3,     4,     5,    20,    27,    28,    50,    57,    28,
      28,    46,    28,    28,    45,    31,    46,    20,    20,    40,
      57,    29,    57,    58,    57,    32,    57,    57,    20,    22,
      23,    24,    26,    27,    57,    57,    10,     5,    48,    40,
      31,    19,    29,    33,    57,    29,    57,    57,    57,    57,
      57,    29,    29,    28,    20,    29,    57,    21,    33,    46,
      46,    57,    57,    30,    57,    13,    29,    20,    16,    17,
      56,    46,    20,    48,     3,     8,    31,    29,     8,    45,
      46,    45,    18,    18,    56,    20,    20,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    35,    35,    35,    36,    36,    37,    37,
      38,    39,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    54,    54,    55,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     1,     2,     1,     2,
       3,     1,     3,     1,     4,     5,     6,     2,     4,     1,
       1,     3,     4,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     6,     2,     3,
       4,     2,     3,     5,     7,     9,     5,     7,     7,     4,
       6,     3,     5,     5,     7,     0,     2,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     4,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 76 "expr.y" /* yacc.c:1646  */
    {
   struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));


   program->decl = (yyvsp[-1].ptr_decl);
   program->func = (yyvsp[0].ptr_func);

   head = program;
   
   (yyval.ptr_prog) = program;
}
#line 1396 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "expr.y" /* yacc.c:1646  */
    {
      struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));

      head = program;
      program->decl = (yyvsp[0].ptr_decl);      
      program->func = NULL;
      (yyval.ptr_prog) = program;
}
#line 1409 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "expr.y" /* yacc.c:1646  */
    {
      struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));

      head = program;
      program->decl = NULL;
      program->func = (yyvsp[0].ptr_func);
      (yyval.ptr_prog) = program;
}
#line 1422 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "expr.y" /* yacc.c:1646  */
    {
   		struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));

   		program = NULL;
      	head = NULL;
      	(yyval.ptr_prog) = NULL;
   }
#line 1434 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_decl) = (yyvsp[0].ptr_decl);
}
#line 1442 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "expr.y" /* yacc.c:1646  */
    {
      (yyvsp[0].ptr_decl)->prev = (yyvsp[-1].ptr_decl);
      (yyval.ptr_decl) = (yyvsp[0].ptr_decl);
}
#line 1451 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_func) = (yyvsp[0].ptr_func);
}
#line 1459 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "expr.y" /* yacc.c:1646  */
    {
      (yyvsp[0].ptr_func)->prev = (yyvsp[-1].ptr_func);
      (yyval.ptr_func) = (yyvsp[0].ptr_func);
}
#line 1468 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 131 "expr.y" /* yacc.c:1646  */
    {
   struct DECLARATION *declaration = (struct DECLARATION *) malloc (sizeof (struct DECLARATION));

   declaration->t = (yyvsp[-2].ptr_type);
   declaration->id = (yyvsp[-1].ptr_ident);

   (yyval.ptr_decl) = declaration;
   
}
#line 1482 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_ident) = (yyvsp[0].ptr_ident);
}
#line 1490 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "expr.y" /* yacc.c:1646  */
    {
      (yyvsp[0].ptr_ident)->prev = (yyvsp[-2].ptr_ident);
      (yyval.ptr_ident) = (yyvsp[0].ptr_ident);
}
#line 1499 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 151 "expr.y" /* yacc.c:1646  */
    {
   struct IDENTIFIER * identifier = (struct IDENTIFIER *) malloc (sizeof (struct IDENTIFIER));

   identifier->ID = (yyvsp[0].id);
   identifier->intnum = 0;
   (yyval.ptr_ident) = identifier;
}
#line 1511 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "expr.y" /* yacc.c:1646  */
    {
      struct IDENTIFIER * identifier = (struct IDENTIFIER *) malloc (sizeof (struct IDENTIFIER));

      identifier->ID = (yyvsp[-3].id);
      identifier->intnum = (yyvsp[-1].intnum);
      (yyval.ptr_ident) = identifier;      
}
#line 1523 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 167 "expr.y" /* yacc.c:1646  */
    {
   struct FUNCTION *func = (struct FUNCTION *) malloc (sizeof (struct FUNCTION));

   func->t = (yyvsp[-4].ptr_type);
   func->ID = (yyvsp[-3].id);
   func->param = NULL;
   func->cstmt = (yyvsp[0].ptr_comp);
   (yyval.ptr_func) = func;
}
#line 1537 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 176 "expr.y" /* yacc.c:1646  */
    {
   struct FUNCTION *func = (struct FUNCTION *) malloc (sizeof (struct FUNCTION));

   func->t = (yyvsp[-5].ptr_type);
   func->ID = (yyvsp[-4].id);
   func->param = (yyvsp[-2].ptr_param);
   func->cstmt = (yyvsp[0].ptr_comp);
   (yyval.ptr_func) = func;
}
#line 1551 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 187 "expr.y" /* yacc.c:1646  */
    {
   struct PARAMETER *param = (struct PARAMETER *) malloc (sizeof (struct PARAMETER));

   param->t = (yyvsp[-1].ptr_type);
   param->id = (yyvsp[0].ptr_ident);
   (yyval.ptr_param) = param;
}
#line 1563 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "expr.y" /* yacc.c:1646  */
    {
      struct PARAMETER *param = (struct PARAMETER *) malloc (sizeof (struct PARAMETER));

      param->t = (yyvsp[-1].ptr_type);
      param->id = (yyvsp[0].ptr_ident);
      param->prev = (yyvsp[-3].ptr_param);
      (yyval.ptr_param) = param;      
}
#line 1576 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 204 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_type) = eInt;
}
#line 1584 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "expr.y" /* yacc.c:1646  */
    {
      (yyval.ptr_type) = eFloat;
}
#line 1592 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 212 "expr.y" /* yacc.c:1646  */
    {
   struct COMPOUNDSTMT *comp = (struct COMPOUNDSTMT *) malloc (sizeof (struct COMPOUNDSTMT));

   comp->decl = NULL;
   comp->stmt = (yyvsp[-1].ptr_stmt);   
   (yyval.ptr_comp) = comp;
}
#line 1604 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 219 "expr.y" /* yacc.c:1646  */
    {
      struct COMPOUNDSTMT *comp = (struct COMPOUNDSTMT *) malloc (sizeof (struct COMPOUNDSTMT));

      comp->decl = (yyvsp[-2].ptr_decl);
      comp->stmt = (yyvsp[-1].ptr_stmt);
      (yyval.ptr_comp) = comp;
}
#line 1616 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "expr.y" /* yacc.c:1646  */
    {
		(yyval.ptr_stmt) = (yyvsp[0].ptr_stmt);
}
#line 1624 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 231 "expr.y" /* yacc.c:1646  */
    {
	   (yyvsp[0].ptr_stmt)->prev = (yyvsp[-1].ptr_stmt);
	   (yyval.ptr_stmt) = (yyvsp[0].ptr_stmt);
}
#line 1633 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 235 "expr.y" /* yacc.c:1646  */
    { 
		struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));
		st = NULL;
		(yyval.ptr_stmt) = st;
	}
#line 1643 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 242 "expr.y" /* yacc.c:1646  */
    {
      struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eAssign;
      st->stmt.assign_ = (yyvsp[0].ptr_ass);
       (yyval.ptr_stmt) = st;
}
#line 1655 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 249 "expr.y" /* yacc.c:1646  */
    {
      struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eCall;
      st->stmt.call_ = (yyvsp[0].ptr_call);
      (yyval.ptr_stmt) = st;
}
#line 1667 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 256 "expr.y" /* yacc.c:1646  */
    {
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eRet;
      st->stmt.return_ = (yyvsp[0].ptr_expr);
      (yyval.ptr_stmt) = st;
}
#line 1679 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 263 "expr.y" /* yacc.c:1646  */
    {
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eWhile;
      st->stmt.while_ = (yyvsp[0].ptr_while);
      (yyval.ptr_stmt) = st;
}
#line 1691 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 270 "expr.y" /* yacc.c:1646  */
    {
        struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eFor;
      st->stmt.for_ = (yyvsp[0].ptr_for);
      (yyval.ptr_stmt) = st;
}
#line 1703 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 277 "expr.y" /* yacc.c:1646  */
    {
         struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eIf;
      st->stmt.if_ = (yyvsp[0].ptr_if);
      (yyval.ptr_stmt) = st;
}
#line 1715 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 284 "expr.y" /* yacc.c:1646  */
    {
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eSwitch;
      st->stmt.switch_ = (yyvsp[0].ptr_switch);
      (yyval.ptr_stmt) = st;
}
#line 1727 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 291 "expr.y" /* yacc.c:1646  */
    {
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eCompound;
      st->stmt.cstmt_ = (yyvsp[0].ptr_comp);
      (yyval.ptr_stmt) = st;
}
#line 1739 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 298 "expr.y" /* yacc.c:1646  */
    {
		struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

		st->s = eSemi;
		(yyval.ptr_stmt) = st;
}
#line 1750 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 306 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_ass) = (yyvsp[-1].ptr_ass);
}
#line 1758 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 311 "expr.y" /* yacc.c:1646  */
    {
   struct ASSIGN *ass = (struct ASSIGN *) malloc (sizeof (struct ASSIGN));

   ass->ID = strdup((yyvsp[-2].id));
   ass->index = NULL;
   ass->expr = (yyvsp[0].ptr_expr);
   (yyval.ptr_ass) = ass;

}
#line 1772 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 320 "expr.y" /* yacc.c:1646  */
    {
      struct ASSIGN *ass = (struct ASSIGN *) malloc (sizeof (struct ASSIGN));

      ass->ID = strdup((yyvsp[-5].id));
      ass->index = (yyvsp[-3].ptr_expr);
      ass->expr = (yyvsp[0].ptr_expr);
      (yyval.ptr_ass) = ass;
}
#line 1785 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 330 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_call) = (yyvsp[-1].ptr_call);
}
#line 1793 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 335 "expr.y" /* yacc.c:1646  */
    {
   struct CALL *call = (struct CALL *) malloc (sizeof (struct CALL));

   call->ID = strdup((yyvsp[-2].id));
   (yyval.ptr_call) = call;
}
#line 1804 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 341 "expr.y" /* yacc.c:1646  */
    {
      struct CALL *call = (struct CALL *) malloc (sizeof (struct CALL));

      call->ID = strdup((yyvsp[-3].id));
      call->arg = (yyvsp[-1].ptr_arg);

      (yyval.ptr_call) = call;      
}
#line 1817 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 351 "expr.y" /* yacc.c:1646  */
    {
   (yyval.ptr_expr) = NULL;
}
#line 1825 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 354 "expr.y" /* yacc.c:1646  */
    {
      (yyval.ptr_expr) = (yyvsp[-1].ptr_expr);
}
#line 1833 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 359 "expr.y" /* yacc.c:1646  */
    {
   struct WHILE_S *wh = (struct WHILE_S *) malloc (sizeof (struct WHILE_S));

   wh->do_while = false;
   wh->cond = (yyvsp[-2].ptr_expr);
   wh->stmt = (yyvsp[0].ptr_stmt);
   (yyval.ptr_while) = wh;   
}
#line 1846 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 367 "expr.y" /* yacc.c:1646  */
    {
      struct WHILE_S *wh = (struct WHILE_S *) malloc (sizeof (struct WHILE_S));

      wh->do_while = true;
      wh->cond = (yyvsp[-2].ptr_expr);
      wh->stmt = (yyvsp[-5].ptr_stmt);
      (yyval.ptr_while) = wh;         
}
#line 1859 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 377 "expr.y" /* yacc.c:1646  */
    {
   struct FOR_S *fo = (struct FOR_S *) malloc (sizeof (struct FOR_S));

   fo->init = (yyvsp[-6].ptr_ass);
   fo->cond = (yyvsp[-4].ptr_expr);
   fo->inc = (yyvsp[-2].ptr_ass);
   fo->stmt = (yyvsp[0].ptr_stmt);
   (yyval.ptr_for) = fo;
}
#line 1873 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 388 "expr.y" /* yacc.c:1646  */
    {
   struct IF_S *if_s = (struct IF_S *) malloc (sizeof (struct IF_S));

   if_s->cond = (yyvsp[-2].ptr_expr);
   if_s->if_ = (yyvsp[0].ptr_stmt);
   if_s->else_ = NULL;
   (yyval.ptr_if) = if_s;
}
#line 1886 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 396 "expr.y" /* yacc.c:1646  */
    {
      struct IF_S *if_s = (struct IF_S *) malloc (sizeof (struct IF_S));

      if_s->cond = (yyvsp[-4].ptr_expr);
      if_s->if_ = (yyvsp[-2].ptr_stmt);
      if_s->else_ = (yyvsp[0].ptr_stmt);
      (yyval.ptr_if) = if_s;
}
#line 1899 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 406 "expr.y" /* yacc.c:1646  */
    {
   struct SWITCH_S *swi = (struct SWITCH_S *) malloc (sizeof (struct SWITCH_S));

   swi->identifier = (yyvsp[-4].ptr_ident);
   swi->case_ = (yyvsp[-1].ptr_case);
   (yyval.ptr_switch) = swi;
}
#line 1911 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 415 "expr.y" /* yacc.c:1646  */
    {
    struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));
    
    ca->break_ = false;
    ca->intnum = (yyvsp[-2].intnum);
    ca->stmt = (yyvsp[0].ptr_stmt);
    ca->prev = NULL;
    (yyval.ptr_case) = ca;
}
#line 1925 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 424 "expr.y" /* yacc.c:1646  */
    {
       struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));
        
        ca->break_ = true;
        ca->intnum = (yyvsp[-4].intnum);
        ca->stmt = (yyvsp[-2].ptr_stmt);
        ca->prev = NULL;
        (yyval.ptr_case) = ca;
}
#line 1939 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 433 "expr.y" /* yacc.c:1646  */
    {
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = false;
        ca->intnum = 0;
        ca->stmt = (yyvsp[0].ptr_stmt);
        ca->prev = NULL;
        (yyval.ptr_case) = ca;
}
#line 1953 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 442 "expr.y" /* yacc.c:1646  */
    {
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = true;
        ca->intnum = 0;
        ca->stmt = (yyvsp[-2].ptr_stmt);
        ca->prev = NULL;
        (yyval.ptr_case) = ca;
}
#line 1967 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 451 "expr.y" /* yacc.c:1646  */
    {
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = false;
        ca->intnum = (yyvsp[-3].intnum);
        ca->stmt = (yyvsp[-1].ptr_stmt);
        ca->prev = (yyvsp[0].ptr_case);
        (yyval.ptr_case) = ca;
}
#line 1981 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 460 "expr.y" /* yacc.c:1646  */
    {
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = true;
        ca->intnum = (yyvsp[-5].intnum);
        ca->stmt = (yyvsp[-3].ptr_stmt);
        ca->prev = (yyvsp[0].ptr_case);
        (yyval.ptr_case) = ca;
}
#line 1995 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 469 "expr.y" /* yacc.c:1646  */
    {   	
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca = NULL;
        (yyval.ptr_case) = ca;
}
#line 2006 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 477 "expr.y" /* yacc.c:1646  */
    {
   struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
   struct UNOP *un = (struct UNOP *) malloc (sizeof (struct UNOP));

   ex->e = eUnop;
   un->u = eNegative;
   un->expr = (yyvsp[0].ptr_expr);
   ex->expression.unop_ = un;
   
   (yyval.ptr_expr) = ex;
}
#line 2022 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 488 "expr.y" /* yacc.c:1646  */
    {
      struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
      struct ADDIOP *addi = (struct ADDIOP *) malloc (sizeof (struct ADDIOP));

      ex->e = eAddi;
      addi->a = ePlus;
      addi->lhs = (yyvsp[-2].ptr_expr);
      addi->rhs = (yyvsp[0].ptr_expr);
      ex->expression.addiop_ = addi;
      
      (yyval.ptr_expr) = ex;

}
#line 2040 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 501 "expr.y" /* yacc.c:1646  */
    {
      struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
      struct ADDIOP *addi = (struct ADDIOP *) malloc (sizeof (struct ADDIOP));

      ex->e = eAddi;
      addi->a = eMinus;
      addi->lhs = (yyvsp[-2].ptr_expr);
      addi->rhs = (yyvsp[0].ptr_expr);
      ex->expression.addiop_ = addi;
      
      (yyval.ptr_expr) = ex;

}
#line 2058 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 514 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct MULTOP *mult = (yyvsp[-1].ptr_mult);

       ex->e = eMulti;
       mult->lhs = (yyvsp[-2].ptr_expr);
       mult->rhs = (yyvsp[0].ptr_expr);
       ex->expression.multop_ = mult;

       (yyval.ptr_expr) = ex;
}
#line 2074 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 525 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct RELAOP *rela = (yyvsp[-1].ptr_rela);

       ex->e = eRela;       
       rela->lhs = (yyvsp[-2].ptr_expr);
       rela->rhs = (yyvsp[0].ptr_expr);
       ex->expression.relaop_ = rela;

       (yyval.ptr_expr) = ex;
}
#line 2090 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 536 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct EQLTOP *eql = (yyvsp[-1].ptr_eqlt);

       ex->e = eEqlt;       
       eql->lhs = (yyvsp[-2].ptr_expr);
       eql->rhs = (yyvsp[0].ptr_expr);
       ex->expression.eqltop_ = eql;

       (yyval.ptr_expr) = ex;

}
#line 2107 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 548 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct CALL *call = (struct CALL *) malloc (sizeof (struct CALL));

       ex->e = eCallExpr;   
       ex->expression.call_ = (yyvsp[0].ptr_call);
       (yyval.ptr_expr) = ex;
}
#line 2120 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 556 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));

       ex->e = eIntnum;
       ex->expression.intnum = (yyvsp[0].intnum);
       (yyval.ptr_expr) = ex;
}
#line 2132 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 563 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));

       ex->e = eFloatnum;
       ex->expression.floatnum = (yyvsp[0].floatnum);
       (yyval.ptr_expr) = ex;
}
#line 2144 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 570 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct ID_S *id = (struct ID_S *) malloc (sizeof (struct ID_S));

       ex->e = eId;
       id->ID = strdup((yyvsp[0].id));
       ex->expression.ID_ = id;
       (yyval.ptr_expr) = ex;
}
#line 2158 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 579 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct ID_S *id = (struct ID_S *) malloc (sizeof (struct ID_S));

       ex->e = eId;
       id->ID = strdup((yyvsp[-3].id));
       id->expr = (yyvsp[-1].ptr_expr);
       ex->expression.ID_ = id;
       (yyval.ptr_expr) = ex;
}
#line 2173 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 589 "expr.y" /* yacc.c:1646  */
    {
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));       

       ex->e = eExpr;
       ex->expression.bracket = (yyvsp[-1].ptr_expr);
       (yyval.ptr_expr) = ex;
}
#line 2185 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 598 "expr.y" /* yacc.c:1646  */
    {
       struct ARG *arg = (struct ARG *) malloc(sizeof(struct ARG ));
       arg->expr = (yyvsp[0].ptr_expr);
       arg->prev = NULL;
       (yyval.ptr_arg) = arg;
}
#line 2196 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 604 "expr.y" /* yacc.c:1646  */
    {
       struct ARG *arg = (struct ARG *) malloc(sizeof(struct ARG ));
       arg->expr = (yyvsp[0].ptr_expr);
       arg->prev = (yyvsp[-2].ptr_arg);
       (yyval.ptr_arg) = arg;
}
#line 2207 "expr.tab.c" /* yacc.c:1646  */
    break;


#line 2211 "expr.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 611 "expr.y" /* yacc.c:1906  */


int yyerror (char *s) {
   return fprintf (stderr, "%s\n", s);
}
