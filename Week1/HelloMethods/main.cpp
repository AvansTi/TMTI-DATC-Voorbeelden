#include <iostream>


void printCircleArea(double radius = 1); // default arg
void printNumber(const int number); // const

// Pass by reference / value / pointer
void changeNumber(int number);
void changeNumberRef(int &number);
void changeNumberPointer(int *number);

int main() {

	printCircleArea();
	printCircleArea(4);

	std::cout << std::endl;

	{
		int number = 1;
		changeNumber(number);
		std::cout << "Pass by value: " << number << '\n';
	}

	{
		int number = 1;
		changeNumberRef(number);
		std::cout << "Pass by reference: " << number << '\n';
	}

	{
		int number = 1;
		changeNumberPointer(&number);
		std::cout << "Pass by pointer: " << number << std::endl;
	}

	std::cin.get();

	return 0;
}

void printCircleArea(double radius) {
	double area = radius * radius * 3.14159;
	std::cout << "area is " << area << std::endl;
}

void printNumber(const int number) {
	
	std::cout << "Number: " << number << std::endl;
	//number = 10;
}

void changeNumber(int number) {
	number += 10;
}

void changeNumberRef(int &number) {
	number += 10;
}

void changeNumberPointer(int *number) {
	*number += 10;
}