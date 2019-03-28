#ifndef GROUP_H
#define GROUP_H
#include "Student.h"
#include <vector>

class Group {
private:
	const vector<Student*>& students;
	const std::string groupName;

public:
	Group(const std::vector<Student*>& students, const std::string& groupName);

	std::string toString() const;

};

#endif
