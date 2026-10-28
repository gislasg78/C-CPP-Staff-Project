#include <iostream>

//Main function.
int main()
{
	/* Preliminary working variables. */
	int num {}, number {};

	/* Pointer and reference to the 'std::cout' object. */
	std::ostream& output {std::cout};
	std::ostream* ptr_output {&std::cout};

	/* Pointer and reference to the 'std::cin' object. */
	std::istream& input {std::cin};
	std::istream* ptr_input {&std::cin};

	/* Initial header messages. */
	std::cout << "'Cout' & 'Cin' Pointers & References Exercises." << std::endl;

	/* Testing the reference to the 'std::cout' and 'std::cin' objects. */
	output << std::endl << "Output Screen Reference." << std::endl;
	output << "+ Enter a value: ";
	input >> num;

	/* Testing pointers to the 'std::cout' and 'std::cin' objects. */
	*ptr_output << std::endl << "Output Screen Pointer." << std::endl;
	*ptr_output << "+ Enter a value: ";
	*ptr_input >> number;

	/* Final results. */
	std::cout << std::endl << "The values are: [" << num << "] and [" << number << "]." << std::endl;

	/* Program termination messages. */
	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended!" << std::endl;

	return EXIT_SUCCESS;
}
