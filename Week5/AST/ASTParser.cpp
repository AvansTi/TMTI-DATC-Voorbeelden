#include "ASTParser.h"

using namespace std;

ASTNode* ASTParser::Parse(const std::string& expression) {

	vector<string> tokens = split(expression);


	// local storage
	double value = 0.0;

	// Phase 1: Scan tokens
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i][0] == '+' || tokens[i][0] == '-')
		{
			// Process all +, -, *, / in the top of the operator stack
			/*while (!operatorStack.empty() && (operatorStack.peek() == '+'
				|| operatorStack.peek() == '-' || operatorStack.peek() == '*'
				|| operatorStack.peek() == '/'))
			{
				processAnOperator(operandStack, operatorStack);
			}*/

			// Push the + or - operator into the operator stack
			//operatorStack.push(tokens[i][0]);
		}
		else if (tokens[i][0] == '*' || tokens[i][0] == '/')
		{
			// Process all *, / in the top of the operator stack
			/*while (!operatorStack.empty() && (operatorStack.peek() == '*'
				|| operatorStack.peek() == '/'))
			{
				processAnOperator(operandStack, operatorStack);
			}

			// Push the * or / operator into the operator stack
			operatorStack.push(tokens[i][0]);*/
		}
		/*else if (tokens[i][0] == '(')
		{
			operatorStack.push('('); // Push '(' to stack
		}
		else if (tokens[i][0] == ')')
		{
			// Process all the operators in the stack until seeing '('
			while (operatorStack.peek() != '(')
			{
				processAnOperator(operandStack, operatorStack);
			}

			operatorStack.pop(); // Pop the '(' symbol from the stack
		}*/
		else {
			// Numeric value
			value = atof(tokens[i].c_str());
			ASTNode* node = new ASTNode();
			node->Type = ASTNodeType::NumberValue;
			node->Value = value;
		}
	}

	// Phase 2: process all the remaining operators in the stack
	/*while (!operatorStack.empty())
	{
		processAnOperator(operandStack, operatorStack);
	}*/

	// Return the result
	//return operandStack.pop();


	return nullptr;
}

vector<string> ASTParser::split(const string& expression)
{
	vector<string> v; // A vector to store split items as strings
	string numberString; // A numeric string

	for (char i : expression) {
		if (isdigit(i))
			numberString.append(1, i); // Append a digit
		else
		{
			if (!numberString.empty()) {
				v.push_back(numberString); // Store the numeric string
				numberString.erase(); // Empty the numeric string
			}

			if (!isspace(i)) {
				string s;
				s.append(1, i);
				v.push_back(s); // Store an operator and parenthesis
			}
		}
	}

	// Store the last numeric string
	if (!numberString.empty())
		v.push_back(numberString);

	return v;
}
