#include <iostream>
#include "Course.h"



Course::Course(const std::string& courseName, int capacity) noexcept: 
	capacity(capacity), courseName(courseName), numberOfStudents(0) {
	students.reset(new std::string[capacity]);
	//students = new std::string[capacity];
}

Course::Course(const Course& course) noexcept :
	capacity(course.capacity), courseName(course.courseName), numberOfStudents(course.numberOfStudents) 
{
	//this->students = course.students;
	//this->students = new std::string[this->capacity];
	students.reset(new std::string[capacity]);
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() noexcept{
	//delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const std::string& name) {
	// Left as an exercise
}

std::string* Course::getStudents() const {
	return students.get();
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

Course& Course::operator=(const Course& course) {
	if (this != &course) { // Do nothing with self-assignment
		courseName = course.courseName;
		numberOfStudents = course.numberOfStudents;
		capacity = course.capacity;

		//delete[] this->students; // Delete the old array

		// Create a new array with the same capacity as course copied
		//students = new string[capacity];
		students.reset(new std::string[capacity]);
		for (int i = 0; i < numberOfStudents; i++)
			students[i] = course.students[i];
	}

	return *this;
}