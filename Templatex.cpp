#include <iostream>
#include <type_traits>

#define	V_PI	3.1415926
#define	V_TEN	10
#define	V_ZERO	0


template<typename T, typename std::enable_if<std::is_same<T, int>::value>::type* = nullptr>
T process_number(T value)
	{
		std::cout << "Value int:\t[" << value << "]." << std::endl;
		return value;
	}

template<typename T, typename std::enable_if<std::is_same<T, double>::value>::type* = nullptr>
T process_number(T value)
	{
		std::cout << "Value double:\t[" << value << "]." << std::endl;
		return value;
	}


int main()
	{
		process_number(V_TEN);
		process_number(V_PI);

		return V_ZERO;
	}
