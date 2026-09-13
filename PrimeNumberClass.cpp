#include <algorithm>
#include <iterator>
#include <iostream>
#include <limits>
#include <sstream>

template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};

template <typename T>
constexpr T V_FIVE		{T(5)};
template <typename T>
constexpr T V_MINUS_ONE		{T(-1)};
template <typename T>
constexpr T V_SEVEN		{T(7)};
template <typename T>
constexpr T V_THREE		{T(3)};
template <typename T>
constexpr T V_TWO		{T(2)};
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_ZERO		{T(0)};

template <typename T>
class PrimeNumber
	{
		private:
			T *array {nullptr};
			T size {V_ZERO<T>};

		protected:
			static std::size_t s_counter;

		public:
			PrimeNumber() : array(nullptr), size(V_ZERO<T>)
				{this->s_counter++;}
			PrimeNumber(const T& _size) : array(nullptr), size(_size)
				{
					(*this).s_counter++;

					if (this->size > V_ZERO<T>)
						{
							this->array = new T[this->size]();
							this->fillArray(V_ZERO<T>, size + V_MINUS_ONE<T>, V_TWO<T>);
						}
				}
			PrimeNumber(const PrimeNumber<T>& my_prime) : array(nullptr), size(my_prime.size)
				{
					s_counter++;

					if (my_prime.array && (my_prime.size > V_ZERO<T>))
						{
							if ((this->array = new T[this->size]()))
								{
									for (T idx{}; idx < this->size; ++idx)
										{
											(*this).array[idx] = my_prime.array[idx];
										}
								}
						}
				}
			PrimeNumber(PrimeNumber<T>&& my_prime) : array(my_prime.array), size(my_prime.size)
				{
					s_counter++;
					my_prime.array = nullptr;
					my_prime.size = V_ZERO<T>;
				}

			const T& operator[](const T& index) const
				{return (checkValidity() && checkLimits(index)) ? this->array[index] : V_ZERO<T>;}

			PrimeNumber<T>& operator=(const PrimeNumber<T>& my_prime)
				{
					if (&my_prime != this)
						{
							if (my_prime.array && (my_prime.size > V_ZERO<T>))
								{
									release();

									if (!this->array && !this->size)
										{
											this->size = my_prime.size;

											if ((this->array = new T[this->size]{}))
												{
													for (T idx{}; idx < this->size; ++idx)
														{
															this->array[idx] = my_prime.array[idx];
														}
												}
										}
								}
						}

					return *this;
				}

			PrimeNumber<T>& operator=(PrimeNumber&& my_prime)
				{
					if (&my_prime != this)
						{
							if (my_prime.array && (my_prime.size > V_ZERO<T>))
								{
									release();

									if (!(*this).array && !(*this).size)
										{
											this->size = my_prime.size;
											this->array = my_prime.array;

											my_prime.array = nullptr;
											my_prime.size = V_ZERO<T>;
										}
								}
						}

					return *this;
				}

			bool checkLimits(const T& index) const
				{return (index >= V_ZERO<T> && index < this->size);}

			bool checkValidity() const
				{return (this->array && this->size);}

			static const T& enter_a_value(T *const ptr_value)
				{
					static T ZERO{};

					if (ptr_value)
						{
							std::string str_value {};
							std::getline(std::cin >> std::ws, str_value);
							str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
							std::stringstream(str_value) >> *ptr_value;

							std::cout << "Value entered:\t[" << *ptr_value << "]. OK!" << std::endl;
						}
					else
						std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

					return (ptr_value) ? *ptr_value : ZERO;
				}

			static void enter_a_pause(const std::string& str_Message)
				{
					std::cout << str_Message;
					std::cin.clear();
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
				}

			const T fillArray(const T& start, const T &finish, const T &last_number)
				{
					T counter {V_ZERO<T>};

					if (this->checkValidity())
						{
							for (T idx {start}, number {last_number}; idx <= finish; number++)
								if ((*this).IsPrimeNumber(number))
									{
										counter++;
										*(this->array + idx++) = number;
									}
						}

					return counter;
				}

			const T *const &getPtrArray() const
				{return this->array;}

			const T& getSize() const
				{return this->size;}

			bool IsPrimeNumber(const T& number) const
				{
					if (number < V_TWO<T>)
						return false;

					for (T idx{V_TWO<T>}; idx < number; ++idx)
						{
							if (!(number % idx))
								return false;
						}

					return true;
				}

			void release()
				{
					if (checkValidity())
						{
							delete[] (*this).array;
							this->array = nullptr;
							this->size = V_ZERO<T>;
						}
				}

			void resize(const T& _size)
				{
					if (_size > V_ZERO<T>)
						{
							T *_array {new T[_size]()};
							T counter {V_ZERO<T>};
							T last_value {};

							const T maximum {std::max(this->size, _size)};
							const T minimum {std::min((*this).size, _size)};

							const T new_size {_size};
							const T old_size {this->size};

							if (checkValidity())
								std::copy((*this).array, (*this).array + minimum, _array);

							this->release();
							this->array = _array;
							this->size = _size;

							if (new_size > old_size)
								{
									last_value = (old_size) ? _array[minimum + V_MINUS_ONE<T>] : V_ZERO<T>;
									counter = (*this).fillArray(minimum, maximum + V_MINUS_ONE<T>, last_value + V_ONE<T>);
									std::cout << "[" << counter << "] Output results generated." << std::endl;
								}
						}
					else
						{
							(*this).release();
							std::cout << std::endl << "Resources cleaned up!" << std::endl;
						}
				}

			void show() const
				{
					if (this->checkValidity())
						{
							std::cout << std::endl << "Displaying the prime number array." << std::endl;
							std::copy(this->array, this->array + this->size, std::ostream_iterator<T>(std::cout, "\t"));
							std::cout << std::endl;
						}
					else
						std::cout << std::endl << "Empty resources!" << std::endl;
				}

			virtual ~PrimeNumber()
				{
					s_counter--;
					release();
				}
	};

