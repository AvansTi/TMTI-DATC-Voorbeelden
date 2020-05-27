#include "StopWatch.h"
#include <chrono> // For systemclock
#include <iostream>


StopWatch::StopWatch(std::string description) :
	description(description)
{
	startTime = std::chrono::high_resolution_clock::now();
}


StopWatch::~StopWatch() {
	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> diff = endTime - startTime;
	if (diff.count() > 0.1) {
		std::cout << "Execution time: " << diff.count() << " ms\n";
	}
	else {
		std::chrono::duration<double, std::micro> diffns = endTime - startTime;
		std::cout << "Execution time: " << diffns.count() << " us\n";
	}
}

