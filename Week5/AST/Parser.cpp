#include "Parser.h"
#include "Exceptions.h"
/*
ASTNode* Parser::Parse(std::string& sourceText) {
	this->sourceText = sourceText;
	sourceIndex = 0;
	GetNextToken();

	return Expression();
}


ASTNode* Parser::Expression() {
	ASTNode* tnode = Term();
	ASTNode* e1node = Expression1();

	return CreateNode(ASTNodeType::OperatorPlus, tnode, e1node);
}

ASTNode* Parser::Expression1() {
	ASTNode* tnode;
	ASTNode* e1node;

	switch (crtlToken.Type)
	{
	case TokenType::Plus:
		GetNextToken();
		tnode = Term();
		e1node = Expression1();

		return CreateNode(ASTNodeType::OperatorPlus, e1node, tnode);

	case TokenType::Minus:
		GetNextToken();
		tnode = Term();
		e1node = Expression1();

		return CreateNode(ASTNodeType::OperatorMinus, e1node, tnode);
	}

	return CreateNode(ASTNodeType::NumberValue, nullptr, nullptr, 0);
}


ASTNode* Parser::Term()
{
	ASTNode* fnode = Factor();
	ASTNode* t1node = Term1();

	return CreateNode(ASTNodeType::OperatorMul, fnode, t1node);
}

ASTNode* Parser::Term1()
{
	ASTNode* fnode;
	ASTNode* t1node;

	switch (crtlToken.Type)
	{
	case TokenType::Mul:
		GetNextToken();
		fnode = Factor();
		t1node = Term1();
		return CreateNode(ASTNodeType::OperatorMul, t1node, fnode);

	case TokenType::Div:
		GetNextToken();
		fnode = Factor();
		t1node = Term1();
		return CreateNode(ASTNodeType::OperatorDiv, t1node, fnode);
	}

	return CreateNode(ASTNodeType::NumberValue, nullptr, nullptr, 1);
}

ASTNode* Parser::Factor() {
	ASTNode* node;
	switch (crtlToken.Type)
	{
	case TokenType::OpenParenthesis:
		GetNextToken();
		node = Expression();
		Match(')');
		return node;

	case TokenType::Minus:
		GetNextToken();
		node = Factor();
		return CreateNode(ASTNodeType::UnaryMinus, node, nullptr, 0);

	case TokenType::Number: {
		double value = crtlToken.Value;
		GetNextToken();
		return CreateNode(ASTNodeType::NumberValue, nullptr, nullptr, value);
	}
	default: {
		std::stringstream sstr;
		sstr << "Unexpected token '" << crtlToken.Symbol << "' at position " << sourceIndex;
		throw ParserException(sstr.str(), sourceIndex);
	}
	}
}


ASTNode* Parser::CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right, double value) {
	ASTNode* node = nullptr;

	if (type == ASTNodeType::NumberValue) {
		node = new ASTNumericNode{};
		node->Type = ASTNodeType::NumberValue;
		node->Value = value;
	} else if (type == ASTNodeType::UnaryMinus) {
		node = new ASTNode;
		node->Type = ASTNodeType::UnaryMinus;
		node->Left = left;
		node->Right = nullptr;
	}

	return node;
}
*/

/*ASTNode* Parser::CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right) {
	ASTNode* node = new ASTNode;
	node->Type = type;
	node->Left = left;
	node->Right = right;

	return node;
}*/

/*ASTNode* Parser::CreateUnaryNode(ASTNode* left) {
	ASTNode* node = new ASTNode;
	node->Type = ASTNodeType::UnaryMinus;
	node->Left = left;
	node->Right = nullptr;

	return node;
}*/

/*ASTNode* Parser::CreateNodeNumber(double value) {
	ASTNode* node = new ASTNode;
	node->Type = ASTNodeType::NumberValue;
	node->Value = value;

	return node;
}*/

/*
void Parser::Match(char expected) {
	if (sourceText[sourceIndex - 1] == expected)
		GetNextToken();
	else {
		std::stringstream sstr;
		sstr << "Expected token '" << expected << "' at position " << sourceIndex;
		throw ParserException(sstr.str(), sourceIndex);
	}
}

void Parser::SkipWhitespaces() {
	while (isspace(sourceText[sourceIndex])) sourceIndex++;
}

void Parser::GetNextToken() {
	SkipWhitespaces();

	crtlToken.Value = 0;
	crtlToken.Symbol = 0;

	if (sourceText[sourceIndex] == 0) {
		crtlToken.Type = TokenType::EndOfText;
		return;
	}

	if (isdigit(sourceText[sourceIndex])) {
		crtlToken.Type = TokenType::Number;
		crtlToken.Value = GetNumber();
		return;
	}

	crtlToken.Type = TokenType::Error;

	switch (sourceText[sourceIndex])
	{
	case '+': crtlToken.Type = TokenType::Plus; break;
	case '-': crtlToken.Type = TokenType::Minus; break;
	case '*': crtlToken.Type = TokenType::Mul; break;
	case '/': crtlToken.Type = TokenType::Div; break;
	case '(': crtlToken.Type = TokenType::OpenParenthesis; break;
	case ')': crtlToken.Type = TokenType::ClosedParenthesis; break;
	}

	if (crtlToken.Type != TokenType::Error) {
		crtlToken.Symbol = sourceText[sourceIndex];
		sourceIndex++;
	}
	else {
		std::stringstream sstr;
		sstr << "Unexpected token '" << sourceText[sourceIndex] << "' at position " << sourceIndex;
		throw ParserException(sstr.str(), sourceIndex);
	}
}

double Parser::GetNumber() {
	SkipWhitespaces();

	int index = sourceIndex;
	while (isdigit(sourceText[sourceIndex])) sourceIndex++;
	if (sourceText[sourceIndex] == '.') sourceIndex++;
	while (isdigit(sourceText[sourceIndex])) sourceIndex++;

	int count = sourceIndex - index;
	if (sourceIndex - index == 0)
		throw ParserException("Number expected but not found!", sourceIndex);

	//char buffer[32] = { 0 };
	//memcpy(buffer, &sourceText[index], sourceIndex - index);
	std::string num = sourceText.substr(index, count);

	return atof(num.c_str());
}
*/