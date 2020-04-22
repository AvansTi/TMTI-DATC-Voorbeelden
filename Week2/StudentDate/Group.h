#pragma once

#include "Student.h"
#include <vector>

class Group {
private:
	const std::vector<Student*>& students;
	const std::string groupName;

public:
	Group(const std::vector<Student*>& students, const std::string& groupName) noexcept;
	Group() = delete;
	~Group() = default;

	std::string toString() const;

};
