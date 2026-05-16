#include <atomic>
#include <iostream>
#include <thread>
#include <type_traits>

class Locked
{
	private:
		int m_array[123]{};
};

class Idle
{
	private:
		int m_int{};
};

std::atomic<int> counter{0};

int main()
{
	std::atomic<Locked> locked;
	std::cout << "[" << std::is_trivially_copyable_v<Locked> << ", " << locked.is_lock_free() << "]." << std::endl;

	std::atomic<Idle> idle;
	std::cout << "[" << std::is_trivially_copyable_v<Idle> << ", " << idle.is_lock_free() << "]." << std::endl;

	return 0;
}
