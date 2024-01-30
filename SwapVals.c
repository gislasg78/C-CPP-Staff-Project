/**Exchange values and addresses between any two variables in C.**
 ** Source Code:	SwapVals.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
 ** Purpose:		This program uses a function that uses	**
 **			templates in its formal parameters and	**
 **			that specifically takes care of		**
 **			swapping any two values or addresses	**
 **			and returning them inverted.		**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				Left  Value [x] : 100.		**
 **				Right Value [y] : 200.		**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

//Work Symbolic Constants.
#define V_ZERO	0


/*****************************************************************
 ** Function:		void swap_int (int *ptr_int_left_value,	**
 **				int *ptr_int_right_value).	**
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
void swap_int(int *ptr_int_left_value, int *ptr_int_right_value)
	{
		/* Initialization of preliminary variables. */
		int *ptr_int_aux_value = NULL;

                /* Memory space is reserved for an entire pointer. */
		if (ptr_int_aux_value = (int *) malloc(sizeof(int)))
			{
				*ptr_int_aux_value = *ptr_int_left_value;
				*ptr_int_left_value = *ptr_int_right_value;
				*ptr_int_right_value = *ptr_int_aux_value;

				free(ptr_int_aux_value);
			}
		else
                        printf("Insufficient memory space to create entire pointer...\n");
	}

/*****************************************************************
 ** Function:           void swap_ptr_int                       **
 **                             (int **ptr_ptr_int_left_value,  **
 **                              int **ptr_ptr_int_right_value).**
 ** Explanation:	This function does not return any value,**
 **			but is responsible for exchanging the	**
 **			memory addresses of two simple pointers	**
 **			sent as current parameters to the	**
 **			arguments of this function, which has as**
 **			formal parameters pointers of pointers	**
 **			to integers, and in this way, it does an**
 **			exchange of their addresses creating a	**
 **			dynamic variable at runtime also of type**
 **			double integer pointer.			**
 ** Input Parms:        int **ptr_ptr_int_left_value,           **
 **                     int **ptr_ptr_int_right_value.          **
 ** Output Parms:       int **ptr_ptr_int_left_value,           **
 **                     int **ptr_ptr_int_right_value.          **
 ** Result:		This function exchanges the addresses 	**
 **			between two pointers creating a double	**
 **			auxiliary pointer of type integer to	**
 **			maneuver the operations performed.	**
 ****************************************************************/
void swap_ptr_int(int **ptr_ptr_int_left_value, int **ptr_ptr_int_right_value)
        {
		/* Initialization of preliminary variables. */
                int **ptr_ptr_int_aux_value = NULL;

                /* Memory space is reserved for an entire pointer of pointers. */
                if (ptr_ptr_int_aux_value = (int **) malloc(sizeof(int *)))
                        {
                                *ptr_ptr_int_aux_value = *ptr_ptr_int_left_value;
                                *ptr_ptr_int_left_value = *ptr_ptr_int_right_value;
                                *ptr_ptr_int_right_value = *ptr_ptr_int_aux_value;

                                free(ptr_ptr_int_aux_value);
                        }
                else
                        printf("Insufficient memory space to create entire pointer pointer...\n");
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
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				Left  Value [x] : 100.		**
 **				Right Value [y] : 200.		**
 ****************************************************************/
int main()
	{
		/* Initialization of preliminary variables. */
		int int_left_value = V_ZERO;
		int int_right_value = V_ZERO;
		int *ptr_int_left_value = &int_left_value;
		int *ptr_int_right_value = &int_right_value;
		int **ptr_ptr_int_left_value = &ptr_int_left_value;
		int **ptr_ptr_int_right_value = &ptr_int_right_value;

		/* Incomings request window. */
		printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|     Change of place of any values.    |\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("Enter two numeric values:\n");
		printf("Value [x] : ");
		scanf("%d", &int_left_value);

		printf("Value [y] : ");
		scanf("%d", &int_right_value);


		/* Call to the function that only changes the values of the specified variables. */
		/* Messages before the exchange of values. */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("| Starting values. Before the exchange. |\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|         Source input variables.       |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
		printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|        Source mapping pointers.       |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
		printf("|---+----+---+----+---+----+---+----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		/* Messages after the exchange of values. */
		swap_int(ptr_int_left_value, ptr_int_right_value);		//First Function that swaps variables.

                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("| Values exchanged. After the exchange. |\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		/* Value restore messages. */
		swap_int(&int_left_value, &int_right_value);			//Second Function that swaps variables.

                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|       Restoring initial values.       |\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");


		/* Call to the function that only changes the addresses of the specified variables. */
		/* Messages before the exchange of addresses. */
                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|Starting addresses. Before the exchange|\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		/* Messages after the exchange of addresses. */
		swap_ptr_int(&ptr_int_left_value, &ptr_int_right_value);	//First Function that swaps addresses.

                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|Addresses exchanged. After the exchange|\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		/* Addresses restore messages. */
		swap_ptr_int(&ptr_int_left_value, &ptr_int_right_value);	//Second Function that swaps addresses.

                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|     Restoring initial addresses.      |\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");


		/* Call to the function that only changes the double pointers of the specified variables. */
		/* Messages before the exchange of double pointers. */
                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|Starting pointers. Before the exchange.|\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		/* Messages after the exchange of double pointers. */
		swap_ptr_int(ptr_ptr_int_left_value, ptr_ptr_int_right_value);	//First Function that swaps double pointers.

                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|Pointers exchanged. After the exchange.|\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		/* Double pointers restore messages. */
		swap_ptr_int(ptr_ptr_int_left_value, ptr_ptr_int_right_value);	//Second Function that swaps double pointers.

                printf("\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|   Restoring initial double pointers.  |\n");
                printf("+===|====+===|====+===|====+===|====+===|\n");
                printf("|         Source input variables.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p] = [%d].\n", &int_left_value, int_left_value);
                printf("| Value [y] : [%p] = [%d].\n", &int_right_value, int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("|        Source mapping pointers.       |\n");
                printf("+---|----+---|----+---|----+---|----+---|\n");
                printf("| Value [x] : [%p].\n", &ptr_int_left_value);
                printf("| Value [x] : [%p] = [%d].\n", ptr_int_left_value, *ptr_int_left_value);
                printf("|---+----+---+----+---+----+---+----+---|\n");
                printf("| Value [y] : [%p].\n", &ptr_int_right_value);
                printf("| Value [y] : [%p] = [%d].\n", ptr_int_right_value, *ptr_int_right_value);
                printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Source mapping double pointers.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_left_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_left_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_left_value, **ptr_ptr_int_left_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [y] : [%p].\n", &ptr_ptr_int_right_value);
		printf("| Value [y] : [%p].\n", ptr_ptr_int_right_value);
		printf("| Value [y] : [%p] = [%d].\n", *ptr_ptr_int_right_value, **ptr_ptr_int_right_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		return V_ZERO;
	}
