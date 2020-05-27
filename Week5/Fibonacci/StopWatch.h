#pragma once
#include <chrono>
#include <string>

class StopWatch {

public:
	StopWatch(bool printOnDestruct = true) : printOnDestruct(printOnDestruct) {
		startTime = std::chrono::high_resolution_clock::now();
	}

	double stop() {
		auto endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> diff = endTime - startTime;

		return diff.count();
	}

	~StopWatch() {
		if (!printOnDestruct)
			return;


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


	StopWatch(const StopWatch& other) = delete;

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
	bool printOnDestruct;
};