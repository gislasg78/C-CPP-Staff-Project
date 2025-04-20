/* The purpose of this program is to sort a disorganized array of integers
   using the combination or combinatorial sort method. */

/* Basic work libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_TWO	2
#define	V_ZERO	0

/* Function to combine two subarrays in order. */
void Merge(int array[], int temp[], int left, int right)
	{
		/* Find the midpoint. */
		int middle = (left + right) / V_TWO;

		/* If the lower and upper indexes are different, the code is executed. */
		if (left != right)
			{
				/* Recursive calls to split the array. */
				Merge(array, temp, left, middle);
				Merge(array, temp, middle + V_ONE, right);

				/* Combine the two halves. */
				int idx = left;			/* Index for the left half. */
				int jdx = middle + V_ONE;	/* Index for the right half. */
				int kdx = left;			/* Index for temporary arrangement. */

				/* Compare the elements of both halves and mix them. */
				while (idx <= middle && jdx <= right)
					{
						if (array[idx] <= array[jdx])
							{
								temp[kdx++] = array[idx++];
							}
						else
							{
								temp[kdx++] = array[jdx++];
							}
					}

				/* Copy the remaining elements from the left half (if any). */
				while (idx <= middle)
					{
						temp[kdx++] = array[idx++];
					}

				/* Copy the remaining elements from the right half (if any). */
				while (jdx <= right)
					{
						temp[kdx++] = array[jdx++];
					}

				/* Copies the sorted elements to the original array. */
				for (idx = left; idx <= right; idx++)
					{
						array[idx] = temp[idx];
					}
			}
	}

/* Main function to sort the array. */
void MergeSort(int array[], int idx, int size)
	{
		/* Preliminary working variables. */
		int *temp = (int *) malloc(size * sizeof(int));	/* Temporary fix for the merge. */

		/* Detect if the created pointer is null or invalid. */
		if (temp)
			{
				/* Start the merge sort process. */
				Merge(array, temp, idx, size - V_ONE);	/* Initial call to order the arrangement. */
				free(temp);				/* Free up temporary memory. */
			}
		else
			{
				perror("Error allocating memory to accommodate a temporary array.");
				exit(EXIT_FAILURE);
			}
	}

/* Function to print the array. */
void printArray(int array[], int pos, int size)
	{
		printf("Displaying the array of integers.\n");

		for (int idx = pos; idx < size; idx++)
			{
				printf("#: [%3d].\t\t[%d].\n", idx, array[idx]);
			}

		printf("\n");
	}

int main()
	{
		/* Preliminary working variables. */
		int array[] = 	{
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

		/* Display the contents of the original array. */
		printf("Original arrangement.\n");
		printArray(array, V_ZERO, size);

		/* Sort the array using Merge Sort. */
		MergeSort(array, V_ZERO, size);

		/* Display the contents of the sorted array. */
		printf("Ordered arrangement.\n");
		printArray(array, V_ZERO, size);

		return V_ZERO;
	}
