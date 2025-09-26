/* Program that performs binary searches with cycles
   in the traditional way as well as with a 'delta' factor and other modalities. */

//Standard work libraries.
#include <stdio.h>
#include <stdlib.h>

/* Random number generator. */
#define RANDOM_GENERATOR(s)	(((V_MULTIPLIER) * (s) + (V_INCREMENTER)) % (V_MODULUS))
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

//Macro for partitioning a binary delta search.
#define	MEDIUM(x)		(((x) + V_ONE) / V_TWO)

//Symbolic constants of working characters.
#define	CARRIAGE_RETURN		'\n'
#define	NULL_CHARACTER		'\0'
#define	V_CHR_LOWER_Y		0x79
#define	V_CHR_UPPER_Y		0x59

//Symbolic work constants.
#define	V_MINUS_ONE		-1
#define	V_ONE_HUNDRED		100
#define	V_TEN			10
#define	V_THREE			3
#define	V_TWO			2
#define	V_ONE			1
#define	V_ZERO			0

//Enumeration with menu options.
enum enm_options
	{
		enm_opt_binary_search = V_ONE,
		enm_opt_binary_search_delta,
		enm_opt_binary_search_recursive,
		enm_opt_dump_all_items,
		enm_opt_fibonacci_search,
		enm_opt_interpolation_search,
		enm_opt_locate_directly,
		enm_opt_random_seeking,
		enm_opt_sequential_search,
		enm_opt_sequential_search_recursive,
		enm_opt_view_all_items,
		enm_opt_view_each_element,
		enm_opt_view_statistics,
		enm_opt_exit_this_program
	} enm_option;

//Enumeration with type entry variables and its reseting.
enum enm_type_entry
	{
		enm_type_entry_char,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short
	} enm_type_value;

//Enumeration for memory area reset system.
enum enm_type_reset
	{
		enm_type_reset_NO,
		enm_type_reset_YES
	} enm_type_reset_OK;

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
					829, 839, 853, 857, 859, 863, 869, 877, 881, 883, 889, 907, 911, 919, 929, 937,
					941, 947, 953, 967, 971, 977, 983, 991, 997
				};

const int size_of_array = sizeof(array) / sizeof(*array);	//Overall determination of the fixed array size.

//Array of pointers pointing to the main global array.
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
			array + 165, array + 166, array + 167, array + 168
		};

//Prototype functions.
int BinarySearch(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters);
int BinarySearchDelta(const int array[], const int start, const int finish, const int target_key, int *delta_factor, int *pos, int *iters);
int BinarySearchRecursive(const int array[], const int bottom, const int top, const int target_key, int *pos, int *iters, int *itrvs);
int DumpAllItems(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters);
int *Fibonacci_Series_Numbers(const int max_number, int *qty_items, int **Fibo_Series_Nums);
int FibonacciSearch(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters);
int GetElement(const char *str_Message, const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, const int size, const int position, const int calls, const int iterations, const int iters, const int random_seed);
int GetItem(const char *str_Message, const int array[], const int start, const int finish, const int target_key, const int position, const int iterations);
void *GetEntry(const char *str_Message, void *void_var_address, enum enm_type_entry enm_type_value, enum enm_type_reset enm_type_reset_OK);
int GetRandomInterval(const int start, const int finish, int *random_seed);
double GetRandomNumber(int *random_seed);
int GetValidInputs(int *start, int *finish, int *target_key, int *bottom, int *top);
int GetValidLimits(const int position, int *start, int *finish);
int InterpolationLocate(const int array[], const int bottom, const int top, const int target_key, int *middle_bottom, int *middle_top, int *iters);
int MainMenu(int *option);
int SelectedOptionMainMenu(int *start, int *finish, int *target_key, int *calls, int *iter, int *iters, int *position, int *random_seed, int *value);
int SequentialSearch(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters);
int SequentialSearchRecursive(const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, int *pos, int *iters);
void SwapValues(int *left_value, int *right_value);
void SwappingLimits(const char *str_Message, int *bottom, int *top);
int ViewAllItems(const int array[], const int start, const int finish, const int target_key, int *pos, int *iter, int *iters);
int ViewEachElement(const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, const int size, int *pos, const int calls, int *iter, int *iters, const int random_seed);
int ViewRandomInterval(const int start, const int finish, const int position, int *random_seed);


