#include <algorithm>
#include <iostream>
#include <iterator>
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


template <typename Iter>
typename std::iterator_traits<Iter>::value_type addRatings(Iter start, Iter finish)
	{
		typename std::iterator_traits<Iter>::value_type addition = {};

		for (Iter it = start; it != finish; ++it)
			{
				addition += *it;
			}

		return addition;
	}

template <typename T>
T displayRatings(const std::string& strHeaderMsgList, const std::list<T>& playersRatings)
	{
		T count = V_ZERO;

		std::cout << std::endl << "Displaying the list elements." << std::endl;

		auto fnDisplayItem = [&count] (const T& item) -> T
			{count++; std::cout << item << '\t'; return item;};

		std::cout << "[" << strHeaderMsgList << "]." << std::endl;
		std::for_each(playersRatings.cbegin(), playersRatings.cend(), fnDisplayItem);

		std::cout << std::endl << "Sum:\t[" << addRatings(playersRatings.begin(), playersRatings.end()) << "]." << std::endl;
		std::cout << "[" << count << "] Output results generated." << std::endl;

		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);

		return count;
	}

template <typename T>
T fillRatings(std::list<T>& playersRatings, const T& lower_bound, const T& upper_bound)
	{
		T count = V_ZERO;

		std::random_device myRandomDevice;
		std::mt19937 myGenerator(myRandomDevice());
		std::uniform_int_distribution<> myDistribution(lower_bound, upper_bound);

		std::generate(playersRatings.begin(), playersRatings.end(), [&]()
			{return myDistribution(myGenerator);});

		std::cout << std::endl << "Filling the list elements." << std::endl;
		std::copy(playersRatings.cbegin(), playersRatings.cend(), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl;

		return count;
	}

template <typename T>
T obtainValue(const std::string& str_Message, T* data_value)
	{
		T t_data_value = V_ZERO;
		std::string str_data_value = {};

		std::cout << "Enter the data number: ";
		std::getline(std::cin >> std::ws, str_data_value);
		std::stringstream(str_data_value) >> t_data_value;

		*data_value = t_data_value;
		return t_data_value;
	}

template <typename T>
T separateRatings(const std::list<T>& allPlayers, std::list<T> &beginners, std::list<T> &pros)
	{
		T count = V_ZERO;

		std::cout << std::endl << "Separating the list elements." << std::endl;
		std::copy(std::begin(allPlayers), std::end(allPlayers), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl;

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

		std::list<int> beginners{};	//ratings 01-05.
		std::list<int> pros{};		//ratings 06-10.

		std::cout << "Players ratings." << std::endl;
		int_count = obtainValue<int>("Enter the data number: ", &int_count);

		std::list<int> allPlayers(int_count);

		int_count = fillRatings<int>(allPlayers, V_ONE, V_TEN);
		int_count = separateRatings<int>(allPlayers, beginners, pros);

		int_count = displayRatings<int>("All Players", allPlayers);
		int_count = displayRatings<int>("Beginners", beginners);
		int_count = displayRatings<int>("Pros", pros);

		return V_ZERO;
	}
