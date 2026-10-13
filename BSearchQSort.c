/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic Work Constants. */
#define	V_ZERO	0

/* Function that compares two elements of an array. */
int compare(const void *const lhs, const void *const rhs)
	{
		return (*(int *) lhs) - (*(int *) rhs);
	}

/* Function that prints the array elements one by one. */
void print_array(const int *array, size_t size)
	{
		printf("Print the elements of the array.\n");
		printf("From: [%p] to: [%p].\n", (void *) array, (void *) (array + size));

		while (size--)
			printf("[%i]\t", *(array++));

		printf("\n");
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int element = V_ZERO;
		int array[] = {13, 2, 19 ,23 , 43 ,59 , 97, 17, 31, 73, 5, 71, 61, 29, 41, 11, 89, 83, 3, 103, 7, 37, 67, 79, 101, 47, 53};
		const size_t array_size = sizeof(array);
		const size_t data_size = sizeof(*array);
		const size_t array_num_elements = array_size / data_size;

		printf("Array Sorting and Searching Program.\n");

		/* The original array is printed. */
		printf("\nOriginal Array.\n");
		print_array(array, array_num_elements);

		/* The array sorted in ascending order is shown. */
		printf("\nSorted Array.\n");
		qsort(array, array_num_elements, data_size, compare);
		print_array(array, array_num_elements);

		/* An element to search for in the array is requested. */
		printf("\nItem to search for.\n");
		printf("> Enter an item to track: ");
		scanf("%d", &element);

		/* The binary search function is called to locate it. */
		printf("\nBinary Search Result.\n");
		int *ptr_index = (int *) bsearch(&element, array, sizeof(array) / sizeof(*array), sizeof(*array), compare);

		/* It is validated whether the returned pointer holds a valid memory address. */
		if (ptr_index)
			printf("Element: [%d] found in address: [%p] with position: [%ld] = [%d].\n", element, (void *) ptr_index, (ptr_index - array), *ptr_index);
		else
			printf("Element: [%d] was not found!\n", element);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended!\n");

		return V_ZERO;
	}
