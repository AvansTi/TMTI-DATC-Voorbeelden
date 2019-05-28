#include "Evaluator.h"
#include "Exceptions.h"

double Evaluator::EvaluateSubtree(ASTNode* ast) {
	if (ast == nullptr)
		throw EvaluatorException("Incorrect syntax tree!");

	if (ast->Type == ASTNodeType::NumberValue)
		return ast->Value;
	if (ast->Type == ASTNodeType::UnaryMinus)
		return -EvaluateSubtree(ast->Left);
	else
	{
		double v1 = EvaluateSubtree(ast->Left);
		double v2 = EvaluateSubtree(ast->Right);
		//if (ast->Type == ASTNodeType::Operator) {

			//ASTOperatorNode* astOperator = static_cast<ASTOperatorNode*>(ast);

			switch (ast->Type) {
				case ASTNodeType::OperatorPlus:
					return v1 + v2;
				case ASTNodeType::OperatorMinus:
					return v1 - v2;
				case ASTNodeType::OperatorMul:
					return v1 * v2;
				case ASTNodeType::OperatorDiv:
					return v1 / v2;
				default:
					break;
			}
		//}
	}

	throw EvaluatorException("Incorrect syntax tree!");
}


double Evaluator::Evaluate(ASTNode* ast)
{
	if (ast == nullptr)
		throw EvaluatorException("Incorrect abstract syntax tree");

	return EvaluateSubtree(ast);
}