//Improved traditional binary search function.
int BinarySearch(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters)
	{
		//Preliminary working variables.
		int high = finish, low = start;

		//Calculate the midpoint position.
		int middle = low + (high - low) / V_TWO;

		//Continue searching as long as there is a valid range.
		for (; low <= high && array[middle] != target_key; (*iters)++)
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
int BinarySearchDelta(const int array[], const int start, const int finish, const int target_key, int *delta_factor, int *pos, int *iters)
	{
		//Preliminary working variables. Calculate the midpoint position.
		int middle = start + (finish - start) / V_TWO;

		//Continue searching as long as there is a valid range.
		for (*delta_factor = (finish - start); array[middle] != target_key && *delta_factor; (*iters)++, *delta_factor /= V_TWO)
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
int BinarySearchRecursive(const int array[], const int bottom, const int top, const int target_key, int *pos, int *iters, int *itrvs)
	{
		//Preliminary working variables.
		static int iteratives = V_ZERO;
		int middle = (bottom + top) / V_TWO;	//Calculate the midpoint position.

		//Calculate the first relative position of the element.
		(*iters)++; iteratives++; *pos = V_MINUS_ONE;

		//Compare the value at the midpoint with the target.
		if ((bottom <= top))
			{
				if (array[middle] == target_key)
					*pos = middle;
				else if (array[middle] > target_key)
					BinarySearchRecursive(array, bottom, middle - V_ONE, target_key, pos, iters, itrvs);
				else if (array[middle] < target_key)
					BinarySearchRecursive(array, middle + V_ONE, top, target_key, pos, iters, itrvs);
			}

		*itrvs = iteratives;
		return *pos;	//The located position of the element is returned as a result.
	}

//Dump all elements of the array.
int DumpAllItems(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters)
	{
		/* Preliminary working variables. */
		char char_key = V_ZERO;
		int item_pos = V_MINUS_ONE;

		/* Display of each of the elements of the array. */
		printf("\nDump all elements of the array from [%d] to [%d].\n", start, finish);

		for (int idx = start; idx <= finish; idx++, (*iters)++)
			{
				printf("#[%3.d] = [%3.d].\t", idx, array[idx]);

				if (array[idx] == target_key) item_pos = idx;
			}

		printf("\n");

		/* If the item has been located in the full crawl, indicate that the item was located. */
		if (item_pos >= start && item_pos <= finish) printf ("** Element: [%d] = [%d] located in position: [%d]. **\n", target_key, array[item_pos], item_pos);

		char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));

		return(*pos = item_pos);
	}

//Function that generates a Fibonacci number up to the maximum value sent.
int *Fibonacci_Series_Numbers(const int max_number, int *qty_items, int **Fibo_Series_Nums)
	{
		/* Preliminary working variables. */
		char char_key = V_ZERO;
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

				char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
			}
		else
			perror("There is not enough memory space to accommodate the vector of Fibonacci numbers.");

		/* Assigning a valid memory address to the created vector. */
		if (Fibo_Series_Nums) *Fibo_Series_Nums = vector_Fibonacci_Numbers;

		return vector_Fibonacci_Numbers;
	}

//Function that searches for an element using Fibonacci numbers.
int FibonacciSearch(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters)
	{
		/* Preliminary working variables. */
		int adjust = V_ZERO, fibM_minus_two = V_ZERO, fibM_minus_three = V_ZERO, index = V_ZERO, tmp = V_ZERO;
		int qty_items = V_ZERO, size = start + (finish - start) + V_ONE, *vector_Fibonacci_Numbers = NULL;

		/* Verify the Fibonacci series created. */
		if ((vector_Fibonacci_Numbers = Fibonacci_Series_Numbers(size, &qty_items, &vector_Fibonacci_Numbers)))
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
						for (; (index >= V_ZERO && index < size) && (target_key != array[index]); (*iters)++)
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
					perror("The number of Fibonacci numbers generated is less than three units.");

				free(vector_Fibonacci_Numbers);
			}
		else
			perror("There is not enough memory space to allocate the vector of Fibonacci series numbers.");

		return (*pos = (index >= V_ZERO && index < size) ? index : V_MINUS_ONE);
	}

//Getting an integer value from the keyboard and purging its input.
int GetElement(const char *str_Message, const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, const int size, const int position, const int calls, const int iterations, const int iters, const int random_seed)
	{
		//Preliminary working variables.
		char char_key = NULL_CHARACTER;
		int item = V_ZERO;

		//Validates if the position is in a correct range.
		if (position >= start && position <= finish)
			{
				printf("\n[%s].\n", str_Message);
				printf("+===+====+===+====+===+\n");
				printf("| Binary Search Duty. |\n");
				printf("+===+====+===+====+===+\n");
				printf("|  Position changes.  |\n");
				printf("+ --=----=---=----=-- +\n");
				printf("| + Calls    : [%d].\n", calls);
				printf("| + Cycles   : [%d].\n", iterations);
				printf("| + Spins    : [%d].\n", iters);
				printf("+ --=----=---=----=-- +\n");
				printf("| * Element  : <%d>.\n", target_key);
				printf("| ^ Items    : (%d).\n", size);
				printf("+-=-+----+---+----+-=-+\n");
				printf("| Bounds Information. |\n");
				printf("+-=-+----+---+----+-=-+\n");
				printf("| - Minimum  : [%d].\n", bottom);
				printf("| + Maximum  : [%d].\n", top);
				printf("+-=-+----+---+----+-=-+\n");
				printf("| Fetched Range Info. |\n");
				printf("+-=-+----+---+----+-=-+\n");
				printf("| < Start    : [%d].\n", start);
				printf("| > Finish   : [%d].\n", finish);
				printf("+ --=----=---=----=-- +\n");
				printf("| * Seed     : [%d].\n", random_seed);
				printf("+-=-+----+---+----+-=-+\n");
				printf("| Sought Information. |\n");
				printf("+ --=----=---=----=-- +\n");
				printf("| * Address  : [%p].\n", array + position);
				printf("| * Content  : [%d].\n", array[position]);
				printf("| * Position : [%d].\n", position);
				printf("| * Size     : [%ld].\n", sizeof(*(array + position)));
				printf("+===|====+===|====+===|\n");

				item = *(array + position);
			}
		else
			printf("\nThe searched value: [%d] was not found in array on the boundaries between: [%d] = {%d} and [%d] = {%d}.\n", target_key, start, array[start], finish, array[finish]);

		char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));

		return item;
	}

