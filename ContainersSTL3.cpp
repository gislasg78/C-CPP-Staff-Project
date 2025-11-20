#include <iomanip>
#include <iostream>
#include <map>

#define SPACE           '\x20'

#define V_TWENTY_SIX    26
#define V_THREE         3
#define V_TWO           2
#define V_ZERO          0

int main()
	{
		int counter = V_ZERO;
		std::map<char, int> myMap {};
		std::cout << "Map and pair insertion exercise." << std::endl;

		for (int idx = V_ZERO; idx < V_TWENTY_SIX; idx++)
			myMap.insert(std::pair<char, int>('\x41' + idx, 0x41 + idx));

		for (int idx = V_ZERO; idx < V_TWENTY_SIX; idx++)
			myMap.insert(std::pair<char, int>('\x61' + idx, 0x61 + idx));

		std::pair<std::map<char, int>::iterator, bool> my_map_pair;
		my_map_pair = myMap.insert(std::pair<char, int>('z', V_TWENTY_SIX));

		if (!my_map_pair.second)
			std::cout << std::endl << "The element: {" << my_map_pair.first->second << "} was already inserted." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Dumping of map." << std::endl;
		for (std::map<char, int>::const_iterator it_myMap = myMap.cbegin(); it_myMap != myMap.cend(); it_myMap++)
			std::cout << "#: " << std::setw(V_TWO) << std::setfill(SPACE) << std::fixed << counter ++ << " = [" << it_myMap->first << "] : {" << std::setw(V_THREE) << std::setfill(SPACE) << std::fixed << it_myMap->second << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		return V_ZERO;
	}
