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
	std::cout << std::endl << "Normal assignment." << std::endl;
	Base *b = new Base;
	b->f();
	Derived *d = new Derived;
	d->f();

	/* Polymorfism. */
	std::cout << std::endl << "Polymorfism." << std::endl;
	Base *bd = new Derived;
	bd->f();
	bd->Base::f();

	/* To force the behavior of a 'Derived' class
	   as if it were exclusively a 'Base' class. */
	std::cout << std::endl << "Conversion of a 'Base' type containing a 'Derivative' object to a 'Base' type." << std::endl;
	Base *bd1 = dynamic_cast<Base*>(bd);
	bd1->f();

	Base *db = static_cast<Base*>(bd);
	db->f();

	Base *dbb = dynamic_cast<Base*>(d);
	dbb->f();

	Base *bdb = static_cast<Base*>(d);
	bdb->f();

	/* A 'Base' object type can contain instances of objects
	   of the same type or of 'Derived' types. */
	std::cout << std::endl << "Conversion of a 'Base' type containing a 'Derivative' object to a 'Derivative' type." << std::endl;

	if (Derived *db1 = dynamic_cast<Derived*>(bd))
		db1->f();
	else
		std::cout << "It is not a Derived!\n";

	Derived *bdbd = static_cast<Derived*>(bd);
	bdbd->f();

	if (Derived *bddb = dynamic_cast<Derived*>(d))
		bddb->f();
	else
		std::cout << "It is not a Derived!\n";

	Derived *bbdd = static_cast<Derived*>(d);
	bbdd->f();

	delete b;
	delete d;
	delete bd;

	return V_ZERO;
}
