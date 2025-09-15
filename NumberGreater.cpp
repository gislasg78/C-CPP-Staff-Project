#include <iostream>

#define	V_ZERO	0

/* Greater than 'x', 'y' and 'z' values. */
template <typename T, typename U, typename V>
auto greater(T x, U y, V z)
	{
		auto major = V_ZERO;

		if (x > y)
			if (x > z)
				major = x;
			else
				major = y;
		else
			if (y > z)
				major = y;
			else
				major = z;

		return major;
	}

//Main function.
int main()
	{
		int x = V_ZERO, y = V_ZERO, z = V_ZERO;

		std::cout << "Choosing the largest number from three values." << std::endl;
		std::cout << "Enter the value of 'x': ";
		std::cin >> x;
		std::cout << "Enter the value of 'y': ";
		std::cin >> y;
		std::cout << "Enter the value of 'z': ";
		std::cin >> z;

		std::cout << std::endl << "Values ​​entered." << std::endl;
		std::cout << "(x = [" << x << "], y = [" << y << "], z = [" << z << "])." << std::endl;
		std::cout << "The largest value is: [" << greater(x, y, z) << "]." << std::endl;

		return V_ZERO;
	}
