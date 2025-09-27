/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <iostream>
#include <sstream>

/* Symbolic work constants. */
#define V_ONE   1
#define V_ZERO  0

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

		protected:
			static int counter;

		public:
			RandomNumber()					{this->counter++; this->capture();}
			RandomNumber(const T& random_seed) : random_seed(random_seed), random_number(random_seed)
				{this->counter++; this->random_number = this->newRandom();}

			T operator()()					{return (this->newRandom());}
			operator T()					{return this->random_number;}

			void capture()
				{
					std::string str_random_seed;

					std::cout << std::endl << "Random Number Generator." << std::endl;
					std::cout << "Enter a random initial seed value: ";

					std::getline(std::cin >> std::ws, str_random_seed);
					std::stringstream(str_random_seed) >> this->random_seed;

					this->restore();
					this->random_number = this->newRandom();
				}

			const T& getNumber()	const			{return (*this).random_number;}
			const T& getSeed()	const			{return (*this).random_seed;}
			T& getSeed()					{return this->random_seed;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()					{return (this->random_number / (T) V_RESIDUAL_MODULUS);}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			&getValue()					{return this->random_number;}

			const T getWithin(const T& minimum, const T& maximum)
				{
					return ((static_cast<int>(this->random_number) % (static_cast<int>(maximum) - static_cast<int>(minimum) + V_ONE)) + static_cast<int>(minimum));
				}

			const T& newRandom()
				{
					(*this).random_counter++;
					return (this->random_number = static_cast<T>(RANDOM_GENERATOR(static_cast<int>(this->random_number))));
				}

			void print()
				{
					std::cout << std::endl << "Random Number Information." << std::endl;
					std::cout << "+ Qty Objects:\t[" << this->counter << "]." << std::endl;
					std::cout << "+ Qty Numbers:\t[" << (*this).random_counter << "]." << std::endl;
					std::cout << "+ Random Seed:\t[" << (*this).random_seed << "]." << std::endl;
					std::cout << "+ Last Number:\t[" << (*this).random_number << "] = [" << this->getValue() << "]." << std::endl;
					std::cout << std::endl;
				}

			void reset()					{this->random_counter = V_ZERO; this->random_number = V_ZERO; this->random_seed = V_ZERO;}
			void restore()					{(*this).random_number = this->random_seed;}

			void setSeed(const T &random_seed = V_ZERO)	{this->random_number = V_ZERO; this->random_seed = random_seed;}

			virtual ~RandomNumber() = default;
	};

template <typename T>
int RandomNumber<T>::counter = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO, numbers = V_ZERO, random_seed = V_ZERO;

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

		my_random_number.print();

		return V_ZERO;
	}
