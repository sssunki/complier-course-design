/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     ID = 259,
     RELOP = 260,
     TYPE = 261,
     FLOAT = 262,
     DPLUS = 263,
     LP = 264,
     RP = 265,
     LC = 266,
     RC = 267,
     SEMI = 268,
     COMMA = 269,
     PLUS = 270,
     MINUS = 271,
     STAR = 272,
     DIV = 273,
     ASSIGNOP = 274,
     AND = 275,
     OR = 276,
     NOT = 277,
     IF = 278,
     ELSE = 279,
     WHILE = 280,
     RETURN = 281,
     FOR = 282,
     SWITCH = 283,
     CASECOLON = 284,
     DEFAULT = 285,
     EXT_DEF_LIST = 286,
     EXT_VAR_DEF = 287,
     FUNC_DEF = 288,
     FUNC_DEC = 289,
     EXT_DEC_LIST = 290,
     PARAM_LIST = 291,
     PARAM_DEC = 292,
     VAR_DEF = 293,
     DEC_LIST = 294,
     DEF_LIST = 295,
     COMP_STM = 296,
     STM_LIST = 297,
     EXP_STMT = 298,
     IF_THEN = 299,
     IF_THEN_ELSE = 300,
     FUNC_CALL = 301,
     ARGS = 302,
     FUNCTION = 303,
     PARAM = 304,
     ARG = 305,
     CALL = 306,
     LABEL = 307,
     GOTO = 308,
     JLT = 309,
     JLE = 310,
     JGT = 311,
     JGE = 312,
     EQ = 313,
     NEQ = 314,
     UMINUS = 315,
     LOWER_THEN_ELSE = 316
   };
#endif
/* Tokens.  */
#define INT 258
#define ID 259
#define RELOP 260
#define TYPE 261
#define FLOAT 262
#define DPLUS 263
#define LP 264
#define RP 265
#define LC 266
#define RC 267
#define SEMI 268
#define COMMA 269
#define PLUS 270
#define MINUS 271
#define STAR 272
#define DIV 273
#define ASSIGNOP 274
#define AND 275
#define OR 276
#define NOT 277
#define IF 278
#define ELSE 279
#define WHILE 280
#define RETURN 281
#define FOR 282
#define SWITCH 283
#define CASECOLON 284
#define DEFAULT 285
#define EXT_DEF_LIST 286
#define EXT_VAR_DEF 287
#define FUNC_DEF 288
#define FUNC_DEC 289
#define EXT_DEC_LIST 290
#define PARAM_LIST 291
#define PARAM_DEC 292
#define VAR_DEF 293
#define DEC_LIST 294
#define DEF_LIST 295
#define COMP_STM 296
#define STM_LIST 297
#define EXP_STMT 298
#define IF_THEN 299
#define IF_THEN_ELSE 300
#define FUNC_CALL 301
#define ARGS 302
#define FUNCTION 303
#define PARAM 304
#define ARG 305
#define CALL 306
#define LABEL 307
#define GOTO 308
#define JLT 309
#define JLE 310
#define JGT 311
#define JGE 312
#define EQ 313
#define NEQ 314
#define UMINUS 315
#define LOWER_THEN_ELSE 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "chapter2/parser.y"
{
int type_int;
float type_float; 
char type_id[32]; 
struct ASTNode *ptr;
}
/* Line 1529 of yacc.c.  */
#line 178 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
