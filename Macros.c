/****************** Macros and functions in C. *******************
 ** Source Code:        Macros.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		The primary purpose of this program is	**
 **			to show the use of macros and functions	**
 **			in C, and to observe the different	**
 **			results that are generated both at	**
 **			preprocessing and compilation time, in	**
 **			such a way that substantial results can	**
 **			be seen when preferring the use of one	**
 **			or more another encoding method.	**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				First Number:	10.		**
 **				Second Number:	20.		**
*****************************************************************/
//C Standard Libraries.
#include   <stdio.h>

//Exemplification macros.
#define    INPUT(msg, fmt, dat)		printf(msg ": "); \
                    			scanf(#fmt, &int_##dat);
#define    MINOR(x, y)			( ( (x) < (y) ) ? (x) : (y) )

//Symbolic work constants.
#define    V_ZERO			0

/*****************************************************************
 ** Function:		int int_minor	(const int int_x,	**
 **					const int int_y);	**
 ** Explanation:	This function returns as the only result**
 **			the smaller of two numbers compared	**
 **			using the ternary operator and said	**
 **			smaller number is returned as part of	**
 **			the call to the function name.		**
 ** Input Parms:	const int int_x,			**
 **			const int int_y.			**
 ** Output Parms:	None.					**
 ** Result:		Returns as a result the smallest integer**
 **			value of two integers.			**
 ****************************************************************/
int int_minor(const int int_x, const int int_y)
	{
		return ((int_x < int_y) ? int_x : int_y);
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This main module is responsible for	**
 **			making calls to both the macro and the	**
 **			function, both implemented in C, and	**
 **			shows details of both the macro and the	**
 **			function in their respective output	**
 **			results, to appreciate and evaluate	**
 **			their operation and execution.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		In this main function the result is to	**
 **			see the substitution and recalculation	**
 **			of the different variables used as	**
 **			current parameters and sent as formal	*+
 **			parameters to the arguments of both the	**
 **			C macro and its implemented function.	**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				First Number:	10.		**
 **				Second Number:	20.		**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		int int_smaller = V_ZERO;
		int int_first = V_ZERO;
		int int_second = V_ZERO;

		/* Welcome window and data request. */
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+  Smallest numbers verification.   +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| [%s]\t:\t[%d].\n", __FILE__, __LINE__);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| [%s]\t:\t[%s].\n", __DATE__, __TIME__);
		printf("+---|----+---|----+---|----+---|----+\n");

		/* Compiler directive used to know if a macro is defined. */
		#if defined(V_ZERO)
			INPUT("First number\t", %d, first);
			INPUT("Second number\t", %d, second);
		#else
			printf("First number\t: ");
			scanf("%d", &int_first);
			printf("Second number\t: ");
			scanf("%d", &int_second);
		#endif

		/* Using the replaceable macro by the C preprocessor. */
		int_smaller = MINOR(int_first--, int_second--);

		/* Window showing the side effect. Value decremented twice. */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+     Results using the C Macro.    +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| MINOR\t\t:\t[%02d].\n", int_smaller);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| First\t\t:\t[%02d].\n", int_first);
		printf("| Second\t:\t[%02d].\n", int_second);
		printf("+---|----+---|----+---|----+---|----+\n");

		/* Llamando a la función. */
		printf("\n");

		/* Compiler directive used to know if a macro is not defined. */
		#if !defined(V_ZERO)
			INPUT("First number\t", %d, first);
			INPUT("Second number\t", %d, second);
		#else
			printf("First number\t: ");
			scanf("%d", &int_first);
			printf("Second number\t: ");
			scanf("%d", &int_second);
		#endif

		/* Using the function to find out the smallest of two numbers. */
		int_smaller = int_minor(int_first--, int_second--);

		/* Window showing the effect of calling the function implemented in C. */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+   Results using the C Function.   +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| minor\t\t:\t[%2.d].\n", int_smaller);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| First\t\t:\t[%2.d].\n", int_first);
		printf("| Second\t:\t[%2.d].\n", int_second);
		printf("+---|----+---|----+---|----+---|----+\n");

		return V_ZERO;
	}
