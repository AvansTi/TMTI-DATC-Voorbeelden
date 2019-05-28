#include "AST.h"
#include "Parser.h"
#include "Evaluator.h"
#include "Exceptions.h"

#include <iostream>
#include <fstream>
#include "ASTParser.h"

using namespace std::string_literals;

void Test(std::string text) {
	ASTParser parser;

	try {
		ASTNode* ast = parser.Parse(text);

		try {
			Evaluator eval;
			double val = eval.Evaluate(ast);

			std::cout << text << " = " << val << std::endl;
		} catch (EvaluatorException& ex) {
			std::cout << text << " t " << ex.what() << std::endl;
		}

		delete ast;
	} catch (ParserException& ex) {
		std::cout << text << " t " << ex.what() << std::endl;
	}
}


void parse(const std::string& filename) {
	std::ifstream input{ filename };

	input.close();

}

int main()
{
	Test("1+2+3+4");
	Test("1*2*3*4");
	Test("1-2-3-4");
	Test("1/2/3/4");
	Test("1*2+3*4");
	Test("1+2*3+4");
	Test("(1+2)*(3+4)");
	Test("1+(2*3)*(4+5)");
	Test("1+(2*3)/4+5");
	Test("5/(4+3)/2");
	Test("1 + 2.5");
	Test("125");
	Test("-1");
	Test("-1+(-2)");
	Test("-1+(-2.0)");

	Test("   1*2,5");
	Test("   1*2.5e2");
	Test("M1 + 2.5");
	Test("1 + 2&5");
	Test("1 * 2.5.6");
	Test("1 ** 2.5");
	Test("*1 / 2.5");

	return 0;
}