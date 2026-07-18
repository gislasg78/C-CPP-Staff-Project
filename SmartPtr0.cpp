#include <iostream>
#include <memory>

template <typename T>
constexpr T V_ONE_HUNDRED_ONE {T(101)};

int main()
	{
		std::unique_ptr<int> ptr_int {std::make_unique<int>(V_ONE_HUNDRED_ONE<int>)};
		std::unique_ptr<int[]> ptr_array_int {std::make_unique<int[]>(V_ONE_HUNDRED_ONE<int>)};
		std::shared_ptr<int> ptr_shr_int {std::make_shared<int>(V_ONE_HUNDRED_ONE<int>)};

		std::cout << "Smart Pointers." << std::endl;

		std::cout << std::endl << "Unique Pointers." << std::endl;
		std::cout << "+ Address:\t(" << &ptr_int << ")." << std::endl;
		std::cout << "+ Content:\t[" << &(*ptr_int) << "]." << std::endl;
		std::cout << "+ Value:\t{" << *ptr_int << "}." << std::endl;

		std::cout << std::endl << "Shared Pointers." << std::endl;
		std::cout << "+ Address:\t(" << &ptr_shr_int << ")." << std::endl;
		std::cout << "+ Content:\t[" << &(*ptr_shr_int) << "]." << std::endl;
		std::cout << "+ Value:\t{" << *ptr_shr_int << "}." << std::endl;

		std::cout << std::endl << "Unique Pointer Integer Values." << std::endl;
		std::cout << "+ Address:\t(" << &ptr_array_int << ")." << std::endl;

		for (int idx{}; idx < V_ONE_HUNDRED_ONE<int>; ++idx)
			{
				ptr_array_int[idx] = idx;
				std::cout << "#: (" << idx << ") : [" << &ptr_array_int[idx] << "] = {" << ptr_array_int[idx] << "}." << std::endl;
			}

		std::cout << std::endl << "Done." << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
