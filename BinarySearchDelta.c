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

//Global static array of prime numbers.
static int array[] = 	{
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

//Improved traditional binary search function.
int BinarySearch(int array[], const int size, const int target_key, int *pos, int *iters)
	{
		//Preliminary working variables.
		int high = size + V_MINUS_ONE, low = V_ZERO, middle = V_ZERO;

		//Calculate the midpoint position.
		middle = low + (high - low) / V_TWO;
		*pos = V_MINUS_ONE;

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

		return *pos;	//The located position of the element is returned as a result.
	}

//Improved binary search function with internal delta factor.
int BinarySearchDelta(int array[], const int size, const int target_key, int *delta_factor, int *pos, int *iters)
	{
		//Preliminary working variables.
		int middle = V_ZERO;

		//Calculate the midpoint position.
		middle = *delta_factor = size / V_TWO;
		*pos = V_MINUS_ONE;

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

		return *pos;	//The located position of the element is returned as a result.
	}

//Improved traditional recursirve and cyclic binary search function.
int BinarySearchRecursive(int array[], const int target_key, const int bottom, const int top, int *pos, int *iters)
	{
		//Preliminary working variables.
		static int iteratives = V_ZERO;
		int middle = (bottom + top) / V_TWO;

		//Calculate the first relative position of the element.
		iteratives++; *pos = V_MINUS_ONE;

		//Compare the value at the midpoint with the target.
		if ((bottom <= top))
			{
				if (array[middle] == target_key)
					*pos = middle;
				else if (array[middle] > target_key)
					BinarySearchRecursive(array, target_key, bottom, middle - V_ONE, pos, iters);
				else if (array[middle] < target_key)
					BinarySearchRecursive(array, target_key, middle + V_ONE, top, pos, iters);
			}

		*iters = iteratives;
		return *pos;	//The located position of the element is returned as a result.
	}

int getElement(const char *str_Message, const int array[], const int size, const int target_key, const int position, const int iterations)
	{
		//Preliminary working variables.
		int item = V_ZERO;

		//Validates if the position is in a correct range.
		if (position >= V_ZERO && position < size)
			{
				printf("\n");
				printf("[%s].\n", str_Message);
				printf("+===+====+===+====+===+\n");
				printf("|    Binary Search.   |\n");
				printf("+-=-+----+-=-+----+-=-+\n");
				printf("| * Element  : [%d].\n", target_key);
				printf("| + Cycles   : {%d}.\n", iterations);
				printf("+-=-+----+---+----+-=-+\n");
				printf("|      Item Info.     |\n");
				printf("+-=-+----+---+----+-=-+\n");
				printf("| * Position : [%d].\n", position);
				printf("| * Content  : [%d].\n", array[position]);
				printf("+===+====+===+====+===+\n");
				printf("\n");

				item = array[position];
			}
		else
			printf("\nThe searched value: [%d] was not found in array.\n", target_key);

		return item;
	}

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
				scanf("%*[^\n]%*c");
				while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}

		return value_key;
	}

//Main function.
int main()
	{
		//Preliminary working variables.
		int delta_factor = V_ZERO;	//Delta factor that adjusts the position of the medium.
		int iterations = V_ZERO;	//Number of iterations performed.
		int position = V_ZERO;		//Location position of the located element.
		int size = sizeof(array) / sizeof(array[V_ZERO]);	//Calculated array size.
		int target_key = V_ZERO;	//Numeric search key.

		//Presentation and indication headers.
		printf("Search for a prime number within the first thousand.\n");
		printf("Prime number to find: ");
		target_key = getEntry(&target_key);

		//We call the traditional binary search function.
		position = BinarySearch(array, size, target_key, &position, &iterations);
		getElement("Traditional Loop Binary Search", array, size, target_key, position, iterations);

		//We call the binary search function with a delta factor.
		position = BinarySearchDelta(array, size, target_key, &delta_factor, &position, &iterations);
		getElement("Binary Search with delta factor", array, size, target_key, position, iterations);
		printf("  * Delta Fx : [%d].\n", delta_factor);

		//We call the traditional recursive and cyclic binary search function.
		position = BinarySearchRecursive(array, target_key, V_ZERO, size + V_MINUS_ONE, &position, &iterations);
		getElement("Recursive Loop Binary Search", array, size, target_key, position, iterations);

		return V_ZERO;
	}
