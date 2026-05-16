#include <atomic>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

constexpr int V_FOURTY_TWO	{42};
constexpr int V_TEN		{10};
constexpr int V_TWENTY		{20};
constexpr int V_ONE		{1};
constexpr int V_ZERO		{};

std::atomic<int*> ptr{};

void sum()
{
	int *q = ptr.load();
	(*q)++;
	ptr.store(q + V_ONE);
}

int main()
{
	std::atomic<std::shared_ptr<int>> ptr_x {};
	ptr_x.store(std::make_shared<int>(V_FOURTY_TWO));
	std::shared_ptr<int> p = ptr_x.load();
	std::cout << "Value: [" << *p << "]." << std::endl;

	std::vector<int> my_vector(V_TWENTY, V_ONE);

	ptr.store(&my_vector[V_ZERO]);

	std::vector<std::thread> threads;
	for (int i{}; i < V_TEN; i++)
		threads.emplace_back(sum);

	for (auto& t : threads)
		t.join();

	for (int i{}; i < my_vector.size(); i++)
		std::cout << "[" << my_vector[i] << "]." << '\t';

	std::cout << std::endl;

	return V_ZERO;
}
