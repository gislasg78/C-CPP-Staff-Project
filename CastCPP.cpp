#include <iostream>

constexpr int V_FIVE {5};
constexpr int V_TEN  {10};
constexpr int V_ZERO {};

class Base
{
	public:
		int num{};

		Base(int _num = V_ZERO) : num(_num) {};

		virtual void f()
		{
			std::cout << "+ Base." << std::endl;
			std::cout << '\t' << "* Value: [" << num << "]." << std::endl;
		}

		virtual ~Base() = default;
};

class Derived : public Base
{
	public:
		int num{};

		Derived(int _num = V_ZERO) : num(_num) {};

		void f() override
		{
			std::cout << "- Derived." << std::endl;
			std::cout << '\t' << "* Value: [" << num << "]." << std::endl;
		}

		virtual ~Derived() = default;
};


int main()
{
	std::cout << "Inheritance.\n";

	/* Normal assignement. */
	std::cout << std::endl << "Normal assignment." << std::endl;
	Base *b = new Base{V_FIVE};
	b->f();

	Derived *d = new Derived{V_TEN};
	d->f();

	/* Polymorfism. */
	std::cout << std::endl << "Polymorfism." << std::endl;
	Base *bd = new Derived{V_TEN};
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

	/* Deleting assigned pointers. */
	delete b;
	delete d;
	delete bd;

	return V_ZERO;
}
