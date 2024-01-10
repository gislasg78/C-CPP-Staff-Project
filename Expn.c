/************* Euler exponential natural number 'e'. *************
 ** Source Code:        Expn.c					**
 ** Author:             Gustavo Islas Gálvez.			**
 ** Creation Date:      Saturday, December 30, 2023.		**
 ** Purpose:		This program is in charge of raising	**
 **			Euler's natural number 'e' to a		**
 **			determined power 'x', and it is solved	**
 **			through power series or Taylow series.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define	V_MINUS_ONE	-1
#define V_NUM_TERMS	256	//2^8.
#define V_ONE		1
#define V_ZERO		0

/*****************************************************************
 ** Function:		static double dbl_factorial.		**
 ** Explanation:        Gets the value of the factorial of any  **
 **                     integer by recursively multiplying it by**
 **                     its descendant surrogate numbers.       **
 ** Input Parms:        const size_t szt_num.			**
 ** Output Parms:       None.                                   **
 ** Result:             Factorial from 'i' to 'n'.              **
 ****************************************************************/
static double dbl_factorial(const size_t szt_num)
	{
		return	(szt_num < V_ONE) ? V_ONE : szt_num * dbl_factorial(szt_num + V_MINUS_ONE);
	}

/*****************************************************************
 ** Function:           static double dbl_potency.              **
 ** Explanation:        Returns a base coefficient raised to the**
 **                     specified power recursively by means of **
 **                     successive multiplications or divisions.**
 **                                                             **
 **                     This function can also be programmed    **
 **                     recursively in the form:                **
 **                             (int_exp > V_ZERO) ?            **
 **                                     dbl_potency(dbl_base,   **
 **                                     int_exp + V_MINUS_ONE)  **
 **                                     * dbl_base :            **
 **                             (int_exp == V_ZERO) ? V_ONE :   **
 **                             (int_exp < V_ZERO) ?            **
 **                                     dbl_potency(dbl_base,   **
 **                                     int_exp + V_ONE)        **
 **                                     / dbl_base :            **
 **                                     V_ONE;                  **
 ** Input Parms:        const double dbl_base,                  **
 **                     const int int_exp.                      **
 ** Output Parms:       None.                                   **
 ** Result:             The base raised to a positive power     **
 **                     results in a series of products in      **
 **                     sequence from 1 to 'n', while a base    **
 **                     raised to a negative power results in a **
 **                     series of quotients in sequence from 1  **
 **                     to '-n' .                               **
*****************************************************************/
static double dbl_potency(const double dbl_base, const size_t szt_exp)
        {
                return  (szt_exp < V_ONE) ? V_ONE : dbl_potency(dbl_base, szt_exp + V_MINUS_ONE) * dbl_base;
        }

/*****************************************************************
 ** Function:           static double expn			**
 **				(const double dbl_base).	**
 ** Explanation:	Computes Euler's natural number 'e'	**
 **			through power series given a specified	**
 **			number of terms, in such a way that the	**
 **			series is obtained: (x^0 / 0!) +	**
 **			(x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!)...	**
 ** Input Parms:        const double dbl_base.			**
 ** Output Parms:       None.					**
 ** Result:             'e' raised to dbl_base.			**
 ****************************************************************/
static double expn(const double dbl_base)
	{
		double dbl_outcome = V_ZERO;

		for (size_t szt_idx = V_ZERO; szt_idx < V_NUM_TERMS; szt_idx++)
			dbl_outcome += dbl_potency(dbl_base, szt_idx) / dbl_factorial(szt_idx);

		return dbl_outcome;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In the main module of this program,	**
 **			simply request the power 'x' to which	**
 **			the Euler's natural number 'e' is going **
 **			to be calculated raised to said power	**
 **			'x' by means of power series or Taylor	**
 **			series.					**
 ** Input Parms:        None.                                   **
 ** Output Parms:       None.                                   **
 ** Result:		Euler's natural number 'e' raised to	**
 **			the given 'x' power.			**
 ****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		double dbl_base = V_ZERO;
		double dbl_exp = V_ZERO;

		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+   Taylor Series Neperian Euler.   +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Exp 'e' : ");
		scanf("%lf", &dbl_base);

		/* Obtaining preliminary variables. */
		dbl_exp = expn(dbl_base);	//Obtaining the number 'e' to the power of 'x'.

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ Results of the Exponential Number.+\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Exp.\t: [%lf].\n", dbl_base);
		printf("| Terms\t: [%d].\n", V_NUM_TERMS);
		printf("| Euler\t: [%lf].\n", dbl_exp);
		printf("+---|----+---|----+---|----+---|----+\n");

		return V_ZERO;
	}
