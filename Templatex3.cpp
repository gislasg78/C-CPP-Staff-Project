#include <iostream>

#define	V_ZERO	0

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
auto maximum(T value)
{return value;}

template <Numeric T>
auto maximum(T x, T y)
{return (x > y) ? x : y;}

template <Numeric T, typename... Arguments>
auto maximum(T value, Arguments... arguments)
{return maximum(value, maximum(arguments...));}


template <Numeric T>
auto minimum(T value)
{return value;}

template <Numeric T>
auto minimum(T x, T y)
{return (x < y) ? x : y;}

template <Numeric T, typename... Arguments>
auto minimum(T value, Arguments... arguments)
{return minimum(value, minimum(arguments...));}


template <typename T, typename U>
	requires (std::integral<T> || std::floating_point<T>) &&
		 (std::integral<U> || std::floating_point<U>)
auto summatory(T x, U y)
{return (x + y);}

template <typename T, typename... Arguments>
	requires std::integral<T> || std::floating_point<T>
auto summatory(T value, Arguments... arguments)
{
	if constexpr (sizeof...(arguments) == V_ZERO)
		return value;
	else
		return summatory(value, summatory(arguments...));
}

int main()
{
	std::cout << "Variadic Templates Exercise." << std::endl;

	std::cout << std::endl << "Summatories." << std::endl;
	std::cout << "+ Max: (" << maximum(1, 3, 5, 7, 9) << ")." << std::endl;
	std::cout << "+ Min: (" << minimum(1, 3, 5, 7, 9) << ")." << std::endl;
	std::cout << "+ Sum: (" << summatory(1, 3, 5, 7, 9) << ")." << std::endl << std::endl;

	std::cout << "+ Max: [" << maximum(2, 4, 6, 8, 10) << "]." << std::endl;
	std::cout << "+ Min: [" << minimum(2, 4, 6, 8, 10) << "]." << std::endl;
	std::cout << "+ Sum: [" << summatory(2, 4, 6, 8, 10) << "]." << std::endl << std::endl;

	std::cout << "+ Max: {" << maximum(3, 6, 9, 12, 15) << "}." << std::endl;
	std::cout << "+ Min: {" << minimum(3, 6, 9, 12, 15) << "}." << std::endl;
	std::cout << "+ Sum: {" << summatory(3, 6, 9, 12, 15) << "}." << std::endl;

	std::cout << "\nDone!\n";
	std::cout << "This program has ended.\n";

	return EXIT_SUCCESS;
}
