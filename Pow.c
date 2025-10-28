/******************** Powers of Numbers Results. *****************
 ** Source Code:	Pow.c		               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Wednesday, December 31, 2025.		**
 ** Purpose:		This program generates a series of	**
 **			multiplications or divisions of a base	**
 **			number raised to a given power,		**
 **			depending on whether it is a positive	**
 **			power or a negative power respectively.	**
 **			It is important to clarify that the	**
 **			exponent index count must always be	**
 **			close to zero to know how many		**
 **			occurrences will be counted to return	**
 **			the desired result.			**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_MINUS_ONE	-1
#define V_ONE		1
#define	V_ZERO		0

/*****************************************************************
 ** Function:		double dbl_potency.			**
 ** Explanation:	Returns a base coefficient raised to the**
 **			specified power recursively by means of	**
 **			successive multiplications or divisions.**
 **								**
 **			This function can also be programmed	**
 **			recursively in the form:		**
 **				(int_exp > V_ZERO) ? 		**
 **					dbl_potency(dbl_base,	**
 **					int_exp + V_MINUS_ONE)	**
 **					* dbl_base :		**
 **				(int_exp == V_ZERO) ? V_ONE :	**
 **				(int_exp < V_ZERO) ?		**
 **					dbl_potency(dbl_base,	**
 **					int_exp + V_ONE)	**
 **					/ dbl_base :		**
 **					V_ONE;			**
 **								**
 ** Input Parms:	const double dbl_base,			**
 **			const int int_exp.			**
 ** Output Parms:	None.					**
 ** Result:		The base raised to a positive power	**
 **			results in a series of products in	**
 **			sequence from 1 to 'n', while a base	**
 **			raised to a negative power results in a	**
 **			series of quotients in sequence from 1	**
 **			to '-n' .				**
*****************************************************************/
double dbl_potency(const double dbl_base, const int int_exp)
	{
		return	(int_exp > V_ZERO) ? dbl_potency(dbl_base, int_exp + V_MINUS_ONE) * dbl_base :
			(int_exp == V_ZERO) ? V_ONE :
			(int_exp < V_ZERO) ? dbl_potency(dbl_base, int_exp + V_ONE) / dbl_base : V_ONE;
	}

/*****************************************************************
 ** Function:           static dbl_potw.			**
 ** Explanation:        Returns a base coefficient raised to the**
 **                     specified power recursively by means of **
 **                     successive multiplications or divisions.**
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
double dbl_potw(const double dbl_base, const int int_exp)
	{
		double dbl_result = V_ONE;

		if (int_exp == V_ZERO)
			{
				dbl_result = V_ONE;
			}
		else if (int_exp > V_ZERO)
			{
				for (int int_idx = V_ZERO; int_idx < int_exp; int_idx++)
					{
						dbl_result *= dbl_base;
					}
			}
		else if (int_exp < V_ZERO)
			{
				for (int int_idx = V_ZERO; int_idx > int_exp; int_idx--)
					{
						dbl_result /= dbl_base;
					}
			}

		return dbl_result;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In the main module we have the call to	**
 **			the power function which is highly	**
 **			recursive with positive or negative	**
 **			exponents, and always calls itself to	**
 **			reach zero and therefore,		**
 **			multiplication by unity.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		This main module calls two		**
 **			implementations that produce the same	**
 **			result, which is to raise a given base	**
 **			to a given power, depending on whether	**
 **			the latter is positive, successive	**
 **			multiplications will be made on the	**
 **			same base, and if it is negative,	**
 **			successive divisions will be made on	**
 **			the same base. One function is		**
 **			predominantly recursive and the other	**
 **			uses conditional loops.			**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		double dbl_base = V_ZERO;
		double dbl_potency_res = V_ZERO;
		double dbl_potw_res = V_ZERO;
		int int_exp = V_ZERO;

		/* Initial presentation headers. */
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+   Positive and negative powers.   +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("Base: ");
		scanf("%lf", &dbl_base);
		printf("Exponent: ");
		scanf("%d", &int_exp);

		/* Obtaining preliminary variables. */
		dbl_potency_res = dbl_potency(dbl_base, int_exp);	//Obtaining a power through recursive calls to the function itself.
		dbl_potw_res = dbl_potw(dbl_base, int_exp);		//Obtaining power through established cycles.

		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+     Powers of Numbers Results.    +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| Base:\t\t[%lf].\n", dbl_base);
		printf("| Exponent:\t[%d].\n", int_exp);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Potency:\t[%lf],\n", dbl_potency_res);
		printf("! Power:\t[%lf].\n", dbl_potw_res);
		printf("+===|====+===|====+===|====+===|====+\n");

		return V_ZERO;
	}
