#ifndef DATE_H
#define DATE_H

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Date {
private:
	int day, month, year;

public:
	Date(int day, int month, int year);
	string toString() const;
	void changeYear(int year);
	int getYear() const;

};


#endif