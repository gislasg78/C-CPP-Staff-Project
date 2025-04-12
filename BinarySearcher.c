/* Program that performs binary searches with cycles
   in the traditional way as well as with a 'delta' factor and other modalities. */

//Standard work libraries.
#include <stdio.h>
#include <stdlib.h>

//Macro for partitioning a binary delta search.
#define	MEDIUM(x)	(((x) + V_ONE) / V_TWO)

//Symbolic constants of working characters.
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'
#define	V_CHR_UPPER_Y	0x59
#define	V_CHR_LOWER_Y	0x79

//Symbolic work constants.
#define	V_MINUS_ONE	-1
#define	V_TEN		10
#define	V_THREE		3
#define	V_TWO		2
#define	V_ONE		1
#define	V_ZERO		0

//Enumeration with menu options.
enum enm_options
	{
		opt_bin_srch_delta = V_ONE,
		opt_bin_srch_in_loop,
		opt_bin_srch_recursive,
		opt_fibonacci_search,
		opt_interpolation_srch,
		opt_locate_directly,
		opt_seq_srch_normal,
		opt_view_all_items,
		opt_exit
	} enm_option;

//Global static array of prime numbers.
static const int array[] =	{
					2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
					59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131,
					137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
					227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311,
					313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
					419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
					509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
					617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719,
					727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
					829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
					947, 953, 967, 971, 977, 983, 991, 997
				};

const int *p_array = array,
	*pa_array[] =
		{
			array + 0, array + 1, array + 2, array + 3, array + 4,
			array + 5, array + 6, array + 7, array + 8, array + 9,
			array + 10, array + 11, array + 12, array + 13, array + 14,
			array + 15, array + 16, array + 17, array + 18, array + 19,
			array + 20, array + 21, array + 22, array + 23, array + 24,
			array + 25, array + 26, array + 27, array + 28, array + 29,
			array + 30, array + 31, array + 32, array + 33, array + 34,
			array + 35, array + 36, array + 37, array + 38, array + 39,
			array + 40, array + 41, array + 42, array + 43, array + 44,
			array + 45, array + 46, array + 47, array + 48, array + 49,
			array + 50, array + 51, array + 52, array + 53, array + 54,
			array + 55, array + 56, array + 57, array + 58, array + 59,
			array + 60, array + 61, array + 62, array + 63, array + 64,
			array + 65, array + 66, array + 67, array + 68, array + 69,
			array + 70, array + 71, array + 72, array + 73, array + 74,
			array + 75, array + 76, array + 77, array + 78, array + 79,
			array + 80, array + 81, array + 82, array + 83, array + 84,
			array + 85, array + 86, array + 87, array + 88, array + 89,
			array + 90, array + 91, array + 92, array + 93, array + 94,
			array + 95, array + 96, array + 97, array + 98, array + 99,
			array + 100, array + 101, array + 102, array + 103, array + 104,
			array + 105, array + 106, array + 107, array + 108, array + 109,
			array + 110, array + 111, array + 112, array + 113, array + 114,
			array + 115, array + 116, array + 117, array + 118, array + 119,
			array + 120, array + 121, array + 122, array + 123, array + 124,
			array + 125, array + 126, array + 127, array + 128, array + 129,
			array + 130, array + 131, array + 132, array + 133, array + 134,
			array + 135, array + 136, array + 137, array + 138, array + 139,
			array + 140, array + 141, array + 142, array + 143, array + 144,
			array + 145, array + 146, array + 147, array + 148, array + 149,
			array + 150, array + 151, array + 152, array + 153, array + 154,
			array + 155, array + 156, array + 157, array + 158, array + 159,
			array + 160, array + 161, array + 162, array + 163, array + 164,
			array + 165, array + 166, array + 167,
		};

