LEX = flex
YACC = bison
CC = g++ -W -std=c++17 -Wno-deprecated-register -Wno-inconsistent-missing-override
OBJECT = main 


compiler:
	flex -o lex.yy.cpp source.l
	bison -d -o source.tab.cpp source.y
	g++ -Wno-register -O2 -lm -std=c++17 *.cpp -o compiler -Idirs

parser: source.tab.o lex.yy.o parser.cpp
	$(CC) source.tab.o lex.yy.o util.c ast.cpp parser.cpp -o parser

source.tab.c source.tab.h: source.y
	$(YACC) source.y -d

lex.yy.c: source.l
	$(LEX) source.l

clean:
	rm -f main lex.yy.* *.tab.* source.tab.o parser main compiler