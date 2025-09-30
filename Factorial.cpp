#include <iostream>
#include <functional>

#define V_MINUS_ONE -1
#define V_ONE       1
#define V_ZERO      0

int main()
	{
		size_t number = V_ZERO, spins = V_ZERO;

		auto factorial = [&spins](auto&& one_self, const size_t& number) -> size_t
			{
				spins++; return (number < V_ONE) ? V_ONE : number * one_self(one_self, number + V_MINUS_ONE);
			};

		std::function<size_t(size_t)> factorial_two = [&factorial_two](const size_t& number) -> size_t
			{return (number < V_ONE) ? V_ONE : number * factorial_two(number + V_MINUS_ONE);};

		std::cout << "Anonymous recursive factorial function." << std::endl;
		std::cout << "Enter the number to calculate: ";
		std::cin >> number;

		std::cout << std::endl << "Outcomes." << std::endl;
		std::cout << "+ Number:\t[" << number << "]." << std::endl;
		std::cout << "+ Factorial:\t[" << factorial(factorial, number) << "] = [" << factorial_two(number) << "]." << std::endl;
		std::cout << "* Spins:\t[" << spins << "]." << std::endl;

		return V_ZERO;
	}
