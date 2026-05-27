#include <cstdint>
#include <iostream>

constexpr int V_ONE	{1};

std::int_fast64_t powint(std::int_fast64_t base, std::int_fast64_t exponent)
	{
		std::int_fast64_t result { V_ONE };

		while (exponent)
			{
				if (exponent & V_ONE)
					result *= base;

				exponent >>= V_ONE;
				base *= base;
			}

		return result;
	}

int main()
	{
		std::int_fast64_t base{}, exponent{};
		std::cout << "Integer Exponentiation." << std::endl;

		std::cout << "+ Base: ";
		std::cin >> base;
		std::cout << "+ Exponent: ";
		std::cin >> exponent;

		std::cout << std::endl << "Outcomes." << std::endl;
		std::cout << "+ Base:\t\t(" << base << ")." << std::endl;
		std::cout << "- Exponent:\t[" << exponent << "]." << std::endl;
		std::cout << "* Result:\t{" << powint(base, exponent) << "}." << std::endl;

		return EXIT_SUCCESS;
	}
