#include <iostream>

template <typename T>
constexpr T First_Value		{T(2.5)};
template <typename T>
constexpr T Second_Value	{T(3.75)};


template<typename T> concept Arithmetic = std::integral<T> || std::floating_point<T>;

template<Arithmetic... Arguments>
constexpr auto sum(Arguments... arguments) noexcept
{
	using CommonType = std::common_type_t<Arguments...>;
	return (static_cast<CommonType>(arguments) + ...);
}


template <typename T, typename U>
requires
(
    (std::is_integral_v<T> || std::is_floating_point_v<T>) &&
    (std::is_integral_v<U> || std::is_floating_point_v<U>)
)
constexpr std::common_type_t<T, U>
add(T a, U b) noexcept
{
	using CommonType = std::common_type_t<T, U>;
	return static_cast<CommonType>(a) + static_cast<CommonType>(b);
}


int main()
{
	std::cout << "Function Pointers." << std::endl;

	int (*pf_add_int_int)(int, int) {add<int, int>};
	double (*pf_add_float_double)(float, double) {add<float, double>};

	int (*pf_args_int_sum)(int, int, int) {sum<int, int, int>};
	double (*pf_args_double_sum)(int, float, double) {sum<int, float, double>};

	std::cout << "+ Double:\t[" << pf_add_float_double(First_Value<float>, Second_Value<double>) << "]." << std::endl;
	std::cout << "+ Double:\t[" << pf_args_int_sum(First_Value<int>, First_Value<int>, Second_Value<int>) << "]." << std::endl;
	std::cout << "+ Integer:\t[" << pf_add_int_int(First_Value<int>, Second_Value<int>) << "]." << std::endl;
	std::cout << "+ Integer:\t[" << pf_args_double_sum(First_Value<int>, Second_Value<float>, First_Value<double>) << "]." << std::endl;

	return EXIT_SUCCESS;
}
