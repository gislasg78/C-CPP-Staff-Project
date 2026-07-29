#include <iostream>

int main()
	{
		int num1 {}, num2 {}, *p_num1 {new int()};
		int &r_num {*p_num1};

		std::cout << "Pointers & References." << std::endl;
		std::cout << "Enter a first number: ";
		std::cin >> num1;

		std::cout << "Enter a second number: ";
		std::cin >> num2;

		std::cout << std::endl << "Results." << std::endl;
		std::cout << "First Value." << std::endl;
		std::cout << "+ Address:\t[" << &num1 << "]." << std::endl;
		std::cout << "+ Value:\t[" << num1 << "]." << std::endl;
		std::cout << "Second Value." << std::endl;
		std::cout << "+ Address:\t[" << &num2 << "]." << std::endl;
		std::cout << "+ Value:\t[" << num2 << "]." << std::endl;
		std::cout << "Pointer." << std::endl;
		std::cout << "+ Address:\t[" << &p_num1 << "]." << std::endl;
		std::cout << "+ Content:\t[" << p_num1 << "]." << std::endl;
		std::cout << "+ Value:\t[" << *p_num1 << "]." << std::endl;

		p_num1 = &num1;

		std::cout << std::endl << "Results." << std::endl;
		std::cout << "Pointer." << std::endl;
		std::cout << "+ Address:\t[" << &p_num1 << "]." << std::endl;
		std::cout << "+ Content:\t[" << p_num1 << "]." << std::endl;
		std::cout << "+ Value:\t[" << *p_num1 << "]." << std::endl;
		std::cout << "Reference." << std::endl;
		std::cout << "+ Address:\t[" << &r_num << "]." << std::endl;
		std::cout << "+ Value:\t[" << r_num << "]." << std::endl;

		p_num1 = &num2;

		std::cout << std::endl << "Results." << std::endl;
		std::cout << "Pointer." << std::endl;
		std::cout << "+ Address:\t[" << &p_num1 << "]." << std::endl;
		std::cout << "+ Content:\t[" << p_num1 << "]." << std::endl;
		std::cout << "+ Value:\t[" << *p_num1 << "]." << std::endl;
		std::cout << "Reference." << std::endl;
		std::cout << "+ Address:\t[" << &r_num << "]." << std::endl;
		std::cout << "+ Value:\t[" << r_num << "]." << std::endl;

		std::cout << std::endl << "Freeing assigned memory..." << std::endl;

		delete &r_num;

		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
