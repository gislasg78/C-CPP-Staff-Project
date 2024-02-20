/****************** Fibonacci Number Generator. ******************
 ** Source Code:	Fibonacc.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
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
//C Standard Libraries.
#include <iostream>
#include <vector>

//Lower and upper limit constants.
#define	V_LOWER_LIMIT_FIBO	1
#define V_UPPER_LIMIT_MAX	45

//Work Symbolic Constants.
#define	V_MINUS_ONE		-1
#define	V_ONE			1
#define V_ZERO			0

/*--------------------------------------------------------------**
 * Data structure that stores the generated calculation record	--
 * number, the first and second numbers and the sum of these	--
 * that are part of the generation of the Fibonacci series of	--
 * numbers.							--
 *--------------------------------------------------------------*/
struct strct_record_Fibonacci
	{
		size_t szt_idx;			//Calculated record number of the Fibonacci series.
		size_t szt_First_Number;	//First game number of the series.
		size_t szt_Second_Number;	//Second starting number of the series.
		size_t szt_Addition;		//Sum of both previous numbers.
	};

/*****************************************************************
 ** Function:		struct strct_record_Fibonacci		**
 **				*dump_record_Fibonacci		**
 **				(const size_t szt_Quantity,	**
 **				 const size_t szt_First_Number,	**
 **				 const size_t			**
 **					szt_Second_Number,	**
 **				struct strct_record_Fibonacci	**
 **					**ptr_ptr_st_rec_Fibo);	**
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
 ** Input Parms:	const size_t szt_Quantity.		**
 **			const size_t szt_First_Number.		**
 **			const size_t szt_Second_Number,		**
 **			struct strct_record_Fibonacci		**
 **				**ptr_ptr_st_rec_Fibo.		**
 ** Output Parms:	struct strct_record_Fibonacci		**
 **				**ptr_ptr_st_rec_Fibo.		**
 ** Result:		Returns the last number of the Fibonacci**
 **			series given a series of given terms.	**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
struct strct_record_Fibonacci *dump_record_Fibonacci(const size_t szt_Quantity, const size_t szt_First_Number, const size_t szt_Second_Number, struct strct_record_Fibonacci **ptr_ptr_st_rec_Fibo)
	{
		/* Initial declaration of work variables. */
		size_t szt_counting_items = V_ZERO;
		struct strct_record_Fibonacci st_rec_Fibo = {V_ZERO, V_ZERO, V_ZERO, V_ZERO}, *ptr_st_rec_Fibo = &st_rec_Fibo;

		/* Initial assignment of series starting values. */
		st_rec_Fibo.szt_First_Number = szt_First_Number;
		st_rec_Fibo.szt_Second_Number = szt_Second_Number;

		/* Routine information window. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+Fibonnaci Number Dumping Breakdown.+" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| Generating the Fibonacci Series..." << std::endl;

		/* Dynamically allocate memory for the Fibonacci structure pointer. */
		if (ptr_st_rec_Fibo = (struct strct_record_Fibonacci *) malloc(szt_Quantity * sizeof(st_rec_Fibo)))
			{
				std::cout << "| Fibonacci series record dump at addresses:\t[" << ptr_st_rec_Fibo << "]\t:\t[" << &st_rec_Fibo << "]." << std::endl << std::endl;

				/* Generation of results and filling of the structure pointer. */
				for (size_t szt_idx = V_ZERO; szt_idx < szt_Quantity; szt_idx++, szt_counting_items++)
					{
						/* Assignment of calculations to the structure variable to pointer. */
						st_rec_Fibo.szt_idx = szt_idx;
						st_rec_Fibo.szt_Addition = st_rec_Fibo.szt_First_Number + st_rec_Fibo.szt_Second_Number;

						/* Saving values in the local structure. */
						std::cout << "|\t[" << &st_rec_Fibo.szt_idx
							<< "] = [" << st_rec_Fibo.szt_idx
							<< "]\t:\t[" <<  &st_rec_Fibo.szt_First_Number
							<< "] = [" <<  st_rec_Fibo.szt_First_Number
							<< "] + [" << &st_rec_Fibo.szt_First_Number
							<< "] = [" << st_rec_Fibo.szt_Second_Number
							<< "] => [" << &st_rec_Fibo.szt_Addition
							<< "] = [" << st_rec_Fibo.szt_Addition
							<< "]." << std::endl << std::endl;

						/* Saving the structure in the vector or created pointer. */
						*(ptr_st_rec_Fibo + szt_idx) = st_rec_Fibo;

						std::cout << "|\t[" << ptr_st_rec_Fibo[szt_idx].szt_idx
							<< "] = [" << (ptr_st_rec_Fibo + szt_idx)->szt_idx
							<< "]\t\t:\t[" <<  &ptr_st_rec_Fibo[szt_idx].szt_idx
							<< "] = [" <<  &(ptr_st_rec_Fibo + szt_idx)->szt_idx
							<< "]\t->" << std::endl << "|" << std::endl;

						std::cout << "|\t\t[" << ptr_st_rec_Fibo[szt_idx].szt_First_Number
							<< "] = [" << (ptr_st_rec_Fibo + szt_idx)->szt_First_Number
							<< "]\t:\t[" <<  &ptr_st_rec_Fibo[szt_idx].szt_First_Number
							<< "] = [" <<  &(ptr_st_rec_Fibo + szt_idx)->szt_First_Number
							<< "]\t+"<< std::endl;

						std::cout << "|\t\t[" << ptr_st_rec_Fibo[szt_idx].szt_Second_Number
							<< "] = [" << (ptr_st_rec_Fibo + szt_idx)->szt_Second_Number
							<< "]\t:\t[" <<  &ptr_st_rec_Fibo[szt_idx].szt_Second_Number
							<< "] = [" <<  &(ptr_st_rec_Fibo + szt_idx)->szt_Second_Number
							<< "]\t=>" << std::endl;

						std::cout << "|\t\t[" << ptr_st_rec_Fibo[szt_idx].szt_Addition
							<< "] = [" << (ptr_st_rec_Fibo + szt_idx)->szt_Addition
							<< "]\t:\t[" <<  &ptr_st_rec_Fibo[szt_idx].szt_Addition
							<< "] = [" <<  &(ptr_st_rec_Fibo + szt_idx)->szt_Addition
							<< "]." << std::endl << "|" << std::endl;

						/* Reassignment of Fibonacci series values. */
						st_rec_Fibo.szt_First_Number = st_rec_Fibo.szt_Second_Number;
						st_rec_Fibo.szt_Second_Number = st_rec_Fibo.szt_Addition;
					}

					/* Show the pointer of the structure of the generated series. */
					std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
					std::cout << "| Fibonacci series consecutive sum. |" << std::endl;
					std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

					for (size_t szt_idx = V_ZERO; szt_idx < szt_Quantity; szt_idx++)
						std::cout << "[" << ptr_st_rec_Fibo[szt_idx].szt_Addition << "].\t";

					std::cout << std::endl << "+---|----+---|----+---|----+---|----+" << std::endl;
			}

		/* Expected results. */
		std::cout << "[" << szt_counting_items << "] Generated dumping output results." << std::endl;

		if (ptr_ptr_st_rec_Fibo) *ptr_ptr_st_rec_Fibo = ptr_st_rec_Fibo;

		return ptr_st_rec_Fibo;
	}

