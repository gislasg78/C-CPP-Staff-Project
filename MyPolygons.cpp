/* This program performs polymorphism of different geometric figures
   to obtain their respective areas and perimeters. */

/* Standard work libraries. */
#include <iostream>

/* Symbolic work constants. */
#define V_PI    3.1415926

#define	V_FOUR	4.0
#define V_THREE 3.0
#define V_TWO   2.0
#define V_ZERO  0

/* Shape Class. */
template <class T>
class Shape
	{
		protected:
			T area = V_ZERO, perimeter = V_ZERO;

		public:
			virtual const T& getArea() const
				{return (*this).area;}
			virtual const T& getPerimeter() const
				{return (*this).perimeter;}
	};

/* Circle class. */
template <class T>
class Circle: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& radius)
				{return (*this).area = V_PI * radius * radius;}
			const T getPerimeter(const T& radius)
				{return (*this).perimeter = V_TWO * V_PI * radius;}
	};

/* Diamond class. */
template <class T>
class Diamond: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& major_diameter, const T& minor_diameter)
				{return this->area = (major_diameter * minor_diameter) / V_TWO;}
			const T getPerimeter(const T &side)
				{return this->perimeter = V_FOUR * side;}
	};

/* Kite class. */
template <class T>
class Kite: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& major_diameter, const T& minor_diameter)
				{return (*this).area = (major_diameter * minor_diameter) / V_TWO;}
			const T getPerimeter(const T& top, const T& bottom)
				{return (*this).perimeter = V_TWO * (bottom + top);}
	};

/* Parallelogram class. */
template <typename T>
class Parallelogram: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& bottom, const T& height)
				{return (*this).area = bottom * height;}
			const T getPerimeter(const T& side, const T& bottom)
				{return (*this).perimeter = V_TWO * side + V_TWO * bottom;}
	};

/* Polygon class. */
template <class T>
class Polygon: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T& getArea(const T& number, const T& side, const T& apothegm)
				{return this->area = ((number * side) * apothegm) / V_TWO;}
			const T& getPerimeter(const T &number, const T &side)
				{return (*this).perimeter = number * side;}
	};

/* Rectangle class. */
template <class T>
class Rectangle: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& width, const T& height)
				{return (*this).area = width * height;}
			const T getPerimeter(const T &width, const T &height)
				{return (*this).perimeter = V_TWO * height + V_TWO * width;}
	};

/* Square class. */
template <class T>
class Square: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T &side)
				{return this->area = side * side;}
			const T getPerimeter(const T& side)
				{return this->perimeter = V_FOUR * side;}
	};

/* Trapeze class. */
template <class T>
class Trapeze: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& top, const T& bottom, const T& height)
				{return (*this).area = ((top * bottom) * height) / V_TWO;}
			const T getPerimeter(const T &top, const T &bottom, const T &left, const T &right)
				{return (*this).perimeter = top + bottom + left + right;}
	};

/* Triangle class. */
template <class T>
class Triangle: public Shape<T>
	{
		public:
			const T& getArea() const override
				{return (*this).area;}
			const T& getPerimeter() const override
				{return (*this).perimeter;}

			const T getArea(const T& width, const T& height)
				{return (*this).area = (width * height / V_TWO);}
			const T getPerimeter(const T &side)
				{return (*this).perimeter = V_THREE * side;}
	};


