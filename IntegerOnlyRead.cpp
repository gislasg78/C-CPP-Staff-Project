/* This program is responsible for creating a class
   through a structure to generate any constant integer
   that the user desires.*/

//Common work libraries.
#include <iostream>
#include <limits>

//Symbolic work constants.
#define V_ZERO  0

/* Class structure 'IntegerReadOnly'. */
struct IntegerOnlyRead
	{
		private:
			const int value;

		public:
			IntegerOnlyRead(int value) : value(value)	{}

			operator int()	const	{return value;}
	};

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int int_multiplier = V_ZERO;
		int32_t int_value {V_ZERO};

		/* Header messages. */
		std::cout << "Operator overloading with integer values." << std::endl;
		std::cout << "Enter a integer value    : ";
		std::cin >> int_value;

		std::cout << "Enter a multiplier value : ";
		std::cin >> int_multiplier;

		/* Generating an instance of the 'IntegerReadOnly' class. */
		IntegerOnlyRead integer_response {int_value};
		auto multiplied_integer_response = static_cast<int64_t>(integer_response) * int_multiplier;

		/* Exit warning messages. */
		std::cout << std::endl << "Converted and overloaded values..." << std::endl;
		std::cout << "Original Value:\t\t[" << integer_response << "]." << std::endl;
		std::cout << "Multiplier Value:\t[" << int_multiplier << "]." << std::endl;
		std::cout << "Multiplied Value:\t[" << multiplied_integer_response << "]." << std::endl;

		/* Messages of numerical scopes and areas. */
		std::cout << std::endl << "Scope of numerical limits for each type..." << std::endl;
		std::cout << "int:\t\t\t[" << std::numeric_limits<int>::max() << "]." << std::endl;
		std::cout << "int32_t:\t\t[" << std::numeric_limits<int32_t>::max() << "]." << std::endl;
		std::cout << "int64_t:\t\t[" << std::numeric_limits<int64_t>::max() << "]." << std::endl;

		return V_ZERO;
	}
