#include <mutex>
#include <condition_variable>
#include <chrono>

class semaphore
{
private:
	int m_uiCount;
	std::mutex m_mutex;
	std::condition_variable m_condition;

public:
	inline semaphore(int uiCount)
		: m_uiCount(uiCount) { }

	inline void Wait() {
		std::unique_lock< std::mutex > lock(m_mutex);
		m_condition.wait(lock, [&]()->bool { return m_uiCount>0; });
		--m_uiCount;
	}

	template< typename R, typename P >
	int Wait(const std::chrono::duration<R, P>& crRelTime) {
		std::unique_lock< std::mutex > lock(m_mutex);
		if (!m_condition.wait_for(lock, crRelTime, [&]()->bool { return m_uiCount>0; }))
			return -1;
		--m_uiCount;
		return m_uiCount;
	}

	inline void Signal() {
		std::unique_lock< std::mutex > lock(m_mutex);
		++m_uiCount;
		m_condition.notify_one();
	}
};