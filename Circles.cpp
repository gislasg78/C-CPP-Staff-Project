#include <iostream>

#define V_PI    3.1415926

#define	V_FIVE	5
#define	V_FOUR	4
#define	V_THREE	3
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
			Circle() : radius(V_ZERO)
				{
					std::cout << std::endl << "Data capture for a 'circle'." << std::endl;
					std::cout << "Enter the radius: ";
					std::cin >> this->radius;
				}

			Circle(const T radius)				{this->radius = radius;}

			const T& getRadius()	const			{return (*this).radius;}
			T& getRadius()					{return this->radius;}

			const T getArea()				{return pi() * this->radius * this->radius;}
			const T getPerimeter()				{return V_TWO * pi.getPi() * this->radius;}

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

		Circle<double> circle(radius);
		circle.getRadius() = radius;

		std::cout << std::endl << "Results of the 'Circle' calculations." << std::endl;
		std::cout << "+ PI:\t\t[" << static_cast<double>(pi) << "] = [" << pi() << "]." << std::endl;
		std::cout << "+ Radius:\t[" << circle.getRadius() << "]." << std::endl;
		std::cout << "+ Area:\t\t[" << circle.getArea() << "]." << std::endl;
		std::cout << "+ Perimeter:\t[" << circle.getPerimeter() << "]." << std::endl;

		Circle<float> foo;				//Functional form.
		Circle<float> bar = V_TWO;			//Assignment init.
		Circle<float> baz {V_THREE};			//Uniform init.
		Circle<float> qux = {V_FOUR};			//POD-like
		Circle<float> quz = Circle<float>(V_FIVE);	//Traditional assignment form.

		std::cout << std::endl << "Outcomes." << std::endl;
		std::cout << "** foo." << std::endl;
		std::cout << " + Radius:\t[" << foo.getRadius() << "]." << std::endl;
		std::cout << " + Area:\t[" << foo.getArea() << "]." << std::endl;
		std::cout << " + Perimeter:\t[" << foo.getPerimeter() << "]." << std::endl;

		std::cout << "** bar." << std::endl;
		std::cout << " + Radius:\t[" << bar.getRadius() << "]." << std::endl;
		std::cout << " + Area:\t[" << bar.getArea() << "]." << std::endl;
		std::cout << " + Perimeter:\t[" << bar.getPerimeter() << "]." << std::endl;

		std::cout << "** baz." << std::endl;
		std::cout << " + Radius:\t[" << baz.getRadius() << "]." << std::endl;
		std::cout << " + Area:\t[" << baz.getArea() << "]." << std::endl;
		std::cout << " + Perimeter:\t[" << baz.getPerimeter() << "]." << std::endl;

		std::cout << "** qux." << std::endl;
		std::cout << " + Radius:\t[" << qux.getRadius() << "]." << std::endl;
		std::cout << " + Area:\t[" << qux.getArea() << "]." << std::endl;
		std::cout << " + Perimeter:\t[" << qux.getPerimeter() << "]." << std::endl;

		std::cout << "** quz." << std::endl;
		std::cout << " + Radius:\t[" << quz.getRadius() << "]." << std::endl;
		std::cout << " + Area:\t[" << quz.getArea() << "]." << std::endl;
		std::cout << " + Perimeter:\t[" << quz.getPerimeter() << "]." << std::endl;

		return V_ZERO;
	}
