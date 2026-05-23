#include <iostream>
#include <map>

template <typename T>
constexpr T V_ZERO {T(0)};

template <typename T>
struct parse_base
{
	using value_type = T;
};

template <typename T>
struct parse : parse_base<T>
{
	void analyzer()
	{
		typename parse_base<T>::value_type v{};
		std::cout << "Analyzing: [" << v << "].\n";
	}
};

template <typename T>
struct base_analyzer
{
	void init()
	{
		std::cout << "Initializing...\n";
	}
};

template <typename T>
struct analyzer : base_analyzer<T>
{
	void analyze()
	{
		base_analyzer<T>::init();
		std::cout << "Analyzing...\n";
	}
};

template <>
struct base_analyzer<int>
{
	void init()
	{
		std::cout << "Special Initializing...\n";
	}
};

template <typename TX, typename TY>
struct dictionary_attributes
{
	using key_type = TX;
	using value_type = TY;
	using map_type = std::map<key_type, value_type>;
	static constexpr int identity {1};
};

template <typename T>
struct dictionary : T::map_type
{
	int start_key {T::identity};
	typename T::key_type next_key;

	void print()
	{
		std::cout << "[" << start_key << "]." << std::endl;
	}
};

int main()
{
	std::cout << "Inheritance in compilation time.\n";

	analyzer<int> my_analyzer;
	my_analyzer.analyze();

	analyzer<double> your_analyzer;
	your_analyzer.analyze();

	parse<int> my_parser;
	my_parser.analyzer();

	dictionary<dictionary_attributes<int, double>> my_dict;
	my_dict.print();

	return V_ZERO<int>;
}
