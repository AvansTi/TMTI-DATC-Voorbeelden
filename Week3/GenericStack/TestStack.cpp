#include <iostream>
#include "GenericStack.h"
#include <string>

using namespace std;

int main() {
	
	Stack<std::string> papers;
	papers.push("Krant 1");
	papers.push("Krant 2");
	papers.push("Krant 3");


	while (!papers.empty()) {
		std::cout << "Paper: " << papers.peek() << '\n';
		papers.pop();
	}

	cin.get();
	return 0;
}