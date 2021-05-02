#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

#define DEBUG

#define MAXTOKENLEN 40
#define TRUE 1
#define FALSE 0

typedef int TokenType;

#if __cplusplus > 199711L
#define register 
#endif

/*
typedef enum {
    // Reserved words
    CONST, INT, VOID, IF, WHILE, ELSE, CONTINUE, BREAK, RETURN,
    // Symbols
    COMMA, SEMICOLON, LSQUARE, RSQUARE, LPAREN, RPAREN, ASSIGN, LBRACE, RBRACE,
    ADD, MINUS, TIMES, DIVIDE, MOD,
    LT, GT, LE, GE, EQ, NEQ,
    AND, OR, NOT,
    POSITIVE, NEGATIVE,
    // Multi-character
    NUM, ID,
    // Others
    ERROR,
} TokenType;*/

extern FILE *source;
extern FILE *target;

extern int lineno;

extern "C" {
	TokenType getToken(void);
	int yywrap(void);
	int yylex(void);
	int calc(const char *, int);
	void yyerror(const char *);
}

#define CERR cerr

#endif