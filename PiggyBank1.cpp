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

	protected:
		static int s_counter;

	public:
		PiggyBank() = default;
		PiggyBank(const T& _coins) : ptr_coins(new T{_coins})
		{s_counter++;}

		PiggyBank(const PiggyBank& _piggybank) : ptr_coins{nullptr}
		{
			s_counter++;

			if (_piggybank.ptr_coins)
			{
				ptr_coins = new T{*_piggybank.ptr_coins};
			}
		}

		PiggyBank(PiggyBank&& _piggybank) : ptr_coins(_piggybank.ptr_coins)
		{
			s_counter--;

			_piggybank.ptr_coins = nullptr;
		}

		const T& operator()() const
		{return *ptr_coins;}

		PiggyBank& operator=(const PiggyBank& _piggybank)
		{
			if (this != &_piggybank)
			{
				s_counter++;

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
				s_counter--;

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
			std::cout << std::endl << "Dynamic pointer information." << std::endl;
			std::cout << "< Counter:\t\t<" << s_counter << ">." << std::endl;
			std::cout << "+ Address pointer:\t(" << &ptr_coins << ")." << std::endl;
			std::cout << "+ Content address:\t[" << ptr_coins << "]." << std::endl;

			if (ptr_coins)
				std::cout << "> Coins content:\t{" << *ptr_coins << "}." << std::endl;

			std::cout << std::endl;
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

template <typename T>
int PiggyBank<T>::s_counter {V_ZERO<int>};

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
	std::cout << "Test Class Pointer Value." << std::endl;

	std::cout << std::endl << "Builder with size information." << std::endl;
	PiggyBank<int> my_money_box {V_100<int>};
	std::cout << "Coins value: [" << my_money_box() << "]." << std::endl;
	enter_a_pause("Press the ENTER key to continue...");

	my_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Copy constructor." << std::endl;
	PiggyBank<int> your_money_box {my_money_box};
	my_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");
	your_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Copy assignment." << std::endl;
	PiggyBank<int> her_money_box;
	her_money_box = my_money_box;
	my_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");
	her_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Move constructor." << std::endl;
	PiggyBank<int> his_money_box {std::move(your_money_box)};
	your_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");
	his_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Move assignment." << std::endl;
	PiggyBank<int> our_money_box;
	our_money_box = std::move(my_money_box);
	my_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");
	our_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Adding & Subtracting values..." << std::endl;
	PiggyBank<int> their_money_box{V_ZERO<int>};
	their_money_box.addCoins(V_100<int>).addCoins(V_200<int>).addCoins(V_500<int>).subtractCoins(V_50<int>);
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Setting values..." << std::endl;
	their_money_box.setCoins(V_5000<int>);
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Reassignment..." << std::endl;
	their_money_box.reassignment();
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Adding & Subtracting values..." << std::endl;
	their_money_box.addCoins(V_1000<int>).addCoins(V_2000<int>).addCoins(V_5000<int>).subtractCoins(V_500<int>);
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Releasing..." << std::endl;
	their_money_box.release();
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Reassignment..." << std::endl;
	their_money_box.reassignment();
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Setting values..." << std::endl;
	their_money_box.setCoins(V_500<int>);
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Adding & Subtracting values..." << std::endl;
	their_money_box.addCoins(V_100<int>).addCoins(V_200<int>).addCoins(V_500<int>).subtractCoins(V_50<int>);
	their_money_box.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Address & Size." << std::endl;
	std::cout << "> (" << their_money_box.getPtrCoins() << ")." << std::endl;
	std::cout << "> [" << their_money_box.getCoins() << "]." << std::endl;

	std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
	std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

	return EXIT_SUCCESS;
}
