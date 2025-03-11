#include <stdio.h>

#define	V_MINUS_ONE	-1
#define	V_TWO		2
#define	V_ONE		1
#define	V_ZERO		0

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
			947, 953, 967, 971, 977, 983, 991, 997.
			};

//Improved binary search function with a delta factor.
int BinarySearchDelta(int array[], const int size, const int target_key, const int delta_factor, int *pos, int *iters)
	{
		//Preliminary working variables.
		int high = size + V_MINUS_ONE, low = V_ZERO;

		//Calculate the midpoint with the delta factor.
		int middle = low + (high - low) / V_TWO + delta_factor;
		*pos = V_MINUS_ONE;

		//Continue searching as long as there is a valid range.
		for (*iters = V_ZERO; low <= high && array[middle] != target_key; (*iters)++)
			{
				//If the average index falls outside the range, we adjust.
				middle = (middle < low || middle > high) ? low + (high - low) / V_TWO
									 : low + (high - low) / V_TWO + delta_factor;

				//Compare the value at the midpoint with the target
				if (array[middle] == target_key)
					*pos = middle;			//The number was found.
				else if (array[middle] < target_key)
					low = middle + V_ONE;		//We adjust the lower limit of the array.
				else if (array[middle] > target_key)
					high = middle + V_MINUS_ONE;	//We adjust the upper limit of the array
			}

		return *pos;	//The located position of the element is returned as a result.
	}

int main()
	{
		//Preliminary working variables.
		int delta_factor = V_ZERO;	//Delta factor that adjusts the position of the medium.
		int iterations = V_ZERO;
		int size = sizeof(array) / sizeof(array[V_ZERO]);
		int target_key = V_ZERO;

		printf("Search for a prime number within the first thousand.\n");
		printf("Prime number to find: ");
		scanf("%d", &target_key);
		printf("Delta adjustment factor: ");
		scanf("%d", &delta_factor);

		//We call the function enhanced binary search.
		int position = BinarySearchDelta(array, size, target_key, delta_factor, &position, &iterations);

		//Validates if the position is in a correct range.
		if (position >= V_ZERO && position < size)
			{
				printf("\n");
				printf("+---+----+---+----+---+\n");
				printf("|  Search successful. |\n");
				printf("+---+----+---+----+---+\n");
				printf("| * Delta      : [%d].\n", delta_factor);
				printf("+---+----+---+----+---+\n");
				printf("| * Element    : [%d].\n", target_key);
				printf("| * Iterations : [%d].\n", iterations);
				printf("+---+----+---+----+---+\n");
				printf("| * Position   : [%d].\n", position);
				printf("| * Content    : [%d].\n", array[position]);
				printf("+---+----+---+----+---+\n");
				printf("\n");
			}
		else
			printf("\nThe searched value: [%d] was not found in array.\n", target_key);

		return V_ZERO;
	}
