#include <functional>
#include <iostream>

template <typename T>
constexpr T V_ONE   {static_cast<T>(1)};
template <typename T>
constexpr T V_ZERO  {static_cast<T>(0)};

template <typename T>
std::function<T(T)> fn_reciprocal_variable {[](const T& x) -> T {return (x) ? (V_ONE<T> / x) : V_ZERO<T>;}};

template <typename T>
std::function<T(T)> fn_reciprocal_function()
{
	return [](const T& x) -> T
	{
		return x ? V_ONE<T> / x : V_ZERO<T>;
	};
}

int main()
{
	double x{};

	std::cout << "Reciprocal Function." << std::endl;
	std::cout << "> Enter a number: ";
	std::cin >> x;

	std::cout << std::endl << "Results." << std::endl;
	std::cout << "+ Number:\t[" << x << "]." << std::endl;
	std::cout << "+ Reciprocal:\t{" << fn_reciprocal_variable<double>(x) << "}." << std::endl;
	std::cout << "+ Reciprocal:\t{" << fn_reciprocal_function<double>()(x) << "}." << std::endl;

	return EXIT_SUCCESS;
}
