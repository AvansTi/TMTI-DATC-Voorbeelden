#pragma once


class Date {
public:
	Date(int year, int month, int day) :
		year(year), month(month), day(day)
	{

	}
	friend void p();

private:
	int year;
	int month;
	int day;
};