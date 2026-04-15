/* This program is responsible for separating a linked list
   into two lists that have values ​​within ranges specified
   by the programmer. */

/* Standard work libraries. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <random>
#include <sstream>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define	V_FIVE		5
#define	V_ONE		1
#define	V_SIX		6
#define	V_TEN		10
#define	V_ZERO		0

/* Iterator to sum the elements obtained from the list. */
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

/* Display the values ​​corresponding to a given list. */
template <typename T>
T displayRatings(const std::string& strHeaderMsgList, const std::list<T>& playersRatings)
	{
		T count = V_ZERO, sum = V_ZERO;

		std::cout << std::endl << "Displaying the list elements." << std::endl;

		auto fnDisplayItem = [&count](const T& item) -> T
			{count++; std::cout << item << '\t'; return item;};

		std::cout << "[" << strHeaderMsgList << "]." << std::endl;
		std::for_each(playersRatings.cbegin(), playersRatings.cend(), fnDisplayItem);

		sum = std::accumulate(playersRatings.cbegin(), playersRatings.cend(), V_ZERO);

		std::cout << std::endl << "+ Accumulate:\t[" << sum << "]." << std::endl;
		std::cout << "+ Sum:\t\t[" << addRatings(playersRatings.cbegin(), playersRatings.cend()) << "]." << std::endl;
		std::cout << "[" << count << "] Output results generated." << std::endl;

		return count;
	}

/* Fill a given list with specific values. */
template <typename T>
T fillRatings(std::list<T>& playersRatings, const T& minimum, const T& maximum)
	{
		T count = V_ZERO, lower_bound = V_ZERO, upper_bound = V_ZERO;

		lower_bound = std::min(minimum, maximum);
		upper_bound = std::max(minimum, maximum);

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

/* Get a simple pause from the program. */
void getPause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
	}

/* Capture the number of values ​​to generate. */
template <typename T>
T obtainValue(const std::string& str_Message, T* data_value)
	{
		T t_data_value = V_ZERO;
		std::string str_data_value = std::string();

		std::function<bool(const std::string&)> IsNumeric = [&](const std::string& str_value) -> bool
			{
				if (str_value.empty()) return false;

				return std::all_of(std::begin(str_value), std::end(str_value), [&](const unsigned char& c)
					{return std::isdigit(c);});
			};

		std::cout << str_Message;
		std::getline(std::cin >> std::ws, str_data_value);

		if (IsNumeric(str_data_value))
			std::cout << std::endl << "The value entered is numeric." << std::endl;
		else
			std::cout << std::endl << "The value entered is not numeric." << std::endl;

		std::stringstream(str_data_value) >> t_data_value;

		if (data_value) *data_value = t_data_value;
		return t_data_value;
	}

/* Separate the elements of a given list into two separate lists. */
template <typename T>
std::list<T> separateRatings(const std::list<T>& allPlayers, std::list<T> &playersRating, const T& minimum, const T& maximum)
	{
		T count = V_ZERO, lower_bound = V_ZERO, upper_bound = V_ZERO;

		lower_bound = std::min(minimum, maximum);
		upper_bound = std::max(minimum, maximum);

		std::cout << std::endl << "Separating the list elements." << std::endl;
		std::cout << "Range between: [" << lower_bound << "] and: [" << upper_bound << "]." << std::endl;

		std::copy_if(allPlayers.cbegin(), allPlayers.cend(), std::back_inserter(playersRating),
			[&count, &lower_bound, &upper_bound](const T& value)
			{return (value >= lower_bound && value <= upper_bound) ? ++count : V_ZERO;});

		std::copy(std::begin(playersRating), std::end(playersRating), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

		return playersRating;
	}

//Main function.
int main()
	{
		int int_count {V_ZERO};

		std::list<int> beginners{};	//ratings 01-05.
		std::list<int> pros{};		//ratings 06-10.

		std::cout << "Players ratings." << std::endl;
		int_count = obtainValue<int>("Enter the data number: ", &int_count);

		std::list<int> allPlayers(int_count);

		int_count = fillRatings<int>(allPlayers, V_ONE, V_TEN);
		getPause("Press the ENTER key to continue...");

		beginners = separateRatings<int>(allPlayers, beginners, V_ONE, V_FIVE);
		getPause("Press the ENTER key to continue...");

		pros = separateRatings<int>(allPlayers, pros, V_SIX, V_TEN);
		getPause("Press the ENTER key to continue...");

		int_count = displayRatings<int>("All Players", allPlayers);
		getPause("Press the ENTER key to continue...");

		int_count = displayRatings<int>("Beginners", beginners);
		getPause("Press the ENTER key to continue...");

		int_count = displayRatings<int>("Pros", pros);
		getPause("Press the ENTER key to continue...");

		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return V_ZERO;
	}
