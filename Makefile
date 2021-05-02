LEX = flex
YACC = bison
CC = g++ -std=c++17 -Wno-deprecated-register -Wno-inconsistent-missing-override 
OBJECT = main 

main: SysY.tab.c lex.yy.c main.cpp
	$(CC) SysY.tab.c lex.yy.c util.c compiler.cpp ast.cpp main.cpp ir.cpp -o main

main-gdb: SysY.tab.c lex.yy.c main.cpp
	$(CC) -g SysY.tab.c lex.yy.c util.c compiler.cpp ast.cpp main.cpp ir.cpp -o main

parser: SysY.tab.o lex.yy.o parser.cpp
	$(CC) SysY.tab.o lex.yy.o util.c ast.cpp parser.cpp -o parser

SysY.tab.c SysY.tab.h: SysY.y
	$(YACC) SysY.y -d

lex.yy.c: Sysy.l
	$(LEX) SysY.l

clean:
	rm -f main lex.yy.* SysY.tab.* SysY.tab.o parser main 