/* Standard Work Libraries. */
#include <iostream>
#include <limits>
#include <string>
#include <termios.h>
#include <unistd.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN	'\n'
#define	V_QUIT		"QUIT"

/* Symbolic Work Constants. */
#define V_MINUS_ONE	-1
#define V_ONE		1
#define V_ZERO		0

//Main function.
int main()
{
	/* Preliminary Working Variables. */
	std::string str_value{};
	termios old_term{}, new_term{};

	/* The goal is to obtain the precise configuration of the current terminal. */
	if (tcgetattr(STDIN_FILENO, &old_term) == V_MINUS_ONE)
	{
		std::cerr << "It was not possible to obtain the precise terminal configuration." << std::endl;
		return V_ONE;
	}

	new_term = old_term;	//Assignment from the old terminal to the new terminal.

	/* Disable the 'End of File' ('EOF') special character (CTRL + D). */
	new_term.c_cc[VEOF] = _POSIX_VDISABLE;

	/* An attempt is being made to modify the specific configuration of the current terminal. */
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) == V_MINUS_ONE)
	{
		std::cerr << "It was not possible to modify the terminal's specific configuration." << std::endl;
		return V_ONE;
	}

	/* A loop or cycle that repeats until the word 'QUIT' is entered. */
	while (str_value != V_QUIT)
	{
		/* Initial header messages. */
		std::cout << std::endl << "Terminal Control Test." << std::endl;
		std::cout << "Type \'QUIT\' to exit." << std::endl;
		std::cout << "Enter text: " << std::flush;

		/* Process input from the keyboard. */
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

	/* Reset the input and output attributes of the current terminal. */
	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);

	/* Program termination messages. */
	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended." << std::endl;

	return EXIT_SUCCESS;
}
