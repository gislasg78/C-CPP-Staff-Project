/* This program obtains the current date and time
   and generates a series of tickets with random numbers
   for a drawing. */

/* Standard work libraries. */
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

/* Symbolic work constants. */
#define	V_ONE	1
#define V_ZERO  0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int count = V_ZERO, counter = V_ZERO, counting = V_ZERO;
		int maximum = V_ZERO, minimum = V_ZERO;
		int numbers = V_ZERO, tickets = V_ZERO;
		std::vector<std::set<int>> vector_of_tickets;

		/* Initial presentation headers. */
		std::cout << "Obtaining the current date and time of the operating system." << std::endl;
		std::cout << "Number of tickets: ";
		std::cin >> tickets;

		std::cout << "Number of numbers per ticket: ";
		std::cin >> numbers;

		std::cout << "Minimum value: ";
		std::cin >> minimum;

		std::cout << "Maximum value: ";
		std::cin >> maximum;

		/* Choose between the minimum and maximum value. */
		maximum = std::max(minimum, maximum);
		minimum = std::min(minimum, maximum);

		/* Get the current time from the system clock. */
		auto now = std::chrono::system_clock::now();

		/* Convert to time_t for use with C-style functions. */
		std::time_t time_now = std::chrono::system_clock::to_time_t(now);

		/* Convert time_t to tm (local time). */
		std::tm local_tm = *std::localtime(&time_now);

		/* Format the time as a string. */
		std::cout << std::endl << "Current date and time information." << std::endl;
		std::cout << "Current time: "  << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << std::endl;
		std::cout << std::put_time(&local_tm, "[%A, %B %d, %Y] - [%H:%M:%S].") << std::endl;

		/* Random number generator. */
		time_t t_tm_seconds = V_ZERO;
		time(&t_tm_seconds);
		srand(t_tm_seconds);

		/* Load the numbers that each ticket has. */
		for (int idx = V_ZERO; idx < tickets; idx++)
			{
				std::set<int> set_by_ticket;

				for (int ind = V_ZERO; ind < numbers; ind++)
					{
						set_by_ticket.insert(rand());
					}

				vector_of_tickets.push_back(set_by_ticket);
			}

		/* List of the random numbers created. */
		counter = V_ZERO;
		std::cout << std::endl << "List of random numbers obtained by ticket." << std::endl;
		for (const std::set<int>& set_by_ticket : vector_of_tickets)
			{
				std::cout << "Ticket #: [" << counter++ + V_ONE << "] of: [" << tickets << "]." << std::endl;

				count = V_ZERO;
				for (const int& number_by_ticket : set_by_ticket)
					{
						int random_in_range = minimum + (number_by_ticket % (maximum - minimum + V_ONE));

						counting++;
						std::cout << "#: (" << count++ + V_ONE << ")\t=\t[" << number_by_ticket << "]\t=\t{" << random_in_range << "}." << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << counting << "] Output generated results." << std::endl;

		return V_ZERO;
	}
