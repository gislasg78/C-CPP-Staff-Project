#include <stdio.h>

#define V_ZERO  0

void getStats(const int *const ptr_begin, const int *const ptr_end, int *const avg, int *const count, int *const max, int *const min, int *const sum)
	{
		if (ptr_begin && ptr_end && avg && count && max && min && sum)
			{
				int m_max = *ptr_begin, m_min = *ptr_begin;
				*count = V_ZERO; *sum = V_ZERO;

				for (const int* ptr = ptr_begin; ptr != ptr_end; ptr++)
					{
						(*count)++;
						*sum += *ptr;

						if (*ptr > m_max) m_max = *ptr;
						if (*ptr < m_min) m_min = *ptr;
					}

				*max = m_max;
				*min = m_min;
				*avg = *sum / *count;
			}
		else
			fprintf(stderr, "\nValid memory addresses were not passed correctly.\n");
	}

int main()
	{
		int avg = V_ZERO, count = V_ZERO, max = V_ZERO, min = V_ZERO, sum = V_ZERO;
		int int_array[] = {103, 61, 41, 67, 73, 101, 13, 31, 29, 89,
				   83, 11, 7, 47, 43, 19, 71, 79, 97, 37,
				   59, 23, 17, 3, 53, 53, 61, 11, 2, 71};

		const int size_array = sizeof(int_array) / sizeof(*int_array);

		printf("Arrangement dump.\n");
		for (int i = V_ZERO; i < size_array; i++)
			printf("[%d].\t", int_array[i]);
		printf("\n");

		getStats(int_array, int_array + size_array, &avg, &count, &max, &min, &sum);

		printf("\nArray statistics.\n");
		printf("+ Average:\t[%d].\n", avg);
		printf("+ Counter:\t[%d].\n", count);
		printf("+ Maximum:\t[%d].\n", max);
		printf("+ Minimum:\t[%d].\n", min);
		printf("+ Summatory:\t[%d].\n", sum);

		return V_ZERO;
	}
