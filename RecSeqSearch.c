/* Standard libraries for general use. */
#include <stdio.h>

/* Symbolic work constants. */
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

//Function that performs a recursive sequential search for a given element in a given array.
int SequentialSearchRecursive(const int array[], const int start, const int finish, const int target_key, const int bottom, const int top, int *pos, int *iters)
	{
		/* Validates that the start and end ranges are within the bounds of the minimum and maximum array index. */
		if ((start >= bottom && start <= top))
			if ((finish >= bottom && finish <= top))
				/* Base case: if we have reached the final index. */
				if (*pos >= start && *pos <= finish)
					/* If the element at index 'start' is the one we are looking for, return the obtained index. */
					if (array[*pos] == target_key)
						/* Print the result returned by the recursive sequential search function. */
						printf("\nThe element: [%d] from: [%d] to [%d] was located in the position: [%d] = {%d} with: [%d] spins.\n", target_key, start, finish, *pos, array[*pos], *iters);
					else
						{
							/* Recursive call to find the element at the next incremented index. */
							(*iters)++; (*pos)++;
							SequentialSearchRecursive(array, start, finish, target_key, bottom, top, pos, iters);
						}
				else
					{
						printf("\nThe element: [%d] was not located.\n", target_key);
						printf("Highest position reached: [%d]. Out of range between: [%d] and [%d] with: [%d] turns.\n", *pos, start, finish, *iters);
					}
			else
				printf("\nThe finish index: [%d] are out of range between: [%d] and [%d].\n", finish, top, bottom);
		else
			printf("\nThe start index: [%d] are out of range between: [%d] and [%d].\n", start, top, bottom);

		return (*pos = (*pos >= start && *pos <= finish) ? *pos : V_MINUS_ONE);
	}

int main()
	{
		/* Preliminary working variables. */
		int iterations = V_ZERO, number_elements = V_ZERO, target_key = V_ZERO;
		int position = V_ZERO, start = V_ZERO, finish = V_ZERO;

		/* Request the quantity 'n' of elements that the array of integers will contain. */
		printf("Recursive sequential search program of a variable-length array.\n");
		printf("Enter the number of elements in the array: ");
		scanf("%d", &number_elements);

		/* Variable Length Array (VLA). */
		int array[number_elements];			//Runtime fixing of the array size on the stack.
		int size = sizeof(array)/sizeof(array[V_ZERO]);	//Total number of elements in the array.

		/* Request each and every one of the elements that will be used to fill the arrangement. */
		printf("\nCapturing [%d] array elements...\n", number_elements);
		for (int idx = V_ZERO; idx < number_elements; idx++)
			{
				scanf("%d", &array[idx]);
			}

		/* Request the element you want to search for in the array. */
		printf("\nEnter the content of the item you want to search for: ");
		scanf("%d", &target_key);

		/* The start and end indexes of the search subrange are requested,
		   without exceeding the minimum and maximum limits of the array. */
		printf("\n");
		printf("Enter the start  index (between: [%d] and [%d]) : ", V_ZERO, size + V_MINUS_ONE);
		scanf("%d", &start);

		printf("Enter the finish index (between: [%d] and [%d]) : ", V_ZERO, size + V_MINUS_ONE);
		scanf("%d", &finish);

		/* Initial call to the recursive sequential search function (to itself). */
		position = start;
		position = SequentialSearchRecursive(array, start, finish, target_key, V_ZERO, size + V_MINUS_ONE, &position, &iterations);

		return V_ZERO;
	}
