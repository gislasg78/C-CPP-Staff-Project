/* Standard Work Libraries. */
#include <cerrno>
#include <cstring>
#include <iostream>
#include <unistd.h>

/* Alphanumeric Symbolic Constants. */
#define NULL_CHARACTER  '\0'
#define	V_QUIT		"QUIT\n"

/* Symbolic Work Constants. */
#define V_ONE           1
#define V_ZERO          0

//Main function.
int main()
{
	/* Preliminary working variables. */
	static char buffer[BUFSIZ];

	/* A loop that will repeat as long as the buffer read from the keyboard differs from the specified text. */
	while (std::strcmp(buffer, V_QUIT))
	{
		/* Initial header messages. */
		std::cout << std::endl << "End-of-File (EOF) Checker." << std::endl;
		std::cout << "CTRL + D to send End-of-File (EOF)." << std::endl;
		std::cout << "Enter 'QUIT' to exit." << std::endl;
		std::cout << "Type something: " << std::flush;

		/* Low-level, direct reading of the input device. */
		ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer) - V_ONE);

		/* Validation of the result returned by reading the input buffer. */
		if (n > V_ZERO)		//The content of the read buffer is printed.
		{
			buffer[n] = NULL_CHARACTER;
			std::cout << "Read: " << buffer << std::endl;
		}
		else if (n == V_ZERO)	//It is printed that an End of File (EOF) was detected.
		{
			std::cout << std::endl << "End of File (EOF) detected! Please try again." << std::endl;
			continue;
		}
		else if (n < V_ZERO)	//There was an error in the keyboard input.
		{
			if (errno == EINTR)
			{
				continue;
			}

			std::cerr << "Error reading input: " << strerror(errno) << std::endl;
			break;
		}
	}

	/* Program termination messages. */
	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended." << std::endl;

	return EXIT_SUCCESS;
}
