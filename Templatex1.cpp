#include <iostream>
#include <type_traits> // Required for std::is_same

/* Symbolic working variables. */
#define	MY_CHAR		'a'
#define	MY_DOUBLE	3.1415926
#define	MY_FLOAT	1.60f
#define MY_INT		256
#define	MY_LONG		65536l
#define	MY_SHORT	16384

#define	V_ZERO	0

//Template function that displays the type of variable sent.
template <typename T>
T process_number(T var)
	{
		std::cout << std::boolalpha << std::endl;
		std::cout << "Type of variable detected:" << std::endl;

		if (std::is_same<T, char>::value)
			{
				std::cout << "[char]\t:\t{" << std::is_same<T, char>::value << "}." << std::endl;
			}
		else if (std::is_same<T, double>::value)
			{
				std::cout << "[double]:\t{" << std::is_same<T, double>::value << "}." << std::endl;
			}
		else if (std::is_same<T, float>::value)
			{
				std::cout << "[float]\t:\t{" << std::is_same<T, float>::value << "}." << std::endl;
				std::cout << "is_floating_point<float>: [" << std::is_floating_point<T>::value << "]." << std::endl;
			}
		else if (std::is_same<T, int>::value)
			{
				std::cout << "[int]\t:\t{" << std::is_same<T, int>::value << "}." << std::endl;
				std::cout << "is_integral<int>: [" << std::is_integral<T>::value << "]." << std::endl;
			}
		else if (std::is_same<T, long>::value)
			{
				std::cout << "[long]\t:\t{" << std::is_same<T, long>::value << "}." << std::endl;
			}
		else if (std::is_same<T, short>::value)
			{
				std::cout << "[short]\t:\t{" << std::is_same<T, short>::value << "}." << std::endl;
			}
		else
			{
				std::cout << std::endl << "The variable type is not one of those specified:" << std::endl;
				std::cout << "(char, double, float, int, long or short)." << std::endl;
			}

		std::cout << "Value:\t\t[" << var << "]." << std::endl;

		return var;
	}


//Main function.
int main()
	{
		/* Preliminary working variables. */
		char my_char = MY_CHAR;
		double my_double = MY_DOUBLE;
		float my_float = MY_FLOAT;
		int my_int = MY_INT;
		long my_long = MY_LONG;
		short my_short = MY_SHORT;

		std::cout << "Variable type detector." << std::endl;

		/* Value corroboration function. */
		process_number(my_char);
		process_number(my_double);
		process_number(my_float);
		process_number(my_int);
		process_number(my_long);
		process_number(my_short);

		return V_ZERO;
	}
