#include <iostream>

template <typename T>
T Factor(const T& number, T& square, T& cube)
{
	square = number * number;
	cube = number * number * number;

	std::cout << std::endl << "Factor Reference Results." << std::endl;
	std::cout << "Number." << std::endl;
	std::cout << "+ Address:\t[" << &number << "]." << std::endl;
	std::cout << "+ Value:\t[" << number << "]." << std::endl;
	std::cout << "Square." << std::endl;
	std::cout << "+ Address:\t[" << &square << "]." << std::endl;
	std::cout << "+ Value:\t[" << square << "]." << std::endl;
	std::cout << "Cube." << std::endl;
	std::cout << "+ Address:\t[" << &cube << "]." << std::endl;
	std::cout << "+ Value:\t[" << cube << "]." << std::endl;

	return number;
}

template <typename T>
T Factor(const T& number, T *const &p_square, T *const &q_cube)
{
	*p_square = number * number;
	*q_cube = number * number * number;

	std::cout << std::endl << "Factor Pointer Results." << std::endl;
	std::cout << "Number." << std::endl;
	std::cout << "+ Address:\t[" << &number << "]." << std::endl;
	std::cout << "+ Value:\t[" << number << "]." << std::endl;
	std::cout << "Square." << std::endl;
	std::cout << "+ Address:\t[" << &p_square << "]." << std::endl;
	std::cout << "+ Content:\t[" << p_square << "]." << std::endl;
	std::cout << "+ Value:\t[" << *p_square << "]." << std::endl;
	std::cout << "Cube." << std::endl;
	std::cout << "+ Address:\t[" << &q_cube << "]." << std::endl;
	std::cout << "+ Content:\t[" << q_cube << "]." << std::endl;
	std::cout << "+ Value:\t[" << *q_cube << "]." << std::endl;

	return number;
}

int main()
{
	int number {}, outcome {};
	int *p_square {new int()}, *q_cube {new int()};

	std::cout << "Pointers and References." << std::endl;
	std::cout << "Enter a number: ";
	std::cin >> number;

	outcome = Factor(number, p_square, q_cube);

	std::cout << std::endl << "Main Pointers Results." << std::endl;
	std::cout << "Number." << std::endl;
	std::cout << "+ Address:\t[" << &number << "]." << std::endl;
	std::cout << "+ Value:\t[" << number << "]." << std::endl;
	std::cout << "Outcome." << std::endl;
	std::cout << "+ Address:\t[" << &outcome << "]." << std::endl;
	std::cout << "+ Value:\t[" << outcome << "]." << std::endl;
	std::cout << "Square." << std::endl;
	std::cout << "+ Address:\t[" << &p_square << "]." << std::endl;
	std::cout << "+ Content:\t[" << p_square << "]." << std::endl;
	std::cout << "+ Value:\t[" << *p_square << "]." << std::endl;
	std::cout << "Cube." << std::endl;
	std::cout << "+ Address:\t[" << &q_cube << "]." << std::endl;
	std::cout << "+ Content:\t[" << q_cube << "]." << std::endl;
	std::cout << "+ Value:\t[" << *q_cube << "]." << std::endl;

	outcome = Factor(number, *p_square, *q_cube);

	std::cout << std::endl << "Main References Results." << std::endl;
	std::cout << "Number." << std::endl;
	std::cout << "+ Address:\t[" << &number << "]." << std::endl;
	std::cout << "+ Value:\t[" << number << "]." << std::endl;
	std::cout << "Outcome." << std::endl;
	std::cout << "+ Address:\t[" << &outcome << "]." << std::endl;
	std::cout << "+ Value:\t[" << outcome << "]." << std::endl;
	std::cout << "Square." << std::endl;
	std::cout << "+ Address:\t[" << &p_square << "]." << std::endl;
	std::cout << "+ Content:\t[" << p_square << "]." << std::endl;
	std::cout << "+ Value:\t[" << *p_square << "]." << std::endl;
	std::cout << "Cube." << std::endl;
	std::cout << "+ Address:\t[" << &q_cube << "]." << std::endl;
	std::cout << "+ Content:\t[" << q_cube << "]." << std::endl;
	std::cout << "+ Value:\t[" << *q_cube << "]." << std::endl;

	delete p_square;
	p_square = nullptr;

	delete q_cube;
	q_cube = nullptr;

	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended." << std::endl;

	return EXIT_SUCCESS;
}
