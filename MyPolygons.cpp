//Virtual members.
#include <iostream>

#define V_PI    3.1415926

#define	V_FOUR	4.0
#define V_THREE 3.0
#define V_TWO   2.0
#define V_ZERO  0

class Polygon
	{
		protected:
			int width = V_ZERO, height = V_ZERO;

		public:
			virtual double area ()			{return V_ZERO;}
			virtual double perimeter()		{return V_ZERO;}

			void set_values (double width, double height)
				{this->width = width; this->height = height;}
	};

class Circle: public Polygon
	{
		public:
			double area(double radius)		{return V_PI * radius * radius;}
			double perimeter(double radius)		{return V_TWO * V_PI * radius;}
	};

class Diamond: public Polygon
	{
		public:
			double area()				{return (this->width * this->height) / V_TWO;}
			double perimeter(double side)		{return V_FOUR * side;}
	};

class Rectangle: public Polygon
	{
		public:
			double area ()				{return this->width * this->height;}
			double perimeter()			{return V_TWO * this->width + V_TWO * this->height;}
	};

class Square: public Polygon
	{
		public:
			double area(double side)		{return side * side;}
			double perimeter(double side)		{return V_FOUR * side;}
	};

class Triangle: public Polygon
	{
		public:
			double area ()				{return (this->width * this->height / V_TWO);}
			double perimeter(double side)		{return V_THREE * side;}
	};

int main()
	{
		Polygon poly;
		Circle circ;
		Diamond diam;
		Rectangle rect;
		Square sqr;
		Triangle trgl;

		Polygon * ppoly1 = &poly;
		Polygon * ppoly2 = &circ;
		Polygon * ppoly3 = &diam;
		Polygon * ppoly4 = &rect;
		Polygon * ppoly5 = &sqr;
		Polygon * ppoly6 = &trgl;

		ppoly1->set_values (V_TWO, V_THREE);
		ppoly2->set_values (V_THREE, V_TWO);
		ppoly3->set_values (V_TWO, V_THREE);
		ppoly4->set_values (V_TWO, V_THREE);
		ppoly5->set_values (V_THREE, V_TWO);
		ppoly6->set_values (V_THREE, V_TWO);

		std::cout << "Polygon." << std::endl;
		std::cout << "+ Area:\t\t[" << ppoly1->area() << "]." << std::endl;
		std::cout << "+ Perimeter:\t[" << ppoly1->perimeter() << "]." << std::endl << std::endl;

		std::cout << "Circle." << std::endl;
		if (Circle *c = dynamic_cast<Circle*>(ppoly2))
			{
				std::cout << "+ Area:\t\t[" << c->area(V_TWO) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << c->perimeter(V_TWO) << "]." << std::endl << std::endl;
			}
		else
			{
				std::cout << "- Area:\t\t[" << ppoly2->area() << "]." << std::endl;
				std::cout << "- Perimeter:\t[" << ppoly2->perimeter() << "]." << std::endl << std::endl;
			}

		std::cout << "Diamond." << std::endl;
		if (Diamond *d = dynamic_cast<Diamond*>(ppoly3))
			{
				std::cout << "+ Area:\t\t[" << d->area() << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << d->perimeter(V_TWO) << "]." << std::endl << std::endl;
			}
		else
			{
				std::cout << "- Area:\t\t[" << ppoly3->area() << "]." << std::endl;
				std::cout << "- Perimeter:\t[" << ppoly3->perimeter() << "]." << std::endl << std::endl;
			}

		std::cout << "Rectangle." << std::endl;
		std::cout << "+ Area:\t\t[" << ppoly4->area() << "]." << std::endl;
		std::cout << "+ Perimeter:\t[" << ppoly4->perimeter() << "]." << std::endl << std::endl;

		std::cout << "Square." << std::endl;
		if (Square *s = dynamic_cast<Square*>(ppoly5))
			{
				std::cout << "+ Area:\t\t[" << s->area(V_TWO) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << s->perimeter(V_TWO) << "]." << std::endl << std::endl;
			}
		else
			{
				std::cout << "- Area:\t\t[" << ppoly5->area() << "]." << std::endl;
				std::cout << "- Perimeter:\t[" << ppoly5->perimeter() << "]." << std::endl << std::endl;
			}

		std::cout << "Triangle." << std::endl;
		std::cout << "+ Area:\t\t[" << ppoly6->area() << "]." << std::endl;
		if (Triangle *t = dynamic_cast<Triangle*>(ppoly6))
			std::cout << "+ Perimeter:\t[" << t->perimeter(V_TWO) << "]." << std::endl << std::endl;
		else
			std::cout << "- Perimeter:\t[" << ppoly6->perimeter() << "]." << std::endl << std::endl;

		return V_ZERO;
	}
