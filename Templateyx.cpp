//Template specialization.
#include <iostream>

#define	CONVERSION_FACTOR	0x20

#define LOWERBOUND_UPPERCASES	'\x41'
#define UPPERBOUND_UPPERCASES	'\x5a'
#define LOWERBOUND_LOWERCASES	'\x61'
#define UPPERBOUND_LOWERCASES	'\x7a'

#define V_ZERO  0

//Class template.
template <class T>
class Vessel
	{
		private:
			T element = V_ZERO;

		public:
			Vessel (T arg)	{this->element = arg;}
			T increase ()	{return (*this).element++;}
	};

//Class template specialization.
template <>
class Vessel <char>
	{
		private:
			char element = V_ZERO;

		public:
			Vessel (char item)	{(*this).element = item;}

			char inversecase ()
				{
					if ((element >= LOWERBOUND_UPPERCASES) && (element <= UPPERBOUND_UPPERCASES) ||
					    (element >= LOWERBOUND_LOWERCASES) && (element <= UPPERBOUND_LOWERCASES))
							{
								this->element ^= CONVERSION_FACTOR;
							}

					return this->element;
				}
	};

int main()
	{
		char mychar = V_ZERO;
		int myint = V_ZERO;

		std::cout << "Generation of specialized templates in C++." << std::endl;
		std::cout << "Enter an integer: ";
		std::cin >> myint;

		std::cout << "Enter a char: ";
		std::cin >> mychar;

		Vessel<int> vessel_myint (myint);
		Vessel<char> vessel_mychar (mychar);

		std::cout << std::endl << "Results obtained." << std::endl;
		std::cout << "Integer:\t[" << vessel_myint.increase() << "]." << std::endl;
		std::cout << "Char:\t\t[" << vessel_mychar.inversecase() << "]." << std::endl;

		return V_ZERO;
	}
