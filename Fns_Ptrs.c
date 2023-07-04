/*** Pointers to functions that return pointers to structures. ***
 ** Source Code:	Fns_Ptrs.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Monday, July 31, 2023.          	**
 ** Purpose:		This program uses pointers to functions,**
 **			which in turn return pointers to	**
 **			structures as their result.		**
 **			+---|----+---|----+---|----+---|----+-- **
 **			The program itself asks for a base and	**
 **			an exponent to which to raise that base	**
 **			and returns a listing of previous	**
 **			calculations up to the required power.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

//Numeric Symbolic Constants.
#define V_ONE	1
#define V_ZERO	0

/*****************************************************************
 * Macros:							**
 * 1. To get the absolute value of any variable number.		**
 * 2. To calculate the number of bytes that need to be reserved	**
 *    for memory and for a pointer.				**
 ****************************************************************/
#define ABSOLUTE(value)		( ( ( value ) == V_ZERO ) ? V_ZERO :	\
			  	( ( value ) > V_ZERO ) ? ( value ) : ( -value ) )

#define RESERVED_BYTES(bytes)	( ABSOLUTE ( ( bytes ) ) + V_ONE )

/*****************************************************************
 ** Structure that returns the iteration number and the		**
 ** calculation returned by an implemented function called	**
 ** 'power', from the initial value 'zero'' to the given	**
 ** exponent number.						**
*****************************************************************/
struct str_dbl_potw
	{
		int int_idx;
		double dbl_result;
	}	s_dbl_potw = {V_ZERO};

/*****************************************************************
 ** Function:		*ptr_str_dbl_potw.			**
 ** Explanation:	This function returns a pointer to a	**
 **			structure containing each iteration of	**
 **			each previous calculation performed to	**
 **			obtain a number raised to a given power.**
 **								**
 **			The pointer has the number of elements	**
 **			indicated by the exponent plus the unit.**
 ** Input Parms:	integer int_base,			**
 **			integer int_exp.			**
 ** Output Parms:	None.					**
 ** Result:		The sequence, cycle by cycle, of each	**
 **			cumulative calculation that was actually**
 **			performed to raise a given number to a	**
 **			given power is returned, using the	**
 **			formulas:				**
 **								**
 **			dbl_result*=int_base.	Positive exp.	**
 **			dbl_result/=int_base.	Negative exp.	**
 **								**
 **			Such that each multiplication is stored	**
 **			in an element of the pointer or dynamic **
 **			array returned by this function.	**
 ****************************************************************/
struct str_dbl_potw *ptr_str_dbl_potw(int int_base, int int_exp)
	{
		/* The work variables of this function are initialized. */
		struct str_dbl_potw *p_str_dbl_potw=NULL;
		/* Number of bytes to reserve. */
		int int_reserved_bytes=RESERVED_BYTES(int_exp);

		/* ---------------------------------------------------------------
		 * Validate if the exponent sent is zero, positive or negative,	--
		 * and according to its	own value, determine the calculation	--
		 * algorithm to follow.						--
		 * -------------------------------------------------------------*/
		int int_exp_pow=ABSOLUTE(int_exp);

		/* Return initial value. */
		double dbl_ret=V_ONE;

		/* ---------------------------------------------------------------
		 * First, the necessary memory space is created	to accommodate	--
		 * the pointer with the number of octets necessary for the	--
		 * structure that will store each iteration of the successive	--
		 * multiplications to reach a base raised to a given power.	--
		 * -------------------------------------------------------------*/
		if ((p_str_dbl_potw = (struct str_dbl_potw *) malloc((int_reserved_bytes) * sizeof(struct str_dbl_potw))) != NULL)
			/* -------------------------------------------------------
			 * The calculation that is carried out to raise a base	--
			 * to a positive power is to multiply or to divide (1/x)--
			 * the base successively as many times as the value of	--
			 * the exponent indicates.				--
			 * -----------------------------------------------------*/
			for (int int_i=V_ZERO; int_i <= int_exp_pow; int_i++)
				{
					/* Array notation for pointers. */
					p_str_dbl_potw[int_i].int_idx = int_i;
					p_str_dbl_potw[int_i].dbl_result = dbl_ret;

					/* Accumulator multiplier or divider. */
					dbl_ret = (int_exp > V_ZERO) ? dbl_ret * int_base :
						  (int_exp < V_ZERO) ? dbl_ret / int_base : V_ONE;
				}

		return p_str_dbl_potw;
	}

