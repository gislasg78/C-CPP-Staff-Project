/* Construction and movement allocation operator. */
#include <iostream>
#include <string>

#define V_ZERO  	0

class Vessel
	{
		public:
			std::string* ptr = nullptr;

			/* Default constructors and destructor. */
			Vessel() : ptr(new std::string())	{}
			Vessel (const std::string& str) : ptr(new std::string(str))	{}

			/* Specific motion builder. */
			Vessel (Vessel&& vessel) : ptr(vessel.ptr) {vessel.ptr = nullptr;}

			~Vessel()	{delete ptr;}

			/* Specific movement assignment operator. */
			Vessel& operator= (Vessel&& vessel)
				{
					delete ptr;
					ptr = vessel.ptr;
					vessel.ptr = nullptr;
					return *this;
				}

			/* Method to access the content of the string pointer of this class. */
			const std::string& content() const {return *ptr;}

			/* Overloaded addition operator of this class. */
			Vessel operator+ (const Vessel& vessel)
				{
					return Vessel(this->content() + vessel.content());
				}
	};


//Main function.
int main()
	{
		/* Preliminary working variables. */
		Vessel foo("Gustavo");
		Vessel bar = Vessel(" Islas ");		/* Movement class constructor. */
		Vessel baz{"Galvez"};

		std::cout << "Movement assignment builders and operators." << std::endl;

		std::cout << std::endl << "Contents of the created instances." << '\n';
		std::cout << "+ foo's content: [" << foo.content() << "]." << '\n';
		std::cout << "+ bar's content: [" << bar.content() << "]." << std::endl;
		std::cout << "+ baz's content: [" << baz.content() << "]." << std::endl;

		foo = foo + bar;			/* Movement class assignment operator. */

		std::cout << std::endl << "Contents of the created instances." << '\n';
		std::cout << "+ bar's content: [" << bar.content() << "]." << std::endl;
		std::cout << "+ foo's content: [" << foo.content() << "]." << '\n';

		foo = foo + baz;			/* Movement class assignment operator. */

		std::cout << std::endl << "Contents of the created instances." << '\n';
		std::cout << "+ baz's content: [" << baz.content() << "]." << std::endl;
		std::cout << "+ foo's content: [" << foo.content() << "]." << '\n';

		return V_ZERO;
	}
