#pragma once 

#include <string>


class Rational
{
public:
	Rational() noexcept;
	Rational(int numerator, int denominator) noexcept;
	Rational(const Rational& other) = default;
	~Rational() = default;
	


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
	std::string toString() const;

private:
	int numerator;
	int denominator;
	static int gcd(int n, int d);
};
