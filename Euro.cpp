#include <iostream>

constexpr int V_SEVEN{7};
constexpr int V_THREE{3};
constexpr int V_ZERO{};

class Euro
{
	private:
		int euros{};

	public:
		Euro(int _euros) : euros(_euros)	{}

		int getEuros() const			{return euros;}

		Euro operator+(const Euro& e1) const
		{return Euro{euros + e1.euros};}
};

int main()
{
	Euro euro1{V_SEVEN};
	Euro euro2{V_THREE};
	Euro sum{euro1 + euro2};

	std::cout << "I have: [" << sum.getEuros() << "] euros." << '\n';

	return V_ZERO;
}
