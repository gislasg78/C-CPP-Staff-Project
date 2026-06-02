#include <iostream>
#include <vector>

template <typename T>
constexpr T V_LOWER_CASE_A	{T('\x61')};
template <typename T>
constexpr T V_LOWER_CASE_Z	{T('\x7a')};
template <typename T>
constexpr T V_UPPER_CASE_A	{T('\x41')};
template <typename T>
constexpr T V_UPPER_CASE_Z	{T('\x5a')};

template <typename T>
class WhatEver
{
	public:
		static std::vector<T> s_vector;

		void print() const
		{
			std::cout << std::endl << "Vector Contents." << std::endl;

			for (const auto& item : s_vector)
				std::cout << "{" << item << "}." << '\t';
			std::cout << std::endl;
		}

		class InitStatic
		{
			public:
				InitStatic()
				{
					for (T v {V_LOWER_CASE_A<T>}; v <= V_LOWER_CASE_Z<T>; v++)
						s_vector.push_back(v);
				}
		};

		static InitStatic s_own_initializer;
};

template <typename T>
typename WhatEver<T>::InitStatic WhatEver<T>::s_own_initializer;

template <typename T>
std::vector<T> WhatEver<T>::s_vector
{
	[]
	{
		std::vector<T> my_vector {std::vector<T>()};

		for (T v {V_UPPER_CASE_A<T>}; v <= V_UPPER_CASE_Z<T>; v++)
			my_vector.push_back(v);

		return my_vector;
	}()
};

int main()
{
	std::cout << "Static Constructors & Static Members." << std::endl;

	std::cout << std::endl << "Static vector without class instantiation." << std::endl;
	for (auto c : WhatEver<char>::s_vector)
		std::cout << "(" << c << ")." << '\t';
	std::cout << std::endl;

	std::cout << std::endl << "Static vector with class instantiation." << std::endl;
	WhatEver<char> whatever;
	for (auto c : whatever.s_vector)
		std::cout << "[" << c << "]." << '\t';
	std::cout << std::endl;

	whatever.print();

	std::cout << std::endl << "Static vector with inner class instantiation." << std::endl;
	WhatEver<char>::InitStatic s_initializer;
	for (auto c : WhatEver<char>::s_vector)
		std::cout << "{" << c << "}." << '\t';
	std::cout << std::endl;

	std::cout << std::endl << "Static vector with inner member class instantiation." << std::endl;
	/* WhatEver<char>::s_own_initializer; */
	for (auto c : WhatEver<char>::s_vector)
		std::cout << "[" << c << "]." << '\t';
	std::cout << std::endl << std::endl;

	/* whatever.s_own_initializer; */
	for (auto c : WhatEver<char>::s_vector)
		std::cout << "{" << c << "}." << '\t';
	std::cout << std::endl;

	std::cout << '\n' << "Done!" << '\n';
	std::cout << "This program has ended." << '\n';

	return EXIT_SUCCESS;
}
