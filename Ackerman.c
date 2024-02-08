/******************* Recursive Ackerman function. ****************
 ** Source Code:        Ackerman.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		In computing theory, an Ackermann	**
 **			function is a recursive mathematical	**
 **			function found in 1926 by Wilhelm	**
 **			Ackermann.				**
 **			It has extremely rapid growth, which is	**
 **			of interest to theoretical computer	**
 **			science and computability theory.	**
 **			Today there are a series of functions	**
 **			that are called Ackermann functions.	**
 **			They all have a similar shape to the	**
 **			original Ackermann function and also	**
 **			have similar growth behavior.		**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				'm':	3.			**
 **				'n':	4.			**
 **				'a':	125			**
 **								**
 **				'm':	4.			**
 **				'n':	1.			**
 **				'a':	65533.			**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//C Standard Constants.
#define	V_FOUR		4
#define	V_MINUS_ONE	-1
#define V_ONE		1
#define	V_THREE		3
#define	V_TWO		2
#define V_ZERO  	0

/*****************************************************************
 ** Function:		size_t szt_Ackerman			**
 **				(const size_t szt_m,		**
 **				 const size_t szt_n);		**
 ** Explanation:	This function grows extremely fast: the	**
 **			value A(4,2) already has 19,729 digits.	**
 **			This excessive growth can be used to	**
 **			show that the computable function f(n) =**
 **			A(n, n) grows faster than any primitive	**
 **			recursive function, and therefore is not**
 **			primitive recursive.			**
 ** Input Parms:	const size_t szt_m,			**
 **			const size_t szt_n.			**
 ** Output Parms:	None.					**
 ** Result:		In its modern standard version, this	**
 **			function takes two natural numbers as	**
 **			arguments and returns a single natural	**
 **			number.					**
 ****************************************************************/
size_t szt_Ackerman(const size_t szt_m, const size_t szt_n)
	{
		return	(szt_m == V_ZERO) ? szt_n + V_ONE :
			(szt_n == V_ZERO) ? szt_Ackerman(szt_m + V_MINUS_ONE, V_ONE) :
			szt_Ackerman(szt_m + V_MINUS_ONE, szt_Ackerman(szt_m, szt_n + V_MINUS_ONE));
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	To get an idea of the magnitude of the	**
 **			values that appear from row 4 onwards,	**
 **			it can be noted that, for example,	**
 **			A(4, 2) is greater than the number of	**
 **			particles that make up the universe	**
 **			raised to the 200th power and The result**
 **			of A(5, 2) cannot be written since it	**
 **			would not fit in the physical Universe.	**
 **			In general, below row 4 it is no longer	**
 **			possible to write all the digits of the	**
 **			function result.			**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The first row of the Ackerman function	**
 **			contains the positive integers, since	**
 **			A(0, n)) consists of adding one to n.	**
 **			The rest of the rows can be seen as	**
 **			indirections towards the first.		**
 **			In the case of m = 1, it is redirected	**
 **			towards A(0, n + 1);			**
 **			However, the simplification is somewhat	**
 **			complicated.				**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				'm':	3.			**
 **				'n':	4.			**
 **				'a':	125			**
 **								**
 **				'm':	4.			**
 **				'n':	1.			**
 **				'a':	65533.			**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		size_t szt_a = V_ZERO;	//Ackerman result.
		size_t szt_m = V_ZERO;	//Maximum value: 3.
		size_t szt_n = V_ZERO;	//Maximum value: 4.

		/* Welcome messages. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+   Ackerman Recursive Function.    +\n");
		printf("+--------+--------+--------+--------+\n");
		printf("+    A(m,n) = A(m-1,A(m,n-1)).      +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Values of 'm' and 'n' between [%d] and [%d] : ", V_ZERO, V_FOUR);
		scanf("%ld %ld", &szt_m, &szt_n);

		/* Range validation for 'm' and 'n'. */
		switch (szt_m)
			{
				case V_ZERO:
				case V_ONE:
				case V_TWO:
				case V_THREE:
					if (szt_n >= V_ZERO && szt_n <= V_FOUR)
						{
							/* Output obtaining results. */
							szt_a = szt_Ackerman(szt_m, szt_n);

							printf("\n");
							printf("+---|----+---|----+---|----+---|----+\n");
							printf("+Ackerman Recursive Function Results+\n");
							printf("+---|----+---|----+---|----+---|----+\n");
							printf("| A(%ld, %ld) = [%ld].\n", szt_m, szt_n, szt_a);
							printf("+---|----+---|----+---|----+---|----+\n");
						}
					else
						printf("The Ackerman function cannot be determined with a value for 'm' greater than: [%d] or for 'n' greater than: [%d].\n", V_THREE, V_FOUR);
					break;

				case V_FOUR:
					if (szt_n >= V_ZERO && szt_n <= V_ONE)
						{
							/* Output obtaining results. */
							szt_a = szt_Ackerman(szt_m, szt_n);

							printf("\n");
							printf("+---|----+---|----+---|----+---|----+\n");
							printf("+Ackerman Recursive Function Results+\n");
							printf("+---|----+---|----+---|----+---|----+\n");
							printf("| A(%ld, %ld) = [%ld].\n", szt_m, szt_n, szt_a);
							printf("+---|----+---|----+---|----+---|----+\n");
						}
					else
						printf("The Ackerman function cannot be determined with a value for 'm' greater than: [%d] and for 'n' greater than: [%d].\n", V_FOUR, V_ONE);
					break;

				default:
					printf("Impossible to determine the Ackerman function with the value for 'm' of: [%ld].\n", szt_m);
					break;

			}

		return V_ZERO;
	}
