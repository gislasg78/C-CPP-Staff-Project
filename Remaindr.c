/****** Get the list of remainders of an integer division. *******
 ** Source Code:        Remaindr.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		The purpose of this program is to obtain**
 **			the remainder of an integer division	**
 **			based on various procedures: the first,	**
 **			through simple arithmetic operations,	**
 **			and the second, through repetitive	**
 **			iterations to obtain the remainder of	**
 **			said division.				**
 **								**
 **			Test Values:				**
 **				Dividend:	3,650,000.	**
 **				Divisor:	2,048.		**
 **				Quotient:	1,782.		**
 **				Remainder:	464.		**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

//C Standard Constants.
#define V_ZERO		0

/*****************************************************************
 ** Function:		size_t szt_remainder			**
 **				(const size_t szt_dividen,	**
 **				 const size_t szt_divisor);	**
 ** Explanation:	This function aims to obtain the	**
 **			remainder of an integer division,	**
 **			based on simple arithmetic operations,	**
 **			taking into account the following	**
 **			formula:				**
 **			remainder = [ divisor *			**
 **				(dividend / divisor) ]		**
 ** Input Parms:	const size_t szt_dividen,		**
 **			const size_t szt_divisor.		**
 ** Output Parms:	None.					**
 ** Result:		The result obtained by the function is	**
 **			the remainder of an integer division,	**
 **			such that it is obtained by		**
 **			remainder = (divisor *			**
 **				(dividend / divisor)).		**
 ****************************************************************/
size_t szt_remainder(const size_t szt_dividen, const size_t szt_divisor)
	{
		return szt_dividen - (szt_divisor * (szt_dividen / szt_divisor));
	}

/*****************************************************************
 ** Function:		size_t *ptr_create_szt_remnant_lst	**
 **				(const size_t szt_cte_dividen,	**
 **				 const size_t szt_cte_divisor,	**
 **				 size_t *ptr_szt_quotient,	**
 **				 size_t *ptr_szt_remainder);	**
 ** Explanation:	The purpose of this function is to carry**
 **			out a series of iterations in which the	**
 **			divisor is subtracted from the dividend	**
 **			until the first is less than the second.**
 **			In this way, each iteration is stored in**
 **			an unsigned long integer pointer to know**
 **			the calculation process. Both the	**
 **			quotient and the remainder of the	**
 **			calculated division are returned in the	**
 **			current parameters of this		**
 **			pass-by-reference function.		**
 ** Input Parms:	const size_t szt_cte_dividen,		**
 **			const size_t szt_cte_divisor,		**
 **			size_t *ptr_szt_quotient,		**
 **			size_t *ptr_szt_remainder.		**
 ** Output Parms:	size_t *ptr_szt_quotient,		**
 **			size_t *ptr_szt_remainder.		**
 ** Result:		As many iterations are carried out as	**
 **			the dividend of the divisor is large,	**
 **			and in each iteration the divisor is	**
 **			subtracted from the dividend and a	**
 **			counter is incremented so that the	**
 **			quotient is reached and when the	**
 **			dividend becomes less than the divisor,	**
 **			then we have a quotient and a remainder	**
 **			of that entire division.		**
 ****************************************************************/
size_t *ptr_create_szt_remnant_lst(const size_t szt_cte_dividen, const size_t szt_cte_divisor, size_t *ptr_szt_quotient, size_t *ptr_szt_remainder)
	{
		/* Initial declaration of work variables. */
		size_t *ptr_szt_remnant_list = NULL;

		size_t szt_quotient = V_ZERO;
		size_t szt_remainder = szt_cte_dividen;
		size_t szt_size_lst = szt_cte_dividen / szt_cte_divisor;

		//Iterate until the dividend is less than the divisor.
		if (ptr_szt_remnant_list = (size_t *) malloc(szt_size_lst * sizeof(size_t)))
			while (szt_remainder >= szt_cte_divisor)
				*(ptr_szt_remnant_list + szt_quotient++) = (szt_remainder -= szt_cte_divisor);

		/* Update the values of the referenced data. */
		*ptr_szt_quotient = szt_quotient;
		*ptr_szt_remainder = szt_remainder;

		return ptr_szt_remnant_list;
	}

