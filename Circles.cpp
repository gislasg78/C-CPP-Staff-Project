#include <iostream>

#define V_PI    3.1415926
#define V_TWO   2
#define V_ZERO  0

template <typename T>
class Pi
	{
		private:
			const T PI = V_PI;

		public:
			const T& getPi()	const	{return this->PI;}
			const T& operator()()	const	{return this->PI;}
			operator T()		const	{return this->PI;}

			virtual ~Pi() = default;
	};

template <typename T>
class Circle
	{
		private:
			Pi<T> pi;
			T radius = V_ZERO;

		public:
			const T& getRadius()	const	{return (*this).radius;}
			T& getRadius()			{return this->radius;}

			const T getArea()		{return pi() * this->radius * this->radius;}
			const T getPerimeter()		{return V_TWO * pi.getPi() * this->radius;}

			void setRadius(const T& radius = V_ZERO)	{this->radius = radius;}

			virtual ~Circle() = default;
	};


int main()
	{
		double radius = V_ZERO;

		std::cout << "Perimeter and Area of a 'Circle'." << std::endl;
		std::cout << "Enter the value for the radius: ";
		std::cin >> radius;

		Pi<double> pi;

		Circle<double> circle;
		circle.setRadius(radius);
		circle.getRadius() = radius;

		std::cout << std::endl << "Results of the 'Circle' calculations." << std::endl;
		std::cout << "+ PI:\t\t[" << static_cast<double>(pi) << "] = [" << pi() << "]." << std::endl;
		std::cout << "+ Radius:\t[" << circle.getRadius() << "]." << std::endl;
		std::cout << "+ Area:\t\t[" << circle.getArea() << "]." << std::endl;
		std::cout << "+ Perimeter:\t[" << circle.getPerimeter() << "]." << std::endl;

		return V_ZERO;
	}
