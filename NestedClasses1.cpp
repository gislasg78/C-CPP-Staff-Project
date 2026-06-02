#include <iostream>
#include <vector>

#define V_UPPER_CASE_A  '\x41'
#define V_UPPER_CASE_Z  '\x5a'

#define V_LOWER_CASE_A  '\x61'
#define V_LOWER_CASE_Z  '\x7a'

template <typename T>
class WhatEver
{
	public:
		static std::vector<T> st_vector;

	class InitStatic
	{
		public:
			InitStatic()
			{
				for (T v {V_LOWER_CASE_A}; v <= V_LOWER_CASE_Z; v++)
					st_vector.push_back(v);
			}
	};
};

template <typename T>
std::vector<T> WhatEver<T>::st_vector
{
	[]
	{
		std::vector<T> my_vector {std::vector<T>()};

		for (T v {V_UPPER_CASE_A}; v <= V_UPPER_CASE_Z; v++)
			my_vector.push_back(v);

		return my_vector;
	}()
};

int main()
{
	std::cout << "Static Constructors & Static Members." << std::endl;

	std::cout << std::endl << "Static vector without class instantiation." << std::endl;
	for (auto c : WhatEver<char>::st_vector)
		std::cout << "(" << c << ")." << '\t';
	std::cout << std::endl;

	std::cout << std::endl << "Static vector with class instantiation." << std::endl;
	WhatEver<char> whatever;
	for (auto c : whatever.st_vector)
		std::cout << "[" << c << "]." << '\t';
	std::cout << std::endl;

	std::cout << std::endl << "Static vector with inner class instantiation." << std::endl;
	WhatEver<char>::InitStatic s_initializer;
	for (auto c : WhatEver<char>::st_vector)
		std::cout << "{" << c << "}." << '\t';
	std::cout << std::endl;

	std::cout << "\nDone!\n";
	std::cout << "This program has ended." << '\n';

	return EXIT_SUCCESS;
}
