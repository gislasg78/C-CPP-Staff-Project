//Friend functions.
#include <iostream>

#define	V_THREE	3
#define	V_TWO	2
#define V_ZERO  0

class Rectangle
	{
		private:
			int width = V_ZERO, height = V_ZERO;

		protected:
			static int counter;

		public:
			Rectangle() : width(V_ZERO), height(V_ZERO)			{this->counter++;}
			Rectangle (const int &x, const int &y) : width(x), height(y)	{this->counter++;}

			double area()		{return this->width * this->height;}
			double perimeter()	{return V_TWO * this->width + V_TWO * this->height;}

			friend Rectangle obtain_results	(const Rectangle& rect);
	};

int Rectangle::counter = V_ZERO;

Rectangle obtain_results (const Rectangle& rect)
	{
		Rectangle res;

		res.width = rect.width;
		res.height = rect.height;

		std::cout << "Rectangle's outcomes." << std::endl;
		std::cout << "Counter:\t[" << res.counter << "]." << std::endl;
		std::cout << "Height:\t\t[" << res.height << "]." << std::endl;
		std::cout << "Width:\t\t[" << res.width << "]." << std::endl;
		std::cout << "Area:\t\t[" << res.area() << "]." << std::endl;
		std::cout << "Perimeter:\t[" << res.perimeter() << "]." << std::endl << std::endl;

		return res;
	}

int main ()
	{
		Rectangle foo;
		Rectangle bar (V_TWO, V_THREE);
		Rectangle baz (V_THREE, V_TWO);

		obtain_results(foo);
		obtain_results(bar);
		obtain_results(baz);

		foo = obtain_results(bar);
		bar = obtain_results(baz);
		baz = obtain_results(foo);

		return V_ZERO;
	}
