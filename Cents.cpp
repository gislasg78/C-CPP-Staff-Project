#include <iostream>

constexpr int V_ZERO{};
constexpr int V_SIX{6};
constexpr int V_EIGHT{8};

class Cent
{
	private:
		int hundredths{};

	public:
		Cent(int _hundredths) : hundredths(_hundredths) {}

		const int& getCents() const    {return hundredths;}
};

Cent add(const Cent& c1, const Cent& c2)
{
	return Cent{c1.getCents() + c2.getCents()};
}

int main()
{
	std::cout << "I have: [" << add(Cent{V_SIX}, Cent{V_EIGHT}).getCents() << "] cents." << '\n';

	return V_ZERO;
}
