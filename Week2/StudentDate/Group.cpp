#include "Group.h"
#include <sstream>

Group::Group(const std::vector<Student*>& students, const std::string& groupName) noexcept :
	students(students), groupName(groupName)
{

}

std::string Group::toString() const {
	std::stringstream s;
	s << "Group: " << groupName << "Members: " << '\n';
	for (Student* student : students) {
		s << student->toString() << std::endl;
	}
	return s.str();
}