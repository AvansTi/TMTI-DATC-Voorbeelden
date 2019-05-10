#include <cstring>
#include <iostream>

// C++ string
#include <string>
using namespace std::string_literals; // literals


int main() {
	
	// C String
	char cstr[15] = "Hello World";
	std::cout << "String cstr, contains: " << cstr << ". of length: " << strlen(cstr) << std::endl;

	// C++ String
	auto cppstring = "Hello World"s;
	std::string cppstring2("Hallo Klas"s);
	std::cout << "String cppstring, contains: " << cppstring << ". of length: " << cppstring.size() << std::endl;

	// Concatinate String
	std::string combinedString = cppstring + " " + cppstring2;
	std::cout << "Combined String: " << combinedString << std::endl;

	
	std::cin.get();

	return 0;
}