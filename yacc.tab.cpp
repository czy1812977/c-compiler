/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbol.h"
extern int yylex(void);
extern char* yytext;
extern FILE * yyin;
extern int yylineno;
struct ASTNode
{
    int line; //行号
    char* name; //语法单元名字
    struct ASTNode *left;  //第一个子节点
    struct ASTNode *right;  //兄弟节点
    char* idname; //id型节点的名字
    int value;  //int型节点的    
};

/*  创建节点函数  */
struct ASTNode *newAstnode(char* name,char* text,int num,...);

/*  遍历语法树函数  level为树的层数*/
void eval(struct ASTNode*, int level);
void yyerror(const char *str);

#line 98 "yacc.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
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
    RETURN = 258,
    INT = 259,
    TYPE = 260,
    ID = 261,
    FOR = 262,
    RELOP = 263,
    AND = 264,
    OR = 265,
    NOT = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    LOWER_THAN_ELSE = 270,
    ERRID = 271
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "yacc.y"

	struct ASTNode* ast;

#line 171 "yacc.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

#define YYUNDEFTOK  2
#define YYMAXUTOK   271


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    15,     2,     2,
      17,    18,    13,    12,     9,    11,     2,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     8,
       2,    10,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,    16,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
       5,     6,     7,    21,    22,    23,    24,    25,    26,    27,
      30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    65,    66,    69,    70,    71,    72,    75,
      76,    81,    82,    85,    86,    90,    91,    94,    95,   100,
     101,   105,   106,   107,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   133,   134,   140,   141,   145,   146,   150,
     151,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   178,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "INT", "TYPE", "ID", "FOR",
  "';'", "','", "'='", "'-'", "'+'", "'*'", "'/'", "'%'", "'^'", "'('",
  "')'", "'['", "']'", "RELOP", "AND", "OR", "NOT", "IF", "ELSE", "WHILE",
  "'{'", "'}'", "LOWER_THAN_ELSE", "ERRID", "$accept", "Root",
  "external_definition_list", "external_definition",
  "external_declaration_list", "variable_declaration",
  "function_declaration", "variable_list", "param_declaration",
  "local_statement", "statement_list", "statement", "for_declaration",
  "definition", "declaration_list", "declaration", "expression", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    59,    44,
      61,    45,    43,    42,    47,    37,    94,    40,    41,    91,
      93,   263,   264,   265,   266,   267,   268,   269,   123,   125,
     270,   271
};
# endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    32,    20,     7,   -41,    37,   -41,    42,   -41,     9,
     -41,   -41,    10,    35,   -41,    39,    40,   -41,     2,   -41,
      64,   -41,    25,   -41,    53,    65,   -41,   -41,    -7,   144,
     -41,    79,    38,    69,   221,   221,   221,    70,    72,   -41,
     115,   -41,    82,   236,   -41,    88,   -41,   -41,    96,   -41,
      90,   -41,   252,   100,    13,   -41,    97,   145,   221,   130,
     114,   298,    92,   221,   221,   -41,   -41,   -41,   -41,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     -41,   -41,   221,   -41,   -41,    39,   -41,   424,    26,   312,
      24,    39,   166,   104,   -41,   424,   -41,   326,   340,   424,
     114,   114,    17,    17,    17,    92,   354,   460,   449,   437,
     424,   -41,   221,   -41,   -41,   -41,   174,   268,   178,    71,
      71,   -41,   424,    71,   368,   193,   202,   284,    87,   -41,
     -41,    71,    71,   382,    71,   396,   217,    71,   -41,   -41,
      71,   -41,    71,    71,   410,   -41,   -41,   -41,   -41,    71,
     -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,    11,     6,     0,     9,     0,
       1,     4,     0,     0,     5,     0,     0,     8,     0,     7,
      18,    14,     0,    16,     0,    11,    10,    20,     0,     0,
      69,     0,    67,     0,     0,     0,     0,     0,     0,    28,
       0,    21,     0,     0,    17,     0,    13,    12,    42,    70,
       0,    30,     0,    49,     0,    45,    47,     0,     0,     0,
      62,     0,    63,     0,     0,    19,    22,    25,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    29,     0,    27,    26,     0,    65,    72,     0,     0,
       0,     0,     0,     0,    43,    44,    61,     0,     0,    51,
      56,    55,    57,    58,    59,    60,     0,    54,    52,    53,
      50,    48,     0,    64,    68,    46,     0,     0,     0,     0,
       0,    66,    71,     0,     0,     0,     0,     0,    31,    33,
      34,     0,     0,     0,     0,     0,     0,     0,    37,    36,
       0,    35,     0,     0,     0,    32,    41,    40,    39,     0,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   120,   -41,     1,    86,   -41,   108,    -5,
     -41,   -40,   -41,    78,    73,   -41,   -11,   -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     7,    53,     9,    22,    23,    39,
      40,    41,    93,    42,    55,    56,    43,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    48,     8,    28,    19,    29,    30,    31,    32,    33,
      16,    49,     1,    34,    16,    20,    26,    17,    52,    35,
      10,    83,    27,    60,    61,    62,    36,    37,    21,    38,
      18,   -23,   115,    75,    45,   112,    76,    18,     5,    24,
       6,    18,    49,    46,   113,    25,    87,    89,    95,    84,
      14,    15,    97,    98,    12,    57,    13,    58,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    27,
      44,   110,    28,    47,    29,    30,    31,    32,    33,   128,
     129,   117,    34,   130,    13,     5,    59,    63,    35,    64,
      67,   138,   139,    20,   141,    36,    37,   145,    38,    18,
     146,   122,   147,   148,   -46,   124,    85,   127,    49,   150,
      82,    76,   118,   137,   133,   135,    28,    54,    29,    30,
      31,    32,    33,    11,     0,   144,    34,    72,    73,    74,
      75,    90,    35,    76,    30,    91,    32,    94,    92,    36,
      37,    34,    38,    18,    65,    50,    50,    35,    30,    30,
      32,    32,    51,    80,    36,    34,    34,     0,   111,     0,
       0,    35,    35,    86,     0,     0,     0,    50,    36,    36,
      30,     0,    32,     0,   116,    50,     0,    34,    30,    50,
      32,     0,    30,    35,    32,    34,   126,     0,     0,    34,
      36,    35,   123,     0,    50,    35,     0,    30,    36,    32,
       0,     0,    36,    50,    34,     0,    30,     0,    32,     0,
      35,   132,     0,    34,     0,     0,     0,    36,    50,    35,
     134,    30,    50,    32,     0,    30,    36,    32,    34,     0,
       0,     0,    34,     0,    35,   143,     0,     0,    35,     0,
       0,    36,     0,     0,    68,    36,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,     0,    77,    78,    79,
      81,     0,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,     0,    77,    78,    79,   125,     0,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,     0,    77,
      78,    79,   136,     0,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,     0,    77,    78,    79,    69,    70,
      71,    72,    73,    74,    75,     0,    96,    76,     0,    77,
      78,    79,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,   114,    77,    78,    79,    69,    70,    71,    72,
      73,    74,    75,     0,   119,    76,     0,    77,    78,    79,
      69,    70,    71,    72,    73,    74,    75,     0,   120,    76,
       0,    77,    78,    79,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,   121,    77,    78,    79,    69,    70,
      71,    72,    73,    74,    75,     0,   131,    76,     0,    77,
      78,    79,    69,    70,    71,    72,    73,    74,    75,     0,
     140,    76,     0,    77,    78,    79,    69,    70,    71,    72,
      73,    74,    75,     0,   142,    76,     0,    77,    78,    79,
      69,    70,    71,    72,    73,    74,    75,     0,   149,    76,
       0,    77,    78,    79,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,     0,    77,    78,    79,    70,    71,
      72,    73,    74,    75,     0,     0,    76,     0,    77,    78,
      70,    71,    72,    73,    74,    75,     0,     0,    76,     0,
      77,    70,    71,    72,    73,    74,    75,     0,     0,    76
};

