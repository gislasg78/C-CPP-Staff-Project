#include <iostream>

#define V_TWO   2.0
#define V_ZERO  0

int main()
	{
		double radius = V_ZERO;
		constexpr double V_PI = 3.1415926;

		std::cout << "Circle Area and Perimeter." << std::endl;
		std::cout << "Enter the radius: ";
		std::cin >> radius;

		std::cout << std::endl << "Circle Information." << std::endl;

		const double area = V_PI * radius * radius;
		std::cout << "+ Area:\t\t\t[" << area << "]." << std::endl;

		const double circumference = V_TWO * V_PI * radius;
		std::cout << "+ Circumference:\t[" << circumference << "]." << std::endl;

		std::cout << "+ PI Value:\t\t[" << V_PI << "]." << std::endl;

		return V_ZERO;
	}
