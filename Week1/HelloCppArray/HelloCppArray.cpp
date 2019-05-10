#include <iostream>
#include <algorithm>
#include <array>

constexpr int size = 5;

int largest(std::array<int, size> &myArray);

int main() {

	std::array<int, size> myArray = { 2, 16, 77, 34, 50 };

	std::cout << "Array contains:";
	for (auto it = myArray.begin(); it != myArray.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "Array contains:";
	// Of Range based for loop
	for (auto value : myArray)
		std::cout << ' ' << value;

	std::cout << '\n';

	std::cout << "Largest number: " << largest(myArray) << std::endl;

	int x = NULL;

	std::cin.get();

}

int largest(std::array<int, size> &myArray) {

	auto largest = myArray.at(0);
	for (auto value : myArray) {
		largest = std::max(largest, value);
	}
		
	return largest;
}