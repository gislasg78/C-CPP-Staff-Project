#include <iostream>

#define V_ZERO  0

enum class Colors : int
	{
		Black, Blue, Green, Cyan, Red, Purple, Brown, White
	} my_color;

int main()
	{
		int color = V_ZERO;

		std::cout << "Examples with class enumerations." << std::endl;
		std::cout<<"Enter the color number (0 - 7) : ";
		std::cin >> color;

		my_color = static_cast<Colors>(color);

		switch(my_color)
			{
				case Colors::Black:
					std::cout << "[Black]." << std::endl;
					break;

				case Colors::Blue:
					std::cout << "[Blue]." << std::endl;
					break;

				case Colors::Green:
					std::cout << "[Green]." << std::endl;
					break;

				case Colors::Cyan:
					std::cout << "[Cyan]." << std::endl;
					break;

				case Colors::Red:
					std::cout << "[Red]." << std::endl;
					break;

				case Colors::Purple:
					std::cout << "[Purple]." << std::endl;
					break;

				case Colors::Brown:
					std::cout << "[Brown]." << std::endl;
					break;

				case Colors::White:
					std::cout << "[White]." << std::endl;
					break;

				default:
					std::cout << "[Undefined Color]." << std::endl;
					break;

			}

			return V_ZERO;
	}