//Obtains more succinct information about the queried item.
int GetItem(const char *str_Message, const int array[], const int start, const int finish, const int target_key, const int position, const int iterations)
	{
		//Preliminary working variables.
		char char_key = NULL_CHARACTER;
		int item = V_ZERO;

		//Validates if the position is in a correct range.
		if (position >= start && position <= finish)
			{
				printf("\n[%s].\n", str_Message);
				printf("+---+----+---+----+---+\n");
				printf("|  Item Information.  |\n");
				printf("+---+----+---+----+---+\n");
				printf("| Loops    : {%d}.\n", iterations);
				printf("| Searched : <%d>.\n", target_key);
				printf("+---------------------+\n");
				printf("|   Scanned Records.  |\n");
				printf("+---------------------+\n");
				printf("| Found    : [%d].\n", array[position]);
				printf("| Position : [%d].\n", position);
				printf("+---------------------+\n");
				printf("|   Matching Result.  |\n");
				printf("+---------------------+\n");
				printf("| [%s].\n", (*(array + position) == target_key) ? "The located and sought values ​​are equal" : "The types do not match");
				printf("+---+----+---+----+---+\n");

				item = array[position];
			}
		else
			printf("\nThe searched value: [%d] was not found in array on the boundaries between: [%d] = {%d} and [%d] = {%d}.\n", target_key, start, array[start], finish, array[finish]);

		char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));

		return item;
	}

