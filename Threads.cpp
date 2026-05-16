/* The primary purpose of this program is to perform two autonomous functions
   and assign them to threads, which are like timers that will cause both
   to run simultaneously until their autonomous execution is complete. */

/* Libraries Standards of Work. */
#include <iostream>
#include <thread>

/* Symbolic work constants. */
constexpr char	CARRIAGE_RETURN	{'\n'};

constexpr int	V_ONE_HUNDRED	{100};
constexpr int	V_TWO_HUNDRED	{200};
constexpr int	V_ONE		{1};
constexpr int	V_TWO		{2};
constexpr int	V_ZERO		{};

/* Function to be executed in the thread. */
const int int_function_count(const int& int_id, const int& int_loops, const int& int_delay, const char& chr_left, const char& chr_right)
	{
		int int_counter {V_ZERO};

		for (int int_idx {V_ZERO}; int_idx < int_loops; int_idx++)
			{
				std::cout << "#" << int_id << ":\t" << chr_left << int_counter++ << chr_right << '\x2e' << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(int_delay));
			}

		return int_counter;
	}

//Main function.
int main()
	{
		/* Initial header message. */
		std::cout << "Multithreaded testing system in C++." << std::endl;

		/* Create three threads and assign them functions to execute. */
		std::thread thread_one(int_function_count, V_ONE, V_ONE_HUNDRED, V_TWO_HUNDRED, '\x28', '\x29');
		std::thread thread_two(int_function_count, V_TWO, V_TWO_HUNDRED, V_ONE_HUNDRED, '\x5b', '\x5d');

		/* Wait for both created threads to finish their execution. */
		thread_one.join();
		thread_two.join();

		std::cout << CARRIAGE_RETURN << "Done!" << CARRIAGE_RETURN;
		std::cout << "This program has ended." << CARRIAGE_RETURN;

		return V_ZERO;
	}
