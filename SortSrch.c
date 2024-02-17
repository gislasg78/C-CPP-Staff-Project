#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	V_MINUS_ONE	-1
#define	V_TWO		2
#define	V_ONE		1
#define	V_ZERO  	0

void swap_values(int*, int *);

int BinarySearch(int *ptr_int_array, const int int_Size)
	{
		int int_data = V_ZERO;

		int int_bottom = V_ZERO;
		int int_middle = V_ZERO;
		int int_top = int_Size;

		printf("Enter a data: ");
		scanf("%d", &int_data);

		printf("Binary search.\n");

		/* Binary search for an element within an array. */
		while (int_bottom <= int_top && int_data != ptr_int_array[int_middle])
			{
				int_middle = (int_bottom + int_top) / V_TWO;

				if (int_data > ptr_int_array[int_middle])
					int_bottom = int_middle + V_ONE;

				if (int_data < ptr_int_array[int_middle])
					int_top = int_middle + V_MINUS_ONE;
			}

		if (int_data == ptr_int_array[int_middle])
			{
				printf("\n");
				printf("Data     : [%d].\n", int_data);
				printf("Position : [%d].\n", int_middle);
				printf("Address  : [%p].\n", ptr_int_array);
				printf("\n");
				printf("Values   : [%d] = [%d].\n", *(ptr_int_array + int_middle), ptr_int_array[int_middle]);
				printf("Address  : [%p] = [%p].\n", ptr_int_array + int_middle, &ptr_int_array[int_middle]);
			}
		else
			printf("Value: [%d] Not Found! Nearest position: [%d] with value: [%d].\n", int_data, int_middle, ptr_int_array[int_middle]);
	}

int BubbleSort(int *ptr_int_array, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		printf("Bubble Sort.\n");

		for (int int_idx = V_ZERO; int_idx < int_Size + V_MINUS_ONE; int_idx++)
			for (int int_ind = int_idx + V_ONE; int_ind < int_Size; int_ind++)
				if (ptr_int_array[int_idx] > *(ptr_int_array + int_ind))
					{
						int_counting_items++;
						swap_values(&ptr_int_array[int_idx], &ptr_int_array[int_ind]);
					}

		return int_counting_items;
	}

int captureArray(int *ptr_int_array, const int int_Size)
	{
		int int_counting_items = V_ZERO;
		int int_data = V_ZERO;

		if (ptr_int_array)
			for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
				{
					printf("Enter a data #[%d] of [%d] : ", int_idx, int_Size);
					scanf("%d", &int_data);

					ptr_int_array[int_idx] = int_data;
				}

		return int_counting_items;
	}

int *createArray(int **ptr_int_matrix_numbers, const int int_Size)
	{
		int *ptr_int_array = NULL;

		if (ptr_int_matrix_numbers)
			if (ptr_int_array = (int *) malloc(int_Size * sizeof(int)))
				*ptr_int_matrix_numbers = ptr_int_array;
			else
				{
					perror("Mistake! Insufficient memory space for allocation...");
					exit(EXIT_FAILURE);
				}

		return ptr_int_array;
	}

int dumpArray(int *ptr_int_array, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		if (ptr_int_array)
			{
				printf("Address:\t[%p].\n", ptr_int_array);

				for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
					printf("#[%d].\t(%d, %d).\t[%p] : [%p].\t[%d] = [%d].\n", int_counting_items++, int_idx, int_Size,
						ptr_int_array + int_idx, &ptr_int_array[int_idx],
						*(ptr_int_array + int_idx), ptr_int_array[int_idx]);
			}

		printf("\n");

		return int_counting_items;
	}

int initializeArray(int *ptr_int_array, const int int_Size)
	{
		if (ptr_int_array)
			for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
				*(ptr_int_array + int_idx) = V_ZERO;
	}

int InsertionSort(int *ptr_int_array, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		int int_aux = V_ZERO;
		int int_pos = V_ZERO;

		printf("Insertion Sort.\n");

		for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
			{
				for (int_pos = int_idx, int_aux = ptr_int_array[int_idx];
					(int_pos > V_ZERO) && (ptr_int_array[int_pos + V_MINUS_ONE] > int_aux); int_pos--)
						{
							int_counting_items++;
							ptr_int_array[int_pos] = ptr_int_array[int_pos + V_MINUS_ONE];
						}

				ptr_int_array[int_pos] = int_aux;
			}

		return int_counting_items;

	}

int SelectionSort(int *ptr_int_array, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		int int_aux = V_ZERO;
		int int_min = V_ZERO;

		printf("Selection Sort.\n");

		for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
			{
				int_min = int_idx;

				for (int int_ind = int_idx + V_ONE; int_ind < int_Size; int_ind++)
					if (ptr_int_array[int_ind] < ptr_int_array[int_min])
						int_min = int_ind;

				int_counting_items++;
				swap_values(ptr_int_array + int_idx, ptr_int_array + int_min);
			}

		return int_counting_items;

	}

void swap_values(int *ptr_int_left_value, int *ptr_int_right_value)
	{
		int int_aux_value = V_ZERO;

		int_aux_value = *ptr_int_left_value;
		*ptr_int_left_value = *ptr_int_right_value;
		*ptr_int_right_value = int_aux_value;
	}

int viewArray(int *ptr_int_array, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		if (ptr_int_array)
			for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++, int_counting_items++)
				printf("[%d].\t", ptr_int_array[int_idx]);

		printf("\n");

		return int_counting_items;
	}

int main()
	{
		int int_counting_items = V_ZERO;
		int *ptr_int_array = NULL;
		int int_Size = V_ZERO;

		printf("Enter the size of array: ");
		scanf("%d", &int_Size);

		ptr_int_array = createArray(&ptr_int_array, int_Size);

		int_counting_items = initializeArray(ptr_int_array, int_Size);
		int_counting_items = captureArray(ptr_int_array, int_Size);
		int_counting_items = BubbleSort(ptr_int_array, int_Size);
		int_counting_items = dumpArray(ptr_int_array, int_Size);
		int_counting_items = viewArray(ptr_int_array, int_Size);
		int_counting_items = BinarySearch(ptr_int_array, int_Size);

		int_counting_items = initializeArray(ptr_int_array, int_Size);
		int_counting_items = captureArray(ptr_int_array, int_Size);
		int_counting_items = InsertionSort(ptr_int_array, int_Size);
		int_counting_items = dumpArray(ptr_int_array, int_Size);
		int_counting_items = viewArray(ptr_int_array, int_Size);
		int_counting_items = BinarySearch(ptr_int_array, int_Size);

		int_counting_items = initializeArray(ptr_int_array, int_Size);
		int_counting_items = captureArray(ptr_int_array, int_Size);
		int_counting_items = SelectionSort(ptr_int_array, int_Size);
		int_counting_items = dumpArray(ptr_int_array, int_Size);
		int_counting_items = viewArray(ptr_int_array, int_Size);
		int_counting_items = BinarySearch(ptr_int_array, int_Size);

		free(ptr_int_array);

		return V_ZERO;
	}
