/* The primary purpose of this program is to invoke a variadic function
   that is compile-time variadic template to accept any
   number of arguments—each potentially of a different type—and
   to automatically select the most appropriate type for its return value. */

/* Standard Work Libraries.  */
#include <cstdint>
#include <iostream>
#include <type_traits>

/* Defined macros. */
#define	V_TEN		10
#define	V_THIRTY	30
#define	V_TWENTY_ONE	21

/* Symbolic Work Constants. */
template <typename T>
inline constexpr T V_ZERO  {T(0)};

/* Variadic template that returns an average of a given number of arguments... */
template <typename... Arguments>
requires (sizeof...(Arguments) > V_ZERO<std::size_t>) &&
((std::integral<Arguments> || std::floating_point<Arguments>) && ...)
constexpr auto average(Arguments... arguments) noexcept
	{
		/* Validation of automatic data type inference. */
		using CommonType = std::common_type_t<Arguments...>;
		using ResultType = std::conditional_t<std::floating_point<CommonType>, CommonType, double>;

		/* Check the number of arguments provided to avoid division by zero. */
		if constexpr(sizeof...(arguments) == V_ZERO<std::size_t>)
			return V_ZERO<ResultType>;
		else
			return (static_cast<ResultType>(arguments) + ...) / ResultType(sizeof...(arguments));
	}

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		int a = V_TEN;
		int8_t b = V_TWENTY_ONE;
		uint32_t c = V_THIRTY;

		/* Validate that the type is of type 'double'. */
		static_assert(std::same_as<decltype(average(a, b, c)), double>);
		auto learnerResult = average(a, b, c);

		/* Output result generated. */
		std::cout << "Calculate the average of variadic values." << std::endl;

		std::cout << std::endl << "Output results." << std::endl;
		std::cout << "+ Value 'a':\t(" << a << ")." << std::endl;
		std::cout << "+ Value 'b':\t(" << +b << ")." << std::endl;
		std::cout << "+ Value 'c':\t(" << c << ")." << std::endl;
		std::cout << "* Result:\t{" << learnerResult << "}." << std::endl;

		/* Program termination messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
