/* The purpose of this program is to sort
   an array of integers using the bubble sort method. */

/* Main work libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_ZERO	0

/* Function that exchanges the position of two integer values. */
void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

/* Bubble sort method. */
void BubbleSort(int array[], int pos, int size)
	{
		/* Preliminary working variables. */
		int idx = V_ZERO, sdx = V_ZERO;

		/* Combined cycle of successive orders. */
		sdx = V_ONE;
		while ((sdx = V_ONE) && (--size >= pos))
			{
				sdx = V_ZERO;

				/* Internal cycle of the route. */
				for (idx = V_ONE; idx <= size; idx++)
					if (array[idx - V_ONE] > array[idx])
						{
							swap(array + (idx - V_ONE), &array[idx]);
							sdx = V_ONE;
						}
			}
	}

/* Displays the contents of the integer array. */
void ViewArray(int array[], const int pos, const int size)
	{
		printf("Display of the array contents.\n");

		for (int idx = pos; idx < size; idx++)
			printf("#: [%3d].\t[%d].\n", idx, *(array + idx));

		printf("\n");
	}

/* Main function. */
int main()
	{
		int array[] =
			{
				907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
				809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
				701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
				601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
				503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
				401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
				307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
				211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
				101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
				2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
			};

		int size = sizeof(array) / sizeof(array[V_ZERO]);

		/* The original arrangement is shown. */
		printf("Bubble sort.\n");
		printf("Original arrangement.\n");
		ViewArray(array, V_ZERO, size);

		/* Bubble sort is performed. */
		BubbleSort(array, V_ZERO, size);

		/* The sorted arrangement is shown. */
		printf("Ordered arrangement.\n");
		ViewArray(array, V_ZERO, size);

		return V_ZERO;
	}
