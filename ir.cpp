#include "globals.h"
#include "util.h"
#include "ir.h"

int indent = 0;

int eval( EE_Op op, int opr1, int opr2)
{
	switch (op) {
		case EE_ADD: return  opr1 + opr2;
		case EE_SUB: return  opr1 - opr2;
		case EE_MUL: return  opr1 * opr2;
		case EE_DIV: return  opr1 / opr2;
		case EE_MOD: return  opr1 % opr2;
		case EE_NEG: return -opr1;
		case EE_AND: return  opr1 && opr2;
		case EE_OR: return  opr1 || opr2;
		case EE_NOT: return  !opr1;
		case EE_LE: return  opr1 <= opr2;
		case EE_GE: return  opr1 >= opr2;
		case EE_LT: return  opr1 < opr2;
		case EE_GT: return  opr1 > opr2;
		case EE_EQ: return  opr1 == opr2;
		case EE_NEQ: return  opr1 != opr2;
	}
}