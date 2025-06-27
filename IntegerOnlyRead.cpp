#include <iostream>
#include <limits>

#define V_ZERO  0

struct IntegerOnlyRead
	{
		private:
			const int value;

		public:
			IntegerOnlyRead(int value) : value(value) {}

			operator int() const    { return value; }
	};

int main()
	{
		int int_multiplier = V_ZERO;
		int32_t int_value {V_ZERO};

		std::cout << "Operator overloading with integer values." << std::endl;
		std::cout << "Enter a integer value    : ";
		std::cin >> int_value;

		std::cout << "Enter a multiplier value : ";
		std::cin >> int_multiplier;

		IntegerOnlyRead integer_response {int_value};
		auto multiplied_integer_response = static_cast<int64_t>(integer_response) * int_multiplier;

		std::cout << std::endl << "Converted and overloaded values..." << std::endl;
		std::cout << "Original Value:\t\t[" << integer_response << "]." << std::endl;
		std::cout << "Multiplied Value:\t[" << multiplied_integer_response << "]." << std::endl;

		std::cout << std::endl << "Scope of numerical limits for each type..." << std::endl;
		std::cout << "int:\t\t\t[" << std::numeric_limits<int>::max() << "]." << std::endl;
		std::cout << "int32_t:\t\t[" << std::numeric_limits<int32_t>::max() << "]." << std::endl;
		std::cout << "int64_t:\t\t[" << std::numeric_limits<int64_t>::max() << "]." << std::endl;

		return V_ZERO;
	}
