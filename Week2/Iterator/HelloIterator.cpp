/*
#include <string>
#include <iostream>
*/

import std.core;

using namespace std::string_literals;

void reversePrint(const std::string& input);

int main() {
	std::string aString = "Hello World!"s;
	std::string::iterator pos;

	for (pos = aString.begin(); pos != aString.end(); ++pos) {
		std::cout << *pos << std::endl;
	}

	reversePrint(aString);

	// Maar het kan natuurlijk ook makkelijker met ingebouwede functionaliteit
	std::reverse(aString.begin(), aString.end());
	std::cout << "Reverse STL: " << aString << std::endl;

}

void reversePrint(const std::string& input) {
	std::string reverse(input.rbegin(), input.rend());
	
	std::cout << "Reverse: " << reverse << std::endl;
	
}
