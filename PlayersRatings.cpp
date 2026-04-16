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
#define	V_ZERO		0

/* Declaration of function prototypes. */
template <typename T> void swap(T* left_hand_side, T* right_hand_side);

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
T fillRatings(std::list<T>& playersRatings, T& minimum, T& maximum)
	{
		T count = V_ZERO;

		/* Swap the minimum and maximum values ​​if they are reversed. */
		if ((minimum > maximum) || (maximum < minimum))
			{swap(&minimum, &maximum);}

		std::random_device myRandomDevice;
		std::mt19937 myGenerator(myRandomDevice());
		std::uniform_int_distribution<> myDistribution(minimum, maximum);

		std::generate(playersRatings.begin(), playersRatings.end(), [&](){return myDistribution(myGenerator);});

		count = static_cast<T>(std::count_if(std::begin(playersRatings), std::end(playersRatings), [&](const T& value){return value;}));

		std::cout << std::endl << "Filling the list elements." << std::endl;
		std::copy(playersRatings.cbegin(), playersRatings.cend(), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

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
std::list<T> separateRatings(const std::list<T>& allPlayers, std::list<T> &playersRating, T& minimum, T& maximum)
	{
		T count = V_ZERO;

		/* Swap the minimum and maximum values ​​if they are reversed. */
		if ((minimum > maximum) || (maximum < minimum))
			{swap(&minimum, &maximum);}

		std::cout << std::endl << "Separating the list elements." << std::endl;
		std::cout << "Range between: [" << minimum << "] and: [" << maximum << "]." << std::endl;

		std::copy_if(allPlayers.cbegin(), allPlayers.cend(), std::back_inserter(playersRating),
			[&count, &minimum, &maximum](const T& value)
			{return (value >= minimum && value <= maximum) ? ++count : V_ZERO;});

		std::copy(std::begin(playersRating), std::end(playersRating), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

		return playersRating;
	}

/* Function that is responsible for swapping two variables with each other. */
template <typename T>
void swap(T* left_hand_side, T* right_hand_side)
	{
		T temp = *left_hand_side;
		*left_hand_side = *right_hand_side;
		*right_hand_side = temp;
	}

//Main function.
int main()
	{
		int int_count {V_ZERO};
		int int_minimum {}, int_maximum {};
		int int_beginners_minimum{}, int_beginners_maximum{};
		int int_pros_minimum{}, int_pros_maximum{};

		std::list<int> beginners{};
		std::list<int> pros{};

		std::cout << "Players ratings." << std::endl;
		int_count = obtainValue<int>("Enter the data number: ", &int_count);

		std::cout << std::endl << "Value Range for Generative Numbers." << std::endl;
		int_minimum = obtainValue<int>("+ Generative minimum value: ", &int_minimum);
		int_maximum = obtainValue<int>("+ Generative maximum value: ", &int_maximum);

		std::list<int> allPlayers(int_count);

		int_count = fillRatings<int>(allPlayers, int_minimum, int_maximum);
		getPause("Press the ENTER key to continue...");

		std::cout << std::endl << "Value Range for Beginners." << std::endl;
		int_beginners_minimum = obtainValue<int>("+ Beginners minimum value: ", &int_beginners_minimum);
		int_beginners_maximum = obtainValue<int>("+ Beginners maximum value: ", &int_beginners_maximum);

		beginners = separateRatings<int>(allPlayers, beginners, int_beginners_minimum, int_beginners_maximum);
		getPause("Press the ENTER key to continue...");

		std::cout << std::endl << "Value Range for Pros." << std::endl;
		int_pros_minimum = obtainValue<int>("+ Pros minimum value: ", &int_pros_minimum);
		int_pros_maximum = obtainValue<int>("+ Pros maximum value: ", &int_pros_maximum);

		pros = separateRatings<int>(allPlayers, pros, int_pros_minimum, int_pros_maximum);
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
