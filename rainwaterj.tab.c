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
#line 1 "rainwaterj.y" /* yacc.c:339  */

#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>

int numLines = 1;
void printToken(const char* tokenType, const char* lexeme);
void printError(const char* error, const char* lexeme);
void printRule(const char*, const char*);
bool validateIntConst(const char* intconst);
int yyerror(const char *s);
const char* maxint = "2147483647";

enum TOKEN_TYPE { ARRAY, INTEGER, CHAR, BOOLEAN };

struct TYPE_INFO {
    TOKEN_TYPE type;
};

typedef std::map<const char*, TYPE_INFO> SymbolTable;

class ProgramScope {
private:
    std::vector<SymbolTable> table;

public:
    ProgramScope(): table(0) {}

    void pushScope() { table.push_back(SymbolTable()); }

    //return success/failure of insertion
    bool insertSymbol(const char* ident, TYPE_INFO info) {
        SymbolTable& current = table.back();
        return current.insert(std::pair<const char*, TYPE_INFO>(ident, info)).second;
    }
};

ProgramScope programScope;

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}


#line 114 "rainwaterj.tab.c" /* yacc.c:339  */

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
    T_WSPACE = 258,
    T_ASSIGN = 259,
    T_MULT = 260,
    T_PLUS = 261,
    T_MINUS = 262,
    T_DIV = 263,
    T_AND = 264,
    T_OR = 265,
    T_NOT = 266,
    T_LT = 267,
    T_GT = 268,
    T_LE = 269,
    T_GE = 270,
    T_EQ = 271,
    T_NE = 272,
    T_VAR = 273,
    T_OF = 274,
    T_BOOL = 275,
    T_CHAR = 276,
    T_INT = 277,
    T_PROG = 278,
    T_PROC = 279,
    T_BEGIN = 280,
    T_END = 281,
    T_WHILE = 282,
    T_DO = 283,
    T_IF = 284,
    T_READ = 285,
    T_WRITE = 286,
    T_TRUE = 287,
    T_FALSE = 288,
    T_LBRACK = 289,
    T_RBRACK = 290,
    T_NEWLINE = 291,
    T_SCOLON = 292,
    T_COLON = 293,
    T_LPAREN = 294,
    T_RPAREN = 295,
    T_COMMA = 296,
    T_DOT = 297,
    T_DOTDOT = 298,
    T_ARRAY = 299,
    T_CHARCONST = 300,
    T_IDENT = 301,
    T_INTCONST = 302,
    T_UNKNOWN = 303,
    T_THEN = 304,
    T_ELSE = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 213 "rainwaterj.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    75,    80,    85,    90,    95,    99,   104,
     108,   113,   118,   123,   127,   131,   136,   141,   146,   151,
     155,   159,   164,   169,   173,   178,   183,   188,   193,   198,
     202,   206,   210,   214,   218,   222,   226,   231,   236,   241,
     246,   251,   256,   260,   265,   270,   275,   279,   284,   288,
     293,   298,   302,   307,   312,   317,   321,   326,   331,   335,
     339,   343,   347,   352,   356,   361,   365,   369,   373,   378,
     382,   386,   391,   395,   399,   403,   407,   411,   416,   420,
     425,   430,   435,   440,   445,   449,   453,   458,   463,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_WSPACE", "T_ASSIGN", "T_MULT",
  "T_PLUS", "T_MINUS", "T_DIV", "T_AND", "T_OR", "T_NOT", "T_LT", "T_GT",
  "T_LE", "T_GE", "T_EQ", "T_NE", "T_VAR", "T_OF", "T_BOOL", "T_CHAR",
  "T_INT", "T_PROG", "T_PROC", "T_BEGIN", "T_END", "T_WHILE", "T_DO",
  "T_IF", "T_READ", "T_WRITE", "T_TRUE", "T_FALSE", "T_LBRACK", "T_RBRACK",
  "T_NEWLINE", "T_SCOLON", "T_COLON", "T_LPAREN", "T_RPAREN", "T_COMMA",
  "T_DOT", "T_DOTDOT", "T_ARRAY", "T_CHARCONST", "T_IDENT", "T_INTCONST",
  "T_UNKNOWN", "T_THEN", "T_ELSE", "$accept", "N_START", "N_PROGLBL",
  "N_PROG", "N_BLOCK", "N_VARDECPART", "N_VARDECLST", "N_VARDEC",
  "N_IDENT", "N_IDENTLST", "N_TYPE", "N_ARRAY", "N_IDX", "N_IDXRANGE",
  "N_SIMPLE", "N_PROCDECPART", "N_PROCDEC", "N_PROCHDR", "N_STMTPART",
  "N_COMPOUND", "N_STMTLST", "N_STMT", "N_ASSIGN", "N_PROCSTMT",
  "N_PROCIDENT", "N_READ", "N_INPUTLST", "N_INPUTVAR", "N_WRITE",
  "N_OUTPUTLST", "N_OUTPUT", "N_CONDITION", "N_WHILE", "N_EXPR",
  "N_SIMPLEEXPR", "N_ADDOPLST", "N_TERM", "N_MULTOPLST", "N_FACTOR",
  "N_SIGN", "N_ADDOP", "N_MULTOP", "N_RELOP", "N_VARIABLE", "N_IDXVAR",
  "N_ARRAYVAR", "N_ENTIREVAR", "N_VARIDENT", "N_CONST", "N_INTCONST",
  "N_BOOLCONST", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -84

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -16,   -82,    20,   -37,   -82,   -82,   -15,     6,   -18,    12,
      23,   -82,    25,    14,   -82,    11,    38,    31,     6,   -18,
     -18,    32,    34,    -4,   -82,   -82,    23,   -82,   -82,    35,
      14,    -3,   -82,     5,     5,    30,    36,     9,   -82,    37,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,    69,   -82,    42,
      43,   -82,   -82,   -18,   -82,   -82,   -82,   -82,    44,   -82,
     -82,   -82,   -82,   -82,     5,   -82,   -82,     5,   -82,    51,
      18,    54,    40,   -32,   -82,   -82,   -82,    39,    41,     5,
      -4,    55,     5,     5,   -82,    33,   -82,    46,    -4,   -82,
     -82,   -82,   -82,   -82,   -82,     5,   -82,   -82,   -82,   -82,
       5,   -82,   -82,   -82,   -82,     5,   -82,   -82,   -82,    -4,
      48,   -82,    49,   -82,    37,   -82,   -82,    47,    50,    56,
      52,   -82,   -82,   -82,   -82,    54,    40,    53,    41,    57,
       5,    58,   -82,   -82,    33,    61,   -82,   -82,    -4,    48,
     -82,    49,   -82,   -82,    45,   -82,   -82,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     2,     1,     0,     7,     0,     0,
      23,    11,     0,    13,     4,     0,     0,     0,     7,     9,
       0,     0,     0,     0,     5,    26,    23,    24,     6,     0,
      13,     0,    25,    65,    65,     0,     0,    39,    35,    29,
      30,    31,    38,    33,    32,    36,    34,     0,    79,     0,
      78,    82,    22,     9,    12,    21,    20,    19,     0,    10,
      15,    14,    63,    64,    65,    88,    89,    65,    85,     0,
      51,    55,    58,     0,    60,    84,    86,     0,     0,    65,
       0,     0,    65,    65,     8,    65,    62,     0,     0,    72,
      76,    73,    77,    75,    74,    65,    66,    67,    68,    53,
      65,    69,    70,    71,    56,    65,    83,    87,    59,     0,
      42,    43,    46,    47,    29,    27,    37,     0,     0,     0,
       0,    17,    61,    50,    52,    55,    58,    48,     0,     0,
      65,     0,    28,    80,    65,     0,    54,    57,     0,    42,
      40,    46,    44,    18,     0,    49,    41,    45,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -82,   -82,    65,   -82,    59,    76,    72,    64,
     -82,   -82,   -49,   -82,   -48,    74,   -82,   -82,   -82,    79,
     -13,   -80,   -82,   -82,   -82,   -82,   -35,   -26,   -82,   -36,
     -24,   -82,   -82,   -31,    13,   -14,     7,   -17,   -59,   -81,
     -82,   -82,   -82,   -72,   -82,   -82,   -82,   -82,   -82,   -75,
     -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    10,    28,    29,    13,    21,
      59,    60,   118,   119,    61,    16,    17,    18,    24,    38,
      81,    39,    40,    41,    42,    43,   129,   110,    44,   131,
     112,    45,    46,   113,    70,    99,    71,   104,    72,    73,
     100,   105,    95,    47,    48,    49,    50,    51,    74,    75,
      76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   108,    69,    77,   120,    86,   111,     1,   123,     6,
     121,    62,    63,   -83,   106,   107,    64,    55,    56,    57,
       5,    23,     7,    33,     8,    34,    35,    36,    11,   127,
      89,    90,    91,    92,    93,    94,    87,    65,    66,    62,
      63,    58,    37,   -83,    67,   101,   126,    15,   102,   103,
      68,   116,   117,   120,    14,    20,   111,    22,   145,   121,
      96,    97,    19,    23,    98,    55,    56,    57,    26,    78,
      31,    32,    53,    82,    80,    79,    83,   -81,    85,    88,
     144,   115,   133,    27,    12,   143,   122,   106,   109,   128,
     130,   135,    30,   134,    54,    25,   148,   140,   142,   107,
      52,   132,   139,   138,   146,   147,   141,   125,   124,   137,
       0,   136,    84
};

