#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::Course(const Course& course) {
	numberOfStudents = course.getNumberOfStudents();
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	//this->students = course.students;
	this->students = new string[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const string& name) {
	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const string& name) {
	// Left as an exercise
}

string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

Course& Course::operator=(const Course& course) {
	if (this != &course) { // Do nothing with self-assignment
		courseName = course.courseName;
		numberOfStudents = course.numberOfStudents;
		capacity = course.capacity;

		delete[] this->students; // Delete the old array

		// Create a new array with the same capacity as course copied
		students = new string[capacity];
		for (int i = 0; i < numberOfStudents; i++)
			students[i] = course.students[i];
	}

	return *this;
}