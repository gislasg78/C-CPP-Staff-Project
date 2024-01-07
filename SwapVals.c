/******* Exchange values between any two variables in C. *********
 ** Source Code:	SwapVals.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
 ** Purpose:		This program uses a function that uses	**
 **			templates in its formal parameters and	**
 **			that specifically takes care of		**
 **			swapping any two values and returning	**
 **			them inverted.				**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Work Symbolic Constants.
#define V_ZERO	0

/*****************************************************************
 ** Function:		swapper.				**
 ** Explanation:	This function doesn't actually return	**
 **			any value, it just swaps two variables	**
 **			that are passed to that function as	**
 **			formal parameters in its function header**
 **			and swaps them between them.		**
 ** Input Parms:	int *ptr_int_left_value,		**
 **			int *ptr_int_right_value.		**
 ** Output Parms:	int *ptr_int_left_value,		**
 **			int *ptr_int_right_value.		**
 ** Result:		This function primarily swaps the values**
 **			of two variables passed as current	**
 **			parameters and returns them in the same **
 **			way in the same variables.		**
 ****************************************************************/
void swapper(int *ptr_int_left_value, int *ptr_int_right_value)
	{
		int int_aux_value=V_ZERO, *ptr_int_aux_value = &int_aux_value;

		*ptr_int_aux_value = *ptr_int_left_value;
		*ptr_int_left_value = *ptr_int_right_value;
		*ptr_int_right_value = *ptr_int_aux_value;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function of this program shows	**
 **			a series of messages before and after	**
 **			calling a generic function that		**
 **			exchanges the values contained in two	**
 **			variables and shows their respective	**
 **			results before and after the operation	**
 **			executed by said exchange function.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The main function, itself, just displays**
 **			a series of messages before and after	**
 **			exchanging the value of two		**
 **			user-supplied variables.		**
 ****************************************************************/
int main()
	{
		/* Initialization of preliminary variables. */
		int int_num_X = V_ZERO;
		int int_num_Y = V_ZERO;
		int *ptr_int_num_X = &int_num_X;
		int *ptr_int_num_Y = &int_num_Y;

		printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|     Change of place of any values.    |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("Enter two numeric values:\n");
		printf("Value [x] : ");
		scanf("%d", &int_num_X);

		printf("Value [y] : ");
		scanf("%d", &int_num_Y);

		/* Messages before the exchange of values. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|Starting initials. Before the exchange.|\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p] = [%d].\n", &int_num_X, *ptr_int_num_X);
		printf("| Value [y] : [%p] = [%d].\n", &int_num_Y, *ptr_int_num_Y);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		swapper(ptr_int_num_X, ptr_int_num_Y);	//First Function that swaps variables.

		/* Messages after the exchange of values. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Values exchanged. After the exchange. |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p] = [%d].\n", ptr_int_num_X, *ptr_int_num_X);
		printf("| Value [y] : [%p] = [%d].\n", ptr_int_num_Y, *ptr_int_num_Y);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		swapper(&int_num_X, &int_num_Y);	//Second Function that swaps variables.

		/* Value restore messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|       Restoring initial values.       |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p] = [%d].\n", ptr_int_num_X, *ptr_int_num_X);
		printf("| Value [y] : [%p] = [%d].\n", ptr_int_num_Y, *ptr_int_num_Y);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("\n");

		return V_ZERO;
	}
