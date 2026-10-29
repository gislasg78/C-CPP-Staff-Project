#include <cerrno>
#include <cstring>
#include <iostream>
#include <unistd.h>

#define NULL_CHARACTER  '\0'
#define	TAG_QUIT	"QUIT"

#define V_FOUR		4
#define V_ONE           1
#define V_ZERO          0

int main()
{
	static char buffer[BUFSIZ];

	while (std::strncmp(buffer, TAG_QUIT, V_FOUR))
	{
		std::cout << "Type something (CTRL+D to send EOF. Enter 'QUIT' to exit): " << std::flush;

		ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer) - V_ONE);

		if (n > V_ZERO)
		{
			buffer[n] = NULL_CHARACTER;
			std::cout << "Read: " << buffer << std::endl;
		}
		else if (n == V_ZERO)
		{
			std::cout << std::endl << "End of File (EOF) detected! Please try again." << std::endl;
			continue;
		}
		else if (n < V_ZERO)
		{
			if (errno == EINTR)
			{
				continue;
			}

			std::cerr << "Error reading input: " << strerror(errno) << std::endl;
			break;
		}
	}

	return EXIT_SUCCESS;
}
