/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compil.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
FILE* destination;
int dest = 0;
struct node {
    char data[50];
    struct node* next;
};

struct linked_list {
    struct node* start;
    struct node* end;
};

typedef struct Quad {
		char op[50];
		char src1[50];
		char src2[50];
		char dest[50];
}Quad;


int quadCourant =0, cpt_tmp=1;
char buf[50], buf1[50], buf2[50], buf3[50];
Quad quad[100]; 


int isError = 0; //0: there is no error so print result; 1: there is an error so don't print
int isFile = 0; //0: we read from an stdin; 1: we read from a file specified in argument

void GenererQuadruplet(char CodeOp[50],char source1[50],char source2[50],char destination[50]);
void empilerQuad(Quad tab[] ,Quad val,int* ptr);
Quad depilerQuad (Quad tab[] ,int *ptr);

char* moyenne(struct linked_list* list);
char* somme(struct linked_list* list);
char* produit(struct linked_list* list);
char* variance(struct linked_list* list);
char* racine(char* a);
char* ecartType(struct linked_list* list);
char* max(struct linked_list* list);
int yyerror(char *err);
int yylex();

#line 116 "compil.tab.c" /* yacc.c:339  */

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
   by #include "compil.tab.h".  */
#ifndef YY_YY_COMPIL_TAB_H_INCLUDED
# define YY_YY_COMPIL_TAB_H_INCLUDED
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
    NUMBER = 258,
    PLUS = 259,
    MINUS = 260,
    TIMES = 261,
    DIVIDE = 262,
    POWER = 263,
    LEFT = 264,
    RIGHT = 265,
    EXIT = 266,
    MOYENNE = 267,
    SOMME = 268,
    PRODUCT = 269,
    VARIANCE = 270,
    ECARTTYPE = 271,
    MAX = 272,
    COMMA = 273,
    END = 274,
    MODUL = 275,
    NEG = 276,
    POS = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "compil.y" /* yacc.c:355  */

	char value[20]; //for operands
	char symbol; //for operators
	char* string; //for functions
	int num;
	struct linked_list* list; //for function's arguments

#line 187 "compil.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPIL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "compil.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  54

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    83,    87,    88,   118,   122,   123,   133,
     134,   135,   146,   147,   157,   158,   174,   175,   185,   195,
     196,   197,   198,   202,   232,   233,   237,   238,   239,   240,
     241,   242,   245,   258,   271,   272
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "POWER", "LEFT", "RIGHT", "EXIT", "MOYENNE", "SOMME",
  "PRODUCT", "VARIANCE", "ECARTTYPE", "MAX", "COMMA", "END", "MODUL",
  "NEG", "POS", "$accept", "Input", "Line", "Expression", "Function",
  "Name", "List", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277
};
# endif

#define YYPACT_NINF -23

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-23)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,    27,   -23,   -23,   164,   164,   164,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,     7,   -23,     8,    -6,
      -6,   181,    47,    64,    81,    98,   115,   -23,   132,   132,
     -23,   -23,   -23,   191,   -23,   191,   -23,    -6,   -23,    -6,
     -23,    -6,   -12,   188,    -2,     0,   164,   -23,   149,   -23,
     -23,   188,   -23,   188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,     0,     0,     6,    26,    27,
      28,    29,    30,    31,     4,     3,     0,    22,     0,    10,
      17,     0,     0,     0,     0,     0,     0,     5,     0,     0,
      21,    20,     9,     8,    12,    11,    14,    13,    16,    15,
      19,    18,     0,    33,     0,     0,     0,    24,     0,    25,
      23,    34,    35,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,   -23,    -1,   -23,   -23,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    15,    43,    17,    18,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    49,    26,    19,    20,    21,    46,    45,    47,    28,
      50,    22,    23,    24,    25,    26,    48,    29,    48,     0,
       0,    33,    35,    37,    39,    41,    27,     2,     0,     0,
       3,     4,     5,     0,     0,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    51,    14,    53,    32,     0,
       3,     4,     5,     0,     0,     0,     6,     0,     0,     8,
       9,    10,    11,    12,    13,    34,     0,     3,     4,     5,
       0,     0,     0,     6,     0,     0,     8,     9,    10,    11,
      12,    13,    36,     0,     3,     4,     5,     0,     0,     0,
       6,     0,     0,     8,     9,    10,    11,    12,    13,    38,
       0,     3,     4,     5,     0,     0,     0,     6,     0,     0,
       8,     9,    10,    11,    12,    13,    40,     0,     3,     4,
       5,     0,     0,     0,     6,     0,     0,     8,     9,    10,
      11,    12,    13,    42,     0,     3,     4,     5,     0,     0,
       0,     6,     0,     0,     8,     9,    10,    11,    12,    13,
      52,     0,     3,     4,     5,     0,     0,     0,     6,     0,
       0,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       0,     0,     0,     6,     0,     0,     8,     9,    10,    11,
      12,    13,    30,     0,     0,    22,    23,    24,    25,    26,
       0,    31,    22,    23,    24,    25,    26,    24,    25,    26
};

