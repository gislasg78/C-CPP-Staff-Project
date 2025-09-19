#include <iostream>

#define V_PI    3.1415926
#define	V_TWO	2
#define V_ZERO  0


template <typename T> T captureRadius();

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
			Circle() : radius(V_ZERO)			{(*this).radius = captureRadius<T>();}
			Circle(const T& radius) : radius(radius)	{this->radius = radius;}

			const T  getPi()	const			{return static_cast<T>(pi);}
			const T& getRadius()	const			{return (*this).radius;}
			T& getRadius()					{return this->radius;}

			const T getArea()				{return pi() * this->radius * this->radius;}
			const T getPerimeter()				{return V_TWO * pi.getPi() * this->radius;}

			void print()					{infoCircle(*this);}
			void setRadius(const T& radius = V_ZERO)	{this->radius = radius;}

			virtual ~Circle() = default;
	};


template <typename T>
T captureRadius()
	{
		T radius = V_ZERO;

		std::cout << std::endl << "Capture the 'Circle' object radius." << std::endl;
		std::cout << "Enter the value for the radius: ";
		std::cin >> radius;

		return radius;
	}

template <typename T>
void infoCircle(Circle<T>& circle)
	{
		std::cout << std::endl << "Results of the 'Circle' calculations." << std::endl;
		std::cout << " + PI:\t\t[" << circle.getPi() << "]." << std::endl;
		std::cout << " + Radius:\t[" << circle.getRadius() << "]." << std::endl;
		std::cout << " + Area:\t[" << circle.getArea() << "]." << std::endl;
		std::cout << " + Perimeter:\t[" << circle.getPerimeter() << "]." << std::endl;
	};


int main()
	{
		std::cout << "Creating objects of type 'Circle'." << std::endl;

		Pi<double> pi;

		Circle<double> circle(captureRadius<double>());
		infoCircle(circle);

		Circle<double> foo;						//Functional form.
		foo.print();

		Circle<double> bar = captureRadius<double>();			//Assignment init.
		infoCircle(bar);

		Circle<double> baz {captureRadius<double>()};			//Uniform init.
		infoCircle(baz);

		Circle<double> qux = {captureRadius<double>()};			//POD-like
		qux.print();

		Circle<double> quz = Circle<double>(captureRadius<double>());	//Traditional assignment form.
		quz.print();

		return V_ZERO;
	}
