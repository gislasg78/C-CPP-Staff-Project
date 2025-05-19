#include <iostream>

#define V_ZERO  0

struct BaseClass
	{
		BaseClass()
			{
				std::cout << std::endl << "Base Class Constructor invoked." << std::endl;
			}

		virtual const char* final_message() const
			{
				return "This message is sent from the Base Class.";
			}

		virtual ~BaseClass()
			{
				std::cout << std::endl << "Base Class Destructor invoked." << std::endl;
			}
	};

struct DerivedClass : BaseClass
	{
		DerivedClass()
			{
				std::cout << std::endl << "Derived Class Constructor invoked." << std::endl;
			}

		const char* final_message() const override
			{
				return "This message is sent from the Derived Class.";
			}

		~DerivedClass()
			{
				std::cout << std::endl << "Derived Class Destructor invoked." << std::endl;
			}
	};

int main()
	{
		BaseClass base_instance = BaseClass();
		DerivedClass derived_instance;

		BaseClass& base_reference = derived_instance;

		std::cout << "Base Class:\t" << base_instance.final_message() << std::endl;
		std::cout << "Derived Class:\t" << derived_instance.final_message() << std::endl;

		std::cout << std::endl << "Derived Instance like reference to Base Class:" << std::endl;
		std::cout << "[" << base_reference.final_message() << "]." << std::endl;

		std::cout << std::endl << "Constructing a pointer to a Derived Class as a Base Class type." << std::endl;
		BaseClass* pointer_derived_instance {new DerivedClass()};

		std::cout << "Pointer to a new derived class: [" << pointer_derived_instance << "]." << std::endl;
		std::cout << "Deleting pointer to a new derived class..." << std::endl;
		delete pointer_derived_instance;

		return V_ZERO;
	}