//Prototype functions.
int BinarySearch(const int array[], const int size, const int target_key, int *pos, int *iters);
int BinarySearchDelta(const int array[], const int size, const int target_key, int *delta_factor, int *pos, int *iters);
int BinarySearchRecursive(const int array[], const int target_key, const int bottom, const int top, int *pos, int *iters, int *itrvs);
int *Fibonacci_Series_Numbers(int max_number, int *qty_items);
int FibonacciSearch(const int array[], const int size, const int target_key, int *pos, int *iters);
int GetElement(const char *str_Message, const int array[], const int size, const int target_key, const int position, const int iterations);
int GetEntry(int *target_key);
char GetResponse(const char *str_Message);
int InterpolationLocate(const int array[], const int bottom, const int top, const int target_key, int *middle_bottom, int *middle_top, int *iters);
int Menu(int *option);
int SelectedOption(int *value);
int SequentialSearch(const int array[], const int start, const int size, const int target_key, int *pos, int *iters);
int ViewAllItems(const int array[], const int position, const int size, const int target_key, int *pos, int *iters);


//Improved traditional binary search function.
int BinarySearch(const int array[], const int size, const int target_key, int *pos, int *iters)
	{
		//Preliminary working variables.
		int high = size + V_MINUS_ONE, low = V_ZERO;

		//Calculate the midpoint position.
		int middle = low + (high - low) / V_TWO;

		//Continue searching as long as there is a valid range.
		for (*iters = V_ZERO; low <= high && array[middle] != target_key; (*iters)++)
			{
				//An adjustment is made to the substitute middle position.
				middle = low + (high - low) / V_TWO;

				//Compare the value at the midpoint with the target.
				if (array[middle] == target_key)
					*pos = middle;			//The number was found. Leaves!
				else if (array[middle] > target_key)
					high = middle + V_MINUS_ONE;	//We adjust the upper limit of the array
				else if (array[middle] < target_key)
					low = middle + V_ONE;		//We adjust the lower limit of the array.
			}

		//The located position of the element is returned as a result.
		return (*pos = (array[middle] == target_key) ? middle : V_MINUS_ONE);
	}

//Improved binary search function with internal delta factor.
int BinarySearchDelta(const int array[], const int size, const int target_key, int *delta_factor, int *pos, int *iters)
	{
		//Preliminary working variables. Calculate the midpoint position.
		int middle = *delta_factor = size / V_TWO;

		//Continue searching as long as there is a valid range.
		for (*iters = V_ZERO; array[middle] != target_key && *delta_factor; (*iters)++, *delta_factor /= V_TWO)
			{
				//Compare the value at the midpoint with the target.
				if (array[middle] == target_key)
					*pos = middle;
				else if (array[middle] > target_key)
					*pos = middle -= MEDIUM(*delta_factor);
				else if (array[middle] < target_key)
					*pos = middle += MEDIUM(*delta_factor);
			}

		//The located position of the element is returned as a result.
		return (*pos = (array[middle] == target_key) ? middle : V_MINUS_ONE);
	}

//Improved traditional recursirve and cyclic binary search function.
int BinarySearchRecursive(const int array[], const int target_key, const int bottom, const int top, int *pos, int *iters, int *itrvs)
	{
		//Preliminary working variables.
		static int iteratives = V_ZERO;
		int middle = (bottom + top) / V_TWO;

		//Calculate the first relative position of the element.
		(*iters)++; iteratives++; *pos = V_MINUS_ONE;

		//Compare the value at the midpoint with the target.
		if ((bottom <= top))
			{
				if (array[middle] == target_key)
					*pos = middle;
				else if (array[middle] > target_key)
					BinarySearchRecursive(array, target_key, bottom, middle - V_ONE, pos, iters, itrvs);
				else if (array[middle] < target_key)
					BinarySearchRecursive(array, target_key, middle + V_ONE, top, pos, iters, itrvs);
			}

		*itrvs = iteratives;
		return *pos;	//The located position of the element is returned as a result.
	}

