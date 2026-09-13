#include <iostream>

//Main function.
int main()
	{
		/* Preliminary working variables. */
		std::string str_Message {};
		std::cout << "Traversal of a character string." << std::endl;
		std::cout << "Enter a character string: ";
		std::getline(std::cin >> std::ws, str_Message);

		/* The character string is displayed and visualized in a standard manner. */
		std::cout << std::endl << "Displaying in a standard manner." << std::endl;
		std::cout << str_Message << std::endl;

		/* Traversing the string using pointers. */
		std::cout << std::endl << "Pointer-based displacement." << std::endl;
		const char *ptr_str = str_Message.data();
		for (std::size_t idx{}; idx < str_Message.size(); idx++)
			std::cout << *(ptr_str + idx) << '\x20';
		std::cout << std::endl;

		/* Movement within the string via its [] operator. */
		std::cout << std::endl << "Offsetting using the square bracket operator." << std::endl;
		for (std::size_t idx{}; idx < str_Message.size(); idx++)
			std::cout << str_Message[idx] << '\x20';
		std::cout << std::endl;

		/* Traversal via a constant iterator. */
		std::cout << std::endl << "Navigation via iterator." << std::endl;
		for (std::string::const_iterator itc_str = str_Message.cbegin(); itc_str != str_Message.cend(); itc_str++)
			std::cout << *itc_str << '\x20';
		std::cout << std::endl;

		/* Mobilization within the chain using a 'For Each' loop. */
		std::cout << std::endl << "Displacement per cycle 'For Each'." << std::endl;
		for (const char& c : str_Message)
			std::cout << c << '\x20';
		std::cout << std::endl;

		/* Program termination messages. */
		std::cout << std::endl << "Done\x21" << std::endl;
		std::cout << "This program has ended\x2e" << std::endl;

		return EXIT_SUCCESS;
	}
