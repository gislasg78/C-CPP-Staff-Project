#include <iostream>

template <typename T>
constexpr T V_ZERO {T(0)};

template <typename T>
class PiggyBank
{
	private:
		T coins{};

	public:
		PiggyBank() = default;
		PiggyBank(const T& _coins) : coins(_coins) {}
		PiggyBank(const PiggyBank& _piggybank) : coins(_piggybank.coins) {}
		PiggyBank(PiggyBank&& _piggybank) : coins(_piggybank.coins) {_piggybank.coins = V_ZERO<T>;}

		PiggyBank& operator=(const PiggyBank& _piggybank)
		{coins = _piggybank.coins; return *this;}
		PiggyBank& operator=(PiggyBank&& _piggybank)
		{coins = _piggybank.coins; _piggybank.coins = V_ZERO<T>; return *this;}

		PiggyBank<T>& addCoins(const T& _coins) {coins += _coins; return *this;}

		const T& getCoins() const {return coins;}
		T& getCoins() {return coins;}

		void print() const
		{
			std::cout << std::endl << "PiggyBank info." << std::endl;
			std::cout << "+ Coins: [" << coins << "]." << std::endl;
		}

		void setCoins(const T& _coins) {coins = _coins;}

		PiggyBank<T>& subtractCoins(const T& _coins) {coins -= _coins; return *this;}

		~PiggyBank() = default;
};

int main()
{
	std::cout << "Replacing Class Pointers." << std::endl;

	PiggyBank<int> my_money_box{100}, your_money_box{200}, temp_money_box{your_money_box};
	PiggyBank<int> *ptr_my_money_box {&my_money_box}, *ptr_your_money_box {&your_money_box}, *ptr_temp_money_box{&temp_money_box};

	ptr_my_money_box->print();
	ptr_your_money_box->print();
	(*ptr_temp_money_box).print();

	std::swap(ptr_my_money_box, ptr_your_money_box);

	ptr_my_money_box->print();
	ptr_your_money_box->print();

	my_money_box.addCoins(200).addCoins(300).subtractCoins(50);
	my_money_box.print();

	your_money_box.getCoins() = 500;
	your_money_box.print();

	temp_money_box = my_money_box;
	temp_money_box.print();

	return EXIT_SUCCESS;
}
