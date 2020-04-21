#include <iostream>
#include "StopWatch.h"


int main() {

	constexpr int times = 10000;
	long long timeEndl;
	long long timeNewline;
	{
		StopWatch stopWatch{ "endl" };

		for (int i = 0; i < times; i++) {
			std::cout << "Hello world" << std::endl;
		}
		timeEndl = stopWatch.stop();

	}

	{
		StopWatch stopWatch{ "only newline" };

		for (int i = 0; i < times; i++) {
			std::cout << "Hello world" << '\n';
		}
		timeNewline = stopWatch.stop();
	}

	std::cout << "Execution time off endl    : " << timeEndl << " us\n";
	std::cout << "Execution time off newLine : " << timeNewline << " us\n";


	return 0;
}