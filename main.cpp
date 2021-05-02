#include "globals.h"
#include "compiler.h"
#include "unistd.h"

extern ASTPtr parse();

int main(int argc, char *argv[])
{
	const char *optString = "Se:o:";
	char *inFile, *outFile;
	char mode = 0;
	char opt;
	while ((opt = getopt(argc, argv, optString)) != -1) {
		switch (opt) {
			case 'S': mode = 'S'; break;
			case 'e': inFile = optarg; break;
			case 'o': outFile = optarg; break;
		}
	}
	FILE *fin = fopen(inFile, "r");
	ofstream newFile(outFile);
	if (fin == NULL) {
		puts("File not found\n");
		return 0;
	}
	extern FILE *yyin;
	yyin = fin;

	if (mode == 'S') {
		ASTPtr tree = parse();
		EeyoreGenerator gen(newFile);
		tree->generateIR(gen);
	}
	return 0;
}