static const yytype_int8 yycheck[] =
{
       1,     1,     8,     4,     5,     6,    18,    29,    10,     1,
      10,     4,     5,     6,     7,     8,    18,     9,    18,    -1,
      -1,    22,    23,    24,    25,    26,    19,     0,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    46,    19,    48,     1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,     1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,     1,    -1,     3,     4,     5,    -1,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,     1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    17,     1,    -1,     3,     4,
       5,    -1,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,     1,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    17,
       1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    17,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,     1,    -1,    -1,     4,     5,     6,     7,     8,
      -1,    10,     4,     5,     6,     7,     8,     6,     7,     8
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,     0,     3,     4,     5,     9,    11,    12,    13,
      14,    15,    16,    17,    19,    25,    26,    27,    28,    26,
      26,    26,     4,     5,     6,     7,     8,    19,     1,     9,
       1,    10,     1,    26,     1,    26,     1,    26,     1,    26,
       1,    26,     1,    26,    29,    29,    18,    10,    18,     1,
      10,    26,     1,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    24,    24,    25,    25,    25,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    27,    27,    27,    28,    28,    28,    28,
      28,    28,    29,    29,    29,    29
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     1,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3
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
#line 82 "compil.y" /* yacc.c:1646  */
    { if (!isFile) printf("> ");}
#line 1338 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "compil.y" /* yacc.c:1646  */
    { if (!isFile) printf("> ");}
#line 1344 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "compil.y" /* yacc.c:1646  */
    { if (!isError){
     					if(dest ==1) //on ecrit dans un fichier
     					{
     						int i=0;
     						fprintf(destination,"   Op\t|Src1\t|Src2\t|Dest \n");
     						for(i=0;i<quadCourant;i++){
     							fprintf(destination,"%2d: %s\t| %s\t| %s\t| %s\n",i,quad[i].op,quad[i].src1,quad[i].src2, quad[i].dest);
    			
     						}
     						fprintf(destination,"----------------------------------\n");
     						
     					}else{
     						int i=0;
     						printf("   Op\t|Src1\t|Src2\t|Dest \n");
     						for(i=0;i<quadCourant;i++){
     							printf("%2d: %s\t| %s\t| %s\t| %s\n",i,quad[i].op,quad[i].src1,quad[i].src2, quad[i].dest);
    			
     						}
     						//quadCourant = 0;
     						//cpt_tmp = 1;
     						


     					}	
     					quadCourant = 0;
     					cpt_tmp = 1;
     					isError = 0;
     					if (!isFile) printf("> "); 
     					}
     				}
#line 1379 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 118 "compil.y" /* yacc.c:1646  */
    { exit(EXIT_SUCCESS);}
#line 1385 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "compil.y" /* yacc.c:1646  */
    { strcpy((yyval.value),(yyvsp[0].value)); }
#line 1391 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "compil.y" /* yacc.c:1646  */
    { 
			sprintf(buf,"%s",(yyvsp[-2].value));
			sprintf(buf1,"%s",(yyvsp[0].value));
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf((yyval.value),"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			GenererQuadruplet("+",buf,buf1,buf2);
	
	
	 }
#line 1406 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "compil.y" /* yacc.c:1646  */
    { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
#line 1412 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "compil.y" /* yacc.c:1646  */
    { strcpy((yyval.value),(yyvsp[0].value)); }
#line 1418 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 135 "compil.y" /* yacc.c:1646  */
    { 
	
			sprintf(buf,"%s",(yyvsp[-2].value));
			sprintf(buf1,"%s",(yyvsp[0].value));
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf((yyval.value),"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			GenererQuadruplet("-",buf,buf1,buf2);
	
	
	}
#line 1434 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 146 "compil.y" /* yacc.c:1646  */
    { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
#line 1440 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "compil.y" /* yacc.c:1646  */
    { 
			sprintf(buf,"%s",(yyvsp[-2].value));
			sprintf(buf1,"%s",(yyvsp[0].value));
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf((yyval.value),"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			GenererQuadruplet("*",buf,buf1,buf2);
	
	
	 }
#line 1455 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "compil.y" /* yacc.c:1646  */
    { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
#line 1461 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "compil.y" /* yacc.c:1646  */
    { 
				if(strcmp((yyvsp[0].value),"0")==0) 
				{
					yyerror("Erreur! Division par 0\n");
					isError = 1;
				}
				else{
					sprintf(buf,"%s",(yyvsp[-2].value));
					sprintf(buf1,"%s",(yyvsp[0].value));
					sprintf(buf2,"%s%d","tmp",cpt_tmp);
					sprintf((yyval.value),"%s%d","tmp",cpt_tmp);
					cpt_tmp++;
					GenererQuadruplet("/",buf,buf1,buf2);
	
				} 
			}
#line 1482 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 174 "compil.y" /* yacc.c:1646  */
    {  yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
#line 1488 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 175 "compil.y" /* yacc.c:1646  */
    { 
	
					sprintf(buf,"%d",-1);
					sprintf(buf1,"%s",(yyvsp[0].value));
					sprintf(buf2,"%s%d","tmp",cpt_tmp);
					sprintf((yyval.value),"%s%d","tmp",cpt_tmp);
					cpt_tmp++;
					GenererQuadruplet("*",buf,buf1,buf2);
	
	 }
#line 1503 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "compil.y" /* yacc.c:1646  */
    { 
	
					sprintf(buf,"%s",(yyvsp[-2].value));
					sprintf(buf1,"%s",(yyvsp[0].value));
					sprintf(buf2,"%s%d","tmp",cpt_tmp);
					sprintf((yyval.value),"%s%d","tmp",cpt_tmp);
					cpt_tmp++;
					GenererQuadruplet("^",buf,buf1,buf2);
	
	 }
#line 1518 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 195 "compil.y" /* yacc.c:1646  */
    { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
#line 1524 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 196 "compil.y" /* yacc.c:1646  */
    { strcpy((yyval.value),(yyvsp[-1].value)); }
#line 1530 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 197 "compil.y" /* yacc.c:1646  */
    { yyerror("')' attendue\n"); yyerrok; isError = 1;}
#line 1536 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 198 "compil.y" /* yacc.c:1646  */
    { strcpy((yyval.value),(yyvsp[0].value));	}
#line 1542 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 202 "compil.y" /* yacc.c:1646  */
    {
			struct linked_list* list = (yyvsp[-1].list);
			int numFunction = (yyvsp[-3].num);
			if(list)
			{
				switch (numFunction)
				{
					case 1: //si c'est la moyenne
						strcpy((yyval.value),moyenne(list));
						break;
				
					case 2: //si c'est la somme
						strcpy((yyval.value),somme(list));
						break;
					case 3: //si c'est le produit
						strcpy((yyval.value),produit(list));
						break;
					case 4: //si c'est la variance
						strcpy((yyval.value),variance(list));
						break;
					case 5: //si c'est l'ecart type
						strcpy((yyval.value),ecartType(list));
						break;
					case 6:
						strcpy((yyval.value),max(list));
						break;
				}
			} 
			
		}
#line 1577 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 232 "compil.y" /* yacc.c:1646  */
    { yyerror("'(' attendue\n"); yyerrok; isError =1;}
#line 1583 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 233 "compil.y" /* yacc.c:1646  */
    { yyerror("')' attendue\n"); yyerrok; isError =1;}
#line 1589 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 237 "compil.y" /* yacc.c:1646  */
    { (yyval.num) = 1;}
#line 1595 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 238 "compil.y" /* yacc.c:1646  */
    { (yyval.num) = 2;}
#line 1601 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 239 "compil.y" /* yacc.c:1646  */
    { (yyval.num) = 3;}
#line 1607 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 240 "compil.y" /* yacc.c:1646  */
    { (yyval.num) = 4;}
#line 1613 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 241 "compil.y" /* yacc.c:1646  */
    { (yyval.num) = 5;}
#line 1619 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 242 "compil.y" /* yacc.c:1646  */
    {(yyval.num) = 6;}
#line 1625 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 245 "compil.y" /* yacc.c:1646  */
    {
		if(!isError){
			struct node* node = malloc(sizeof(struct node)); 
		    strcpy(node->data,(yyvsp[0].value));
		    node->next = NULL;
		    struct linked_list* list = (yyvsp[-2].list);
		    list->end->next = node;
		    list->end = node;

		    (yyval.list) = list;
		}
        
	}
#line 1643 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 258 "compil.y" /* yacc.c:1646  */
    {
		if(!isError){
			struct linked_list* list = malloc(sizeof(struct linked_list));
		 	struct node* node = malloc(sizeof(struct node));

			strcpy(node->data , (yyvsp[0].value));
			node->next = NULL;
			list->start = node;
			list->end = node;
			(yyval.list) = list;
		}
	    
	}
#line 1661 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 271 "compil.y" /* yacc.c:1646  */
    { yyerror("Argument attendu avant ','\n"); yyerrok; isError = 1;}
#line 1667 "compil.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 272 "compil.y" /* yacc.c:1646  */
    { yyerror("Argument attendu apres ','\n"); yyerrok; isError = 1;}
#line 1673 "compil.tab.c" /* yacc.c:1646  */
    break;


#line 1677 "compil.tab.c" /* yacc.c:1646  */
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
#line 276 "compil.y" /* yacc.c:1906  */


int yyerror(char *err) {
  fprintf(stderr,"%s\n", err);
}


int main(int argc, char* argv[]) {

  if (argc>1){
  	if(strcmp(argv[1],"-f")==0)
  	{
  		if(argv[2])
  		{
  			destination = fopen(argv[2],"w");
  		
  		} else destination = fopen("formeIntermediaire.txt","w");
  		if(destination != NULL)
  		{
  			dest =1;
  			yyparse();
  			fclose(destination);
  		}
  		else
  		{
  		 printf("Impossible d'ouvrir le fichier formeIntermediaire.txt\nPassage en mode console");
  		 dest = 0;
  		 yyparse();
  		}
  	}else
  	{
  		yyin = fopen(argv[1],"r");
  		if (yyin != NULL)
  		{
  			isFile = 1;
  			yyparse();
  			fclose(yyin);
  			return 0;
  		}
  		else printf("Impossible d'ouvrir le fichier %s\n",argv[1]);
	}
  }
  else 
  {
  	return yyparse();
  }
}


char* somme(struct linked_list* list)
{
	struct node* node = list->start;
	if ((node != NULL)&&(node->next !=NULL))
	{
		sprintf(buf,"%s",node->data);
		sprintf(buf1,"%s",node->next->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("+",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		
		node = node->next->next;
		
	}
	while(node != NULL)
	{
		sprintf(buf1,"%s",node->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("+",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		node = node->next;	
	}
	return buf;
}

char* produit(struct linked_list* list)
{
	struct node* node = list->start;
	if ((node != NULL)&&(node->next !=NULL))
	{
		sprintf(buf,"%s",node->data);
		sprintf(buf1,"%s",node->next->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("*",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		
		node = node->next->next;
		
	}
	while(node != NULL)
	{
		sprintf(buf1,"%s",node->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("*",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		node = node->next;	
	}
	return buf;
}

char* moyenne(struct linked_list* list)
{
	struct node* node = list->start;
	int cpt;
	if(node){
		if(node->next == NULL)
		{
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s","");
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("+",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
		}
		else
		{
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->next->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("+",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			node = node->next->next;
			cpt = 2;
			while(node != NULL)
			{
				sprintf(buf1,"%s",node->data);
				sprintf(buf2,"%s%d","tmp",cpt_tmp);
				GenererQuadruplet("+",buf,buf1,buf2);
				sprintf(buf,"%s%d","tmp",cpt_tmp);
				cpt_tmp++;
				cpt++;
				node = node->next;	
				
			}
			sprintf(buf1,"%d",cpt);	
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("/",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
				
		}
		
	
	}
	return buf;
}

char* variance(struct linked_list* list)
{
	struct node* node = list->start;
	int cpt;
	if(node){
		if(node->next == NULL)
		{
			//X2
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			//X
			sprintf(buf1,"%s",node->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("-",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
		}
		else
		{
			//Moment d'ordre 2
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			sprintf(buf1,"%s",node->next->data);
			sprintf(buf2,"%s",node->next->data);
			sprintf(buf3,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf1,buf2,buf3);
			sprintf(buf3,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("+",buf,buf3,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
				
			
			node = node->next->next;
			cpt = 2;
			
			while(node != NULL)
			{
				sprintf(buf1,"%s",node->data);
				sprintf(buf3,"%s",node->data);
				sprintf(buf2,"%s%d","tmp",cpt_tmp);
				cpt_tmp++;
				GenererQuadruplet("*",buf1,buf3,buf2);
				sprintf(buf3,"%s%d","tmp",cpt_tmp);
				GenererQuadruplet("+",buf,buf2,buf3);
				sprintf(buf,"%s%d","tmp",cpt_tmp);
				cpt_tmp++;
				cpt++;
				node = node->next;	
				
			}
			
			//La somme / N
			sprintf(buf1,"%d",cpt);	
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("/",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			//Moyenne
			sprintf(buf3,"%s",buf);
			sprintf(buf1,"%s",moyenne(list));	
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf1,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			//E(x2)-E(x)2
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("-",buf3,buf,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
				
		}
		
	
	}
	return buf;

}

char* racine(char* a)
{
	char val[50];
	char quadRetour[50];
	
	sprintf(val,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	
	sprintf(buf1,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	
	
	GenererQuadruplet("MOV","1","",val);	
	sprintf(quadRetour,"%d",quadCourant+1);
	GenererQuadruplet("MOV",val,"",buf1);
	sprintf(buf2,"%s%d","tmp",cpt_tmp);
	GenererQuadruplet("/",a,buf1,buf2);
	cpt_tmp++;
	sprintf(buf3,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	GenererQuadruplet("+",buf1,buf2,buf3);
	sprintf(buf2,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	GenererQuadruplet("/",buf3,"2",buf2);
	sprintf(buf3,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	GenererQuadruplet("MOV",buf1,"",buf3);
	GenererQuadruplet("MOV",buf2,"",buf1);
	GenererQuadruplet("SUB",buf3,buf1,"");
	GenererQuadruplet("JNZ","","",quadRetour);
	return buf1;		
}

char* ecartType(struct linked_list* list)
{
	char a[50];
	
	sprintf(a,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	strcpy(a,variance(list));
	return racine(a);
	
}

char* max(struct linked_list* list)
{
	struct node* node = list->start;
	
	if(node){
		if(node->next)
		{
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->next->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("CMP",buf,buf1,"");
			sprintf(buf3,"%d",quadCourant+3);
			GenererQuadruplet("JL","","",buf3);
			GenererQuadruplet("MOV",buf,"",buf2);
			sprintf(buf3,"%d",quadCourant+2);
			GenererQuadruplet("JMP","","",buf3);
			GenererQuadruplet("MOV",buf1,"",buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			node = node->next->next;

			while(node != NULL)
			{
				sprintf(buf1,"%s",node->data);
				GenererQuadruplet("CMP",buf,buf1,"");
				sprintf(buf3,"%d",quadCourant+2);
				GenererQuadruplet("JL","","",buf3);
				sprintf(buf3,"%d",quadCourant+2);
				GenererQuadruplet("JMP","","",buf3);
				GenererQuadruplet("MOV",buf1,"",buf);
				
				node = node->next;	
				
			}
				
		}
		
	
	}
	return buf;
}

void GenererQuadruplet(char CodeOp[50],char source1[50],char source2[50],char destination[50]){
	strcpy(quad[quadCourant].op,CodeOp);
	strcpy(quad[quadCourant].src1,source1);
	strcpy(quad[quadCourant].src2,source2);
	strcpy(quad[quadCourant].dest,destination);
	quadCourant++;
}

void empilerQuad(Quad tab[] ,Quad val,int* ptr){
	*ptr = *ptr + 1;
	strcpy(tab[*ptr].op , val.op );
	strcpy(tab[*ptr].src1 ,val.src1) ;
	strcpy(tab[*ptr].src2 , val.src2); 
	strcpy(tab[*ptr].dest , val.dest) ;
}
	
Quad depilerQuad (Quad tab[] ,int *ptr){
	Quad quad = tab[*ptr];
	*ptr = *ptr - 1;
	return quad;
}	

