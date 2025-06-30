//Classes and uniform initialization.
#include <iostream>

#define V_ZERO	0
#define	V_ONE	1.0
#define	V_TWO	2.0
#define	V_THREE	3.0
#define V_FOUR	4.0

#define V_PI	3.14159265

class Circle
	{
		private:
			const double PI = V_PI;
			double radius = V_ZERO;

			friend std::istream &operator>> (std::istream& in, Circle &circle)
				{circle.capture(); return in;}

			friend std::ostream& operator<< (std::ostream &out, const Circle &circle)
				{circle.print(); return out;}

		protected:
			static int c;

		public:
			Circle()							{(*this).c++; this->capture();}
			Circle(const double &radius) : radius(radius)			{this->c++;}
			Circle(const Circle& circle) : radius(circle.getRadius())	{(*this).c++;};

			Circle& operator=(const Circle& circle)
				{this->radius = circle.getRadius(); return *this;}

			Circle& operator()()
				{
					std::cout << std::endl << "Radius of the figure 'Circle'." << std::endl;
					std::cout << "+ Radius:\t[" << this->radius << "]." << std::endl;
					return *this;
				}

			Circle& operator++()			{++this->radius; return *this;}
			Circle& operator++(int)			{(*this).radius++; return *this;}
			Circle& operator--()			{--(*this).radius; return *this;}
			Circle& operator--(int)			{this->radius--; return *this;}

			operator double()	const		{return this->radius;}

			double area()		const		{return PI * this->radius * (*this).radius;}
			double perimeter()	const		{return V_TWO * PI * (*this).radius;}

			virtual void capture()
				{
					std::cout << std::endl << "Capture of the radius of the 'Circle' figure." << std::endl;
					std::cout << "Enter the desired radius: ";
					std::cin >> (*this).radius;
				}

			virtual Circle& copy(const Circle& circle)
				{(*this).radius = circle.getRadius(); return *this;}

			const double& getPI()	const		{return this->PI;}
			double getRadius()	const		{return this->radius;}

			virtual void print()	const
				{
					std::cout << std::endl << "Information about the figure 'Circle'." << std::endl;
					this->view();
				}

			virtual void reset()			{this->radius = V_ZERO;}
			void setRadius(const double &radius)	{this->radius = radius;}

			virtual void view()	const
				{
					std::cout << "+ Counter:\t[" << this->c << "]." << std::endl;
					std::cout << "+ PI Value:\t[" << (*this).PI << "]." << std::endl;
					std::cout << "+ Radius:\t[" << this->radius << "]." << std::endl;
					std::cout << "+ Area:\t\t[" << this->area() << "]." << std::endl;
					std::cout << "+ Perimeter:\t[" << (*this).perimeter() << "]." << std::endl;
				}

			virtual ~Circle() = default;
	};

int Circle::c = V_ZERO;

class Cylinder
	{
		private:
			Circle base;
			double height = V_ZERO;

		public:
			Cylinder(double radius, double height) : base(radius), height(height) {}

			virtual void print()	const
				{
					std::cout << std::endl << "Information about the 'Cylinder." << std::endl;
					std::cout << "+ Volume:\t[" << (*this).volume() << "]." << std::endl;
					(&base)->print();
				}

			double volume()		const	{return base.area() * height;}
	};

int main ()
	{
		double height = V_ZERO, radius = V_ZERO;

		std::cout << "Volume of a cylinder." << std::endl;
		std::cout << "Radius: ";
		std::cin >> radius;
		std::cout << "Height: ";
		std::cin >> height;

		Circle foo(V_ONE);	//Functional form.
		Circle bar = V_TWO;	//Assignment init.
		Circle baz {V_THREE};	//Uniform init.
		Circle qux = {V_FOUR};	//POD-like.
		Circle quux;		//Default constructor.
		Circle corge(quux);	//Copy constructor.
		Circle grault = baz;	//Copy constructor.

		Cylinder garply(radius, height);

		foo.print();
		bar.print();
		baz.print();
		qux.print();
		quux.print();
		corge.print();

		grault.print();
		grault.copy(corge);
		grault.print();
		grault = quux;
		grault.print();
		grault();
		grault++;
		grault.print();
		grault--;
		grault.print();

		std::cin >> grault;
		std::cout << grault;
		std::cout << std::endl << "+ Radius:\t[" << static_cast<double>(grault) << "]." << std::endl;
		grault.reset();
		grault.capture();
		grault.print();

		garply.print();

		return V_ZERO;
	}
