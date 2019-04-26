#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int numerator, int denominator);
	int getNumerator() const;
	int getDenominator() const;
	Rational add(const Rational& secondRational) const;
	Rational subtract(const Rational& secondRational) const;
	Rational multiply(const Rational& secondRational) const;
	Rational divide(const Rational& secondRational) const;
	int compareTo(const Rational& secondRational) const;
	bool equals(const Rational& secondRational) const;
	int intValue() const;
	double doubleValue() const;
	string toString() const;


	// Added for overloading

	// Compare operator(s)
	bool operator<(const Rational& second) const;

	// Math operator(s)
	Rational operator+(const Rational& second) const;
	Rational operator-(const Rational& second) const;
	Rational operator*(const Rational& second) const;
	Rational operator/(const Rational& second) const;
	Rational operator-() const;
	Rational& operator+=(const Rational& second);
	Rational& operator-=(const Rational& second);

	// Access index
	int& operator[](int index);
	bool operator==(const Rational& second) const;


	// Conversion operators
	operator double();
	operator int();
	operator std::string() const {
		return toString();
	}

	friend ostream& operator<<(ostream&, const Rational&);
	friend istream& operator>>(istream&, Rational&);
	

private:
	int numerator;
	int denominator;
	static int gcd(int n, int d);
};

#endif