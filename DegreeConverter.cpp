#include <iostream>
#include <sstream>

//Working symbolic variables.
#define V_THIRTY_TWO		32.0
#define	V_THREE			3
#define	V_TWO			2
#define	V_ONE			1
#define	V_ONE_POINT_EIGHT	1.8
#define V_ZERO  		0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int int_option = V_ZERO;
		double dbl_result = V_ZERO;
		double dbl_value = V_ZERO;

		/* Receiving the values ​​as strings of characters. */
		std::string str_option = {};
		std::string str_value {};

		/* Main loop that displays the conversion menu. */
		while (int_option != V_THREE)
			{
				std::cout << std::endl << "Temperature Conversion." << std::endl;
				std::cout << "[1]. Celsius to Fahrenheit." << std::endl;
				std::cout << "[2]. Fahrenheit to Celsius." << std::endl;
				std::cout << "[3]. Quit this program." << std::endl;
				std::cout << "Option: ";
				std::getline(std::cin >> std::ws, str_option);
				std::stringstream(str_option) >> int_option;

				std::cout << "Option captured: [" << int_option << "]. OK!" << std::endl;

				/* Case selection based on the chosen option. */
				switch (int_option)
					{
						case V_ONE:
							/* Capture the value in degrees Celsius. */
							std::cout << std::endl << "Enter a value in degrees Celsius: ";
							std::getline(std::cin >> std::ws, str_value);
							std::stringstream(str_value) >> dbl_value;

							/* Formula to convert from 'Celsius' to 'Fahrenheit'. */
							dbl_result = (V_ONE_POINT_EIGHT * dbl_value) + V_THIRTY_TWO;

							/* Outgoing messages. */
							std::cout << std::endl << "Calculation results' degrees." << std::endl;
							std::cout << "+ Celsius:\t[" << dbl_value << "]." << std::endl;
							std::cout << "* Fahrenheit:\t{" << dbl_result << "}." << std::endl;
							break;

						case V_TWO:
							/* Capture the value in degrees Fahrenheit. */
							std::cout << std::endl << "Enter a value in degrees Fahrenheit: ";
							std::getline(std::cin >> std::ws, str_value);
							std::stringstream(str_value) >> dbl_value;

							/* Formula to convert from 'Fahrenheit' to 'Celsius'. */
							dbl_result = (dbl_value - V_THIRTY_TWO) / V_ONE_POINT_EIGHT;

							/* Outgoing messages. */
							std::cout << std::endl << "Calculation results' degrees." << std::endl;
							std::cout << "+ Fahrenheit:\t[" << dbl_value << "]." << std::endl;
							std::cout << "* Celsius:\t{" << dbl_result << "}." << std::endl;
							break;

						case V_THREE:
							std::cout << std::endl << "Leaving this program..." << std::endl;
							break;

						default:
							std::cout << std::endl << "Invalid option: [" << int_option << "]!" << std::endl;
							break;

					}
			}

		return V_ZERO;
	}
