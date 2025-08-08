/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <iostream>

/* Symbolic work constants. */
#define V_ONE   1
#define V_ZERO  0

//Work Numeric Symbolic Constants.
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

#define RANDOM_GENERATOR(ml, s, i, md)		((ml * (s) + i) % md)


template <typename T>
class RandomNumber
	{
		private:
			T incrementer = V_ZERO;
			T modulus = V_ZERO;
			T multiplier = V_ZERO;
			T random_seed = V_ZERO;
			T last_number = V_ZERO;

		protected:
			static int counter;

		public:
			RandomNumber() : multiplier(V_MULTIPLIER), incrementer(V_INCREMENTER), modulus(V_MODULUS), random_seed(V_ZERO), last_number(random_seed)		{this->counter++; this->capture();}
			RandomNumber(T &random_seed) : multiplier(V_MULTIPLIER), incrementer(V_INCREMENTER), modulus(V_MODULUS), random_seed(random_seed), last_number(random_seed) {this->counter++;}
			RandomNumber(T &multiplier, T &incrementer, T modulus, T random_seed) : multiplier(multiplier), incrementer(incrementer), modulus(modulus), random_seed(random_seed), last_number(random_seed) {(*this).counter++;}
			RandomNumber(RandomNumber &random_number) : multiplier(random_number.getMultiplier()), incrementer(random_number.getIncrementer()), modulus(random_number.getModulus()), random_seed(random_number.getRandomSeed()), last_number(random_number.getRandomSeed()) {this->counter++;}

			void capture()
				{
					std::cout << std::endl << "Generator of random number series." << std::endl;
					std::cout << "Multiplier  : "; std::cin >> this->multiplier;
					std::cout << "Incrementer : "; std::cin >> this->incrementer;
					std::cout << "Modulus     : "; std::cin >> this->modulus;
					std::cout << "Random seed : "; std::cin >> this->random_seed;
				}

			T getMultiplier()	const		{return this->multiplier;}
			T getIncrementer()	const		{return this->incrementer;}
			T getModulus()		const		{return this->modulus;}
			T getRandomSeed()	const		{return this->random_seed;}
			T getLastNumber()	const		{return this->last_number;}

			T operator()()				{return this->last_number = RANDOM_GENERATOR(this->multiplier, this->last_number, this->incrementer, this->modulus);}

			void print()
				{
					std::cout << std::endl << "Current values ​​of the 'RandomNumber' class." << std::endl;
					std::cout << "Multiplier  :\t[" << this->multiplier << "]." << std::endl;
					std::cout << "Incrementer :\t[" << this->incrementer << "]." << std::endl;
					std::cout << "Modulus     :\t[" << this->modulus << "]." << std::endl;
					std::cout << "Random Seed :\t[" << this->random_seed << "]." << std::endl;
					std::cout << "Last Number :\t[" << this->last_number << "]." << std::endl;
					std::cout << std::endl;
				}

			void reset()					{this->multiplier = this->incrementer = this->modulus = this->last_number = V_ZERO;}

			void setMultiplier(const T &multiplier)		{this->multiplier = multiplier;}
			void setIncrementer(const T &incrementer)	{this->incrementer = incrementer;}
			void setModulus(const T &modulus)		{this->modulus = modulus;}
			void setRandomSeed(const T &random_seed)	{this->random_seed = random_seed;}

			virtual ~RandomNumber() = default;
	};

template <typename T>
int RandomNumber<T>::counter = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int idx = V_ZERO, nums = V_ZERO, random_seed = V_ZERO;

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of elements: ";
		std::cin >> nums;
		std::cout << "Random Seed Value: ";
		std::cin >> random_seed;

		/* Create a class with the overloaded 'int' operator to generate series of numbers. */
		RandomNumber<int> my_random_number(random_seed);

		/* We use the generator to take 'n' given values. */
		std::cout << "Generator of series of consecutive random numbers." << std::endl;
		my_random_number.print();

		std::cout << "List of generated random numbers." << std::endl;
		for (idx = V_ZERO; idx < nums; idx++)
			{
				std::cout << "#: " << idx << "\t[" << my_random_number() << "]." << std::endl;
			}
		std::cout << "[" << idx << "] Output results generated." << std::endl;

		my_random_number.print();

		return V_ZERO;
	}
