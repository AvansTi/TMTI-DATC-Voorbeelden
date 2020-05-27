#pragma once

#include <mutex>
#include <condition_variable>
#include <chrono>

class semaphore
{
private:
	int count;
	std::mutex mutex;
	std::condition_variable condition;

public:
	inline semaphore(int count)
		: count(count) { }

	inline void Wait() {
		std::unique_lock<std::mutex> lock(mutex);
		condition.wait(lock, [&]()->bool { return count > 0; });
		--count;
	}

	template< typename R, typename P >
	int Wait(const std::chrono::duration<R, P>& crRelTime) {
		std::unique_lock< std::mutex > lock(mutex);
		if (!condition.wait_for(lock, crRelTime, [&]()->bool { return count > 0; }))
			return -1;
		--count;
		return count;
	}

	inline void Signal() {
		std::unique_lock<std::mutex> lock(mutex);
		++count;
		condition.notify_one();
	}
};