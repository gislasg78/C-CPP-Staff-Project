#include <iomanip>
#include <iostream>
#include <vector>

#define	V_ONE_HUNDRED_ONE	101
#define	V_FOUR			4
#define	V_THREE			3
#define	V_TWO			2
#define V_ZERO  		0

int main()
	{
		int counter = V_ZERO;
		std::vector<int> myVec = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		auto it = myVec.begin() + V_FOUR;

		std::cout << "Dumping a vector." << std::endl;
		for (std::vector<int>::const_iterator itc_myVec = myVec.cbegin(); itc_myVec != myVec.cend(); itc_myVec++)
			std::cout << "#: [" << std::setw(V_TWO) << std::fixed << counter++ << "] = {" << std::setw(V_THREE) << std::fixed << *itc_myVec << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		std::cout << std::endl << "Vector practice." << std::endl;
		std::cout << "*it = [" << *it << "]." << std::endl;
		std::cout << "*begin = [" << *myVec.begin() << "]." << std::endl;
		std::cout << "it - begin = [" << it - myVec.begin() << "]." << std::endl;
		std::cout << "Distance = {" << std::distance(myVec.begin(), it) << "}." << std::endl;
		std::cout << "*it - *begin = [" << *it - *myVec.begin() << "]." << std::endl;

		it = myVec.insert(it, V_ONE_HUNDRED_ONE);
		std::cout << std::endl << "Vector insertion." << std::endl;
		std::cout << "*it = [" << *it << "]." << std::endl;
		std::cout << "*begin = [" << *myVec.begin() << "]." << std::endl;
		std::cout << "it - begin = [" << it - myVec.begin() << "]." << std::endl;
		std::cout << "Distance = {" << std::distance(myVec.begin(), it) << "}." << std::endl;
		std::cout << "*it - *begin = [" << *it - *myVec.begin() << "]." << std::endl << std::endl;
		std::cout << "Value #4: [" << myVec[V_FOUR] << "]." << std::endl << std::endl;

		counter = V_ZERO;
		std::cout << "Dumping a vector." << std::endl;
		for (int item : myVec)
			std::cout << "#: [" << std::setw(V_TWO) << std::fixed << counter++ << "] = {" << std::setw(V_THREE) << std::fixed << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		return V_ZERO;
	}
