/* The primary purpose of this program is to demonstrate the use of the 'qsort' and 'bsearch' functions
   in the C programming language: specifically, to sort an array using the QuickSort method
   and subsequently perform a binary search for a given element within that now-organized array. */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'

/* Symbolic Work Constants. */
#define	V_ARRAY_SIZE	261
#define	V_ZERO		0

/* Function that compares two elements of an array. */
int compare(const void *const lhs, const void *const rhs)
	{
		return (*((int *) lhs) > *((int *) rhs)) - (*((int *) lhs) < *((int *) rhs));
	}

/* Function that performs a specified pause with a warning message. */
char getPause(const char *str_Message)
	{
		/* Preliminary working variables. */
		char chr_key = NULL_CHARACTER;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Header message. */
		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if ((int_fields = scanf("%c%*c%n", &chr_key, &int_chars)))
			{
				/* Get a correct character value. */
				printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, chr_key, chr_key, chr_key, int_chars);
			}
		else
			{
				/* Check whether an End-of-File condition occurred during keyboard data input. */
				if (feof(stdin))
					{
						fprintf(stderr, "\nEnd of File (EOF) detected in data entry!\n");
						clearerr(stdin);
						fflush(stdin);
					}

				/* Get an incorrect entried value. */
				fputs("\nThe value entered is not valid!\n", stderr);
				fprintf(stderr, "Press ENTER to continue...");
				scanf("%*[^\n]%*c");

				/* Clear the input buffer until a carriage return followed by a line feed, or an end-of-file, is encountered. */
				fputs("\nPress the ENTER key to clear the input buffer...", stderr);
				while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);

				chr_key = (char) int_key;
			}

		/* Return of key value. */
		return chr_key;
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

		/* I’m sorting out the numbers, which are currently jumbled and disorganized. */
		static int array[V_ARRAY_SIZE] = {
						727, 3, 1097, 43, 887, 233, 1481, 71, 419, 997,
						157, 1223, 541, 13, 1063, 349, 809, 191, 1453, 617,
						29, 1321, 467, 853, 101, 1289, 577, 1489, 223, 761,
						1123, 5, 1307, 383, 1039, 1499, 311, 941, 67, 1153,
						487, 1373, 211, 827, 599, 139, 1069, 443, 1237, 19,
						881, 263, 1423, 661, 109, 1319, 353, 953, 239, 1217,
						7, 1187, 433, 1297, 743, 47, 1361, 283, 911, 103,
						1483, 397, 1277, 31, 1051, 691, 1459, 521, 113, 1381,
						797, 181, 2, 1429, 359, 1009, 251, 1327, 463, 1201, 89,
						1447, 547, 131, 1249, 619, 173, 107, 1283, 571, 929,
						17, 1163, 401, 1291, 739, 53, 1439, 293, 919, 127,
						1487, 409, 1279, 37, 1049, 683, 1451, 509, 97, 1399,
						821, 193, 1427, 367, 1013, 257, 1303, 457, 1193, 83,
						1433, 557, 137, 1231, 613, 179, 1091, 593, 971, 11,
						1171, 421, 1301, 751, 59, 143, 307, 937, 131, 1103,
						877, 197, 141, 347, 1021, 269, 129, 449, 1181, 73,
						1409, 563, 151, 1259, 631, 199, 1093, 601, 977, 23,
						1129, 431, 1309, 769, 61, 1471, 331, 967, 163, 1117,
						883, 199, 1429, 373, 1019, 271, 1283, 461, 1193, 79,
						1447, 563, 137, 1231, 607, 179, 1091, 587, 983, 41,
						1151, 439, 1297, 757, 53, 1439, 317, 947, 167, 1109,
						863, 193, 1411, 379, 1021, 277, 1291, 457, 1187, 83,
						1459, 569, 149, 1229, 643, 199, 1097, 607, 991, 31,
						1171, 443, 1303, 773, 47, 1481, 337, 953, 173, 1129,
						857, 181, 1423, 389, 1031, 281, 1297, 479, 1199, 89,
						1453, 571, 139, 1237, 647, 211, 1109, 613, 997, 37
					};

		/* Calculation of the static dimensions of the preceding array. */
		const size_t array_size = sizeof(array);
		const size_t data_size = sizeof(*array);
		const size_t array_num_elements = array_size / data_size;

		printf("Array Sorting and Searching Program.\n");

		/* The original array is printed. */
		printf("\nOriginal Array.\n");
		print_array(array, array_num_elements);
		printf("[%lu] Output results generated.\n", array_num_elements);
		getPause("Press the ENTER key to continue...");

		/* The array sorted in ascending order is shown. */
		printf("\nSorted Array.\n");
		qsort(array, array_num_elements, data_size, compare);
		print_array(array, array_num_elements);
		printf("[%lu] Output results sorted.\n", array_num_elements);
		getPause("Press the ENTER key to continue...");

		/* An element to search for in the array is requested. */
		printf("\nItem to search for.\n");
		printf("> Enter an item to track: ");
		scanf("%d%*c", &element);

		/* The binary search function is called to locate it. */
		printf("\nBinary Search Result.\n");
		int *ptr_index = (int *) bsearch(&element, array, sizeof(array) / sizeof(*array), sizeof(*array), compare);
		printf("[%lu] Output results searched.\n", array_num_elements);
		getPause("Press the ENTER key to continue...");

		/* It is validated whether the returned pointer holds a valid memory address. */
		if (ptr_index)
			printf("\nElement: [%d] found in address: <%p> with position: [%ld] = [%x] : {%d}.\n", element, (void *) ptr_index, (ptr_index - array), *ptr_index, *ptr_index);
		else
			printf("\nElement: [%x] : [%d] was not found!\n", element, element);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended!\n");
		getPause("Press the ENTER key to continue...");

		return V_ZERO;
	}
