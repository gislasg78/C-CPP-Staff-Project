/****************** Bernoulli Number Generator. ******************
 ** Source Code:	Bernoull.cc	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
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

//Working Macros
#define	DENOMINATOR(v_n, v_k)	((v_n) - (v_k) + V_ONE)

//Numeric Symbolic Constants.
#define	V_LIM_MAX		26
#define	V_LIM_MIN		0
#define V_MINUS_ONE		-1
#define V_ONE			1
#define V_ZERO			0

/*****************************************************************
 ** Function:		factorial.				**
 ** Explanation:	Gets the value of the factorial of any	**
 **			integer by iterativity multiplying	**
 **			it by its descendant surrogate numbers.	**
 ** Input Parms:	int int_num.				**
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
*****************************************************************/
long factorial(int int_num)
	{
		long lng_fact=V_ONE;

		for (int int_idx=V_ONE; int_idx<=int_num; int_idx++)
			lng_fact*=int_idx;

		return lng_fact;
	}

/*****************************************************************
 ** Function:		combinations.				**
 ** Explanation:	Gets the total number of combinations	**
 **			arising from the mathematical formula:	**
 **			nCr = n! / [(n - r)! * r!].		**
 **			In such a way that it also resorts to	**
 **			the previously predefined and		**
 **			pre-established factorial formula.	**
 ** Input Parms:	int int_num.				**
 ** Output Parms:	None.					**
 ** Result:		nCr = n! / [(n - r)! * r!].		**
*****************************************************************/
long combinations(int int_num, int int_r)
	{
		return factorial(int_num) / (factorial(int_num - int_r) * factorial(int_r));
	}

/*****************************************************************
 ** Function:		Bernoulli.				**
 ** Explanation:	Returns as the result itself the	**
 **			Bernoulli number requested by the	**
 **			mathematical formula:			**
 **			-Sum(from j=0 to m):                    **
 **                             mCj * (B[j] / (m + 1 - j)).	**
 ** Input Parms:	int int_num.				**
 ** Output Parms:	None.					**
 ** Result:		Repetitive loops & recursive iterations.**
 **			-Sum(from j=0 to m):			**
 **				(m!/((m!-j!)*j!) * (B[j] /	**
 **					(m + 1 - j)).		**
*****************************************************************/
double Bernoulli(int int_num)
	{
		double dbl_Bernoulli=V_ZERO;

		if (int_num>V_ZERO)
			for (int int_idx=V_ZERO; int_idx<=(int_num+V_MINUS_ONE); int_idx++)
				dbl_Bernoulli += (double) (combinations(int_num, int_idx)
						* Bernoulli(int_idx)) / DENOMINATOR(int_num, int_idx);
		else
			dbl_Bernoulli=V_MINUS_ONE;

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
		int int_nums=V_ZERO;

		printf("Bernoulli numbers between [%d] and [%d] : ", V_LIM_MIN, V_LIM_MAX);
		scanf("%d", &int_nums);

		if (int_nums>=V_LIM_MIN && int_nums<=V_LIM_MAX)
			{
				printf("[%d] Bernoulli numbers:\n", int_nums);

				for (int int_idx=V_ZERO; int_idx<=int_nums; int_idx++)
					printf("B:[%2.d] = [%12.6lf].\n", int_idx, Bernoulli(int_idx));
			}
		else
			printf("Error! The number [%d] is out of range from [%d] to [%d].\n", int_nums, V_LIM_MIN, V_LIM_MAX);

		return V_ZERO;
	}
