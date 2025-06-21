//StringStreams.
#include <iostream>
#include <string>
#include <sstream>

#define V_ZERO  0

int main ()
	{
		float price = V_ZERO;
		int quantity = V_ZERO;
		std::string mystr = std::string();

		std::cout << "Enter price: ";
		std::getline(std::cin, mystr);
		std::stringstream(mystr) >> price;

		std::cout << "Enter quantity: ";
		std::getline(std::cin, mystr);
		std::stringstream(mystr) >> quantity;

		auto total = price * static_cast<float>(quantity);

		std::cout << "Total price: [" << total << "]." << std::endl;

		return V_ZERO;
	}
