#include <stdio.h>

#define	V_CHR_UPPER_Y	0x59
#define	V_CHR_LOWER_Y	0x79
#define V_ZERO  	0

int main()
	{
		static int lista[] =
				{
				2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
				101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
				211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
				307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
				401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
				503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
				601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
				701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
				809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
				907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
				};
		int *plista = lista,
			*pa_lista[] =
				{
				lista + 0, lista + 1, lista + 2, lista + 3, lista + 4,
				lista + 5, lista + 6, lista + 7, lista + 8, lista + 9,
				lista + 10, lista + 11, lista + 12, lista + 13, lista + 14,
				lista + 15, lista + 16, lista + 17, lista + 18, lista + 19,
				lista + 20, lista + 21, lista + 22, lista + 23, lista + 24,
				lista + 25, lista + 26, lista + 27, lista + 28, lista + 29,
				lista + 30, lista + 31, lista + 32, lista + 33, lista + 34,
				lista + 35, lista + 36, lista + 37, lista + 38, lista + 39,
				lista + 40, lista + 41, lista + 42, lista + 43, lista + 44,
				lista + 45, lista + 46, lista + 47, lista + 48, lista + 49,
				lista + 50, lista + 51, lista + 52, lista + 53, lista + 54,
				lista + 55, lista + 56, lista + 57, lista + 58, lista + 59,
				lista + 60, lista + 61, lista + 62, lista + 63, lista + 64,
				lista + 65, lista + 66, lista + 67, lista + 68, lista + 69,
				lista + 70, lista + 71, lista + 72, lista + 73, lista + 74,
				lista + 75, lista + 76, lista + 77, lista + 78, lista + 79,
				lista + 80, lista + 81, lista + 82, lista + 83, lista + 84,
				lista + 85, lista + 86, lista + 87, lista + 88, lista + 89,
				lista + 90, lista + 91, lista + 92, lista + 93, lista + 94,
				lista + 95, lista + 96, lista + 97, lista + 98, lista + 99,
				lista + 100, lista + 101, lista + 102, lista + 103, lista + 104,
				lista + 105, lista + 106, lista + 107, lista + 108, lista + 109,
				lista + 110, lista + 111, lista + 112, lista + 113, lista + 114,
				lista + 115, lista + 116, lista + 117, lista + 118, lista + 119,
				lista + 120, lista + 121, lista + 122, lista + 123, lista + 124,
				lista + 125, lista + 126, lista + 127, lista + 128, lista + 129,
				lista + 130, lista + 131, lista + 132, lista + 133, lista + 134,
				lista + 135, lista + 136, lista + 137, lista + 138, lista + 139,
				lista + 140, lista + 141, lista + 142, lista + 143, lista + 144,
				lista + 145, lista + 146, lista + 147, lista + 148, lista + 149,
				lista + 150, lista + 151, lista + 152, lista + 153, lista + 154,
				lista + 155, lista + 156, lista + 157, lista + 158, lista + 159,
				lista + 160, lista + 161, lista + 162, lista + 163, lista + 164,
				lista + 165, lista + 166, lista + 167,
				};

		char chr_key = V_CHR_UPPER_Y;

		printf("Pointer naming practice.\n");
		printf("Dump of the first 1000 prime numbers.\n");

		for (int idx = V_ZERO; (idx < (sizeof(lista)/sizeof(lista[V_ZERO]))) && (chr_key == V_CHR_LOWER_Y || chr_key == V_CHR_UPPER_Y); idx++)
			{
				printf("\n");
				printf("#: [%d].\n", idx);
				printf("Addresses:\n");
				printf("* lista    : {%p}.\n", &lista);
				printf("             {%p} : [%p] = [%p].\n", lista, &lista[idx], lista + idx);
				printf("* plista   : {%p}.\n", &plista);
				printf("             [%p] : [%p] = [%p].\n", plista, &plista[idx], plista + idx);
				printf("* pa_lista : {%p}.\n", &pa_lista);
				printf("             {%p} : [%p] = [%p].\n", pa_lista, &pa_lista[idx], pa_lista + idx);
				printf("\n");
				printf("Values:\n");
				printf("- lista    : {%d} : [%d] = [%d].\n", *lista, lista[idx], *(lista + idx));
				printf("- plista   : {%d} : [%d] = [%d].\n", *plista, plista[idx], *(plista + idx));
				printf("- pa_lista : {%p} : [%p] = [%p].\n", *pa_lista, pa_lista[idx], *(pa_lista + idx));
				printf("             [%d].\n", *pa_lista[idx]);
				printf("\n");

				printf("Do you want to continue viewing more records (y/n)? : ");
				scanf("%*c%[^\n]", &chr_key);

				printf("[%c] : [%d] : [%o] : [%x].\n", chr_key, chr_key, chr_key, chr_key);
			}

		return V_ZERO;
	}
