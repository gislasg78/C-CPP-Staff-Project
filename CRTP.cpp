#include <iostream>

template <typename Derivative>
class BaseMixin
{
	public:
		void getName()
		{
			(static_cast<Derivative*>(this))->implicative();
		}
};

class Derivative1 : public BaseMixin<Derivative1>
{
	public:
		void implicative()
		{
			std::cout << ".[Derivative1]::[Implicative]." << std::endl;
		}
};

class Derivative2 : public BaseMixin<Derivative2>
{
	public:
		void implicative()
		{
			std::cout << ".[Derivative2]::[Implicative]." << std::endl;
		}
};

int main()
{
	std::cout << "The Curiosly Recurring Template Pattern (CRTP)." << std::endl;

	std::cout << std::endl << "Mixin1." << std::endl;
	BaseMixin<Derivative1> mixin1;
	mixin1.getName();

	std::cout << std::endl << "Mixin2." << std::endl;
	BaseMixin<Derivative2> mixin2;
	mixin2.getName();

	std::cout << std::endl << "Derivative1." << std::endl;
	Derivative1 derivative1;
	derivative1.getName();

	std::cout << std::endl << "Derivative2." << std::endl;
	Derivative2 derivative2;
	derivative2.getName();

	std::cout << std::endl << "Done." << std::endl;
	std::cout << "This program has ended." << std::endl;

	return EXIT_SUCCESS;
}
