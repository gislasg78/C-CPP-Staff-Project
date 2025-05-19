#include <algorithm>
#include <iostream>
#include <vector>

#define	V_ZERO	0

//Main function.
int main()
	{
		//Preliminary working variables.
		int int_value_searched {V_ZERO};

		//To be able to use the characters in the Spanish language.
		setlocale(LC_ALL, "es_ES.UTF-8");

		//A dynamic array of integers is created.
		std::vector<int> int_Vector = 	{
						2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
						101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
						211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
						307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
						401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
						503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
						601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
						701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
						809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 869, 877, 881, 883, 889,
						907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
						};

		//The size of the previously created vector is displayed.
		std::cout << "Number of elements in the vector: [" << int_Vector.size() << "]." << std::endl;

		//You move through the vector and each of its elements is displayed one by one.
		std::cout << std::endl << "Content of each of the elements of the array..." << std::endl;

		for (std::vector<int>::iterator iterator_int_Vector = int_Vector.begin(); iterator_int_Vector != int_Vector.end(); iterator_int_Vector++)
			{
				std::cout << "[" << *iterator_int_Vector << "].\t";
			}

		//Find an element with the 'find' algorithm.
		std::cout << std::endl << "Enter a value to search for: ";
		std::cin >> int_value_searched;

		//Check if the value was found in the array.
		std::vector<int>::iterator iterator_searching_int_Vector = std::find(std::begin(int_Vector), std::end(int_Vector), int_value_searched);

		if (iterator_searching_int_Vector != int_Vector.end())
			{
				//Determine the relative position of the successfully located element.
				int int_position = std::distance(int_Vector.begin(), iterator_searching_int_Vector);

				std::cout << std::endl << "Value:\t\t[" << *iterator_searching_int_Vector << "] = [" << int_Vector[int_position] << "] was found!" << std::endl;
				std::cout << "Position:\t[" << int_position << "]." << std::endl;
			}
		else
			std::cout << std::endl << "Value:\t[" << int_value_searched << "] was not found!" << std::endl;

		return V_ZERO;
	}
