#include <iostream>
#include <thread>
#include <mutex>
#include "Semaphore.h"
#include <sstream>
#include <future>
#include <chrono>

enum class LockType {
	None = 0,
	Mutex = 1,
	Semaphore = 2
};

//std::mutex localMutex;
std::timed_mutex localMutex;
semaphore localSemaphore(2);

using Ms = std::chrono::milliseconds;
using us = std::chrono::microseconds;
using ns = std::chrono::nanoseconds;

int square(int x) {
	return x * x;
}

void call_from_thread(int threadId, LockType lock) {
	if (lock == LockType::Mutex && !localMutex.try_lock_for(Ms(100)))
		return;

	if (lock == LockType::Semaphore) {
		// Using a stringstream to avoid incorrect appending. 
		std::stringstream ss;
		int semId = localSemaphore.Wait(Ms(1000));
		if (semId < 0)
			return;
		ss << "Aquire Semaphore num: " << semId << std::endl;
		std::cout << ss.str();
	}

	std::cout << "Hello, World from thread: " << threadId << std::endl;

	if (lock == LockType::Mutex)
		localMutex.unlock();

	if (lock == LockType::Semaphore)
		localSemaphore.Signal();
}


int main() {
	constexpr const int num_threads = 10;
	std::thread t[num_threads];

	//Launch a group of threads
	for (int i = 0; i < num_threads; ++i) {
		t[i] = std::thread(call_from_thread, i, LockType::Mutex);
		//std::this_thread::sleep_for(us(50));
	}

	/*auto a = std::async(&square, 10);
	int v = a.get();
	std::cout << "The thread returned: " << v << std::endl;
	std::cout << "Launched from the main" << std::endl;*/

	//Join the threads with the main thread
	for (int i = 0; i < num_threads; ++i) {
		t[i].join();
	}

	return 0;
}

