
/*#include <vector>
#include <iostream>
#include <string>*/

import std.core;

void printVector(const std::vector<double>& v);

int main() {
	
	double a[] = { 10.2, 1.23, 3.43, 3.14, 101.79 };
	//std::vector<double> v{10}; // Initialize vector with 10 zeros
	//std::vector<double> v{a, a + 5};
	std::vector<double> v = { 10.2, 1.23, 3.43, 3.14, 101.79 };

	std::cout << "Capacity: " << v.capacity() << ", size: " << v.size() << std::endl; // check capacity

	v.push_back(12.234);

	std::cout << "Capacity: " << v.capacity() << ", size: " << v.size() << std::endl; // check capacity

	// range based for loop
	for (double value : v) {
		std::cout << value << std::endl;
	}
	//printVector(v);

	// Get specific value
	std::cout << "Value at index "<< v.size()-1 <<": " << v.at(v.size()-1) << std::endl;

	// Remove the values
	while (!v.empty()) {
		v.pop_back();
	}

	return 0;
}


void printVector(const std::vector<double>& v) {

	for (auto pos = v.cbegin(); pos < v.cend(); ++pos) {
		std::cout << *pos << std::endl;
	}
}
