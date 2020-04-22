export module StudentDate;

import std.core;

Date::Date(int day, int month, int year) noexcept
	: day(day), month(month), year(year) {
}

std::string Date::toString() const {
	std::stringstream os;
	os << std::setfill('0') << std::setw(2) << day << '-'
		<< std::setw(2) << month << '-' << std::setw(4) << year;
	return os.str();
}

void Date::changeYear(int year) {
	this->year = year;
	//(*this).year = year;
}

int Date::getYear() const {
	return year;
}