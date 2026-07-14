/****************** Fibonacci Number Generator. ******************
 ** Source Code:	Fibonacc.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, December 31, 2026.		**
 ** Purpose:		The purpose of this program is to	**
 **			generate a vector whose structure stores**
 **			the numbers used to calculate each	**
 **			record or series of Fibonacci numbers,	**
 **			and in this way, certain calculation	**
 **			records can be consulted to find out	**
 **			what the final Fibonacci number is given**
 **			a series of given terms with the pair of**
 **			initial values to consider.		**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
*****************************************************************/
/* C++ Standard Libraries. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

/* Lower and upper limit constants. */
template <typename T>
constexpr T V_CHAR_LOWER_Y	{T('\x79')};
template <typename T>
constexpr T V_CHAR_UPPER_Y	{T('\x59')};
template <typename T>
constexpr T V_LOWER_LIMIT_FIBO	{T(1)};
template <typename T>
constexpr T V_UPPER_LIMIT_MAX	{T(45)};

/* Work Symbolic Constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};
template <typename T>
constexpr T NULL_CHARACTER	{T('\0')};

/* Numerical symbolic constants. */
template <typename T>
constexpr T V_MINUS_ONE		{T(-1)};
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_THREE		{T(3)};
template <typename T>
constexpr T V_TWO		{T(2)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Global overload of the 'new' operator. */
void* operator new (std::size_t size_of_bucket)
	{
		std::cout << std::endl << "> Assigning: (" << size_of_bucket << ") bytes..." << std::endl;

		void* ptr_bucket {std::malloc(size_of_bucket)};

		if (!ptr_bucket)
			{
				throw std::bad_alloc();	//Handling critical memory failure.
			}

		return ptr_bucket;
	}

/* Global overload of the 'delete' operator. */
void operator delete (void* ptr_bucket) noexcept
	{
		std::cout << std::endl << "Releasing allocated memory..." << std::endl;
		std::free(ptr_bucket);
	}

/* Global overload of the 'delete' operator with pointer and size of bucket. */
void operator delete (void* ptr_bucket, std::size_t size_of_bucket) noexcept
	{
		std::cout << std::endl << "< Releasing: (" << size_of_bucket << ") bytes..." << std::endl;
		std::free(ptr_bucket);
	}

/*--------------------------------------------------------------**
 * Data structure that stores the generated calculation record	--
 * number, the first and second numbers and the sum of these	--
 * that are part of the generation of the Fibonacci series of	--
 * numbers.							--
 *--------------------------------------------------------------*/
template <typename T>
struct Fibonacci_Record
	{
		T idx {V_ZERO<T>};			//Calculated record number of the Fibonacci series.
		T first_number {V_ZERO<T>};		//First game number of the series.
		T second_number {V_ZERO<T>};		//Second starting number of the series.
		T addition {V_ZERO<T>};			//Sum of both previous numbers.

		/* Structure Builder. */
		Fibonacci_Record()
			{std::cout << std::endl << "<Building Fibonacci sequence...>" << std::endl;}

		/* Destroyer of the Structure. */
		~Fibonacci_Record()
			{std::cout << std::endl << ">Destroying Fibonacci sequence...<" << std::endl;}
	};

/* Custom memory host for the 'std::vector' class. */
template <typename T>
struct My_Allocator
	{
		using value_type = T;

		My_Allocator() = default;

		/* Custom Host Constructor for the Vector class. */
		template <typename U>
		My_Allocator(const My_Allocator<U>&)	{}

		/* Memory holder for the Locator. */
		T* allocate(std::size_t num_buckets)
			{
				std::cout << CARRIAGE_RETURN<char> << "+ Assigning: [" << num_buckets << "] elements. +" << CARRIAGE_RETURN<char>;
				return static_cast<T*>(::operator new(num_buckets * sizeof(T)));
			}

		/* Memory unholder for the Locator. */
		void deallocate(T* ptr_bucket, std::size_t num_buckets)
			{
				std::cout << CARRIAGE_RETURN<char> << "- Releasing: [" << num_buckets << "] elements. -" << CARRIAGE_RETURN<char>;
				::operator delete(ptr_bucket);
			}

		/* Explicit construct: the analyzer understands that the object is initialized. */
		template <typename U, typename... Arguments>
		void construct(U* ptr_bucket, Arguments&&... arguments)
			{
				::new ((void*)ptr_bucket) U(std::forward<Arguments>(arguments)...);
			}

		/* Custom Host Destructor for the Vector class. */
		template <typename U>
		void destroy(U* ptr_bucket)
			{
				ptr_bucket->~U();
			}
	};

/* Prototype functions. */
void enter_a_pause(const std::string& str_Message);
template <typename T>
const T& enter_a_value(T *const &ptr_value);

/*****************************************************************
 ** Function:		template <typename T>			**
 **			T *breakdown_Fibonacci			**
 **				(const T& quantity,		**
 **				 T first_number,		**
 **				 T second_number,		**
 **				 T **list_Fibonacci);		**
 ** Explanation:	The primary purpose of this function is	**
 **			to generate a simple vector or		**
 **			arrangement that purely stores the	**
 **			series of Fibonacci numbers, which is	**
 **			its iterative sum of its two preceding	**
 **			elements, without further details and	**
 **			without further relevant information.	**
 ** Input Parms:	const T& quantity,			**
 **			T first_number,				**
 **			T second_number,			**
 **			T **list_Fibonacci.			**
 ** Output Parms:	T **list_Fibonacci.			**
 ** Result:		As a result, a pointer to integers is	**
 **			returned with each of the summed values	**
 **			of the series of Fibonacci numbers.	**
 **								**
 **			Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
template <typename T>
T *breakdown_Fibonacci(const T& quantity, T first_number, T second_number, T **list_Fibonacci)
	{
		/* Initial declaration of work variables. */
		T *vector_Fibonacci {nullptr};
		T addition {V_ZERO<T>};
		T counting_items {V_ZERO<T>};

		/* Creation of a simple one-dimensional vector or array. */
		if ((vector_Fibonacci = new T[quantity]()))
			{
				/* Filling the vector or array with the values of the Fibonacci series. */
				for (T idx {V_ZERO<T>}; idx < quantity; idx++)
					{
						addition = first_number + second_number;
						vector_Fibonacci[idx] = addition;
						counting_items++;

						first_number = second_number;
						second_number = addition;
					}

				/* Display of each value. */
				std::cout << std::endl;
				for (T idx {V_ZERO<T>}; idx < quantity; idx++)
					std::cout << "[" << *(vector_Fibonacci + idx) << "].\t";
				std::cout << std::endl;

				/* Expected results. */
				std::cout << "[" << counting_items << "] Generated output results." << std::endl;
				enter_a_pause("Press the ENTER key to continue...");
			}
		else
			std::cerr << std::endl << "An error occurred while allocating memory to the Fibonacci number pointer." << std::endl;

		/* Assignment of the new memory address that contains the created elements. */
		return (list_Fibonacci && vector_Fibonacci) ? *list_Fibonacci = vector_Fibonacci : nullptr;
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **			Fibonacci_Record			**
 **				*dump_record_Fibonacci		**
 **				(const T& quantity,		**
 **				 const T& first_number,		**
 **				 const T& second_number,	**
 **				 Fibonacci_Record		**
 **					**p_st_rec_Fibo);	**
 ** Explanation:	The primary purpose of this routine is	**
 **			to return a structure pointer of the	**
 **			calculated records of the Fibonacci	**
 **			series and, in turn, to return the	**
 **			starting memory addresses of the	**
 **			created pointer of the structure and of	**
 **			each data stored in each field of the	**
 **			structure, simulating then a complete	**
 **			dump of the records generated step by	**
 **			step of the Fibonacci numerical series.	**
 ** Input Parms:	const size_t& quantity.			**
 **			const size_t& first_number.		**
 **			const size_t& second_number,		**
 **			struct Fibonacci_Record			**
 **				**p_st_rec_Fibo.		**
 ** Output Parms:	struct Fibonacci_Record			**
 **				**p_st_rec_Fibo.		**
 ** Result:		Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
template <typename T>
Fibonacci_Record<T> *dump_record_Fibonacci(const T& quantity, const T& first_number, const T& second_number, Fibonacci_Record<T>** p_st_rec_Fibo)
	{
		/* Initial declaration of work variables. */
		T counting_items {V_ZERO<T>};
		Fibonacci_Record<T> st_rec_Fibo {}, *ptr_st_rec_Fibo = &st_rec_Fibo;

		/* Initial assignment of series starting values. */
		st_rec_Fibo.first_number = first_number;
		st_rec_Fibo.second_number = second_number;

		/* Routine information window. */
		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+Fibonnaci Number Dumping Breakdown.+" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "| Generating the Fibonacci Series..." << std::endl;

		/* Dynamically allocate memory for the Fibonacci structure pointer. */
		if ((ptr_st_rec_Fibo = static_cast<Fibonacci_Record<T>*>(std::calloc(quantity, sizeof(st_rec_Fibo)))))
			{
				std::cout << "| Fibonacci series record dump at addresses:\t[" << ptr_st_rec_Fibo << "]\t:\t[" << &st_rec_Fibo << "]." << std::endl << std::endl;

				/* Generation of results and filling of the structure pointer. */
				for (T idx {V_ZERO<T>}; idx < quantity; idx++, counting_items++)
					{
						/* Assignment of calculations to the structure variable to pointer. */
						st_rec_Fibo.idx = idx;
						st_rec_Fibo.addition = st_rec_Fibo.first_number + st_rec_Fibo.second_number;

						/* Saving values in the local structure. */
						std::cout << "|\t[" << &st_rec_Fibo.idx
							<< "] = [" << st_rec_Fibo.idx
							<< "]\t:\t[" <<  &st_rec_Fibo.first_number
							<< "] = [" <<  st_rec_Fibo.first_number
							<< "] + [" << &st_rec_Fibo.first_number
							<< "] = [" << st_rec_Fibo.second_number
							<< "] => [" << &st_rec_Fibo.addition
							<< "] = [" << st_rec_Fibo.addition
							<< "]." << std::endl << std::endl;

						/* Saving the structure in the vector or created pointer. */
						*(ptr_st_rec_Fibo + idx) = st_rec_Fibo;

						std::cout << "|\t[" << ptr_st_rec_Fibo[idx].idx
							<< "] = [" << (ptr_st_rec_Fibo + idx)->idx
							<< "]\t\t:\t[" <<  &ptr_st_rec_Fibo[idx].idx
							<< "] = [" <<  &(ptr_st_rec_Fibo + idx)->idx
							<< "]\t->" << std::endl << "|" << std::endl;

						std::cout << "|\t\t[" << ptr_st_rec_Fibo[idx].first_number
							<< "] = [" << (ptr_st_rec_Fibo + idx)->first_number
							<< "]\t:\t[" <<  &ptr_st_rec_Fibo[idx].first_number
							<< "] = [" <<  &(ptr_st_rec_Fibo + idx)->first_number
							<< "]\t+"<< std::endl;

						std::cout << "|\t\t[" << ptr_st_rec_Fibo[idx].second_number
							<< "] = [" << (ptr_st_rec_Fibo + idx)->second_number
							<< "]\t:\t[" <<  &ptr_st_rec_Fibo[idx].second_number
							<< "] = [" <<  &(ptr_st_rec_Fibo + idx)->second_number
							<< "]\t=>" << std::endl;

						std::cout << "|\t\t[" << ptr_st_rec_Fibo[idx].addition
							<< "] = [" << (ptr_st_rec_Fibo + idx)->addition
							<< "]\t:\t[" <<  &ptr_st_rec_Fibo[idx].addition
							<< "] = [" <<  &(ptr_st_rec_Fibo + idx)->addition
							<< "]." << std::endl << "|" << std::endl;

						/* Reassignment of Fibonacci series values. */
						st_rec_Fibo.first_number = st_rec_Fibo.second_number;
						st_rec_Fibo.second_number = st_rec_Fibo.addition;
					}

					/* Show the pointer of the structure of the generated series. */
					std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
					std::cout << "| Fibonacci series consecutive sum. |" << std::endl;
					std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;

					for (T idx {V_ZERO<T>}; idx < quantity; idx++)
						std::cout << "[" << ptr_st_rec_Fibo[idx].addition << "].\t";

					std::cout << std::endl << "+---|----+---|----+---|----+---|----+" << std::endl;
			}
		else
			std::cerr << std::endl << "An error occurred while allocating memory to the Fibonacci struct pointer." << std::endl;

		/* Expected results. */
		std::cout << "[" << counting_items << "] Generated dumping output results." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Dynamic memory allocations with the list of created items. */
		return (p_st_rec_Fibo && ptr_st_rec_Fibo) ? *p_st_rec_Fibo = ptr_st_rec_Fibo : NULL;
	}

/* Function to take breaks when strictly necessary. */
void enter_a_pause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/* Function to capture a specific value from the console. */
template <typename T>
const T& enter_a_value(T *const &ptr_value)
	{
		static T ZERO {T(V_ZERO<T>)};

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

		return (ptr_value) ? *ptr_value : ZERO;
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **			T getFib (const T& number);		**
 ** Explanation:	This function aims to calculate		**
 **			Fibonacci numbers up to a given		**
 **			position, taking as a base the initial	**
 **			values ​​of zero and one up to the number	**
 **			of iterations indicated as the final	**
 **			quantity number.			**
 ** Input Parms:	const T& number.			**
 ** Output Parms:	None.					**
 ** Result:		Fibonacci number calculation function.	**
 **			======================================	**
 **			Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 **								**
 **			This recursive function obeys the	**
 **			next condition:				**
 **			Fibo(n) = (n <= 1) ?			**
 **				n : Fibo(n - 1) + Fibo (n -2).	**
 *****************************************************************/
template <typename T>
T getFib(const T& number)
	{
		std::cout << std::endl << "Processing Fib: (" << number << ")..." << std::endl;

		if (number < V_THREE<T>)
			{
				std::cout << "> Giving back: (" << V_ONE<T> << ")." << std::endl;
				return V_ONE<T>;
			}
		else
			{
				std::cout << "> Calling Fib: (" << number - V_TWO<T> <<") and Fib: (" << number - V_ONE<T> << ")." << std::endl;
				return getFib(number - V_TWO<T>) + getFib(number - V_ONE<T>);
			}
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **			T get_Fib				**
 **				(T number,			**
 **				 T first_number = V_ZERO<T>,	**
 **				 T second_number = V_ONE<T>);	**
 ** Explanation:	This function aims to calculate		**
 **			Fibonacci numbers up to a given		**
 **			position, taking as a base the initial	**
 **			values ​​of zero and one up to the number	**
 **			of iterations indicated as the final	**
 **			quantity number.			**
 ** Input Parms:	T number.				**
 **			T first_number = V_ZERO<T>.		**
 **			T second_number = V_ONE<T>.		**
 ** Output Parms:	None.					**
 ** Result:							**
 **			Fibonacci number calculation function.	**
 **			======================================	**
 **			Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 **								**
 **			This recursive function obeys the	**
 **			next condition:				**
 **			Fibo(n) = (n <= 1) ?			**
 **				n : Fibo(n - 1) + Fibo (n -2).	**
 *****************************************************************/
template <typename T>
T get_Fib(T number, T first_number = V_ZERO<T>, T second_number = V_ONE<T>)
	{
		T addition {first_number + second_number};

		if (number < V_THREE<T>)
			return V_ONE<T>;

		for (number -= V_THREE<T>; number != V_ZERO<T>; number--)
			{
				second_number = first_number;
				first_number = addition;
				addition = first_number + second_number;
			}

		return addition;
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **			T getFibo (const T& quantity);		**
 ** Explanation:	This function calculates the last number**
 **			of the Fibonacci series given a given	**
 **			number of series to generate, and	**
 **			obtains it discursively, exchanging the	**
 **			first value for the second and the	**
 **			latter for the sum of the first and	**
 **			second values, until reaching a		**
 **			iteration such that the value is less	**
 **			than or equal to unity (1).		**
 ** Input Parms:	const T& quantity.			**
 ** Output Parms:	None.					**
 ** Result:		Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 **								**
 **			This recursive function obeys the	**
 **			next condition:				**
 **			Fibo(n) = (n <= 1) ?			**
 **				n : Fibo(n - 1) + Fibo (n -2).	**
 *****************************************************************/
template <typename T>
T getFibo(const T& quantity)
	{
		return (quantity > V_ONE<T>) ? getFibo(quantity - V_ONE<T>) + getFibo(quantity - V_TWO<T>) : quantity;
	};

/*****************************************************************
 ** Function:		template <typename T>			**
 **			T getFibonacci				**
 **				(const T& quantity,		**
 **				 const T& first_number,		**
 **				 const T& second_number);	**
 ** Explanation:	This function calculates the last number**
 **			of the Fibonacci series given a given	**
 **			number of series to generate, and	**
 **			obtains it discursively, exchanging the	**
 **			first value for the second and the	**
 **			latter for the sum of the first and	**
 **			second values, until reaching a		**
 **			iteration such that the value is less	**
 **			than or equal to unity (1).		**
 ** Input Parms:	const T& quantity.			**
 **			const T& first_number.			**
 **			const T& second_number.			**
 ** Output Parms:	None.					**
 ** Result:		Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 **								**
 **			This recursive function obeys the	**
 **			next condition:				**
 **			Fibo(n, x, y) = (n <= 1) ?		**
 **				x + y : Fibo(n - 1, y, x + y).	**
 ****************************************************************/
template <typename T>
T getFibonacci(const T& quantity, const T& first_number, const T& second_number)
	{
		return	(quantity <= V_ONE<T>) ? first_number + second_number :
			getFibonacci(quantity + V_MINUS_ONE<T>, second_number, first_number + second_number);
	};

/*****************************************************************
 ** Function:		template <typename T>			**
 **			std::vector				**
 **			<Fibonacci_Record, My_Allocator		**
 **				<Fibonacci_Record<T>>>		**
 **				getVectorFibo			**
 **				(const T& quantity,		**
 **				 const T& first_number,		**
 **				 const T& second_number);	**
 ** Explanation:	This function's primary objective is to **
 **			generate a structure-type vector that	**
 **			stores the control fields for the	**
 **			generation of the Fibonacci number	**
 **			series through cycles and returns each	**
 **			record that was obtained from the	**
 **			calculation until the number of terms	**
 **			desired by the user is reached.		**
 ** Input Parms:	const T& quantity.			**
 **			const T& first_number.			**
 **			const T& second_number.			**
 ** Output Parms:	None.					**
 ** Result:		The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
template <typename T>
std::vector<Fibonacci_Record<T>, My_Allocator<Fibonacci_Record<T>>> getVectorFibo(const T& quantity, const T& first_number, const T& second_number)
	{
		/* Initial declaration of work variables. */
		T counting_items {V_ZERO<T>};

		Fibonacci_Record<T> st_rec_Fibo {};
		std::vector<Fibonacci_Record<T>, My_Allocator<Fibonacci_Record<T>>> vec_st_rec_Fibo {};

		/* Initial assignment of series starting values. */
		st_rec_Fibo.first_number = first_number;
		st_rec_Fibo.second_number = second_number;

		/* Routine information window. */
		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+     Fibonnaci Number Creation.    +" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "| Generating the Fibonacci Series..." << std::endl;

		/* Filling a 'vector' class with the summation calculations of the Fibonacci series. */
		for (T idx {V_ZERO<T>}; idx < quantity; idx++, counting_items++)
			{
				st_rec_Fibo.idx = idx;
				st_rec_Fibo.addition = st_rec_Fibo.first_number + st_rec_Fibo.second_number;

				vec_st_rec_Fibo.push_back(st_rec_Fibo);	//Saving the structure in the vector.

				std::cout << "| # [" << st_rec_Fibo.idx << "]:\t[" << st_rec_Fibo.first_number << "]\t+\t[" << st_rec_Fibo.second_number << "]\t=\t[" << st_rec_Fibo.addition << "]." << std::endl;

				st_rec_Fibo.first_number = st_rec_Fibo.second_number;
				st_rec_Fibo.second_number = st_rec_Fibo.addition;
			}

		/* Expected results. */
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "[" << counting_items << "] : [" << vec_st_rec_Fibo.size() << "] Generated output results." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		return vec_st_rec_Fibo;
	};

/*****************************************************************
 ** Function:		template <typename T>			**
 **			void viewInfoFibo			**
 **				(const T& quantity,		**
 **				 const T& first_number,		**
 **				 const T& second_number,	**
 **				 const std::vector		**
 **					<Fibonacci_Record<T>,	**
 **					My_Allocator		**
 **					<Fibonacci_Record<T>>>&	**
 **					vec_st_rec_Fibo,	**
 **				 const T& recursive_Fibo);	**
 ** Explanation:	The purpose of this function is to show	**
 **			the general information with which the	**
 **			series of iterative Fibonacci numbers	**
 **			was generated and, in turn, the result	**
 **			of a call to a recursive function that	**
 **			returns the last value generated from a	**
 **			series with two given numbers up to 'n'	**
 **			cycles.					**
 ** Input Parms:	const T& quantity,			**
 **			const T& first_number,			**
 **			const T& second_number,			**
 **			const std::vector<Fibonacci_Record<T>,	**
 **				My_Allocator			**
 **					<Fibonacci_Record<T>>&	**
 **					vec_st_rec_Fibo.	**
 **			const T& recursive_Fibo.		**
 ** Output Parms:	None.					**
 ** Result:		This function shows the most relevant	**
 **			output results of the generation of the	**
 **			numbers that make up the Fibonacci	**
 **			series given a pair of numbers up to	**
 **			'n' iterations.				**
 ****************************************************************/
template <typename T>
void viewInfoFibo(const T& quantity, const T& first_number, const T& second_number, const std::vector<Fibonacci_Record<T>, My_Allocator<Fibonacci_Record<T>>>& vec_st_rec_Fibo, const T& recursive_Fibo)
	{
		/* Call to a recursive function that obtains the direct Fibonacci of two values. */
		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+ Direct Fibonnaci Number Generator.+" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "| [" << quantity << "] : [" << vec_st_rec_Fibo.size() << "] Fibonacci series records." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| * First  value:\t[" << first_number << "]." << std::endl;
		std::cout << "| * Second value:\t[" << second_number << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| > Final  value:\t[" << recursive_Fibo << "]." << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		enter_a_pause("Press the ENTER key to continue...");
	};

/*****************************************************************
 ** Function:		template <typename T>			**
			T viewVectorFibo			**
 **				(const std::vector		**
 **				<Fibonacci_Record<T>,		**
 **				My_Allocator			**
 **				<Fibonacci_Record<T>>>&		**
 **					vec_st_rec_Fibo;	**
 ** Explanation:	The final goal of this procedure is to	**
 **			display the vector generated in the	**
 **			'getVectorFiboSeries' function returned **
 **			as an intrinsic part of its return	**
 **			value, and to display the message series**
 **			of the structure content stored in the	**
 **			vector of Fibonacci numbers by		**
 **			traversing an iterator.			**
 ** Input Parms:	const std::vector<Fibonacci_Record<T>,	**
 **				My_Allocator			**
 **				<Fibonacci_Record<T>>>&		**
 **			 		vec_st_rec_Fibo		**
 ** Output Parms:	None.					**
 ** Result:		Returns each calculation record for the **
 **			generation of Fibonacci series numbers. **
 **								**
 ** 			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
template <typename T>
T viewVectorFibo(const std::vector<Fibonacci_Record<T>, My_Allocator<Fibonacci_Record<T>>>& vec_st_rec_Fibo)
	{
		/* Initial declaration of work variables. */
		T counting_items {V_ZERO<T>};

		/* Routine information window. */
		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+Fibonacci Number Generator Results.+" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "| Number of records calculated: [" << vec_st_rec_Fibo.size() << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

		/* Generation and implementation of an automatic iterator for the 'vector' class. */
		for (typename std::vector<Fibonacci_Record<T>, My_Allocator<Fibonacci_Record<T>>>::const_iterator itc_vec_st_rec_Fibo = std::cbegin(vec_st_rec_Fibo); itc_vec_st_rec_Fibo != std::cend(vec_st_rec_Fibo); itc_vec_st_rec_Fibo++, counting_items++)
			std::cout << "| # [" << itc_vec_st_rec_Fibo->idx << "]:\t[" << itc_vec_st_rec_Fibo->first_number << "]\t+\t[" << itc_vec_st_rec_Fibo->second_number << "]\t=\t[" << (*itc_vec_st_rec_Fibo).addition << "]." << std::endl;

		/* Expected results. */
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "[" << counting_items << "] : [" << vec_st_rec_Fibo.size() <<  "] Generated output results." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		return counting_items;
	};

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function of this program	**
 **			requests three values: First, the number**
 **			of records that the series will contain:**
 **			Second, the first reference value;	**
 **			Third and last, the second reference	**
 **			value. With these current parameters,	**
 **			the functions 'getVectorFibo' and	**
 **			'viewVectorFibo' will be called		**
 **			to observe the detailed calculations of	**
 **			each record of the Fibonacci series.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		This main function calls the		**
 **			aforementioned functions to calculate	**
 **			and display the structure vector that	**
 **			stores the unit records of the		**
 **			Fibonacci series, given a specified	**
 **			number of terms.			**
 **								**
 ** 			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		char chr_response {NULL_CHARACTER<char>};
		size_t *list_Fibonacci {nullptr}, recursive_Fibo{};
		std::vector<Fibonacci_Record<size_t>, My_Allocator<Fibonacci_Record<size_t>>> vec_st_rec_Fibo {};
		Fibonacci_Record<size_t> *ptr_Fibonacci_Record {nullptr};

		/* Intermediate calculation variables. */
		size_t quantity {V_ZERO<size_t>};
		size_t first_number {V_ZERO<size_t>};
		size_t second_number {V_ZERO<size_t>};

		/* Routine information window. */
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+     Fibonacci Number Generator.   +" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "Numbers of Fibonacci to generate from [" << V_LOWER_LIMIT_FIBO<size_t> << "] to [" << V_UPPER_LIMIT_MAX<size_t> << "]: ";

		try {quantity = enter_a_value<std::size_t>(&quantity);}
		catch (const std::exception& e)
		{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* Verification of the generation intervals of the Fibonacci series. */
		if (quantity >= V_LOWER_LIMIT_FIBO<size_t> && quantity <= V_UPPER_LIMIT_MAX<size_t>)
			{
				/* Request for boot values. */
				std::cout << "+ First  number: ";
				try {first_number = enter_a_value<std::size_t>(&first_number);}
				catch (const std::exception& e)
				{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

				std::cout << "+ Second number: ";
				try {second_number = enter_a_value<std::size_t>(&second_number);}
				catch (const std::exception& e)
				{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

				if (first_number || second_number)
					{
						/* Generate a pointer to the dynamic structure of the Fibonacci series. */
						try
							{
								if ((ptr_Fibonacci_Record = dump_record_Fibonacci<size_t>(quantity, first_number, second_number, &ptr_Fibonacci_Record)))
									/* Memory cleaning assigned areas. */
									std::free(ptr_Fibonacci_Record);
								else
									std::cerr << CARRIAGE_RETURN<char> << "It was not possible to create the structure pointer for the Fibonacci series." << CARRIAGE_RETURN<char>;
							}
						catch (const std::exception& e)
						{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

						/* Generate a vector to a static structure of the Fibonacci series. */
						try
							{
								vec_st_rec_Fibo = getVectorFibo<size_t>(quantity, first_number, second_number);
								viewVectorFibo<size_t>(vec_st_rec_Fibo);
							}
						catch (const std::exception& e)
						{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

						/* Shows the general information of the Fibonacci series. */
						viewInfoFibo<size_t>(quantity, first_number, second_number, vec_st_rec_Fibo, getFibonacci(quantity, first_number, second_number));

						/* Displays the base Fibonacci value with default values ​​of one and one. */
						recursive_Fibo = get_Fib<size_t>(quantity, V_ONE<size_t>, V_ONE<size_t>);

						std::cout << std::endl;
						std::cout << "+---|----+---|----+---|----+" << std::endl;
						std::cout << "| Fibonacci with one & one.|" << std::endl;
						std::cout << "+---|----+---|----+---|----+" << std::endl;
						std::cout << "| + Iters:\t[" << quantity << "]." << std::endl;
						std::cout << "| + Result:\t{" << recursive_Fibo << "}." << std::endl;
						std::cout << "+---|----+---|----+---|----+" << std::endl;
						enter_a_pause("Press the ENTER key to continue...");

						/* Displays the regular and normal fibonacci series with intermediate messages. */
						std::cout << std::endl << "Calculate the common Fibonacci function" << std::endl;
						std::cout << "but showing intermediate calculation messages." << std::endl;
						std::cout << "This could take a long time." << std::endl;
						std::cout << "Do you want to calculate this anyway? (y/n) : ";

						try {chr_response = enter_a_value<char>(&chr_response);}
						catch (const std::exception& e)
						{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

						/* Validate the suitability of the calculation. */
						if ((chr_response == V_CHAR_LOWER_Y<char>) || (chr_response == V_CHAR_UPPER_Y<char>))
							{
								std::cout << "Generating value..." << std::endl;
								recursive_Fibo = getFib<size_t>(quantity);

								/* Messages of the generated output results. */
								std::cout << std::endl;
								std::cout << "+---|----+---|----+---|----+" << std::endl;
								std::cout << "| Fibonacci Final Results. |" << std::endl;
								std::cout << "+---|----+---|----+---|----+" << std::endl;
								std::cout << "| + Position:\t[" << quantity << "]." << std::endl;
								std::cout << "| + Result:\t{" << recursive_Fibo << "}." << std::endl;
								std::cout << "+---|----+---|----+---|----+" << std::endl;
								enter_a_pause("Press the ENTER key to continue...");
							}

						/* Displays the regular and normal fibonacci series. */
						std::cout << std::endl << "Calculate a common regular recursive function." << std::endl;
						std::cout << "This could take a long time." << std::endl;
						std::cout << "Do you want to calculate it anyway? (y/n) : ";

						try {chr_response = enter_a_value<char>(&chr_response);}
						catch (const std::exception& e)
						{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

						/* Validate the suitability of the calculation. */
						if ((chr_response == V_CHAR_LOWER_Y<char>) || (chr_response == V_CHAR_UPPER_Y<char>))
							{
								std::cout << "Generating value..." << std::endl;
								recursive_Fibo = getFibo<size_t>(quantity);

								std::cout << std::endl;
								std::cout << "+---|----+---|----+---|----+" << std::endl;
								std::cout << "|Fibonacci with zero & one.|" << std::endl;
								std::cout << "+---|----+---|----+---|----+" << std::endl;
								std::cout << "| + Cycles:\t[" << quantity << "]." << std::endl;
								std::cout << "| - Result:\t{" << recursive_Fibo << "}." << std::endl;
								std::cout << "+---|----+---|----+---|----+" << std::endl;
								enter_a_pause("Press the ENTER key to continue...");
							}

						/* Display the simple list of Fibonacci numbers in the traditional way. */
						try
							{
								if ((list_Fibonacci = breakdown_Fibonacci<size_t>(quantity, first_number, second_number, &list_Fibonacci)))
									/* Memory cleaning assigned areas. */
									delete [] list_Fibonacci;
								else
									std::cerr << CARRIAGE_RETURN<char> << "It was not possible to create the integer pointer for the Fibonacci series." << CARRIAGE_RETURN<char>;
							}
						catch (const std::exception& e)
						{std::cout << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}
					}
				else
					std::cerr << CARRIAGE_RETURN<char> << "One of the two starting numbers must be different from zero." << CARRIAGE_RETURN<char>;
			}
		else
			std::cerr << "The number: [" << quantity << "] is out of range from: [" << V_LOWER_LIMIT_FIBO<size_t> << "] to: [" << V_UPPER_LIMIT_MAX<size_t> << "]." << std::endl;

		std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
		std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

		return EXIT_SUCCESS;
	}
