#include <iostream>
#include <mutex>
#include <thread>

constexpr int V_ZERO	{};

std::mutex my_owner_mutex;

void f()
{
	std::unique_lock<std::mutex> unique_lock_my_owner_mutex {my_owner_mutex, std::defer_lock};

	if (unique_lock_my_owner_mutex.try_lock())
		std::cout << "Acquisition of resource lock in the function." << std::endl;
	else
		std::cout << "The resource lock could not be acquired in the function." << std::endl;

	if (unique_lock_my_owner_mutex.owns_lock())
		std::cout << "The function is locked." << std::endl;
	else
		std::cout << "The function could not be locked." << std::endl;
}

int main()
{
	std::unique_lock<std::mutex> unique_lock_my_owner_mutex {my_owner_mutex, std::defer_lock};

	if (unique_lock_my_owner_mutex.try_lock())
		std::cout << "Acquisition of resource lock in the main." << std::endl;
	else
		std::cout << "The resource lock could not be acquired in the main." << std::endl;

	if (unique_lock_my_owner_mutex.owns_lock())
		std::cout << "The main is locked." << std::endl;
	else
		std::cout << "The main could not be locked." << std::endl;

	return V_ZERO;
}
