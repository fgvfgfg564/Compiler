%{
#include "globals.h"
#include "util.h"
#include "ast.h"
#include "SysY.tab.h"
char tokenString[MAXTOKENLEN+1];
%}

letter      [A-Za-z_]
digit8      [0-7]
digit10     [0-9]
digit16     [0-9A-Fa-f]
num8        0[1-7]{digit8}*
num10       0|([1-9]{digit10}*)
num16       ((0x)|(0X)){digit16}*
identifier  {letter}({letter}|{digit10})*
whitespace  [ \t\n]+
remark		(\/\*([^\*]|\*+[^\/\*])*\*+\/)|(\/\/[^\n]*\n)

%%

{remark}	{}
"const"     {return CONST;}
"int"       {return INT;}
"void"      {return VOID;}
"if"        {return IF;}
"while"     {return WHILE;}
"else"      {return ELSE;}
"break"     {return BREAK;}
"continue"  {return CONTINUE;}
"return"    {return RETURN;}
","     {return COMMA;}
";"     {return SEMICOLON;}
"{"		{return LBRACE;}
"}"		{return RBRACE;}
"["     {return LSQUARE;}
"]"     {return RSQUARE;}
"("     {return LPAREN;}
")"     {return RPAREN;}
"="     {return ASSIGN;}
"+"     {return ADD;}
"-"     {return SUB;}
"*"     {return MUL;}
"/"     {return DIV;}
"%"     {return MOD;}
"<"     {return LT;}
">"     {return GT;}
"<="    {return LE;}
">="    {return GE;}
"!="    {return NEQ;}
"=="    {return EQ;}
"&&"    {return AND;}
"||"    {return OR;}
"!"     {return NOT;}
{num10}	{yylval = new IntAST(atoi(yytext));return NUM;}
{num8}  {yylval = new IntAST(calc(yytext+1, 8));return NUM;}
{num16} {yylval = new IntAST(calc(yytext+2, 16));return NUM;}
{identifier}    {yylval = new IdAST(yytext);return ID;}
{whitespace}    {}
.       {return ERROR;}
%%

int calc(const char *str, int k){
	int res=0;
	for(int i=0;str[i]!='\0';i++){
		res*=k;
		char c=str[i];
		if('a'<=c && c<='z') res+=c-'a'+10;
		if('A'<=c && c<='Z') res+=c-'A'+10;
		if('0'<=c && c<='9') res+=c-'0';
	}
	return res;
}

int yywrap(void) {
	puts("End of the file");
	return 1;
}