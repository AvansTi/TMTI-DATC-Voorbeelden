#include <string>
#include <iostream>

int main() {
	std::string aString = "Hello World!";
	std::string::iterator pos;

	for (pos = aString.begin(); pos != aString.end(); ++pos) {
		std::cout << *pos << std::endl;
	}
}
