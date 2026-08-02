#include <iostream>
#include <limits>

template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};

class Base
	{
		public:
			Base() = default;

			virtual void f() const
				{
					std::cout << "+ <<Base>>::[f()]." << std::endl;
				}

			void g() const
				{
					std::cout << "+ <<Base>>::[g()]." << std::endl;
				}

			void k() const
				{
					std::cout << "+ <<Base>>::[k()]." << std::endl;
				}

			virtual Base* clone() const
				{
					return new Base(*this);
				}

			virtual ~Base() = default;
	};

class Derived : public Base
	{
		public:
			Derived() = default;

			void f() const override
				{
					std::cout << "- >>Derived<<::{f()}." << std::endl;
				}

			void g() const
				{
					std::cout << "- >>Derived<<::{g()}." << std::endl;
				}

			void h() const
				{
					std::cout << "- >>Derived<<::{h()}." << std::endl;
				}

			Base* clone() const override
				{
					return new Derived(*this);
				}

			~Derived() = default;
	};

void enter_a_pause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

int main()
	{
		std::cout << "Inheritance & Polymorfism Practice Exercise." << std::endl;

		std::cout << std::endl << "Base Object instantiated from the 'Base' class." << std::endl;
		Base base;
		base.f();
		base.g();
		base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' Object instantiated from the 'Derivative' class." << std::endl;
		Derived derived;
		derived.f();
		derived.g();
		derived.h();
		derived.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer instantiated from a 'Base' object." << std::endl;
		Base *p_base = new Base();
		p_base->f();
		p_base->g();
		p_base->k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' Pointer instantiated from a 'Derivative' object." << std::endl;
		Derived *p_derived = new Derived();
		p_derived->f();
		p_derived->g();
		p_derived->h();
		p_derived->k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer instantiated with a 'Derivative' object." << std::endl;
		Base *p_base_derived = new Derived();
		p_base_derived->f();
		p_base_derived->g();
		p_base_derived->k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer <dynamic cast> to 'Base' Pointer with a 'Base' object pointer." << std::endl;
		if (Base* p_base_clone = dynamic_cast<Base*>(p_base))
			{
				p_base_clone->f();
				p_base_clone->g();
				p_base_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer <dynamic cast> to 'Derivative' Pointer with a 'Base' object pointer." << std::endl;
		if (Base* p_base_clone = dynamic_cast<Derived*>(p_base))
			{
				p_base_clone->f();
				p_base_clone->g();
				p_base_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer <dynamic cast> to 'Base' Pointer with a 'Derivative' object pointer." << std::endl;
		if (Base* p_derived_clone = dynamic_cast<Base*>(p_derived))
			{
				p_derived_clone->f();
				p_derived_clone->g();
				p_derived_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer <dynamic cast> to 'Derivative' Pointer with a 'Derivative' object pointer." << std::endl;
		if (Base* p_derived_clone = dynamic_cast<Derived*>(p_derived))
			{
				p_derived_clone->f();
				p_derived_clone->g();
				p_derived_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' Pointer <dynamic cast> to 'Derivative' Pointer with a 'Derivative' object." << std::endl;
		if (Derived* p_derived_clone = dynamic_cast<Derived*>(p_derived))
			{
				p_derived_clone->f();
				p_derived_clone->g();
				p_derived_clone->h();
				p_derived_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer <dynamic cast> to 'Base' Pointer with a 'Derivative' object." << std::endl;
		if (Base* p_base_derived_clone = dynamic_cast<Base*>(p_base_derived))
			{
				p_base_derived_clone->f();
				p_base_derived_clone->g();
				p_base_derived_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' Pointer <dynamic cast> to 'Derivative' Pointer with a 'Derivative' object." << std::endl;
		if (Base* p_base_derived_clone = dynamic_cast<Derived*>(p_base_derived))
			{
				p_base_derived_clone->f();
				p_base_derived_clone->g();
				p_base_derived_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' Pointer <dynamic cast> to 'Derivative' Pointer with a 'Derivative' object." << std::endl;
		if (Derived *p_derived_base_clone = dynamic_cast<Derived*>(p_base_derived))
			{
				p_derived_base_clone->f();
				p_derived_base_clone->g();
				p_derived_base_clone->h();
				p_derived_base_clone->k();
			}
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' object initialized with a 'Base' object." << std::endl;
		Base my_base {base};
		my_base.f();
		my_base.g();
		my_base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' object initialized with a 'Derivative' object." << std::endl;
		Derived my_derived {derived};
		my_derived.f();
		my_derived.g();
		my_derived.h();
		my_derived.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' pointer obtained from the 'Base' class pointer as a 'Base' clone." << std::endl;
		Base *ptr_base_clone {base.clone()};
		if (ptr_base_clone)
			{
				ptr_base_clone->f();
				ptr_base_clone->g();
				ptr_base_clone->k();
			}

		std::cout << std::endl << "'Derivative' pointer obtained from the 'Base' class as a 'Derivative' clone." << std::endl;
		Base *ptr_base_derived_clone {derived.clone()};
		if (ptr_base_derived_clone)
			{
				ptr_base_derived_clone->f();
				ptr_base_derived_clone->g();
				ptr_base_derived_clone->k();
			}

		std::cout << std::endl << "'Derivative' Pointer <dynamic cast> to 'Derivative' Pointer with a 'Derivative' object." << std::endl;
		if (Derived* ptr_base_derived = dynamic_cast<Derived*>(ptr_base_derived_clone))
			{
				ptr_base_derived->f();
				ptr_base_derived->g();
				ptr_base_derived->h();
				ptr_base_derived->k();
			}

		std::cout << std::endl << "'Derivative' pointer obtained from the 'Derivative' class as a 'Derivative' clone." << std::endl;
		Base *ptr_derived_clone {derived.clone()};
		if (ptr_derived_clone)
			{
				ptr_derived_clone->f();
				ptr_derived_clone->g();
				ptr_derived_clone->k();
			}

		std::cout << std::endl << "'Derivative' pointer <dynamic cast> to 'Base' Pointer with a 'Derivative' object." << std::endl;
		if (Derived* ptr_inner_derived_clone = dynamic_cast<Derived*>(ptr_derived_clone))
			{
				ptr_inner_derived_clone->f();
				ptr_inner_derived_clone->g();
				ptr_inner_derived_clone->h();
				ptr_derived_clone->k();
			}

		std::cout << std::endl << "'Base' object initialized with a 'Base' object." << std::endl;
		Base slice_base {base};
		slice_base.f();
		slice_base.g();
		slice_base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' object assigned with a 'Base' object." << std::endl;
		slice_base = base;
		slice_base.f();
		slice_base.g();
		slice_base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' object assigned with a 'Derivative' object." << std::endl;
		slice_base = derived;
		slice_base.f();
		slice_base.g();
		slice_base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' object assigned with a 'Base' object pointer." << std::endl;
		slice_base = *p_base;
		slice_base.f();
		slice_base.g();
		slice_base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Base' object assigned with a 'Derivative' object pointer." << std::endl;
		slice_base = *p_derived;
		slice_base.f();
		slice_base.g();
		slice_base.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' object initialized with a 'Derivative' object." << std::endl;
		Derived slice_derived {derived};
		slice_derived.f();
		slice_derived.g();
		slice_derived.h();
		slice_derived.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "'Derivative' object assigned with a 'Derivative' object pointer." << std::endl;
		slice_derived = *p_derived;
		slice_derived.f();
		slice_derived.g();
		slice_derived.h();
		slice_derived.k();
		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "Removing dynamically assigned pointers..." << std::endl;

		if (p_base) {delete p_base; p_base = nullptr;}
		if (p_derived) {delete p_derived; p_derived = nullptr;}
		if (p_base_derived) {delete p_base_derived; p_base_derived = nullptr;}
		if (ptr_base_clone) {delete ptr_base_clone; ptr_base_clone = nullptr;}
		if (ptr_base_derived_clone) {delete ptr_base_derived_clone; ptr_base_derived_clone = nullptr;}
		if (ptr_derived_clone) {delete ptr_derived_clone; ptr_derived_clone = nullptr;}

		enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
