#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

template <typename T>
const T V_ONE		{T(1)};
template <typename T>
const T V_TEN		{T(10)};
template <typename T>
const T V_THREE		{T(3)};
template <typename T>
const T V_TWENTY	{T(20)};
template <typename T>
const T V_TWO		{T(2)};
template <typename T>
const T V_ZERO		{T(0)};

void printRange(std::string_view str_Message, auto& my_range)
{
	std::cout << std::endl << "List of Filter's Views." << std::endl;
	std::cout << '\x5b' << str_Message << '\x5d' << '\x2e' << std::endl;

	for (const auto& value : my_range)
		std::cout << '\x5b' << value << '\x5d' << '\t';
	std::cout << std::endl;
}

int main()
{
	std::cout << "Ranges." << std::endl;

	std::vector<int> my_vec {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int *ptr_my_vec {my_vec.data()};

	std::ranges::sort(my_vec);
	std::span<int> span_range_vec(my_vec.data(), my_vec.size());
	int *ptr_data_span_range_vec{std::ranges::data(span_range_vec)};
	std::size_t size_data_span_range_vec(my_vec.size());

	int *ptr_range_vec_data = std::ranges::data(my_vec);
	std::size_t size_range_vec_data {my_vec.size()};

	if (std::ranges::empty(my_vec))
		std::cout << "The container is empty!" << std::endl;
	else
	{
		std::cout << "The container has something." << std::endl;
		std::cout << "There's something in the container." << std::endl;
	}

	std::cout << std::endl << "List of elements." << std::endl;
	for (const int& my_item_vec : my_vec)
		std::cout << '\x5b' << my_item_vec << '\x5d' << '\x2e' << '\t';
	std::cout << '\n';

	std::cout << std::endl << "List of elements." << std::endl;
	for (std::vector<int>::const_reverse_iterator itcr_my_vec = my_vec.crbegin(); itcr_my_vec != my_vec.crend(); ++itcr_my_vec)
		std::cout << '\x5b' << *itcr_my_vec << '\x5d' << '\x2e' << '\t';
	std::cout << '\n';

	std::cout << std::endl << "List of elements." << std::endl;
	for (auto itcr_my_vec {std::ranges::crbegin(my_vec)}; itcr_my_vec != std::ranges::crend(my_vec); ++itcr_my_vec)
		std::cout << '\x5b' << *itcr_my_vec << '\x5d' << '\x2e' << '\t';
	std::cout << '\n';

	std::cout << std::endl << "List of elements." << std::endl;
	for (size_t idx {V_ZERO<size_t>}; idx < size_range_vec_data; ++idx)
		std::cout << '\x5b' << ptr_range_vec_data[idx] << '\x5d' << '\x2e' << '\t';
	std::cout << '\n';

	std::cout << std::endl << "List of elements." << std::endl;
	for (size_t idx {V_ZERO<size_t>}; idx < size_data_span_range_vec; ++idx)
		std::cout << '\x5b' << ptr_data_span_range_vec[idx] << '\x5d' << '\x2e' << '\t';
	std::cout << '\n';

	std::cout << std::endl << "List of elements." << std::endl;
	for (size_t idx {V_ZERO<size_t>}; idx < my_vec.size(); ++idx)
		std::cout << '\x5b' << ptr_my_vec[idx] << '\x5d' << '\x2e' << '\t';
	std::cout << '\n';

	auto it_found_vector {std::ranges::find(my_vec, V_THREE<int>)};
	if (it_found_vector != std::end(my_vec))
		std::cout << std::endl << "Found: [" << *it_found_vector << "]." << std::endl;
	else
		std::cout << std::endl << "Not Found!" << std::endl;


	auto result1 {my_vec  | std::views::filter([](const auto& value) {return (value > V_TEN<int> && value < V_TWENTY<int>) ? value : V_ZERO<int>;})};
	printRange("Result1", result1);

	auto result2 {result1 | std::views::transform([](const auto& value) {return value * V_TWO<int>;})};
	printRange("Result2", result2);

	auto result3 {result2 | std::views::drop(V_ONE<int>)};
	printRange("Result3", result3);

	auto result4 {result3 | std::views::reverse};
	printRange("Result4", result4);

	auto result5
	{
		my_vec
		| std::views::filter([](const auto& value) {return (value > V_TEN<int> && value < V_TWENTY<int>) ? value : V_ZERO<int>;})
		| std::views::transform([](const auto& value) {return value * V_TWO<int>;})
		| std::views::drop(V_ONE<int>)
		| std::views::reverse
	};
	printRange("Result5", result5);

	auto result6
	{
		my_vec
		| std::views::filter([](const auto& value) {return (value > V_TEN<int> && value < V_TWENTY<int>) ? value : V_ZERO<int>;})
		| std::views::take(V_THREE<int>)
		| std::views::transform([](const auto& value) {return std::format(R"("{}")", value);})
	};
	printRange("Result6", result6);

	return EXIT_SUCCESS;
}