//Function that gets a correct type value depending on its option.
void *GetEntry(const char *str_Message, void *void_var_address, enum enm_type_entry enm_type_data, enum enm_type_reset enm_type_reset_OK)
	{
		//Preliminary working variables.
		char c = NULL_CHARACTER, *buffer = NULL;
		int count_bytes = V_ZERO, number_arguments = V_ZERO, number_elements = V_ONE_HUNDRED;
		int option_type_entry = (int) enm_type_data;

		/* Structure with the type of the returned variable. */
		struct s_input_type_format
			{
				char *type_variable;
				char *format_variable;
			}
			s_input_types_formats[] =
				{{"char", "%c%n"}, {"double", "%lf%n"}, {"float", "%f%n"},
				 {"int", "%d%n"}, {"long", "%ld%n"}, {"short", "%hi%n"}};

		/* Validate if the obtained memory addresses are valid. */
		if (void_var_address)
			{
				if ((buffer = (char *) calloc(number_elements, sizeof(char))))
					{
						/* Incoming message. */
						printf("%s", str_Message);
						scanf("%[^\n]", buffer);

						/* Selection of validating case of the type of variable to generate. */
						switch(enm_type_data)
							{
								//Get a correct character value.
								case enm_type_entry_char:
									if ((number_arguments = sscanf(buffer, s_input_types_formats[option_type_entry].format_variable, (char *) void_var_address, &count_bytes)) == V_ONE)
										printf("\nOption: [%d]. Type: [%s]. Bytes: [%d]. Size: [%ld]. Memory address: [%p]. Input value: [%x] : [%d] = [%c]. OK!\n", option_type_entry, s_input_types_formats[option_type_entry].type_variable, count_bytes, sizeof(char), (char *) void_var_address, *((char *) void_var_address), *((char *) void_var_address), *((char *) void_var_address));
									break;

								//Get a correct double value.
								case enm_type_entry_double:
									if ((number_arguments = sscanf(buffer, s_input_types_formats[option_type_entry].format_variable, (double *) void_var_address, &count_bytes)) == V_ONE)
										printf("\nOption: [%d]. Type: [%s]. Bytes: [%d]. Size: [%ld]. Memory address: [%p]. Input value: [%lf]. OK!\n", option_type_entry, s_input_types_formats[option_type_entry].type_variable, count_bytes, sizeof(double), (double *) void_var_address, *((double *) void_var_address));
									break;

								//Get a correct float value.
								case enm_type_entry_float:
									if ((number_arguments = sscanf(buffer, s_input_types_formats[option_type_entry].format_variable, (float *) void_var_address, &count_bytes)) == V_ONE)
										printf("\nOption: [%d]. Type: [%s]. Bytes: [%d]. Size: [%ld]. Memory address: [%p]. Input value: [%f]. OK!\n", option_type_entry, s_input_types_formats[option_type_entry].type_variable, count_bytes, sizeof(float), (float *) void_var_address, *((float *) void_var_address));
									break;

								//Get a correct integer value.
								case enm_type_entry_int:
									if ((number_arguments = sscanf(buffer, s_input_types_formats[option_type_entry].format_variable, (int *) void_var_address, &count_bytes)) == V_ONE)
										printf("\nOption: [%d]. Type: [%s]. Bytes: [%d]. Size: [%ld]. Memory address: [%p]. Input value: [%d]. OK!\n", option_type_entry, s_input_types_formats[option_type_entry].type_variable, count_bytes, sizeof(int), (int *) void_var_address, *((int *) void_var_address));
									break;

								//Get a correct long value.
								case enm_type_entry_long:
									if ((number_arguments = sscanf(buffer, s_input_types_formats[option_type_entry].format_variable, (long *) void_var_address, &count_bytes)) == V_ONE)
										printf("\nOption: [%d]. Type: [%s]. Bytes: [%d]. Size: [%ld]. Memory address: [%p]. Input value: [%ld]. OK!\n", option_type_entry, s_input_types_formats[option_type_entry].type_variable, count_bytes, sizeof(long), (long *) void_var_address, *((long *) void_var_address));
									break;

								//Get a correct short value.
								case enm_type_entry_short:
									if ((number_arguments = sscanf(buffer, s_input_types_formats[option_type_entry].format_variable, (short *) void_var_address, &count_bytes)) == V_ONE)
										printf("\nOption: [%d]. Type: [%s]. Bytes: [%d]. Size: [%ld]. Memory address: [%p]. Input value: [%hi]. OK!\n", option_type_entry, s_input_types_formats[option_type_entry].type_variable, count_bytes, sizeof(short), (short *) void_var_address, *((short *) void_var_address));
									break;

								//Option no valid.
								default:
									printf("The selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
									break;
							}

							//Get an incorrect value.
							if (number_arguments != V_ONE)
								{
									if (feof(stdin))
										{
											printf("\nEnd of File (EOF) detected in data entry.\n");
											clearerr(stdin);
											fflush(stdin);
										}
									else
										{
											printf("\nThe value entered is not valid. Trying again!\n");
											scanf("%*[^\n]%*c");
											while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
										}

									/* Initialize the specified memory area. */
									if (enm_type_reset_OK == enm_type_reset_YES)
										{
											printf("The value at memory address: [%p] is going to be reset.\n", void_var_address);

											switch(enm_type_data)
												{
													case enm_type_entry_char:
														*((char *) void_var_address) = V_ZERO;
														break;

													case enm_type_entry_double:
														*((double *) void_var_address) = V_ZERO;
														break;

													case enm_type_entry_float:
														*((float *) void_var_address) = V_ZERO;
														break;

													case enm_type_entry_int:
														*((int *) void_var_address) = V_ZERO;
														break;

													case enm_type_entry_long:
														*((long *) void_var_address) = V_ZERO;
														break;

													case enm_type_entry_short:
														*((short *) void_var_address) = V_ZERO;
														break;

													default:
														printf("The value of memory address: [%p] was not altered.\n", void_var_address);
														break;
												}
										}
								}

						/* We must always clear the input buffer of impurities. */
						printf("Address: [%p] = {%s}. Clearing buffer...\n", buffer, buffer);
						while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);

						free(buffer);
					}
				else
					perror("An error occurred while allocating memory for the character string.");
			}
		else
			fprintf(stderr, "The memory address to hold the variable is not valid.\n");

		return void_var_address;
	}

//Function that obtains a random number within a range.
int GetRandomInterval(const int start, const int finish, int *random_seed)
	{
		return ((int) ((finish - start + V_ONE) * GetRandomNumber(random_seed) + start));
	}