//Function that generates a Fibonacci number up to the maximum value sent.
int *Fibonacci_Series_Numbers(int max_number, int *qty_items)
	{
		/* Preliminary working variables. */
		int addition_value = V_ZERO, first_value = V_ZERO, second_value = V_ONE;
		int *vector_Fibonacci_Numbers = NULL;

		/* Cycle to count the number of elements whose numbers are below a maximum value. */
		for (*qty_items = V_ZERO; addition_value < max_number; (*qty_items)++)
			{
				addition_value = first_value + second_value;
				first_value = second_value;
				second_value = addition_value;
			}

		/* Condition to create a dynamic array of Fibonacci numbers smaller than the size of the search vector. */
		if ((--(*qty_items) > V_ZERO) && (vector_Fibonacci_Numbers = (int *) malloc(*qty_items * sizeof(int))))
			{
				addition_value = V_ZERO, first_value = V_ZERO, second_value = V_ONE;

				for (int idx = V_ZERO; idx < *qty_items; idx++)
					{
						addition_value = first_value + second_value;
						*(vector_Fibonacci_Numbers + idx) = addition_value;

						first_value = second_value;
						second_value = addition_value;
					}

				printf("\nFibonacci Series Numbers.\n");

				for (int idx = V_ZERO; idx < *qty_items; idx++)
					printf("#: [%2d].\t[%d].\n", idx, vector_Fibonacci_Numbers[idx]);

				printf("[%d] Generated output results.\n", *qty_items);
			}
		else
			perror("There is not enough memory space to accommodate the vector of Fibonacci numbers.");

		return vector_Fibonacci_Numbers;
	}

//Function that searches for an element using Fibonacci numbers.
int FibonacciSearch(const int array[], const int size, const int target_key, int *pos, int *iters)
	{
		/* Preliminary working variables. */
		int adjust = V_ZERO, fibM_minus_two = V_ZERO, fibM_minus_three = V_ZERO, index = V_ZERO, tmp = V_ZERO;
		int qty_items = V_ZERO, *vector_Fibonacci_Numbers = NULL;

		/* Verify the Fibonacci series created. */
		if (vector_Fibonacci_Numbers = Fibonacci_Series_Numbers(size, &qty_items))
			{
				if (qty_items > V_TWO)
					{
						/* Preliminary assignment of starting positions. */
						adjust = (size + V_MINUS_ONE) - vector_Fibonacci_Numbers[qty_items + V_MINUS_ONE];

						index = vector_Fibonacci_Numbers[qty_items + V_MINUS_ONE];
						fibM_minus_two = vector_Fibonacci_Numbers[qty_items - V_TWO];
						fibM_minus_three = vector_Fibonacci_Numbers[qty_items - V_THREE];

						if (target_key > array[index]) index += adjust;	//Fit to size != fib_num.

						/* Work loop to reposition the array index. */
						for (*iters = V_ZERO; (index >= V_ZERO && index < size) && (target_key != array[index]); (*iters)++)
							{
								if (target_key == array[index])
									{
										*pos = index;
									}
								else if (target_key > array[index])
									{
										index += fibM_minus_three;
										fibM_minus_two -= fibM_minus_three;
										fibM_minus_three -= fibM_minus_two;
									}
								else if (target_key < array[index])
									{
										index -= fibM_minus_three;
										tmp = fibM_minus_two;
										fibM_minus_two = fibM_minus_three;
										fibM_minus_three = tmp - fibM_minus_three;
									}
							}
					}
				else
					perror("The number of Fibonacci numbers generated is less than two units.");

				free(vector_Fibonacci_Numbers);
			}
		else
			perror("There is not enough memory space to allocate the vector of Fibonacci series numbers.");

		return (*pos = (index >= V_ZERO && index < size) ? index : V_MINUS_ONE);
	}

//Getting an integer value from the keyboard and purging its input.
int GetElement(const char *str_Message, const int array[], const int size, const int target_key, const int position, const int iterations)
	{
		//Preliminary working variables.
		char stop_key = NULL_CHARACTER;
		int item = V_ZERO;

		//Validates if the position is in a correct range.
		if (position >= V_ZERO && position < size)
			{
				printf("[%s].\n", str_Message);
				printf("+===+====+===+====+===+\n");
				printf("|    Binary Search.   |\n");
				printf("+===+====+===+====+===+\n");
				printf("| * Element  : <%d>.\n", target_key);
				printf("| + Cycles   : {%d}.\n", iterations);
				printf("+-=-+----+---+----+-=-+\n");
				printf("|      Item Info.     |\n");
				printf("+-=-+----+---+----+-=-+\n");
				printf("| * Maximum  : [%d].\n", size + V_MINUS_ONE);
				printf("+ --=----=---=----=-- +\n");
				printf("| * Position : [%d].\n", position);
				printf("| * Content  : [%d].\n", array[position]);
				printf("+===+====+===+====+===+\n");

				stop_key = GetResponse("Press the ENTER key to continue...");
				item = array[position];
			}
		else
			printf("\nThe searched value: [%d] was not found in array.\n", target_key);

		return item;
	}

