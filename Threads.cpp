/* The primary purpose of this program is to perform two autonomous functions
   and assign them to threads, which are like timers that will cause both
   to run simultaneously until their autonomous execution is complete. */

/* Libraries Standards of Work. */
#include <iostream>
#include <thread>

/* Symbolic work constants. */
#define	V_ONE_HUNDRED	100
#define	V_TWO_HUNDRED	200
#define V_ZERO 		0

/* Function to be executed in the first thread. */
const int int_function_one(const int& int_loops, const int& int_delay)
	{
		int counter = V_ZERO;

		for (int int_idx = V_ZERO; int_idx < int_loops; int_idx++)
			{
				std::cout << "#1:\t(" << counter++ << ")." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(int_delay));	//Two hundred millisecond wait.
			}

		return counter;
	}

/* Function to be executed in the second thread. */
const int int_function_two(const int& int_loops, const int& int_delay)
	{
		int counter = V_ZERO;

		for (int int_idx = V_ZERO; int_idx < int_loops; int_idx++)
			{
				std::cout << "#2:\t[" << counter++ << "]." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(int_delay));	//One hundred millisecond wait.
			}

		return counter;
	}

//Main function.
int main()
	{
		std::cout << "Multithreaded testing system in C++." << std::endl;

		/* Create three threads and assign them functions to execute. */
		std::thread thread_one(int_function_one, V_ONE_HUNDRED, V_TWO_HUNDRED);
		std::thread thread_two(int_function_two, V_TWO_HUNDRED, V_ONE_HUNDRED);

		/* Wait for both created threads to finish their execution. */
		thread_one.join();
		thread_two.join();

		return V_ZERO;
	}
