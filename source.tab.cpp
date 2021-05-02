/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONST = 258,
     INT = 259,
     VOID = 260,
     IF = 261,
     WHILE = 262,
     ELSE = 263,
     CONTINUE = 264,
     BREAK = 265,
     RETURN = 266,
     COMMA = 267,
     SEMICOLON = 268,
     LSQUARE = 269,
     RSQUARE = 270,
     LPAREN = 271,
     RPAREN = 272,
     ASSIGN = 273,
     LBRACE = 274,
     RBRACE = 275,
     ADD = 276,
     SUB = 277,
     MUL = 278,
     DIV = 279,
     MOD = 280,
     LT = 281,
     GT = 282,
     LE = 283,
     GE = 284,
     EQ = 285,
     NEQ = 286,
     AND = 287,
     OR = 288,
     NOT = 289,
     NUM = 290,
     ID = 291,
     ERROR = 292,
     POSITIVE = 293,
     NEGATIVE = 294
   };
#endif
/* Tokens.  */
#define CONST 258
#define INT 259
#define VOID 260
#define IF 261
#define WHILE 262
#define ELSE 263
#define CONTINUE 264
#define BREAK 265
#define RETURN 266
#define COMMA 267
#define SEMICOLON 268
#define LSQUARE 269
#define RSQUARE 270
#define LPAREN 271
#define RPAREN 272
#define ASSIGN 273
#define LBRACE 274
#define RBRACE 275
#define ADD 276
#define SUB 277
#define MUL 278
#define DIV 279
#define MOD 280
#define LT 281
#define GT 282
#define LE 283
#define GE 284
#define EQ 285
#define NEQ 286
#define AND 287
#define OR 288
#define NOT 289
#define NUM 290
#define ID 291
#define ERROR 292
#define POSITIVE 293
#define NEGATIVE 294




/* Copy the first part of user declarations.  */
#line 1 "source.y"

#include "globals.h"
#include "util.h"
#include "ast.h"

