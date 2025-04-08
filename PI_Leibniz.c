/****************** PI number by Leibniz series. *****************
 ** Source Code:	PI_Leibniz.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Tuesday, December 31, 2024.          	**
 ** Purpose:		This program uses the Leibniz and	**
 **			Wallis methods to calculate a good	**
 **			approximation of the irrational number	**
 **			PI.					**
 **								**
 **			It is highly recommended that the	**
 **			number of terms used in the calculation **
 **			be at least 1,048,576 or 2^20.		**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_FOUR		4.0
#define V_MINUS_ONE	-1
#define	V_ONE		1.0
#define	V_TWO		2.0
#define	V_ZERO		0

/*****************************************************************
 ** Function:		double PI_Leibniz			**
 **				(const size_t szt_terms).	**
 ** Explanation:	This function returns as a result the	**
 **			calculation by iterative series of the	**
 **			Leibniz method to obtain with the	**
 **			greatest possible accuracy the		**
 **			irrational number PI given a certain	**
 **			number of terms.			**
 **								**
 **			The function computes the Leibniz	**
 **			iterative series as follows using	**
 **			reciprocals:				**
 **								**
 **			+ [1 / (2 * i + 1)]			**
 **			- [1 / (2 * i + 1)] + [...].		**
 **								**
 ** Input Parms:	const size_t szt_terms.			**
 ** Output Parms:	None.					**
 ** Result:		Approximation of the irrational number	**
 **			PI.					**
 ****************************************************************/
double PI_Leibniz(const size_t szt_terms)
	{
		double dbl_PI = V_ZERO;
		double dbl_sign = V_ONE;

		for (size_t szt_idx = V_ZERO; szt_idx < szt_terms; szt_idx++)
			{
				dbl_PI += dbl_sign * (double) (V_ONE / (V_TWO * szt_idx + V_ONE));
				dbl_sign *= V_MINUS_ONE;
			}

		return V_FOUR * dbl_PI;
	}

/*****************************************************************
 ** Function:           double PI_Wallis			**
 **                             (const size_t szt_terms).       **
 ** Explanation:	This function is intended to contain	**
 **			the 'for' loop that iterates 'n' times,	**
 **			calculating each pair of factors in the	**
 **			Wallis series in each iteration:	**
 **								**
 **			1. (double)(2 * i) / (2 * i - 1):	**
 **				Calculates the first factor of	**
 **				the pair.			**
 **				The conversion to double is	**
 **				important to ensure		**
 **				floating-point division.	**
 **								**
 **			2. (double)(2 * i) / (2 * i + 1):	**
 **				Calculates the second factor of	**
 **				the pair.			**
 **								**
 **			3. pi_over_2 *= [...]:			**
 **				Multiplies the current value of	**
 **				pi_over_2 by each of these	**
 **				factors.			**
 **								**
 **			4. double pi_approx = 2.0 * pi_over_2.	**
 **				After calculating the product	**
 **				of the 'n' terms, we multiply	**
 **				the result by 2 to obtain the	**
 **				approximation of PI.		**
 **								**
 ** Input Parms:        const size_t szt_terms.                 **
 ** Output Parms:       None.                                   **
 ** Result:		Understanding the Wallis Series:	**
 **								**
 **			The Wallis series is a representation	**
 **			of 2 * PI as an infinite product:	**
 **								**
 **			PI/2 =	(2/1) * (2/3) * (4/3) * (4/5) *	**
 **				(6/5) * (6/7) * (8/7) * (8/9) *	**
 **				[...].				**
 **								**
 ** 			We can observe a pattern in this	**
 **			product.				**
 **			For the first 'n' terms, we can		**
 **			generalize it.				**
 **			If we consider the first 'n' factor	**
 **			pairs					**
 **				(i.e., '2 * n' 			**
 **				total terms in the product),	**
 **				the formula looks like this:	**
 **								**
 **			PI/2 ≈ PI (From i=1 To n) of		**
 **				[ (2 * i) / (2 * i - 1) ] *	**
 **				[ (2 * i) / (2 * i + 1) ].	**
 **								**
 **			Where 'PI' denotes the product.		**
 ****************************************************************/
double PI_Wallis(const size_t szt_terms)
	{
		double dbl_pi_over_two = V_ONE;

		for (size_t szt_idx = V_ONE; szt_idx <= szt_terms; szt_idx++)
			{
				dbl_pi_over_two *= (double) (V_TWO * szt_idx) / (V_TWO * szt_idx + V_MINUS_ONE);
				dbl_pi_over_two *= (double) (V_TWO * szt_idx) / (V_TWO * szt_idx + V_ONE);
			}

		double dbl_pi_approx = V_TWO * dbl_pi_over_two;

		return dbl_pi_approx;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function, the user is	**
 **			requested to enter a certain number of	**
 **			terms to start the iterations that will	**
 **			seek to approximate the accuracy of the	**
 **			irrational number PI. It is highly	**
 **			recommended that the number to enter is	**
 **			1,048,576 or 2^20.			**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The function calculates the Leibniz	**
 **			series as follows:			**
 **			+ [1 / (2 * i + 1)]			**
 **			- [1 / (2 * i + 1)] + ...		**
 ****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		double dbl_PI_Leibniz = V_ZERO, dbl_PI_Wallis = V_ZERO;
		size_t szt_terms = V_ZERO;

		/* Presentation headers. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Leibniz & Wallis PI Method.    |\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Enter the number of terms for PI: ");
		scanf("%ld", &szt_terms);

		/* Obtaining preliminary variables. */
		dbl_PI_Leibniz = PI_Leibniz(szt_terms);	//Obtaining the value of PI by the Leibniz method.
		dbl_PI_Wallis = PI_Wallis(szt_terms);	//Obtaining the value of PI by the Wallis method.

		/* Final results messages. */
		printf("\n");
		printf("+===|====+===|====+===|====+===+\n");
		printf("+ Leibniz & Wallis PI Results. +\n");
		printf("+===|====+===|====+===|====+===+\n");
		printf("| Num. Terms\t: [%ld].\n", szt_terms);
		printf("+---+----+---+----+---+----+---+\n");
		printf("| Leibniz & Wallis PI Methods. |\n");
		printf("+---+----+---+----+---+----+---+\n");
		printf("| Leibniz\t: [%lf].\n", dbl_PI_Leibniz);
		printf("| Wallis\t: [%lf].\n", dbl_PI_Wallis);
		printf("+===|====+===|====+===|====+===+\n");

		return V_ZERO;
	}
