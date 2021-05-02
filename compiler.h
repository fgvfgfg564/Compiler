#ifndef _COMPILER_H_
#define _COMPILER_H_


#include "globals.h"
#include "nested_trie.h"
#include "ir.h"
#include "sgset.h"
#include "ast.h"

class EeyoreGenerator
{
public:
	EeyoreGenerator(ostream &out): out_(out), symTable(), varInd(0),
		currentFunc(NULL), getReference(0), labelInd(0), maxTempVar(-1), isConst(0)
	{
		_init_lib_funcs();
	}

	ValPtr generateOn(CompUnitAST *ast);
	ValPtr generateOn(ConstDeclAST *ast);
	ValPtr generateOn(VarDeclAST *ast);
	ValPtr generateOn(ConstDefAST *ast);
	ValPtr generateOn(VarDefAST *ast);
	ValPtr generateOn(InitValAST *ast);
	ValPtr generateOn(ConstInitValAST *ast);
	ValPtr generateOn(FunctionAST *ast);
	ValPtr generateOn(FuncFParamAST *ast);
	ValPtr generateOn(BlockAST *ast);
	ValPtr generateOn(AssignStatAST *ast);
	ValPtr generateOn(IfStatAST *ast);
	ValPtr generateOn(WhileStatAST *ast);
	ValPtr generateOn(BreakAST *ast);
	ValPtr generateOn(ContinueAST *ast);
	ValPtr generateOn(ReturnAST *ast);
	ValPtr generateOn(BinaryExpAST *ast);
	ValPtr generateOn(UnaryExpAST *ast);
	ValPtr generateOn(FuncCallAST *ast);
	ValPtr generateOn(LValAST *ast);
	ValPtr generateOn(IdAST *ast);
	ValPtr generateOn(IntAST *ast);
	ValPtr generateOn(BTypeAST *ast);
	ValPtr generateOn(ASTList list);

	void compile(BaseAST *ast);

	void newEnvironment()
	{
		symTable.newEnvironment();
		arraySize.newEnvironment();
		constTable.newEnvironment();
	}
	void outer()
	{
		symTable.outer();
		arraySize.outer();
		constTable.outer();
	}
	void newDecl(ValPtr name, int len = 0)
	{
		if (currentFunc != NULL) currentFunc->newDecl(name, len);
		else prog.newDecl(name, len);
	}
	void newAssign(ValPtr name, ValPtr value)
	{
		if (currentFunc == NULL) {
			assert(value->type == EE_CONST);
			prog.newInit(name, value->val);
		} else
			currentFunc -> newInst(new Assign(name, value));
	}
	void newAssign(ValPtr name, ValPtr ind, ValPtr value)
	{
		if (currentFunc == NULL) {
			assert(value->type == EE_CONST && ind->type == EE_CONST);
			prog.newInit(name, ind->val, value->val);
		} else
			currentFunc -> newInst(new AssignArray(name, ind, value));
	}
	ValPtr newVar()
	{
		int newvar = tempVar.get();
		if (newvar > maxTempVar) maxTempVar = newvar;
		return new RightValue(newvar, EE_TEMP);
	}
	void recycleVar(ValPtr ptr)
	{
		if (ptr == NULL) return;
		if (ptr->type == EE_TEMP) tempVar.recover(ptr->val);
	}
	vector<int> readConstExpList(ASTList list)
	{
		vector<int> res;
		for (auto u : list) {
			if (u == NULL) {
				res.push_back(0);
				continue;
			}
			ValPtr ptr = u->generateIR((*this));
			assert(ptr != NULL && ptr->type == EE_CONST);
			res.push_back(ptr->val);
		}
		return res;
	}

	void _init_lib_funcs()
	{
		hasReturnValue.insert("getint", true);
		hasReturnValue.insert("getch", true);
		hasReturnValue.insert("getarray", true);
		hasReturnValue.insert("putint", false);
		hasReturnValue.insert("putch", false);
		hasReturnValue.insert("putarray", false);
		hasReturnValue.insert("_sysy_starttime", true);
		hasReturnValue.insert("_sysy_stoptime", true);
	}
private:
	ostream &out_;
	Program prog;

	// Variable and label informations
	NestedTrie<ValPtr> symTable;
	NestedTrie<vector<int> >arraySize;
	NestedTrie<int *> constTable;
	NestedTrie<bool> hasReturnValue;
	int paramInd, varInd, labelInd, maxTempVar;;
	SGSet tempVar;

	// useful parameters during compiling
	Function *currentFunc;
	ValPtr currentVar, arrayName, arrayInd;
	vector<int> temp, dimensions;
	int tempInt;
	bool getReference;
	vector<LabelPtr> labelLoop, labelEnd;
	bool isConst;
	string constVarName;
};

#endif