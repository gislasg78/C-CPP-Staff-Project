/* This program converts from degrees Celsius
   to degrees Fahrenheit and Kelvin and vice versa. */

/* Standard work libraries. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>

/* Unique character constants. */
#define V_DECIMAL_POINT		'\x2e'
#define V_PLUS_SIGN		'\x2b'
#define V_MINUS_SIGN		'\x2d'

/* Working symbolic variables. */
#define	V_273_15		273.15
#define V_THIRTY_TWO		32.0
#define	V_ONE			1
#define	V_ONE_POINT_EIGHT	1.8
#define V_ZERO  		0

/* Determine the type of conversion to be performed. */
enum class Converter : int {Celsius_to_Fahrenheit, Fahrenheit_to_Celsius, Celsius_to_Kelvin, Kelvin_to_Celsius, Exit_Converter} cnv_myConverter;

/* Function to display the values ​​obtained from the calculations. */
template <typename T>
auto getCalculations(const Converter& cnv_Conv, const std::function<T(T)> fn_MyFunction, const T *const t_degrees, T *const t_result)
	{
		/* Valid memory addresses. */
		if (t_degrees && t_result)
			{
				/* The function that has been sent as an argument for the calculation is executed. */
				std::cout << std::endl;
				std::cout << "+===+====+===+====+===+====+===+" << std::endl;
				std::cout << "| Calculation results' degrees.|" << std::endl;
				std::cout << "+===+====+===+====+===+====+===+" << std::endl;

				/* Execute the function passed as an argument. */
				*t_result = fn_MyFunction(*t_degrees);

				/* Determine the type of conversion to be performed. */
				switch(cnv_Conv)
					{
						case Converter::Celsius_to_Fahrenheit:
							std::cout << "| + Celsius:\t[" << *t_degrees << "]." << std::endl;
							std::cout << "| * Fahrenheit:\t[" << *t_result << "]." << std::endl;
							break;

						case Converter::Fahrenheit_to_Celsius:
							std::cout << "| + Fahrenheit:\t[" << *t_degrees << "]." << std::endl;
							std::cout << "| * Celsius:\t[" << *t_result << "]." << std::endl;
							break;

						case Converter::Celsius_to_Kelvin:
							std::cout << "| + Celsius:\t[" << *t_degrees << "]." << std::endl;
							std::cout << "| * Kelvin:\t[" << *t_result << "]." << std::endl;
							break;

						case Converter::Kelvin_to_Celsius:
							std::cout << "| + Kelvin:\t[" << *t_degrees << "]." << std::endl;
							std::cout << "| * Celsius:\t[" << *t_result << "]." << std::endl;
							break;

						case Converter::Exit_Converter:
							std::cout << std::endl << "Quitting this program..." << std::endl;
							break;

						default:
							std::cout << "Invalid conversion." << std::endl;
							break;
					}

				std::cout << "+===+====+===+====+===+====+===+" << std::endl << std::endl;
			}
		else
			std::cerr << std::endl << "A valid memory address was not provided: [" << t_degrees << "] : [" << t_result << "]." << std::endl;

		return *t_result;
	}