static const yytype_int16 yycheck[] =
{
      80,    73,    33,    34,    85,    64,    78,    23,    88,    46,
      85,     6,     7,     4,    46,    47,    11,    20,    21,    22,
       0,    25,    37,    27,    18,    29,    30,    31,    46,   109,
      12,    13,    14,    15,    16,    17,    67,    32,    33,     6,
       7,    44,    46,    34,    39,     5,   105,    24,     8,     9,
      45,    82,    83,   134,    42,    41,   128,    46,   138,   134,
       6,     7,    37,    25,    10,    20,    21,    22,    37,    39,
      38,    37,    37,     4,    37,    39,    34,    34,    34,    28,
      19,    26,    35,    18,     8,   134,    40,    46,    49,    41,
      41,    35,    20,    43,    30,    16,   144,    40,    40,    47,
      26,   114,   128,    50,   139,   141,   130,   100,    95,   126,
      -1,   125,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    52,    53,    54,     0,    46,    37,    18,    55,
      56,    46,    58,    59,    42,    24,    66,    67,    68,    37,
      41,    60,    46,    25,    69,    70,    37,    55,    57,    58,
      59,    38,    37,    27,    29,    30,    31,    46,    70,    72,
      73,    74,    75,    76,    79,    82,    83,    94,    95,    96,
      97,    98,    66,    37,    60,    20,    21,    22,    44,    61,
      62,    65,     6,     7,    11,    32,    33,    39,    45,    84,
      85,    87,    89,    90,    99,   100,   101,    84,    39,    39,
      37,    71,     4,    34,    57,    34,    89,    84,    28,    12,
      13,    14,    15,    16,    17,    93,     6,     7,    10,    86,
      91,     5,     8,     9,    88,    92,    46,    47,    94,    49,
      78,    94,    81,    84,    72,    26,    84,    84,    63,    64,
      90,   100,    40,    72,    85,    87,    89,    72,    41,    77,
      41,    80,    71,    35,    43,    35,    86,    88,    50,    78,
      40,    81,    40,    63,    19,    72,    77,    80,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    61,    62,    63,    64,    65,
      65,    65,    66,    66,    67,    68,    69,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    73,    74,    75,
      76,    77,    77,    78,    79,    80,    80,    81,    82,    82,
      83,    84,    84,    85,    86,    86,    87,    88,    88,    89,
      89,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    96,    97,    98,    99,    99,    99,   100,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     5,     3,     4,     0,     3,     0,
       4,     1,     3,     0,     1,     1,     6,     1,     3,     1,
       1,     1,     3,     0,     2,     3,     1,     4,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       5,     3,     0,     1,     5,     3,     0,     1,     4,     6,
       4,     1,     3,     2,     3,     0,     2,     3,     0,     2,
       1,     3,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     2,     1,     1
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
#line 61 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_START", "N_PROG");
    printf("\n---- Completed parsing ----\n\n\n");
    programScope.pushScope();
    TYPE_INFO t;
    t.type = ARRAY;
    bool result;
    result = programScope.insertSymbol("Hi", t);
    printf("%d\n", result);
    result = programScope.insertSymbol("Hi", t);
    printf("%d\n", result);
    return 0;
}
#line 1414 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROGLBL", "T_PROG");
}
#line 1422 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROG", "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
}
#line 1430 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_BLOCK", " N_VARDECPART N_PROCDECPART N_STMTPART");
}
#line 1438 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
}
#line 1446 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARDECPART", "epsilon");
}
#line 1454 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 100 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
}
#line 1462 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARDECLST", "epsilon");
}
#line 1470 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
}
#line 1478 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_IDENT", "T_IDENT");
}
#line 1486 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
}
#line 1494 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_IDENTLST", "epsilon");
}
#line 1502 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_TYPE", "N_SIMPLE");
}
#line 1510 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_TYPE", "N_ARRAY");
}
#line 1518 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 137 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ARRAY", "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
}
#line 1526 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_IDX", "N_INTCONST");
}
#line 1534 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 147 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
}
#line 1542 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIMPLE", "T_INT");
}
#line 1550 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIMPLE", "T_CHAR");
}
#line 1558 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIMPLE", "T_BOOL");
}
#line 1566 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
}
#line 1574 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 169 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROCDECPART", "epsilon");
}
#line 1582 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 174 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
}
#line 1590 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 179 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
}
#line 1598 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMTPART", "N_COMPOUND");
}
#line 1606 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 189 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
}
#line 1614 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 194 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
}
#line 1622 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 198 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMTLST", "epsilon");
}
#line 1630 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 203 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_ASSIGN");
}
#line 1638 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 207 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_PROCSTMT");
}
#line 1646 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_WRITE");
}
#line 1654 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 215 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_READ");
}
#line 1662 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 219 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_WHILE");
}
#line 1670 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 223 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_COMPOUND");
}
#line 1678 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 227 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_STMT", "N_CONDITION");
}
#line 1686 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 232 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
}
#line 1694 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 237 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROCSTMT", "N_PROCIDENT");
}
#line 1702 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 242 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_PROCIDENT", "T_IDENT");
}
#line 1710 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
}
#line 1718 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
}
#line 1726 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 256 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_INPUTLST", "epsilon");
}
#line 1734 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 261 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_INPUTVAR", "N_VARIABLE");
}
#line 1742 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 266 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
}
#line 1750 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 271 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
}
#line 1758 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 275 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_OUTPUTLST", "epsilon");
}
#line 1766 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 280 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_OUTPUT", "N_EXPR");
}
#line 1774 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 285 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
}
#line 1782 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 289 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
}
#line 1790 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 294 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
}
#line 1798 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 299 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_EXPR", "N_SIMPLEEXPR");
}
#line 1806 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 303 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
}
#line 1814 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 308 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
}
#line 1822 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 313 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
}
#line 1830 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 317 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ADDOPLST", "epsilon");
}
#line 1838 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 322 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_TERM", "N_FACTOR N_MULTOPLST");
}
#line 1846 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 327 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
}
#line 1854 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 331 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_MULTOPLST", "epsilon");
}
#line 1862 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 336 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_FACTOR", "N_SIGN N_VARIABLE");
}
#line 1870 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 340 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_FACTOR", "N_CONST");
}
#line 1878 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 344 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
}
#line 1886 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 348 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_FACTOR", "T_NOT N_FACTOR");
}
#line 1894 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 353 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIGN", "T_PLUS");
}
#line 1902 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 357 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIGN", "T_MINUS");
}
#line 1910 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 361 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_SIGN", "epsilon");
}
#line 1918 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 366 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ADDOP", "T_PLUS");
}
#line 1926 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 370 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ADDOP", "T_MINUS");
}
#line 1934 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 374 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ADDOP", "T_OR");
}
#line 1942 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 379 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_MULTOP", "T_MULT");
}
#line 1950 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 383 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_MULTOP", "T_DIV");
}
#line 1958 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 387 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_MULTOP", "T_AND");
}
#line 1966 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 392 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_RELOP", "T_LT");
}
#line 1974 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 396 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_RELOP", "T_LE");
}
#line 1982 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 400 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_RELOP", "T_NE");
}
#line 1990 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_RELOP", "T_EQ");
}
#line 1998 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 408 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_RELOP", "T_GT");
}
#line 2006 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 412 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_RELOP", "T_GE");
}
#line 2014 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 417 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARIABLE", "N_ENTIREVAR");
}
#line 2022 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 421 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARIABLE", "N_IDXVAR");
}
#line 2030 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 426 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
}
#line 2038 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 431 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ARRAYVAR", "N_ENTIREVAR");
}
#line 2046 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 436 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_ENTIREVAR", "N_VARIDENT");
}
#line 2054 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 441 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_VARIDENT", "T_IDENT");
}
#line 2062 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 446 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_CONST", "N_INTCONST");
}
#line 2070 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 450 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_CONST", "T_CHARCONST");
}
#line 2078 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 454 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_CONST", "N_BOOLCONST");
}
#line 2086 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 459 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_INTCONST", "N_SIGN T_INTCONST");
}
#line 2094 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 464 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_BOOLCONST", "T_TRUE");
}
#line 2102 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 468 "rainwaterj.y" /* yacc.c:1646  */
    {
    printRule("N_BOOLCONST", "T_FALSE");
}
#line 2110 "rainwaterj.tab.c" /* yacc.c:1646  */
    break;


#line 2114 "rainwaterj.tab.c" /* yacc.c:1646  */
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
#line 472 "rainwaterj.y" /* yacc.c:1906  */


#include "lex.yy.c"
extern FILE *yyin;

void printToken(const char* tokenType, const char* lexeme) {
    printf("TOKEN: %s LEXEME:\t%s\n", tokenType, lexeme);
}

void printError(const char* error, const char* lexeme) {
    printf("**** %s: %s\n",error, yytext);
}

int yyerror(const char *s) {
  printf("Line %d: syntax error\n", numLines);
  return(1);
}

bool validateIntConst(const char* intconst) {
    for(int idx = 0; intconst[idx]; ++idx){
        const char digit = intconst[idx];
        const char max = maxint[idx];
        if(digit > max)
            return false;
        else if(digit < max)
            return true;
    }

    return true;
}

void printRule(const char* lhs, const char* rhs) {
    printf("%s -> %s\n", lhs, rhs);
}

int main() {
  do {
  yyparse();
  } while (!feof(yyin));

  // printf("%d lines processed\n", numLines);
  return 0;
}
