#include <iostream>
#include "Rational.h"
using namespace std;

int main() {
	// Create and initialize two rational numbers r1 and r2.
	Rational r1(4, 2);
	Rational r2(2, 3);

	// Test toString, add, subtract, multiply, and divide
	cout << r1.toString() << " + " << r2.toString() << " = "
		<< (r1 + r2).toString() << endl;
	cout << r1.toString() << " - " << r2.toString() << " = "
		<< (r1 - r2).toString() << endl;
	cout << r1.toString() << " * " << r2.toString() << " = "
		<< (r1 * r2).toString() << endl;
	cout << r1.toString() << " / " << r2.toString() << " = "
		<< (r1 / r2).toString() << endl;


	// Test intValue and double
	cout << "r2.intValue()" << " is " << int(r2) << endl;
	cout << "r2.doubleValue()" << " is " << double(r2) << endl;

	// Test compareTo and equal
	cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;
	cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
	cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
	cout << "r1.equals(r1) is "
		<< (r1.equals(r1) ? "true" : "false") << endl;
	cout << "r1.equals(r2) is "
		<< (r1.equals(r2) ? "true" : "false") << endl;


	cin.get();
	return 0;
}