#ifndef AST_H
#define AST_H

enum class ASTNodeType {
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	UnaryMinus,
	NumberValue
};
/*
enum class ASTOperatorType {
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv
};*/

class ASTNode
{
public:
	ASTNodeType Type;
	double      Value;
	ASTNode*    Left;
	ASTNode*    Right;

	ASTNode() {
		Type = ASTNodeType::Undefined;
		Value = 0;
		Left = nullptr;
		Right = nullptr;
	}

	~ASTNode() {
		delete Left;
		delete Right;
	}
};

/*
class ASTOperatorNode : public ASTNode {
public:
	ASTOperatorType Operator;
	ASTOperatorNode() : ASTNode() {
		Operator = ASTOperatorType::Undefined;
	}
};

class ASTNumericNode : public ASTNode {
public:
	ASTNumericNode() : ASTNode() {
		
	}
};*/




#endif
