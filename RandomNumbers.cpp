/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */

/* Standard work libraries. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <vector>

/* Symbolic character constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{static_cast<T>('\n')};

/* Numeric symbolic constants. */
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Random number generator. */
#define RANDOM_GENERATOR(s)	(((V_MULTIPLIER) * (s) + (V_INCREMENTER)) % (V_MODULUS))
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

/* Forward prototypes of classes and functions. */
template <typename T>
class RandomNumber;

/* Base class that generates random numbers based on an initial seed value. */
template <typename T>
class RandomNumber
	{
		private:
			T random_counter = V_ZERO<T>;
			T random_number = V_ZERO<T>;
			T random_seed = V_ZERO<T>;

			friend std::istream &operator>> (std::istream &in, RandomNumber<T> &random_number)
				{random_number.capture(); return in;}
			friend std::ostream& operator<< (std::ostream& out, RandomNumber<T>& random_number)
				{random_number.print(); return out;}

		protected:
			static std::size_t counter;

		public:
			using value_type = T;

			RandomNumber() : random_counter(V_ZERO<T>), random_number(V_ZERO<T>), random_seed(V_ZERO<T>)
				{this->counter++; this->capture();}
			RandomNumber(const T& _random_seed) : random_counter(V_ZERO<T>), random_number(_random_seed), random_seed(_random_seed)
				{this->counter++; this->random_number = this->GenerateRandom();}
			RandomNumber(const T& _random_counter, const T& _random_seed) : random_counter(random_counter), random_number(_random_seed), random_seed(random_seed)
				{this->counter++; (*this).random_number = this->giveRandom(random_counter, random_seed);}

			RandomNumber(const RandomNumber<T>& _random_number) : random_counter(_random_number.random_counter), random_number(_random_number.random_number), random_seed(_random_number.random_seed)
				{(*this).counter++;}
			RandomNumber(RandomNumber<T>&& _random_number) : random_counter(_random_number.random_counter), random_number(_random_number.random_number), random_seed(_random_number.random_seed)
				{(*this).counter++; _random_number.reset();}

			RandomNumber<T>& operator=(const T& _random_seed)
				{(*this).random_seed = _random_seed; (*this).restore(); return *this;}
			RandomNumber<T>& operator=(const RandomNumber<T> &_random_number)
				{this->copy(_random_number); return *this;}
			RandomNumber<T>& operator=(RandomNumber<T>&& _random_number)
				{this->copy(_random_number); _random_number.reset(); return *this;}

			RandomNumber<T>& operator()()
				{this->random_number = this->GenerateRandom(); return *this;}
			RandomNumber<T>& operator()(const T& _random_counter, const T &_random_seed = V_ZERO<T>)
				{(*this).random_number = this->giveRandom(_random_counter, _random_seed); return *this;}

			RandomNumber<T> operator[](const T& _random_counter)
				{
					RandomNumber<T> _random_number_instance(_random_counter, this->random_seed);
					return _random_number_instance;
				}

			RandomNumber<T> operator+() const
				{return RandomNumber<T>(this->random_seed);}
			RandomNumber<T> operator+(const RandomNumber<T>& _random_number)
				{
					RandomNumber<T> _random_number_instance(_random_number.random_seed);
					_random_number_instance.random_seed += (*this).random_seed;
					_random_number_instance.restore();
					return _random_number_instance;
				}
			RandomNumber<T>& operator+=(const RandomNumber<T>& _random_number)
				{(*this).random_seed += _random_number.random_seed; (*this).restore(); return *this;}
			RandomNumber<T>& operator+=(const T& _random_seed)
				{this->random_seed += _random_seed; this->restore(); return *this;}

			RandomNumber<T>& operator++()			{++this->random_seed; this->restore(); return *this;}
			RandomNumber<T> operator++(int)			{RandomNumber<T> _random_number_instance(this->random_seed); (*this).random_seed++; (*this).restore(); return _random_number_instance;}
			RandomNumber<T>& operator--()			{--(*this).random_seed; (*this).restore(); return *this;}
			RandomNumber<T> operator--(int)			{RandomNumber<T> _random_number_instance(this->random_seed); (*this).random_seed--; (*this).restore(); return _random_number_instance;}

			RandomNumber<T> operator-() const
				{return RandomNumber<T>(-this->random_seed);}
			RandomNumber<T> operator-(const RandomNumber<T>& _random_number)
				{
					RandomNumber<T> _random_number_instance(_random_number.random_seed);
					_random_number_instance.random_seed -= (*this).random_seed;
					_random_number_instance.restore();
					return _random_number_instance;
				}
			RandomNumber<T>& operator-=(const RandomNumber<T>& _random_number)
				{this->random_seed -= _random_number.random_seed; this->restore(); return *this;}
			RandomNumber<T>& operator-=(const T& _random_seed)
				{(*this).random_seed -= _random_seed; (*this).restore(); return *this;}

			RandomNumber<T> operator*(const RandomNumber<T>& _random_number) const
				{return RandomNumber<T>((*this).random_seed * _random_number.random_seed);}
			RandomNumber<T> operator*(const T& _random_seed) const
				{return RandomNumber<T>(this->random_seed * _random_seed);}
			RandomNumber<T>& operator*=(const RandomNumber<T>& _random_number)
				{this->random_seed *= _random_number.random_seed; this->restore(); return *this;}
			RandomNumber<T>& operator*=(const T& _random_seed)
				{(*this).random_seed *= _random_seed; (*this).restore(); return *this;}

			RandomNumber<T> operator/(const RandomNumber<T>& _random_number) const
				{
					RandomNumber<T> _random_number_instance(_random_number.random_seed);
					_random_number_instance.random_seed = (_random_number.random_seed) ? (*this).random_seed / random_number.random_seed : V_ZERO<T>;
					_random_number_instance.restore();
					return _random_number_instance;
				}
			RandomNumber<T> operator/(const T& _random_seed) const
				{
					RandomNumber<T> _random_number_instance(this->random_seed);
					_random_number_instance.random_seed = (_random_seed) ? (*this).random_seed / _random_seed : V_ZERO<T>;
					_random_number_instance.restore();
					return _random_number_instance;
				}
			RandomNumber<T>& operator/=(const RandomNumber<T>& _random_number)
				{
					this->random_seed = (_random_number.random_seed) ? this->random_seed / _random_number.random_seed : V_ZERO<T>;
					(*this).restore();
					return *this;
				}
			RandomNumber<T>& operator/=(const T& _random_seed)
				{
					(*this).random_seed = (_random_seed) ? (*this).random_seed / _random_seed : V_ZERO<T>;
					this->restore();
					return *this;
				}

			RandomNumber<T> operator%(const RandomNumber<T>& _random_number) const
				{
					RandomNumber<T> _random_number_instance((*this).random_seed);
					_random_number_instance.random_seed = (_random_number.random_seed) ? static_cast<int>((*this).random_seed) % static_cast<int>(_random_number_instance.random_seed) : V_ZERO<T>;
					_random_number_instance.restore();
					return _random_number_instance;
				}
			RandomNumber<T> operator%(const T& _random_seed) const
				{
					RandomNumber<T> _random_number_instance(this->random_seed);
					_random_number_instance.random_seed = (_random_seed) ? static_cast<int>((*this).random_seed) % static_cast<int>(_random_seed) : V_ZERO<T>;
					_random_number_instance.restore();
					return _random_number_instance;
				}
			RandomNumber<T>& operator%=(const RandomNumber<T>& _random_number)
				{
					this->random_seed = (_random_number.random_seed) ? static_cast<int>((*this).random_seed) % static_cast<int>(_random_number.random_seed) : V_ZERO<T>;
					(*this).restore();
					return *this;
				}
			RandomNumber<T>& operator%=(const T& _random_seed)
				{
					(*this).random_seed = (_random_seed) ? static_cast<int>((*this).random_seed) % static_cast<int>(_random_seed) : V_ZERO<T>;
					return *this;
				}

			const T operator!=(const RandomNumber<T>& _random_number) const
				{return ((this->random_counter != _random_number.random_counter) || (this->random_number != _random_number.random_number) || (this->random_seed != _random_number.random_seed));}
			const T operator==(const RandomNumber<T>& _random_number) const
				{return ((this->random_counter == _random_number.random_counter) && (this->random_number == _random_number.random_number) && (this->random_seed == _random_number.random_number));}
			const T operator>(const RandomNumber<T>& _random_number) const
				{return ((*this).random_seed > _random_number.random_seed);}
			const T operator>=(const RandomNumber<T>& _random_number) const
				{return ((*this).random_seed >= _random_number.random_seed);}
			const T operator<(const RandomNumber<T>& _random_number) const
				{return ((*this).random_seed < _random_number.random_seed);}
			const T operator<=(const RandomNumber<T>& _random_number) const
				{return ((*this).random_seed <= _random_number.random_seed);}

			const T operator>>(RandomNumber<T>& _random_number)
				{_random_number.random_seed = this->random_seed; _random_number.restore(); return this->random_seed;}
			const T operator>>(const T& _random_seed)
				{return this->random_seed;}
			RandomNumber<T>& operator<<(const RandomNumber<T>& _random_number)
				{(*this).random_seed = _random_number.random_seed; (*this).restore(); return *this;}
			RandomNumber<T>& operator<<(const T& _random_seed)
				{(*this).random_seed = _random_seed; (*this).restore(); return *this;}

			operator T()					{return this->random_number;}

			virtual void capture()
				{
					T _random_counter = V_ZERO<T>, _random_seed = V_ZERO<T>;

					std::cout << std::endl << "Random Number Generator Object." << std::endl;
					std::cout << "+ Enter a counter value: ";
					_random_counter = (*this).enter_a_value(&_random_counter);
					std::cout << "+ Enter a random seed: ";
					_random_seed = (*this).enter_a_data(&_random_seed);

					this->random_number = (*this).giveRandom(_random_counter, _random_seed);
				}

			template <typename C = T>
			const RandomNumber<C> convert() const
				{RandomNumber<C> _random_number_instance((*this).random_seed); return _random_number_instance;}
			template <typename C = T>
			const RandomNumber<C> convert(const RandomNumber<T>& _random_number) const
				{RandomNumber<C> _random_number_instance(_random_number.random_seed); return _random_number_instance;}

			virtual RandomNumber<T>& copy(const RandomNumber<T>& _random_number)
				{
					this->random_counter = _random_number.random_counter;
					this->random_number = _random_number.random_number;
					this->random_seed = _random_number.random_seed;
					return *this;
				}

			static const T &enter_a_data(T *const& ptr_data)
				{
					if (ptr_data)
						{
							if (std::cin >> *ptr_data)
								{
									std::cout << "Characters:\t[" << std::cin.gcount() << "]." << std::endl;
									std::cout << "Value entered:\t[" << *ptr_data << "]. OK!" << std::endl;
								}
							else
								{
									*ptr_data = V_ZERO<T>;
									std::cerr << "Error! The input does not have a valid value." << std::endl;
									std::cerr << "Default value assigned to the variable: [" << *ptr_data << "]." << std::endl;

									if (std::cin.fail())
										{
											std::cin.clear();
											std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
										}

									throw std::invalid_argument("Invalid captured value!");
								}
						}
					else
						{
							std::cerr << "A valid memory address was not provided." << std::endl;
							throw std::runtime_error("The memory location must be valid and not a null pointer.");
						}

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);

					return (ptr_data) ? *ptr_data : V_ZERO<T>;
				}

			static void enter_a_pause(const std::string& str_Message)
				{
					std::cout << str_Message;
					std::cin.clear();
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
				}

			static const T& enter_a_value(T *const &ptr_value)
				{
					if (ptr_value)
						{
							std::string str_value {std::string()};

							if (std::getline(std::cin >> std::ws, str_value))
								{
									str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
									std::stringstream(str_value) >> *ptr_value;

									std::cout << "+ Characters:\t\t[" << std::cin.gcount() << "]." << std::endl;
									std::cout << "+ Value entered:\t[" << *ptr_value << "]. OK!" << std::endl << std::endl;
								}
							else
								{
									std::cerr << std::endl << std::endl << "Incorrect input information." << std::endl;

									if (std::cin.eof())
										std::cerr << "* EOF detected! *" << std::endl;

									if (std::cin.fail())
										std::cerr << "* Keyboard error detected! *" << std::endl;

									char c{};
									while (std::cin.get(c)) {}

									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);

									std::cerr << "> Throwing overflow exception..." << std::endl << std::endl;
									throw std::overflow_error("The information coming from the keyboard input is overloaded.");
								}
						}
					else
						{
							std::cerr << std::endl << "A valid memory address was not provided." << std::endl << std::endl;
							throw std::runtime_error("The memory location must be valid and not a null pointer.");
						}

					return (ptr_value) ? *ptr_value : V_ZERO<T>;
			}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const T formulaRandomGenerator(const T& _random_seed)
				{return T(RANDOM_GENERATOR(static_cast<int>(_random_seed)));}

			const T& GenerateRandom()
				{(*this).random_counter++; return (this->random_number = (*this).formulaRandomGenerator(this->random_number));}

			const T& getCounter()	const			{return (*this).random_counter;}
			const T& getNumber()	const			{return (*this).random_number;}

			const T getPosition(const T& _random_counter, const T& _random_seed, const T& _random_number_to_find)
				{
					size_t _counter = V_ZERO<T>;
					T _random_number = _random_seed;

					std::cout << std::endl << "Searching for a random number from a seed." << std::endl;
					std::cout << "+ Random seed:\t\t[" << _random_seed << "]." << std::endl;
					std::cout << "+ Random number:\t[" << _random_number_to_find << "]." << std::endl;
					std::cout << "+ Random counter:\t[" << _random_counter << "]." << std::endl;
					RandomNumber<T>::enter_a_pause("Press ENTER key to continue...");

					std::cout << std::endl;
					for (_counter = V_ZERO<T>; _counter < _random_counter && _random_number != _random_number_to_find; counter++)
						{
							_random_number = this->formulaRandomGenerator(_random_number);
							std::cout << "- Iteration #: [" << (_counter + V_ONE<T>) << "]. Value: {" << _random_number << "}. \r";
						}

					std::cout << std::endl << std::endl << "[" << _counter << "] Iterations performed." << std::endl;
					std::cout << "Random Number: [" << _random_number << "] = [" << _random_number_to_find << "]";
					std::cout << " : {" << std::boolalpha << (_random_number == _random_number_to_find) << "}." << std::endl;
					RandomNumber<T>::enter_a_pause("Press ENTER key to continue...");

					return counter;
				}

			const T& getQuantity()	const			{return this->counter;}

			const T getRandom(const T &_random_counter = V_ZERO<T>, const T& _random_seed = V_ZERO<T>)
				{
					T _random_number = _random_seed;

					for (size_t _counter = V_ZERO<T>; _counter < _random_counter; _counter++)
						_random_number = this->formulaRandomGenerator(_random_number);

					return _random_number;
				}

			const T& getSeed()	const			{return (*this).random_seed;}
			T& getSeed()					{return this->random_seed;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()					{return (this->random_number / (T)(V_RESIDUAL_MODULUS));}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			&getValue()					{return (this->random_number);}

			const T getWithin(const T& minimum = V_ZERO<T>, const T& maximum = V_ZERO<T>) const
				{
					T highest = std::max(minimum, maximum);
					T lowest = std::min(minimum, maximum);
					T interval = highest - lowest + V_ONE<T>;

					return (static_cast<int>(this->random_number) % static_cast<int>(interval) + static_cast<int>(lowest));
				}

			const T& giveRandom(const T &_random_counter = V_ZERO<T>, const T& _random_seed = V_ZERO<T>)
				{
					(*this).random_counter = V_ZERO<T>;
					(*this).random_number = (*this).random_seed = _random_seed;

					for (size_t _counter {V_ZERO<size_t>}; _counter < size_t(_random_counter); _counter++)
						(*this).random_number = (*this).GenerateRandom();

					return (*this).random_number;
				}

			bool isitme(const RandomNumber<T>& _random_number) const
				{return (this == &_random_number);}

			virtual RandomNumber<T>& move(RandomNumber<T>&& _random_number)
				{(*this).copy(_random_number); _random_number.reset(); return *this;}

			virtual void print()
				{
					std::cout << std::endl << "Random Number Information." << std::endl;
					std::cout << "+ Number of Objects:\t[" << this->counter << "]." << std::endl;
					std::cout << "+ Random Count Value:\t[" << (*this).random_counter << "]." << std::endl;
					std::cout << "+ Random Seed Number:\t[" << (*this).random_seed << "]." << std::endl;
					std::cout << "+ Last Random Number:\t[" << (*this).random_number << "] = {" << this->getValue() << "}." << std::endl << std::endl;
				}

			virtual void reset()
				{this->random_counter = this->random_number = this->random_seed = V_ZERO<T>;}

			virtual void restore()
				{
					(*this).random_counter = V_ZERO<T>;
					(*this).random_number = (*this).random_seed;
					(*this).random_number = (*this).GenerateRandom();
				}

			void setSeed(const T &_random_seed = V_ZERO<T>)
				{this->random_seed = _random_seed; this->restore();}

			virtual void swap()
				{
					T _random_value = this->random_seed;
					this->random_seed = this->random_number;
					this->random_number = _random_value;
					(*this).restore();
				}

			virtual ~RandomNumber()				{(*this).counter--;}
	};

