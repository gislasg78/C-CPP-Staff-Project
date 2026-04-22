#include <iostream>
#include <vector>

constexpr char V_ZERO{};

class MyContainer
{
	public:
		static std::vector<char> my_vector;
};

std::vector<char> MyContainer::my_vector
{
	[]
	{
		std::vector<char> my_own_vector = std::vector<char>();

		for (char my_char{'A'}; my_char <= 'Z'; my_char++)
			my_own_vector.push_back(my_char);

		for (char my_char{'a'}; my_char <= 'z'; my_char++)
			my_own_vector.push_back(my_char);

		return my_own_vector;
	}()
};

//Main function.
int main()
{
	std::cout <<"Dumping of the static vector." << std::endl;

	for (char item : MyContainer::my_vector)
		std::cout << "[" << item << "]." << '\t';

	std::cout << std::endl;

	return V_ZERO;
}
