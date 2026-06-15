#include <iostream>
#include <string>

template <class T>
void exchangeByCopy(T& a, T& b)
{
	T temp { a };
	a = b;
	b = temp;
}

template <class T>
void exchangeByMove(T& a, T& b)
{
	T temp {std::move(a)};
	a = std::move(b);
	b = std::move(temp);
}

int main()
{
	std::string x {"Start"};
	std::string y {"Finish"};

	std::cout << "Exchange by Value." << std::endl;
	std::cout << std::endl << "Copy exchange." << std::endl;

	std::cout << "Before exchange." << std::endl;
	std::cout << "+ x: [" << x << "]." << std::endl;
	std::cout << "+ y: [" << y << "]." << std::endl;

	exchangeByCopy(x, y);

	std::cout << "After exchange." << std::endl;
	std::cout << "- x: {" << x << "}." << std::endl;
	std::cout << "- y: {" << y << "}." << std::endl;

	std::cout << std::endl << "Move exchange." << std::endl;

	std::cout << "Before exchange." << std::endl;
	std::cout << "+ x: [" << x << "]." << std::endl;
	std::cout << "+ y: [" << y << "]." << std::endl;

	exchangeByMove(x, y);

	std::cout << "After exchange." << std::endl;
	std::cout << "- x: {" << x << "}." << std::endl;
	std::cout << "- y: {" << y << "}." << std::endl;

	exchangeByMove(x, y);

	std::cout << "\nDone!\n";
	std::cout << "This program has ended.\n";

	return EXIT_SUCCESS;
}
