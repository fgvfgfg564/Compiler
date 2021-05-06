%{
#include "globals.h"
#include "util.h"
#include "ast.h"

static BaseAST *savedTree;
%}

%token CONST INT VOID IF WHILE ELSE CONTINUE BREAK RETURN
%token COMMA SEMICOLON LSQUARE RSQUARE LPAREN RPAREN ASSIGN LBRACE RBRACE
%token ADD SUB MUL DIV MOD
%token LT GT LE GE EQ NEQ
%token AND OR NOT
%token NUM ID ERROR
%token POSITIVE NEGATIVE

%%

Program 		: CompUnit {savedTree = $1;}
				;

CompUnit		: Decl {ASTList t={$1};$$=new CompUnitAST(t);}
				| FuncDef {ASTList t={$1};$$=new CompUnitAST(t);}
				| CompUnit Decl 
					{
						YYSTYPE t=$1;
						t->nodeList().push_back($2);
						$$=t;
					}
				| CompUnit FuncDef					
					{
						YYSTYPE t=$1;
						t->nodeList().push_back($2);
						$$=t;
					}
				| Error {}
				;
Decl			: ConstDecl {$$=$1;}
				| VarDecl {$$=$1;}
				;
ConstDecl		: CONST INT ConstDeclList SEMICOLON
					{
						$$=new ConstDeclAST(INT, $3->astList());
					}
				;
ConstDeclList	: ConstDef 
					{
						ASTList t={$1};
						$$=new ASTListAST(t);
					}
				| ConstDeclList COMMA ConstDef
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				;
ConstDef		: ID ConstDimensions ASSIGN ConstInitVal
					{
						$$=new ConstDefAST($1->name(), $2->astList(), $4);
					}
				;
ConstDimensions : ConstDimensions LSQUARE ConstExp RSQUARE 
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				| /* epsilon */ {$$=new ASTListAST();}
				;
ConstInitVal	: ConstExp 
					{
						ASTList t;
						$$ = new ConstInitValAST($1, t);
					}
				| LBRACE ConstInitValList RBRACE {$$ = new ConstInitValAST(NULL, $2->astList());}
				| LBRACE RBRACE
					{
						ASTList t;
						$$ = new ConstInitValAST(NULL, t);
					}
				;
ConstInitValList: ConstInitVal 
					{
						$$ = new ASTListAST();
						$$->astList().push_back($1);
					}
				| ConstInitValList COMMA ConstInitVal
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				;
VarDecl 		: INT VarDeclList SEMICOLON {$$ = new VarDeclAST(INT, $2->astList());}
				;
VarDeclList 	: VarDef	
					{
						ASTList t = {$1};
						$$ = new ASTListAST(t);
					}
				| VarDeclList COMMA VarDef
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				;
VarDef 			: ID ConstDimensions ASSIGN InitVal {$$ = new VarDefAST($1->name(), $2->astList(), $4);}
				| ID ConstDimensions	{$$ = new VarDefAST($1->name(), $2->astList(), NULL);}
				;
InitVal 		: Exp 
					{
						ASTList t;
						$$ = new InitValAST($1, t);
					}
				| LBRACE InitValList RBRACE {$$ = new InitValAST(NULL, $2->astList());}
				| LBRACE RBRACE
					{
						ASTList t;
						$$ = new InitValAST(NULL, t);
					}
				;
InitValList 	: InitVal 
					{
						$$ = new ASTListAST();
						$$->astList().push_back($1);
					}
				| InitValList COMMA InitVal
					{
						$$ = $1; 
						$$->astList().push_back($3);
					}
				;

FuncDef			: VOID ID LPAREN FuncFParams RPAREN Block
					{
						$$ = new FunctionAST(VOID, $2->name(), 
							$4->astList(), $6);
					}
				| VOID ID LPAREN RPAREN Block
					{
						ASTList t;
						$$ = new FunctionAST(VOID, $2->name(), 
							t, $5);
					}
				| INT ID LPAREN FuncFParams RPAREN Block
					{
						$$ = new FunctionAST(INT, $2->name(), 
							$4->astList(), $6);
					}
				| INT ID LPAREN RPAREN Block
					{
						ASTList t;
						$$ = new FunctionAST(INT, $2->name(), 
							t, $5);
					}
				;
FuncFParams 	: FuncFParam 
					{
						ASTList t = {$1};
						$$ = new ASTListAST(t);
					}
				| FuncFParams COMMA FuncFParam
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				;
FuncFParam  	: INT ID 
					{
						ASTList t = {NULL};
						$$ = new FuncFParamAST(INT, $2->name(), t);
					}
				| INT ID LSQUARE RSQUARE ConstDimensions {
					ASTList t = {NULL};
					$$ = new FuncFParamAST(INT, $2->name(), t);
					for(auto &each: $5->astList()) {
						$$->dimensions().push_back(each);
					}
				}
				;

Block 			: LBRACE BlockItemList RBRACE {$$=new BlockAST($2->astList());}
				;
BlockItemList 	: /* epsilon */ {$$=new ASTListAST();}
				| BlockItemList BlockItem 
					{
						$$ = $1;
						$$->astList().push_back($2);
					}
				;