/*****************************************************************
 ** Function:		printFn.				**
 ** Explanation:	This function returns a series of	**
 **			messages on the screen that contain	**
 **			each of the elements returned by the	**
 **			structure pointer of the function	**
 *+			pointer that is responsible for raising **
 **			a given numerical base to a given	**
 **			exponent, through a cycle that iteration**
 **			by iteration shows punctually each	**
 **			previous calculation to achieve the	**
 **			desired result.				**
 ** Input Parms:	integer int_base,			**
 **			integer int_exp,			**
 **			struct str_dbl_potw *(*pFn)().		**
 ** Output Parms:	None.					**
 ** Result:		It just returns the series of messages	**
 **			that result from scrutinizing the	**
 **			structure pointer that returns the	**
 *+			function pointer that returns each	**
 **			intermediate or preliminary calculation	**
 **			of raising a base 'x' to a power 'y'.	**
 **			At the moment, the function name	**
 **			does not return any value itself.	**
 ****************************************************************/
void printFn(int int_base, int int_exp, struct str_dbl_potw *(*pFn)())
	{
		/* The work variables of this function are initialized. */
		struct str_dbl_potw *p_str_dbl_potw = NULL;

		/* ---------------------------------------------------- **
		 * A call to a pointer to a function that returns	**
		 * a pointer to a structure of values.			**
		 * ---------------------------------------------------- */
		p_str_dbl_potw = (*pFn)(int_base, int_exp);

		/* ---------------------------------------------------------------
		 * Validate if the exponent sent is zero, positive or negative,	--
		 * and according to its	own value, determine the calculation	--
		 * algorithm to follow.						--
		 * -------------------------------------------------------------*/
		int int_exp_pow = ABSOLUTE(int_exp);

		/*----------------------------------------------------------------
		 * Number of octets that the structure generated by multiplying	--
		 * a number by itself has until reaching the desired power.	--
		 *--------------------------------------------------------------*/
		long lng_bytes_generated = RESERVED_BYTES(int_exp_pow) * sizeof(struct str_dbl_potw);

		printf("\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("|     Cálculos previos para alcanzar: '+-x' ^ '+-y'.    |\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("| Coeficientes obtenidos en captura:			|\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("| Base	    'x'     : [%d].\n", int_base);
		printf("| Exponente 'y'     : [%d].\n", int_exp);
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("| Apuntadores conseguidos en cálculos:			|\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("| Dirección 'Fnctn' : [%p].\n", pFn);
		printf("| Dirección 'strct' : [%p].\n", p_str_dbl_potw);
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("| Estructuras conseguidas en cálculos:			|\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("| Ocurrencias #     : [%d].\n", RESERVED_BYTES(int_exp_pow));
		printf("| Longitud x ocurr  : [%d].\n", sizeof(struct str_dbl_potw));
		printf("| Octetos en total  : [%d].\n", lng_bytes_generated);
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");

		for (int int_i=V_ZERO; int_i <= int_exp_pow; int_i++)
			/* Pointer notation proper. */
			printf("| [%d] : [%lf].\n", (p_str_dbl_potw + int_i)->int_idx, (p_str_dbl_potw + int_i)->dbl_result);

		printf("+---+----+---+----+---+----+---+----+---+----+---+----+--\n");
		printf("\n");
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In the main module of this program, the	**
 **			knowledge of using pointers to		**
 **			functions, pointers to structures and	**
 **			the notation for both pointers and	**
 **			arrays that is used interchangeably is	**
 **			reinforced.				**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		In the main function of this program,	**
 **			the base and the exponent to which it is**
 **			going to be raised are requested, and a **
 **			pointer is prepared to a function that	**
 **			will in turn return a pointer to a	**
 **			structure and that will be read,	**
 **			iteration by iteration, by another	**
 **			function that will launch messages on	**
 **			the screen of each previous calculation	**
 **			made to reach the result of the desired	**
 **			power.					**
 ****************************************************************/
int main(int argc, char *argv[])
	{
		int int_base = V_ZERO;
		int int_exp = V_ZERO;

		printf("+---|----+---|----+---+---|----+---|----+---|\n");
		printf("|   Apuntadores a funciones y estructuras.  |\n");
		printf("+---|----+---|----+---+---|----+---|----+---|\n");

		printf("Base: ");
		scanf("%i", &int_base);
		printf("Exponente: ");
		scanf("%i", &int_exp);

		printFn(int_base, int_exp, ptr_str_dbl_potw);

		return V_ZERO;
	}
