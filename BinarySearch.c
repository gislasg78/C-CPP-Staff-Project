/* Binary Search */
#include <stdio.h>

#define	NULL_CHARACTER	'\0'
#define	CARRIAGE_RETURN	'\n'

#define	V_168		168
#define	V_1000		1000

#define	V_MINUS_ONE	-1
#define	V_TWO		2
#define	V_ONE		1
#define	V_ZERO		0

static int array[] = 	{
			2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
			59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131,
			137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
			227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311,
			313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
			419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
			509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
			617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719,
			727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
			829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
			947, 953, 967, 971, 977, 983, 991, 997.
			};

int BinarySearch(int array[], const int value, const int bottom, const int top, int *pos)
	{
		int middle = (bottom + top) / V_TWO;
		*pos = V_MINUS_ONE;

		if ((bottom <= top))
			{
				if (array[middle] == value)
					*pos = middle;

				if (array[middle] > value)
					BinarySearch(array, value, bottom, middle - V_ONE, pos);

				if (array[middle] < value)
					BinarySearch(array, value, middle + V_ONE, top, pos);
			}

		return *pos;
	}

int main()
	{
		char c = NULL_CHARACTER;
		int idx = V_ZERO, position = V_ZERO, value = V_ZERO;
		int size = sizeof(array) / sizeof(array[V_ZERO]);

		printf("Binary Search.\n");
		printf("Enter a value (%d - %d) to search for: ", V_ZERO, V_1000);

		if (scanf("%d", &value))
			printf("\nInput value: [%d]. OK!\n", value);
		else
			{
				scanf("%*[^\n]%*c");
				while ((c = getchar() != CARRIAGE_RETURN && c != EOF));
			}

		position = BinarySearch(array, value, V_ZERO, size - V_ONE, &position);

		if (position >= V_ZERO && position < size)
			{
				printf("\n");
				printf("+---+----+---+----+---+\n");
				printf("|  Search successful. |\n");
				printf("+---+----+---+----+---+\n");
				printf("| * Element  : [%d].\n", value);
				printf("| * Position : [%d].\n", position);
				printf("| * Content  : [%d].\n", array[position]);
				printf("+---+----+---+----+---+\n");
				printf("\n");
			}
		else
			printf("\nThe searched value: [%d] was not found.\n", value);

		return V_ZERO;
	}
