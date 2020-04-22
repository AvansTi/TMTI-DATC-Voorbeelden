#include "Student.h"
#include <locale>
#include <sstream>

Student::Student(std::string name, std::string study, std::string gender, int number, Date birthday) noexcept
	: name(name), study(study), gender(gender), number(number),
	birthday(birthday) {
}

std::string Student::toString() const {
	std::stringstream os;
	os << name << " (" << birthday.toString() << ")\n";
	os << study << '\n';
	os << gender << '\n';
	os << number << std::endl;
	return os.str();
}

void Student::naamInUpperCase() {
	std::locale l;
	for (char& c : name) {
		c = std::toupper(c, l);
	}
}

void Student::changeYear(int year) {
	birthday.changeYear(year);
}