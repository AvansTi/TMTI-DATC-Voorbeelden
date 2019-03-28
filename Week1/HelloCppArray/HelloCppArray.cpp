#include <iostream>
#include <algorithm>
#include <array>

constexpr int size = 5;

int main() {

	std::array<int, size> myArray = { 2, 16, 77, 34, 50 };

	std::cout << "Array contains:";
	for (auto it = myArray.begin(); it != myArray.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

int largest(std::array<int, size> &myArray) {

	int largest = myArray.at(0);
	for (auto it = myArray.begin(); it != myArray.end(); ++it) {
		largest = std::max(largest, *it);
	}
		
	
}