//Main function.
int main()
	{
		/* Preliminary working variables. */
		double apothegm = V_ZERO, number = V_ZERO;
		double bottom = V_ZERO, left = V_ZERO, right = V_ZERO, top = V_ZERO;
		double height = V_ZERO, width = V_ZERO;
		double major_diameter = V_ZERO, minor_diameter = V_ZERO, side = V_ZERO;
		double radius = V_ZERO;

		/* Initial header message. */
		std::cout << "Program that calculates areas and perimeters of flat figures." << std::endl << std::endl;


		/* Circle. */
		Circle<double> circ;
		Shape<double> *pcirc = &circ;
		std::cout << "Circle." << std::endl;

		if (Circle<double> *c = dynamic_cast<Circle<double>*>(pcirc))
			{
				std::cout << "Enter the radius: ";
				std::cin >> radius;

				std::cout << std::endl << "[Circle]." << std::endl;
				std::cout << "+ Area:\t\t[" << c->getArea(radius) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << c->getPerimeter(radius) << "]." << std::endl << std::endl;
			}


		/* Diamond. */
		Diamond<double> diam;
		Shape<double> *pdiam = &diam;
		std::cout << "Diamond." << std::endl;

		if (Diamond<double> *d = dynamic_cast<Diamond<double>*>(pdiam))
			{
				std::cout << "Enter the major diameter: ";
				std::cin >> major_diameter;
				std::cout << "Enter the minor diameter: ";
				std::cin >> minor_diameter;
				std::cout << "Enter the side: ";
				std::cin >> side;

				std::cout << std::endl << "[Diamond]." << std::endl;
				std::cout << "+ Area:\t\t[" << d->getArea(major_diameter, minor_diameter) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << d->getPerimeter(side) << "]." << std::endl << std::endl;
			}


		/* Kite. */
		Kite<double> kite;
		Shape<double> *pkite = &kite;
		std::cout << "Kite." << std::endl;

		if (Kite<double> *k = dynamic_cast<Kite<double>*>(pkite))
			{
				std::cout << "Enter the major diameter: ";
				std::cin >> major_diameter;
				std::cout << "Enter the minor diameter: ";
				std::cin >> minor_diameter;
				std::cout << "Enter the top: ";
				std::cin >> top;
				std::cout << "Enter the bottom: ";
				std::cin >> bottom;

				std::cout << std::endl << "[Kite]." << std::endl;
				std::cout << "+ Area:\t\t[" << k->getArea(major_diameter, minor_diameter) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << k->getPerimeter(top, bottom) << "]." << std::endl << std::endl;
			}


		/* Parallelogram. */
		Parallelogram<double> prll;
		Shape<double> *pprll = &prll;
		std::cout << "Parallelogram." << std::endl;

		if (Parallelogram<double> *p = dynamic_cast<Parallelogram<double>*>(pprll))
			{
				std::cout << "Enter the bottom: ";
				std::cin >> bottom;
				std::cout << "Enter the height: ";
				std::cin >> height;
				std::cout << "Enter the side: ";
				std::cin >> side;

				std::cout << std::endl << "[Parallelogram]." << std::endl;
				std::cout << "+ Area:\t\t[" << p->getArea(bottom, height) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << p->getPerimeter(side, bottom) << "]." << std::endl << std::endl;
			}


		/* Polygon. */
		Polygon<double> poly;
		Shape<double> *ppoly = &poly;
		std::cout << "Polygon." << std::endl;

		if (Polygon<double> *p = dynamic_cast<Polygon<double>*>(ppoly))
			{
				std::cout << "Enter the number sides: ";
				std::cin >> number;
				std::cout << "Enter the length of side: ";
				std::cin >> side;
				std::cout << "Enter the apothegm: ";
				std::cin >> apothegm;

				std::cout << std::endl << "[Polygon]." << std::endl;
				std::cout << "+ Area:\t\t[" << p->getArea(number, side, apothegm) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << p->getPerimeter(number, side) << "]." << std::endl << std::endl;
			}


		/* Rectangle. */
		Rectangle<double> rect;
		Shape<double> *prect = &rect;
		std::cout << "Rectangle." << std::endl;

		if (Rectangle<double> *r = dynamic_cast<Rectangle<double>*>(prect))
			{
				std::cout << "Enter the width: ";
				std::cin >> width;
				std::cout << "Enter the height: ";
				std::cin >> height;

				std::cout << std::endl << "[Rectangle]." << std::endl;
				std::cout << "+ Area:\t\t[" << r->getArea(width, height) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << r->getPerimeter(width, height) << "]." << std::endl << std::endl;
			}

		/* Shape Base Class. */
		Shape<double> shp;
		Shape<double> *pshp = &shp;
		std::cout << "Shape." << std::endl;

		if (Shape<double> *s = dynamic_cast<Shape<double>*>(pshp))
			{
				std::cout << std::endl << "[Shape]." << std::endl;
				std::cout << "+ Area:\t\t[" << s->getArea() << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << s->getPerimeter() << "]." << std::endl << std::endl;
			}

		/* Square. */
		Square<double> sqr;
		Shape<double> *psqr = &sqr;
		std::cout << "Square." << std::endl;

		if (Square<double> *s = dynamic_cast<Square<double>*>(psqr))
			{
				std::cout << "Enter the side: ";
				std::cin >> side;

				std::cout << std::endl << "[Square]." << std::endl;
				std::cout << "+ Area:\t\t[" << s->getArea(side) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << s->getPerimeter(side) << "]." << std::endl << std::endl;
			}


		/* Trapeze. */
		Trapeze<double> trpz;
		Shape<double> *ptrpz = &trpz;
		std::cout << "Trapeze." << std::endl;

		if (Trapeze<double> *t = dynamic_cast<Trapeze<double>*>(ptrpz))
			{
				std::cout << "Enter the top: ";
				std::cin >> top;
				std::cout << "Enter the bottom: ";
				std::cin >> bottom;
				std::cout << "Enter the left side: ";
				std::cin >> left;
				std::cout << "Enter the right side: ";
				std::cin >> right;
				std::cout << "Enter the height: ";
				std::cin >> height;

				std::cout << std::endl << "[Trapeze]." << std::endl;
				std::cout << "+ Area:\t\t[" << t->getArea(top, bottom, height) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << t->getPerimeter(top, bottom, left, right) << "]." << std::endl << std::endl;
			}


		/* Triangle. */
		Triangle<double> trgl;
		Shape<double> *ptrgl = &trgl;
		std::cout << "Triangle." << std::endl;

		if (Triangle<double> *t = dynamic_cast<Triangle<double>*>(ptrgl))
			{
				std::cout << "Enter the width: ";
				std::cin >> width;
				std::cout << "Enter the height: ";
				std::cin >> height;
				std::cout << "Enter the side: ";
				std::cin >> side;

				std::cout << std::endl << "[Triangle]." << std::endl;
				std::cout << "+ Area:\t\t[" << t->getArea(width, height) << "]." << std::endl;
				std::cout << "+ Perimeter:\t[" << t->getPerimeter(side) << "]." << std::endl;
			}

		return V_ZERO;
	}
