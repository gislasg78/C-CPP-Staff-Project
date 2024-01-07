/**************** Hanoi Towers recursive generator. **************
 ** Source Code:	Hanoi.c					**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
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
#define V_MINUS_ONE	-1
#define V_ONE		1
#define V_ONE_HUNDRED	100.0
#define V_TWO		2
#define V_ZERO		0

//Work Symbolic Constants.
#define FIRST_TOWER	'A'
#define SECOND_TOWER	'B'
#define THIRD_TOWER	'C'

//Minimum and maximum number of dishes on the pillars of the Towers of Hanoi.
#define V_MAX_DISHES	28
#define V_MIN_DISHES	1

/*****************************************************************
 ** Function:           static size_t szt_potency.		**
 ** Explanation:	The purpose of this function is to	**
 **			return a number raised to a given power,**
 **			through recursive iterations, calling	**
 **			the function itself and multiplying a	**
 **			base 'x' by an exponent 'y' in a	**
 **			cumulative manner.			**
 ** Input Parms:        const size_t szt_x,			**
 **			const size_t szt_y.			**
 ** Output Parms:       None.                                   **
 ** Result:		'potency' function that returns a number**
 **			raised to at a certain power.		**
 ****************************************************************/
static size_t szt_potency(const size_t szt_x, const size_t szt_y)
	{
		return (szt_y < V_ONE) ? V_ONE : szt_x * szt_potency(szt_x, szt_y + V_MINUS_ONE);
	}

/*****************************************************************
 ** Function:		static size_t szt_HanoiTowers		**
 **				(const size_t szt_num_dishes,	**
 **				 const char chr_first_tower,	**
 **				 const char chr_second_tower,	**
 **				 const char chr_third_tower,	**
 **				 const size_t 			**
 **					szt_num_maximum_cycles).**
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
 ** Input Parms:	const size_t szt_num_dishes,		**
 **			const char chr_first_tower,		**
 **			const char chr_second_tower,		**
 **			const char chr_third_tower,		**
 **			const size_t szt_num_maximum_cycles.	**
 ** Output Parms:	None.					**
 ** Result:		Function 'szt_HanoiTowers' to perform	**
 **			and account for iterations of the disks	**
 **			between the towers.			**
 ****************************************************************/
