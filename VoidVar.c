/* This program uses a 'void' type function to store a certain value
   depending on the type of variable you want to return. */
#include <stdio.h>

#define	V_LOWER_C	'\x63'
#define	V_LOWER_F	'\x66'
#define	V_LOWER_I	'\x69'

#define V_ZERO  	0

//Function that receives and returns a pointer of type 'void'.
void *catchVar(void *vd_ptr, char typ)
	{
		if (typ == V_LOWER_C)
			{
				//If the variable is of type 'character'.
				printf("Enter a character value: ");
				scanf(" %c", (char*) vd_ptr);  //A space must come before '%c' to clear the buffer.
			}
		else if (typ == V_LOWER_F)
			{
				//If the variable is of type 'single precision floating point'.
				printf("Enter a floating  value: ");
				scanf("%f", (float*) vd_ptr);
			}
		else if (typ == V_LOWER_I)
			{
				//If the variable is of type 'integer'.
				printf("Enter an integer  value: ");
				scanf("%d", (int*) vd_ptr);
			}

		return vd_ptr; //We return the memory address of the empty pointer.
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char CharValue = V_ZERO;
		float FloatValue = V_ZERO;
		int IntegerValue = V_ZERO;
		void *vd_ptr = NULL;

		printf("Program that returns a 'void' type pointer and converts it.\n");

		//Example with a 'char' value.
		vd_ptr = catchVar(&CharValue, V_LOWER_C);
		printf("* Char    : [%p] : [%p] = [%c].\n", &CharValue, vd_ptr, *((char*) vd_ptr));

		//Example with a 'single precision floating point' value.
		vd_ptr = catchVar(&FloatValue, V_LOWER_F);
		printf("* Float   : [%p] : [%p] = [%.2f].\n", &FloatValue, vd_ptr, *((float*) vd_ptr));

		//Example with an 'integer' value.
		vd_ptr = catchVar(&IntegerValue, V_LOWER_I);
		printf("* Integer : [%p] : [%p] = [%d].\n", &IntegerValue, vd_ptr, *((int*) vd_ptr));

		return V_ZERO;
	}