/* Function to obtain a valid numeric value according to the type. */
template <typename T>
auto getData(const std::string& str_Message, T *const ptr_value)
	{
		std::cout << str_Message;

		if (ptr_value)
			{
				/* Function to validate that the type is numeric. */
				std::function<bool(const std::string&)> IsNumeric = [](const std::string& str_value)
					{
						if (str_value.empty()) return false;

						int plus_sign_count = V_ZERO, minus_sign_count = V_ZERO, decimal_point_count = V_ZERO;

						return std::all_of(str_value.begin(), str_value.end(), [&](const unsigned char& c)
							{
								switch (c)
									{
										case V_PLUS_SIGN:
											plus_sign_count++;
											return plus_sign_count <= V_ONE;
											break;

										case V_MINUS_SIGN:
											minus_sign_count++;
											return minus_sign_count <= V_ONE;
											break;

										case V_DECIMAL_POINT:
											decimal_point_count++;
											return decimal_point_count <= V_ONE;
										break;
									}

								return std::isdigit(c) || c == V_PLUS_SIGN || c == V_MINUS_SIGN || c == V_DECIMAL_POINT;
							});
					};

				/* Receiving the value ​​as a string of characters. */
				std::string str_value {};
				std::getline(std::cin >> std::ws, str_value);
				str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());

				/* Validate if the character string is numeric. */
				if (IsNumeric(str_value))
					std::cout << std::endl << "There is a valid numeric value." << std::endl;
				else
					std::cout << std::endl << "There are invalid alphanumeric characters." << std::endl;

				/* Convert the string to a valid and workable value. */
				std::stringstream(str_value) >> *ptr_value;

				std::cout << "Value entered:\t[" << *ptr_value << "]. OK!" << std::endl;
			}
		else
			std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

		return *ptr_value;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int int_option = V_ZERO;
		double dbl_degrees = V_ZERO;
		double dbl_result = V_ZERO;

		/* Anonymous function to convert from Celsius degrees to Fahrenheit. */
		std::function<double(double)> fn_celsius_to_fahrenheit = [&](const double& dbl_degrees) -> double
			{return ((V_ONE_POINT_EIGHT * dbl_degrees) + V_THIRTY_TWO);};

		/* Anonymous function to convert from Fahrenheit degrees to Celsius. */
		std::function<double(double)> fn_fahrenheit_to_celsius = [&](const double& dbl_degrees) -> double
			{return ((dbl_degrees - V_THIRTY_TWO) / V_ONE_POINT_EIGHT);};

		/* Anonymous function to convert from Celsius degrees to Kelvin. */
		std::function<double(double)> fn_celsius_to_kelvin = [&](const double& dbl_degrees) -> double
			{return (dbl_degrees + V_273_15);};

		/* Anonymous function to convert from Celsius degrees to Kelvin. */
		std::function<double(double)> fn_kelvin_to_celsius = [&](const double& dbl_degrees) -> double
			{return (dbl_degrees - V_273_15);};

		/* Main loop that displays the conversion menu. */
		while (cnv_myConverter != Converter::Exit_Converter)
			{
				/* Main menu header messages. */
				std::cout << "+===+====+===+====+===+====+===+" << std::endl;
				std::cout << "|    Temperature Conversion.   |" << std::endl;
				std::cout << "+===+====+===+====+===+====+===+" << std::endl;
				std::cout << "| [1]. Celsius to Fahrenheit.  |" << std::endl;
				std::cout << "| [2]. Fahrenheit to Celsius.  |" << std::endl;
				std::cout << "| [3]. Celsius to Kelvin.      |" << std::endl;
				std::cout << "| [4]. Kelvin to Celsius.      |" << std::endl;
				std::cout << "| [5]. Quit this program.      |" << std::endl;
				std::cout << "+===+====+===+====+===+====+===+" << std::endl;

				/* Converts an enumerated class to a primitive integer type. */
				int_option = getData<int>("Option: ", &int_option);
				cnv_myConverter = static_cast<Converter>(--int_option);

				/* Case selection based on the chosen option. */
				switch (cnv_myConverter)
					{
						case Converter::Celsius_to_Fahrenheit:
							/* Capture the value in degrees 'Celsius'. */
							dbl_degrees = getData<double>("Enter a value in degrees Celsius: ", &dbl_degrees);

							/* Formula to convert from 'Celsius' to 'Fahrenheit'. */
							dbl_result = getCalculations<double>(Converter::Celsius_to_Fahrenheit, fn_celsius_to_fahrenheit, &dbl_degrees, &dbl_result);
							break;

						case Converter::Fahrenheit_to_Celsius:
							/* Capture the value in degrees 'Fahrenheit'. */
							dbl_degrees = getData<double>("Enter a value in degrees Fahrenheit: ", &dbl_degrees);

							/* Formula to convert from 'Fahrenheit' to 'Celsius'. */
							dbl_result = getCalculations<double>(Converter::Fahrenheit_to_Celsius, fn_fahrenheit_to_celsius, &dbl_degrees, &dbl_result);
							break;

						case Converter::Celsius_to_Kelvin:
							/* Capture the value in degrees 'Celsius'. */
							dbl_degrees = getData<double>("Enter a value in degrees Celsius: ", &dbl_degrees);

							/* Formula to convert from 'Fahrenheit' to 'Celsius'. */
							dbl_result = getCalculations<double>(Converter::Celsius_to_Kelvin, fn_celsius_to_kelvin, &dbl_degrees, &dbl_result);
							break;

						case Converter::Kelvin_to_Celsius:
							/* Capture the value in degrees 'Celsius'. */
							dbl_degrees = getData<double>("Enter a value in degrees Kelvin: ", &dbl_degrees);

							/* Formula to convert from 'Kelvin' to 'Celsius'. */
							dbl_result = getCalculations<double>(Converter::Kelvin_to_Celsius, fn_kelvin_to_celsius, &dbl_degrees, &dbl_result);
							break;

						case Converter::Exit_Converter:
							std::cout << std::endl << "Leaving this program..." << std::endl;
							break;

						default:
							std::cout << std::endl << "Invalid option: [" << int_option << "]. Correct it!" << std::endl << std::endl;
							break;

					}
			}

		return V_ZERO;
	}
