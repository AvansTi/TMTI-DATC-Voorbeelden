#include <iostream>
#include <algorithm>


int main() {

	int length = 7;
	double numbers[7] = { 22.3, 6.57, 31.44, 123.2, 17.84, 119.6, 66.77 };

	double maximum = numbers[0];
	for (int i = 1; i < length; i++) {
		maximum = std::max(numbers[i], maximum);
	}
	std::cout << "Maximum is: " << maximum << std::endl;
}