//Function that generates a single-precision floating-point random number between zero and one.
double GetRandomNumber(int *random_seed)
	{
		return ((double) (*random_seed = RANDOM_GENERATOR(*random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

//Valid entries for the initial and final search indexes, as well as the value to be searched for, are obtained.
int GetValidInputs(int *start, int *finish, int *target_key, int *bottom, int *top)
	{
		/* Preliminary working variables. */
		char char_key = NULL_CHARACTER;

		/* Prior request for data for searches. */
		printf("\nRequest for input data...\n");

		/* Request for the input value for the start position. */
		printf("Starting position from: [%d] to [%d]: ", *bottom, *top);
		*start = *((int *) GetEntry("", start, enm_type_entry_int, enm_type_reset_YES));
		printf("Starting position captured: [%d] between [%d] and [%d].\n", *start, *bottom, *top);

		/* Key validation to determine if the starting value is within the indicated ranges. */
		if (GetValidLimits(*start, bottom, top))
			{
				/* Request for the input value for the finish position. */
				printf("Finishing position from: [%d] to [%d]: ", *bottom, *top);
				*finish = *((int *) GetEntry("", finish, enm_type_entry_int, enm_type_reset_YES));
				printf("Finishing position captured: [%d] between [%d] and [%d].\n", *finish, *bottom, *top);

				/* Key validation to determine if the finishing value is within the indicated ranges. */
				if (GetValidLimits(*finish, bottom, top))
					{
						/* Validate if the begin and end values ​​are inverted. */
						SwappingLimits("Get Valid Inputs", start, finish);

						/* Ask for the number you want to search for in the array. */
						printf("\nSearch for a prime number within the first thousand.\n");
						printf("Prime number to find: ");
						*target_key = *((int *) GetEntry("", target_key, enm_type_entry_int, enm_type_reset_YES));
					}
			}

		char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));

		return ((*start >= *bottom && *start <= *top) && (*finish >= *bottom && *finish <= *top) && (target_key));
	}

//Limits validation for the given position.
int GetValidLimits(const int position, int *start, int *finish)
	{
		/* Preliminary working variables. */
		char char_key = NULL_CHARACTER;

		/* Header message. */
		printf("\nVerifying that a value is within a range...\n");

		/* Validate if the begin and end values ​​are inverted. */
		SwappingLimits("Get Valid Limits", start, finish);

		/* If the limits are incorrect, exchange them again. */
		printf("Tinnier value: [%d]. Bigger value: [%d]. OK!\n", *start, *finish);

		/* Correctly validate that the value is within the range sent. */
		if (position >= *start && position <= *finish)
			printf("Position: [%d]. OK! Range from: [%d] to [%d].\n", position, *start, *finish);
		else
			printf("Position: [%d]. Fail! Out of range between: [%d] and [%d].\n", position, *start, *finish);

		char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));

		return (position >= *start && position <= *finish);
	}

//Function to locate a certain value by means of interpolations.
int InterpolationLocate(const int array[], const int bottom, const int top, const int target_key, int *middle_bottom, int *middle_top, int *iters)
	{
		/* Preliminary working variables. */
		*middle_top = top + ((target_key - array[top]) * (bottom - top)) / (array[bottom] - array[top] + V_ONE);
		*middle_bottom = bottom + ((target_key - array[bottom]) * (top - bottom)) / (array[top] - array[bottom] + V_ONE);

		//The located position of the element is returned as a result.
		return (*middle_top >= bottom && *middle_top <= top) && (*middle_bottom >= bottom && *middle_bottom <= top);
	}

