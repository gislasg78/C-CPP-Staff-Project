#include <iostream>

#define V_TEN		10
#define V_THIRTY	30
#define V_TWENTY	20
#define V_TWO		2
#define V_ZERO		0

const int multiply(const int x, const int y)			{return x * y;}

constexpr int multiplyConstexpr(const int x, const int y)	{return x * y;}

int main()
	{
		int val1 = V_TEN, val2 = V_TWENTY;
		constexpr int val3 = V_THIRTY;

		const int xval = val1;
		const int yval = val2;
		int zval = val3;

		int result1 = multiply(val1, V_TWO);
		int result2 = multiply(val2, V_TWO);
		constexpr int result3 = multiplyConstexpr(val3, V_TWO);

		std::cout << "Program that exemplifies constants." << std::endl;
		std::cout << "Results." << std::endl;
		std::cout << " + 1: [" << result1 << "]." << std::endl;
		std::cout << " + 2: [" << result2 << "]." << std::endl;
		std::cout << " + 3: [" << result3 << "]." << std::endl;

		std::cout << std::endl << "(x = [" << xval << "], y = [" << yval << "], z = [" << zval << "])." << std::endl;

		return V_ZERO;
	}