/*****************************************************************
 ** Function:		size_t szt_view_szt_remnant_lst		**
 **				(const size_t *const		**
 **					ptr_szt_remnant_lst,	**
 **				 const size_t			**
 **					szt_size_limit_lst);	**
 ** Explanation:	In this function, the pointer that	**
 **			stored each of the iterations of the	**
 **			residual calculations is read to arrive	**
 **			at both the quotient and the remainder	**
 **			of an integer division.			**
 ** Input Parms:	const size_t *ptr_szt_remnant_lst,	**
 **			const size_t szt_size_limit_lst.	**
 ** Output Parms:	const size_t *ptr_szt_remnant_lst.	**
 ** Result:		The number of iterations made to reach	**
 **			the remainder, which is the quotient of	**
 **			the requested integer division, is	**
 **			returned as a result, as well as the	**
 **			results tracked on the screen.		**
 ****************************************************************/
size_t szt_view_szt_remnant_lst(const size_t *const ptr_szt_remnant_lst, const size_t szt_size_limit_lst)
	{
		/* Initial declaration of work variables. */
		size_t szt_idx_iters = V_ZERO;

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ Obtaining residual calculations.  +\n");
		printf("+---|----+---|----+---|----+---|----+\n");

		for (szt_idx_iters = V_ZERO; szt_idx_iters < szt_size_limit_lst; szt_idx_iters++)
			printf("#[%ld]\t:\t[%ld].\n", szt_idx_iters, *(ptr_szt_remnant_lst + szt_idx_iters));

		printf("[%ld] Obtained output results.\n", szt_idx_iters);

		return szt_idx_iters;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this function, the function that	**
 **			generates the pointer that will store	**
 **			each residual calculation of an integer	**
 **			division is called.			**
 **			It will also call a function that will	**
 **			display said pointer generated with the	**
 **			calculations carried out and a direct	**
 **			function to obtain the remainder of the	**
 **			division by arithmetic operations an	**
 **			entire division.			**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The result of this main function is to	**
 **			display various results returned by the	**
 **			various calls to the functions		**
 **			implemented in this program.		**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		size_t *ptr_szt_residuum_list = NULL;

		size_t szt_dividen = V_ZERO;
		size_t szt_divisor = V_ZERO;
		size_t szt_idx_iters = V_ZERO;

		size_t szt_quotient = V_ZERO;
		size_t szt_residuum = V_ZERO;
		size_t szt_rest = V_ZERO;

		/* Requisition of the dividend and the division divisor. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+   Obtaining division remainder.   +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Dividend : ");
		scanf("%ld", &szt_dividen);
		printf("Divisor  : ");
		scanf("%ld", &szt_divisor);

		/* Results of an iterative function to obtain the remainder. */
		ptr_szt_residuum_list = ptr_create_szt_remnant_lst(szt_dividen, szt_divisor, &szt_quotient, &szt_rest);

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+     Division residuum results.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Dividend  :\t[%ld].\n", szt_dividen);
		printf("| Divisor   :\t[%ld].\n", szt_divisor);
		printf("+--------+--------+--------+--------+\n");
		printf("| Quotient  :\t[%ld].\n", szt_quotient);
		printf("| Remainder :\t[%ld].\n", szt_rest);
		printf("+---|----+---|----+---|----+---|----+\n");

		/* View the residual calculations for the entire division. */
		szt_idx_iters = szt_view_szt_remnant_lst(ptr_szt_residuum_list, szt_dividen / szt_divisor);

		/* Obtaining the remainder through a direct function. */
		szt_residuum = szt_remainder(szt_dividen, szt_divisor);
		printf("\nThe remainder of [%ld] divided by [%ld] is equal to: [%ld].\n", szt_dividen, szt_divisor, szt_residuum);

		return V_ZERO;
	}
