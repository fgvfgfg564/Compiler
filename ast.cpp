#include "ast.h"
#include "compiler.h"

ValPtr CompUnitAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr ConstDeclAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr VarDeclAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr ConstDefAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr VarDefAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr InitValAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr ConstInitValAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr FunctionAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr FuncFParamAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr BlockAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr AssignStatAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr IfStatAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr WhileStatAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr BreakAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr ContinueAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr ReturnAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr BinaryExpAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr UnaryExpAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr FuncCallAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr LValAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr IdAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr IntAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}
ValPtr BTypeAST::generateIR(EeyoreGenerator &gen) {return gen.generateOn(this);}