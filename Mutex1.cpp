#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

constexpr int V_TEN	{10};
constexpr int V_ZERO	{};

size_t counter {};
int shared_var {V_ZERO};
std::mutex my_own_mutex;

void update_var(const int& new_value)
{
	std::lock_guard<std::mutex> locked_guard_my_own_mutex {my_own_mutex};
	shared_var += new_value;

	std::cout << "Mutex Control Info." << std::endl;
	std::cout << "> Counter:\t(" << counter++ << ")." << std::endl;
	std::cout << "* Identifier:\t[" << std::this_thread::get_id() << "]." << std::endl;
	std::cout << "+ New value :\t{" << new_value << "}." << std::endl;
	std::cout << "- Shared var:\t<" << shared_var << ">." << std::endl << std::endl;
}

int main()
{
	std::vector<std::thread> threads;

	for (int i{}; i < V_TEN; i++)
		threads.emplace_back(std::thread {update_var, i});

	for (int i{}; i < V_TEN; i++)
		threads[i].join();

	return V_ZERO;
}