/*****************************************************************
 ** Function:		static size_t getsztFibonacci		**
 **				(const size_t szt_Quantity,	**
 **				 const size_t szt_First_Number,	**
 **				 const size_t 			**
 **					szt_Second_Number);	**
 ** Explanation:	This function calculates the last number**
 **			of the Fibonacci series given a given	**
 **			number of series to generate, and	**
 **			obtains it discursively, exchanging the	**
 **			first value for the second and the	**
 **			latter for the sum of the first and	**
 **			second values, until reaching a		**
 **			iteration such that the value is less	**
 **			than or equal to unity (1).		**
 ** Input Parms:	const size_t szt_Quantity.		**
 **			const size_t szt_First_Number.		**
 **			const size_t szt_Second_Number.		**
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
static int getsztFibonacci(const size_t szt_Quantity, const size_t szt_First_Number, const size_t szt_Second_Number)
	{
		return	(szt_Quantity <= V_ONE) ? szt_First_Number + szt_Second_Number :
			getsztFibonacci(szt_Quantity + V_MINUS_ONE, szt_Second_Number, szt_First_Number + szt_Second_Number);
	};

/*****************************************************************
 ** Function:		std::vector				**
 **			<struct strct_record_Fibonacci>		**
 **			getVectorstrctFiboSeries		**
 **				(const size_t szt_Quantity,	**
 **				 const size_t szt_First_Number,	**
 **				 const size_t			**
 **					szt_Second_Number);	**
 ** Explanation:	This function's primary objective is to **
 **			generate a structure-type vector that	**
 **			stores the control fields for the	**
 **			generation of the Fibonacci number	**
 **			series through cycles and returns each	**
 **			record that was obtained from the	**
 **			calculation until the number of terms	**
 **			desired by the user is reached.		**
 ** Input Parms:	const size_t szt_Quantity.		**
 **			const size_t szt_First_Number.		**
 **			const size_t szt_Second_Number.		**
 ** Output Parms:	None.					**
 ** Result:		The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
std::vector<struct strct_record_Fibonacci> getVectorstrctFiboSeries(const size_t szt_Quantity, const size_t szt_First_Number, const size_t szt_Second_Number)
	{
		/* Initial declaration of work variables. */
		size_t szt_counting_items = V_ZERO;

		struct strct_record_Fibonacci st_rec_Fibo = {V_ZERO, V_ZERO, V_ZERO, V_ZERO};
		std::vector<struct strct_record_Fibonacci> vec_st_rec_Fibo;

		/* Initial assignment of series starting values. */
		st_rec_Fibo.szt_First_Number = szt_First_Number;
		st_rec_Fibo.szt_Second_Number = szt_Second_Number;

		/* Routine information window. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+     Fibonnaci Number Creation.    +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| Generating the Fibonacci Series..." << std::endl;

		/* Filling a 'vector' class with the summation calculations of the Fibonacci series. */
		for (size_t szt_idx = V_ZERO; szt_idx < szt_Quantity; szt_idx++, szt_counting_items++)
			{
				st_rec_Fibo.szt_idx = szt_idx;
				st_rec_Fibo.szt_Addition = st_rec_Fibo.szt_First_Number + st_rec_Fibo.szt_Second_Number;

				vec_st_rec_Fibo.push_back(st_rec_Fibo);	//Saving the structure in the vector.

				std::cout << "| # [" << st_rec_Fibo.szt_idx << "]:\t[" << st_rec_Fibo.szt_First_Number << "]\t+\t[" << st_rec_Fibo.szt_Second_Number << "]\t=\t[" << st_rec_Fibo.szt_Addition << "]." << std::endl;

				st_rec_Fibo.szt_First_Number = st_rec_Fibo.szt_Second_Number;
				st_rec_Fibo.szt_Second_Number = st_rec_Fibo.szt_Addition;
			}

		/* Expected results. */
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "[" << szt_counting_items << "] : [" << vec_st_rec_Fibo.size() << "] Generated output results." << std::endl;

		return vec_st_rec_Fibo;
	};

