// enable_if example: two ways of using enable_if.
#include <iostream>
#include <type_traits>

/* Symbolic working variables. */
#define	V_FIVE	5
#define	V_SEVEN	7
#define	V_THREE	3
#define V_TWO   2
#define V_ZERO  0

// 1. The return type (bool) is only valid if T is an integral type.
template <typename T>
typename std::enable_if<std::is_same<T, int>::value, bool>::type
is_odd (T var)		{return bool(var % V_TWO);}

// 2. The second template argument syntax is only valid if T is an integral type.
template <typename T, typename = typename std::enable_if<std::is_same<T, int>::value>::type>
bool is_even (T var)	{return !bool(var % V_TWO);}

// 3. The first syntax is used but with the std::is_same clause.
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_prime (T var)
	{
		return (((var == V_TWO) || (var == V_THREE) || (var == V_FIVE) || (var == V_SEVEN)) ||
			((var % V_TWO) && (var % V_THREE) && (var % V_FIVE) && (var % V_SEVEN)));
	}

//4. Another syntax for calling template conditionals.
template<typename T, typename std::enable_if<std::is_same<T, int>::value>::type* = nullptr>
T process_number(T var)	{return var;}

//Main function.
int main()
	{
		int value = V_ZERO;	 // Code does not compile if type of 'i' var is not integral.

		std::cout << "Conditional templates." << std::endl;
		std::cout << "Enter a number: ";
		std::cin >> value;

		std::cout << std::boolalpha;
		std::cout << std::endl << "Outcomes." << std::endl;
		std::cout << "+ Is even?  : {" << is_even(value) << "}." << std::endl;
		std::cout << "+ Is odd?   : {" << is_odd(value) << "}." << std::endl;
		std::cout << "+ Is prime? : {" << is_prime(value) << "}." << std::endl;
		std::cout << "+ Value int : [" << process_number(value) << "]." << std::endl;

		return V_ZERO;
	}
