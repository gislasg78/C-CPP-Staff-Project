#include <iostream>

class Base
{
	public:
		virtual Base* getThis()
		{
			std::cout << "+ Calling (Base)::(getThis()). +" << std::endl;
			return this;
		}

		void displayType() const
		{
			std::cout << "> Retrieving a 'Base' Class. <" << std::endl;
		}

		virtual void printType() const
		{
			std::cout << "> Returning a 'Base' Class. <" << std::endl;
		}

		virtual ~Base()
		{
			std::cout << "> Destroying 'Base' Class Object. <" << std::endl;
		}
};

class Derivative : public Base
{
	public:
		Derivative* getThis() override
		{
			std::cout << "- Calling [Derivative]::[getThis()]. -" << std::endl;
			return this;
		}

		void displayType() const
		{
			std::cout << "< Retrieving a 'Derivative' Class. >" << std::endl;
		}

		void printType() const override
		{
			std::cout << "< Returning a 'Derivative' Class. >" << std::endl;
		}

		virtual ~Derivative()
		{
			std::cout << "< Destroying 'Derivative' Class Object. >" << std::endl;
		}
};

int main()
{
	std::cout << "CoVariant Classes." << std::endl;

	std::cout << std::endl << "Derivative Class." << std::endl;
	Derivative derivative {};
	derivative.getThis()->printType();
	derivative.getThis()->displayType();

	std::cout << std::endl << "Pointer to Derivative Class." << std::endl;
	Derivative* ptr_derivative {&derivative};
	ptr_derivative->getThis()->printType();
	ptr_derivative->getThis()->displayType();

	std::cout << std::endl << "Pointer to Base Class from Derivative Object." << std::endl;
	Base* ptr_base {&derivative};
	ptr_base->getThis()->printType();
	ptr_base->getThis()->displayType();

	std::cout << std::endl << "Pointer to Base Class from Derivative Object." << std::endl;
	Base* ptr_base_derivative_dynamic {dynamic_cast<Base*>(&derivative)};
	ptr_base_derivative_dynamic->getThis()->printType();
	ptr_base_derivative_dynamic->getThis()->displayType();

	std::cout << std::endl << "Pointer to Base Class from Derivative Object." << std::endl;
	Base* ptr_base_derivative_static {static_cast<Base*>(&derivative)};
	ptr_base_derivative_static->getThis()->printType();
	ptr_base_derivative_static->getThis()->displayType();

	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended." << std::endl << std::endl;

	return EXIT_SUCCESS;
}