/*****************************************************************
 ** Function:		size_t viewVectorstrctFiboSeries	**
 **				(std::vector			**
 **				<struct strct_record_Fibonacci	**
 **					vec_st_rec_Fibo>);	**
 ** Explanation:	The final goal of this procedure is to	**
 **			display the vector generated in the	**
 **			'getVectorFiboSeries' function returned **
 **			as an intrinsic part of its return	**
 **			value, and to display the message series**
 **			of the structure content stored in the	**
 **			vector of Fibonacci numbers by		**
 **			traversing an iterator.			**
 ** Input Parms:	std::vector<struct			**
 **				strct_record_Fibonacci		**
 **			 		vec_st_rec_Fibo>	**
 ** Output Parms:	None.					**
 ** Result:		Returns each calculation record for the **
 **			generation of Fibonacci series numbers. **
 **								**
 ** 			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
size_t viewVectorstrctFiboSeries(std::vector<struct strct_record_Fibonacci> vec_st_rec_Fibo)
	{
		/* Initial declaration of work variables. */
		int szt_counting_items = V_ZERO;
		std::vector<struct strct_record_Fibonacci>::iterator it_vec_st_rec_Fibo;

		/* Routine information window. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+Fibonacci Number Generator Results.+" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| Number of records calculated: [" << vec_st_rec_Fibo.size() << "]." << std::endl;

		/* Generation and implementation of an automatic iterator for the 'vector' class. */
		for (it_vec_st_rec_Fibo = std::begin(vec_st_rec_Fibo); it_vec_st_rec_Fibo != std::end(vec_st_rec_Fibo); it_vec_st_rec_Fibo++, szt_counting_items++)
			std::cout << "| # [" << it_vec_st_rec_Fibo->szt_idx << "]:\t[" << it_vec_st_rec_Fibo->szt_First_Number << "]\t+\t[" << it_vec_st_rec_Fibo->szt_Second_Number << "]\t=\t[" << it_vec_st_rec_Fibo->szt_Addition << "]." << std::endl;

		/* Expected results. */
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "[" << szt_counting_items << "] : [" << vec_st_rec_Fibo.size() <<  "] Generated output results." << std::endl;

		return szt_counting_items;
	};

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function of this program	**
 **			requests three values: First, the number**
 **			of records that the series will contain:**
 **			Second, the first reference value;	**
 **			Third and last, the second reference	**
 **			value. With these current parameters,	**
 **			the functions 'getVectorFiboSeries' and	**
 **			'viewVectorFiboSeries' will be called	**
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
		std::vector<struct strct_record_Fibonacci> vec_st_rec_Fibo;
		struct strct_record_Fibonacci *ptr_strct_record_Fibonacci = NULL;

		/* Intermediate calculation variables. */
		size_t szt_counting_items = V_ZERO;
		size_t szt_Quantity = V_ZERO;
		size_t szt_First_Number = V_ZERO;
		size_t szt_Second_Number = V_ZERO;

		/* Routine information window. */
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+     Fibonacci Number Generator.   +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Numbers of Fibonacci to generate from [" << V_LOWER_LIMIT_FIBO << "] to [" << V_UPPER_LIMIT_MAX << "]: ";
		std::cin >> szt_Quantity;

		/* Verification of the generation intervals of the Fibonacci series. */
		if (szt_Quantity >= V_LOWER_LIMIT_FIBO && szt_Quantity <= V_UPPER_LIMIT_MAX)
			{
				/* Request for boot values. */
				std::cout << "First  number: ";
				std::cin >> szt_First_Number;
				std::cout << "Second number: ";
				std::cin >> szt_Second_Number;

				/* Generate a pointer to the dynamic structure of the Fibonacci series. */
				ptr_strct_record_Fibonacci = dump_record_Fibonacci(szt_Quantity, szt_First_Number, szt_Second_Number, &ptr_strct_record_Fibonacci);

				/* Generate a vector to a static structure of the Fibonacci series. */
				vec_st_rec_Fibo = getVectorstrctFiboSeries(szt_Quantity, szt_First_Number, szt_Second_Number);
				szt_counting_items = viewVectorstrctFiboSeries(vec_st_rec_Fibo);

				/* Call to a recursive function that obtains the direct Fibonacci of two values. */
				std::cout << std::endl;
				std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
				std::cout << "+ Direct Fibonnaci Number Generator.+" << std::endl;
				std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
				std::cout << "| [" << szt_Quantity << "] : [" << vec_st_rec_Fibo.size() << "] Fibonacci series records." << std::endl;
				std::cout << "+-----------------------------------+" << std::endl;
				std::cout << "| First  value:\t[" << szt_First_Number << "]." << std::endl;
				std::cout << "| Second value:\t[" << szt_Second_Number << "]." << std::endl;
				std::cout << "+-----------------------------------+" << std::endl;
				std::cout << "| Final  value:\t[" << getsztFibonacci(szt_Quantity, szt_First_Number, szt_Second_Number) << "]." << std::endl;
				std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

				/* Memory cleaning. */
				free(ptr_strct_record_Fibonacci);
				vec_st_rec_Fibo.clear();
			}
		else
			std::cout << "The number [" << szt_Quantity << "] is out of range from [" << V_LOWER_LIMIT_FIBO << "] to [" << V_UPPER_LIMIT_MAX << "]." << std::endl;

		return V_ZERO;
	}
