#include <iostream>
#include <iomanip>

int main()
{
	double x = 2000.0;

	std::cout << std::setprecision(2) << std::showpoint << std::fixed;

	for (int i = 0; i < 20; i++)
	{
		std::cout << std::setw(3) << i;
		std::cout << std::setw(12) << x * i << '\n';
	}


	std::cout << "Enter a number: ";
	int value;
	std::cin >> value;
	std::cout << std::endl;

	std::cout << "Entered value: " << value;
	
	return 0;
}