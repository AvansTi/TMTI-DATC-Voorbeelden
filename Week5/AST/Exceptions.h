#pragma once

#include <exception>
#include <string>

class ParserException : public std::exception {
	const int position;
public:
	ParserException(const std::string& message, int pos) :
		std::exception(message.c_str()),
		position(pos)
	{
	}
};

class EvaluatorException : public std::exception {
public:
	EvaluatorException(const std::string& message) :
		std::exception(message.c_str())
	{
	}
};