#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "GenericStack.h"

using namespace std;

// Split an expression into numbers, operators, and parenthese
vector<string> split(const string& expression);

// Evaluate an expression and return the result
int evaluateExpression(const string& expression);

// Perform an operation
void processAnOperator(Stack<int>& operandStack, Stack<char>& operatorStack);

int main() {
	string expression;
	while (true) {
		cout << "Enter an expression: ";
		getline(cin, expression);

		cout << expression << " = " << evaluateExpression(expression) << endl;
	}
	cin.get();

	return 0;
}

vector<string> split(const string& expression) {
	vector<string> v; // A vector to store split items as strings
	string numberString; // A numeric string

	for (unsigned int i = 0; i < expression.length(); i++) {
		if (isdigit(expression[i]))
			numberString.append(1, expression[i]); // Append a digit
		else {
			if (numberString.size() > 0) {
				v.push_back(numberString); // Store the numeric string
				numberString.erase(); // Empty the numeric string
			}

			if (!isspace(expression[i])) {
				string s;
				s.append(1, expression[i]);
				v.push_back(s); // Store an operator and parenthesis
			}
		}
	}

	// Store the last numeric string
	if (numberString.size() > 0)
		v.push_back(numberString);

	return v;
}

// Evaluate an expression 
int evaluateExpression(const string& expression) {
	// Create operandStack to store operands
	Stack<int> operandStack;

	// Create operatorStack to store operators
	Stack<char> operatorStack;

	// Extract operands and operators
	vector<string> tokens = split(expression);

	// Phase 1: Scan tokens
	for (unsigned int i = 0; i < tokens.size(); i++) {
		if (tokens[i][0] == '+' || tokens[i][0] == '-') {
			// Process all +, -, *, / in the top of the operator stack
			while (!operatorStack.empty() && (operatorStack.peek() == '+'
				|| operatorStack.peek() == '-' || operatorStack.peek() == '*'
				|| operatorStack.peek() == '/')) {
				processAnOperator(operandStack, operatorStack);
			}

			// Push the + or - operator into the operator stack
			operatorStack.push(tokens[i][0]);
		} else if (tokens[i][0] == '*' || tokens[i][0] == '/') {
			// Process all *, / in the top of the operator stack
			while (!operatorStack.empty() && (operatorStack.peek() == '*'
				|| operatorStack.peek() == '/')) {
				processAnOperator(operandStack, operatorStack);
			}

			// Push the * or / operator into the operator stack
			operatorStack.push(tokens[i][0]);
		} else if (tokens[i][0] == '(') {
			operatorStack.push('('); // Push '(' to stack
		} else if (tokens[i][0] == ')') {
			// Process all the operators in the stack until seeing '('
			while (operatorStack.peek() != '(') {
				processAnOperator(operandStack, operatorStack);
			}

			operatorStack.pop(); // Pop the '(' symbol from the stack
		} else { // An operand scanned. Push an operand to the stack as integer
			operandStack.push(atoi(tokens[i].c_str()));
		}
	}

	// Phase 2: process all the remaining operators in the stack
	while (!operatorStack.empty()) {
		processAnOperator(operandStack, operatorStack);
	}

	// Return the result
	return operandStack.pop();
}

// Process one opeator: Take an operator from operatorStack and 
// apply it on the operands in the operandStack 
void processAnOperator(Stack<int>& operandStack, Stack<char>& operatorStack) {
	char op = operatorStack.pop();
	int op1 = operandStack.pop();
	int op2 = operandStack.pop();
	if (op == '+')
		operandStack.push(op2 + op1);
	else if (op == '-')
		operandStack.push(op2 - op1);
	else if (op == '*')
		operandStack.push(op2 * op1);
	else if (op == '/')
		operandStack.push(op2 / op1);
}