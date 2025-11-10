/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic character constants. */
#define	CARRIAGE_RETURN		'\n'

/* Numeric symbolic constants. */
#define V_ONE			1
#define V_ZERO			0

/* Random number generator. */
#define RANDOM_GENERATOR(s)	(((V_MULTIPLIER) * (s) + (V_INCREMENTER)) % (V_MODULUS))
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

//Base class that generates random numbers based on an initial seed value.
template <typename T>
class RandomNumber
	{
		private:
			T random_counter = V_ZERO;
			T random_seed = V_ZERO;
			T random_number = V_ZERO;

			friend std::istream &operator>> (std::istream &in, RandomNumber<T> &object_random)
				{object_random.capture(); return in;}
			friend std::ostream& operator<< (std::ostream& out, RandomNumber<T>& object_random)
				{object_random.print(); return out;}

		protected:
			static int counter;

		public:
			RandomNumber() : random_counter(V_ZERO), random_seed(V_ZERO), random_number(V_ZERO)
				{this->counter++; this->capture();}
			RandomNumber(const T& random_seed) : random_counter(V_ZERO), random_seed(random_seed), random_number(random_seed)
				{this->counter++; this->random_number = this->GenerateRandom();}
			RandomNumber(const T& random_seed, const T& random_counter) : random_counter(random_counter), random_seed(random_seed), random_number(random_seed)
				{this->counter++; (*this).random_number = this->giveRandom(random_seed, random_counter);}

			RandomNumber(const RandomNumber<T>& object_random) : random_counter(object_random.getCounter()), random_seed(object_random.getSeed()), random_number(object_random.getNumber())
				{this->counter++;}
			RandomNumber(RandomNumber<T>&& object_random) : random_counter(object_random.getCounter()), random_seed(object_random.getSeed()), random_number(object_random.getNumber())
				{this->counter--; object_random.reset();}

			RandomNumber<T>& operator= (const T& random_seed)
				{(*this).random_seed = random_seed; (*this).restore(); return *this;}
			RandomNumber<T>& operator= (const RandomNumber<T> &object_random)
				{this->copy(object_random); return *this;}
			RandomNumber<T>& operator= (RandomNumber<T>&& object_random)
				{this->counter--; this->copy(object_random); object_random.reset(); return *this;}

			RandomNumber<T>& operator()()
				{this->random_number = this->GenerateRandom(); return *this;}
			RandomNumber<T>& operator()(const T &random_seed, const T& random_counter = V_ZERO)
				{(*this).random_number = this->giveRandom(random_seed, random_counter); return *this;}

			RandomNumber<T> operator[](const T &random_counter)
				{return this->getRandom((*this).random_seed, random_counter);}

			RandomNumber<T>& operator+ (const RandomNumber<T>& object_random)
				{this->random_seed += object_random.getSeed(); this->restore(); return *this;}
			RandomNumber<T>& operator+= (const RandomNumber<T>& object_random)
				{(*this).random_seed += object_random.getSeed(); (*this).restore(); return *this;}
			RandomNumber<T>& operator+= (const T& random_seed)
				{this->random_seed += random_seed; this->restore(); return *this;}

			RandomNumber<T>& operator++()			{++this->random_seed; this->restore(); return *this;}
			RandomNumber<T>& operator++(int)		{(*this).random_seed++; (*this).restore(); return *this;}
			RandomNumber<T>& operator--()			{--(*this).random_seed; (*this).restore(); return *this;}
			RandomNumber<T>& operator--(int)		{this->random_seed--; this->restore(); return *this;}

			RandomNumber<T>& operator- (const RandomNumber<T>& object_random)
				{(*this).random_seed -= object_random.getSeed(); (*this).restore(); return *this;}
			RandomNumber<T>& operator-= (const RandomNumber<T>& object_random)
				{this->random_seed -= object_random.getSeed(); this->restore(); return *this;}
			RandomNumber<T>& operator-= (const T& random_seed)
				{(*this).random_seed -= random_seed; (*this).restore(); return *this;}

			operator T()					{return this->random_number;}

			virtual void capture()
				{
					T random_counter = V_ZERO, random_seed = V_ZERO;

					std::cout << std::endl << "Random Number Generator Object." << std::endl;
					std::cout << "+ Enter a random seed: ";
					random_seed = (*this).enter_a_data(&random_seed);
					std::cout << "+ Enter a index value: ";
					random_counter = (*this).enter_a_value(&random_counter);

					this->random_number = (*this).giveRandom(random_seed, random_counter);
				}

			template <typename C = T>
			const RandomNumber<C> convert() const
				{RandomNumber<C> object_random((*this).random_seed); return object_random;}
			template <typename C = T>
			const RandomNumber<C> convert(const RandomNumber<T>& object_random) const
				{RandomNumber<C> random_instance(object_random.getSeed()); return random_instance;}

			virtual RandomNumber<T>& copy(const RandomNumber<T>& object_random)
				{
					this->random_counter = object_random.getCounter();
					this->random_number = object_random.getNumber();
					this->random_seed = object_random.getSeed();
					return *this;
				}

			static const T &enter_a_data(T *const p_data)
				{
					if (p_data)
						if (std::cin >> *p_data)
							std::cout << "Value entered:\t[" << *p_data << "]. OK!" << std::endl;
						else
							{
								*p_data = V_ZERO;
								std::cerr << "Error! The input does not have a valid value." << std::endl;
							}
					else
						std::cerr << "A valid memory address was not provided." << std::endl;

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);

					return *p_data;
				};

			static void enter_a_pause(const std::string& str_Message)
				{
					std::cout << str_Message;
					std::cin.clear();
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
				}

			static const T& enter_a_value(T *const p_value)
				{
					if (p_value)
						{
							std::string str_value {};
							std::getline(std::cin >> std::ws, str_value);
							str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
							std::stringstream(str_value) >> *p_value;

							std::cout << "Value entered:\t[" << *p_value << "]. OK!" << std::endl;
						}
					else
						std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

					return *p_value;
				}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const T& GenerateRandom()
				{
					(*this).random_counter++;
					return (this->random_number = RANDOM_GENERATOR(static_cast<int>(this->random_number)));
				}

			const T& getCounter()	const			{return (*this).random_counter;}
			const T& getNumber()	const			{return (*this).random_number;}

			const T getRandom(const T& random_seed = V_ZERO, const T &random_counter = V_ZERO)
				{
					T random_number = random_seed;

					for (int counter = V_ZERO; counter < random_counter; counter++)
						random_number = RANDOM_GENERATOR(static_cast<int>(random_number));

					return random_number;
				}

			const T& getSeed()	const			{return (*this).random_seed;}
			T& getSeed()					{return this->random_seed;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()					{return (this->random_number / (T) V_RESIDUAL_MODULUS);}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			&getValue()					{return this->random_number;}

			const T getWithin(const T& minimum = V_ZERO, const T& maximum = V_ZERO) const
				{
					T highest = std::max(minimum, maximum);
					T lowest = std::min(minimum, maximum);
					T interval = highest - lowest + V_ONE;

					return (static_cast<int>(this->random_number) % static_cast<int>(interval) + lowest);
				}

			const T& giveRandom(const T& random_seed = V_ZERO, const T &random_counter = V_ZERO)
				{
					(*this).random_counter = V_ZERO;
					(*this).random_number = (*this).random_seed = random_seed;

					for (int counter = V_ZERO; counter < random_counter; counter++)
						(*this).random_number = (*this).GenerateRandom();

					return (*this).random_number;
				}

			const bool isitme(const RandomNumber<T>& object_random)
				{return (this == &object_random);}

			virtual RandomNumber<T>& move(RandomNumber<T>&& object_random)
				{(*this).counter--; (*this).copy(object_random); object_random.reset(); return *this;}

			virtual void print()
				{
					std::cout << std::endl << "Random Number Information." << std::endl;
					std::cout << "+ Number of Objects:\t[" << this->counter << "]." << std::endl;
					std::cout << "+ Random Count Value:\t[" << (*this).random_counter << "]." << std::endl;
					std::cout << "+ Random Seed Number:\t[" << (*this).random_seed << "]." << std::endl;
					std::cout << "+ Last Random Number:\t[" << (*this).random_number << "] = [" << this->getValue() << "]." << std::endl;
					std::cout << std::endl;
				}

			virtual void reset()
				{this->random_counter = this->random_number = this->random_seed = V_ZERO;}

			virtual void restore()
				{
					(*this).random_counter = V_ZERO;
					(*this).random_number = (*this).random_seed;
					(*this).random_number = (*this).GenerateRandom();
				}

			void setSeed(const T &random_seed = V_ZERO)
				{this->random_seed = random_seed; this->restore();}

			virtual void swap()
				{
					T temp = this->random_seed;
					this->random_seed = this->random_number;
					this->random_number = temp;
					(*this).restore();
				}

			virtual ~RandomNumber() = default;
	};

