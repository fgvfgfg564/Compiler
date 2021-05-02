#include "globals.h"
#include "compiler.h"

extern ASTPtr parse();

int main()
{
	const char* inFile = "test.sysy";
	string outFile = "test.ee";
	FILE* fin = fopen(inFile, "r");
	ofstream newFile(outFile);
	if(fin == NULL){
		puts("File not found\n");
		return 0;
	}
	extern FILE* yyin;
	yyin = fin;

	ASTPtr tree = parse();
	EeyoreGenerator gen(cout);
	tree->generateIR(gen);
	return 0;
}