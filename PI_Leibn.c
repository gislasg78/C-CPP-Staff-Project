/****************** PI number by Leibniz series. *****************
 ** Source Code:	PI_Leibn.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, August 31, 2023.          	**
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
 ** Function:		PI_Leibniz.				**
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
 ** Input Parms:	long lng_terms.				**
 ** Output Parms:	None.					**
 ** Result:		Approximation of the irrational number	**
 **			PI.					**
 ****************************************************************/
double PI_Leibniz(long lng_terms)
	{
		double dbl_PI=V_ZERO;
		double dbl_sign=V_ONE;

		for (long lng_i=V_ZERO; lng_i<lng_terms; lng_i++)
			{
				dbl_PI += dbl_sign * (V_ONE / (V_TWO * lng_i + V_ONE));
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
		double dbl_PI=V_ZERO;
		long lng_terms=V_ZERO;

		printf("+---|----+---|----+---|----+---|----+---|--\n");
		printf("|  Calcular PI por el método de Leibniz.  |\n");
		printf("+---|----+---|----+---|----+---|----+---|--\n");
		printf("Número de términos : ");
		scanf("%ld", &lng_terms);

		dbl_PI=PI_Leibniz(lng_terms);

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|--\n");
		printf("| Resultados al calcular PI por Leibniz.  |\n");
		printf("+---|----+---|----+---|----+---|----+---|--\n");
		printf("| Términos : [%ld].\n", lng_terms);
		printf("| Valor PI : [%lf].\n", dbl_PI);
		printf("+---|----+---|----+---|----+---|----+---|--\n");
		printf("\n");

		return lng_terms;
	}
