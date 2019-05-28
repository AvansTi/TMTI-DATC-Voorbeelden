#pragma once
#include <chrono>

using namespace std;

class StopWatch {

public:
	StopWatch() = default;
	~StopWatch() = default;

	void start();
	void stop();
	double getElapsedTime();

private:
	chrono::time_point<chrono::steady_clock> startTime;
	chrono::time_point<chrono::steady_clock> endTime;
};