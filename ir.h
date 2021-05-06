#ifndef _IR_H_
#define _IR_H_

#include "globals.h"
#include "util.h"

enum EE_Op {
	EE_ADD, EE_SUB, EE_MUL, EE_DIV, EE_MOD, EE_NEG,
	EE_AND, EE_OR, EE_NOT,
	EE_LE, EE_GE, EE_LT, EE_GT, EE_EQ, EE_NEQ
};

const string op2str[] = {"+", "-", "*", "/", "\%", "-", "&&", "||", "!", "<=", ">=", "<", ">", "==", "!="};
#define toStr(x) op2str[(int)(x)]

int eval( EE_Op op, int opr1, int opr2 = 0);

extern int indent;

class BaseIR
{
public:
	virtual ~BaseIR() = default;
	virtual void print(ostream &out) const {}
	friend ostream &operator<<(ostream &out, BaseIR *ir)
	{
		if (ir == NULL) out << 0;
		else ir->print(out);
		return out;
	}
	virtual bool changeLeft(void *oldptr, void *newptr)
	{
		return false;
	}
};

typedef BaseIR *IRPtr;
typedef vector<IRPtr> IRPtrList;

enum ValType {
	EE_CONST, EE_PARAM, EE_ORIGIN, EE_TEMP
};

class RightValue: public BaseIR
{
public:
	int val;
	ValType type;
	RightValue(int val_, ValType type_): val(val_), type(type_) {}
	RightValue(int val_): val(val_), type(EE_CONST) {}
	void print(ostream &out) const override
	{
		switch (type) {
			case EE_CONST: out << val; break;
			case EE_PARAM: out << "p" << val; break;
			case EE_ORIGIN: out << "T" << val; break;
			case EE_TEMP: out << "t" << val; break;
		}
	}
};

typedef RightValue *ValPtr;

class Id: public BaseIR
{
public:
	ValPtr name;
	uint len;
	Id(ValPtr name_, int len_ = 0): name(name_), len(len_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << "var" << ' ';
		if (len > 0) out << len << ' ';
		out << name << "\n";
	}
};

class Init: public BaseIR
{
public:
	ValPtr name;
	int ind;
	int num;
	Init(ValPtr name_, int num_): name(name_), num(num_), ind(-1) {}
	Init(ValPtr name_, int ind_, int num_): name(name_), num(num_), ind(ind_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		assert(ind >= -1);
		if (ind != -1) out << name << "[" << ind << "] = " << num << '\n';
		else out << name << " = " << num << '\n';
	}
};

class Label: public BaseIR
{
public:
	string name;
	Label(int ind): name("l" + to_string(ind)) {}
	Label(string name_): name(name_)
	{
		assert(name[0] == 'l');
	}
	void print(ostream &out) const override
	{
		out << name << ":\n";
	}
	void use(ostream &out)
	{
		out << name;
	}
};

typedef Label *LabelPtr;

class BinaryAssign: public BaseIR
{
public:
	ValPtr name;
	EE_Op op;
	ValPtr opr1, opr2;
	BinaryAssign(ValPtr name_, ValPtr opr1_, EE_Op op_,
				 ValPtr opr2_): name(name_),
		op(op_), opr1(opr1_), opr2(opr2_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << name << " = ";
		opr1->print(out);
		out << ' ' << toStr(op) << ' ';
		opr2->print(out);
		out << '\n';
	}
	bool changeLeft(void *oldptr, void *newptr) override
	{
		if (oldptr != name) return false;
		name = (ValPtr)newptr;
		return true;
	}
};

class UnaryAssign: public BaseIR
{
public:
	ValPtr name;
	EE_Op op;
	ValPtr opr;
	UnaryAssign(ValPtr name_, EE_Op op_, ValPtr opr_): name(name_),
		op(op_), opr(opr_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << name << " = ";
		out << ' ' << toStr(op) << ' ';
		opr->print(out);
		out << '\n';
	}
	bool changeLeft(void *oldptr, void *newptr) override
	{
		if (oldptr != name) return false;
		name = (ValPtr)newptr;
		return true;
	}
};

class Assign: public BaseIR
{
public:
	ValPtr name;
	ValPtr opr;
	Assign(ValPtr name_, ValPtr opr_): name(name_),
		opr(opr_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << name << " = ";
		opr->print(out);
		out << '\n';
	}
	bool changeLeft(void *oldptr, void *newptr) override
	{
		if (oldptr != name) return false;
		name = (ValPtr)newptr;
		return true;
	}
};

