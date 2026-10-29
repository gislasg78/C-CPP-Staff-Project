#include <iostream>
#include <limits>
#include <string>
#include <termios.h>
#include <unistd.h>

#define	CARRIAGE_RETURN	'\n'
#define	V_QUIT		"QUIT"

#define V_MINUS_ONE	-1
#define V_ONE		1
#define V_ZERO		0

int main()
{
	std::string str_value{};
	termios old_term{}, new_term{};

	if (tcgetattr(STDIN_FILENO, &old_term) == V_MINUS_ONE)
	{
		std::cerr << "It was not possible to obtain the precise terminal configuration." << std::endl;
		return V_ONE;
	}

	new_term = old_term;

	/* Disable the 'End of File' ('EOF') special character (CTRL + D). */
	new_term.c_cc[VEOF] = _POSIX_VDISABLE;

	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) == V_MINUS_ONE)
	{
		std::cerr << "It was not possible to modify the terminal's specific configuration." << std::endl;
		return V_ONE;
	}

	while (str_value != V_QUIT)
	{
		std::cout << "Enter text (Type 'QUIT' to exit): " << std::flush;

		if (std::getline(std::cin >> std::ws, str_value))
		{
			std::cout << "Entered text: " << str_value << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
		}
	}

	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);

	return EXIT_SUCCESS;
}
