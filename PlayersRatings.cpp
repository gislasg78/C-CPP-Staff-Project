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
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_ZERO		{T(0)};

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

/* Template function that returns the numeric distribution type of the chosen random numbers. */
template <typename T>
auto make_distribution(T minimum, T maximum)
	{
		if constexpr (std::is_integral<T>::value)
			return std::uniform_int_distribution<T>(minimum, maximum);
		else
			return std::uniform_real_distribution<T>(minimum, maximum);
	}

/* Display the values ​​corresponding to a given list. */
template <typename T>
T displayRatings(const std::string& strHeaderMsgList, const std::list<T>& playersRatings)
	{
		/* Preliminary working variables. */
		T count {V_ZERO<T>}, sum {V_ZERO<T>};

		std::cout << std::endl << "Displaying the list elements." << std::endl;

		/* Anonymous function to print each element of the list. */
		auto fnDisplayItem = [&count](const T& item) -> T
			{count++; std::cout << item << '\t'; return item;};

		std::cout << "[" << strHeaderMsgList << "]." << std::endl;
		std::for_each(playersRatings.cbegin(), playersRatings.cend(), fnDisplayItem);

		/* Algorithms prepared to accumulate the container values. */
		sum = std::accumulate(playersRatings.cbegin(), playersRatings.cend(), V_ZERO<T>);

		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

		std::cout << std::endl << "Final Results." << std::endl;
		std::cout << "+ Accumulate:\t[" << sum << "]." << std::endl;
		std::cout << "+ Sum:\t\t[" << addRatings(playersRatings.cbegin(), playersRatings.cend()) << "]." << std::endl;

		return count;
	}