//Get a correct integer value.
int GetEntry(int *target_key)
	{
		//Preliminary working variables.
		char c = NULL_CHARACTER;
		int value_key = V_ZERO;

		//Validate data entry as correct.
		if (scanf("%d%*c", &value_key) == V_ONE)
			{
				//Get a correct integer value.
				printf("\nInput value: [%d]. OK!\n", value_key);
				*target_key = value_key;
			}
		else
			{
				//Get an incorrect integer value.
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}

		return value_key;
	}

//Make a pause or obtain a given response.
char GetResponse(const char *str_Message)
	{
		//Preliminary working variables.
		char c = NULL_CHARACTER;
		char chr_key = V_ZERO;

		printf("%s", str_Message);

		//Validate data entry as correct.
		if (scanf("%c%*c", &chr_key) == V_ONE)
			//Get a correct character value.
			printf("\nInput value: [%x] : [%d] = [%c]. OK!\n", chr_key, chr_key, chr_key);
		else
			{
				//Get an incorrect character value.
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			};

		return chr_key;
	}

//Function to locate a certain value by means of interpolations.
int InterpolationLocate(const int array[], const int bottom, const int top, const int target_key, int *middle_bottom, int *middle_top, int *iters)
	{
		//Preliminary working variables.
		*iters = V_ZERO;
		*middle_top = top + ((target_key - array[top]) * (bottom - top)) / (array[bottom] - array[top]);
		*middle_bottom = bottom + ((target_key - array[bottom]) * (top - bottom)) / (array[top] - array[bottom]);

		//The located position of the element is returned as a result.
		return (*middle_top >= bottom && *middle_top <= top) && (*middle_bottom >= bottom && *middle_bottom <= top);
	}

