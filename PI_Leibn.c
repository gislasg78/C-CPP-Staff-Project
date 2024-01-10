/****************** PI number by Leibniz series. *****************
 ** Source Code:	PI_Leibn.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December, 2023.          	**
 ** Purpose:		This program uses the Leibniz method to	**
 **			calculate a good approximation of the	**
 **			irrational number PI. It is highly	**
 **			recommended that the number of terms	**
 **			used in the calculation be at least	**
 **			1,048,576.				**
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
 ** Function:		static double PI_Leibniz		**
 **				(const size_t szt_terms).	**
 ** Explanation:	This function returns as a result the	**
 **			calculation by iterative series of the	**
 **			Leibniz method to obtain with the	**
 **			greatest possible accuracy the		**
 **			irrational number PI given a certain	**
 **			number of terms.			**
 **			The function computes the Leibniz	**
 **			iterative series as follows using	**
 **			reciprocals:				**
 **			+ [1 / (2 * i + 1)]			**
 **			- [1 / (2 * i + 1)] + ...		**
 ** Input Parms:	size_t szt_terms.			**
 ** Output Parms:	None.					**
 ** Result:		Approximation of the irrational number	**
 **			PI.					**
 ****************************************************************/
static double PI_Leibniz(size_t szt_terms)
	{
		double dbl_PI = V_ZERO;
		double dbl_sign = V_ONE;

		for (size_t szt_idx = V_ZERO; szt_idx < szt_terms; szt_idx++)
			{
				dbl_PI += dbl_sign * (V_ONE / (V_TWO * szt_idx + V_ONE));
				dbl_sign *= V_MINUS_ONE;
			}

		return V_FOUR * dbl_PI;
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
		double dbl_PI = V_ZERO;
		size_t szt_terms=V_ZERO;

		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+     PI by the Leibniz Method.     |\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Terms : ");
		scanf("%ld", &szt_terms);

		/* Obtaining preliminary variables. */
		dbl_PI = PI_Leibniz(szt_terms);	//Obtaining the value of PI by the Leibniz method.

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ PI Results by the Leibniz Method. +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Terms\t: [%ld].\n", szt_terms);
		printf("| PI\t: [%lf].\n", dbl_PI);
		printf("+---|----+---|----+---|----+---|----+\n");

		return V_ZERO;
	}
