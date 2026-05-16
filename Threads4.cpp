#include <atomic>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

std::atomic<int*> ptr{};

void sum()
{
	int *q = ptr.load();
	(*q)++;
	ptr.store(q + 1);
}

int main()
{
	std::atomic<std::shared_ptr<int>> ptr_x;
	ptr_x.store(std::make_shared<int>(42));
	std::shared_ptr<int> p = ptr_x.load();
	std::cout << "[" << *p << "]." << std::endl;

	std::vector<int> my_vector(20, 1);

	ptr.store(&my_vector[0]);

	std::vector<std::thread> threads;
	for (int i{}; i < 10; i++)
		threads.emplace_back(sum);

	for (auto& t : threads)
		t.join();

	for (int i{}; i < my_vector.size(); i++)
		std::cout << "[" << my_vector[i] << "]." << '\t';

	std::cout << std::endl;

	return 0;
}
