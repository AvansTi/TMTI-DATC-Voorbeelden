#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>


void splitWords(const std::string& input, std::vector<std::string>& output);

int main() {
	
	int i = 10;
	const long double d = std::acos(-1.L);
	std::stringstream os;

	os << "The value of i = " << i << std::endl;
	os << "The value of d = " << std::setprecision(10) << d << std::endl;

	std::string string = os.str();
	std::cout << string;


	// Split strings on whitespace
	std::string inputString("Programming with C++ is next level!");
	std::vector<std::string> v;
	splitWords(inputString, v);

	int x;
	std::cin >> x;
	return 0;
}

void splitWords(const std::string& input, std::vector<std::string>& output) {
	
	std::stringstream ss(input);

	while (!ss.eof()) {
		std::string data;
		ss >> data;
		output.push_back(data);
	}
}
