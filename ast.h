#ifndef _AST_H_
#define _AST_H_

#include "globals.h"
#include "util.h"
#include "ir.h"

class EeyoreGenerator;

class BaseAST
{
public:
	virtual ~BaseAST() = default;
	virtual void debug(int depth)
	{
		assert(0);
	};
	virtual ValPtr generateIR(EeyoreGenerator &gen)
	{
		assert(0);
	};
	virtual vector<BaseAST *> &nodeList()
	{
		assert(0);
	};
	virtual vector<BaseAST *> &varList()
	{
		assert(0);
	};
	virtual vector<BaseAST *> &dimensions()
	{
		assert(0);
	};
	virtual vector<BaseAST *> &valList()
	{
		assert(0);
	};
	virtual vector<BaseAST *> &astList()
	{
		assert(0);
	};
	virtual string &name()
	{
		assert(0);
	};
};

class IntAST: public BaseAST
{
public:
	IntAST(int value): value_(value) {}
	int &value()
	{
		return value_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<IntConst>\n");
		printTab(depth + 1);
		cout << "Value: " << value_ << '\n';
		printTab(depth);
		printf("</IntConst>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	int value_;
};

typedef BaseAST *ASTPtr;
typedef vector<ASTPtr> ASTList;

#define YYSTYPE ASTPtr

class CompUnitAST: public BaseAST
{
public:
	CompUnitAST(ASTList &nodes): nodeList_(nodes) {}
	ASTList &nodeList() override
	{
		return nodeList_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		printf("<CompUnit>\n");
		for (ASTList::iterator it = nodeList_.begin(); it != nodeList_.end(); it++)
			(*it)->debug(depth + 1);
		printTab(depth);
		printf("</CompUnit>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTList nodeList_;
};

class ConstDeclAST: public BaseAST
{
public:
	ConstDeclAST(TokenType bType, ASTList &varList): bType_(bType),
		varList_(varList) {}
	ASTList &varList() override
	{
		return varList_;
	}
	TokenType &bType()
	{
		return bType_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		printf("<ConstDecl Type=%d>\n", bType_);
		for (auto u : varList_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</ConstDecl>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTList varList_;
	TokenType bType_;
};

class VarDeclAST: public BaseAST
{
public:
	VarDeclAST(TokenType bType, ASTList &varList): bType_(bType),
		varList_(varList) {}
	ASTList &varList() override
	{
		return varList_;
	}
	TokenType &bType()
	{
		return bType_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		printf("<VarDecl Type=%d>\n", bType_);
		for (auto u : varList_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</VarDecl>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTList varList_;
	TokenType bType_;
};

class ConstDefAST: public BaseAST
{
public:
	ConstDefAST(string &name, ASTList &dimensions, ASTPtr &initValue):
		name_(name), dimensions_(dimensions), initValue_(initValue) {}
	string &name() override
	{
		return name_;
	}
	ASTList &dimensions() override
	{
		return dimensions_;
	}
	ASTPtr &initValue()
	{
		return initValue_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		cout << "<ConstDef name=" << name_ << ">\n";
		printTab(depth + 1); printf("dimensions:\n");
		for (auto u : dimensions_)
			u->debug(depth + 1);
		puts("");
		if (initValue_ != NULL)
			initValue_->debug(depth + 1);
		printTab(depth);
		printf("</ConstDef>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	string name_;
	ASTList dimensions_;
	ASTPtr initValue_;
};

class VarDefAST: public BaseAST
{
public:
	VarDefAST(string &name, ASTList &dimensions, ASTPtr initValue):
		name_(name), dimensions_(dimensions), initValue_(initValue) {}
	string &name() override
	{
		return name_;
	}
	ASTList &dimensions() override
	{
		return dimensions_;
	}
	ASTPtr &initValue()
	{
		return initValue_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		cout << "<VarDef name=" << name_ << ">\n";
		printTab(depth + 1); printf("dimensions:\n");
		for (auto u : dimensions_)
			u->debug(depth + 1);
		puts("");
		if (initValue_ != NULL)
			initValue_->debug(depth + 1);
		printTab(depth);
		printf("</VarDef>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	string name_;
	ASTList dimensions_;
	ASTPtr initValue_;
};

class InitValAST: public BaseAST
{
public:
	InitValAST(ASTPtr value, ASTList &list): value_(value), valList_(list) {}
	ASTPtr &value()
	{
		return value_;
	}
	ASTList &valList() override
	{
		return valList_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		printf("<InitVal>\n");
		if (value_ != NULL) {
			printTab(depth + 1);
			printf("value:\n");
			value_->debug(depth + 1);
		}
		printTab(depth + 1);
		printf("valueList:\n");
		for (auto u : valList_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</InitVal>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTPtr value_;
	ASTList valList_;
};

class ConstInitValAST: public BaseAST
{
public:
	ConstInitValAST(ASTPtr value, ASTList &list): value_(value), valList_(list) {}
	ASTPtr &value()
	{
		return value_;
	}
	ASTList &valList() override
	{
		return valList_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		printf("<ConstInitVal>\n");
		if (value_ != NULL) {
			printTab(depth + 1);
			printf("value:\n");
			value_->debug(depth + 1);
		}
		printTab(depth + 1);
		printf("valueList:\n");
		for (auto u : valList_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</ConstInitVal>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTPtr value_;
	ASTList valList_;
};

class FunctionAST: public BaseAST
{
public:
	FunctionAST(TokenType funcType, string &name,
				ASTList &fParams, ASTPtr &block): funcType_(funcType),
		name_(name), fParams_(fParams), block_(block) {}
	TokenType &funcType()
	{
		return funcType_;
	}
	string &name() override
	{
		return name_;
	}
	ASTList &fParams()
	{
		return fParams_;
	}
	ASTPtr &block()
	{
		return block_;
	}
	void debug(int depth) override
	{
		printTab(depth);
		printf("<Function>\n");
		printTab(depth + 1);
		printf("Type: %d\n", funcType_);
		printTab(depth + 1);
		cout << "Name: " << name_ << '\n';
		printTab(depth + 1);
		printf("FParams:\n");
		for (auto u : fParams_)
			u->debug(depth + 1);
		printTab(depth + 1);
		printf("Body:\n");
		block_->debug(depth + 1);
		printTab(depth);
		printf("</Function>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	TokenType funcType_;
	string name_;
	ASTPtr block_;
	ASTList fParams_;
};

class FuncFParamAST: public BaseAST
{
public:
	FuncFParamAST(TokenType bType, string &name, ASTList &dimensions):
		bType_(bType), name_(name), dimensions_(dimensions) {}
	TokenType &bType()
	{
		return bType_;
	}
	string &name() override
	{
		return name_;
	}
	ASTList &dimensions() override
	{
		return dimensions_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<FuncFParam>\n");
		printTab(depth + 1);
		printf("Type: %d\n", bType_);
		printTab(depth + 1);
		cout << "Name: " << name_ << '\n';
		if (dimensions_.size() >= 1) {
			printTab(depth + 1);
			printf("Dimensions:\n");
			printTab(depth + 1);
			printf("NULL\n");
			for (auto u : dimensions_)
				if (u != NULL)u->debug(depth + 1);
		}
		printTab(depth);
		printf("</FuncFParam>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	TokenType bType_;
	string name_;
	ASTList dimensions_;
};

class BlockAST: public BaseAST
{
public:
	BlockAST(ASTList &items): items_(items) {}
	ASTList &items()
	{
		return items_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<Block>\n");
		for (auto u : items_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</Block>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTList items_;
};

class AssignStatAST: public BaseAST
{
public:
	AssignStatAST(ASTPtr &lval, ASTPtr &exp): lval_(lval), exp_(exp) {}
	ASTPtr &lval()
	{
		return lval_;
	}
	ASTPtr &exp()
	{
		return exp_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<Assign>\n");
		printTab(depth + 1);
		printf("Lval:\n");
		lval_->debug(depth + 1);
		printTab(depth + 1);
		printf("Exp:\n");
		exp_->debug(depth + 1);
		printTab(depth);
		printf("</Assign>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTPtr lval_;
	ASTPtr exp_;
};

class IfStatAST: public BaseAST
{
public:
	IfStatAST(ASTPtr cond, ASTPtr thenStmt, ASTPtr elseStmt):
		cond_(cond), thenStmt_(thenStmt), elseStmt_(elseStmt) {}
	ASTPtr &cond()
	{
		return cond_;
	}
	ASTPtr &thenStmt()
	{
		return thenStmt_;
	}
	ASTPtr &elseStmt()
	{
		return elseStmt_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<If>\n");
		printTab(depth + 1);
		printf("Cond:\n");
		cond_->debug(depth + 1);
		printTab(depth + 1);
		printf("Then:\n");
		thenStmt_->debug(depth + 1);
		if(elseStmt_){
			printTab(depth + 1);
			printf("Else:\n");
			elseStmt_->debug(depth + 1);
		}
		printTab(depth);
		printf("</If>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTPtr cond_;
	ASTPtr thenStmt_, elseStmt_;
};

class WhileStatAST: public BaseAST
{
public:
	WhileStatAST(ASTPtr cond, ASTPtr items):
		cond_(cond), items_(items) {}
	ASTPtr &cond()
	{
		return cond_;
	}
	ASTPtr &items()
	{
		return items_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<While>\n");
		printTab(depth + 1);
		printf("Cond:\n");
		cond_->debug(depth + 1);
		printTab(depth + 1);
		printf("Content:\n");
		items_->debug(depth + 1);
		printTab(depth);
		printf("</While>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTPtr cond_, items_;
};

class BreakAST: public BaseAST
{
public:
	BreakAST() {}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<Break>\n");
		printTab(depth);
		printf("</Break>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
};

class ContinueAST: public BaseAST
{
public:
	ContinueAST() {}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<Continue>\n");
		printTab(depth);
		printf("</Continue>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
};

class ReturnAST: public BaseAST
{
public:
	ReturnAST(ASTPtr value): value_(value) {}
	ASTPtr &value ()
	{
		return value_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<Return>\n");
		if (value_ != NULL) {
			printTab(depth + 1);
			printf("Value:\n");
			value_->debug(depth + 1);
		}
		printTab(depth);
		printf("</Return>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	ASTPtr value_;
};

class BinaryExpAST: public BaseAST
{
public:
	BinaryExpAST(TokenType op, ASTPtr &opr1, ASTPtr &opr2):
		op_(op), opr1_(opr1), opr2_(opr2) {}
	TokenType &op()
	{
		return op_;
	}
	ASTPtr &opr1()
	{
		return opr1_;
	}
	ASTPtr &opr2()
	{
		return opr2_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<BinaryOp op=%d>\n", op_);
		printTab(depth + 1);
		printf("opr1:\n");
		opr1_->debug(depth + 1);
		printTab(depth + 1);
		printf("opr2:\n");
		opr2_->debug(depth + 1);
		printTab(depth);
		printf("</BinaryOp>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	TokenType op_;
	ASTPtr opr1_, opr2_;
};

class UnaryExpAST: public BaseAST
{
public:
	UnaryExpAST(TokenType op, ASTPtr &opr):
		op_(op), opr_(opr) {}
	TokenType &op()
	{
		return op_;
	}
	ASTPtr &opr()
	{
		return opr_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<BinaryOp op=%d>\n", op_);
		printTab(depth + 1);
		printf("opr:\n");
		opr_->debug(depth + 1);
		printTab(depth);
		printf("</BinaryOp>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	TokenType op_;
	ASTPtr opr_;
};

class FuncCallAST: public BaseAST
{
public:
	FuncCallAST(string &name, ASTList &args):
		name_(name), args_(args) {
			if(name_ == "starttime") {
				name_ = "_sysy_starttime";
				args_.push_back(new IntAST(0));
			}
			if(name_ == "stoptime") {
				name_ = "_sysy_stoptime";
				args_.push_back(new IntAST(0));
			}
		}
	string &name() override
	{
		return name_;
	}
	ASTList &args()
	{
		return args_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<FuncCall>\n");
		printTab(depth + 1);
		cout << "Name: " << name_ << '\n';
		printTab(depth + 1);
		printf("Args:\n");
		for (auto u : args_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</FuncCall>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	string name_;
	ASTList args_;
};

class LValAST: public BaseAST
{
public:
	LValAST(string &name, ASTList &dimensions): name_(name),
		dimensions_(dimensions) {}
	string &name() override
	{
		return name_;
	}
	ASTList &dimensions() override
	{
		return dimensions_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<LVal>\n");
		printTab(depth + 1);
		cout << "Name: " << name_ << '\n';
		printTab(depth + 1);
		printf("dimensions_:\n");
		for (auto u : dimensions_)
			u->debug(depth + 1);
		printTab(depth);
		printf("</LVal>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	string name_;
	ASTList dimensions_;
};

class IdAST: public BaseAST
{
public:
	IdAST(string &name): name_(name) {}
	IdAST(char *name): name_(name) {}
	string &name() override
	{
		return name_;
	}
	void debug (int depth) override
	{
		printTab(depth);
		printf("<Id>\n");
		printTab(depth + 1);
		cout << "Name: " << name_ << '\n';
		printTab(depth);
		printf("</Id>\n");
	}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	string name_;
};

class BTypeAST: public BaseAST
{
public:
	BTypeAST(TokenType bType): bType_(bType) {}
	TokenType &bType()
	{
		return bType_;
	}
	void debug(int depth) override {}
	ValPtr generateIR(EeyoreGenerator &gen) override;
private:
	TokenType bType_;
};

class ASTListAST: public BaseAST
{
public:
	ASTListAST(ASTList &astList): astList_(astList) {}
	ASTListAST() {}
	ASTList &astList() override
	{
		return astList_;
	}
	void debug(int depth) override {}
private:
	ASTList astList_;
};

class DoNothingAST: public BaseAST
{
public:
	DoNothingAST() {}
	void debug(int depth) override {}
	ValPtr generateIR(EeyoreGenerator &gen) override
	{
		return NULL;
	}
};

#endif