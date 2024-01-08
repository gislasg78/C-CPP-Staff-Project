/****************** Bernoulli Number Generator. ******************
 ** Source Code:	Bernoull.cc	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
 ** Purpose:		This program generates the sequence of	**
 **			Bernoulli numbers attending to		**
 **			iterations and recursion.		**
 **			Up to a maximum of terms are calculated,**
 **			since the storage capacity of the	**
 **			variables is limited when such prominent**
 **			factorial numbers are present.		**
 **			The formula used is:			**
 **			-Sum(from j=0 to m):			**
 **				(m!/((m!-j!)*j!) * (B[j] /	**
 **					(m + 1 - j)).		**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Working Macros.
#define	DENOMINATOR(v_n, v_k)	((v_n) - (v_k) + V_ONE)

//Limit constants for Bernoulli numbers.
#define	V_UPPER_LIMIT_BERN	28
#define	V_LOWER_LIMIT_BERN	0

//Numeric Symbolic Constants.
#define V_MINUS_ONE		-1
#define V_ONE			1
#define V_ZERO			0

/*****************************************************************
 ** Function:		static size_t factorial.		**
 ** Explanation:	Gets the value of the factorial of any	**
 **			integer by iterativity multiplying	**
 **			it by its descendant surrogate numbers.	**
 ** Input Parms:	size_t szt_num.				**
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
*****************************************************************/
static size_t factorial(size_t szt_num)
	{
		return (szt_num < V_ONE) ? V_ONE : szt_num * factorial(szt_num + V_MINUS_ONE);
	}

/*****************************************************************
 ** Function:		static size_t combinations.		**
 ** Explanation:	Gets the total number of combinations	**
 **			arising from the mathematical formula:	**
 **			nCr = n! / [(n - r)! * r!].		**
 **			In such a way that it also resorts to	**
 **			the previously predefined and		**
 **			pre-established factorial formula.	**
 ** Input Parms:	size_t szt_num,				**
 **			size_t szt_r.				**
 ** Output Parms:	None.					**
 ** Result:		nCr = n! / [(n - r)! * r!].		**
*****************************************************************/
static size_t combinations(size_t szt_num, size_t szt_r)
	{
		return factorial(szt_num) / (factorial(szt_num - szt_r) * factorial(szt_r));
	}

/*****************************************************************
 ** Function:		static double Bernoulli.		**
 ** Explanation:	Returns as the result itself the	**
 **			Bernoulli number requested by the	**
 **			mathematical formula:			**
 **			-Sum(from j=0 to m):                    **
 **                             mCj * (B[j] / (m + 1 - j)).	**
 ** Input Parms:	size_t szt_num.				**
 ** Output Parms:	None.					**
 ** Result:		Repetitive loops & recursive iterations.**
 **			-Sum(from j=0 to m):			**
 **				(m!/((m!-j!)*j!) * (B[j] /	**
 **					(m + 1 - j)).		**
*****************************************************************/
static double Bernoulli(size_t szt_num)
	{
		double dbl_Bernoulli = V_ZERO;

		if (szt_num > V_ZERO)
			for (size_t szt_idx = V_ZERO; szt_idx <= (szt_num + V_MINUS_ONE); szt_idx++)
				dbl_Bernoulli += (double) (combinations(szt_num, szt_idx)
						* Bernoulli(szt_idx)) / DENOMINATOR(szt_num, szt_idx);
		else
			dbl_Bernoulli = V_MINUS_ONE;

		return -dbl_Bernoulli;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This program generates the first 'n'	**
 **			Bernoulli numbers until the capacity of	**
 **			the storage variables allows, since due	**
 **			to the large number of iterations and	**
 **			recursive spins, the calculations become**
 **			so inaccurate with such gigantic	**
 **			denominators, that it can be observed	**
 **			lags or inaccuracies after a certain	**
 **			maximum requested number of terms.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Bernoulli numbers generated with the	**
 **			following iterative and recursive	**
 **			mathematical procedure:			**
 **			-Sum(from j=0 to m):			**
 **				(m!/((m!-j!)*j!) * (B[j] /	**
 **					(m + 1 - j)).		**
*****************************************************************/
int main()
	{
		size_t szt_nums = V_ZERO;

		printf("Bernoulli numbers between [%d] and [%d] : ", V_LOWER_LIMIT_BERN, V_UPPER_LIMIT_BERN);
		scanf("%ld", &szt_nums);

		if (szt_nums >= V_LOWER_LIMIT_BERN && szt_nums <= V_UPPER_LIMIT_BERN)
			{
				printf("[%ld] Bernoulli numbers:\n", szt_nums);

				for (size_t szt_idx = V_ZERO; szt_idx <= szt_nums; szt_idx++)
					printf("B:[%2.ld] = [%12.6lf].\n", szt_idx, Bernoulli(szt_idx));
			}
		else
			printf("Error! The number [%ld] is out of range from [%d] to [%d].\n", szt_nums, V_LOWER_LIMIT_BERN, V_UPPER_LIMIT_BERN);

		return V_ZERO;
	}
