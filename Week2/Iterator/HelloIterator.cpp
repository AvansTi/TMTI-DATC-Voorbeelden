#include <string>
#include <iostream>

void reversePrint(const std::string& input);

int main() {
	std::string aString = "Hello World!";
	std::string::iterator pos;

	for (pos = aString.begin(); pos != aString.end(); ++pos) {
		std::cout << *pos << std::endl;
	}

	reversePrint(aString);

	std::cin.get();
}

void reversePrint(const std::string& input) {
	std::string reverse(input.rbegin(), input.rend());
	
	std::cout << "Reverse: " << reverse << std::endl;
	
}
