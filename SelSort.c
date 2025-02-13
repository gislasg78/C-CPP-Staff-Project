#include <stdio.h>

#define	V_ONE	1
#define	V_ZERO	0

void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

void SelectionSort(int array[], const int size)
	{
		int idx = V_ZERO, jdx = V_ZERO, min_idx = V_ZERO;

		for (idx = V_ZERO; idx < size - V_ONE; idx++)
			{
				min_idx = idx;

				for (jdx = idx + V_ONE; jdx < size; jdx++)
					if (array[jdx] < array[min_idx])
						min_idx = jdx;

				swap(&array[min_idx], &array[idx]);
			}
	}

void ViewArray(int array[], const int size)
	{
		for (int idx = V_ZERO; idx < size; idx++)
			printf("#[%d].\t[%d].\n", idx, *(array + idx));

		printf("\n");
	}

int main()
	{
		int array[] =	{
				79, 2, 64, 103, 350, 378, 174, 223, 317, 243,
				304, 207, 497, 356, 132, 678, 226, 213, 461, 271,
				983, 312, 35, 932, 829, 923, 853, 9, 101, 734,
				674, 630, 887, 889, 296, 399, 613, 146, 589, 988,
				110, 595, 267, 776, 32, 919, 137, 891, 154, 222,
				843, 441, 976, 462, 442, 535, 980, 820, 112, 377,
				122, 264, 996, 311, 354, 529, 424, 873, 800, 369,
				416, 244, 859, 699, 774, 196, 881, 745, 600, 158,
				886, 799, 72, 822, 90, 487, 327, 241, 495, 323,
				46, 723, 987, 751, 587, 385, 308, 524, 826, 638
				};

		int size = sizeof(array) / sizeof(array[V_ZERO]);

		printf("Selection sort.\n");
		printf("Original arrangement uploaded :\n");
		ViewArray(array, size);

		SelectionSort(array, size);

		printf("Ordered arrangement by selection (Selection Sort) :\n");
		ViewArray(array, size);

		return V_ZERO;
	}
