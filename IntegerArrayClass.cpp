/* This program exemplifies overloading the '[]' operator in a C++ class. */

/* Standard work libraries. */
#include <iostream>
#include <limits>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define	V_ONE		1
#define	V_TEN		10
#define V_ZERO		0

/* A class that has an entire array of ten integers. */
class TenInt
	{
		private:
			int values[V_TEN] = {V_ZERO};

		public:
			static void enter_a_pause(const std::string& str_Message)
				{
					std::cout << str_Message;
					std::cin.clear();
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
				}

			int & operator [] (const int & index)
				{
					if (index >= V_ZERO && index < V_TEN)
						{
							std::cout << std::endl << "Accessing index #: [" << index << "] of: [" << V_TEN - V_ONE << "]." << std::endl;
							std::cout << "Current recovered value: [" << values[index] << "]." << std::endl << std::endl;
						}
					else
						std::cout << std::endl << "Error! The index to be queried is outside the range between: [" << V_ZERO << "] and: [" << V_TEN << "]." << std::endl;

					return ((index >= V_ZERO && index < V_TEN) ? values[index] : values[V_ZERO]);
				}
	};

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;

		/* Instantiation of the base class. */
		TenInt ten;

		/* Preliminary header messages. */
		std::cout << "Example of overloading the '[]' operator in C++." << std::endl;
		std::cout << "Enter ten integer values within a class." << std::endl;

		/* Loop that captures and loads the values ​​into the class. */
		counter = V_ZERO;
		for (int idx = V_ZERO; idx < V_TEN; idx++)
			{
				int response = V_ZERO;

				printf("Insert the value #: [%d] from: [%d]: ", counter++ + V_ONE, V_TEN);
				scanf("%d", &response);

				ten[idx] = response;
			}
		std::cout << std::endl << "[" << counter << "] Output results generated." << std::endl;
		ten.enter_a_pause("Press the ENTER key to continue...");

		/* Loop that displays each value loaded into the class in its internal array. */
		counter = V_ZERO;
		for (int idx = V_ZERO; idx < V_TEN; idx++)
			{
				int outcome = ten[idx];

				std::cout << "Content captured from the index: [" << counter++ + V_ONE << "] of: [" << V_TEN << "] is: [" << outcome << "]." << std::endl;
				ten.enter_a_pause("Press the ENTER key to continue...");
			}
		std::cout << std::endl << "[" << counter << "] Output results generated." << std::endl;
		TenInt::enter_a_pause("Press the ENTER key to continue...");

		/* Notices of termination of this program. */
		std::cout << std::endl;
		std::cout << "Done!" << '\n';
		std::cout << "This program has ended.\n";

		return V_ZERO;
	}