static const yytype_int16 yycheck[] =
{
      40,     8,     1,     1,     9,     3,     4,     5,     6,     7,
       1,    18,     5,    11,     1,     5,    15,     8,    29,    17,
       0,     8,    29,    34,    35,    36,    24,    25,    18,    27,
      28,    29,     8,    16,     9,     9,    19,    28,     6,     4,
       8,    28,    18,    18,    18,     6,    57,    58,    59,    54,
       8,     9,    63,    64,    17,    17,    19,    19,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    29,
       6,    82,     1,    20,     3,     4,     5,     6,     7,   119,
     120,    92,    11,   123,    19,     6,    17,    17,    17,    17,
       8,   131,   132,     5,   134,    24,    25,   137,    27,    28,
     140,   112,   142,   143,     8,   116,     9,   118,    18,   149,
      10,    19,     8,    26,   125,   126,     1,    31,     3,     4,
       5,     6,     7,     3,    -1,   136,    11,    13,    14,    15,
      16,     1,    17,    19,     4,     5,     6,    59,     8,    24,
      25,    11,    27,    28,    29,     1,     1,    17,     4,     4,
       6,     6,     8,    45,    24,    11,    11,    -1,    85,    -1,
      -1,    17,    17,    18,    -1,    -1,    -1,     1,    24,    24,
       4,    -1,     6,    -1,     8,     1,    -1,    11,     4,     1,
       6,    -1,     4,    17,     6,    11,     8,    -1,    -1,    11,
      24,    17,    18,    -1,     1,    17,    -1,     4,    24,     6,
      -1,    -1,    24,     1,    11,    -1,     4,    -1,     6,    -1,
      17,    18,    -1,    11,    -1,    -1,    -1,    24,     1,    17,
      18,     4,     1,     6,    -1,     4,    24,     6,    11,    -1,
      -1,    -1,    11,    -1,    17,    18,    -1,    -1,    17,    -1,
      -1,    24,    -1,    -1,     8,    24,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    -1,    21,    22,    23,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    21,    22,    23,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    19,    -1,    21,
      22,    23,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    -1,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    -1,    21,
      22,    23,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    20,    21,    22,    23,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    -1,    21,    22,    23,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      -1,    21,    22,    23,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    -1,    21,
      22,    23,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    -1,    21,    22,    23,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    -1,    21,    22,    23,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      -1,    21,    22,    23,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    -1,    21,    22,    23,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    21,    22,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    -1,
      21,    11,    12,    13,    14,    15,    16,    -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    33,    34,    35,     6,     8,    36,    37,    38,
       0,    35,    17,    19,     8,     9,     1,     8,    28,    41,
       5,    18,    39,    40,     4,     6,    37,    29,     1,     3,
       4,     5,     6,     7,    11,    17,    24,    25,    27,    41,
      42,    43,    45,    48,     6,     9,    18,    20,     8,    18,
       1,     8,    48,    37,    38,    46,    47,    17,    19,    17,
      48,    48,    48,    17,    17,    29,    43,     8,     8,    10,
      11,    12,    13,    14,    15,    16,    19,    21,    22,    23,
      40,     8,    10,     8,    41,     9,    18,    48,    49,    48,
       1,     5,     8,    44,    45,    48,    18,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    46,     9,    18,    20,     8,     8,    48,     8,    18,
      18,    20,    48,    18,    48,     8,     8,    48,    43,    43,
      43,    18,    18,    48,    18,    48,     8,    26,    43,    43,
      18,    43,    18,    18,    48,    43,    43,    43,    43,    18,
      43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    36,
      36,    37,    37,    38,    38,    39,    39,    40,    40,    41,
      41,    42,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     1,
       3,     1,     4,     4,     3,     3,     1,     2,     1,     3,
       2,     1,     2,     0,     2,     2,     3,     3,     1,     3,
       2,     5,     7,     5,     6,     7,     7,     7,     9,     8,
       8,     8,     2,     1,     1,     2,     2,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     1,     4,     1,
       2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 62 "yacc.y"
                                {(yyval.ast) = newAstnode("Root","",1,(yyvsp[0].ast)); eval((yyval.ast),0);}
#line 1507 "yacc.tab.cpp"
    break;

  case 3:
#line 65 "yacc.y"
                           { (yyval.ast) = newAstnode("external_definition_list","",1,(yyvsp[0].ast));}
#line 1513 "yacc.tab.cpp"
    break;

  case 4:
#line 66 "yacc.y"
                                                   { (yyval.ast) = newAstnode("external_definition_list","",2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1519 "yacc.tab.cpp"
    break;

  case 5:
#line 69 "yacc.y"
                                                        { (yyval.ast) = newAstnode("external_definition","",2,(yyvsp[-2].ast),(yyvsp[-1].ast));}
#line 1525 "yacc.tab.cpp"
    break;

  case 6:
#line 70 "yacc.y"
                                                        { (yyval.ast) = newAstnode("external_definition","",1,(yyvsp[-1].ast));}
#line 1531 "yacc.tab.cpp"
    break;

  case 7:
#line 71 "yacc.y"
                                                        { (yyval.ast) = newAstnode("external_definition","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1537 "yacc.tab.cpp"
    break;

  case 8:
#line 72 "yacc.y"
                                                        { (yyval.ast) = newAstnode("external_definition","",2,(yyvsp[-2].ast),(yyvsp[-1].ast));}
#line 1543 "yacc.tab.cpp"
    break;

  case 9:
#line 75 "yacc.y"
                                                          { (yyval.ast) = newAstnode("external_declaration_list","",1,(yyvsp[0].ast));}
#line 1549 "yacc.tab.cpp"
    break;

  case 10:
#line 76 "yacc.y"
                                                          { (yyval.ast) = newAstnode("external_declaration_list","",2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1555 "yacc.tab.cpp"
    break;

  case 11:
#line 81 "yacc.y"
                                                        { if ((yyvsp[0].ast)->idname!=NULL) if(base.using_table->addSymbol((yyvsp[0].ast)->idname,symbolType::integer) ==-1) yyerror("ERROR: repeated declaration!"); (yyval.ast) = newAstnode("variable_declaration","",1,(yyvsp[0].ast));}
#line 1561 "yacc.tab.cpp"
    break;

  case 12:
#line 82 "yacc.y"
                                                        { if ((yyvsp[-3].ast)->idname!=NULL) if(base.using_table->addArraySymbol((yyvsp[-3].ast)->idname,(yyvsp[-1].ast)->value) ==-1) yyerror("ERROR: repeated declaration!");(yyval.ast) = newAstnode("variable_declaration","",4,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1567 "yacc.tab.cpp"
    break;

  case 13:
#line 85 "yacc.y"
                                                        { funcflag=1;if ((yyvsp[-3].ast)->idname!=NULL) if(base.using_table->addSymbol((yyvsp[-3].ast)->idname,symbolType::function) ==-1) yyerror("ERROR: repeated declaration!");(yyval.ast) = newAstnode("function_declaration","",4,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1573 "yacc.tab.cpp"
    break;

  case 14:
#line 86 "yacc.y"
                                                        { funcflag=1;if ((yyvsp[-2].ast)->idname!=NULL) if(base.using_table->addSymbol((yyvsp[-2].ast)->idname,symbolType::function) ==-1) yyerror("ERROR: repeated declaration!");(yyval.ast) = newAstnode("function_declaration","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1579 "yacc.tab.cpp"
    break;

  case 15:
#line 90 "yacc.y"
                                                        { (yyval.ast) = newAstnode("variable_list","",2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1585 "yacc.tab.cpp"
    break;

  case 16:
#line 91 "yacc.y"
                                                        { (yyval.ast) = newAstnode("variable_list","",1,(yyvsp[0].ast));}
#line 1591 "yacc.tab.cpp"
    break;

  case 17:
#line 94 "yacc.y"
                                                        { (yyval.ast) = newAstnode("param_declaration","",2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1597 "yacc.tab.cpp"
    break;

  case 18:
#line 95 "yacc.y"
                                                        { (yyval.ast) = newAstnode("param_declaration","",1,(yyvsp[0].ast));}
#line 1603 "yacc.tab.cpp"
    break;

  case 19:
#line 100 "yacc.y"
                                                        { (yyval.ast) = newAstnode("local_statement","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1609 "yacc.tab.cpp"
    break;

  case 20:
#line 101 "yacc.y"
                                                        { yyerrok;}
#line 1615 "yacc.tab.cpp"
    break;

  case 21:
#line 105 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statememt_list","",1,(yyvsp[0].ast));}
#line 1621 "yacc.tab.cpp"
    break;

  case 22:
#line 106 "yacc.y"
                                                            { (yyval.ast) = newAstnode("statement_list","",2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1627 "yacc.tab.cpp"
    break;

  case 23:
#line 107 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement_list","",-1);}
#line 1633 "yacc.tab.cpp"
    break;

  case 24:
#line 111 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",1,(yyvsp[-1].ast));}
#line 1639 "yacc.tab.cpp"
    break;

  case 25:
#line 112 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",1,(yyvsp[-1].ast));}
#line 1645 "yacc.tab.cpp"
    break;

  case 26:
#line 113 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1651 "yacc.tab.cpp"
    break;

  case 27:
#line 114 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",2,(yyvsp[-2].ast),(yyvsp[-1].ast));}
#line 1657 "yacc.tab.cpp"
    break;

  case 28:
#line 115 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",1,(yyvsp[0].ast));}
#line 1663 "yacc.tab.cpp"
    break;

  case 29:
#line 116 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",2,(yyvsp[-2].ast),(yyvsp[-1].ast));}
#line 1669 "yacc.tab.cpp"
    break;

  case 30:
#line 117 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",1,(yyvsp[-1].ast));}
#line 1675 "yacc.tab.cpp"
    break;

  case 31:
#line 118 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",5,(yyvsp[-4].ast),(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1681 "yacc.tab.cpp"
    break;

  case 32:
#line 119 "yacc.y"
                                                                                { (yyval.ast) = newAstnode("statement","",7,(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-4].ast),(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1687 "yacc.tab.cpp"
    break;

  case 33:
#line 120 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",5,(yyvsp[-4].ast),(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1693 "yacc.tab.cpp"
    break;

  case 34:
#line 121 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",4,(yyvsp[-5].ast),(yyvsp[-4].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1699 "yacc.tab.cpp"
    break;

  case 35:
#line 122 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",5,(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-4].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1705 "yacc.tab.cpp"
    break;

  case 36:
#line 123 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",5,(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1711 "yacc.tab.cpp"
    break;

  case 37:
#line 124 "yacc.y"
                                                        { (yyval.ast) = newAstnode("statement","",5,(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1717 "yacc.tab.cpp"
    break;

  case 38:
#line 125 "yacc.y"
                                                                           { (yyval.ast) = newAstnode("statement","",7,(yyvsp[-8].ast),(yyvsp[-7].ast),(yyvsp[-6].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1723 "yacc.tab.cpp"
    break;

  case 39:
#line 126 "yacc.y"
                                                                           { (yyval.ast) = newAstnode("statement","",6,(yyvsp[-7].ast),(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1729 "yacc.tab.cpp"
    break;

  case 40:
#line 127 "yacc.y"
                                                                           { (yyval.ast) = newAstnode("statement","",6,(yyvsp[-7].ast),(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1735 "yacc.tab.cpp"
    break;

  case 41:
#line 128 "yacc.y"
                                                                           { (yyval.ast) = newAstnode("statement","",6,(yyvsp[-7].ast),(yyvsp[-6].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1741 "yacc.tab.cpp"
    break;

  case 42:
#line 129 "yacc.y"
                                                                           { yyerrok;}
#line 1747 "yacc.tab.cpp"
    break;

  case 43:
#line 133 "yacc.y"
                                                        { (yyval.ast) = newAstnode("for_declaration","",1,(yyvsp[0].ast));}
#line 1753 "yacc.tab.cpp"
    break;

  case 44:
#line 134 "yacc.y"
                                                        { (yyval.ast) = newAstnode("for_declaration","",1,(yyvsp[0].ast));}
#line 1759 "yacc.tab.cpp"
    break;

  case 45:
#line 140 "yacc.y"
                                                         { (yyval.ast) = newAstnode("definition","",2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1765 "yacc.tab.cpp"
    break;

  case 46:
#line 141 "yacc.y"
                                                         { yyerrok; }
#line 1771 "yacc.tab.cpp"
    break;

  case 47:
#line 145 "yacc.y"
                                                         { (yyval.ast) = newAstnode("declaration_list","",1,(yyvsp[0].ast));}
#line 1777 "yacc.tab.cpp"
    break;

  case 48:
#line 146 "yacc.y"
                                                         { (yyval.ast) = newAstnode("declaration_list","",2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1783 "yacc.tab.cpp"
    break;

  case 49:
#line 150 "yacc.y"
                                                         {  (yyval.ast) = newAstnode("declaration","",1,(yyvsp[0].ast));}
#line 1789 "yacc.tab.cpp"
    break;

  case 50:
#line 151 "yacc.y"
                                                         { (yyval.ast) = newAstnode("declaration","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1795 "yacc.tab.cpp"
    break;

  case 51:
#line 156 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1801 "yacc.tab.cpp"
    break;

  case 52:
#line 157 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1807 "yacc.tab.cpp"
    break;

  case 53:
#line 158 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1813 "yacc.tab.cpp"
    break;

  case 54:
#line 159 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1819 "yacc.tab.cpp"
    break;

  case 55:
#line 160 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1825 "yacc.tab.cpp"
    break;

  case 56:
#line 161 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1831 "yacc.tab.cpp"
    break;

  case 57:
#line 162 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1837 "yacc.tab.cpp"
    break;

  case 58:
#line 163 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1843 "yacc.tab.cpp"
    break;

  case 59:
#line 164 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1849 "yacc.tab.cpp"
    break;

  case 60:
#line 165 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1855 "yacc.tab.cpp"
    break;

  case 61:
#line 166 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1861 "yacc.tab.cpp"
    break;

  case 62:
#line 167 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1867 "yacc.tab.cpp"
    break;

  case 63:
#line 168 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1873 "yacc.tab.cpp"
    break;

  case 64:
#line 169 "yacc.y"
                                                        { if(base.using_table->findSymbol((yyvsp[-3].ast)->idname)==NULL) yyerror("ERROR: haven`t declaration!");(yyval.ast) = newAstnode("expression","",4,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1879 "yacc.tab.cpp"
    break;

  case 65:
#line 170 "yacc.y"
                                                        { if(base.using_table->findSymbol((yyvsp[-2].ast)->idname)==NULL) yyerror("ERROR: haven`t declaration!");(yyval.ast) = newAstnode("expression","",3,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1885 "yacc.tab.cpp"
    break;

  case 66:
#line 171 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",4,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1891 "yacc.tab.cpp"
    break;

  case 67:
#line 172 "yacc.y"
                                                        { if(base.using_table->findSymbol((yyvsp[0].ast)->idname)==2) yyerror("ERROR: haven`t declaration!");(yyval.ast) = newAstnode("expression","",1,(yyvsp[0].ast));}
#line 1897 "yacc.tab.cpp"
    break;

  case 68:
#line 173 "yacc.y"
                                                        { if(base.using_table->findSymbol((yyvsp[-3].ast)->idname)==NULL) yyerror("ERROR: haven`t declaration!");(yyval.ast) = newAstnode("expression","",4,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1903 "yacc.tab.cpp"
    break;

  case 69:
#line 174 "yacc.y"
                                                        { (yyval.ast) = newAstnode("expression","",1,(yyvsp[0].ast));}
#line 1909 "yacc.tab.cpp"
    break;

  case 70:
#line 175 "yacc.y"
                                                        { yyerrok; }
#line 1915 "yacc.tab.cpp"
    break;

  case 71:
#line 178 "yacc.y"
                                                        { (yyval.ast) = newAstnode("Args","",2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1921 "yacc.tab.cpp"
    break;

  case 72:
#line 179 "yacc.y"
                                                        { (yyval.ast) = newAstnode("Args","",1,(yyvsp[0].ast));}
#line 1927 "yacc.tab.cpp"
    break;


#line 1931 "yacc.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 182 "yacc.y"



struct ASTNode *newAstnode(char* name,char* text,int num,...){
    va_list varlist;  //定义参数列表
    struct ASTNode *news = (struct ASTNode*)malloc(sizeof(struct ASTNode));  //新生成节点
    struct ASTNode *temp = (struct ASTNode*)malloc(sizeof(struct ASTNode));  //临时节点
    if(!news){
        yyerror("out of space");
        exit(0);
    }
    news->name = name;
    va_start(varlist,num); //将varlist初始化为num之后的所有参数组成的列表

    if(num > 0){ //表示有节点传
        temp = va_arg(varlist,struct ASTNode*);  //将varlist中第一个节点拿出
        news->left = temp;  //将temp赋给新建节点的子节点
        news->line = temp->line;  //且行号相同  即处于同一行
        if(num >= 2){  //如果传入多个节点
            for(int i = 0;i<num-1;i++){
                temp->right = va_arg(varlist,struct ASTNode*);  //将下一个传入的节点赋给new的左节点（其孩子节点）的右节点
                temp = temp->right;  //
            }
        }
    }
    else
    {
        int flag = va_arg(varlist,int);  //取num后参数列表中的第一个int型值
        news->line = flag;
        if(( !strcmp(news->name,"ID") || !strcmp(news->name,"TYPE"))){       //如果为id int void 将其名字赋值给idname
            news->idname = strdup(text);
        }                       
        else if( !strcmp(news->name,"INT") ){        //如果为int数值 则赋值给value
            news->value = atoi(text);
        }   
        else
        {
                // 其他类型暂不需要
        }
            
    }  
    return news;  //将新建节点返回
}

 
void eval(struct ASTNode* root, int level){  //先序遍历
    if(root != NULL){
        if(!strcmp(root->name,"statement_list")){
            eval(root->left,level);
            eval(root->right,level-1);
        }
        else{
            for(int i=0;i<level;i++)
            printf("|-");  //缩进
            if(root ->line != -1){   //为-1时不需打印
                printf("%s",root->name);
            if( (!strcmp(root->name,"ID")) || (!strcmp(root->name,"TYPE")) )
                printf(":%s ",root->idname);
            else if( !strcmp(root->name,"INT"))
                printf(":%d",root->value);
            else
                {}//printf("  %d",root->line);
            }
            printf("\n");
            eval(root->left,level+1);  //打印子节点
            eval(root->right,level); //打印兄弟节点
        }
           
    }
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

int main(int args, char **argv){
    yyin = fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
    return 0;
}
