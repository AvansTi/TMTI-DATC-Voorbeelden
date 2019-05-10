#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include <vector>
#include "Group.h"

using namespace std;

using namespace std::literals;


int main() {

	// Aanmaken van student
	Student s{"Elena"s, "mathematics", "v", 201053,
		Date{13, 5, 1990} };

	cout << s.toString() << endl;

	// Bij een toekenning wordt een kopie van alle velden gemaakt:
	Student s2 = s;
	s.naamInUpperCase();
	s.changeYear(2000);

	cout << "student 1:\n" << s.toString() << endl;
	cout << "Kopie van student 1:\n" << s2.toString() << endl;


	// Studenten toevoegen aan vector
	// Pointers op deze manier is gevaarlijk!!!
	Student s10{ "Jan", "TI", "M", 1, Date{1, 1, 1996 } };
	Student s11{ "Piet", "TI", "M", 2, Date{2, 8, 1996 } };
	vector<Student*> group1Students;// = { s10, s11 };
	group1Students.push_back(&s10);
	group1Students.push_back(&s11);

	Group g1{ group1Students, "1" };
	s11.naamInUpperCase();

	cout << g1.toString();

	cin.get();

}