static size_t szt_HanoiTowers(const size_t szt_num_dishes, const char chr_first_tower, const char chr_second_tower, const char chr_third_tower, const size_t szt_num_maximum_cycles)
	{
		/* ----------------------------------------------------	--
		 * The movement of the rings begins with three rooks,	--
		 * numbered from the first (1st) to the third (3rd) and	--
		 * their cycles are counted.				--
		 * ----------------------------------------------------	*/
		static size_t szt_num_loops_HanoiTowers = V_ZERO;
		double dbl_perc_advantage = V_ZERO;

		/* ----------------------------------------------------	--
		 * Count the number of cycles and their percentage that	--
		 * they are taken from the calculations of the Towers	--
		 * of Hanoi.						--
		 * ---------------------------------------------------- */
		szt_num_loops_HanoiTowers++;
		dbl_perc_advantage = (	(double) szt_num_loops_HanoiTowers / (double) (szt_num_maximum_cycles + V_MINUS_ONE) ) * V_ONE_HUNDRED;

		/* ----------------------------------------------------	--
		 * It is validated for recursions if the number of	--
		 * disks is always greater than unity and less than to	--
		 * the maximum calculated cycles.			--
		 * ----------------------------------------------------	*/
		if (szt_num_dishes > V_ONE && szt_num_loops_HanoiTowers < szt_num_maximum_cycles)
			{
				/* ------------------------------------------------------------	--
				 * The antlers from which they are going to be extracted are	--
				 * inverted the rings, now it is the 1st, the 3rd and the 2nd.	--
				 * ------------------------------------------------------------	*/
				szt_HanoiTowers(szt_num_dishes + V_MINUS_ONE, chr_first_tower, chr_third_tower, chr_second_tower, szt_num_maximum_cycles);

				/* ------------------------------------------------------------	--
				 * This message prints while there are rings on it of the	--
				 * current flagpole to be mobilized.				--
				 * ------------------------------------------------------------	*/
				printf("Motion: [%10.ld].\t[%5.2lf]%% advanced.\tRing # [%2.ld].\tFrom antler [%c] to [%c].\t\r", szt_num_loops_HanoiTowers, dbl_perc_advantage, szt_num_dishes, chr_first_tower, chr_third_tower);

				/* ------------------------------------------------------------	--
				 * The antlers from which they are going to be extracted are	--
				 * inverted the rings, now it is the 2nd, the 1st and the 3rd.	--
				 * ------------------------------------------------------------	*/
				szt_HanoiTowers(szt_num_dishes + V_MINUS_ONE, chr_second_tower, chr_first_tower, chr_third_tower, szt_num_maximum_cycles);
			}

		/* ------------------------------------------------------------	--
		 * This message is printed if the last ring of the block that	--
		 * you want to move from a specific pole.			--
		 * ------------------------------------------------------------	*/
		printf("Motion: [%10.ld].\t[%5.2lf]%% advanced.\tRing # [%2.ld].\tFrom antler [%c] to [%c]. \r", szt_num_loops_HanoiTowers, dbl_perc_advantage, szt_num_dishes, chr_first_tower, chr_third_tower);

		return (szt_num_loops_HanoiTowers);
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
		size_t szt_num_dishes = V_ZERO;
		size_t szt_num_loops_HanoiTowers = V_ZERO;
		size_t szt_num_maximum_cycles_HanoiTowers = V_ZERO;

   		printf("|---|----+---|----+---|----+---|----+\n");
		printf("|     Towers of Hanoi Algorithm.    |\n");
   		printf("|---|----+---|----+---|----+---|----+\n");
		printf("Rings to move between [%2.d] and [%2.d]: ", V_MIN_DISHES, V_MAX_DISHES);
   		scanf("%ld", &szt_num_dishes);

		/* ------------------------------------------------------------	--
		 * It is validated that the number of disks is in a range	--
		 * allowable and tolerable by the processor.			--
		 * ------------------------------------------------------------	*/
		if (szt_num_dishes >= V_MIN_DISHES && szt_num_dishes <= V_MAX_DISHES)
			{
				/* ------------------------------------------------------------	--
				 * The maximum number of processor cycles is determined to 	--
				 * solve the Towers of Hanoi with 'n' discs.			--
				 * ------------------------------------------------------------	*/
				szt_num_maximum_cycles_HanoiTowers = szt_potency(V_TWO, szt_num_dishes); //(2^N)

				/* ------------------------------------------------------------	--
				 * The number of movements that have been made is displayed on	--
				 * the screen required to move the different disks.		--
				 * ------------------------------------------------------------	*/
				printf("\n[%10.ld] Necessary movements with [%2.ld] discs.\n", szt_num_maximum_cycles_HanoiTowers + V_MINUS_ONE, szt_num_dishes);

				/* ------------------------------------------------------------	--
				 * The 'HanoiTowers' function is called and returns as a result	--
				 * the number of cycles to solve them.				--
				 * ------------------------------------------------------------	*/
				szt_num_loops_HanoiTowers = szt_HanoiTowers(szt_num_dishes, FIRST_TOWER, SECOND_TOWER, THIRD_TOWER, szt_num_maximum_cycles_HanoiTowers);

				/* ------------------------------------------------------------	--
				 * The screen displays how many effective movements were made	--
				 * with the specified number of disks.				--
				 * ------------------------------------------------------------	*/
				printf("\n[%10.ld] Movements performed with [%2.ld] displaced discs.\n", szt_num_loops_HanoiTowers, szt_num_dishes);
			}
		else
			/* ------------------------------------------------------------	--
			 * The entered value is outside the allowed range.		--
			 * The more disks, the greater the probability that the		--
			 * algorithm process never ends.				--
			 * ------------------------------------------------------------	*/
			printf("Mistake! Value [%2.ld] is not in the range of [%2.d] and [%2.d].\n", szt_num_dishes, V_MIN_DISHES, V_MAX_DISHES);

    	return V_ZERO;
    }
