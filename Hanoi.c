/**************** Hanoi Towers recursive generator. **************
 ** Source Code:	Hanoi.c					**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Wednesday, December 31, 2025.		**
 ** Purpose:		The purpose of this program is, through	**
 **			recursive calls, to solve the enigma of **
 **			the Towers of Hanoi, which basically	**
 **			consists of moving a stack of disks	**
 **			ordered from smallest to largest	**
 **			starting from the top of a pole,	**
 **			and moving them to two adjacent poles,	**
 **			fulfilling as a fundamental restriction	**
 **			that when the discs are moved, a smaller**
 **			one always remains on top of a larger	**
 **			one, that is, there cannot be larger	**
 **			discs on smaller discs.			**
 **			This program performs the necessary	**
 **			iterations to move a certain number of	**
 **			discs on a pillar towards another	**
 **			following the algorithm of the enigma	**
 **			of the Towers of Hanoi.			**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Symbolic constants of minimum and maximum limits.
#define	V_MINUS_ONE		-1
#define	V_ONE			1
#define	V_ONE_HUNDRED		100.0
#define	V_TWO			2
#define	V_ZERO			0

//Work Symbolic Constants.
#define	FIRST_TOWER		'A'
#define	SECOND_TOWER		'B'
#define	THIRD_TOWER		'C'

//Minimum and maximum number of dishes on the pillars of the Towers of Hanoi.
#define	V_LOWER_LIMIT_DISHES	1
#define	V_UPPER_LIMIT_DISHES	28

/*****************************************************************
 ** Function:           int int_potency				**
 **				(const int int_x,		**
 **				 const int int_y).		**
 ** Explanation:        Returns a base coefficient raised to the**
 **                     specified power recursively by means of **
 **                     successive multiplications or divisions.**
 **                                                             **
 **                     This function can also be programmed    **
 **                     recursively in the form:                **
 **								**
 **                             (int_exp > V_ZERO) ?            **
 **                                     int_potency(int_base,   **
 **                                     int_exp + V_MINUS_ONE)  **
 **                                     * int_base :            **
 **                             (int_exp == V_ZERO) ? V_ONE :   **
 **                             (int_exp < V_ZERO) ?            **
 **                                     int_potency(int_base,   **
 **                                     int_exp + V_ONE)        **
 **                                     / int_base :            **
 **                                     V_ONE;                  **
 **								**
 ** Input Parms:        const int int_x.			**
 **			const int int_y.			**
 ** Output Parms:       None.                                   **
 ** Result:             The base raised to a positive power     **
 **                     results in a series of products in      **
 **                     sequence from 1 to 'n', while a base    **
 **                     raised to a negative power results in a **
 **                     series of quotients in sequence from 1  **
 **                     to '-n' .                               **
*****************************************************************/
int int_potency(const int int_x, const int int_y)
	{
		return	(int_y > V_ZERO) ? int_potency(int_x, int_y + V_MINUS_ONE) * int_x :
			(int_y == V_ZERO) ? V_ONE :
			(int_y < V_ZERO) ? int_potency(int_x, int_y + V_ONE) / int_x : V_ONE;
	}

/*****************************************************************
 ** Function:		int int_HanoiTowers			**
 **				(const int int_num_dishes,	**
 **				 const char chr_first_tower,	**
 **				 const char chr_second_tower,	**
 **				 const char chr_third_tower,	**
 **				 const int 			**
 **					int_num_maximum_cycles).**
 ** Explanation:	In this function, the recursive		**
 **			iterations necessary to solve the	**
 **			enigma of the Towers of Hanoi are	**
 **			carried out, which consists of moving a	**
 **			series of plates arranged from smallest	**
 **			to largest starting from the top and	**
 **			placed on a given pillar, towards two	**
 **			underlying poles, in such a way that in	**
 **			the last one they are equally ordered	**
 **			as in their origin.			**
 **			The fundamental rule to follow in this	**
 **			algorithm is that as the plates are	**
 **			moved, a smaller one cannot be below a	**
 **			larger one, so the three pillars or	**
 **			poles must validate these conditions.	**
 ** Input Parms:	const int int_num_dishes,		**
 **			const char chr_first_tower,		**
 **			const char chr_second_tower,		**
 **			const char chr_third_tower,		**
 **			const int int_num_maximum_cycles.	**
 ** Output Parms:	None.					**
 ** Result:		Function 'int_HanoiTowers' to perform	**
 **			and account for iterations of the disks	**
 **			between the towers.			**
 ****************************************************************/
