#include "globals.h"
#include "SysY.tab.h"
#include "util.h"
#include "ast.h"

extern ASTPtr parse();

int main()
{
	const char* sFile = "test.sysy";
	FILE* fp = stdin;
	if(fp == NULL){
		puts("File not found\n");
		return 0;
	}
	extern FILE* yyin;
	yyin = fp;

	ASTPtr tree = parse();
	tree->debug(0);
	return 0;
}