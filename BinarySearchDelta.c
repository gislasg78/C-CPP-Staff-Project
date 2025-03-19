/* Program that performs binary searches with cycles
   in the traditional way as well as with a 'delta' factor. */

//Standard work libraries.
#include <stdio.h>

//Macro for partitioning a binary delta search.
#define	MEDIUM(x)	(((x) + V_ONE) / V_TWO)

//Symbolic constants of working characters.
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'

//Symbolic work constants.
#define	V_MINUS_ONE	-1
#define	V_TWO		2
#define	V_ONE		1
#define	V_ZERO		0

//Enumeration with menu options.
enum enm_options
	{
		opt_bin_srch_normal = V_ONE,
		opt_bin_srch_recursive,
		opt_bin_srch_delta,
		opt_interpolation_srch,
		opt_exit
	} enm_option;

//Global static array of prime numbers.
static const int array[] = {
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

//Prototype functions.
char getPause(const char *str_Message);
int SelectedOption(int *value);


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

int getElement(const char *str_Message, const int array[], const int size, const int target_key, const int position, const int iterations)
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
				printf("| * Position : [%d].\n", position);
				printf("| * Content  : [%d].\n", array[position]);
				printf("+===+====+===+====+===+\n");

				stop_key = getPause("Press the ENTER key to continue...");
				item = array[position];
			}
		else
			printf("\nThe searched value: [%d] was not found in array.\n", target_key);

		return item;
	}

//Get a correct integer value.
int getEntry(int *target_key)
	{
		//Preliminary working variables.
		char c = NULL_CHARACTER;
		int value_key = V_ZERO;

		//Validate data entry as correct.
		if (scanf("%d", &value_key) == V_ONE)
			{
				printf("\nInput value: [%d]. OK!\n", value_key);
				*target_key = value_key;
			}
		else
			{
				//Get a incorrect unsigned integer value.
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}

		return value_key;
	}

//Make a pause.
char getPause(const char *str_Message)
	{
		//Preliminary working variables.
		char chr_key = NULL_CHARACTER;

		printf("%s", str_Message);

		//Validate data entry as correct.
		if (scanf("%c", &chr_key))
			{
				scanf("%*[^\n]%*c");
				while ((chr_key = getchar()) != CARRIAGE_RETURN && chr_key != EOF);
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
				printf("| [1]. Binary search in loop.  |\n");
				printf("| [2]. Recursive binary search.|\n");
				printf("| [3]. Binary delta search.    |\n");
				printf("| [4]. Interpolation search.   |\n");
				printf("| [5]. Exit this program.      |\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("Choose an option: ");

				*option = value = getEntry(&value);
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
		int position = V_ZERO;		//Location position of the located element.
		int size = sizeof(array) / sizeof(array[V_ZERO]);	//Calculated array size.
		int target_key = V_ZERO;	//Numeric search key.

		//Presentation and indication headers.
		if (*value >= opt_bin_srch_normal && *value < opt_exit)
			{
				printf("\nSearch for a prime number within the first thousand.\n");
				printf("Prime number to find: ");
				target_key = getEntry(&target_key);
			}

		//Convert integer value to enumerated value.
		enm_option = (enum enm_options) *value;

		//Selection of cases with the enumerated value obtained.
		switch (enm_option)
			{
				//We call the traditional binary search function.
				case opt_bin_srch_normal:
					position = BinarySearch(array, size, target_key, &position, &iterations);
					getElement("Traditional Loop Binary Search", array, size, target_key, position, iterations);
					break;

				//We call the traditional recursive and cyclic binary search function.
				case opt_bin_srch_recursive:
					iterations = V_ZERO;
					position = BinarySearchRecursive(array, target_key, V_ZERO, size + V_MINUS_ONE, &position, &iterations, &iteratives);
					getElement("Recursive Loop Binary Search", array, size, target_key, position, iterations);
					printf("[%d] calls made to the recursive binary search function.\n", iteratives);
					break;

				//We call the binary search function with a delta factor.
				case opt_bin_srch_delta:
					position = BinarySearchDelta(array, size, target_key, &delta_factor, &position, &iterations);
					getElement("Binary Search with delta factor", array, size, target_key, position, iterations);
					printf("  * Delta Fx : [%d].\n", delta_factor);
					break;

				//We call a function that obtains the position of the searched element by means of interpolations.
				case opt_interpolation_srch:
					if (InterpolationLocate(array, V_ZERO, size - V_ONE, target_key, &middle_bottom, &middle_top, &iterations))
						{
							printf("\n** [Approximate values ​​obtained] **.\n");
							getElement("Interpolated lower value obtained", array, size, target_key, middle_bottom, iterations);
							getElement("Interpolated upper value obtained", array, size, target_key, middle_top, iterations);
						}
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


//Main function.
int main()
	{
		int option = Menu(&option);

		return V_ZERO;
	}
