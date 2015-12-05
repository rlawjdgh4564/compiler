/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 9 "expr.y" /* yacc.c:1909  */

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

#line 115 "expr.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPR_TAB_H_INCLUDED  */
