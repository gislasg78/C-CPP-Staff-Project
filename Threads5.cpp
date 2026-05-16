#include <atomic>
#include <iostream>
#include <memory>
#include <thread>

constexpr int V_FIFTY_SIX	{56};
constexpr int V_FOURTY_TWO	{42};
constexpr int V_TEN		{10};
constexpr int V_ZERO		{};

int main()
{
	int x{};
	std::atomic_ref<int> a{x};
	a = V_TEN;
	std::cout << "Value:\t[" << a << "]." << std::endl;

	std::thread ta1
	{
		[&]	{a++;}
	};

	std::thread ta2
	{
		[&]	{a++;}
	};

	ta1.join();
	ta2.join();

	std::cout << "Value:\t[" << x << "]." << std::endl << std::endl;

	std::shared_ptr<int> shared_pointer = std::make_shared<int>(V_FOURTY_TWO);
	std::atomic<std::shared_ptr<int>> shr_ptr {shared_pointer};

	std::thread t1
	{
		[&]
		{
			std::shared_ptr<int> p {shr_ptr.load()};
			std::cout << "Subprocess #1. Value:\t\t[" << *p << "]." << std::endl;
		}
	};

	std::thread t2
	{
		[&]
		{
			std::shared_ptr<int> p {shr_ptr.load()};
			std::cout << "Subprocess #2. Value:\t\t[" << *p << "]." << std::endl;

			*p = V_FIFTY_SIX;
			std::cout << "Subprocess #2. Modified:\t[" << *p << "]." << std::endl;
		}
	};

	t1.join();
	t2.join();

	std::shared_ptr<int> p = shr_ptr.load();
	std::cout << std::endl << "Final value:\t\t\t[" << *p << "]." << std::endl;

	return V_ZERO;
}
