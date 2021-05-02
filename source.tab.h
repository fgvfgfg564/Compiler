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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

