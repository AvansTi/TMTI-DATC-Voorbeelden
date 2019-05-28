#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "AST.h"


class Evaluator {
public:
	double Evaluate(ASTNode* ast);

private:
	double EvaluateSubtree(ASTNode* ast);
};


#endif