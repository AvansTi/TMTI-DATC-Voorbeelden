#include "Date.h"
#include <sstream>

Date::Date(int day, int month, int year)
	: day(day), month(month), year(year) {
}

string Date::toString() const {
	std::stringstream os;
	os << std::setfill('0') << setw(2) << day << '-'
		<< setw(2) << month << '-' << setw(4) << year;
	return os.str();
}

void Date::changeYear(int year) {
	this->year = year;
	//(*this).year = year;
}

int Date::getYear() const {
	return year;
}