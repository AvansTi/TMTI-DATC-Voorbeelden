#pragma once

#include <string>
#include "Date.h"

class Student {
private:
	std::string name, study, gender;
	int number;
	Date birthday;

public:
	Student(std::string name, std::string study, std::string gender, int number, Date birthday) noexcept;
	Student() = delete;
	~Student() = default;

	std::string toString() const;
	void naamInUpperCase();
	void changeYear(int year);
};
