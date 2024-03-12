#include <iostream>

#define V_THIRTY_TWO		32.0
#define	V_TWO			2
#define	V_ONE			1
#define	V_ONE_POINT_EIGHT	1.8
#define V_ZERO  		0

int main()
	{
		int int_option = V_ZERO;
		double dbl_result = V_ZERO;
		double dbl_value = V_ZERO;

		std::cout << "Temperature Conversion." << std::endl;
		std::cout << "[1]. Celsius to Farenheit." << std::endl;
		std::cout << "[2]. Farenheit to Celsius." << std::endl;
		std::cout << "Option: ";
		std::cin >> int_option;

		switch (int_option)
			{
				case V_ONE:
					std::cout << std::endl << "Enter a value in degrees Celsius: ";
					std::cin >> dbl_value;

					dbl_result = (V_ONE_POINT_EIGHT * dbl_value) + V_THIRTY_TWO;
					std::cout << std::endl << "[" << dbl_value << "] Celsius = [" << dbl_result << "] Farenheit." << std::endl;
					break;

				case V_TWO:
					std::cout << std::endl << "Enter a value in degrees Fahrenheit: ";
					std::cin >> dbl_value;

					dbl_result = (dbl_value - V_THIRTY_TWO) / V_ONE_POINT_EIGHT;
					std::cout << std::endl << "[" << dbl_value << "] Farenheit = [" << dbl_result << "] Celsius." << std::endl;
					break;

				default:
					std::cout << std::endl << "Invalid option: [" << int_option << "]!" << std::endl;
					break;
			}

		return V_ZERO;
	}
