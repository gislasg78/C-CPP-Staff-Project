#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO  	0

void swap_values(int*, int *);


int BubbleSort(int *ptr_int_array_numbers, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		printf("Bubble Sort.\n");

		for (int int_idx = V_ZERO; int_idx < int_Size + V_MINUS_ONE; int_idx++)
			for (int int_ind = int_idx + V_ONE; int_ind < int_Size; int_ind++)
				if (ptr_int_array_numbers[int_idx] > *(ptr_int_array_numbers + int_ind))
					{
						int_counting_items++;
						swap_values(&ptr_int_array_numbers[int_idx], &ptr_int_array_numbers[int_ind]);
					}

		return int_counting_items;
	}

int *createArray(int **ptr_int_matrix_numbers, const int int_Size)
	{
		int *ptr_int_array_numbers = NULL;

		if (ptr_int_matrix_numbers)
			if (ptr_int_array_numbers = (int *) malloc(int_Size * sizeof(int)))
				*ptr_int_matrix_numbers = ptr_int_array_numbers;
			else
				{
					perror("Mistake! Insufficient memory space for allocation...");
					exit(EXIT_FAILURE);
				}

		return ptr_int_array_numbers;
	}

int captureArray(int *ptr_int_array_numbers, const int int_Size)
	{
		int int_counting_items = V_ZERO;
		int int_data = V_ZERO;

		if (ptr_int_array_numbers)
			{
				for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
					{
						printf("Enter a data #[%d] of [%d] : ", int_idx, int_Size);
						scanf("%d", &int_data);

						ptr_int_array_numbers[int_idx] = int_data;
					}

				printf("\n");
			}

		return int_counting_items;
	}

int initializeArray(int *ptr_int_array_numbers, const int int_Size)
	{
		if (ptr_int_array_numbers)
			for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
				*(ptr_int_array_numbers + int_idx) = V_ZERO;
	}

int InsertionSort(int *ptr_int_array_numbers, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		int int_aux = V_ZERO;
		int int_pos = V_ZERO;

		printf("Insertion Sort.\n");

		for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
			{
				for (int_pos = int_idx, int_aux = ptr_int_array_numbers[int_idx];
					(int_pos > V_ZERO) && (ptr_int_array_numbers[int_pos + V_MINUS_ONE] > int_aux); int_pos--)
						{
							int_counting_items++;
							ptr_int_array_numbers[int_pos] = ptr_int_array_numbers[int_pos + V_MINUS_ONE];
						}

				ptr_int_array_numbers[int_pos] = int_aux;
			}

		return int_counting_items;

	}

int SelectionSort(int *ptr_int_array_numbers, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		int int_aux = V_ZERO;
		int int_min = V_ZERO;

		printf("Selection Sort.\n");

		for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
			{
				int_min = int_idx;

				for (int int_ind = int_idx + V_ONE; int_ind < int_Size; int_ind++)
					if (ptr_int_array_numbers[int_ind] < ptr_int_array_numbers[int_min])
						int_min = int_ind;

				int_counting_items++;
				swap_values(ptr_int_array_numbers + int_idx, ptr_int_array_numbers + int_min);
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

int viewArray(int *ptr_int_array_numbers, const int int_Size)
	{
		int int_counting_items = V_ZERO;

		if (ptr_int_array_numbers)
			for (int int_idx = V_ZERO; int_idx < int_Size; int_idx++)
				printf("#[%d].\t=\t[%d].\n", int_counting_items++, ptr_int_array_numbers[int_idx]);

		printf("\n");

		return int_counting_items;
	}

int main()
	{
		int int_counting_items = V_ZERO;
		int *ptr_int_array_numbers = NULL;
		int int_Size = V_ZERO;

		printf("Enter the size of array: ");
		scanf("%d", &int_Size);

		ptr_int_array_numbers = createArray(&ptr_int_array_numbers, int_Size);

		int_counting_items = initializeArray(ptr_int_array_numbers, int_Size);
		int_counting_items = captureArray(ptr_int_array_numbers, int_Size);
		int_counting_items = BubbleSort(ptr_int_array_numbers, int_Size);
		int_counting_items = viewArray(ptr_int_array_numbers, int_Size);

		int_counting_items = initializeArray(ptr_int_array_numbers, int_Size);
		int_counting_items = captureArray(ptr_int_array_numbers, int_Size);
		int_counting_items = InsertionSort(ptr_int_array_numbers, int_Size);
		int_counting_items = viewArray(ptr_int_array_numbers, int_Size);

		int_counting_items = initializeArray(ptr_int_array_numbers, int_Size);
		int_counting_items = captureArray(ptr_int_array_numbers, int_Size);
		int_counting_items = SelectionSort(ptr_int_array_numbers, int_Size);
		int_counting_items = viewArray(ptr_int_array_numbers, int_Size);

		free(ptr_int_array_numbers);

		return V_ZERO;
	}
