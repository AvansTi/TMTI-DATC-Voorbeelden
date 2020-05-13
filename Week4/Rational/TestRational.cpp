#include <iostream>
#include <string>
#include "Rational.h"

int main() {
	// Create and initialize two rational numbers r1 and r2.
	Rational r1(4, 2);
	Rational r2(2, 3);

	// Test relational operators
	std::cout << r1 << " > " << r2 << " is " <<
		((r1 > r2) ? "true" : "false") << '\n';
	std::cout << r1 << " < " << r2 << " is " <<
		((r1 < r2) ? "true" : "false") << '\n';
	std::cout << r1 << " == " << r2 << " is " <<
		((r1 == r2) ? "true" : "false") << '\n';
	std::cout << r1 << " != " << r2 << " is " <<
		((r1 != r2) ? "true" : "false") << '\n';

	// Test toString, add, subtract, multiply, and divide operators
	std::cout << r1 << " + " << r2 << " = " << r1 + r2 << '\n';
	std::cout << r1 << " - " << r2 << " = " << r1 - r2 << '\n';
	std::cout << r1 << " * " << r2 << " = " << r1 * r2 << '\n';
	std::cout << r1 << " / " << r2 << " = " << r1 / r2 << '\n';

	// Test augmented operators
	Rational r3(1, 2);
	r3 += r1;
	std::cout << "r3 is " << r3 << '\n';

	// Test function operator []
	Rational r4(1, 2);
	r4[0] = 3; r4[1] = 4;
	std::cout << "r4 is " << r4 << '\n';

	// Test function operators for prefix ++ and --
	r3 = r4++;
	std::cout << "r3 is " << r3 << '\n';
	std::cout << "r4 is " << r4 << '\n';

	// Test function operator for conversion
	std::cout << "1 + " << r4 << " is " << (1 + r4) << '\n';

	return 0;
}