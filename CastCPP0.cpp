#include <iostream>

constexpr int V_ZERO {};

class Base
{
	public:
		void f()
		{
			std::cout << "+ Base." << std::endl;
		}
};

class Derived : public Base
{
	public:
		void f()
		{
			std::cout << "+ Derived." << std::endl;
		}
};

int main()
{
	std::cout << "Inheritance.\n";

	/* Normal assignement. */
	std::cout << std::endl << "Normal assignment." << std::endl;
	Base b;
	b.f();

	Derived d;
	d.f();
	d.Base::f();

	/* Object Slicing. */
	std::cout << std::endl << "Object Slicing." << std::endl;
	Base bd {Derived{}};
	bd.f();

	/* To force the behavior of a 'Base' class
	   as if it were exclusively a 'Derivative' class. */
	std::cout << std::endl << "Conversion of a 'Base' type initialized with a 'Derivative' object." << std::endl;
	Derived *db {static_cast<Derived*>(&bd)};
	(*db).f();

	return V_ZERO;
}