BlockItem 		: Decl {$$=$1;}
				| FreeStmt {$$=$1;}
				;
FreeStmt 		: NonIfStmt {$$=$1;}
 				| FreeIfStmt {$$=$1;}
 				| FreeWhileStmt {$$=$1;}
 				;
BoundedStmt 	: NonIfStmt {$$=$1;}
				| BoundedIfStmt {$$=$1;}
				| BoundedWhileStmt {$$=$1;}
				;
FreeIfStmt		: IF LPAREN Cond RPAREN FreeStmt {$$ = new IfStatAST($3, $5, NULL);}
				| IF LPAREN Cond RPAREN BoundedStmt ELSE FreeStmt {$$ = new IfStatAST($3, $5, $7);}
				;
BoundedIfStmt   : IF LPAREN Cond RPAREN BoundedStmt ELSE BoundedStmt {$$ = new IfStatAST($3, $5, $7);}
				;
FreeWhileStmt 	: WHILE	LPAREN Cond RPAREN FreeStmt {$$ = new WhileStatAST($3, $5);}
				;
BoundedWhileStmt: WHILE	LPAREN Cond RPAREN BoundedStmt {$$ = new WhileStatAST($3, $5);}
				;
NonIfStmt 		: LVal ASSIGN Exp SEMICOLON {$$=new AssignStatAST($1, $3);}
				| SEMICOLON	{$$ = new DoNothingAST();}
				| Exp SEMICOLON {$$ = $1;}
				| Block {$$=$1;}
				| BREAK SEMICOLON {$$ = new BreakAST();}
				| CONTINUE SEMICOLON {$$ = new ContinueAST();}
				| RETURN SEMICOLON	{$$ = new ReturnAST(NULL);}
				| RETURN Exp SEMICOLON {$$ = new ReturnAST($2);}
				;

Exp 			: Cond {$$ = $1;}
				;
Cond 			: LOrExp {$$ = $1;}
				;
LVal 			: ID Dimensions {$$ = new LValAST($1->name(), $2->astList());}
				;
Dimensions 		: /* epsilon */ {$$ = new ASTListAST();}
				| Dimensions LSQUARE Exp RSQUARE 
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				;
PrimaryExp 		: LPAREN Exp RPAREN {$$ = $2;}
				| LVal {$$ = $1;}
				| NUM {$$ = $1;}
				;
UnaryExp 		: PrimaryExp {$$=$1;}
				| ID LPAREN FuncRParams RPAREN {$$ = new FuncCallAST($1->name(), $3->astList());}
				| ID LPAREN RPAREN
					{
						ASTList t;
						$$ = new FuncCallAST($1->name(), t);
					}
				| ADD UnaryExp {$$ = new UnaryExpAST(POSITIVE, $2);}
				| SUB UnaryExp {$$ = new UnaryExpAST(NEGATIVE, $2);}
				| NOT UnaryExp {$$ = new UnaryExpAST(NOT, $2);}
				;
FuncRParams 	: Exp
					{
						ASTList t = {$1};
						$$ = new ASTListAST(t);
					}
				| FuncRParams COMMA Exp
					{
						$$ = $1;
						$$->astList().push_back($3);
					}
				;
MulExp 			: UnaryExp {$$=$1;}
				| MulExp MUL UnaryExp {$$ = new BinaryExpAST(MUL, $1, $3);}
				| MulExp DIV UnaryExp {$$ = new BinaryExpAST(DIV, $1, $3);}
				| MulExp MOD UnaryExp {$$ = new BinaryExpAST(MOD, $1, $3);}
				;
AddExp			: MulExp {$$=$1;}
				| AddExp ADD MulExp {$$ = new BinaryExpAST(ADD, $1, $3);}
				| AddExp SUB MulExp {$$ = new BinaryExpAST(SUB, $1, $3);}
				;
RelExp 			: AddExp {$$=$1;}
				| RelExp GT AddExp {$$ = new BinaryExpAST(GT, $1, $3);}
				| RelExp LT AddExp {$$ = new BinaryExpAST(LT, $1, $3);}
				| RelExp GE AddExp {$$ = new BinaryExpAST(GE, $1, $3);}
				| RelExp LE AddExp {$$ = new BinaryExpAST(LE, $1, $3);}
				;
EqExp 			: RelExp {$$=$1;}
				| EqExp EQ RelExp {$$ = new BinaryExpAST(EQ, $1, $3);}
				| EqExp NEQ RelExp {$$ = new BinaryExpAST(NEQ, $1, $3);}
				;
LAndExp 		: EqExp {$$=$1;}
				| LAndExp AND EqExp {$$ = new BinaryExpAST(AND, $1, $3);}
				;
LOrExp 			: LAndExp {$$=$1;}
				| LOrExp OR LAndExp {$$ = new BinaryExpAST(OR, $1, $3);}
				;
ConstExp 		: Cond {$$=$1;}
				;
Error 			: ERROR {yyerror("Unexpected Token!");}
				;

%%

ASTPtr parse()
{
	yyparse();
	return savedTree;
}

void yyerror(const char *s)
{  
    cerr<<s<<endl;
}  