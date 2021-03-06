#include "globals.h"
#include "compiler.h"
#include "source.tab.hpp"

int NDto1D(vector<int> &dimensions, vector<int> &index)
{
	assert(dimensions.size() == index.size());
	if (dimensions.size() == 0) return -1;
	int res = 0, tmp = 1;
	vector<int>::reverse_iterator a = index.rbegin(), b = dimensions.rbegin();
	for (; a != index.rend(); a++, b++) {
		res += (*a) * tmp;
		tmp *= (*b);
	}
	return res;
}

void EeyoreGenerator::compile(BaseAST *ast)
{
	if (debug) ast->debug(0);
	ast->generateIR(*this);
	prog.print(out_);
}

ValPtr EeyoreGenerator::generateOn(CompUnitAST *ast)
{
	for (auto u : ast->nodeList()) u->generateIR(*this);
	return NULL;
}

ValPtr EeyoreGenerator::generateOn(ConstDeclAST *ast)
{
	for (auto u : ast->varList()) u->generateIR(*this);
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(VarDeclAST *ast)
{
	for (auto u : ast->varList()) u->generateIR(*this);
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(ConstDefAST *ast)
{
	if (ast->dimensions().size() == 0) {
		ValPtr ptr = ((ConstInitValAST *)ast->initValue())->value()->generateIR(*this);
		assert(ptr->type == EE_CONST);
		symTable.insert(ast->name(), ptr);
		return NULL;
	} else {
		int size = 1;
		for (auto u : ast->dimensions()) {
			ValPtr ptr = u->generateIR(*this);
			assert(ptr->type == EE_CONST);
			size *= ptr->val;
		}
		constTable.insert(ast->name(), (int *)malloc(size * sizeof(int)));
		isConst = true;
		constVarName = ast->name();
		generateOn((VarDefAST *) ast);
		isConst = false;
		return NULL;
	}
}
ValPtr EeyoreGenerator::generateOn(VarDefAST *ast)
{
	initDim = readConstExpList(ast->dimensions());
	ValPtr eeName = new RightValue(varInd++, EE_ORIGIN);
	symTable.insert(ast->name(), eeName);
	arraySize.insert(ast->name(), initDim);
	if (initDim.size() != 0) {
		int size = 4;
		for (auto u : initDim) size *= u;
		newDecl(eeName, size);
	} else newDecl(eeName);
	initCur.clear();
	currentVar = eeName;
	if (ast->initValue())ast->initValue()->generateIR(*this);
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(InitValAST *ast)
{
	int n = initDim.size(), m = initCur.size();
	if (ast->value() != NULL) {
		assert(n == m);
		ValPtr val = ast->value()->generateIR(*this);
		assert(initDim.size() == initCur.size());
		if (n != 0) {
			ValPtr ind = new RightValue(NDto1D(initDim, initCur));
			newAssign(currentVar, ind, val);
		} else
			newAssign(currentVar, val);
		recycleVar(val);
	} else {
		int l = ast->valList().size();
		int p = 0;
		int remain = 1;
		for (int i = m + 1; i < n; i++)remain *= initDim[i];
		for (int i = 0; i < initDim[m]; i++) {
			if (p >= l) return NULL;
			initCur.push_back(i);
			InitValAST *son = (InitValAST *)ast->valList()[p];
			if (son->value() == NULL) {
				son->generateIR(*this);
				p += 1;
			} else {
				for (int i = 1; i < n - m; i++)initCur.push_back(0);
				int startp = NDto1D(initDim, initCur);
				for (int i = 1; i < n - m; i++)initCur.pop_back();
				for (int j = p; j < p + remain && j < l; j++) {
					ValPtr val = ((InitValAST *)(ast->valList()[j]))->value()->generateIR(*this);
					int ind = startp + j - p;
					newAssign(currentVar, new RightValue(ind * 4), val);
					if (isConst) {
						assert(val->type == EE_CONST);
						constTable.getItem(constVarName)[ind] = val->val;
					}
					recycleVar(val);
				}
				p += remain;
			}
			initCur.pop_back();
		}
	}
	return NULL;
}

ValPtr EeyoreGenerator::generateOn(ConstInitValAST *ast)
{
	return generateOn((InitValAST *) ast);
}

ValPtr EeyoreGenerator::generateOn(FunctionAST *ast)
{
	global = false;
	if (ast->name() != "main")
		currentFunc = prog.newFunc(ast->name(), ast->fParams().size());
	else
		prog.funcs.push_back(mainFunc);
	assert(!hasReturnValue.find(ast->name()));
	hasReturnValue.insert(ast->name(), ast->funcType() == INT);
	newEnvironment();
	paramInd = 0;
	for (auto u : ast->fParams()) u->generateIR(*this);
	ast->block()->generateIR(*this);
	if (ast->funcType() == VOID)
		currentFunc->newInst(new Return());
	else
		currentFunc->newInst(new Return(0));
	outer();
	assert(tempVar.isClean());
	for (int i = 0; i <= maxTempVar; i++)
		currentFunc->newDecl(new RightValue(i, EE_TEMP));
	maxTempVar = 0;
	currentFunc = mainFunc;
	global = true;
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(FuncFParamAST *ast)
{
	symTable.insert(ast->name(), new RightValue(paramInd++, EE_PARAM));
	if (ast->dimensions().size() != 0)
		arraySize.insert(ast->name(), readConstExpList(ast->dimensions()));
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(BlockAST *ast)
{
	newEnvironment();
	for (auto u : ast->items()) {
		ValPtr ptr = u->generateIR(*this);
		recycleVar(ptr);
	}
	outer();
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(AssignStatAST *ast)
{
	getReference = true;
	ValPtr lvalptr = ast->lval()->generateIR(*this);
	getReference = false;
	ValPtr expptr = ast->exp()->generateIR(*this);
	if (lvalptr) {
		if (expptr->type != EE_TEMP || !currentFunc->changeLastAssign(expptr, lvalptr))
			currentFunc->newInst(new Assign(lvalptr, expptr));
	} else {
		currentFunc->newInst(new AssignArray (arrayName, arrayInd, expptr));
		recycleVar(arrayInd);
	}
	recycleVar(expptr);
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(IfStatAST *ast)
{
	ValPtr cond = ast->cond()->generateIR(*this);
	if (ast->elseStmt()) {
		LabelPtr labelElse = new Label(labelInd++), labelEnd = new Label(labelInd++);
		currentFunc->newInst(new IfGoto(cond, EE_EQ, new RightValue(0), labelElse));
		ast->thenStmt()->generateIR(*this);
		currentFunc->newInst(new Goto(labelEnd));
		currentFunc->newInst(labelElse);
		ast->elseStmt()->generateIR(*this);
		currentFunc->newInst(labelEnd);
	} else {
		LabelPtr labelEnd = new Label(labelInd++);
		currentFunc->newInst(new IfGoto(cond, EE_EQ, new RightValue(0), labelEnd));
		ast->thenStmt()->generateIR(*this);
		currentFunc->newInst(labelEnd);
	}
	recycleVar(cond);
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(WhileStatAST *ast)
{
	labelLoop.push_back(new Label(labelInd++));
	labelEnd.push_back(new Label(labelInd++));
	currentFunc->newInst(labelLoop.back());
	ValPtr cond = ast->cond()->generateIR(*this);
	currentFunc->newInst(new IfGoto(cond, EE_EQ, new RightValue(0),
									labelEnd.back()));
	recycleVar(cond);
	ast->items()->generateIR(*this);
	currentFunc->newInst(new Goto(labelLoop.back()));
	currentFunc->newInst(labelEnd.back());
	labelLoop.pop_back();
	labelEnd.pop_back();
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(BreakAST *ast)
{
	currentFunc->newInst(new Goto(labelEnd.back()));
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(ContinueAST *ast)
{
	currentFunc->newInst(new Goto(labelLoop.back()));
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(ReturnAST *ast)
{
	if (ast->value()) {
		ValPtr temp = ast->value()->generateIR(*this);
		recycleVar(temp);
		currentFunc->newInst(new Return(temp));
	} else
		currentFunc->newInst(new Return());
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(BinaryExpAST *ast)
{
	EE_Op op;
	switch (ast->op()) {
		case ADD: op = EE_ADD; break;
		case SUB: op = EE_SUB; break;
		case MUL: op = EE_MUL; break;
		case DIV: op = EE_DIV; break;
		case MOD: op = EE_MOD; break;
		case AND: op = EE_AND; break;
		case OR: op = EE_OR; break;
		case LE: op = EE_LE; break;
		case GE: op = EE_GE; break;
		case LT: op = EE_LT; break;
		case GT: op = EE_GT; break;
		case EQ: op = EE_EQ; break;
		case NEQ: op = EE_NEQ; break;
		default: assert(0);
	}
	if (op == EE_MOD) {
		ValPtr opr1 = ast->opr1()->generateIR(*this);
		ValPtr opr2 = ast->opr2()->generateIR(*this);
		recycleVar(opr1);
		recycleVar(opr2);
		if (opr1->type == EE_CONST && opr2->type == EE_CONST)
			return new RightValue(eval(op, opr1->val, opr2->val));
		else {
			ValPtr ptr = newVar();
			currentFunc->newInst(new BinaryAssign(ptr, opr1, EE_DIV, opr2));
			currentFunc->newInst(new BinaryAssign(ptr, ptr, EE_MUL, opr2));
			currentFunc->newInst(new BinaryAssign(ptr, opr1, EE_SUB, ptr));
			return ptr;
		}
	} else if (op == EE_AND) {
		ValPtr ptr = newVar();
		ValPtr opr1 = ast->opr1()->generateIR(*this);
		LabelPtr fix = new Label(labelInd++), end = new Label(labelInd++);
		currentFunc->newInst(new IfGoto(opr1, EE_EQ, new RightValue(0), fix));
		recycleVar(opr1);
		ValPtr opr2 = ast->opr2()->generateIR(*this);
		recycleVar(opr2);
		currentFunc->newInst(new Assign(ptr, opr2));
		currentFunc->newInst(new Goto(end));
		currentFunc->newInst(fix);
		currentFunc->newInst(new Assign(ptr, new RightValue(0)));
		currentFunc->newInst(end);
		return ptr;
	} else if (op == EE_OR) {
		ValPtr ptr = newVar();
		ValPtr opr1 = ast->opr1()->generateIR(*this);
		LabelPtr fix = new Label(labelInd++), end = new Label(labelInd++);
		currentFunc->newInst(new IfGoto(opr1, EE_NEQ, new RightValue(0), fix));
		recycleVar(opr1);
		ValPtr opr2 = ast->opr2()->generateIR(*this);
		recycleVar(opr2);
		currentFunc->newInst(new Assign(ptr, opr2));
		currentFunc->newInst(new Goto(end));
		currentFunc->newInst(fix);
		currentFunc->newInst(new Assign(ptr, new RightValue(1)));
		currentFunc->newInst(end);
		return ptr;
	} else {
		ValPtr opr1 = ast->opr1()->generateIR(*this);
		ValPtr opr2 = ast->opr2()->generateIR(*this);
		recycleVar(opr1);
		recycleVar(opr2);
		if (opr1->type == EE_CONST && opr2->type == EE_CONST)
			return new RightValue(eval(op, opr1->val, opr2->val));
		else {
			ValPtr ptr = newVar();
			currentFunc->newInst(new BinaryAssign(ptr, opr1, op, opr2));
			return ptr;
		}
	}
}
ValPtr EeyoreGenerator::generateOn(UnaryExpAST *ast)
{
	ValPtr opr = ast->opr()->generateIR(*this);
	EE_Op op;
	switch (ast->op()) {
		case POSITIVE: return opr;
		case NOT: op = EE_NOT; break;
		case NEGATIVE: op = EE_NEG; break;
	}
	if (opr->type == EE_CONST)
		return new RightValue(eval(op, opr->val));
	else {
		recycleVar(opr);
		ValPtr ptr = newVar();
		currentFunc->newInst(new UnaryAssign(ptr, op, opr));
		return ptr;
	}
}
ValPtr EeyoreGenerator::generateOn(FuncCallAST *ast)
{
	vector<ValPtr> params;
	for (auto u : ast->args()) {
		ValPtr param = u->generateIR(*this);
		params.push_back(param);
	}
	for (auto param : params)
		currentFunc->newInst(new Param(param));
	ValPtr ptr;
	if (hasReturnValue.getItem(ast->name())) {
		ptr = newVar();
		currentFunc->newInst(new FuncCallAssign(ptr, ast->name()));
	} else {
		currentFunc->newInst(new FuncCall(ast->name()));
		ptr = NULL;
	}
	for (auto param : params)
		recycleVar(param);
	return ptr;
}
ValPtr EeyoreGenerator::generateOn(LValAST *ast)
{
	assert(symTable.find(ast->name()));
	assert(!(getReference && constTable.find(ast->name())));
	ValPtr eeName = symTable.getItem(ast->name());
	if (ast->dimensions().size() == 0) return eeName;
	else {
		dimensions = arraySize.getItem(ast->name());
		bool temp = getReference;
		getReference = false;
		ValPtr ind = generateOn(ast->dimensions());
		getReference = temp;
		recycleVar(ind);
		ValPtr ptr;
		if (ind->type == EE_CONST) {
			if (constTable.find(ast->name()))
				return new RightValue(constTable.getItem(ast->name())[ind->val]);
			else ptr = new RightValue(ind->val * 4);
		} else {
			ptr = newVar();
			currentFunc->newInst(new BinaryAssign(ptr, ind, EE_MUL, new RightValue(4)));
		}
		if (!getReference) {
			recycleVar(ptr);
			ValPtr ptr2 = newVar();
			currentFunc->newInst(new ArrayAssign(ptr2, eeName, ptr));
			return ptr2;
		} else {
			arrayName = eeName;
			arrayInd = ptr;
			return NULL;
		}
	}
}
ValPtr EeyoreGenerator::generateOn(IdAST *ast)
{
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(IntAST *ast)
{
	return new RightValue(ast->value());
}
ValPtr EeyoreGenerator::generateOn(BTypeAST *ast)
{
	assert(0);
	return NULL;
}
ValPtr EeyoreGenerator::generateOn(ASTList list)
{
	assert(list.size() == dimensions.size());
	int n = list.size();
	ValPtr ptr;
	int wgt = 1;
	bool isConst = true;
	int result = 0;
	for (int i = n - 1; i >= 0; i--) {
		ValPtr curInd = list[i]->generateIR(*this);
		if (curInd->type == EE_CONST && isConst)
			result = result + wgt * curInd->val;
		else {
			ValPtr mul;
			if (wgt != 1) {
				mul = newVar();
				currentFunc->newInst(new BinaryAssign(mul, curInd, EE_MUL,
													  new RightValue(wgt)));
				recycleVar(curInd);
			} else mul = curInd;

			if (isConst) {
				isConst = false;
				if (result != 0) {
					recycleVar(mul);
					ptr = newVar();
					currentFunc->newInst(new BinaryAssign(ptr, mul, EE_ADD,
														  new RightValue(result)));
				} else ptr = mul;
			} else {
				recycleVar(mul);
				recycleVar(ptr);
				ValPtr temp = newVar();
				currentFunc->newInst(new BinaryAssign(temp, ptr, EE_ADD, mul));
				ptr = temp;
			}
		}
		wgt *= dimensions[i];
	}
	if (isConst) return new RightValue(result);
	else return ptr;
}