#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include <vector>
#include "Group.h"


using namespace std::literals;


void addStudentsToGroup(std::vector<Student*>& vec) {
	Student* s10 = new Student { "Jan"s, "TI"s, "M"s, 1, Date{1, 1, 1996 } };
	Student* s11= new Student { "Piet"s, "TI"s, "M"s, 2, Date{2, 8, 1996 } };
	vec.push_back(s10);
	vec.push_back(s11);
}

int main() {

	// Aanmaken van student
	Student s{"Elena"s, "mathematics"s, "v"s, 201053,
		Date{13, 5, 1990} };

	std::cout << s.toString() << '\n';

	// Bij een toekenning wordt een kopie van alle velden gemaakt:
	Student s2 = s;
	s.naamInUpperCase();
	s.changeYear(2000);

	std::cout << "student 1:\n" << s.toString() << '\n';
	std::cout << "Kopie van student 1:\n" << s2.toString() << '\n';


	// Studenten toevoegen aan vector
	// Pointers op deze manier is gevaarlijk!!!
	
	std::vector<Student*> group1Students;// = { s10, s11 };
	addStudentsToGroup(group1Students);

	for (auto s : group1Students) {
		std::cout << s->toString() << '\n';
	}

	Group g1{ group1Students, "1" };
	//s11.naamInUpperCase();

	std::cout << g1.toString();

	while (!group1Students.empty()) {
		Student* p = group1Students.back();
		delete p; p = nullptr;
		group1Students.pop_back();
	}


}
