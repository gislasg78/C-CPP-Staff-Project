#include <iostream>

#define V_ONE_HUNDRED_THREE 103

int main()
	{
		int *ptr_number {new int{V_ONE_HUNDRED_THREE}};
		int &ref_number {*ptr_number};
		int* &ptr_ref_number {ptr_number};
		int* &&ptr_ref_ref_number {new int{V_ONE_HUNDRED_THREE}};

		std::cout << "Pointers with references." << std::endl;

		std::cout << std::endl << "Assigning..." << std::endl;
		std::cout << "Pointer Number." << std::endl;
		std::cout << "+ Address:\t[" << &ptr_number << "]." << std::endl;
		std::cout << "+ Pointer:\t[" << ptr_number << "]." << std::endl;
		std::cout << "+ Content:\t[" << *ptr_number << "]." << std::endl;

		std::cout << "Pointer Reference Number." << std::endl;
		std::cout << "+ Address:\t[" << &ptr_ref_number << "]." << std::endl;
		std::cout << "+ Pointer:\t[" << ptr_ref_number << "]." << std::endl;
		std::cout << "+ Content:\t[" << *ptr_ref_number << "]." << std::endl;

		std::cout << "Pointer Reference RValue Number." << std::endl;
		std::cout << "+ Address:\t[" << &ptr_ref_ref_number << "]." << std::endl;
		std::cout << "+ Pointer:\t[" << ptr_ref_ref_number << "]." << std::endl;
		std::cout << "+ Content:\t[" << *ptr_ref_ref_number << "]." << std::endl;

		std::cout << "Reference Number." << std::endl;
		std::cout << "+ Reference:\t[" << ref_number << "]." << std::endl;

		delete ptr_number;
		delete ptr_ref_ref_number;
		ptr_number = ptr_ref_ref_number = nullptr;

		std::cout << std::endl << "Releasing..." << std::endl;
		std::cout << "Pointer Number." << std::endl;
		std::cout << "+ Address:\t[" << &ptr_number << "]." << std::endl;
		std::cout << "+ Pointer:\t[" << ptr_number << "]." << std::endl;

		std::cout << "Pointer Reference Number." << std::endl;
		std::cout << "+ Address:\t[" << &ptr_ref_number << "]." << std::endl;
		std::cout << "+ Pointer:\t[" << ptr_ref_number << "]." << std::endl;

		std::cout << "Pointer Reference RValue Number." << std::endl;
		std::cout << "+ Address:\t[" << &ptr_ref_ref_number << "]." << std::endl;
		std::cout << "+ Pointer:\t[" << ptr_ref_ref_number << "]." << std::endl;

		if (ptr_number && ptr_ref_ref_number)
			{
				std::cout << "+ Content:\t[" << *ptr_number << "]." << std::endl;
				std::cout << "+ Content:\t[" << *ptr_ref_number << "]." << std::endl;
				std::cout << "+ Content:\t[" << *ptr_ref_ref_number << "]." << std::endl;
				std::cout << "+ Reference:\t[" << ref_number << "]." << std::endl;
			}

		std::cout << std::endl << "Done." << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
