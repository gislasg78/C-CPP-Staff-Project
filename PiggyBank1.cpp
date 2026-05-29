/* The primary purpose of this program is to exemplify a class as
   if it were a piggy bank and to add or subtract coins,
   but using said class as an intelligent pointer and
   with very precise memory release and allocation controls.
*/

/* Libraries Standards of Work. */
#include <iostream>
#include <limits>

/* Work template variables. */
template <typename T>
constexpr T V_50		{T(50)};
template <typename T>
constexpr T V_100		{T(100)};
template <typename T>
constexpr T V_200		{T(200)};
template <typename T>
constexpr T V_500		{T(500)};
template <typename T>
constexpr T V_1000		{T(1000)};
template <typename T>
constexpr T V_2000		{T(2000)};
template <typename T>
constexpr T V_5000		{T(5000)};

/* Predefined variables. */
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};
template <typename T>
constexpr T V_ZERO		{T(0)};

template <typename T>
class PiggyBank
{
	private:
		T *ptr_coins{nullptr};

	public:
		PiggyBank() = default;
		PiggyBank(const T& _coins) : ptr_coins(new T{_coins})	{}
		PiggyBank(const PiggyBank& _piggybank) : ptr_coins{nullptr}
		{
			if (_piggybank.ptr_coins)
			{
				ptr_coins = new T{*_piggybank.ptr_coins};
			}
		}

		PiggyBank(PiggyBank&& _piggybank) : ptr_coins(_piggybank.ptr_coins)
		{
			_piggybank.ptr_coins = nullptr;
		}

		PiggyBank& operator=(const PiggyBank& _piggybank)
		{
			if (this != &_piggybank)
			{
				release();

				if (!ptr_coins && _piggybank.ptr_coins)
				{
					ptr_coins = new T{*_piggybank.ptr_coins};
				}
			}

			return *this;
		}

		PiggyBank& operator=(PiggyBank&& _piggybank)
		{
			if (this != &_piggybank)
			{
				release();

				if (!ptr_coins && _piggybank.ptr_coins)
				{
					ptr_coins = _piggybank.ptr_coins;
					_piggybank.ptr_coins = nullptr;
				}
			}

			return *this;
		}

		PiggyBank<T>& addCoins(const T& _coins)
		{
			if (ptr_coins)
				*ptr_coins += _coins;

			return *this;
		}

		const T& getCoins() const {return (ptr_coins) ? *ptr_coins : V_ZERO<T>;}
		const T* const& getPtrCoins() const {return ptr_coins;}

		void print() const
		{
			std::cout << std::endl << "PiggyBank info." << std::endl;
			std::cout << "* Address:\t(" << ptr_coins << ")." << std::endl;

			if (ptr_coins)
				std::cout << "+ Coins:\t[" << *ptr_coins << "]." << std::endl;
		}

		void reassignment()
		{
			release();

			if (!ptr_coins)
				ptr_coins = new T{};
		}

		void release()
		{
			if (ptr_coins)
			{
				delete ptr_coins;
				ptr_coins = nullptr;
			}
		}

		void setCoins(const T& _coins)
		{
			if (ptr_coins)
				*ptr_coins = _coins;
		}

		PiggyBank<T>& subtractCoins(const T& _coins)
		{
			if (ptr_coins)
				*ptr_coins -= _coins;

			return *this;
		}

		~PiggyBank()	{release();}
};

void enter_a_pause(const std::string& str_Message)
{
	std::cout << str_Message;
	std::cin.clear();
	std::cin.get();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
}

int main()
{
	std::cout << "Replacing Class Pointers." << std::endl;

	PiggyBank<int> my_money_box {V_100<int>}, your_money_box {V_200<int>}, her_money_box {V_500<int>};
	PiggyBank<int> his_money_box {her_money_box}, temp_money_box {std::move(her_money_box)};
	PiggyBank<int> *ptr_my_money_box {&my_money_box}, *ptr_your_money_box {&your_money_box};
	PiggyBank<int> *ptr_her_money_box {&her_money_box}, *ptr_his_money_box {&his_money_box};
	PiggyBank<int> *ptr_temp_money_box {&temp_money_box};

	ptr_my_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	ptr_your_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	ptr_her_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	ptr_his_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	ptr_temp_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	std::swap(ptr_my_money_box, ptr_your_money_box);

	ptr_my_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	ptr_your_money_box->print();
	enter_a_pause("Press the ENTER key to continue...");

	my_money_box.addCoins(V_100<int>).addCoins(V_200<int>).addCoins(V_500<int>).subtractCoins(V_50<int>);
	my_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	your_money_box.setCoins(V_5000<int>);
	your_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box.reassignment();
	her_money_box.addCoins(V_1000<int>).addCoins(V_2000<int>).addCoins(V_5000<int>).subtractCoins(V_500<int>);
	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	temp_money_box = std::move(her_money_box);
	temp_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box = his_money_box;
	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	his_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	his_money_box.release();
	his_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	his_money_box.reassignment();
	his_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	his_money_box.addCoins(V_1000<int>).addCoins(V_2000<int>).addCoins(V_5000<int>).subtractCoins(V_500<int>);
	his_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box = std::move(his_money_box);
	his_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box.reassignment();
	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	her_money_box.release();
	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
	std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

	return EXIT_SUCCESS;
}
