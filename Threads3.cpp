#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> SharedCounter{0};

void IncreaseCounter()
{
	SharedCounter++;
}

void FunctionThread()
{
	for (int idx{}; idx < 10; idx++)
	{
		int previous_value = SharedCounter.fetch_add(1);
		std::cout << "[" << std::this_thread::get_id() << "] : {" << previous_value << "} -> (" << SharedCounter << ")." << std::endl;
	}
}

int main()
{
	std::thread th[10]{};

	std::thread th1(IncreaseCounter);
	std::thread th2(IncreaseCounter);

	th1.join();
	th2.join();

	for (int idx{}; idx < 10; idx++)
		th[idx] = std::thread(IncreaseCounter);

	for (int idx{}; idx < 10; idx++)
		th[idx].join();

	std::thread thx(FunctionThread);
	std::thread thy(FunctionThread);

	thx.join();
	thy.join();

	std::cout << "Final shared value: [" << SharedCounter << "]." << std::endl;

	return 0;
}
