
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "CMINUS.y"

#include"CMINUS.h"

void yyerror(char *);
int yylex();
void toGramTree(int level ,char *name);

extern int yylineno;
int err=0;
char gramTree[10000]="";


/* Line 189 of yacc.c  */
#line 86 "CMINUS.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     ID = 260,
     SEMI = 261,
     COMMA = 262,
     ASSIGNOP = 263,
     RELOP = 264,
     PLUS = 265,
     MINUS = 266,
     STAR = 267,
     DIV = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     DOT = 272,
     TYPE = 273,
     LP = 274,
     RP = 275,
     LB = 276,
     RB = 277,
     LC = 278,
     RC = 279,
     STRUCT = 280,
     RETURN = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     FNCT = 285,
     ERRORA = 286
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "CMINUS.y"

	int vali;
	float valf;
	SYMREC *tptr;
	int type;
	EXPVAL expval;
	NODE node;



/* Line 214 of yacc.c  */
#line 164 "CMINUS.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 176 "CMINUS.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,     9,    13,    17,    20,
      21,    26,    28,    29,    34,    35,    38,    39,    42,    48,
      51,    52,    54,    56,    57,    60,    65,    66,    73,    74,
      80,    81,    86,    90,    92,    95,    96,   102,   103,   104,
     108,   109,   113,   114,   119,   120,   123,   124,   129,   135,
     136,   145,   146,   153,   154,   155,   159,   160,   165,   167,
     171,   173,   177,   182,   186,   190,   194,   198,   202,   206,
     210,   214,   218,   221,   224,   229,   233,   238,   244,   248,
     250,   252,   254,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    -1,    34,    35,    -1,    -1,    -1,    36,
      37,    35,    -1,    41,    39,     6,    -1,    41,     6,    -1,
      -1,    38,    41,    50,    55,    -1,    47,    -1,    -1,    47,
      40,     7,    39,    -1,    -1,    42,    18,    -1,    -1,    43,
      44,    -1,    25,    45,    23,    66,    24,    -1,    25,    46,
      -1,    -1,     5,    -1,     5,    -1,    -1,    48,     5,    -1,
      47,    21,     3,    22,    -1,    -1,    49,    47,    21,     3,
       1,    22,    -1,    -1,     5,    19,    51,    53,    20,    -1,
      -1,     5,    19,    52,    20,    -1,    54,     7,    53,    -1,
      54,    -1,    41,    47,    -1,    -1,    56,    23,    66,    57,
      24,    -1,    -1,    -1,    58,    59,    57,    -1,    -1,    60,
      72,     6,    -1,    -1,    61,    72,     1,     6,    -1,    -1,
      62,    55,    -1,    -1,    63,    26,    72,     6,    -1,    27,
      19,    72,    20,    59,    -1,    -1,    27,    19,    72,    20,
      59,    28,    64,    59,    -1,    -1,    65,    29,    19,    72,
      20,    59,    -1,    -1,    -1,    67,    68,    66,    -1,    -1,
      69,    41,    70,     6,    -1,    71,    -1,    71,     7,    70,
      -1,    47,    -1,    47,     8,    72,    -1,    47,     8,     1,
      72,    -1,    72,     8,    72,    -1,    72,    14,    72,    -1,
      72,    15,    72,    -1,    72,     9,    72,    -1,    72,    10,
      72,    -1,    72,    11,    72,    -1,    72,    12,    72,    -1,
      72,    13,    72,    -1,    19,    72,    20,    -1,    11,    72,
      -1,    16,    72,    -1,     5,    19,    73,    20,    -1,     5,
      19,    20,    -1,    72,    21,    72,    22,    -1,    72,    21,
      72,     1,    22,    -1,    72,    17,     5,    -1,     5,    -1,
       3,    -1,     4,    -1,    72,     7,    73,    -1,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    48,    49,    50,    50,    52,    53,    54,
      54,    56,    57,    57,    59,    59,    60,    60,    62,    63,
      65,    66,    68,    70,    70,    71,    72,    72,    74,    74,
      75,    75,    77,    78,    80,    82,    82,    84,    85,    85,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    92,
      92,    93,    93,    95,    96,    96,    98,    98,   100,   101,
     103,   104,   105,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   129,   130
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "SEMI", "COMMA",
  "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "NOT",
  "DOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "FNCT", "ERRORA", "$accept", "Program", "$@1",
  "ExtDefList", "$@2", "ExtDef", "$@3", "ExtDecList", "$@4", "Specifier",
  "$@5", "$@6", "StructSpecifier", "OptTag", "Tag", "VarDec", "$@7", "$@8",
  "FunDec", "$@9", "$@10", "VarList", "ParamDec", "CompSt", "$@11",
  "StmtList", "$@12", "Stmt", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "DefList", "$@19", "Def", "$@20", "DecList", "Dec", "Exp",
  "Args", 0
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
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    34,    33,    35,    36,    35,    37,    37,    38,
      37,    39,    40,    39,    42,    41,    43,    41,    44,    44,
      45,    45,    46,    48,    47,    47,    49,    47,    51,    50,
      52,    50,    53,    53,    54,    56,    55,    57,    58,    57,
      60,    59,    61,    59,    62,    59,    63,    59,    59,    64,
      59,    65,    59,    66,    67,    66,    69,    68,    70,    70,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     0,     3,     3,     2,     0,
       4,     1,     0,     4,     0,     2,     0,     2,     5,     2,
       0,     1,     1,     0,     2,     4,     0,     6,     0,     5,
       0,     4,     3,     1,     2,     0,     5,     0,     0,     3,
       0,     3,     0,     4,     0,     2,     0,     4,     5,     0,
       8,     0,     6,     0,     0,     3,     0,     4,     1,     3,
       1,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     5,     3,     1,
       1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     3,     9,     5,    14,    23,     0,
       0,     6,     0,     8,     0,    11,     0,    23,    15,    20,
      17,     0,    35,     7,     0,     0,    24,     0,    22,     0,
      19,    28,    10,     0,     0,    23,     0,    54,    14,     0,
      53,    25,    13,     0,     0,    56,    23,     0,    33,    31,
      38,     0,    18,    53,    14,    34,    29,    14,     0,    40,
      27,    55,    23,    32,    36,     0,    38,     0,     0,    35,
       0,     0,    60,     0,    58,     0,    39,    80,    81,    79,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    57,
      23,     0,     0,    72,    73,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    59,    40,    75,    83,     0,    71,    63,    66,
      67,    68,    69,    70,    64,    65,    78,     0,    43,    47,
       0,    62,    48,     0,    74,     0,    76,    40,    49,    82,
      77,    52,    40,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     5,     6,     7,    14,    25,    46,
       9,    10,    20,    29,    30,    15,    16,    17,    22,    38,
      39,    47,    48,    32,    33,    58,    59,    66,    67,    68,
      69,    70,   142,    71,    44,    45,    53,    54,    73,    74,
     115,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
    -112,    20,    28,  -112,  -112,  -112,    28,     7,    24,    15,
      17,  -112,    44,  -112,    42,     0,    54,  -112,  -112,    56,
    -112,    47,  -112,  -112,    59,    61,  -112,    48,    40,    49,
    -112,    50,  -112,    68,    71,  -112,    91,    74,     7,    51,
     -10,  -112,  -112,     5,    75,  -112,  -112,    82,    88,  -112,
      79,    87,  -112,   -10,     7,    89,  -112,     7,    92,   -13,
    -112,  -112,  -112,  -112,  -112,    93,    79,   103,   103,  -112,
      94,    84,     1,   105,   108,   103,  -112,  -112,  -112,    98,
     103,   103,   103,   115,    66,  -112,   103,    99,    81,  -112,
    -112,   158,    85,   200,   200,   172,  -112,   103,   103,   103,
     103,   103,   103,   103,   103,   126,   103,   127,   129,   103,
     103,   200,  -112,   -13,  -112,   144,   114,  -112,   200,   200,
     200,   200,   200,   200,   200,   200,  -112,    43,  -112,  -112,
     186,   200,   117,   103,  -112,   125,  -112,   -13,  -112,  -112,
    -112,  -112,   -13,  -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,   142,  -112,  -112,  -112,   128,  -112,    -4,
    -112,  -112,  -112,  -112,  -112,   -17,  -112,  -112,  -112,  -112,
    -112,   107,  -112,    80,  -112,    96,  -112,  -111,  -112,  -112,
    -112,  -112,  -112,  -112,   -29,  -112,  -112,  -112,    70,  -112,
     -63,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      27,     8,   132,    12,    83,    84,    51,   -12,   -54,    88,
     -44,    50,    91,   -46,    65,   -54,   -51,    93,    94,    95,
       3,    24,    24,   108,    61,   111,   141,    41,    -4,    55,
      13,   143,   -16,    18,   118,   119,   120,   121,   122,   123,
     124,   125,    19,   127,   135,    72,   130,   131,    23,    21,
      62,    97,    98,    99,   100,   101,   102,   103,   104,    26,
     105,    28,    34,   -21,   106,   136,    31,   107,    35,    36,
     -30,    49,    37,    72,    97,    98,    99,   100,   101,   102,
     103,   104,   110,   105,    77,    78,    79,   106,    77,    78,
      79,    40,    80,    41,    43,    57,    80,    81,   -53,    52,
      82,    81,    56,   -37,    82,   114,    77,    78,    79,    60,
      24,    89,    75,    87,    80,    90,    64,    92,   109,    81,
      86,    96,    82,    97,    98,    99,   100,   101,   102,   103,
     104,   126,   105,   128,   134,   129,   106,    97,    98,    99,
     100,   101,   102,   103,   104,   138,   105,   140,    11,    85,
     106,   133,    97,    98,    99,   100,   101,   102,   103,   104,
     112,   105,    76,    42,    63,   106,    97,    98,    99,   100,
     101,   102,   103,   104,   139,   105,     0,     0,   113,   106,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,   117,   106,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,     0,   137,   106,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
       0,   106
};

