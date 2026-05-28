#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Greater than 'x', 'y' and 'z' values. */
/*
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
*/
template <typename T, typename U, typename V>
auto greater(T x, U y, V z)
	{
		using Common_Type = std::common_type_t<T, U, V>;

		Common_Type major = static_cast<Common_Type>(x);

		if (static_cast<Common_Type>(y) > major)
			major = static_cast<Common_Type>(y);

		if (static_cast<Common_Type>(z) > major)
			major = static_cast<Common_Type>(z);

		return major;
	}

/* Improvised 'Template' type function to capture a given string of characters. */
template <typename T>
const T& capture_a_value(T* const ptr_value)
	{
		if (ptr_value)
			{
				std::string str_value {std::string()};

				if (std::getline(std::cin >> std::ws, str_value))
					{
						str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
						std::stringstream(str_value) >> *ptr_value;

						std::cout << "+ Characters:\t\t[" << std::cin.gcount() << "]." << std::endl;
						std::cout << "+ Value entered:\t[" << *ptr_value << "]. OK!" << std::endl << std::endl;
					}
				else
					{
						std::cerr << std::endl << std::endl << "Incorrect input information." << std::endl;

						if (std::cin.eof())
							std::cerr << "* EOF detected! *" << std::endl;

						if (std::cin.fail())
							std::cerr << "* Keyboard error detected! *" << std::endl;

						char c{};
						while (std::cin.get(c)) {}

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);

						std::cerr << "> Throwing overflow exception..." << std::endl << std::endl;
						throw std::overflow_error("The information coming from the keyboard input is overloaded.");
					}
			}
		else
			{
				std::cerr << std::endl << "A valid memory address was not provided." << std::endl << std::endl;
				throw std::runtime_error("The memory location must be valid and not a null pointer.");
			}

		return (ptr_value) ? *ptr_value : V_ZERO<T>;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int x {V_ZERO<int>};
		float y {V_ZERO<float>};
		double z = V_ZERO<double>;

		std::cout << "Choosing the largest number from three values." << std::endl;

		/* Capturing values. */
		std::cout << "Enter the value of 'x': ";
		try {x = capture_a_value<int>(&x);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		std::cout << "Enter the value of 'y': ";
		try {y = capture_a_value<float>(&y);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		std::cout << "Enter the value of 'z': ";
		try {z = capture_a_value<double>(&z);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		std::cout << std::endl << "Values ​​entered." << std::endl;
		std::cout << "(x = [" << x << "], y = [" << y << "], z = [" << z << "])." << std::endl;
		std::cout << "The largest value is: [" << greater(x, y, z) << "]." << std::endl;

		return EXIT_SUCCESS;
	}
