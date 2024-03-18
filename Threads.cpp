#include <iostream>
#include <thread>

#define V_ZERO  0

//Function to be executed in the first thread.
void func1()
	{
		for (int int_idx = V_ZERO; int_idx < 200; int_idx++)
			{
				std::cout << "Thread #1: [" << int_idx << "]." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));    //One hundred millisecond wait.
			}
	}

//Function to be executed in the second thread.
void func2()
	{
		for (int int_idx = V_ZERO; int_idx < 100; int_idx++)
			{
				std::cout << "Thread #2: [" << int_idx << "]." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(200));    //Two hundred millisecond wait.
			}
	}

int main()
	{
		//Create two threads and assign them functions to execute.
		std::thread thread1(func1);
		std::thread thread2(func2);

		//Wait for both created threads to finish their execution.
		thread1.join();
		thread2.join();

		return V_ZERO;
	}
