#include <iostream>
#include <type_traits> // Required for std::is_same

#define	MY_CHAR		'a'
#define	MY_DOUBLE	3.1415926
#define	MY_FLOAT	1.60f
#define MY_INT		256
#define	MY_LONG		65536l
#define	MY_SHORT	16384

#define	V_ZERO	0

//Template function that displays the type of variable sent.
template <typename T>
void checkVariableType(T var)
	{
		std::cout << "Type of variable detected: [";

		if (std::is_same<T, char>::value)
			{
				std::cout << "char";
			}
		else if (std::is_same<T, double>::value)
			{
				std::cout << "double";
			}
		else if (std::is_same<T, float>::value)
			{
				std::cout << "float";
			}
		else if (std::is_same<T, int>::value)
			{
				std::cout << "int";
			}
		else if (std::is_same<T, long>::value)
			{
				std::cout << "long";
			}
		else if (std::is_same<T, short>::value)
			{
				std::cout << "short";
			}
		else
			{
				std::cout << std::endl << "The variable type is not one of those specified:" << std::endl;
				std::cout << "(char, double, float, int, long or short)." << std::endl;
			}

		std::cout << "]." << std::endl;
		std::cout << "Value: [" << var << "]" << std::endl;
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
		checkVariableType(my_char);
		checkVariableType(my_double);
		checkVariableType(my_float);
		checkVariableType(my_int);
		checkVariableType(my_long);
		checkVariableType(my_short);

		return V_ZERO;
	}
