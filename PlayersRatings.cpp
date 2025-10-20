#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <random>
#include <sstream>

#define	CARRIAGE_RETURN	'\n'

#define	V_FIVE		5
#define	V_ONE		1
#define	V_SIX		6
#define	V_TEN		10
#define	V_ZERO		0

template <typename T>
T displayRatings(const std::string& strHeaderMsgList, const std::list<T>& playersRatings)
	{
		T count = V_ZERO;

		auto fnDisplayItem = [&count] (const T& item) -> T
			{count++; std::cout << "(" << item << ")." << '\t'; return item;};

		std::cout << "[" << strHeaderMsgList << "]." << std::endl;
		std::for_each(playersRatings.cbegin(), playersRatings.cend(), fnDisplayItem);

		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);

		return count;
	}

template <typename T>
T insertRatings(const std::list<T>& allPlayers, std::list<T> &beginners, std::list<T> &pros)
	{
		T count = V_ZERO;

		for (std::list<int>::const_iterator c_it_allPlayers = allPlayers.cbegin(); c_it_allPlayers != allPlayers.cend(); c_it_allPlayers++, count++)
			{
				if (*c_it_allPlayers >= V_ONE && *c_it_allPlayers <= V_FIVE)
					beginners.push_back(*c_it_allPlayers);
				else if (*c_it_allPlayers >= V_SIX && *c_it_allPlayers <= V_TEN)
					pros.push_back(*c_it_allPlayers);
			}

		return count;
	}

int main()
	{
		int int_count {V_ZERO};
		std::string str_count = {};

		std::random_device myRandomDevice;
		std::mt19937 myGenerator(myRandomDevice());
		std::uniform_int_distribution<> myDistribution(V_ONE, V_TEN);

		std::cout << "Players ratings." << std::endl;
		std::cout << "Enter the data number: ";
		std::getline(std::cin >> std::ws, str_count);
		std::stringstream(str_count) >> int_count;

		std::list<int> allPlayers(int_count);
		std::generate(allPlayers.begin(), allPlayers.end(), [&]()
			{return myDistribution(myGenerator);});

		std::list<int> beginners{};	//ratings 01-05.
		std::list<int> pros{};		//ratings 06-10.

		int_count = insertRatings<int>(allPlayers, beginners, pros);

		int_count = displayRatings<int>("All Players", allPlayers);
		int_count = displayRatings<int>("Beginners", beginners);
		int_count = displayRatings<int>("Pros", pros);

		return V_ZERO;
	}
