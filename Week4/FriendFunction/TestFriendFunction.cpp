#include <iostream>
using namespace std;

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

void p() {
	Date date(2010, 5, 9);
	date.year = 2000;
	cout << date.year << endl;
}

int main() {
	p();

	return 0;
}