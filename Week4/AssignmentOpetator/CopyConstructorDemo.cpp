#include <iostream>
#include "Course.h" // See Listing 11.19


using namespace std::string_literals;


void printStudent(const std::string names[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << names[i] << (i < size - 1 ? ", " : " ");
}

int main() {
	Course course1{ "Java Programming", 10 };
	course1.addStudent("Peter Pan"); // Add a student to course1

	Course course2{ "C++ Programming", 10 };
	course2 = course1; // Create course2 as a copy of course1
	course2.addStudent("Lisa Ma"); // Add a student to course2


	std::cout << "students in course1: " << course1.getCourseName() << '\n';
	printStudent(course1.getStudents(), course1.getNumberOfStudents());
	std::cout << '\n';

	std::cout << "students in course2: " << course2.getCourseName() << '\n';
	printStudent(course2.getStudents(), course2.getNumberOfStudents());
	std::cout << '\n';

	return 0;
}