/* Initialization of the instantiated class counter. */
template <typename T>
int RandomNumber<T>::counter = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		double counter = V_ZERO, numbers = V_ZERO, random_seed = V_ZERO;
		double minimum = V_ZERO, maximum = V_ZERO;

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of elements: ";
		numbers = RandomNumber<double>::enter_a_data(&numbers);
		std::cout << "Random seed value: ";
		random_seed = RandomNumber<double>::enter_a_value(&random_seed);

		/* Ask the user for the minimum and maximum values ​​of the range. */
		std::cout << std::endl << "Range of minimum and maximum values." << std::endl;
		std::cout << "Minimum value in range: ";
		minimum = RandomNumber<double>::enter_a_data(&minimum);
		std::cout << "Maximum value in range: ";
		maximum = RandomNumber<double>::enter_a_value(&maximum);

		/* Create a class with the overloaded 'int' operator to generate series of numbers. */
		RandomNumber<double> my_random_number(random_seed);
		my_random_number.print();
		my_random_number.enter_a_pause("Press the ENTER key to continue...");

		/* We use the generator to take 'n' given values. */
		std::cout << "List of generated random numbers." << std::endl;
		for (int idx = V_ZERO; idx < numbers; idx++)
			{
				std::cout << "#: [" << (counter++) + V_ONE << "]\t:\t[" << my_random_number.getNumber() << "]\t=\t[" << my_random_number.getValue() << "]\t=\t[" << my_random_number.getWithin(minimum, maximum) << "]." << std::endl;
				my_random_number();	//Activate the generator to get the next number.
			}
		std::cout << "[" << counter << "] Output results generated." << std::endl;
		my_random_number.enter_a_pause("Press the ENTER key to continue...");

		std::cout << my_random_number;
		RandomNumber<double>::enter_a_pause("Press the ENTER key to continue...");

		return V_ZERO;
	}