/* Fill a given list with specific values. */
template <typename T>
std::list<T> fillRatings(std::list<T>& playersRatings, T& minimum, T& maximum)
	{
		/* Preliminary working variables. */
		T count {V_ZERO<T>};

		/* Swap the minimum and maximum values ​​if they are reversed. */
		if ((minimum > maximum) || (maximum < minimum))
			{swap(&minimum, &maximum);}

		/* Automatic random number generation process. */
		std::random_device myRandomDevice;
		std::mt19937 myGenerator(myRandomDevice());

		/* Verify the type of numerical distribution of the random numbers. */
		auto myDistribution = make_distribution<T>(minimum, maximum);
		std::generate(playersRatings.begin(), playersRatings.end(), [&](){return myDistribution(myGenerator);});

		/* Ordering the list and its accounting. */
		playersRatings.sort();
		count = static_cast<T>(std::count_if(std::begin(playersRatings), std::end(playersRatings), [&](const T& value){return value;}));

		/* Display the elements generated with random values. */
		std::cout << std::endl << "Filling the list elements." << std::endl;
		std::copy(playersRatings.cbegin(), playersRatings.cend(), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

		return playersRatings;
	}

/* Get a simple pause from the program. */
void getPause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/* Capture the number of values ​​to generate. */
template <typename T>
T obtainValue(const std::string& str_Message, T* data_value)
	{
		/* Preliminary working variables. */
		T t_data_value {V_ZERO<T>};
		std::string str_data_value {std::string()};

		/* Function to validate a string of characters as numeric. */
		std::function<bool(const std::string&)> IsNumeric = [&](const std::string& str_value) -> bool
			{
				return (str_value.empty()) ? false :
					std::all_of(std::begin(str_value), std::end(str_value), [&](const unsigned char& c)
					{return std::isdigit(c);});
			};

		std::cout << str_Message;
		std::getline(std::cin >> std::ws, str_data_value);

		/* A string of characters is validated as numeric. */
		if (IsNumeric(str_data_value))
			std::cout << "The value entered is numeric." << std::endl;
		else
			std::cout << "The value entered is not numeric." << std::endl;

		std::stringstream(str_data_value) >> t_data_value;

		return (data_value) ? *data_value = t_data_value : V_ZERO<T>;
	}

/* Separate the elements of a given list into two separate lists. */
template <typename T>
std::list<T> separateRatings(const std::list<T>& allPlayers, std::list<T> &playersRatings, T& minimum, T& maximum)
	{
		/* Preliminary working variables. */
		T count {V_ZERO<T>};

		/* Swap the minimum and maximum values ​​if they are reversed. */
		if ((minimum > maximum) || (maximum < minimum))
			{swap(&minimum, &maximum);}

		std::cout << std::endl << "Separating the list elements." << std::endl;
		std::cout << "Range between: [" << minimum << "] and: [" << maximum << "]." << std::endl;

		/* Copy the values ​​within the specified range from the main list to the segmented list. */
		std::copy_if(allPlayers.cbegin(), allPlayers.cend(), std::back_inserter(playersRatings),
			[&count, &minimum, &maximum](const T& value)
			{return (value >= minimum && value <= maximum) ? ++count : V_ZERO<T>;});

		/* Sort the segmented list. */
		playersRatings.sort();

		/* Copy and send the separated and segmented list to standard output. */
		std::copy(std::begin(playersRatings), std::end(playersRatings), std::ostream_iterator<T>(std::cout, "\t"));
		std::cout << std::endl << "[" << count << "] Output results generated." << std::endl;

		return playersRatings;
	}

/* Function that is responsible for swapping two variables with each other. */
template <typename T>
void swap(T* left_hand_side, T* right_hand_side)
	{
		T temp = std::move(*left_hand_side);
		*left_hand_side = std::move(*right_hand_side);
		*right_hand_side = std::move(temp);
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int int_count {V_ZERO<int>}, int_counter {}, int_quantity {V_ZERO<int>};
		int int_minimum {}, int_maximum {};

		/* The container is generated with the specified range of random values. */
		std::cout << "Players ratings." << std::endl;
		int_count = obtainValue<int>("Enter the data number: ", &int_count);

		/* Capture minimum and maximum values ​​to populate the main 'All Players' list. */
		std::cout << std::endl << "Value Range for Generative Numbers." << std::endl;
		int_minimum = obtainValue<int>("+ Generative minimum value: ", &int_minimum);
		int_maximum = obtainValue<int>("+ Generative maximum value: ", &int_maximum);

		/* Filling the main list 'All Players' with random values ​​within a given range. */
		std::list<int> allPlayers(int_count);
		allPlayers = fillRatings<int>(allPlayers, int_minimum, int_maximum);
		getPause("Press the ENTER key to continue...");

		/* This block asks how many split lists you want to generate. */
		std::cout << std::endl << "Generation of segmentation lists." << std::endl;
		int_quantity = obtainValue<int>("Enter the split lists you want: ", &int_quantity);
		std::list<std::list<int>> segmented_lists {};

		/* Capturing and separating the range of values ​​for each unique list. */
		int_counter = V_ZERO<int>;
		std::cout << std::endl << "Creation and Generation of Segmented Lists." << std::endl;
		for (int idx{}; idx < int_quantity; ++idx)
			{
				std::list<int> unique_list {};	//Single list to be filled in and stored in the list container.
				std::cout << std::endl << "Value Range for segmented list #: [" << int_counter++ + V_ONE<int> << "] of: [" << int_quantity << "]." << std::endl;

				/* Detect the minimum and maximum values ​​of each split list. */
				int_minimum = obtainValue<int>("+ Minimum value: ", &int_minimum);
				int_maximum = obtainValue<int>("+ Maximum value: ", &int_maximum);

				unique_list = separateRatings<int>(allPlayers, unique_list, int_minimum, int_maximum);
				segmented_lists.push_back(unique_list);

				getPause("Press the ENTER key to continue...");
			}
		std::cout << std::endl << "[" << int_counter << "] Output results generated." << std::endl;

		/* Display of values ​​for All Players list. */
		std::cout << std::endl << "Main List Display." << std::endl;
		int_count = displayRatings<int>("All Players", allPlayers);
		getPause("Press the ENTER key to continue...");

		/* Display of values for each segmented list. */
		int_counter = V_ZERO<int>;
		std::cout << std::endl << "Viewing Segmented Lists." << std::endl;
		for (std::list<std::list<int>>::const_iterator itc_segmented_lists = segmented_lists.cbegin(); itc_segmented_lists != segmented_lists.cend(); ++itc_segmented_lists)
			{
				std::cout << std::endl << "Display segmented list #: [" << int_counter++ + V_ONE<int> << "] of: [" << int_quantity << "].";
				int_count = displayRatings<int>("Segmented List", *itc_segmented_lists);
				getPause("Press the ENTER key to continue...");
			}
		std::cout << std::endl << "[" << int_counter << "] Output results generated." << std::endl;

		/* Program completion. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
