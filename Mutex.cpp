#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

constexpr size_t V_ONE	{1};
constexpr size_t V_TEN	{10};
constexpr size_t V_TWO	{2};
constexpr size_t V_ZERO	{};

std::mutex mutex_counter;
std::recursive_mutex recursive_mutex_counter;
std::shared_mutex shared_mutex_resource;

void access_lock_guard_inner_resource()
{
	std::lock_guard<std::mutex> lock_guard_mutex {mutex_counter};
	std::cout << "+ Accessing shared resource... +" << std::endl;
}

void access_shared_resource()
{
	shared_mutex_resource.lock_shared();

	try
	{
		std::cout << "* Accessing shared resource... *" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "> Exception: [" << e.what() << "]." << std::endl;
		shared_mutex_resource.unlock_shared();
		throw;
	}

	shared_mutex_resource.unlock_shared();
}

void increase_counter(std::size_t& int_counter)
{
	mutex_counter.lock();
	std::cout << "+ Counter:\t(" << int_counter++ << ")." << std::endl;
	mutex_counter.unlock();
}

void mutex_function()
{
	if (mutex_counter.try_lock())
	{
		std::cout << "* Mutual exclusion has been acquired. *" << std::endl;
		mutex_counter.unlock();
	}
	else
		std::cout << "* Mutual exclusion has not been acquired. *" << std::endl;
}

std::size_t mutex_recursive_fibonacci(const std::size_t& number)
{
	std::size_t result{};
	recursive_mutex_counter.lock();

	if (number > V_TWO)
		result = mutex_recursive_fibonacci(number - V_ONE) + mutex_recursive_fibonacci(number - V_TWO);
	else
		result = number;

	recursive_mutex_counter.unlock();
	return result;
}

size_t mutex_recursive_summatory(const size_t& number)
{
	size_t result{};
	recursive_mutex_counter.lock();

	if (number > V_ZERO)
		result = number + mutex_recursive_summatory(number - V_ONE);
	else
		result = V_ZERO;

	recursive_mutex_counter.unlock();
	return result;
}

int main()
{
	size_t int_counter {V_ZERO};
	std::size_t fibonacci = mutex_recursive_fibonacci(V_TEN);
	size_t result = mutex_recursive_summatory(V_TEN);

	std::cout << "+ Fibo:\t\t[" << fibonacci << "]." << std::endl;
	std::cout << "+ Result:\t[" << result << "]." << std::endl;

	std::thread th0 {increase_counter, std::ref(int_counter)};
	std::thread th1 {mutex_function};
	std::thread th2 {mutex_function};

	std::thread th3 {access_shared_resource};
	std::thread th4 {access_shared_resource};

	access_lock_guard_inner_resource();

	th0.join();
	th1.join();
	th2.join();

	th3.join();
	th4.join();

	return V_ZERO;
}
