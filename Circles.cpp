#include <iostream>

#define V_PI    3.1415926
#define V_TWO   2
#define V_ZERO  0

class Pi
	{
		private:
			double PI = V_PI;

		public:
			const double& getPi()		{return this->PI;}
			double& operator()()		{return this->PI;}

			virtual ~Pi() = default;
	};

class Circle
	{
		private:
			Pi pi;
			double radius = V_ZERO;

		public:
			const double& getRadius()	{return (*this).radius;}

			const double getArea()		{return pi() * this->radius * this->radius;}
			const double getPerimeter()	{return V_TWO * pi.getPi() * this->radius;}

			void setRadius(const double& radius = V_ZERO)	{this->radius = radius;}

			virtual ~Circle() = default;
	};


int main()
	{
		double radius = V_ZERO;

		std::cout << "Perimeter and Area of a 'Circle'." << std::endl;
		std::cout << "Enter the value for the radius: ";
		std::cin >> radius;

		Circle circle;

		circle.setRadius(radius);

		std::cout << std::endl << "Results of the 'Circle' calculations." << std::endl;
		std::cout << "+ Radius:\t[" << circle.getRadius() << "]." << std::endl;
		std::cout << "+ Area:\t\t[" << circle.getArea() << "]." << std::endl;
		std::cout << "+ Perimeter:\t[" << circle.getPerimeter() << "]." << std::endl;

		return V_ZERO;
	}
