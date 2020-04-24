#pragma once

#include <string>


class Course
{
public:
	Course(const std::string& courseName, int capacity);
	Course(const Course& course);
	~Course();
	std::string getCourseName() const;
	void addStudent(const std::string& name);
	void dropStudent(const std::string& name);
	std::string* getStudents() const;
	int getNumberOfStudents() const;

private:
	std::string courseName;
	std::string* students;
	int numberOfStudents;
	int capacity;
};