//Options menu.
int MainMenu(int *option)
	{
		/* Preliminary working variables. */
		int finish = V_ZERO, start = V_ZERO, target_key = V_ZERO;
		int calls = V_ZERO, iter = V_ZERO, iters = V_ZERO, position = V_ZERO, random_seed = V_ZERO, value = V_ZERO;

		/* Combined cycle from the main options menu. */
		while (value != enm_opt_exit_this_program)
			{
				printf("\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("|       Binary search services.     |\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("| [01]. Binary search.              |\n");
				printf("| [02]. Binary search with delta.   |\n");
				printf("| [03]. Binary search recursive.    |\n");
				printf("| [04]. Dump all items.             |\n");
				printf("| [05]. Fibonacci search.           |\n");
				printf("| [06]. Interpolation search.       |\n");
				printf("| [07]. Locate directly.            |\n");
				printf("| [08]. Random seeking.             |\n");
				printf("| [09]. Sequential search.          |\n");
				printf("| [10]. Sequential search recursive.|\n");
				printf("| [11]. View all items details.     |\n");
				printf("| [12]. View each element.          |\n");
				printf("| [13]. View statistics.            |\n");
				printf("| [14]. Exit this program.          |\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("Choose an option: ");

				*option = value = *((int *) GetEntry("", &value, enm_type_entry_int, enm_type_reset_YES));
				*option = value = SelectedOptionMainMenu(&start, &finish, &target_key, &calls, &iter, &iters, &position, &random_seed, &value);
			}

		return value;
	}

//Function to execute a function given an option.
int SelectedOptionMainMenu(int *start, int *finish, int *target_key, int *calls, int *iter, int *iters, int *position, int *random_seed, int *value)
	{
		/* Preliminary working variables. */
		char char_key = NULL_CHARACTER;				//Variable to obtain a pause character.
		int delta_factor = V_ZERO;				//Delta factor that adjusts the position of the medium.
		int iteratives = V_ZERO;				//Number of iterations performed.
		int middle_bottom = V_ZERO, middle_top = V_ZERO;	//Positions for interpolations.
		int bottom = V_ZERO, top = size_of_array + V_MINUS_ONE;	//Lower and upper bounds of the array.
		int size = size_of_array;				//Calculated array size.

		/* Convert integer value to enumerated value. */
		enm_option = (enum enm_options) *value;
		if (enm_option >= enm_opt_binary_search && enm_option <= enm_opt_view_each_element)
			{
				(*calls)++;
				*iter = V_ZERO;
			}

		printf("\nThe selected option was: [%d].\n", *value);

		/* Selection of cases with the enumerated value obtained. */
		switch (enm_option)
			{
				/* We call the traditional binary search function. */
				case enm_opt_binary_search:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = BinarySearch(array, *start, *finish, *target_key, position, iter);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Binary search", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Tracked element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Binary search].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Binary search", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* We call the binary search function with a 'delta' factor. */
				case enm_opt_binary_search_delta:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = BinarySearchDelta(array, *start, *finish, *target_key, &delta_factor, position, iter);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Binary search with delta", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("  * Delta Fx : [%d].\n", delta_factor);
									printf("Fetched element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Binary search with delta].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Binary search with delta", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* We call the traditional recursive and cyclic binary search function. */
				case enm_opt_binary_search_recursive:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = BinarySearchRecursive(array, *start, *finish, *target_key, position, iter, &iteratives);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Binary search recursive", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("[%d] calls made to the recursive binary search function.\n", iteratives);
									printf("Sought element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Binary search recursive].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Binary search recursive", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* We dump all elements of the array. */
				case enm_opt_dump_all_items:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = DumpAllItems(array, *start, *finish, *target_key, position, iter);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Dump all items", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Looked element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Dump all items].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Dump all items", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* Program exit case. */
				case enm_opt_exit_this_program:
					printf("\nLeaving this program...\n");
					break;

				/* We perform the search function by Fibonacci numbers. */
				case enm_opt_fibonacci_search:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = FibonacciSearch(array, *start, *finish, *target_key, position, iter);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Fibonacci search", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Fenced element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Fibonacci search].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Fibonacci search", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* We call a function that obtains the position of the searched element by means of interpolations. */
				case enm_opt_interpolation_search:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							if (InterpolationLocate(array, *start, *finish, *target_key, &middle_bottom, &middle_top, iter))
								{
									printf("\n** [Approximate values ​​obtained] **.\n");

									if (GetValidLimits(middle_bottom, &bottom, &top))
										{
											GetElement("Interpolation search: {lower value obtanied}", array, *start, *finish, *target_key, bottom, top, size, middle_bottom, *calls, *iter, *iters, *random_seed);
											char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
										}
									else
										{
											printf("\n[Interpolation search: {lower value obtained}].\n");
											printf("Element indicated: [%d] not found!\n", *target_key);
											printf("Highest position achieved: [%d].\n", middle_bottom);
										}

									GetItem("Interpolation search: {lower value}", array, *start, *finish, *target_key, middle_bottom, *iter);

									if (GetValidLimits(middle_top, &bottom, &top))
										{
											GetElement("Interpolation search: {upper value obtanied}", array, *start, *finish, *target_key, bottom, top, size, middle_top, *calls, *iter, *iters, *random_seed);
											char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
										}
									else
										{
											printf("\n[Interpolation search: {upper value obtained}].\n");
											printf("Element indicated: [%d] not found!\n", *target_key);
											printf("Highest position achieved: [%d].\n", middle_top);
										}

									GetItem("Interpolation search: {upper value}", array, *start, *finish, *target_key, middle_top, *iter);
								}
							else
								printf("The lower bound: [%d] and upper bound: [%d] are invalid and are outside the range between: [%d] and [%d].\n", middle_bottom, middle_top, *start, *finish);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* We locate an entry or occurrence of the array directly by means of an index number. */
				case enm_opt_locate_directly:
					printf("\nEntry or occurrence number to be located.\n");
					printf("Index position from: [%d] to [%d]: ", V_ZERO, size + V_MINUS_ONE);
					*start = *((int *) GetEntry("", start, enm_type_entry_int, enm_type_reset_YES));
					printf("\nIndex position: [%d] of [%d].\n", *start, size + V_MINUS_ONE);

					if (GetValidLimits(*start, &bottom, &top))
						{
							/* Locate a value determined by its index within the array. */
							*finish = *start;
							char_key = *((char *) GetEntry("Do you want to compare the value located at the given position with a determined value (y/n)? : ", &char_key, enm_type_entry_char, enm_type_reset_YES));

							if (char_key == V_CHR_UPPER_Y || char_key == V_CHR_LOWER_Y)
								{
									//Presentation and indication headers.
									printf("\nSearch for a prime number within the first thousand.\n");
									printf("Prime number to find: ");
									*target_key = *((int *) GetEntry("", target_key, enm_type_entry_int, enm_type_reset_YES));
								}

							GetElement("Locate directly", array, *start, *finish, *target_key, bottom, top, size, *start, *calls, *iter, *iters, *random_seed);
							printf("Element found: [%d] ubicated directly on position: [%d].\n", array[*start], *start);

							GetItem("Locate directly", array, *start, *finish, *target_key, *start, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* A random search is performed within a specified range, using a given starting random seed. */
				case enm_opt_random_seeking:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							/* Visualization of both the random seed and the relative position, both before and after.*/
							ViewRandomInterval(*start, *finish, *position, random_seed);
							*position = GetRandomInterval(*start, *finish, random_seed);
							ViewRandomInterval(*start, *finish, *position, random_seed);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Random seeking", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Searched element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Random seeking].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Random seeking", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* We call a function that sequentially searches for a value until it finds it. */
				case enm_opt_sequential_search:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = SequentialSearch(array, *start, *finish, *target_key, position, iter);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Sequential search", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Searched element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Sequential search].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Sequential search", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* Recursive sequential search process. */
				case enm_opt_sequential_search_recursive:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = *start;
							*position = SequentialSearchRecursive(array, *start, *finish, *target_key, bottom, top, position, iter);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("Sequential search recursive", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Searched element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[Sequential search recursive].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("Sequential search recursive", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* See all the details of the record to be consulted. */
				case enm_opt_view_all_items:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = ViewAllItems(array, *start, *finish, *target_key, position, iter, iters);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("View all items details", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Fenced element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[View all items].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("View all items", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* See each element of the arrangement step by step. */
				case enm_opt_view_each_element:
					if (GetValidInputs(start, finish, target_key, &bottom, &top))
						{
							*position = ViewEachElement(array, *start, *finish, *target_key, bottom, top, size, position, *calls, iter, iters, *random_seed);

							if (GetValidLimits(*position, &bottom, &top))
								{
									GetElement("View each element of the arrangement", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
									printf("Fenced element at position: [%d] located with content: [%d].\n", *position, array[*position]);
								}
							else
								{
									printf("\n[View each element of the arrangement].\n");
									printf("Element indicated: [%d] not found!\n", *target_key);
									printf("Highest position achieved: [%d].\n", *position);
								}

							GetItem("View each element of the arrangement", array, *start, *finish, *target_key, *position, *iter);
						}

					char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
					break;

				/* View the latest generated statistics. */
				case enm_opt_view_statistics:
					GetElement("View Statistics", array, *start, *finish, *target_key, bottom, top, size, *position, *calls, *iter, *iters, *random_seed);
					break;

				/* Case of failed option. */
				default:
					printf("\nThe selected option: [%d] is not valid. Correct it!\n", *value);
					break;
			}

		*iters += *iter;
		return *value;
	}

//Sequential search function given a start position.
int SequentialSearch(const int array[], const int start, const int finish, const int target_key, int *pos, int *iters)
	{
		/* Preliminary working variables. */
		int idx = V_ZERO;

		/* Main cycle of iterations while the searched value is not found. */
		for (idx = start; idx <= finish && array[idx] < target_key; idx++, (*iters)++);

		return(*pos = (array[idx] == target_key) ? idx : V_MINUS_ONE);
	}

//Function that performs a recursive sequential search for a given element in a given array.
int SequentialSearchRecursive(const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, int *pos, int *iters)
	{
		/* Validates that the start and end ranges are within the bounds of the minimum and maximum array index. */
		if ((start >= bottom && start <= top))
			if ((finish >= bottom && finish <= top))
				/* Base case: if we have reached the final index. */
				if (*pos >= start && *pos <= finish)
					/* If the element at index 'start' is the one we are looking for, return the obtained index. */
					if (array[*pos] == target_key)
						/* Print the result returned by the recursive sequential search function. */
						printf("\nThe element: [%d] from: [%d] to [%d] was located in the position: [%d] = {%d} with: [%d] spins.\n", target_key, start, finish, *pos, array[*pos], *iters);
					else
						{
							/* Recursive call to find the element at the next incremented index. */
							(*iters)++; (*pos)++;
							SequentialSearchRecursive(array, start, finish, target_key, bottom, top, pos, iters);
						}
				else
					{
						printf("\nThe element: [%d] was not located.\n", target_key);
						printf("Highest position reached: [%d]. Out of range between: [%d] and [%d] with: [%d] turns.\n", *pos, start, finish, *iters);
					}
			else
				printf("\nThe finish index: [%d] are out of range between: [%d] and [%d].\n", finish, top, bottom);
		else
			printf("\nThe start index: [%d] are out of range between: [%d] and [%d].\n", start, top, bottom);

		return (*pos = (*pos >= start && *pos <= finish) ? *pos : V_MINUS_ONE);
	}

//The limits that comprise a given range are exchanged if they are inverted.
void SwappingLimits(const char *str_Message, int *start, int *finish)
	{
		/* Preliminary working variables. */
		char char_key = NULL_CHARACTER;

		/* Validate whether the sent limits are inverted to exchange them with each other. */
		if (*start > *finish || *finish < *start)
			{
				printf("\n[%s].\n", str_Message);
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("|   Major & Minor Values Exchange.  |\n");
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Higher  : [%d].\n", *finish);
				printf("| Lower   : [%d].\n", *start);
				printf("+---+----+---+----+---+----+---+----+\n");

				SwapValues(start, finish);

				printf("\n");
				printf("+---=----=---=----=---=----=---=----+\n");
				printf("|       Changed limit values.       |\n");
				printf("+---=----=---=----=---=----=---=----+\n");
				printf("| Larger  : [%d].\n", *finish);
				printf("| Smaller : [%d].\n", *start);
				printf("+---=----=---=----=---=----=---=----+\n");
			}
		else
			printf("\nCorrect values. Shorter: [%d]. Longer: [%d].\n", *start, *finish);

		char_key = *((char *) GetEntry("Press the ENTER key to continue...", &char_key, enm_type_entry_char, enm_type_reset_YES));
	}

//Exchange of two numerical variables with each other.
void SwapValues(int *left_value, int *right_value)
	{
		int temp_value = *left_value;
		*left_value = *right_value;
		*right_value = temp_value;
	}

//Function that sees all the details of the record to be consulted.
int ViewAllItems(const int array[], const int start, const int finish, const int target_key, int *pos, int *iter, int *iters)
	{
		/* Preliminary working variables. */
		char char_key = V_CHR_UPPER_Y;
		int idx = V_ZERO;

		/* Header message. */
		printf("\nPractical visualization of pointer naming.\n");

		/* Combined loop to dump the memory addresses and contents of various integer arrays. */
		for (*iter = V_ZERO, idx = start; idx <= finish && array[idx] <= target_key && (char_key == V_CHR_LOWER_Y || char_key == V_CHR_UPPER_Y); idx++, (*iter)++)
			{
				printf("\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("|   Retrieved record information.   |\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("| Index position #: [%d] of: [%d].\n", idx, finish);
				printf("| Position content: [%d].\n", array[idx]);
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Current  cycle  : {%d}.\n", *iter);
				printf("| Searched value  : <%d>.\n", target_key);
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

				if (array[idx] == target_key) printf ("** Element: [%d] = [%d] located in position: [%d]. **\n", target_key, array[idx], idx);

				char_key = *((char *) GetEntry("Do you want to continue viewing more records (y/n)? : ", &char_key, enm_type_entry_char, enm_type_reset_YES));
			}

		*iters += *iter;

		return(*pos = (--idx >= start && idx <= finish) ? idx : V_MINUS_ONE);
	}

//Visualize each element of the arrangement step by step.
int ViewEachElement(const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, const int size, int *pos, const int calls, int *iter, int *iters, const int random_seed)
	{
		/* Preliminary working variables. */
		char char_key = V_CHR_UPPER_Y;
		int idx = V_ZERO;

		/* Header message. */
		printf("\nPractical visualization of each element of the arrangement.\n");

		/* Combined loop to dump the memory addresses and contents of various integer arrays. */
		for (*iter = V_ZERO, idx = start; idx <= finish && (char_key == V_CHR_LOWER_Y || char_key == V_CHR_UPPER_Y); idx++, (*iter)++)
			{
				GetElement("View each element of the arrangement", array, start, finish, target_key, bottom, top, size, idx, calls, *iter, *iters, random_seed);

				if (array[idx] == target_key)
					printf ("** Element: [%d] = [%d] located in position: [%d]. **\n", target_key, array[idx], *pos = idx);

				char_key = *((char *) GetEntry("Do you want to continue viewing more records (y/n)? : ", &char_key, enm_type_entry_char, enm_type_reset_YES));
			}

		*iters += *iter;

		return((*pos >= start && *pos <= finish) ? *pos : V_MINUS_ONE);
	}

//Displays messages about the random number to be generated and its active seed.
int ViewRandomInterval(const int start, const int finish, const int position, int *random_seed)
	{
		/* Preliminary working variables. */
		char char_key = NULL_CHARACTER;

		/* Calculation of a random relative position. */
		printf("\n");
		printf("+===|====+===|====+===|====+\n");
		printf("| Random Relative Position.|\n");
		printf("+===|====+===|====+===|====+\n");
		printf("| * Begin:\t[%d].\n", start);
		printf("| * End:\t[%d].\n", finish);
		printf("+---|----+---|----+---|----+\n");
		printf("| + Seed:\t[%d].\n", *random_seed);
		printf("| + Position:\t[%d].\n", position);
		printf("+===|====+===|====+===|====+\n");

		char_key = *((char *) GetEntry("Do you want to modify the initial random seed (y/n)? : ", &char_key, enm_type_entry_char, enm_type_reset_YES));

		if (char_key == V_CHR_LOWER_Y || char_key == V_CHR_UPPER_Y)
			*random_seed = *((int *) GetEntry("Enter an initial random seed : ", random_seed, enm_type_entry_int, enm_type_reset_YES));

		printf("\nThe random seed is set to: [%d] right now.\n", *random_seed);

		return position;
	}


//Main function.
int main()
	{
		int option = MainMenu(&option);

		return V_ZERO;
	}
