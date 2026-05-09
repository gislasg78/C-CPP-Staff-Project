#include <algorithm>
#include <iostream>
#include <sstream>

constexpr int V_ZERO {};

template<typename TX, typename TY>
auto sum(TX x, TY y)
{return x + y;}

template<typename TX, typename TY, typename TZ>
void print(const TX& x, const TY& y, const TZ& sum)
{std::cout << "[" << x << "] + [" << y << "] = {" << sum << "}." << std::endl;}

int main()
{
	int x{}, y{};
	std::string str_value {std::string()};
	std::cout << "L-Values & R-Values." << std::endl;

	std::cout << "+ x : ";
	std::getline(std::cin >> std::ws, str_value);
	str_value.erase(std::remove_if(std::begin(str_value), std::end(str_value), ::isspace), std::end(str_value));
	std::stringstream(str_value) >> x;

	std::cout << "+ y : ";
	std::getline(std::cin >> std::ws, str_value);
	str_value.erase(std::remove_if(std::begin(str_value), std::end(str_value), ::isspace), std::end(str_value));
	std::stringstream(str_value) >> y;

	const int &&rref1 {sum<int, int>(x, y)};
	int &&rref2 {sum<int, int>(y, x)};

	print(x, y, rref1);
	print(y, x, rref2);

	return V_ZERO;
}
