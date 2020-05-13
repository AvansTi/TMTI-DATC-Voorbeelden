#include "Rational.h"

#include <sstream> // Used in toString to convert numbers to strings
#include <cmath> // For the abs function
#include <numeric>


Rational::Rational() noexcept :
	numerator(0), denominator(1)
{

}

Rational::Rational(int numerator) noexcept  :
	numerator(numerator), denominator(1)
{

}

Rational::Rational(int numerator, int denominator) noexcept {
	int factor = std::gcd(numerator, denominator);
	this->numerator = (denominator > 0 ? 1 : -1) * numerator / factor;
	this->denominator = abs(denominator) / factor;
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
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

bool Rational::equals(const Rational& secondRational) const {
	return (compareTo(secondRational) == 0);
}

int Rational::intValue() const {
	return getNumerator() / getDenominator();
}

double Rational::doubleValue() const {
	return (1.0 * getNumerator()) / getDenominator();
}

std::string Rational::toString() const {
	if (denominator == 1)
		return std::to_string(numerator); 
	else
		return std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Define function operators for augmented operators
Rational& Rational::operator+=(const Rational& secondRational) {
	*this = add(secondRational);
	return *this;
}

Rational& Rational::operator-=(const Rational& secondRational) {
	*this = subtract(secondRational);
	return *this;
}

Rational& Rational::operator*=(const Rational& secondRational) {
	*this = multiply(secondRational);
	return *this;
}

Rational& Rational::operator/=(const Rational& secondRational) {
	*this = divide(secondRational);
	return *this;
}

// Define function operator []
int& Rational::operator[](int index) {
	return ((index == 0) ? numerator : denominator);
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++() {
	numerator += denominator;
	return *this;
}

Rational& Rational::operator--() {
	numerator -= denominator;
	return *this;
}

// Define function operators for postfix ++ and --
Rational Rational::operator++(int dummy) {
	Rational temp{ numerator, denominator };
	numerator += denominator;
	return temp;
}

Rational Rational::operator--(int dummy) {
	Rational temp{ numerator, denominator };
	numerator -= denominator;
	return temp;
}

// Define function operators for unary + and -
Rational Rational::operator+() {
	return *this;
}

Rational Rational::operator-() {
	return Rational(-numerator, denominator);
}

// Define the output and input operator
std::ostream& operator<<(std::ostream& out, const Rational& rational) {
	out << rational.toString();
	return out;
}

std::istream& operator>>(std::istream& in, Rational& rational) {
	std::cout << "Enter numerator: ";
	in >> rational.numerator;

	std::cout << "Enter denominator: ";
	in >> rational.denominator;
	return in;
}

// Define function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2){
	return (r1.compareTo(r2) < 0);
}

bool operator<=(const Rational& r1, const Rational& r2){
	return (r1.compareTo(r2) <= 0);
}

bool operator>(const Rational& r1, const Rational& r2){
	return (r1.compareTo(r2) > 0);
}

bool operator>=(const Rational& r1, const Rational& r2){
	return (r1.compareTo(r2) >= 0);
}

bool operator==(const Rational& r1, const Rational& r2){
	return (r1.compareTo(r2) == 0);
}

bool operator!=(const Rational& r1, const Rational& r2){
	return (r1.compareTo(r2) != 0);
}

// Define non-member function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2){
	return r1.add(r2);
}

Rational operator-(const Rational& r1, const Rational& r2){
	return r1.subtract(r2);
}

Rational operator*(const Rational& r1, const Rational& r2){
	return r1.multiply(r2);
}

Rational operator/(const Rational& r1, const Rational& r2){
	return r1.divide(r2);
}