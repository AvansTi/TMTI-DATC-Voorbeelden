#include "Rational.h"
#include <sstream> // Used in toString to convert numbers to strings
#include <cstdlib> // For the abs function
#include <iostream>


Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
	int factor = gcd(numerator, denominator);
	this->numerator = ((denominator > 0) ? 1 : -1) * numerator / factor;
	this->denominator = abs(denominator) / factor;
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

// Find GCD of two numbers 
int Rational::gcd(int n, int d) {
	int n1 = abs(n);
	int n2 = abs(d);
	int gcd = 1;

	for (int k = 1; k <= n1 && k <= n2; k++) {
		if (n1 % k == 0 && n2 % k == 0)
			gcd = k;
	}

	return gcd;
}

Rational Rational::add(const Rational& secondRational) const {
	int n = numerator * secondRational.getDenominator() +
		denominator * secondRational.getNumerator();
	int d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}

Rational Rational::subtract(const Rational& secondRational) const {
	int n = numerator * secondRational.getDenominator()
		- denominator * secondRational.getNumerator();
	int d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}

Rational Rational::multiply(const Rational& secondRational) const {
	int n = numerator * secondRational.getNumerator();
	int d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}

Rational Rational::divide(const Rational& secondRational) const {
	int n = numerator * secondRational.getDenominator();
	int d = denominator * secondRational.numerator;
	return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const {
	Rational temp = subtract(secondRational);
	if (temp.getNumerator() < 0)
		return -1;
	else if (temp.getNumerator() == 0)
		return 0;
	else
		return 1;
}

bool Rational::equals(const Rational& secondRational) const
{
	return compareTo(secondRational) == 0;
}

int Rational::intValue() const {
	return getNumerator() / getDenominator();
}

double Rational::doubleValue() const {
	return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString() const {
	if (denominator == 1)
		return to_string(numerator); // See Ch7 for to_string
	return  to_string(numerator) + "/" + to_string(denominator);
}


// Added with operator overloading
bool Rational::operator<(const Rational& second) const {
	return compareTo(second) < 0;
}

bool Rational::operator==(const Rational& second) const {
	return compareTo(second) == 0;
}

Rational Rational::operator+(const Rational& second) const {
	return add(second);
}

Rational Rational::operator-(const Rational& second) const {
	return subtract(second);
}

Rational Rational::operator*(const Rational& second) const {
	return multiply(second);
}

Rational Rational::operator/(const Rational& second) const {
	return divide(second);
}

int& Rational::operator[](int index) {
	
	if (index == 0)
		return numerator;
	if (index == 1)
		return denominator;

	throw runtime_error("subscript of of range");
}

Rational Rational::operator-() const {
	return Rational(-numerator, denominator);
}

Rational& Rational::operator+=(const Rational& second) {
	*this = add(second);
	return *this;
}

Rational& Rational::operator-=(const Rational& second) {
	*this = subtract(second);
	return *this;
}

Rational::operator double() {
	return doubleValue();
}

Rational::operator int() {
	return intValue();
}

// Define the output and input operator
ostream& operator<<(ostream& out, const Rational& rational)
{
	if (rational.denominator == 1)
		out << rational.numerator;
	else
		out << rational.numerator << "/" << rational.denominator;
	return out;
}

istream& operator>>(istream& in, Rational& rational)
{
	cout << "Enter numerator: ";
	in >> rational.numerator;

	cout << "Enter denominator: ";
	in >> rational.denominator;
	return in;
}