static BaseAST *savedTree;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "source.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    17,    19,
      21,    26,    28,    32,    37,    42,    43,    45,    49,    52,
      54,    58,    62,    64,    68,    73,    76,    78,    82,    85,
      87,    91,    98,   104,   111,   117,   119,   123,   126,   132,
     136,   137,   140,   142,   144,   146,   148,   150,   152,   154,
     156,   162,   170,   178,   184,   190,   195,   197,   200,   202,
     205,   208,   211,   215,   217,   219,   222,   223,   228,   232,
     234,   236,   238,   243,   247,   250,   253,   256,   258,   262,
     264,   268,   272,   276,   278,   282,   286,   288,   292,   296,
     300,   304,   306,   310,   314,   316,   320,   322,   326,   328
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    -1,    55,    -1,    42,
      43,    -1,    42,    55,    -1,    82,    -1,    44,    -1,    50,
      -1,     3,     4,    45,    13,    -1,    46,    -1,    45,    12,
      46,    -1,    36,    47,    18,    48,    -1,    47,    14,    81,
      15,    -1,    -1,    81,    -1,    19,    49,    20,    -1,    19,
      20,    -1,    48,    -1,    49,    12,    48,    -1,     4,    51,
      13,    -1,    52,    -1,    51,    12,    52,    -1,    36,    47,
      18,    53,    -1,    36,    47,    -1,    68,    -1,    19,    54,
      20,    -1,    19,    20,    -1,    53,    -1,    54,    12,    53,
      -1,     5,    36,    16,    56,    17,    58,    -1,     5,    36,
      16,    17,    58,    -1,     4,    36,    16,    56,    17,    58,
      -1,     4,    36,    16,    17,    58,    -1,    57,    -1,    56,
      12,    57,    -1,     4,    36,    -1,     4,    36,    14,    15,
      47,    -1,    19,    59,    20,    -1,    -1,    59,    60,    -1,
      43,    -1,    61,    -1,    67,    -1,    63,    -1,    65,    -1,
      67,    -1,    64,    -1,    66,    -1,     6,    16,    69,    17,
      61,    -1,     6,    16,    69,    17,    62,     8,    61,    -1,
       6,    16,    69,    17,    62,     8,    62,    -1,     7,    16,
      69,    17,    61,    -1,     7,    16,    69,    17,    62,    -1,
      70,    18,    68,    13,    -1,    13,    -1,    68,    13,    -1,
      58,    -1,    10,    13,    -1,     9,    13,    -1,    11,    13,
      -1,    11,    68,    13,    -1,    69,    -1,    80,    -1,    36,
      71,    -1,    -1,    71,    14,    68,    15,    -1,    16,    68,
      17,    -1,    70,    -1,    35,    -1,    72,    -1,    36,    16,
      74,    17,    -1,    36,    16,    17,    -1,    21,    73,    -1,
      22,    73,    -1,    34,    73,    -1,    68,    -1,    74,    12,
      68,    -1,    73,    -1,    75,    23,    73,    -1,    75,    24,
      73,    -1,    75,    25,    73,    -1,    75,    -1,    76,    21,
      75,    -1,    76,    22,    75,    -1,    76,    -1,    77,    27,
      76,    -1,    77,    26,    76,    -1,    77,    29,    76,    -1,
      77,    28,    76,    -1,    77,    -1,    78,    30,    77,    -1,
      78,    31,    77,    -1,    78,    -1,    79,    32,    78,    -1,
      79,    -1,    80,    33,    79,    -1,    69,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    19,    19,    22,    23,    24,    30,    36,    38,    39,
      41,    46,    51,    57,    63,    68,    70,    75,    76,    82,
      87,    93,    95,   100,   106,   107,   109,   114,   115,   121,
     126,   133,   138,   144,   149,   156,   161,   167,   172,   181,
     183,   184,   190,   191,   193,   194,   195,   197,   198,   199,
     201,   202,   204,   206,   208,   210,   211,   212,   213,   214,
     215,   216,   217,   220,   222,   224,   226,   227,   233,   234,
     235,   237,   238,   239,   244,   245,   246,   248,   253,   259,
     260,   261,   262,   264,   265,   266,   268,   269,   270,   271,
     272,   274,   275,   276,   278,   279,   281,   282,   284,   286
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "INT", "VOID", "IF", "WHILE",
  "ELSE", "CONTINUE", "BREAK", "RETURN", "COMMA", "SEMICOLON", "LSQUARE",
  "RSQUARE", "LPAREN", "RPAREN", "ASSIGN", "LBRACE", "RBRACE", "ADD",
  "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NEQ", "AND",
  "OR", "NOT", "NUM", "ID", "ERROR", "POSITIVE", "NEGATIVE", "$accept",
  "Program", "CompUnit", "Decl", "ConstDecl", "ConstDeclList", "ConstDef",
  "ConstDimensions", "ConstInitVal", "ConstInitValList", "VarDecl",
  "VarDeclList", "VarDef", "InitVal", "InitValList", "FuncDef",
  "FuncFParams", "FuncFParam", "Block", "BlockItemList", "BlockItem",
  "FreeStmt", "BoundedStmt", "FreeIfStmt", "BoundedIfStmt",
  "FreeWhileStmt", "BoundedWhileStmt", "NonIfStmt", "Exp", "Cond", "LVal",
  "Dimensions", "PrimaryExp", "UnaryExp", "FuncRParams", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", "Error", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    42,    43,    43,
      44,    45,    45,    46,    47,    47,    48,    48,    48,    49,
      49,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    56,    56,    57,    57,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    62,
      63,    63,    64,    65,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    70,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       4,     1,     3,     4,     4,     0,     1,     3,     2,     1,
       3,     3,     1,     3,     4,     2,     1,     3,     2,     1,
       3,     6,     5,     6,     5,     1,     3,     2,     5,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     7,     5,     5,     4,     1,     2,     1,     2,
       2,     2,     3,     1,     1,     2,     0,     4,     3,     1,
       1,     1,     4,     3,     2,     2,     2,     1,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    99,     0,     2,     3,     8,     9,
       4,     7,     0,    15,     0,    22,     0,     1,     5,     6,
      15,     0,    11,     0,    25,     0,    21,     0,     0,     0,
      10,     0,     0,     0,    35,     0,     0,    15,    23,     0,
       0,     0,    12,    37,    40,    34,     0,     0,     0,     0,
       0,     0,    70,    66,    98,    69,    71,    79,    83,    86,
      91,    94,    96,    64,     0,     0,    24,    26,    63,    32,
       0,     0,    13,    16,     0,     0,    36,    33,     0,    74,
      75,    76,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    28,    29,
       0,    31,    18,    19,     0,    15,     0,     0,     0,     0,
       0,     0,    56,    39,    42,    58,    41,    43,    45,    46,
      44,     0,    69,    68,    73,    77,     0,     0,    80,    81,
      82,    84,    85,    88,    87,    90,    89,    92,    93,    95,
      97,     0,    27,     0,    17,    38,     0,     0,    60,    59,
      61,     0,    57,     0,     0,    72,     0,    30,    20,     0,
       0,    62,     0,    78,    67,     0,     0,    55,     0,     0,
      50,     0,    48,    49,    44,    53,     0,     0,     0,     0,
       0,    51,     0,     0,     0,    54,     0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    21,    22,    24,    72,   104,
       9,    14,    15,    66,   100,    10,    33,    34,   115,    75,
     116,   170,   171,   118,   172,   119,   173,   174,   121,    68,
      55,    83,    56,    57,   126,    58,    59,    60,    61,    62,
      63,    73,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -157
