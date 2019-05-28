#pragma once

#include <string>
#include <vector>
#include "AST.h"


class ASTParser {
	
public:
	ASTNode* Parse(const std::string&);

private:
	std::vector<std::string> split(const std::string& expression);

};