class AssignArray: public BaseIR
{
public:
	ValPtr name;
	ValPtr ind;
	ValPtr opr;
	AssignArray(ValPtr name_, ValPtr ind_, ValPtr opr_): name(name_),
		ind(ind_), opr(opr_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << name << "[";
		ind->print(out);
		out << "] = ";
		opr->print(out);
		out << '\n';
	}
};

class ArrayAssign: public BaseIR
{
public:
	ValPtr name;
	ValPtr opr;
	ValPtr ind;
	ArrayAssign(ValPtr name_, ValPtr opr_, ValPtr ind_): name(name_),
		ind(ind_), opr(opr_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << name << " = " << opr << "[";
		ind->print(out);
		out << "]\n";
	}
	bool changeLeft(void *oldptr, void *newptr) override
	{
		if (oldptr != name) return false;
		name = (ValPtr)newptr;
		return true;
	}
};

class IfGoto: public BaseIR
{
public:
	ValPtr opr1, opr2;
	EE_Op op;
	LabelPtr label;
	IfGoto(ValPtr opr1_, EE_Op op_, ValPtr opr2_, LabelPtr label_):
		opr1(opr1_), opr2(opr2_), op(op_),
		label(label_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << "if " << opr1 << ' ' << toStr(op) << ' ' << opr2 << " goto ";
		label->use(out);
		out << '\n';
	}
};

class Goto: public BaseIR
{
public:
	LabelPtr label;
	Goto(LabelPtr label_): label(label_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << "goto ";
		label->use(out);
		out << '\n';
	}
};

class Param: public BaseIR
{
public:
	ValPtr val;
	Param(ValPtr val_): val(val_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << "param " << val << '\n';
	}
};

class FuncCall: public BaseIR
{
public:
	string funcName;
	FuncCall(string funcName_): funcName(funcName_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << "call f_" << funcName << '\n';
	}
};

class FuncCallAssign: public BaseIR
{
public:
	ValPtr name;
	string funcName;
	FuncCallAssign(ValPtr name_, string funcName_): name(name_),
		funcName(funcName_) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		out << name << " = call f_" << funcName << '\n';
	}
	bool changeLeft(void *oldptr, void *newptr) override
	{
		if (oldptr != name) return false;
		name = (ValPtr)newptr;
		return true;
	}
};

class Return: public BaseIR
{
public:
	ValPtr val;
	Return(ValPtr val_): val(val_) {}
	Return(int val_): val(new RightValue(val_)) {}
	Return(): val(NULL) {}
	void print(ostream &out) const override
	{
		printTab(indent, out);
		if (!val) out << "return\n";
		else out << "return " << val << '\n';
	}
};

class Function: public BaseIR
{
public:
	string name;
	int nFParam;
	IRPtrList decls;
	IRPtrList insts;
	Function(string name_, int nFParam_): name(name_), nFParam(nFParam_) {}
	void newDecl(ValPtr val, uint len = 0)
	{
		Id *p = new Id(val, len);
		decls.push_back(p);
	}
	void newInst(IRPtr p)
	{
		insts.push_back(p);
	}
	bool changeLastAssign(ValPtr oldptr, ValPtr newptr)
	{
		return insts.back()->changeLeft(oldptr, newptr);
	}
	void print(ostream &out) const override
	{
		out << "f_" << name << " [" << nFParam << "]\n";
		indent ++;
		for (auto u : decls) u->print(out);
		for (auto u : insts) u->print(out);
		indent --;
		out << "end f_" << name << '\n';
	}
};

class Program: public BaseIR
{
public:
	IRPtrList decls, inits, funcs;
	Program () {}
	void newDecl(ValPtr name, uint len = 0)
	{
		Id *p = new Id(name, len);
		decls.push_back(p);
	}
	void newInit(ValPtr name, int num)
	{
		Init *p = new Init(name, num);
		inits.push_back(p);
	}
	void newInit(ValPtr name, int ind, int num)
	{
		Init *p = new Init(name, ind, num);
		inits.push_back(p);
	}
	Function *newFunc(string name, int nFParam)
	{
		Function *p = new Function(name, nFParam);
		funcs.push_back(p);
		return p;
	}
	void print(ostream &out) const override
	{
		for (auto u : decls) out << u;
		for (auto u : inits) out << u;
		for (auto u : funcs) out << u;
	}
};

#endif