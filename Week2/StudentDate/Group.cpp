#include "Group.h"
#include <sstream>

Group::Group(const std::vector<Student*>& students, const std::string& groupName) :
	students(students), groupName(groupName)
{

}

std::string Group::toString() const {
	std::stringstream s;
	s << "Group: " << groupName << "Members: " << std::endl;
	for (Student* student : students) {
		s << student->toString() << endl;
	}
	return s.str();
}