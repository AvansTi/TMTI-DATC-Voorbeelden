#ifndef PARSER_H
#define PARSER_H
/*
#include "AST.h"
#include <sstream>
#include <cctype>
#include <exception>
#include <string>

enum class TokenType {
	Error,
	Plus,
	Minus,
	Mul,
	Div,
	EndOfText,
	OpenParenthesis,
	ClosedParenthesis,
	Number
};

struct Token {
	TokenType Type;
	double Value;
	char Symbol;

	Token() :Type(TokenType::Error), Value(0), Symbol(0)
	{}
};

class Parser {
public:
	ASTNode* Parse(std::string& sourceText);

	Token crtlToken;
	std::string sourceText;
	size_t sourceIndex;

private:

	ASTNode* Expression();
	ASTNode* Expression1();
	ASTNode* Term();
	ASTNode* Term1();
	ASTNode* Factor();
	ASTNode* CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right=nullptr, double value=0);
	//ASTNode* CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right);
	//ASTNode* CreateUnaryNode(ASTNode* left);
	//ASTNode* CreateNodeNumber(double value);
	void Match(char expected);
	void SkipWhitespaces();
	void GetNextToken();
	double GetNumber();
};
*/
#endif