int szt_HanoiTowers(const int int_num_dishes, const char chr_first_tower, const char chr_second_tower, const char chr_third_tower, const int int_num_maximum_cycles)
	{
		/* ----------------------------------------------------	--
		 * The movement of the rings begins with three rooks,	--
		 * numbered from the first (1st) to the third (3rd) and	--
		 * their cycles are counted.				--
		 * ----------------------------------------------------	*/
		static int int_num_loops_HanoiTowers = V_ZERO;
		double dbl_perc_advantage = ((double)int_num_loops_HanoiTowers / (double)(int_num_maximum_cycles + V_MINUS_ONE)) * (double) V_ONE_HUNDRED;

		/* ----------------------------------------------------	--
		 * Count the number of cycles and their percentage that	--
		 * they are taken from the calculations of the Towers	--
		 * of Hanoi.						--
		 * ---------------------------------------------------- */
		int_num_loops_HanoiTowers++;

		/* ----------------------------------------------------	--
		 * It is validated for recursions if the number of	--
		 * disks is always greater than unity and less than to	--
		 * the maximum calculated cycles.			--
		 * ----------------------------------------------------	*/
		if (int_num_dishes > V_ONE && int_num_loops_HanoiTowers < int_num_maximum_cycles)
			{
				/* ------------------------------------------------------------	--
				 * The antlers from which they are going to be extracted are	--
				 * inverted the rings, now it is the 1st, the 3rd and the 2nd.	--
				 * ------------------------------------------------------------	*/
				szt_HanoiTowers(int_num_dishes + V_MINUS_ONE, chr_first_tower, chr_third_tower, chr_second_tower, int_num_maximum_cycles);

				/* ------------------------------------------------------------	--
				 * This message prints while there are rings on it of the	--
				 * current flagpole to be mobilized.				--
				 * ------------------------------------------------------------	*/
				printf("Motion: [%10.d].\t[%5.2lf]%% advanced.\tRing #: [%2.d].\tFrom antler: [%c] to [%c].\t\r", int_num_loops_HanoiTowers, dbl_perc_advantage, int_num_dishes, chr_first_tower, chr_third_tower);

				/* ------------------------------------------------------------	--
				 * The antlers from which they are going to be extracted are	--
				 * inverted the rings, now it is the 2nd, the 1st and the 3rd.	--
				 * ------------------------------------------------------------	*/
				szt_HanoiTowers(int_num_dishes + V_MINUS_ONE, chr_second_tower, chr_first_tower, chr_third_tower, int_num_maximum_cycles);
			}

		/* ------------------------------------------------------------	--
		 * This message is printed if the last ring of the block that	--
		 * you want to move from a specific pole.			--
		 * ------------------------------------------------------------	*/
		printf("Motion: [%10.d].\t[%5.2lf]%% advanced.\x20\tRing #: [%2.d].\tFrom antler: [%c] to [%c]. \r", int_num_loops_HanoiTowers, dbl_perc_advantage, int_num_dishes, chr_first_tower, chr_third_tower);

		return int_num_loops_HanoiTowers;
	}


/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function, a series of discs**
 **			stacked from largest to smallest on a	**
 **			given shaft move towards two adjacent	**
 **			shafts, in such a way that a disc of a	**
 **			smaller size must necessarily be placed	**
 **			on top of a disc of a larger size, thus,**
 **			all the discs from the initial stack	**
 **			must be arranged in the same way in the	**
 **			final stack.				**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Main program that moves the plates	**
 **			between the shafts that make up the	**
 **			algorithm of the Towers of Hanoi enigma.**
*****************************************************************/
int main()
	{
		/* Declaration of numerical work variables. */
		int int_num_dishes = V_ZERO;
		int int_num_loops_HanoiTowers = V_ZERO;
		int int_num_maximum_cycles_HanoiTowers = V_ZERO;

		/* Initial presentation headers. */
   		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+     Towers of Hanoi Algorithm.    +\n");
   		printf("+===|====+===|====+===|====+===|====+\n");
		printf("Rings to move between [%2.d] and [%2.d]: ", V_LOWER_LIMIT_DISHES, V_UPPER_LIMIT_DISHES);
   		scanf("%d", &int_num_dishes);

		/* ------------------------------------------------------------	--
		 * It is validated that the number of disks is in a range	--
		 * allowable and tolerable by the processor.			--
		 * ------------------------------------------------------------	*/
		if (int_num_dishes >= V_LOWER_LIMIT_DISHES && int_num_dishes <= V_UPPER_LIMIT_DISHES)
			{
				/* ------------------------------------------------------------	--
				 * The maximum number of processor cycles is determined to 	--
				 * solve the Towers of Hanoi with 'n' discs.			--
				 * ------------------------------------------------------------	*/
				int_num_maximum_cycles_HanoiTowers = int_potency(V_TWO, int_num_dishes);	//(2^N)

				/* ------------------------------------------------------------	--
				 * The number of movements that have been made is displayed on	--
				 * the screen required to move the different disks.		--
				 * ------------------------------------------------------------	*/
				printf("\n");
				printf("+===|====+===|====+===|====+===|====+\n");
				printf("+  Hanoi Towers Algorithm Results.  +\n");
				printf("+===|====+===|====+===|====+===|====+\n");
				printf("| [%10.d] Movements with [%2.d] discs.\n", int_num_maximum_cycles_HanoiTowers + V_MINUS_ONE, int_num_dishes);
				printf("+===|====+===|====+===|====+===|====+\n");

				/* ------------------------------------------------------------	--
				 * The 'HanoiTowers' function is called and returns as a result	--
				 * the number of cycles to solve them.				--
				 * ------------------------------------------------------------	*/
				int_num_loops_HanoiTowers = szt_HanoiTowers(int_num_dishes, FIRST_TOWER, SECOND_TOWER, THIRD_TOWER, int_num_maximum_cycles_HanoiTowers);

				/* ------------------------------------------------------------	--
				 * The screen displays how many effective movements were made	--
				 * with the specified number of disks.				--
				 * ------------------------------------------------------------	*/
				printf("\n\n");
				printf("+===|====+===|====+===|====+===|====+\n");
				printf("+  Hanoi Towers Algorithm Outcome.  +\n");
				printf("+===|====+===|====+===|====+===|====+\n");
				printf("| [%10.d] Movements with [%2.d] displaced discs.\n", int_num_loops_HanoiTowers, int_num_dishes);
				printf("+===|====+===|====+===|====+===|====+\n");
			}
		else
			/* ------------------------------------------------------------	--
			 * The entered value is outside the allowed range.		--
			 * The more disks, the greater the probability that the		--
			 * algorithm process never ends.				--
			 * ------------------------------------------------------------	*/
			printf("Mistake! Value: [%2.d] is not in the range of [%2.d] and [%2.d].\n", int_num_dishes, V_LOWER_LIMIT_DISHES, V_UPPER_LIMIT_DISHES);

		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
