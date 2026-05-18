#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

constexpr int V_ONE_HUNDRED	{100};
constexpr int V_TEN		{10};
constexpr int V_TWO		{2};
constexpr int V_ONE		{1};
constexpr int V_ZERO		{};

void inc(std::atomic<int>& counter)
{
	int result{V_ZERO};

	for (int idx{V_ZERO}; idx < V_ONE_HUNDRED; idx++)
	{
		std::cout << std::endl << "+ (" << result++ << ")." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(V_ONE));
	}

	counter += result;
}

void increase(std::atomic<int>& counter)
{
	for (int idx {V_ZERO}; idx < V_ONE_HUNDRED; idx++)
	{
		std::cout << std::endl << "- [" << counter++ << "]." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(V_ONE));
	}
}

void increaser(int& counter)
{
	std::atomic_ref<int> atomic_counter {counter};

	for (int idx {V_ZERO}; idx < V_ONE_HUNDRED; idx++)
	{
		std::cout << std::endl << "* {" << atomic_counter++ << "}." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(V_ONE));
	}
}

int main()
{
	int int_counter {V_ZERO};
	std::atomic<int> atomic_counter {V_ZERO};
	std::vector<std::thread> threads {};

	for (int idx {V_ZERO}; idx < V_TEN; idx++)
		threads.emplace_back(std::thread {inc, std::ref(atomic_counter)});

	for (auto& t : threads)
		t.join();

	std::cout << std::endl << "+ Result: (" << atomic_counter << ")." << std::endl;

	threads.clear();
	atomic_counter = V_ZERO;
	for (int idx {V_ZERO}; idx < V_TEN; idx++)
		threads.emplace_back(std::thread {increase, std::ref(atomic_counter)});

	for (auto& t : threads)
		t.join();

	std::cout << std::endl << "- Result: [" << atomic_counter << "]." << std::endl;

	threads.clear();
	for (int idx{V_ZERO}; idx < V_TEN; idx++)
		threads.emplace_back(std::thread {increaser, std::ref(int_counter)});

	for (auto& t : threads)
		t.join();

	std::cout << std::endl << "* Result: {" << int_counter << "}." << std::endl;


	std::atomic<int> atomic_value {V_ZERO};
	std::thread work_thread
	{
		[&atomic_value]
		{
			std::cout << std::endl << "Subprocess begins waiting..." << std::endl;
			std::cout << "< Value: [" << atomic_value << "]." << std::endl;

			atomic_value.wait(V_ZERO);

			std::cout << std::endl << "Subprocess wakes up." << std::endl;
			std::cout << "> Value: [" << atomic_value << "]." << std::endl;
		}
	};

	std::this_thread::sleep_for(std::chrono::seconds(V_TWO));
	std::cout << std::endl << "Main process changes the value: [" << (atomic_value = V_ONE) << "]." << std::endl;
	atomic_value.notify_all();

	work_thread.join();

	return V_ZERO;
}
