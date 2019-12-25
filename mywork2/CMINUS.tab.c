
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
void toGramTree(char *name);

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



/* Line 214 of yacc.c  */
#line 163 "CMINUS.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 175 "CMINUS.tab.c"

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
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

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
       0,     0,     3,     4,     7,     8,     9,    13,    14,    19,
      20,    24,    25,    30,    32,    33,    38,    39,    42,    43,
      46,    52,    55,    56,    58,    60,    61,    64,    65,    71,
      72,    79,    80,    86,    87,    92,    96,    98,   101,   102,
     108,   109,   110,   114,   115,   119,   120,   125,   126,   129,
     130,   135,   141,   142,   151,   152,   159,   160,   161,   165,
     166,   171,   173,   177,   179,   183,   188,   192,   196,   200,
     204,   208,   212,   216,   220,   224,   227,   230,   235,   239,
     244,   250,   254,   256,   258,   260,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    -1,    34,    35,    -1,    -1,    -1,    36,
      37,    35,    -1,    -1,    38,    43,    41,     6,    -1,    -1,
      39,    43,     6,    -1,    -1,    40,    43,    53,    58,    -1,
      49,    -1,    -1,    49,    42,     7,    41,    -1,    -1,    44,
      18,    -1,    -1,    45,    46,    -1,    25,    47,    23,    69,
      24,    -1,    25,    48,    -1,    -1,     5,    -1,     5,    -1,
      -1,    50,     5,    -1,    -1,    51,    49,    21,     3,    22,
      -1,    -1,    52,    49,    21,     3,     1,    22,    -1,    -1,
       5,    19,    54,    56,    20,    -1,    -1,     5,    19,    55,
      20,    -1,    57,     7,    56,    -1,    57,    -1,    43,    49,
      -1,    -1,    59,    23,    69,    60,    24,    -1,    -1,    -1,
      61,    62,    60,    -1,    -1,    75,    63,     6,    -1,    -1,
      75,    64,     1,     6,    -1,    -1,    65,    58,    -1,    -1,
      66,    26,    75,     6,    -1,    27,    19,    75,    20,    62,
      -1,    -1,    27,    19,    75,    20,    62,    28,    67,    62,
      -1,    -1,    68,    29,    19,    75,    20,    62,    -1,    -1,
      -1,    70,    71,    69,    -1,    -1,    72,    43,    73,     6,
      -1,    74,    -1,    74,     7,    73,    -1,    49,    -1,    49,
       8,    75,    -1,    49,     8,     1,    75,    -1,    75,     8,
      75,    -1,    75,    14,    75,    -1,    75,    15,    75,    -1,
      75,     9,    75,    -1,    75,    10,    75,    -1,    75,    11,
      75,    -1,    75,    12,    75,    -1,    75,    13,    75,    -1,
      19,    75,    20,    -1,    11,    75,    -1,    16,    75,    -1,
       5,    19,    76,    20,    -1,     5,    19,    20,    -1,    75,
      21,    75,    22,    -1,    75,    21,    75,     1,    22,    -1,
      75,    17,     5,    -1,     5,    -1,     3,    -1,     4,    -1,
      75,     7,    76,    -1,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    47,    48,    49,    49,    51,    51,    52,
      52,    53,    53,    55,    56,    56,    58,    58,    59,    59,
      61,    62,    64,    65,    67,    69,    69,    70,    70,    71,
      71,    73,    73,    74,    74,    76,    77,    79,    81,    81,
      83,    84,    84,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    92,    94,    95,    95,    97,
      97,    99,   100,   102,   103,   104,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   128,   129
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
  "ExtDefList", "$@2", "ExtDef", "$@3", "$@4", "$@5", "ExtDecList", "$@6",
  "Specifier", "$@7", "$@8", "StructSpecifier", "OptTag", "Tag", "VarDec",
  "$@9", "$@10", "$@11", "FunDec", "$@12", "$@13", "VarList", "ParamDec",
  "CompSt", "$@14", "StmtList", "$@15", "Stmt", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "DefList", "$@22", "Def", "$@23", "DecList",
  "Dec", "Exp", "Args", 0
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
       0,    32,    34,    33,    35,    36,    35,    38,    37,    39,
      37,    40,    37,    41,    42,    41,    44,    43,    45,    43,
      46,    46,    47,    47,    48,    50,    49,    51,    49,    52,
      49,    54,    53,    55,    53,    56,    56,    57,    59,    58,
      60,    61,    60,    63,    62,    64,    62,    65,    62,    66,
      62,    62,    67,    62,    68,    62,    69,    70,    69,    72,
      71,    73,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     0,     3,     0,     4,     0,
       3,     0,     4,     1,     0,     4,     0,     2,     0,     2,
       5,     2,     0,     1,     1,     0,     2,     0,     5,     0,
       6,     0,     5,     0,     4,     3,     1,     2,     0,     5,
       0,     0,     3,     0,     3,     0,     4,     0,     2,     0,
       4,     5,     0,     8,     0,     6,     0,     0,     3,     0,
       4,     1,     3,     1,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     3,     4,
       5,     3,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     3,     7,     5,    16,    16,    16,
       6,    25,     0,     0,     0,     0,     0,    13,     0,    25,
      25,    17,    22,    19,    10,     0,    38,     8,     0,    26,
       0,     0,    24,     0,    21,    31,    12,     0,    25,     0,
       0,    57,    16,     0,    56,    15,     0,     0,     0,    59,
      25,     0,    36,    34,    41,    28,     0,    20,    56,    16,
      37,    32,    16,     0,    47,    30,    58,    25,    35,    39,
      83,    84,    82,     0,     0,     0,     0,    41,    38,     0,
       0,    43,    63,     0,    61,     0,    75,    76,     0,     0,
      42,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    25,    78,
      86,     0,    74,     0,     0,     0,    66,    69,    70,    71,
      72,    73,    67,    68,    81,     0,    44,     0,     0,    64,
      62,     0,    77,    47,    50,     0,     0,    79,    46,    65,
      85,    51,    47,    80,    52,    55,    47,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     5,     6,     7,     8,     9,    16,
      28,    50,    12,    13,    23,    33,    34,    17,    18,    19,
      20,    26,    42,    43,    51,    52,    36,    37,    63,    64,
      77,   104,   105,    78,    79,   146,    80,    48,    49,    58,
      59,    83,    84,    81,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
    -100,    10,    11,  -100,  -100,  -100,    11,   -13,   -13,   -13,
    -100,  -100,    -5,   -10,    14,    12,    16,    26,    31,  -100,
    -100,  -100,    32,  -100,  -100,    22,  -100,  -100,    38,  -100,
      21,    28,    27,    29,  -100,    33,  -100,    40,  -100,    52,
      53,    41,   -13,    56,    -9,  -100,    55,    77,    67,  -100,
    -100,    72,    91,  -100,    78,  -100,    82,  -100,    -9,   -13,
    -100,  -100,   -13,    81,    35,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,    87,   114,   114,   114,    90,    78,  -100,    84,
      85,    73,   105,   115,   113,    96,   197,   197,   155,   114,
    -100,  -100,   114,   103,   114,   114,   114,   114,   114,   114,
     114,   114,   118,   114,   120,   123,    92,  -100,  -100,  -100,
     141,   107,  -100,   169,   126,   114,   197,   197,   197,   197,
     197,   197,   197,   197,  -100,    58,  -100,   122,   114,   197,
    -100,   114,  -100,    35,  -100,   183,   109,  -100,  -100,   197,
    -100,   101,    35,  -100,  -100,  -100,    35,  -100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,   136,  -100,  -100,  -100,  -100,  -100,   106,
    -100,    -1,  -100,  -100,  -100,  -100,  -100,   -19,  -100,  -100,
    -100,  -100,  -100,  -100,    83,  -100,    68,  -100,    80,  -100,
     -99,  -100,  -100,  -100,  -100,  -100,  -100,   -39,  -100,  -100,
    -100,    51,  -100,   -71,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      30,    31,    86,    87,    88,    54,    11,    14,    15,   -57,
       3,    -4,   -18,    21,   110,    22,   -57,    25,   113,    66,
      24,   114,    27,   116,   117,   118,   119,   120,   121,   122,
     123,    60,   125,   -14,   141,   129,    29,    32,    70,    71,
      72,    35,    39,   145,   135,    38,    73,   147,    82,    40,
     -23,    74,    41,   -33,    75,    46,    47,   139,    67,   136,
     110,   -49,    76,    44,   -54,   -56,    94,    95,    96,    97,
      98,    99,   100,   101,   -45,   102,    53,    55,    56,   103,
     137,    94,    95,    96,    97,    98,    99,   100,   101,    82,
     102,    57,    61,   128,   103,    70,    71,    72,    62,    70,
      71,    72,   -40,    73,    65,    69,    85,    73,    74,    89,
      92,    75,    74,   106,    93,    75,   109,    70,    71,    72,
     108,   107,   115,   124,   127,    73,   126,   132,   138,   144,
      74,   143,   134,    75,    94,    95,    96,    97,    98,    99,
     100,   101,    10,   102,    45,    68,    91,   103,   131,    94,
      95,    96,    97,    98,    99,   100,   101,    90,   102,   130,
       0,   140,   103,    94,    95,    96,    97,    98,    99,   100,
     101,     0,   102,     0,     0,   112,   103,    94,    95,    96,
      97,    98,    99,   100,   101,     0,   102,     0,     0,   133,
     103,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     102,     0,     0,   142,   103,    94,    95,    96,    97,    98,
      99,   100,   101,     0,   102,     0,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
      19,    20,    73,    74,    75,    44,     7,     8,     9,    18,
       0,     0,    25,    18,    85,    25,    25,     5,    89,    58,
       6,    92,     6,    94,    95,    96,    97,    98,    99,   100,
     101,    50,   103,     7,   133,   106,     5,     5,     3,     4,
       5,    19,    21,   142,   115,     7,    11,   146,    67,    21,
      23,    16,    23,    20,    19,     3,     3,   128,    59,     1,
     131,    26,    27,    23,    29,    24,     8,     9,    10,    11,
      12,    13,    14,    15,     1,    17,    20,    22,     1,    21,
      22,     8,     9,    10,    11,    12,    13,    14,    15,   108,
      17,    24,    20,     1,    21,     3,     4,     5,     7,     3,
       4,     5,    24,    11,    22,    24,    19,    11,    16,    19,
      26,    19,    16,     8,    29,    19,    20,     3,     4,     5,
       7,     6,    19,     5,     1,    11,     6,    20,     6,    28,
      16,    22,     6,    19,     8,     9,    10,    11,    12,    13,
      14,    15,     6,    17,    38,    62,    78,    21,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    77,    17,   108,
      -1,   131,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    20,
      21,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    21,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      35,    43,    44,    45,    43,    43,    41,    49,    50,    51,
      52,    18,    25,    46,     6,     5,    53,     6,    42,     5,
      49,    49,     5,    47,    48,    19,    58,    59,     7,    21,
      21,    23,    54,    55,    23,    41,     3,     3,    69,    70,
      43,    56,    57,    20,    69,    22,     1,    24,    71,    72,
      49,    20,     7,    60,    61,    22,    69,    43,    56,    24,
       3,     4,     5,    11,    16,    19,    27,    62,    65,    66,
      68,    75,    49,    73,    74,    19,    75,    75,    75,    19,
      60,    58,    26,    29,     8,     9,    10,    11,    12,    13,
      14,    15,    17,    21,    63,    64,     8,     6,     7,    20,
      75,    76,    20,    75,    75,    19,    75,    75,    75,    75,
      75,    75,    75,    75,     5,    75,     6,     1,     1,    75,
      73,     7,    20,    20,     6,    75,     1,    22,     6,    75,
      76,    62,    20,    22,    28,    62,    67,    62
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
#line 47 "CMINUS.y"
    {toGramTree("Program");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 48 "CMINUS.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 49 "CMINUS.y"
    {toGramTree("ExtDefList");  toGramTree("ExtDef";;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 51 "CMINUS.y"
    {toGramTree("ExtDef");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 51 "CMINUS.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 52 "CMINUS.y"
    {toGramTree("ExtDef");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 52 "CMINUS.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 53 "CMINUS.y"
    {toGramTree("ExtDef");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 53 "CMINUS.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 55 "CMINUS.y"
    {toGramTree("ExtDecList");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 56 "CMINUS.y"
    {toGramTree("ExtDecList");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 56 "CMINUS.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 58 "CMINUS.y"
    {toGramTree("Specifier");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 58 "CMINUS.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 59 "CMINUS.y"
    {toGramTree("Specifier");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 59 "CMINUS.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 61 "CMINUS.y"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 62 "CMINUS.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 64 "CMINUS.y"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 65 "CMINUS.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 67 "CMINUS.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 69 "CMINUS.y"
    {toGramTree("VarDec");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 69 "CMINUS.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 70 "CMINUS.y"
    {toGramTree("VarDec");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 70 "CMINUS.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 71 "CMINUS.y"
    {toGramTree("VarDec");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 71 "CMINUS.y"
    {err = 1;printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 73 "CMINUS.y"
    {toGramTree("FunDec");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 73 "CMINUS.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 74 "CMINUS.y"
    {toGramTree("FunDec");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 74 "CMINUS.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 76 "CMINUS.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 77 "CMINUS.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 79 "CMINUS.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 81 "CMINUS.y"
    {toGramTree("CompSt");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 81 "CMINUS.y"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 83 "CMINUS.y"
    {/* \epsilon */;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 84 "CMINUS.y"
    {toGramTree("StmtList");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 84 "CMINUS.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 86 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 86 "CMINUS.y"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 87 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 87 "CMINUS.y"
    {err=1; printf("Error Type B at Line %d: Missing \";\"\n", yylineno);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 88 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 88 "CMINUS.y"
    {;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 89 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 89 "CMINUS.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 90 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 91 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 91 "CMINUS.y"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 92 "CMINUS.y"
    {toGramTree("Stmt");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 92 "CMINUS.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 94 "CMINUS.y"
    {;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 95 "CMINUS.y"
    {toGramTree("DefList");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 95 "CMINUS.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 97 "CMINUS.y"
    {toGramTree("Def");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 97 "CMINUS.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 99 "CMINUS.y"
    {toGramTree("DecList");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 100 "CMINUS.y"
    {toGramTree("DecList");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 102 "CMINUS.y"
    {toGramTree("Dec");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 103 "CMINUS.y"
    {toGramTree("Dec");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 104 "CMINUS.y"
    {toGramTree("Dec"); 	err=1;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 108 "CMINUS.y"
    {toGramTree("Exp"); /*$$.type = $3.type; */;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 109 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 110 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 111 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 112 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 113 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 114 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 115 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 116 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 117 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 118 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 119 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 120 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 121 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 122 "CMINUS.y"
    {toGramTree("Exp"); err=1; printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 123 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 124 "CMINUS.y"
    {toGramTree("Exp");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 125 "CMINUS.y"
    {toGramTree("Exp"); 	(yyval.expval).type = INT; (yyval.expval).value.vali = (yyvsp[(1) - (1)].vali);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 126 "CMINUS.y"
    {toGramTree("Exp");		(yyval.expval).type = FLOAT; (yyval.expval).value.valf = (yyvsp[(1) - (1)].valf);;}
    break;



/* Line 1455 of yacc.c  */
#line 2083 "CMINUS.tab.c"
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
#line 131 "CMINUS.y"



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
void toGramTree(char *name){
	char tmp[100];
	sprintf(tmp, "%s(%d)\n",name,yylineno);strcat(gramTree, tmp);
}
void tmpcode(){
	/* $$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali + $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)+(($3.type==INT)?$3.value.vali:$3.value.valf);
								*/
}

