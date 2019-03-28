#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Date.h"

using namespace std;

class Student {
private:
	string name, study, gender;
	int number;
	Date birthday;

public:
	Student(string n, string opl, string gesl, int nr, Date birthday);
	string toString() const;
	void naamInUpperCase();
	void changeYear(int year);
};

#endif