#include <array>
#include <iostream>
#include <tuple>

template <typename... Arguments>
class MyTemplate
{
	private:
		std::tuple<Arguments...> arguments;

		template <std::size_t... Is>
		void print_recursive_arguments(std::index_sequence<Is...>, const std::tuple<Arguments...>& tuple_arguments) const
		{
			((std::cout << "- [" << std::get<Is>(tuple_arguments) << "]." << std::endl), ...);
		}

	public:
		MyTemplate(Arguments... _arguments) : arguments(_arguments...)	{}

		void print_args() const
		{
			print_recursive_arguments(std::make_index_sequence<sizeof...(Arguments)>{}, arguments);
		}
};

template <typename T>
auto min(T x)
{
	return x;
}

template <typename T, typename U>
auto min(T x, U y)
{
	return (x < y) ? x : y;
}

template <typename T, typename U, typename... Arguments>
auto min(T x, U y, Arguments... args)
{
	return min(x, min(y, args...));
}

template <typename... Arguments>
auto sum(Arguments... args)
{
	return (args + ...);
}

template <typename T, typename... Arguments>
auto summatory(T x, Arguments... args)
{
	if constexpr (sizeof...(args))
		return x + summatory(args...);
	else
		return x;
}

template <typename... Arguments>
constexpr auto get_type_sizes()
{
	std::cout << "\nType's Quantity: [" << sizeof...(Arguments) << "].\n";

	return std::array<std::size_t, sizeof...(Arguments)>{sizeof(Arguments)...};
}

template <typename Tuple>
void print_tuple(const Tuple& my_tuple)
{
	std::cout << "\nVariadic Arguments.\n";

	std::apply([](const auto&... elements)
	{
		((std::cout << "{" << elements << "}.\t"), ...);
	}, my_tuple);

	std::cout << '\n';
}

template <typename Tuple, std::size_t... Is>
void print_tuple_implicit(const Tuple& my_tuple, std::index_sequence<Is...>)
{
	((std::cout << "[" << std::get<Is>(my_tuple) << "].\t"), ...);
}

template <typename... Ts>
void print_tuple_explicit(const std::tuple<Ts...>& my_tuple)
{
	std::cout << "\nVariadic Arguments.\n";
	print_tuple_implicit(my_tuple, std::index_sequence_for<Ts...>{});
	std::cout << '\n';
}

template <typename... Ts>
void print_tuple_super_explicit(const std::tuple<Ts...>& my_tuple)
{
	constexpr std::size_t Number = sizeof...(Ts);

	std::cout << "\nVariadic Arguments.\n";
	print_tuple_implicit(my_tuple, std::make_index_sequence<Number>{});
	std::cout << '\n';
}

int main()
{
	std::tuple<int, double, std::string, int, double, std::string> my_tuple_args = std::make_tuple(1, 2.7182, "Euler", 2, 3.1416, "Pi");

	std::cout << "Variadic Templates." << std::endl;
	std::cout << "+ [" << min(42.5, 7.5) << "]." << std::endl;
	std::cout << "+ [" << min(1, 5, 3, -4, 9) << "]." << std::endl;

	print_tuple(my_tuple_args);
	print_tuple_explicit(my_tuple_args);
	print_tuple_super_explicit(my_tuple_args);

	std::cout << std::endl << "Sum: (" << summatory(1, 2, 3, 4, 5) << ")" << std::endl;
	std::cout << std::endl << "Sum: (" << sum(1.5, 2.5, 3.5, 4.5) << ")." << std::endl;

	auto sizes = get_type_sizes<char, short, int, long, long long>();

	std::cout << std::endl;
	for (size_t i{}; i < 5; i++)
		std::cout << "{" << sizes[i] << "}." << '\t';
	std::cout << std::endl << std::endl;

	MyTemplate<char, short, int, long, long long, float, double, long double, std::string> object_my_template('\n', 10, 100, 1000, 10000, 2.71f, 3.1416, 1.6667, "Hello World!");
	object_my_template.print_args();

	return 0;
}
