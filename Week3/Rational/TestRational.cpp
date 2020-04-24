#include <iostream>
#include "Rational.h"

int main()
{
	// Create and initialize two rational numbers r1 and r2.
	Rational r1(4, 2);
	Rational r2(2, 3);

	// Test toString, add, subtract, multiply, and divide
	std::cout << r1.toString() << " + " << r2.toString() << " = "
		<< r1.add(r2).toString() << '\n';
	std::cout << r1.toString() << " - " << r2.toString() << " = "
		<< r1.subtract(r2).toString() << '\n';
	std::cout << r1.toString() << " * " << r2.toString() << " = "
		<< r1.multiply(r2).toString() << '\n';
	std::cout << r1.toString() << " / " << r2.toString() << " = "
		<< r1.divide(r2).toString() << '\n';

	// Test intValue and double
	std::cout << "r2.intValue()" << " is " << r2.intValue() << '\n';
	std::cout << "r2.doubleValue()" << " is " << r2.doubleValue() << '\n';

	// Test compareTo and equal
	std::cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << '\n';
	std::cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << '\n';
	std::cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << '\n';
	std::cout << "r1.equals(r1) is "
		<< (r1.equals(r1) ? "true" : "false") << '\n';
	std::cout << "r1.equals(r2) is "
		<< (r1.equals(r2) ? "true" : "false") << '\n';


	return 0;


}