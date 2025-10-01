/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic character constants. */
#define	CARRIAGE_RETURN		'\n'

/* Numeric symbolic constants. */
#define	V_MINUS_ONE		-1
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
			T random_index = V_MINUS_ONE;
			T random_seed = V_ZERO;
			T random_number = V_ZERO;

			friend std::istream &operator>> (std::istream &in, RandomNumber<T> &object_random)
				{object_random.capture(); return in;}
			friend std::ostream& operator<< (std::ostream& out, RandomNumber<T>& object_random)
				{object_random.print(); return out;}

		protected:
			static int counter;

		public:
			RandomNumber() : random_index(V_MINUS_ONE)	{this->counter++; this->capture();}
			RandomNumber(const T& random_seed) : random_index(V_MINUS_ONE), random_seed(random_seed), random_number(random_seed)
				{this->counter++; this->random_number = this->GenerateRandom();}
			RandomNumber(const T& random_seed, const T& random_index) : random_index(random_index), random_seed(random_seed), random_number(random_seed)
				{(*this).random_number = getRandom(random_seed, random_index);}

			RandomNumber(const RandomNumber<T>& object_random) : random_index(object_random.getCounter()), random_seed(object_random.getSeed()), random_number(object_random.getNumber())
				{this->counter++;}
			RandomNumber(RandomNumber<T>&& object_random) : random_index(object_random.getCounter()), random_seed(object_random.getSeed()), random_number(object_random.getNumber())
				{this->counter--; object_random.reset();}

			RandomNumber<T>& operator= (const RandomNumber<T> &object_random)
				{this->copy(object_random); return *this;}
			RandomNumber<T>& operator= (RandomNumber<T>&& object_random)
				{this->counter--; this->copy(object_random); object_random.reset(); return *this;}

			RandomNumber<T>& operator()()
				{this->random_number = this->GenerateRandom(); return *this;}
			RandomNumber<T>& operator()(const T &random_seed, const T& random_index = V_ZERO)
				{this->random_number = getRandom(random_seed, random_index); return *this;}

			RandomNumber<T>& operator+ (const RandomNumber<T>& object_random)
				{this->random_seed += object_random.getSeed(); this->restore(); return *this;}

			RandomNumber<T>& operator++()			{++this->random_seed; this->restore(); return *this;}
			RandomNumber<T>& operator++(int)		{(*this).random_seed++; (*this).restore(); return *this;}
			RandomNumber<T>& operator--()			{--(*this).random_seed; (*this).restore(); return *this;}
			RandomNumber<T>& operator--(int)		{this->random_seed--; this->restore(); return *this;}

			RandomNumber<T>& operator- (const RandomNumber<T>& object_random)
				{(*this).random_seed -= object_random.getSeed(); (*this).restore(); return *this;}

			operator T()					{return this->random_number;}

			virtual void capture()
				{
					std::cout << std::endl << "Random Number Generator." << std::endl;
					std::cout << "Enter a random initial seed value: ";
					(*this).random_seed = (*this).enter_a_value(&this->random_seed);
					this->restore();
				}

			template <typename C = T>
			const RandomNumber<C> convert() const
				{
					RandomNumber<C> object_random((*this).random_seed);
					return object_random;
				}

			template <typename C = T>
			const RandomNumber<C> convert(const RandomNumber<T>& object_random) const
				{
					RandomNumber<C> random_instance(object_random.getSeed());
					return random_instance;
				}

			virtual RandomNumber<T>& copy(const RandomNumber<T>& object_random)
				{
					this->random_index = object_random.getCounter();
					this->random_number = object_random.getNumber();
					this->random_seed = object_random.getSeed();
					return *this;
				}

			static const T &enter_a_data(T *const p_data)
				{
					if (p_data)
						if (std::cin >> *p_data)
							std::cout << "Value entered: [" << *p_data << "]. OK!" << std::endl;
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

			static const T& enter_a_value(T *const p_value)
				{
					if (p_value)
						{
							std::string str_value;
							std::getline(std::cin >> std::ws, str_value);
							std::stringstream(str_value) >> *p_value;

							std::cout << std::endl << "Value entered:\t[" << *p_value << "]. OK!" << std::endl;
						}
					else
						std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

					return *p_value;
				}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const T& GenerateRandom()
				{
					(*this).random_index++;
					return (this->random_number = RANDOM_GENERATOR(static_cast<int>(this->random_number)));
				}

			const T& getCounter()	const			{return (*this).random_index;}
			const T& getNumber()	const			{return (*this).random_number;}

			const T& getRandom(const T& random_seed = V_ZERO, const T &random_index = V_ZERO)
				{
					(*this).random_index = V_ZERO;
					(*this).random_number = (*this).random_seed = random_seed;

					for (int counter = V_ZERO; counter <= random_index; counter++)
						(*this).random_number = (*this).GenerateRandom();

					this->random_index -= (this->random_index > V_ZERO) ? V_ONE : V_ZERO;

					return (*this).random_number;
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
					T highest = V_ZERO, interval = V_ZERO, lowest = V_ZERO;

					lowest = std::min(minimum, maximum);
					highest = std::max(minimum, maximum);

					interval = (highest - lowest) + V_ONE;

					return (static_cast<int>(this->random_number) % static_cast<int>(interval) + lowest);
				}

			const bool isitme(const RandomNumber<T>& object_random)
				{return (this == &object_random);}

			virtual RandomNumber<T>& move(RandomNumber<T>&& object_random)
				{(*this).counter--; (*this).copy(object_random); object_random.reset(); return *this;}

			virtual void print()
				{
					std::cout << std::endl << "Random Number Information." << std::endl;
					std::cout << "+ Number of Objects:\t[" << this->counter << "]." << std::endl;
					std::cout << "+ Random Index Value:\t[" << (*this).random_index << "]." << std::endl;
					std::cout << "+ Random Seed Number:\t[" << (*this).random_seed << "]." << std::endl;
					std::cout << "+ Last Random Number:\t[" << (*this).random_number << "] = [" << this->getValue() << "]." << std::endl;
					std::cout << std::endl;
				}

			virtual void reset()
				{
					this->random_index = V_MINUS_ONE;
					this->random_number = this->random_seed = V_ZERO;
				}

			virtual void restore()
				{
					(*this).random_index = V_MINUS_ONE;
					(*this).random_number = (*this).random_seed;
					(*this).random_number = (*this).GenerateRandom();
				}

			void setSeed(const T &random_seed = V_ZERO)
				{
					this->random_seed = random_seed;
					this->restore();
				}

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

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of elements: ";
		std::cin >> numbers;
		std::cout << "Random seed value: ";
		std::cin >> random_seed;

		/* Create a class with the overloaded 'int' operator to generate series of numbers. */
		RandomNumber<double> my_random_number(random_seed);
		my_random_number.print();

		/* We use the generator to take 'n' given values. */
		std::cout << "List of generated random numbers." << std::endl;
		for (int idx = V_ZERO; idx < numbers; idx++)
			{
				std::cout << "#: [" << counter++ << "]\t:\t[" << my_random_number.getNumber() << "]\t=\t[" << my_random_number.getValue() << "]." << std::endl;
				my_random_number();	//Activate the generator to get the next number.
			}
		std::cout << "[" << counter << "] Output results generated." << std::endl;
		std::cout << my_random_number;

		return V_ZERO;
	}
