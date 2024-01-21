/**************** Pythagorean Triples Generator. *****************
 ** Source Code:        TriplesP.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		A Pythagorean triple has three positive	**
 **			integers x, y, and z, such that		**
 **			x^2 + y^2 = z^2.			**
 **			In other words, a Pythagorean triple	**
 **			represents the lengths of the sides of	**
 **			a right triangle in which all three	**
 **			sides have integer lengths.		**
 **			This triple is usually written		**
 **			(x, y, z).				**
 **			Some well-known examples are (3, 4, 5)	**
 **			and (5, 12, 13).			**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//C Standard Constants.
#define V_EPSILON	0.000001
#define	V_ONE		1
#define	V_TWO		2
#define	V_ZERO		0

/*****************************************************************
 ** Function:		double dbl_absolute			**
 **				(const double dbl_num).		**
 ** Explanation:	Returns as a result the positive or 	**
 **			unsigned value of a certain value,	**
 **			as long as it is subjected to a series	**
 **			of conditions such as being greater	**
 **			than zero, to be positive; be zero,	**
 **			to be zero, and less than zero,		**
 **			to become positive by sign		**
 **			neutralization.				**
 ** Input Parms:	const double dbl_num.			**
 ** Output Parms:	None.					**
 ** Result:		the base value (dbl_num) is		**
 **			sign-neutralized.			**
 ****************************************************************/
double dbl_absolute(const double dbl_num)
	{
		return	(dbl_num > V_ZERO) ? dbl_num : (dbl_num == V_ZERO) ? V_ZERO : (dbl_num < V_ZERO) ? -dbl_num : dbl_num;
	}

/*****************************************************************
 ** Function:		double dbl_square_root			**
 **				(const double dbl_num).		**
 ** Explanation:	In this method the square root of a	**
 **			number 'n' is calculated by Newton's	**
 **			method.					**
 **								**
 **			This method is stated as follows:	**
 **			let 'r[¡]' be the approximate square	**
 **			root of 'n'.				**
 **								**
 **			The next approximate root 'r[i+1]' is	**
 **			calculated based on the previous root,	**
 **			such that:				**
 **								**
 **			'r[i+1]' = {(n / 'r[i]') + 'r[i]'} / 2.	**
 **								**
 **			The described process is repeated until	**
 **			the difference in absolute value of the	**
 **			last two calculated approximations is as**
 **			minuscule as specified (taking into	**
 **			account the limits set by the compiler).**
 **								**
 **			According to this, the last		**
 **			approximation will be a valid square	**
 **			root, when the surrogate criterion is	**
 **			met:					**
 **								**
 **			absolute_value('r[¡]' - 'r[¡+1]')	**
 **				<= epsilon_value.		**
 ** Input Parms:	const double dbl_num.			**
 ** Output Parms:	None.					**
 ** Result:		Care must be taken that the formal input**
 **			parameter does not receive a negative	**
 **			number as a current parameter, since the**
 **			k-th even roots of negative numbers have**
 **			no solution in the set of real numbers,	**
 **			that is, it must be avoided because an	**
 **			infinite cycle could be created in this	**
 **			method, by trying to return the square	**
 **			root of said number by series of	**
 **			quotients.				**
 ****************************************************************/
double dbl_square_root(const double dbl_num)
	{
		double dbl_aprox = V_ONE;
		double dbl_antaprox = V_ZERO;
		double dbl_epsilon = V_EPSILON;

		do
			{
				dbl_antaprox = dbl_aprox;
				dbl_aprox = (dbl_num / dbl_antaprox + dbl_antaprox) / V_TWO;
			}
		while (dbl_absolute(dbl_aprox - dbl_antaprox) >= dbl_epsilon);

		return dbl_aprox;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This main function generates the	**
 **			Pythagorean triples that are usually	**
 **			represented as (x, y, z).		**
 **			Triples whose three numbers are		**
 **			relatively prime are called primitive	**
 **			Pythagorean triples or			**
 **			Pythagorean numbers.			**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		A primitive Pythagorean triple is one	**
 **			in which x, y and z are coprime,	**
 **			hat is, the greatest common factor of	**
 **			z, y and z is one (1).			**
 **			The following is a list of early	**
 **			Pythagorean triples with values less	**
 **			than 100:				**
 **			(3, 4, 5), (5, 12, 13), (7, 24, 25),	**
 **			(8, 15, 17), (9, 40, 41), (11, 60, 61),	**
 **			(12 , 35, 37), (13, 84, 85),		**
 **			(16, 63, 65), (20, 21, 29),		**
 **			(28, 45, 53), (33, 56, 65),		**
 **			(36, 77 , 85), (39, 80, 89),		**
 **			(48, 55, 73), (65, 72, 97).		**
 ****************************************************************/
int main()
	{
		size_t szt_counting_triples = V_ZERO;
		size_t szt_terms = V_ZERO;
		size_t szt_x = V_ONE, szt_y = V_ONE;
		size_t szt_z = V_ZERO;

		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+   Pythagorean Triples Generator.  +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Enter number of Pythagorean Triples: ");
		scanf("%ld", &szt_terms);

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Pythagorean Triples Results.   +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Terms: [%ld].\n", szt_terms);
		printf("====\t\t====\t=\t====\t=\t====.\n");
		printf("[#]:\t\t[z]²\t=\t[x]²\t+\t[y]².\n");
		printf("====\t\t====\t=\t====\t=\t====.\n");

		while (szt_x <= szt_terms)
			{
				/* Calculate 'z'. Since 'z' is an integer, it stores the integer part of the square root. */
				szt_z = dbl_square_root(szt_x * szt_x + szt_y * szt_y);

				while (szt_y <= szt_terms && szt_z <= szt_terms)
					{
						/* If the square root obtained above is exact, write the values of 'z', 'x' and 'y'. */
						if (szt_z * szt_z == szt_x * szt_x + szt_y * szt_y)
							printf ("# [%ld]\t:\t[%ld]²\t=\t\[%ld]²\t+\t[%ld]².\n", szt_counting_triples++, szt_z, szt_x, szt_y);

						szt_y++;
						szt_z = dbl_square_root(szt_x * szt_x + szt_y * szt_y);
					}

				szt_x++;
				szt_y = szt_x;
			}

		printf("[%ld] Pythagorean Triples.\n", szt_counting_triples);

		return V_ZERO;
	}
