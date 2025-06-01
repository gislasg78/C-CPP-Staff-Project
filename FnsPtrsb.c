/* This program exemplifies calls to function pointers
with variable numbers of formal parameters
(command line arguments).*/
#include <stdio.h>

/* Symbolic work constants. */
#define V_ZERO	0

//Compare the largest of three values.
int greater_three(int x, int y, int z)
	{
		int major = V_ZERO;

		if (x > y)
			if (x > z)
				major = x;
			else
				major = y;
		else
			if (y > z)
				major = y;
			else
				major = z;

		return major;
	}

//Compares the largest of two values.
int greater_two(int x, int y)
	{
		return (x > y) ? x : y;
	}

/* Function that receives a pointer to a function and its own parameters. */
enum enm_opt_function
	{
		enm_opt_fn_greater_two,
		enm_opt_fn_greater_three
	} enm_opt_fn;

/* Function that receives a function pointer with all possible parameters. */
int make_comparison(enum enm_opt_function enm_opt_fn, int x, int y, int z, int (*compare)())
	{
		/* Preliminary working variables. */
		int result = V_ZERO;

		/* Validation of the type of function to be called with its function pointer. */
		switch(enm_opt_fn)
			{
				case enm_opt_fn_greater_two:
					result = compare(x, y);
					break;

				case enm_opt_fn_greater_three:
					result = (*compare)(x, y, z);
					break;

				default:
					printf("\nThe option: [%d] entered is not valid. Please correct it!\n", (int) enm_opt_fn);
					break;

			}

		return result;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int result = V_ZERO;
		int x = V_ZERO, y = V_ZERO, z = V_ZERO;
		int (*compare)() = NULL;    //Pointer to function with variable number of arguments.

		/* Preliminary request for input data. */
		printf("Pointer to function with variable number of arguments.\n");
		printf("Value 'x' : ");
		scanf("%d", &x);

		printf("Value 'y' : ");
		scanf("%d", &y);

		printf("Value 'z' : ");
		scanf("%d", &z);

		/* Viewing output results. */
		printf("\nResults of function calls.\n");

		compare = greater_two;      //Assigning the function name to the function pointer.
		result = (*compare)(x, y);  //Call to the function pointer with the specified parameters.
		printf("(x = [%d], y = [%d]).\t\tMajor: {%d}.\n", x, y, result);

		compare = greater_three;    //Assigning the function name to the function pointer.
		result = compare(x, y, z);  //Call to the function pointer with the specified parameters.
		printf("(x = [%d], y = [%d], z = [%d]).\tMajor: {%d}.\n", x, y, z, result);

		/* Results of a call to a function that accepts a function pointer. */
		printf("\nOutcomes of function calls.\n");
		printf("(x = [%d], y = [%d]).\t\tMajor: {%d}.\n", x, y, make_comparison(enm_opt_fn_greater_two, x, y, V_ZERO, greater_two));
		printf("(x = [%d], y = [%d], z = [%d]).\tMajor: {%d}.\n", x, y, z, make_comparison(enm_opt_fn_greater_three, x, y, z, greater_three));

		return V_ZERO;
	}
