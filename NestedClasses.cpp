#include <iostream>

#define	V_FIVE	5
#define	V_TEN	10
#define	V_ZERO	0

class Container
{
	public:
		int int_public_data = V_TEN;
		static int int_static_data; // It can be accessed by the nested one.

	class Nested
	{
		public:
			void printData(const Container* ext, const Container &xtern) const
			{
				// Access to public member of the Container class.
				std::cout << "Public extern data: {[" << ext->int_public_data << "], [" << xtern.int_public_data << "]}." << std::endl;
				// Access static member of the Container class.
				std::cout << "Static extern data: {[" << int_static_data << "], [" << Container::int_static_data << "]}." << std::endl;
			}
	};
};

int Container::int_static_data = V_FIVE; // Inicialización del miembro estático

// Uso:
int main()
	{
		Container xtern;
		Container::Nested Nested;
		Nested.printData(&xtern, xtern);

		return V_ZERO;
	}
