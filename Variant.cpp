#include <iostream>
#include <vector>
#include <variant>
#include <string>

#define	HELLO_W	"Hello World!"

#define	V_PI	3.1415926
#define	V_TEN	10
#define	V_ZERO	0

int main()
	{
		std::vector<std::variant<int, double, std::string>> myVector;

		myVector.push_back(V_TEN);
		myVector.push_back(V_PI);
		myVector.push_back(HELLO_W);

		std::cout << "Storing different types in a vector." << std::endl;

		for (const auto& item : myVector)
			{
				std::visit([&](auto&& argument)
					{
						if constexpr (std::is_same_v<std::decay_t<decltype(argument)>, int>)
							{
								std::cout << "+ Integer:\t[" << argument << "]." << '\n';
							}
						else if constexpr (std::is_same_v<std::decay_t<decltype(argument)>, double>)
							{
								std::cout << "+ Double:\t[" << argument << "]." << '\n';
							}
						else if constexpr (std::is_same_v<std::decay_t<decltype(argument)>, std::string>)
							{
								std::cout << "+ String:\t[" << argument << "]." << '\n';
							}
					}, item);
			}

		return V_ZERO;
	}
