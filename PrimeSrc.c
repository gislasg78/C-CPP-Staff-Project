#include <stdio.h>

#define V_MIN_ENTRIES	000
#define V_MIN_LIMIT     000
#define V_MAX_ENTRIES   167
#define V_MAX_LIMIT     999
#define	V_TOTAL_ENTRIES	168

#define V_ZERO          0

int int_sequential_search(int int_number, int int_start_pos, int int_prime_numbers[]);

static int int_prime_numbers[V_TOTAL_ENTRIES] =
				{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
				101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
				211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
				307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
				401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
				503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
				601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
				701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
				809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
				907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int main()
	{
		int int_idx = V_ZERO, int_start_pos = V_ZERO, int_number = V_ZERO;

		printf("Searching for a prime number.\n");
		printf("Prime number to find [%d] to [%d]: ", V_MIN_LIMIT, V_MAX_LIMIT);
		scanf("%i", &int_number);
		printf("Starting position [%d] to [%d]: ", V_MIN_ENTRIES, V_MAX_ENTRIES);
		scanf("%i", &int_start_pos);

		if (int_number >= V_MIN_LIMIT && int_number <= V_MAX_LIMIT)
			{
				int_idx = int_sequential_search(int_number, int_start_pos, int_prime_numbers);

				if (int_start_pos >= V_MIN_ENTRIES && int_start_pos <= V_MAX_ENTRIES)
					{
						printf("\n");
						printf("Starting position: [%d].\n", int_start_pos);

						if (int_idx >= V_ZERO && int_idx <= V_MAX_ENTRIES)
							{
								printf("Fenced element located: [%d] at position: [%d].\n", int_number, int_idx);
								printf("Approximate data located: [%d].\n", int_prime_numbers[int_idx]);
							}
						else
							{
								printf("Element: [%d] not found!\n", int_number);
								printf("Highest position achieved: [%d].\n", int_idx);
							}
					}
				else
					printf("The start index: [%d] is out of bounds between: [%d] and [%d].\n", int_start_pos, V_MIN_ENTRIES, V_MAX_ENTRIES);
			}
		else
			printf ("The value: [%d] is out of bounds between: [%d] and [%d].\n", int_number, V_MIN_LIMIT, V_MAX_LIMIT);

		return V_ZERO;
	}

int int_sequential_search(int int_number, int int_start_pos, int int_prime_numbers[])
	{
		int int_idx = V_ZERO;

		for (int_idx = int_start_pos; int_idx < V_TOTAL_ENTRIES && int_prime_numbers[int_idx] < int_number; int_idx++);

		return(int_idx);
	}