static const yytype_int16 yycheck[] =
{
      17,     5,   113,     7,    67,    68,     1,     7,    18,     8,
      23,    40,    75,    26,    27,    25,    29,    80,    81,    82,
       0,    21,    21,    86,    53,    88,   137,    22,     0,    46,
       6,   142,    25,    18,    97,    98,    99,   100,   101,   102,
     103,   104,    25,   106,     1,    62,   109,   110,     6,     5,
      54,     8,     9,    10,    11,    12,    13,    14,    15,     5,
      17,     5,     3,    23,    21,    22,    19,     1,     7,    21,
      20,    20,    23,    90,     8,     9,    10,    11,    12,    13,
      14,    15,     1,    17,     3,     4,     5,    21,     3,     4,
       5,    23,    11,    22,     3,     7,    11,    16,    24,    24,
      19,    16,    20,    24,    19,    20,     3,     4,     5,    22,
      21,     6,    19,    29,    11,     7,    24,    19,    19,    16,
      26,     6,    19,     8,     9,    10,    11,    12,    13,    14,
      15,     5,    17,     6,    20,     6,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    28,    17,    22,     6,    69,
      21,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      90,    17,    66,    35,    57,    21,     8,     9,    10,    11,
      12,    13,    14,    15,   133,    17,    -1,    -1,    20,    21,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    20,    21,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    -1,    -1,    20,    21,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      -1,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,     0,    35,    36,    37,    38,    41,    42,
      43,    35,    41,     6,    39,    47,    48,    49,    18,    25,
      44,     5,    50,     6,    21,    40,     5,    47,     5,    45,
      46,    19,    55,    56,     3,     7,    21,    23,    51,    52,
      23,    22,    39,     3,    66,    67,    41,    53,    54,    20,
      66,     1,    24,    68,    69,    47,    20,     7,    57,    58,
      22,    66,    41,    53,    24,    27,    59,    60,    61,    62,
      63,    65,    47,    70,    71,    19,    57,     3,     4,     5,
      11,    16,    19,    72,    72,    55,    26,    29,     8,     6,
       7,    72,    19,    72,    72,    72,     6,     8,     9,    10,
      11,    12,    13,    14,    15,    17,    21,     1,    72,    19,
       1,    72,    70,    20,    20,    72,    73,    20,    72,    72,
      72,    72,    72,    72,    72,    72,     5,    72,     6,     6,
      72,    72,    59,     7,    20,     1,    22,    20,    28,    73,
      22,    59,    64,    59
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 48 "CMINUS.y"
    { toGramTree(0,"Program");  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 48 "CMINUS.y"
    {(yyvsp[(2) - (2)].node).level=1;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 49 "CMINUS.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 50 "CMINUS.y"
    {toGramTree(1,"ExtDefList"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 52 "CMINUS.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 53 "CMINUS.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 54 "CMINUS.y"
    {toGramTree(2,"ExtDef");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 54 "CMINUS.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 56 "CMINUS.y"
    {toGramTree(0,"ExtDecList");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 57 "CMINUS.y"
    {toGramTree(0,"ExtDecList");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 57 "CMINUS.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 59 "CMINUS.y"
    {toGramTree(3,"Specifier");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 59 "CMINUS.y"
    {toGramTree(0,"TYPE");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 60 "CMINUS.y"
    {toGramTree(3,"Specifier");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 60 "CMINUS.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 62 "CMINUS.y"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 63 "CMINUS.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 65 "CMINUS.y"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 66 "CMINUS.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 68 "CMINUS.y"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 70 "CMINUS.y"
    {toGramTree(0,"VarDec");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 70 "CMINUS.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 71 "CMINUS.y"
    {toGramTree(0,"VarDec");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 72 "CMINUS.y"
    {toGramTree(0,"VarDec");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 72 "CMINUS.y"
    {toGramTree(0,"VarDec"); err = 1;printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 74 "CMINUS.y"
    {toGramTree(0,"FunDec");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 74 "CMINUS.y"
    {;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 75 "CMINUS.y"
    {toGramTree(0,"FunDec");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 75 "CMINUS.y"
    {toGramTree(0,"ID\nLP\nRP");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 77 "CMINUS.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 78 "CMINUS.y"
    {;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 80 "CMINUS.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 82 "CMINUS.y"
    {toGramTree(0,"CompSt");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 82 "CMINUS.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 84 "CMINUS.y"
    {/* \epsilon */;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 85 "CMINUS.y"
    {toGramTree(0,"StmtList");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 85 "CMINUS.y"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 87 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 87 "CMINUS.y"
    {;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 88 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 88 "CMINUS.y"
    {err=1; printf("Error Type B at Line %d: Missing \";\"\n", yylineno);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 89 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 89 "CMINUS.y"
    {;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 90 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 90 "CMINUS.y"
    {;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 91 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 92 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 92 "CMINUS.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 93 "CMINUS.y"
    {toGramTree(0,"Stmt");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 93 "CMINUS.y"
    {;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 95 "CMINUS.y"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 96 "CMINUS.y"
    {toGramTree(0,"DefList");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 96 "CMINUS.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 98 "CMINUS.y"
    {toGramTree(0,"Def");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 98 "CMINUS.y"
    {;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 100 "CMINUS.y"
    {toGramTree(0,"DecList");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 101 "CMINUS.y"
    {toGramTree(0,"DecList");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 103 "CMINUS.y"
    {toGramTree(0,"Dec");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 104 "CMINUS.y"
    {toGramTree(0,"Dec");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 105 "CMINUS.y"
    {toGramTree(0,"Dec"); 	err=1;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 109 "CMINUS.y"
    {toGramTree(0,"Exp"); /*$$.type = $3.type; */;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 110 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 111 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 112 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 113 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 114 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 115 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 116 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 117 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 118 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 119 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 120 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 121 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 122 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 123 "CMINUS.y"
    {toGramTree(0,"Exp"); err=1; printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 124 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 125 "CMINUS.y"
    {toGramTree(0,"Exp");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 126 "CMINUS.y"
    {toGramTree(0,"Exp"); 	(yyval.expval).type = INT; (yyval.expval).value.vali = (yyvsp[(1) - (1)].vali);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 127 "CMINUS.y"
    {toGramTree(0,"Exp");		(yyval.expval).type = FLOAT; (yyval.expval).value.valf = (yyvsp[(1) - (1)].valf);;}
    break;



/* Line 1455 of yacc.c  */
#line 2071 "CMINUS.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 132 "CMINUS.y"



int main(int argc, char** argv){
	FILE*f;
	if(argc > 1){
		if(!(f=fopen(argv[1],"r"))){
			perror(argv[1]);
			return 1;
		}
		yyrestart(f);
	}
	yylineno = 1;
	yyparse();
	if(!err){
		printf("gramTree:\n%s",gramTree);
	}
	
	return 0;
}

void yyerror(char*s){
	char type = 'A';
	printf("Error type %c at Line %d: %s\n",type, yylineno, s);
}

void toGramTree(int level, char *name){
	char tmp[100];
	for(int i=0;i<level;i++){
		strcat(gramTree, " ");
	}
	sprintf(tmp, "%s(%d)\n",name,yylineno);strcat(gramTree, tmp);
}
void tmpcode(){
	/* $$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali + $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)+(($3.type==INT)?$3.value.vali:$3.value.valf);
								*/
}

