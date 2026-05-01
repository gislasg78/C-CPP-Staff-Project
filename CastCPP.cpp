#include <iostream>

constexpr int V_ZERO {};

class Base
{
	public:
		virtual void f()
		{std::cout << "+ Base.\n";}

		virtual ~Base() = default;
};

class Derived : public Base
{
	public:
		void f()
		{std::cout << "- Derived.\n";}

		virtual ~Derived() = default;
};


int main()
{
	std::cout << "Inheritance.\n";

	/* Normal assignement. */
	Base *b = new Base;
	b->f();
	Derived *d = new Derived;
	d->f();

	/* Polymorfism. */
	Base *bd = new Derived;
	bd->f();
	bd->Base::f();

	Base *bd1 = dynamic_cast<Base*>(bd);
	bd1->f();

	/* A 'Base' object type can contain instances of objects
	   of the same type or of Derived types. */
	if (Derived *db1 = dynamic_cast<Derived*>(bd))
		db1->f();
	else
		std::cout << "It is not Derived!\n";

	delete b;
	delete d;
	delete bd;

	return V_ZERO;
}
