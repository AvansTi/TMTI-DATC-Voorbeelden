#include <iostream>
#include "Date.h"


void p() {
	Date date{ 2010, 5, 9 };
	date.year = 2000;
	std::cout << date.year << '\n';
}

int main() {
	p();

	return 0;
}