#pragma once


#include <string>
#include <memory>


class Course
{
public:
	Course(const std::string& courseName, int capacity) noexcept;
	Course(const Course& course) noexcept;
	~Course() noexcept;

	std::string getCourseName() const;
	void addStudent(const std::string& name);
	void dropStudent(const std::string& name);
	std::string* getStudents() const;
	int getNumberOfStudents() const;

	Course& operator=(const Course& course);

private:
	std::string courseName;
	std::unique_ptr<std::string[]> students;
	int numberOfStudents;
	int capacity;
};
