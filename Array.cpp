#include <array>
#include <iostream>

#define V_TWENTY_FIVE   25
#define V_ZERO          0

int main()
	{
		std::array<int, V_TWENTY_FIVE> my_array = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

		std::cout << "Displaying the contents of an array." << std::endl;

		for (int item : my_array)
			std::cout << "[" << item << "].\t";

		std::cout << std::endl << "End of assignment!" << std::endl;

		return V_ZERO;
	}
