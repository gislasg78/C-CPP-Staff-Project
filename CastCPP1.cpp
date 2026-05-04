#include <iostream>

constexpr int V_FIVE {5};
constexpr int V_ZERO {};

class Base
{
	public:
		int num{};

		Base(int _num = V_ZERO) : num(_num) {};

		void f()
		{
			std::cout << "+ Base." << std::endl;
			std::cout << "\t* Value: [" << num << "]." << std::endl;
		}
};

class Derived : public Base
{
	public:
		int num{};

		Derived(int _num = V_ZERO) : num(_num) {};

		void f()
		{
			std::cout << "+ Derived." << std::endl;
			std::cout << "\t* Value: [" << num << "]." << std::endl;
		}
};

int main()
{
	std::cout << "Inheritance.\n";

	Derived derived {V_FIVE};
	Derived& rDerived {derived};
	Derived* pDerived {&derived};

	std::cout << "Derived." << std::endl;
	std::cout << "(" << derived.num << ")." << std::endl;
	derived.f();
	std::cout << "[" << rDerived.num << "]." << std::endl;
	rDerived.f();
	std::cout << "{" << pDerived->num << "}." << std::endl;
	pDerived->f();

	Base& rBase {derived};
	Base* pBase {&derived};

	std::cout << std::endl << "Base." << std::endl;
	std::cout << "[" << rBase.num << "]." << std::endl;
	rBase.f();
	std::cout << "{" << pBase->num << "}." << std::endl;
	pBase->f();

	return V_ZERO;
}
