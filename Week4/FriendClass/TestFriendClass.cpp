#include <iostream>
#include "Date.h"
using namespace std;

class AccessDate {
public:
	static void p() {
		Date birthDate(2010, 3, 4);
		birthDate.year = 2000;
		cout << birthDate.year << endl;
	}
};

int main() {
	AccessDate::p();

	cin.get();

	return 0;
}