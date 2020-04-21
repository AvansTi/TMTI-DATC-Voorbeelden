#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>


int main() {

	constexpr int length = 7;
	constexpr double numbers[length] = { 22.3, 6.57, 31.44, 123.2, 17.84, 119.6, 66.77 };
	std::vector<double> vecNumbers = { 22.3, 6.57, 31.44, 123.2, 17.84, 119.6, 66.77 };


	vecNumbers.push_back(100);

	double maximum = numbers[0];
	for (int i = 1; i < length; i++) {
		maximum = std::max(numbers[i], maximum);
	}

	double average = std::accumulate(vecNumbers.begin(), vecNumbers.end(), 0)/vecNumbers.size();
	std::cout << "Maximum is: " << maximum << ", Average: "<< average << '\n';
}


