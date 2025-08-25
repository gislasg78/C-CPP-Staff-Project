// enable_if example: two ways of using enable_if.
#include <iostream>
#include <type_traits>

/* Symbolic working variables. */
#define	V_AUREUM	1.6180339f
#define	V_PI		3.1415926

#define	NULL_CHARACTER	'\0'

#define	V_FIVE		5
#define	V_SEVEN		7
#define	V_THREE		3
#define V_TWO   	2
#define V_ZERO  	0

// 1. The first template argument syntax is only valid if T is an integral type.
template <typename T, typename = typename std::enable_if<std::is_same<T, int>::value>::type>
bool is_even (T var)	{return !bool(var % V_TWO);}

// 2. The second template argument syntax is the return type (bool) is only valid if T is an integral type.
template <typename T>
typename std::enable_if<std::is_same<T, int>::value, bool>::type
is_odd (T var)		{return bool(var % V_TWO);}

// 3. The second syntax clause is used right now.
template <typename T>
typename std::enable_if<std::is_same<T, int>::value, bool>::type
is_prime (T var)
	{
		return (((var == V_TWO) || (var == V_THREE) || (var == V_FIVE) || (var == V_SEVEN)) ||
			((var % V_TWO) && (var % V_THREE) && (var % V_FIVE) && (var % V_SEVEN)));
	}

// 4. The second syntax is used but with the 'std::is_floating_point' clause.
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
process (T var)
	{
		std::cout << std::endl << "Generic variable processing." << std::endl;
		std::cout << "[Floating point variables]." << std::endl;
		std::cout << "+ Type of variable\t:\t[" << typeid(var).name() << "]." << std::endl;
		std::cout << "+ Value in process\t:\t[" << var << "]." << std::endl;
		return var;
	}

// 5. The second syntax is used but with the 'std::is_integral' clause.
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
process (T var)
	{
		std::cout << std::endl << "Generic variable processing." << std::endl;
		std::cout << "[Integer variables]." << std::endl;
		std::cout << "+ Type of variable\t:\t[" << typeid(var).name() << "]." << std::endl;
		std::cout << "+ Value in process\t:\t[" << var << "]." << std::endl;
		return var;
	}

// 6. Another syntax for calling template conditionals.
template <typename T, typename std::enable_if<std::is_same<T, int>::value>::type* = nullptr>
T process_number (T var)
	{
		std::cout << "* Value integer\t\t:\t[" << var << "]." << std::endl;
		return var;
	}

// 7. Another syntax to overload the same function but with template-based conditionals.
template <typename T, typename std::enable_if<std::is_same<T, double>::value>::type* = nullptr>
T process_number(T var)
	{
		std::cout << "* Value double\t\t:\t[" << var << "]." << std::endl;
		return var;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char chr_value = NULL_CHARACTER;
		double dbl_value = V_PI;
		float flt_value = V_AUREUM;
		int int_value = V_ZERO;	// Code does not compile if type of 'int_value' var is not integral.
		long lng_value = V_ZERO;
		short shrt_value = V_ZERO;

		/* Main headings start. */
		std::cout << "Conditional templates." << std::endl;
		std::cout << "Enter a char    value : ";
		std::cin >> chr_value;
		std::cout << "Enter a double  number: ";
		std::cin >> dbl_value;
		std::cout << "Enter a float   number: ";
		std::cin >> flt_value;
		std::cout << "Enter a integer number: ";
		std::cin >> int_value;
		std::cout << "Enter a long    number: ";
		std::cin >> lng_value;
		std::cout << "Enter a short   number: ";
		std::cin >> shrt_value;

		/* Calls to template functions of type 'integer' only. */
		std::cout << std::boolalpha;
		std::cout << std::endl << "Outcomes." << std::endl;
		std::cout << "+ Value integer\t\t:\t[" << int_value << "]." << std::endl;
		std::cout << "+ Is even?\t\t:\t{" << is_even(int_value) << "}." << std::endl;
		std::cout << "+ Is odd?\t\t:\t{" << is_odd(int_value) << "}." << std::endl;
		std::cout << "+ Is prime?\t\t:\t{" << is_prime(int_value) << "}." << std::endl;

		/* Calls to template functions of exclusively 'integer' or 'double precision' types. */
		std::cout << std::endl << "Results." << std::endl;
		process_number(int_value);
		process_number(dbl_value);

		/* Calls to template functions of exclusively 'integer', 'single precision' or 'double precision' types. */
		process(chr_value);
		process(dbl_value);
		process(flt_value);
		process(int_value);
		process(lng_value);
		process(shrt_value);

		return V_ZERO;
	}
