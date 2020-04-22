#pragma once

#include <string>

class Date {
private:
	int day, month, year;

public:
	Date() = delete;
	Date(int day, int month, int year) noexcept;
	~Date() = default;

	std::string toString() const;
	void changeYear(int year);
	int getYear() const;

};
