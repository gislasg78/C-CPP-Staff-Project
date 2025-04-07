/****************** Natural logarithm base 'e'. ******************
 ** Source Code:        Ln.c					**
 ** Author:             Gustavo Islas Gálvez.			**
 ** Creation Date:      Tuesday, December 31, 2024.		**
 ** Purpose:		This program calculates through the	**
 **			Taylor series the natural logarithm	**
 **			with a base 'x' determined at a certain	**
 **			number of calculation cycles, taking	**
 **			into consideration the development of	**
 **			the following power series:		**
 **								**
 **			ln(x) = 2 * { [(1/1) * ((x-1)/(x+1))^1]	**
 **			+ [(1/3) * ((x-1)/(x+1))^3]		**
 **			+ [(1/5) * ((x-1)/(x+1))^5]		**
 **			+ [(1/7) * ((x-1)/(x+1))^7] + [...] }	**
 **			For all 'x' -> (x>0).			**
 **								**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_MINUS_ONE	-1
#define V_NUM_TERMS	65536	//2^16.
#define V_TWO		2.0
#define V_ONE		1
#define V_ZERO		0

/*****************************************************************
 ** Function:           double dbl_potency			**
 **				(const double dbl_base,		**
 **				 const size_t szt_exp).		**
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
 **								**
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
double dbl_potency(const double dbl_base, const size_t szt_exp)
        {
                return  (szt_exp < V_ONE) ? V_ONE : dbl_potency(dbl_base, szt_exp + V_MINUS_ONE) * dbl_base;
        }

/*****************************************************************
 ** Function:		double ln (const double dbl_base).	**
 ** Explanation:	Calculates the natural logarithm of a	**
 **			defined number of base 'x' through the	**
 **			Taylor power series, based on which as	**
 **			many calculations are developed as	**
 **			there are number of terms to obtain a	**
 **			good approximation.			**
 **			This calculation is subjected to the	**
 **			following series:			**
 **								**
 **			ln(x) = 2 * { [(1/1) * ((x-1)/(x+1))^1]	**
 **			+ [(1/3) * ((x-1)/(x+1))^3]		**
 **			+ [(1/5) * ((x-1)/(x+1))^5]		**
 **			+ [(1/7) * ((x-1)/(x+1))^7] + [...] }	**
 **			For all 'x' -> (x>0).			**
 **								**
 ** Input Parms:        const double dbl_base.			**
 ** Output Parms:       None.					**
 ** Result:		Returns the natural logarithm based on	**
 **			the exponential natural number 'e',	**
 **			that is, it is its inverse.		**
 ****************************************************************/
double ln(const double dbl_base)
	{
		double dbl_outcome = V_ZERO;

		for (size_t szt_idx = V_ZERO; szt_idx < V_NUM_TERMS; szt_idx++)
			dbl_outcome += (V_ONE / (V_TWO * szt_idx + V_ONE)) *
				dbl_potency(((dbl_base + V_MINUS_ONE) / (dbl_base + V_ONE)), (V_TWO * szt_idx + V_ONE));

		return V_TWO * dbl_outcome;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main module the user is asked	**
 **			for the base 'x' to calculate his	**
 **			natural logarithm based on the		**
 **			exponential natural number 'e', and	**
 **			calls a function that performs a series	**
 **			of cyclical calculations to get a good	**
 **			approximation.				**
 **								**
 **			ln(x) = 2*{ [ (1/(2*i+1)) *		**
 **				((x-1)/(x+1)) ^ (2*i+1) ] +	**
 **				[...] }	-> (x>0).		**
 **								**
 ** Input Parms:        None.                                   **
 ** Output Parms:       None.                                   **
 ** Result:		Natural logarithm based on the natural	**
 **			number 'e' exponential.			**
 ****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		double dbl_base = V_ZERO;
		double dbl_ln = V_ZERO;

		/* Presentation headers. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ Taylor Series Natural Logarithm.  +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Enter the base 'x' for the natural logarithm: ");
		scanf("%lf", &dbl_base);

		/* Obtaining preliminary variables. */
		dbl_ln = ln(dbl_base);	//Obtaining the natural logarithm of 'x'.

		/* Results messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---+\n");
		printf("+  Natural Logarithm Results.  +\n");
		printf("+---|----+---|----+---|----+---+\n");
		printf("| Terms\t: [%d].\n", V_NUM_TERMS);
		printf("| Base\t: [%lf].\n", dbl_base);
		printf("| Log N\t: [%lf].\n", dbl_ln);
		printf("+---|----+---|----+---|----+---+\n");

		return V_ZERO;
	}
