//Virtual members.
#include <iostream>

#define V_PI    3.1415926

#define V_THREE 3
#define V_TWO   2
#define V_ZERO  0

class Polygon
	{
		protected:
			int width = V_ZERO, height = V_ZERO;

		public:
			virtual double area () const       {return V_ZERO;}
			virtual double perimeter() const   {return V_ZERO;}

			void set_values (const double& width, const double& height)
				{this->width = width; this->height = height;}
	};

class Circle : public Polygon
	{
		public:
			Circle() : Polygon() {}

			virtual double area(const double &radius) const        {return V_PI * radius * radius;}
			virtual double perimeter(const double &radius) const   {return V_TWO * V_PI * radius;}
	};

class Rectangle: public Polygon
	{
		public:
			virtual double area () const       {return this->width * this->height;}
			virtual double perimeter() const   {return V_TWO * this->width + V_TWO * this->height;}
	};

class Triangle: public Polygon
	{
		public:
			virtual double area () const       {return (this->width * this->height / V_TWO);}
			virtual double perimeter(const int& side) const {return V_THREE * side;}
	};

int main()
	{
		Polygon poly;
		Circle circ;
		Rectangle rect;
		Triangle trgl;

		Polygon * ppoly1 = &poly;
		Polygon * ppoly2 = &circ;
		Polygon * ppoly3 = &rect;
		Polygon * ppoly4 = &trgl;

		ppoly1->set_values (V_TWO, V_THREE);
		ppoly2->set_values (V_THREE, V_TWO);
		ppoly3->set_values (V_TWO, V_THREE);

		std::cout << "Polygon." << std::endl;
		std::cout << "Area:\t\t[" << ppoly1->area() << "]." << std::endl;
		std::cout << "Perimeter:\t[" << ppoly1->perimeter() << "]." << std::endl << std::endl;

		std::cout << "Circle." << std::endl;

		if (Circle *c = dynamic_cast<Circle*>(ppoly2))
			{
				std::cout << "Area:\t\t[" << c->area(V_TWO) << "]." << std::endl;
				std::cout << "Perimeter:\t[" << c->perimeter(V_TWO) << "]." << std::endl << std::endl;
			}
		else
			{
				std::cout << "Area:\t\t[" << ppoly2->area() << "]." << std::endl;
				std::cout << "Perimeter:\t[" << ppoly2->perimeter() << "]." << std::endl << std::endl;
			}

		std::cout << "Rectangle." << std::endl;
		std::cout << "Area:\t\t[" << ppoly3->area() << "]." << std::endl;
		std::cout << "Perimeter:\t[" << ppoly3->perimeter() << "]." << std::endl << std::endl;

		std::cout << "Triangle." << std::endl;
		std::cout << "Area:\t\t[" << ppoly3->area() << "]." << std::endl;

		if (Triangle *t = dynamic_cast<Triangle*>(ppoly4))
			std::cout << "Perimeter:\t[" << t->perimeter(V_TWO) << "]." << std::endl << std::endl;
		else
			std::cout << "Perimeter:\t[" << ppoly4->perimeter() << "]." << std::endl << std::endl;

		return V_ZERO;
	}
