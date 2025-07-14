#include <exception>
#include <iostream>
#include <sstream>
#include <typeinfo>

#define V_MINUS_TWO -2
#define V_ONE       1
#define V_PLUS_SIGN 0x2b
#define V_ZERO      0


//Class to handle custom exceptions.
class ComplexNumberFormatErrorException : public std::exception
	{
		public:
			const char* what() const noexcept override
				{
					return "Damn! Invalid complex number format.";
				}
	};


//Definition of the 'Complex' class.
class Complex
	{
		public:
			double dbl_real = V_ZERO;
			double dbl_imaginary = V_ZERO;

			//Default constructor.
			Complex() : dbl_real(V_ZERO), dbl_imaginary(V_ZERO) {}

			//Constructor with parameters.
			Complex(double dbl_real, double dbl_imaginary) : dbl_real(dbl_real), dbl_imaginary(dbl_imaginary) {}

			//Overloading of the '>>' operator.
			friend std::istream& operator>> (std::istream& console_input, Complex& complex);
	};


//Defining the '>>' operator overload for std::cin.
std::istream& operator>> (std::istream& input, Complex& complex)
	{
		/* Preliminary working variables. */
		std::string inputStr;
		input >> inputStr;

		//Find the position of the '+' symbol.
		size_t plusPos = inputStr.find(V_PLUS_SIGN);

		if (plusPos == std::string::npos)
			{
				//Handle error if format is not correct.
				input.setstate(std::ios::failbit);
				throw ComplexNumberFormatErrorException();
			}
		else
			{
				//Extract the real part and the imaginary part of the complex number from the character string as decimals.
				try
					{
						complex.dbl_real = std::stod(inputStr.substr(V_ZERO, plusPos));
						complex.dbl_imaginary = std::stod(inputStr.substr(plusPos + V_ONE, inputStr.length() - plusPos + V_MINUS_TWO)); //-2 to remove 'i'.
					}
				catch (std::exception& ex)
					{
						std::cerr << "An exception has occurred: " << '\x5b' << ex.what() << '\x5d' << std::endl;
					}
			}

		return input;
	}


int main()
	{
		//Initial header messages.
		Complex c;
		std::cout << "Program that tests with exceptions." << std::endl;
		std::cout << "Enter a complex number of the form: 'a+bi': ";

		//Testing and obtaining the complex number of the form: 'a+bi'.
		try
			{
				std::cin >> c;
			}
		catch (std::exception& ex)
			{
				std::cerr << "An exception has occurred: " << '\x5b' << ex.what() << '\x5d' << std::endl;
			}

		//Tipo de objeto instanciado de la clase 'Complejo'.
		std::cout << "Instance of class 'Complex' is of type: [" << typeid(c).name() << "]." << std::endl;

		//Sets flag on input as invalid complex number format.
		if (std::cin.fail())
			{
				std::cerr << "Mistake! Incorrect input complex number format." << std::endl;
			}
		else
			{
				std::cout << "Complex number entered: [" << c.dbl_real << "] + [" << c.dbl_imaginary << "]i." << std::endl;
			}

		return V_ZERO;
	}
