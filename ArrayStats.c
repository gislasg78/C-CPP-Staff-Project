/* This program demonstrates the use of pointers in C to return
   various statistics about a given array.
   These statistics include the number of values,
   the average, the maximum, the minimum, and the sum of these.
   The initial memory address of the array and the final memory address
   (which must be one after the last element of the array) must be specified.
*/

/* Standard work libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define V_ZERO  0

/* Function that returns five basic statistics in the array: count, average, sum, maximum, and minimum. */
int getStats(const int *const ptr_begin, const int *const ptr_end, int *const avg, int *const count, int *const max, int *const min, int *const sum)
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;

		/* Validate that the pointers are valid and not null. */
		if (ptr_begin && ptr_end && avg && count && max && min && sum)
			{
				/* Validate that the array is not empty. */
				if (ptr_begin != ptr_end)
					{
						/* Initialize element count, sum, maximum value, and minimum value. */
						int m_max = *ptr_begin, m_min = m_max;
						*count = V_ZERO; *sum = V_ZERO;

						/* Fundamental cycle of traversing the array to be calculated. */
						for (const int* ptr = ptr_begin; ptr != ptr_end; ptr++)
							{
								counter++;	//It is intentionally repeated to return it as part of the function's return value.
								(*count)++;	//Counting values ​​one by one.
								*sum += *ptr;	//Cumulative sum of values.

								if (*ptr > m_max) m_max = *ptr;	//Maximum value.
								if (*ptr < m_min) m_min = *ptr;	//Minimum value.
							}

						/* Returned values: maximum, minimum, and average. */
						*avg = (*count) ? *sum / *count : V_ZERO;	//Arithmetic mean.
						*max = m_max;		//Maximum value.
						*min = m_min;		//Minimum value.
					}
				else
					fprintf(stderr, "\nThe array comes empty (without any elements).\n");
			}
		else
			fprintf(stderr, "\nValid memory addresses were not passed correctly.\n");

		/* Return the number of items processed. */
		return counter;
	}

/* Function that returns the number of elements to display from the array. */
int printArray(const int int_array[], const int size_array)
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;

		/* Pour the elements of the array one by one. */
		printf("\nArrangement dump.\n");
		for (int idx = V_ZERO; idx < size_array; idx++)
			{
				printf("#: [%2d]\t=\t[%3d].\n", counter++, int_array[idx]);
			}
		printf("[%d] Output results generated.\n", counter);

		/* Return the number of items processed. */
		return counter;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int avg = V_ZERO, count = V_ZERO, max = V_ZERO, min = V_ZERO, recs = V_ZERO, sum = V_ZERO;
		int int_array[] = {103, 61, 41, 67, 73, 101, 13, 31, 29, 89,
				   83, 11, 7, 47, 43, 19, 71, 79, 97, 37,
				   59, 23, 17, 3, 53, 53, 61, 11, 2, 71};

		const int size_array = sizeof(int_array) / sizeof(*int_array);	//Automatically calculate the array size.

		/* Initial header messages. */
		printf("Arithmetic calculations with arrays.\n");

		/* Print all elements of the array preliminarily. */
		recs = printArray(int_array, size_array);
		printf("\nRecords viewed:\t[%d].\n", recs);

		/* Calculate various descriptive statistics from the elements of the array. */
		recs = getStats(int_array, int_array + size_array, &avg, &count, &max, &min, &sum);

		/* Visualization of the results obtained using pointers. */
		printf("\nArray statistics.\n");
		printf("+ Average:\t[%d].\n", avg);
		printf("+ Counter:\t[%d].\n", count);
		printf("+ Maximum:\t[%d].\n", max);
		printf("+ Minimum:\t[%d].\n", min);
		printf("+ Records:\t[%d].\n", recs);
		printf("+ Summatory:\t[%d].\n", sum);

		/* Termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
