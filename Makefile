LEX = flex
YACC = bison
CC = g++ -std=c++17 -Wno-deprecated-register -Wno-inconsistent-missing-override
OBJECT = main 

main: source.tab.c lex.yy.c main.cpp
	$(CC) source.tab.c lex.yy.c util.c compiler.cpp ast.cpp main.cpp ir.cpp -o main

main-gdb: source.tab.c lex.yy.c main.cpp
	$(CC) -g source.tab.c lex.yy.c util.c compiler.cpp ast.cpp main.cpp ir.cpp -o main

parser: source.tab.o lex.yy.o parser.cpp
	$(CC) source.tab.o lex.yy.o util.c ast.cpp parser.cpp -o parser

source.tab.c source.tab.h: source.y
	$(YACC) source.y -d

lex.yy.c: source.l
	$(LEX) source.l

test:
	flex -o lex.yy.cpp source.l
	bison -d -o source.tab.cpp source.y
	g++ -Wno-register -O2 -lm -std=c++17 *.cpp -o compiler -Idirs

clean:
	rm -f main lex.yy.* *.tab.* source.tab.o parser main 