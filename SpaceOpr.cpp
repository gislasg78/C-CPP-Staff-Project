#include <compare>
#include <iostream>

#define V_ZERO  0

int main()
	{
		int l_value = V_ZERO, r_value = V_ZERO;
		std::cout << "Spaceship comparator." << std::endl;

		std::cout << "First  value: ";
		std::cin >> l_value;

		std::cout << "Second value: ";
		std::cin >> r_value;

		auto result = (l_value <=> r_value);

		if (result < V_ZERO)
			std::cout << std::endl << "(" << l_value << " < " << r_value << ")" << std::endl;
		else if (result > V_ZERO)
			std::cout << std::endl << "(" << l_value << " > " << r_value << ")" << std::endl;
		else if (result == V_ZERO)
			std::cout << std::endl << "(" << l_value << " = " << r_value << ")" << std::endl;

		return V_ZERO;
	}
