#include <iostream>
#include "Date.h"

class AccessDate {
public:
	static void p() {
		Date birthDate(2010, 3, 4);
		birthDate.year = 2005;
		std::cout << birthDate.year << '\n';
	}
};

int main() {
	AccessDate::p();

	return 0;
}