static const yytype_int16 yypact[] =
{
      17,    36,     9,    20,  -157,    59,   148,  -157,  -157,  -157,
    -157,  -157,    25,    52,    -3,  -157,    63,  -157,  -157,  -157,
    -157,    30,  -157,     8,    55,    51,  -157,    15,    64,    25,
    -157,    60,    62,    12,  -157,   195,   187,  -157,  -157,    62,
      16,   191,  -157,    81,  -157,  -157,    99,    62,   195,   195,
     195,   195,  -157,    89,  -157,  -157,  -157,  -157,   131,    50,
      73,    61,    77,    80,   102,   159,  -157,  -157,  -157,  -157,
      62,   166,  -157,  -157,   110,   124,  -157,  -157,   109,  -157,
    -157,  -157,   198,   115,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,  -157,  -157,  -157,
      45,  -157,  -157,  -157,    46,  -157,    51,   116,   120,   125,
     126,    54,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,   144,   145,  -157,  -157,  -157,    43,   195,  -157,  -157,
    -157,   131,   131,    50,    50,    50,    50,    73,    73,    61,
      77,   187,  -157,   191,  -157,   153,   195,   195,  -157,  -157,
    -157,   156,  -157,   195,   195,  -157,   157,  -157,  -157,   167,
     175,  -157,   160,  -157,  -157,    28,   155,  -157,   154,   180,
    -157,   189,  -157,  -157,   190,  -157,   195,   195,   155,   182,
     188,  -157,    28,    28,   196,  -157,    28,  -157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,    -1,  -157,  -157,   199,   -19,   -60,  -157,
    -157,  -157,   158,   -61,  -157,   212,   197,   192,   -24,  -157,
    -157,   -62,  -156,  -157,  -157,  -157,  -157,   -72,   -34,   -35,
     -68,  -157,  -157,   -33,  -157,    35,    58,    -9,   140,   141,
    -157,   201,  -157
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      54,    28,    67,   120,    99,    18,    54,   122,    45,    25,
      26,   103,    31,   117,    78,    69,    79,    80,    81,    31,
       1,     2,     3,    77,    46,    32,   184,   185,    46,    47,
     187,    67,    39,    70,   168,   169,    54,   109,   110,   111,
      12,   112,    29,    30,    48,    13,   101,    44,   125,    49,
      50,   128,   129,   130,     4,   154,    16,   141,   143,    17,
     155,    20,    51,    52,    53,   142,   144,   150,    23,    35,
      48,    87,    88,    36,   114,    49,    50,   151,    35,    27,
     157,    44,    41,   158,   137,   138,   145,    37,    51,    52,
      53,    93,    94,   156,   120,    74,    43,   122,   122,    89,
      90,    91,    92,    31,   175,    82,   120,    67,    54,    95,
     122,   159,   160,    96,   122,   122,   181,    97,   122,   162,
     163,   175,   131,   132,   181,   105,   123,     1,   106,   127,
     107,   108,   146,   109,   110,   111,   147,   112,   148,   149,
      48,   179,   180,    44,   113,    49,    50,   133,   134,   135,
     136,     1,     2,     3,    84,    85,    86,   152,    51,    52,
      53,   107,   108,   153,   109,   110,   111,    35,   112,   161,
     176,    48,   164,   167,    44,    48,    49,    50,    65,    98,
      49,    50,    48,    38,   165,    71,   102,    49,    50,    51,
      52,    53,   166,    51,    52,    53,   177,   178,   -47,   182,
      51,    52,    53,    48,   186,   183,    65,    48,    49,    50,
      71,    48,    49,    50,    48,   124,    49,    50,    19,    49,
      50,    51,    52,    53,    40,    51,    52,    53,    42,    51,
      52,    53,    51,    52,    53,   139,    64,   140,    76
};

