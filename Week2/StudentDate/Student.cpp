#include "Student.h"
#include <locale>
#include <sstream>

Student::Student(string name, string study, string gender, int number, Date birthday)
	: name(name), study(study), gender(gender), number(number),
	birthday(birthday) {
}

string Student::toString() const {
	stringstream os;
	os << name << " (" << birthday.toString() << ")" << endl;
	os << study << endl;
	os << gender << endl;
	os << number << endl;
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