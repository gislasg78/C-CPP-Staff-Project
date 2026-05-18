#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

constexpr int V_FOURTY_TWO	{42};
constexpr int V_THREE		{3};
constexpr int V_ZERO		{};

int shared_var {V_ZERO};
std::shared_mutex my_shared_mutex;

void read_and_print()
{
	int value {shared_var};

	std::shared_lock my_locked_shared {my_shared_mutex};

	std::cout << "Shared object value: [" << value << "]." << std::endl;
}

void write_value(const int& new_value)
{
	std::unique_lock my_locked_unique {my_shared_mutex};

	shared_var = new_value;
}

int main()
{
	std::vector<std::thread> vector_threads;

	for (int i{}; i < V_THREE; i++)
		vector_threads.emplace_back(std::thread {read_and_print});

	for (int i{}; i < V_THREE; i++)
		vector_threads[i].join();

	std::thread thx {write_value, V_FOURTY_TWO};
	thx.join();

	std::thread thy {read_and_print};
	thy.join();

	return V_ZERO;
}