static const yytype_uint8 yycheck[] =
{
      35,    20,    36,    75,    65,     6,    41,    75,    32,    12,
      13,    71,     4,    75,    48,    39,    49,    50,    51,     4,
       3,     4,     5,    47,    12,    17,   182,   183,    12,    17,
     186,    65,    17,    17,     6,     7,    71,     9,    10,    11,
       4,    13,    12,    13,    16,    36,    70,    19,    82,    21,
      22,    84,    85,    86,    37,    12,    36,    12,    12,     0,
      17,    36,    34,    35,    36,    20,    20,    13,    16,    14,
      16,    21,    22,    18,    75,    21,    22,   111,    14,    16,
     141,    19,    18,   143,    93,    94,   105,    36,    34,    35,
      36,    30,    31,   127,   166,    14,    36,   165,   166,    26,
      27,    28,    29,     4,   166,    16,   178,   141,   143,    32,
     178,   146,   147,    33,   182,   183,   178,    15,   186,   153,
     154,   183,    87,    88,   186,    15,    17,     3,     4,    14,
       6,     7,    16,     9,    10,    11,    16,    13,    13,    13,
      16,   176,   177,    19,    20,    21,    22,    89,    90,    91,
      92,     3,     4,     5,    23,    24,    25,    13,    34,    35,
      36,     6,     7,    18,     9,    10,    11,    14,    13,    13,
      16,    16,    15,    13,    19,    16,    21,    22,    19,    20,
      21,    22,    16,    25,    17,    19,    20,    21,    22,    34,
      35,    36,    17,    34,    35,    36,    16,     8,     8,    17,
      34,    35,    36,    16,     8,    17,    19,    16,    21,    22,
      19,    16,    21,    22,    16,    17,    21,    22,     6,    21,
      22,    34,    35,    36,    27,    34,    35,    36,    29,    34,
      35,    36,    34,    35,    36,    95,    35,    96,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    37,    41,    42,    43,    44,    50,
      55,    82,     4,    36,    51,    52,    36,     0,    43,    55,
      36,    45,    46,    16,    47,    12,    13,    16,    47,    12,
      13,     4,    17,    56,    57,    14,    18,    36,    52,    17,
      56,    18,    46,    36,    19,    58,    12,    17,    16,    21,
      22,    34,    35,    36,    69,    70,    72,    73,    75,    76,
      77,    78,    79,    80,    81,    19,    53,    68,    69,    58,
      17,    19,    48,    81,    14,    59,    57,    58,    68,    73,
      73,    73,    16,    71,    23,    24,    25,    21,    22,    26,
      27,    28,    29,    30,    31,    32,    33,    15,    20,    53,
      54,    58,    20,    48,    49,    15,     4,     6,     7,     9,
      10,    11,    13,    20,    43,    58,    60,    61,    63,    65,
      67,    68,    70,    17,    17,    68,    74,    14,    73,    73,
      73,    75,    75,    76,    76,    76,    76,    77,    77,    78,
      79,    12,    20,    12,    20,    47,    16,    16,    13,    13,
      13,    68,    13,    18,    12,    17,    68,    53,    48,    69,
      69,    13,    68,    68,    15,    17,    17,    13,     6,     7,
      61,    62,    64,    66,    67,    61,    16,    16,     8,    69,
      69,    61,    17,    17,    62,    62,     8,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 19 "source.y"
    {savedTree = (yyvsp[(1) - (1)]);;}
    break;

  case 3:
#line 22 "source.y"
    {ASTList t={(yyvsp[(1) - (1)])};(yyval)=new CompUnitAST(t);;}
    break;

  case 4:
#line 23 "source.y"
    {ASTList t={(yyvsp[(1) - (1)])};(yyval)=new CompUnitAST(t);;}
    break;

  case 5:
#line 25 "source.y"
    {
						YYSTYPE t=(yyvsp[(1) - (2)]);
						t->nodeList().push_back((yyvsp[(2) - (2)]));
						(yyval)=t;
					;}
    break;

  case 6:
#line 31 "source.y"
    {
						YYSTYPE t=(yyvsp[(1) - (2)]);
						t->nodeList().push_back((yyvsp[(2) - (2)]));
						(yyval)=t;
					;}
    break;

  case 7:
#line 36 "source.y"
    {;}
    break;

  case 8:
#line 38 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 9:
#line 39 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 10:
#line 42 "source.y"
    {
						(yyval)=new ConstDeclAST(INT, (yyvsp[(3) - (4)])->astList());
					;}
    break;

  case 11:
#line 47 "source.y"
    {
						ASTList t={(yyvsp[(1) - (1)])};
						(yyval)=new ASTListAST(t);
					;}
    break;

  case 12:
#line 52 "source.y"
    {
						(yyval) = (yyvsp[(1) - (3)]);
						(yyval)->astList().push_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 13:
#line 58 "source.y"
    {
						puts("constdef");
						(yyval)=new ConstDefAST((yyvsp[(1) - (4)])->name(), (yyvsp[(2) - (4)])->astList(), (yyvsp[(4) - (4)]));
					;}
    break;

  case 14:
#line 64 "source.y"
    {
						(yyval) = (yyvsp[(1) - (4)]);
						(yyval)->astList().push_back((yyvsp[(3) - (4)]));
					;}
    break;

  case 15:
#line 68 "source.y"
    {(yyval)=new ASTListAST();;}
    break;

  case 16:
#line 71 "source.y"
    {
						ASTList t;
						(yyval) = new ConstInitValAST((yyvsp[(1) - (1)]), t);
					;}
    break;

  case 17:
#line 75 "source.y"
    {(yyval) = new ConstInitValAST(NULL, (yyvsp[(2) - (3)])->astList());;}
    break;

  case 18:
#line 77 "source.y"
    {
						ASTList t;
						(yyval) = new ConstInitValAST(NULL, t);
					;}
    break;

  case 19:
#line 83 "source.y"
    {
						(yyval) = new ASTListAST();
						(yyval)->astList().push_back((yyvsp[(1) - (1)]));
					;}
    break;

  case 20:
#line 88 "source.y"
    {
						(yyval) = (yyvsp[(1) - (3)]);
						(yyval)->astList().push_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 21:
#line 93 "source.y"
    {(yyval) = new VarDeclAST(INT, (yyvsp[(2) - (3)])->astList());;}
    break;

  case 22:
#line 96 "source.y"
    {
						ASTList t = {(yyvsp[(1) - (1)])};
						(yyval) = new ASTListAST(t);
					;}
    break;

  case 23:
#line 101 "source.y"
    {
						(yyval) = (yyvsp[(1) - (3)]);
						(yyval)->astList().push_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 24:
#line 106 "source.y"
    {(yyval) = new VarDefAST((yyvsp[(1) - (4)])->name(), (yyvsp[(2) - (4)])->astList(), (yyvsp[(4) - (4)]));;}
    break;

  case 25:
#line 107 "source.y"
    {(yyval) = new VarDefAST((yyvsp[(1) - (2)])->name(), (yyvsp[(2) - (2)])->astList(), NULL);;}
    break;

  case 26:
#line 110 "source.y"
    {
						ASTList t;
						(yyval) = new InitValAST((yyvsp[(1) - (1)]), t);
					;}
    break;

  case 27:
#line 114 "source.y"
    {(yyval) = new InitValAST(NULL, (yyvsp[(2) - (3)])->astList());;}
    break;

  case 28:
#line 116 "source.y"
    {
						ASTList t;
						(yyval) = new InitValAST(NULL, t);
					;}
    break;

  case 29:
#line 122 "source.y"
    {
						(yyval) = new ASTListAST();
						(yyval)->astList().push_back((yyvsp[(1) - (1)]));
					;}
    break;

  case 30:
#line 127 "source.y"
    {
						(yyval) = (yyvsp[(1) - (3)]); 
						(yyval)->astList().push_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 31:
#line 134 "source.y"
    {
						(yyval) = new FunctionAST(VOID, (yyvsp[(2) - (6)])->name(), 
							(yyvsp[(4) - (6)])->astList(), (yyvsp[(6) - (6)]));
					;}
    break;

  case 32:
#line 139 "source.y"
    {
						ASTList t;
						(yyval) = new FunctionAST(VOID, (yyvsp[(2) - (5)])->name(), 
							t, (yyvsp[(5) - (5)]));
					;}
    break;

  case 33:
#line 145 "source.y"
    {
						(yyval) = new FunctionAST(INT, (yyvsp[(2) - (6)])->name(), 
							(yyvsp[(4) - (6)])->astList(), (yyvsp[(6) - (6)]));
					;}
    break;

  case 34:
#line 150 "source.y"
    {
						ASTList t;
						(yyval) = new FunctionAST(INT, (yyvsp[(2) - (5)])->name(), 
							t, (yyvsp[(5) - (5)]));
					;}
    break;

  case 35:
#line 157 "source.y"
    {
						ASTList t = {(yyvsp[(1) - (1)])};
						(yyval) = new ASTListAST(t);
					;}
    break;

  case 36:
#line 162 "source.y"
    {
						(yyval) = (yyvsp[(1) - (3)]);
						(yyval)->astList().push_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 37:
#line 168 "source.y"
    {
						ASTList t = {NULL};
						(yyval) = new FuncFParamAST(INT, (yyvsp[(2) - (2)])->name(), t);
					;}
    break;

  case 38:
#line 172 "source.y"
    {
					ASTList t = {NULL};
					(yyval) = new FuncFParamAST(INT, (yyvsp[(2) - (5)])->name(), t);
					for(auto &each: (yyvsp[(5) - (5)])->astList()) {
						(yyval)->dimensions().push_back(each);
					}
				;}
    break;

  case 39:
#line 181 "source.y"
    {(yyval)=new BlockAST((yyvsp[(2) - (3)])->astList());;}
    break;

  case 40:
#line 183 "source.y"
    {(yyval)=new ASTListAST();;}
    break;

  case 41:
#line 185 "source.y"
    {
						(yyval) = (yyvsp[(1) - (2)]);
						(yyval)->astList().push_back((yyvsp[(2) - (2)]));
					;}
    break;

  case 42:
#line 190 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 43:
#line 191 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 44:
#line 193 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 45:
#line 194 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 46:
#line 195 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 47:
#line 197 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 48:
#line 198 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 49:
#line 199 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 50:
#line 201 "source.y"
    {(yyval) = new IfStatAST((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), NULL);;}
    break;

  case 51:
#line 202 "source.y"
    {(yyval) = new IfStatAST((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));;}
    break;

  case 52:
#line 204 "source.y"
    {(yyval) = new IfStatAST((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));;}
    break;

  case 53:
#line 206 "source.y"
    {(yyval) = new WhileStatAST((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 54:
#line 208 "source.y"
    {(yyval) = new WhileStatAST((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 55:
#line 210 "source.y"
    {(yyval)=new AssignStatAST((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 56:
#line 211 "source.y"
    {(yyval) = new DoNothingAST();;}
    break;

  case 57:
#line 212 "source.y"
    {(yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 58:
#line 213 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 59:
#line 214 "source.y"
    {(yyval) = new BreakAST();;}
    break;

  case 60:
#line 215 "source.y"
    {(yyval) = new ContinueAST();;}
    break;

  case 61:
#line 216 "source.y"
    {(yyval) = new ReturnAST(NULL);;}
    break;

  case 62:
#line 217 "source.y"
    {(yyval) = new ReturnAST((yyvsp[(2) - (3)]));;}
    break;

  case 63:
#line 220 "source.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 64:
#line 222 "source.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 65:
#line 224 "source.y"
    {(yyval) = new LValAST((yyvsp[(1) - (2)])->name(), (yyvsp[(2) - (2)])->astList());;}
    break;

  case 66:
#line 226 "source.y"
    {(yyval) = new ASTListAST();;}
    break;

  case 67:
#line 228 "source.y"
    {
						(yyval) = (yyvsp[(1) - (4)]);
						(yyval)->astList().push_back((yyvsp[(3) - (4)]));
					;}
    break;

  case 68:
#line 233 "source.y"
    {(yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 69:
#line 234 "source.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 70:
#line 235 "source.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 71:
#line 237 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 72:
#line 238 "source.y"
    {(yyval) = new FuncCallAST((yyvsp[(1) - (4)])->name(), (yyvsp[(3) - (4)])->astList());;}
    break;

  case 73:
#line 240 "source.y"
    {
						ASTList t;
						(yyval) = new FuncCallAST((yyvsp[(1) - (3)])->name(), t);
					;}
    break;

  case 74:
#line 244 "source.y"
    {(yyval) = new UnaryExpAST(POSITIVE, (yyvsp[(2) - (2)]));;}
    break;

  case 75:
#line 245 "source.y"
    {(yyval) = new UnaryExpAST(NEGATIVE, (yyvsp[(2) - (2)]));;}
    break;

  case 76:
#line 246 "source.y"
    {(yyval) = new UnaryExpAST(NOT, (yyvsp[(2) - (2)]));;}
    break;

  case 77:
#line 249 "source.y"
    {
						ASTList t = {(yyvsp[(1) - (1)])};
						(yyval) = new ASTListAST(t);
					;}
    break;

  case 78:
#line 254 "source.y"
    {
						(yyval) = (yyvsp[(1) - (3)]);
						(yyval)->astList().push_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 79:
#line 259 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 80:
#line 260 "source.y"
    {(yyval) = new BinaryExpAST(MUL, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 81:
#line 261 "source.y"
    {(yyval) = new BinaryExpAST(DIV, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 82:
#line 262 "source.y"
    {(yyval) = new BinaryExpAST(MOD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 83:
#line 264 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 84:
#line 265 "source.y"
    {(yyval) = new BinaryExpAST(ADD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 85:
#line 266 "source.y"
    {(yyval) = new BinaryExpAST(SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 86:
#line 268 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 87:
#line 269 "source.y"
    {(yyval) = new BinaryExpAST(GT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 88:
#line 270 "source.y"
    {(yyval) = new BinaryExpAST(LT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 89:
#line 271 "source.y"
    {(yyval) = new BinaryExpAST(GE, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 90:
#line 272 "source.y"
    {(yyval) = new BinaryExpAST(LE, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 91:
#line 274 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 92:
#line 275 "source.y"
    {(yyval) = new BinaryExpAST(EQ, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 93:
#line 276 "source.y"
    {(yyval) = new BinaryExpAST(NEQ, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 94:
#line 278 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 95:
#line 279 "source.y"
    {(yyval) = new BinaryExpAST(AND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 96:
#line 281 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 97:
#line 282 "source.y"
    {(yyval) = new BinaryExpAST(OR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 98:
#line 284 "source.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 99:
#line 286 "source.y"
    {yyerror("Unexpected Token!");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2151 "source.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 289 "source.y"


ASTPtr parse()
{
	yyparse();
	return savedTree;
}

void yyerror(const char *s)
{  
    cerr<<s<<endl;
}  
