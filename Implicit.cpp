#include <iostream>

template <typename T>
constexpr T V_ZERO = T(0);

template <typename T>
constexpr T V_ONE = T{1};

template <typename T>
constexpr T V_MINUS_ONE = T{-1};

int main()
{
	std::cout << "Implicit comparing types." << std::endl;

	signed int x{V_MINUS_ONE<signed int>};
	unsigned int y {V_ONE<unsigned int>};

	if (x > static_cast<int>(y))
		std::cout << "(" << x << ") > (" << y << ")?" << std::endl;
	else
		std::cout << "[" << x << "] <= [" << y << "]." << std::endl;

	return V_ZERO<int>;
}
