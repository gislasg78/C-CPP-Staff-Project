/******** Trigonometric approximate function of Tangent.  ********
 ** Source Code:	Tangent.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
 ** Purpose:		The purpose of this program is to	**
 **			approximate a value of normal degrees to**
 **			its value in the trigonometric function	**
 **			of the tangent using the up-down	**
 **			coefficients and the Bernoulli numbers.	**
 **			It should be clarified that the exact	**
 **			numbers cannot be obtained because the	**
 **			calculation coefficients generated are	**
 **			so large that the variables overflow,	**
 **			so it only approaches a close trend,	**
 **			so this function requires additional	**
 **			improvements or changes in its		**
 **			calculation method.			**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Working Macros.
#define	DENOMINATOR(v_n, v_k)		((v_n) - (v_k) + V_ONE)
#define RADIANS(angle)			((angle) * V_PI / V_HALF_CIRC)

//Work Symbolic Constants.
#define V_HALF_CIRC	180.0
#define V_MINUS_ONE	-1
#define V_N_TERMS	13
#define V_ONE		1
#define V_PI		3.14159265359
#define V_TWO		2.0
#define V_ZERO		0

/*****************************************************************
 ** Function:		factorial.				**
 ** Explanation:	Gets the value of the factorial of any	**
 **			integer by iterativity multiplying	**
 **			it by its descendant surrogate numbers.	**
 ** Input Parms:	int int_num.				**
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
*****************************************************************/
double factorial(int int_num)
	{
		double dbl_ret=V_ONE;

		for(int int_idx=V_ONE; int_idx<=int_num; int_idx++)
			dbl_ret*=int_idx;

		return dbl_ret;
	}

/*****************************************************************
 ** Function:		potency.				**
 ** Explanation:	Returns a base coefficient raised to the**
 **			specified power recursively by means of	**
 **			successive multiplications.		**
 **								**
 **			This function can also be programmed	**
 **			recursively in the form:		**
 **								**
 **			(int_exp == V_ZERO) ? V_ONE : dbl_base	**
 **			 * potency(dbl_base, int_exp - V_ONE);	**
 **								**
 ** Input Parms:	double dbl_base,			**
 **			int int_exp.				**
 ** Output Parms:	None.					**
 ** Result:		dbl_base raised to int_exp.		**
*****************************************************************/
double potency(double dbl_base, int int_expn)
	{
		double dbl_ret=V_ONE;

		for(int int_idx=V_ZERO; int_idx<int_expn; int_idx++)
			dbl_ret*=dbl_base;

		return dbl_ret;
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
double combinations(int int_num, int int_r)
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
				dbl_Bernoulli += combinations(int_num, int_idx)
						* Bernoulli(int_idx) / DENOMINATOR(int_num, int_idx);
		else
			dbl_Bernoulli=V_MINUS_ONE;

		return -dbl_Bernoulli;
	}

/*****************************************************************
 ** Function:		tangent.				**
 ** Explanation:	This function uses the numbers up/down	**
 **			and the Bernoulli series to get an	**
 **			approximation, albeit a distant one, of **
 **			the trigonometric function of Tangent,	**
 **			without relying on other trigonometric	**
 **			functions.				**
 **			This series is made up as follows:	**
 **								**
 **			tan (x) = sum from n=0 to infinite:	**
 **				{[(-1)^(n-1)] * 2^(2*n)	*	**
 **				 [2^(2*n)-1] * B(2*n) *		**
 **				  x^(2*n-1)} / (2*n)!		**
 **			where: |x| < PI / 2.			**
 **								**
 ** Input Parms:	double dbl_x.				**
 ** Output Parms:	None.					**
 ** Result:		Returns as a result an approximation,	**
 **			although distant in value, but close in **
 **			trend, of the trigonometric function of **
 **			the Tangent, based on the calculation	**
 **			of iterations of the up/down numbers and**
 **			the Bernoulli numbers.			**
 **			This function requires adjustments and	**
 **			improvements due to variable overflow	**
 **			when the number of terms is greater than**
 **			ten units.				**
*****************************************************************/
double tangent(double dbl_x)
	{
		double dbl_tangent=V_ZERO;

		for (int int_idx=V_ZERO; int_idx<=V_N_TERMS; int_idx++)
			dbl_tangent += potency(V_MINUS_ONE, int_idx+V_MINUS_ONE)
					* potency(V_TWO, V_TWO*int_idx)
					* (potency(V_TWO, V_TWO*int_idx)+V_MINUS_ONE)
					* Bernoulli(V_TWO*int_idx)
					* potency(dbl_x, V_TWO*int_idx+V_ONE) / factorial(V_TWO*int_idx);

		return dbl_tangent;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This main function asks the user for a	**
 **			certain number in normal degrees, later	**
 **			it is calculated in radians and the	**
 **			function that approximates in trend,	**
 **			but not in value, to the trigonometric	**
 **			function of the tangent is called.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Returns the approximate trend value of	**
 **			the trigonometric function of the	**
 **			tangent given a value in normal degrees	**
 **			using iterations of the up/down numbers **
 **			and Bernoulli numbers.			**
*****************************************************************/
int main()
	{
		double dbl_angle=V_ZERO;
		double dbl_radns=V_ZERO;
		double dbl_tangent=V_ZERO;

		printf("+---|----+---|----+---|----+\n");
		printf("|   Tangent Calculation.   |\n");
		printf("+---|----+---|----+---|----+\n");
		printf("Degrees: ");
		scanf("%lf", &dbl_angle);

		dbl_radns=RADIANS(dbl_angle);
		dbl_tangent=tangent(dbl_radns);

		printf("\n");
		printf("+---|----+---|----+---|----+\n");
		printf("|     Tangent Results.     |\n");
		printf("+---|----+---|----+---|----+\n");
		printf("| Degrees: [%lf].\n", dbl_angle);
		printf("| Radians: [%lf].\n", dbl_radns);
		printf("| Tangent: [%lf].\n", dbl_tangent);
		printf("+---|----+---|----+---|----+\n");
		printf("\n");

		return V_ZERO;
	}