template <typename T>
std::size_t PrimeNumber<T>::s_counter {V_ZERO<size_t>};

int main()
	{
		size_t szt_numbers {V_ZERO<std::size_t>};

		std::cout << "Automatic adjuster for dynamic prime numbers." << std::endl;

		std::cout << std::endl << "Enter the number of items: ";
		szt_numbers = PrimeNumber<std::size_t>::enter_a_value(&szt_numbers);
		PrimeNumber<std::size_t> my_prime_number(szt_numbers);
		my_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "Enter the number of items: ";
		szt_numbers = PrimeNumber<std::size_t>::enter_a_value(&szt_numbers);
		PrimeNumber<std::size_t> your_prime_number(szt_numbers);
		your_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "Enter the number of items: ";
		szt_numbers = PrimeNumber<std::size_t>::enter_a_value(&szt_numbers);
		PrimeNumber<std::size_t> his_prime_number {szt_numbers};
		his_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		PrimeNumber<std::size_t> her_prime_number(my_prime_number);
		your_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");
		her_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		PrimeNumber<std::size_t> our_prime_number(std::move(her_prime_number));
		our_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");
		her_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "Enter the number of items: ";
		szt_numbers = PrimeNumber<std::size_t>::enter_a_value(&szt_numbers);
		her_prime_number.resize(szt_numbers);
		her_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		his_prime_number = my_prime_number;
		his_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");
		my_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		her_prime_number = std::move(my_prime_number);
		her_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");
		my_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "Enter the number of items: ";
		szt_numbers = PrimeNumber<std::size_t>::enter_a_value(&szt_numbers);
		my_prime_number.resize(szt_numbers);
		my_prime_number.show();
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		std::cout << std::endl << "[" << my_prime_number.getPtrArray() << "]." << std::endl;
		std::cout << "{" << my_prime_number.getSize() << "}." << std::endl;

		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		PrimeNumber<std::size_t>::enter_a_pause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