/* Initialization of the instantiated class counter. */
template <typename T>
std::size_t RandomNumber<T>::counter = static_cast<size_t>(V_ZERO<T>);

//Main function.
int main()
	{
		/* Preliminary working variables. */
		RandomNumber<double>::value_type minimum = V_ZERO<double>, maximum = V_ZERO<double>;
		RandomNumber<double>::value_type _random_seed = V_ZERO<double>;
		size_t counter = V_ZERO<size_t>, numbers = V_ZERO<size_t>, quantity = V_ZERO<size_t>;
		std::vector<std::set<double>> lottery;	//Vector that stores ordered sets of integers.

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of random objects to generate: ";
		try {quantity = RandomNumber<size_t>::enter_a_data(&quantity);}
		catch (const std::exception& e) {std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* The dynamic array of pointers to objects of type 'RandomNumber' is created. */
		RandomNumber<double>** array_Random_Number = new RandomNumber<double>* [quantity];

		/* Critical assignment to each of the elements of the array of random number objects. */
		for (size_t idx = V_ZERO<size_t>; idx < quantity; idx++)
			{
				std::set<double> ticket;	//Ordered sets of integers.
				std::cout << std::endl << "'Random Number Object' #: [" << idx + V_ONE<size_t> << "] of: [" << quantity << "]." << std::endl;

				/* Obtain both the starting random seed and the positioning counter of the random number. */
				std::cout << "Number of elements: ";
				try {numbers = RandomNumber<size_t>::enter_a_data(&numbers);}
				catch (const std::exception& e) {std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

				std::cout << std::endl << "Random seed value: ";
				try {_random_seed = RandomNumber<double>::enter_a_value(&_random_seed);}
				catch (const std::exception& e) {std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

				/* Ask the user for the minimum and maximum values ​​of the range. */
				std::cout << std::endl << "Range of minimum and maximum values." << std::endl;

				std::cout << "Minimum value in range: ";
				try {minimum = RandomNumber<double>::enter_a_data(&minimum);}
				catch (const std::exception& e) {std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

				std::cout << std::endl << "Maximum value in range: ";
				try {maximum = RandomNumber<double>::enter_a_value(&maximum);}
				catch (const std::exception& e) {std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

				/* Create a class with the overloaded 'int' operator to generate series of numbers. */
				array_Random_Number[idx] = new RandomNumber<double>(_random_seed);
				array_Random_Number[idx]->print();
				array_Random_Number[idx]->enter_a_pause("Press the ENTER key to continue...");

				/* We use the generator to take 'n' given values. */
				counter = V_ZERO<size_t>;
				std::cout << "List of generated random numbers." << std::endl;

				/* Activate the generator for each call to its function object. */
				for (size_t jdx = V_ZERO<size_t>; jdx < numbers; jdx++)
					{
						ticket.insert((*array_Random_Number[idx]).getWithin(minimum, maximum));

						std::cout << "#: [" << (counter++) + V_ONE<size_t> << "]\t:\t[" << array_Random_Number[idx]->getNumber() << "]\t=\t[" << array_Random_Number[idx]->getValue() << "]\t=\t[" << array_Random_Number[idx]->getWithin(minimum, maximum) << "]." << std::endl;
						(*array_Random_Number[idx])();	//Activate the generator to get the next number.
					}
				std::cout << "[" << counter << "] Output results generated." << std::endl;

				lottery.push_back(ticket);	//Store each set of sorted integers on one line of the vector.
				(*array_Random_Number[idx]).enter_a_pause("Press the ENTER key to continue...");

				/* Display the last value at which the generator stopped. */
				std::cout << *array_Random_Number[idx];
				(*(*(array_Random_Number + idx))).enter_a_pause("Press the ENTER key to continue...");
			}

		/* All dynamically created instances of objects of type 'RandomNumber' are purged. */
		counter = V_ZERO<size_t>;
		std::cout << std::endl << "Clearing 'RandomNumber' objects..." << std::endl;
		for (size_t idx = V_ZERO<size_t>; idx < quantity; idx++)
			{
				std::cout << "Deleting object 'RandomNumber' #: [" << (counter++) + V_ONE<size_t> << "] of: [" << quantity << "]." << std::endl;
				delete *(array_Random_Number + idx);
				RandomNumber<size_t>::enter_a_pause("Press the ENTER key to continue...");
			}
		std::cout << "[" << counter << "] Output results generated." << std::endl;
		RandomNumber<char>::enter_a_pause("Press the ENTER key to continue...");

		/* Deleting the array of pointer objects of type 'RandomNumber'. */
		std::cout << std::endl << "Deleting the array of pointers of type 'RandomNumber'..." << std::endl;
		delete [] array_Random_Number;
		RandomNumber<char>::enter_a_pause("Press the ENTER key to continue...");

		/* Empty all tickets generated as sets into a vector of a draw. */
		counter = V_ZERO<size_t>;
		std::cout << std::endl << "Empty all tickets generated as sets into a vector of a draw." << std::endl;
		for (std::vector<std::set<double>>::const_iterator itc_lottery = lottery.cbegin(); itc_lottery != lottery.cend(); itc_lottery++)
			{
				std::cout << "Ticket #: [" << (counter++) + V_ONE<size_t> << "] of: [" << lottery.size() << "]." << std::endl;

				for (std::set<double>::const_iterator itc_ticket = (*itc_lottery).cbegin(); itc_ticket != (*itc_lottery).cend(); itc_ticket++)
					std::cout << "[" << *itc_ticket << "].\t";

				std::cout << std::endl << std::endl;
			}
		std::cout << "[" << counter << "] Output results generated." << std::endl;
		RandomNumber<char>::enter_a_pause("Press the ENTER key to continue...");

		/* Program termination messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		RandomNumber<char>::enter_a_pause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
