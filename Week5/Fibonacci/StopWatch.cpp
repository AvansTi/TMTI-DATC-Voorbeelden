#include "StopWatch.h"
#include <chrono> // For systemclock

using namespace std;

void StopWatch::start() {
	startTime = chrono::high_resolution_clock::now();
}

void StopWatch::stop() {
	endTime = chrono::high_resolution_clock::now();
}

double StopWatch::getElapsedTime() {
	std::chrono::duration<double, std::milli> diff = endTime - startTime;
	return diff.count();
}