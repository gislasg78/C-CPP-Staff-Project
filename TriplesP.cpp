/**************** Pythagorean Triples Generator. *****************
 ** Source Code:        TriplesP.cpp				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		A Pythagorean triple has three positive	**
 **			integers a, b, and c, such that		**
 **			a^2 + b^2 = c^2.			**
 **			In other words, a Pythagorean triple	**
 **			represents the lengths of the sides of	**
 **			a right triangle in which all three	**
 **			sides have integer lengths.		**
 **			This triple is usually written		**
 **			(a, b, c).				**
 **			Some well-known examples are (3, 4, 5)	**
 **			and (5, 12, 13).			**
*****************************************************************/
//C Standard Libraries.
#include <iostream>

//C Standard Constants.
#define V_ONE	1
#define V_ZERO  0

/*****************************************************************
 ** Function:		static size_t szt_find_Pyht_Triples	**
 **				(const size_t szt_limit).	**
 ** Explanation:	A Pythagorean triple is an ordered	**
 **			set of three positive integers a, b, c,	**
 **			and are solutions of the quadratic	**
 **			Diophantine equation a^2 + b^2 = c^2.	**
 **			The nomenclature is linked to the	**
 **			Pythagorean theorem, which states that	**
 **			in any right triangle, it holds that	**
 **			r^2 + s^2 = t^2  (where t is the length	**
 **			of the hypotenuse; and the other	**
 **			variables, leg lengths, in integers).	**
 **			In the reciprocal sense it is also true,**
 **			that is, any Pythagorean triple can be	**
 **			associated with the lengths of the two	**
 **			legs and the corresponding hypotenuse,	**
 **			forming a right triangle.		**
 ** Input Parms:	const size_t szt_limit.			**
 ** Output Parms:	None.					**
 ** Result:		To the integers u, v, w, that satisfy	**
 **			the Diophantine equation of the second	**
 **			degree u^2 + v^2 = w^2, they are called	**
 **			Pythagorean numbers.			**
 ****************************************************************/
static size_t szt_find_Pyth_Triples (const size_t szt_limit)
	{
		size_t szt_counting_triples = V_ZERO;

		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+    Pythagorean Triples Results.   +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| Terms: [" << szt_limit << "]." << std::endl;

		for (size_t szt_hick_opposite = V_ONE; szt_hick_opposite <= szt_limit; ++szt_hick_opposite)
			{
				for (size_t szt_cathetus_b = szt_hick_opposite; szt_cathetus_b <= szt_limit; ++szt_cathetus_b)
					{
						for (size_t szt_hypotenuse = szt_cathetus_b + V_ONE; szt_hypotenuse <= szt_limit; ++szt_hypotenuse)
							{
								if (szt_hick_opposite * szt_hick_opposite + szt_cathetus_b * szt_cathetus_b == szt_hypotenuse * szt_hypotenuse)
									{
										std::cout << "| # [" << szt_counting_triples++ << "]:\t" << "[" << szt_hick_opposite << "]\t+\t[" << szt_cathetus_b << "]\t=\t[" << szt_hypotenuse << "]." << std::endl;
									}
							}
					}
			}

		return szt_counting_triples;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This main function generates the	**
 **			Pythagorean triples that are usually	**
 **			represented as (a, b, c).		**
 **			Triples whose three numbers are		**
 **			relatively prime are called primitive	**
 **			Pythagorean triples or			**
 **			Pythagorean numbers.			**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		A primitive Pythagorean triple is one	**
 **			in which a, b and c are coprime,	**
 **			hat is, the greatest common factor of	**
 **			a, b and c is 1.			**
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
		/* Initial declaration of work variables. */
		size_t szt_counting_triples = V_ZERO;
		size_t szt_terms = V_ZERO;

		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+   Pythagorean Triples Generator.  +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Enter number of Pythagorean Triples: ";
		std::cin >> szt_terms;

		/* Obtaining preliminary variables. */
		szt_counting_triples = szt_find_Pyth_Triples(szt_terms);

		std::cout << "[" << szt_counting_triples << "] Pythagorean Triples."<< std::endl;

		return V_ZERO;
	}