//Options menu.
int Menu(int *option)
	{
		int value = V_ZERO;

		while (value != opt_exit)
			{
				printf("\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("|    Binary search services.   |\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("| [1]. Binary delta search.    |\n");
				printf("| [2]. Binary search in loop.  |\n");
				printf("| [3]. Binary search recursive.|\n");
				printf("| [4]. Fibonacci search.       |\n");
				printf("| [5]. Interpolation search.   |\n");
				printf("| [6]. Locate directly.        |\n");
				printf("| [7]. Sequential search.      |\n");
				printf("| [8]. View all items details. |\n");
				printf("| [9]. Exit this program.      |\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("Choose an option: ");

				*option = value = GetEntry(&value);
				*option = value = SelectedOption(&value);
			}

		return value;
	}

//Function to execute a function given an option.
int SelectedOption(int *value)
	{
		//Preliminary working variables.
		int delta_factor = V_ZERO;	//Delta factor that adjusts the position of the medium.
		int iterations = V_ZERO, iteratives = V_ZERO;		//Number of iterations performed.
		int middle_bottom = V_ZERO, middle_top = V_ZERO;	//Positions for interpolations.
		int position = V_ZERO, starting_pos = V_ZERO;		//Location position of the located element.
		int size = sizeof(array) / sizeof(array[V_ZERO]);	//Calculated array size.
		int target_key = V_ZERO;	//Numeric search key.

		//Presentation and indication headers.
		if (*value >= opt_bin_srch_delta && *value < opt_exit)
			{
				printf("\nSearch for a prime number within the first thousand.\n");
				printf("Prime number to find: ");
				target_key = GetEntry(&target_key);
			}

		//Convert integer value to enumerated value.
		enm_option = (enum enm_options) *value;

		//Selection of cases with the enumerated value obtained.
		switch (enm_option)
			{
				//We call the binary search function with a delta factor.
				case opt_bin_srch_delta:
					position = BinarySearchDelta(array, size, target_key, &delta_factor, &position, &iterations);
					GetElement("Binary delta search", array, size, target_key, position, iterations);
					printf("  * Delta Fx : [%d].\n", delta_factor);
					GetResponse("Press the ENTER key to continue...");
					break;

				//We call the traditional binary search function.
				case opt_bin_srch_in_loop:
					position = BinarySearch(array, size, target_key, &position, &iterations);
					GetElement("Binary search in loop", array, size, target_key, position, iterations);
					GetResponse("Press the ENTER key to continue...");
					break;

				//We call the traditional recursive and cyclic binary search function.
				case opt_bin_srch_recursive:
					iterations = V_ZERO;
					position = BinarySearchRecursive(array, target_key, V_ZERO, size + V_MINUS_ONE, &position, &iterations, &iteratives);
					GetElement("Binary search recursive", array, size, target_key, position, iterations);
					printf("[%d] calls made to the recursive binary search function.\n", iteratives);
					GetResponse("Press the ENTER key to continue...");
					break;

				//We perform the search function by Fibonacci numbers.
				case opt_fibonacci_search:
					position = FibonacciSearch(array, size, target_key, &position, &iterations);

					if (position >= V_ZERO && position <= size + V_MINUS_ONE)
						{
							GetElement("Fibonacci search", array, size, target_key, position, iterations);
							printf("Fenced element at position: [%d] located with content: [%d].\n", position, array[position]);
						}
					else
						{
							printf("\nElement: [%d] not found!\n", target_key);
							printf("Highest position achieved: [%d].\n", position);
						}

					GetResponse("Press the ENTER key to continue...");
					break;

				//We call a function that obtains the position of the searched element by means of interpolations.
				case opt_interpolation_srch:
					if (InterpolationLocate(array, V_ZERO, size - V_ONE, target_key, &middle_bottom, &middle_top, &iterations))
						{
							printf("\n** [Approximate values ​​obtained] **.\n");
							GetElement("Interpolation search: lower value obtained", array, size, target_key, middle_bottom, iterations);
							GetElement("Interpolation search: upper value obtained", array, size, target_key, middle_top, iterations);
							GetResponse("Press the ENTER key to continue...");
						}
					break;

				//We locate an entry or occurrence of the array directly by means of an index number.
				case opt_locate_directly:
					printf("\nEntry or occurrence number to be located.\n");
					printf("Index position from: [%d] to [%d]: ", V_ZERO, size + V_MINUS_ONE);
					starting_pos = GetEntry(&starting_pos);

					printf("\nIndex position: [%d] of [%d].\n", starting_pos, size + V_MINUS_ONE);

					if (starting_pos >= V_ZERO && starting_pos <= size + V_MINUS_ONE)
						{
							iterations = V_ZERO;
							GetElement("Locate directly", array, size, target_key, starting_pos, iterations);
							printf("\nElement found: [%d] ubicated directly on position: [%d].\n", array[starting_pos], starting_pos);
							printf("Item searched: [%d].\n", target_key);
							printf("Match result : [%s].\n", (array[starting_pos] == target_key) ? "The located and sought values ​​are equal" : "The types do not match");
						}
					else
						printf("The position index: [%d] is out of bounds between: [%d] and [%d].\n", starting_pos, V_ZERO, size + V_MINUS_ONE);

					GetResponse("Press the ENTER key to continue...");
					break;

				//We call a function that sequentially searches for a value until it finds it.
				case opt_seq_srch_normal:
					printf("Starting position from: [%d] to [%d]: ", V_ZERO, size + V_MINUS_ONE);
					starting_pos = GetEntry(&starting_pos);

					printf("\nStarting position captured: [%d] of [%d].\n", starting_pos, size + V_MINUS_ONE);

					if (starting_pos >= V_ZERO && starting_pos <= size + V_MINUS_ONE)
						{
							position = SequentialSearch(array, starting_pos, size, target_key, &position, &iterations);

							if (position >= V_ZERO && position <= size + V_MINUS_ONE)
								{
									GetElement("Sequential search", array, size, target_key, position, iterations);
									printf("Fenced element at position: [%d] located with content: [%d].\n", position, array[position]);
								}
							else
								{
									printf("\nElement: [%d] not found!\n", target_key);
									printf("Highest position achieved: [%d].\n", position);
								}
						}
					else
						printf("The start index: [%d] is out of bounds between: [%d] and [%d].\n", starting_pos, V_ZERO, size + V_MINUS_ONE);

					GetResponse("Press the ENTER key to continue...");
					break;

				//See all the details of the record to be consulted.
				case opt_view_all_items:
					printf("Starting position from: [%d] to [%d]: ", V_ZERO, size + V_MINUS_ONE);
					starting_pos = GetEntry(&starting_pos);

					printf("\nStarting position captured: [%d] of [%d].\n", starting_pos, size + V_MINUS_ONE);

					if (starting_pos >= V_ZERO && starting_pos <= size + V_MINUS_ONE)
						{
							iterations = V_ZERO;
							position = ViewAllItems(array, starting_pos, size, target_key, &position, &iterations);

							if (position >= V_ZERO && position <= size + V_MINUS_ONE)
								{
									GetElement("View all items details", array, size, target_key, position, iterations);
									printf("Fenced element at position: [%d] located with content: [%d].\n", position, array[position]);
								}
							else
								{
									printf("\nElement: [%d] not found!\n", target_key);
									printf("Highest position achieved: [%d].\n", position);
								}

							printf("Item searched: [%d].\n", target_key);
							printf("Match result : [%s].\n", (array[position] == target_key) ? "The located and sought values ​​are equal" : "The types do not match");
							printf("Scanned: [%d] records to find the value: [%d].\n", iterations, target_key);
						}
					else
						printf("The position index: [%d] is out of bounds between: [%d] and [%d].\n", starting_pos, V_ZERO, size + V_MINUS_ONE);

					GetResponse("Press the ENTER key to continue...");
					break;

				//Program exit case.
				case opt_exit:
					printf("\nLeaving this program...\n");
					break;

				//Case of failed option.
				default:
					printf("The selected option: [%d] is not valid.\n", *value);
					break;
			}

		return *value;
	}

//Sequential search function given a start position.
int SequentialSearch(const int array[], const int start, const int size, const int target_key, int *pos, int *iters)
	{
		int idx = V_ZERO;

		for (*iters = V_ZERO, idx = start; idx < size && array[idx] < target_key; idx++, (*iters)++);

		return(*pos = (array[idx] == target_key) ? idx : V_MINUS_ONE);
	}

//Function that sees all the details of the record to be consulted.
int ViewAllItems(const int array[], const int position, const int size, const int target_key, int *pos, int *iters)
	{
		char chr_key = V_CHR_UPPER_Y;
		int idx = V_ZERO;

		printf("\nPointer naming practice.\n");

		for (idx = position; idx < size && array[idx] <= target_key && (chr_key == V_CHR_LOWER_Y || chr_key == V_CHR_UPPER_Y); idx++, (*iters)++)
			{
				printf("\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("|   Retrieved record information.   |\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("| Index position #: [%d] of: [%d].\n", idx, size - V_ONE);
				printf("| Position content: [%d].\n", array[idx]);
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Addresses:\n");
				printf("| * array    : {%p}.\n", &array);
				printf("|              {%p} : [%p] = [%p].\n", array, &array[idx], array + idx);
				printf("|\n");
				printf("| * p_array  : {%p}.\n", &p_array);
				printf("|              [%p] : [%p] = [%p].\n", p_array, &p_array[idx], p_array + idx);
				printf("|\n");
				printf("| * pa_array : {%p}.\n", &pa_array);
				printf("|              {%p} : [%p] = [%p].\n", pa_array, &pa_array[idx], pa_array + idx);
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Values:\n");
				printf("| + array    : {%d}.\n", *array);
				printf("|              [%d] = [%d].\n", array[idx], *(array + idx));
				printf("|\n");
				printf("| + p_array  : {%d}.\n", *p_array);
				printf("|              [%d] = [%d].\n", p_array[idx], *(p_array + idx));
				printf("|\n");
				printf("| + pa_array : {%p} : {%d}.\n", *pa_array, **pa_array);
				printf("|              [%p] = [%p].\n", pa_array[idx], *(pa_array + idx));
				printf("|              [%d] : [%d].\n", *pa_array[idx], *(*(pa_array + idx)));
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("\n");

				if (array[idx] == target_key) printf ("** Element: [%d] = [%d] located in position: [%d]. **\n", target_key, array[idx], idx);

				chr_key = GetResponse("Do you want to continue viewing more records (y/n)? : ");
			}

		return(*pos = (idx > position && idx <= size) ? --idx : idx);
	}

//Main function.
int main()
	{
		int option = Menu(&option);

		return V_ZERO;
	}
