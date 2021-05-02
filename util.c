#include "globals.h"
#include "util.h"

char *copyString(char *str)
{
	if (str == NULL) return NULL;
	int n = strlen(str) + 1;
	char *c = (char *)malloc(n);
	strcpy(c, str);
	return c;
}

void printTab(int x, ostream &out)
{
	for (int i = 1; i <= x; i++)out << '\t';
}

void printTab(int x)
{
	for (int i = 1; i <= x; i++)cout << '\t';
}