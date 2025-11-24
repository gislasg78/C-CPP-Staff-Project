#include <algorithm>
#include <iostream>
#include <vector>

#define	V_SIXTEEN	16
#define V_ZERO  	0

int main()
	{
		const int age = V_SIXTEEN;
		int counter = V_ZERO;
		std::vector<std::pair<std::string, int>> people = {{"Alice", 25}, {"Bob", 16}, {"Charlie", 30}, {"Dave", 17}, {"Eve", 22}};

		std::cout << "Example of pair vector dumping." << std::endl;
		std::cout << "Dumping of vector of pairs." << std::endl;
		for (std::vector<std::pair<std::string, int>>::const_iterator itc_my_people = people.cbegin(); itc_my_people != people.cend(); itc_my_people++)
			std::cout << "#: [" << counter++ << "]\t{name = [" << itc_my_people->first << "], age = [" << itc_my_people->second << "]}." << std::endl;
		std::cout << std::endl;

		people.erase(std::remove_if(people.begin(), people.end(), [&age](const std::pair<std::string, int>& my_pair){return my_pair.second == age;}), people.end());
		std::sort(std::begin(people), std::end(people), [&](const std::pair<std::string, int>& my_first_pair, const std::pair<std::string, int>& my_second_pair){return my_first_pair.second < my_second_pair.second;});

		counter = V_ZERO;
		std::cout << "Emptying a vector of pairs." << std::endl;
		for (const std::pair<std::string, int>& pair : people)
			std::cout << "#: [" << counter++ << "]\t{name = [" << pair.first << "], age = [" << pair.second << "]}." << std::endl;
		std::cout << std::endl;

		return V_ZERO;
	}
