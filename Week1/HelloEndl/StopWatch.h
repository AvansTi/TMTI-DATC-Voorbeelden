#pragma once

#include <chrono>
#include <iostream>
#include <string>


class StopWatch {
public:
	StopWatch(const std::string& name) : name(name) {
		begin = std::chrono::high_resolution_clock::now();
	}


	long long stop() {
		auto end = std::chrono::high_resolution_clock::now();
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

		return microseconds.count();
	}

	~StopWatch() {
		std::cout << "~StopWatch" << std::endl;
		/*auto end = std::chrono::high_resolution_clock::now();
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

		// Report towards user
		std::cout << "Execution time off " << name << " : " << microseconds.count() << " µs\n";*/
	}

private:

	std::chrono::time_point<std::chrono::high_resolution_clock>  begin;
	std::string name;
};
