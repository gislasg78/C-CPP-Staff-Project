/* This program uses a 'void' type function to store a certain value
   depending on the type of variable you want to return. */
#include <stdio.h>

/* Symbolic work constants. */
#define	V_LOWER_C	'\x63'
#define V_LOWER_D       '\x64'
#define	V_LOWER_F	'\x66'
#define	V_LOWER_I	'\x69'
#define V_LOWER_L       '\x6c'
#define V_LOWER_S       '\x73'

#define V_ZERO  	0

//Function that receives and returns a pointer of type 'void'.
void *catchVar(void *VoidPointer, char typ)
	{
		if (typ == V_LOWER_C)
			{
				//If the variable is of type 'character'.
				printf("\nEnter a character value: ");
				scanf(" %c", (char *) VoidPointer);	//A space must come before '%c' to clear the buffer.
				printf("[%c].\n", *((char *) VoidPointer));
			}
		else if (typ == V_LOWER_D)
			{
				//If the variable is of type 'double'.
				printf("\nEnter a double    value: ");
				scanf("%lf", (double *) VoidPointer);
				printf("[%lf].\n", *((double *) VoidPointer));
			}
		else if (typ == V_LOWER_F)
			{
				//If the variable is of type 'single precision floating point'.
				printf("\nEnter a floating  value: ");
				scanf("%f", (float *) VoidPointer);
				printf("[%f].\n", *((float *) VoidPointer));
			}
		else if (typ == V_LOWER_I)
			{
				//If the variable is of type 'integer'.
				printf("\nEnter an integer  value: ");
				scanf("%d", (int *) VoidPointer);
				printf("[%d].\n", *((int *) VoidPointer));
			}
		else if (typ == V_LOWER_L)
			{
				//If the variable is of type 'long'.
				printf("\nEnter  a long     value: ");
				scanf("%ld", (long *) VoidPointer);
				printf("[%ld].\n", *((long *) VoidPointer));
			}
		else if (typ == V_LOWER_S)
			{
				//If the variable is of type 'integer'.
				printf("\nEnter  a short    value: ");
				scanf("%hi", (short *) VoidPointer);
				printf("[%hi].\n", *((short *) VoidPointer));
			}

		printf("+ Receiver: [%p] : [%p].\n", &VoidPointer, VoidPointer);

		return VoidPointer; //We return the memory address of the empty pointer.
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char CharValue = V_ZERO;
		double DoubleValue = V_ZERO;
		float FloatValue = V_ZERO;
		int IntegerValue = V_ZERO;
		long LongValue = V_ZERO;
		short ShortValue = V_ZERO;
		void *VoidPtr = NULL;

		printf("Program that returns a 'void' type pointer and converts it.\n");

		//Example with a 'char' value.
		VoidPtr = catchVar(&CharValue, V_LOWER_C);
		printf("* Char    : [%p] : [%p] = [%c].\n", &CharValue, VoidPtr, *((char *) VoidPtr));

		//Example with a 'double precision floating point' value.
		VoidPtr = catchVar(&DoubleValue, V_LOWER_D);
		printf("* Double  : [%p] : [%p] = [%lf].\n", &DoubleValue, VoidPtr, *((double *) VoidPtr));

		//Example with a 'single precision floating point' value.
		VoidPtr = catchVar(&FloatValue, V_LOWER_F);
		printf("* Float   : [%p] : [%p] = [%f].\n", &FloatValue, VoidPtr, *((float *) VoidPtr));

		//Example with an 'integer' value.
		VoidPtr = catchVar(&IntegerValue, V_LOWER_I);
		printf("* Integer : [%p] : [%p] = [%d].\n", &IntegerValue, VoidPtr, *((int *) VoidPtr));

		//Example with an 'long' value.
		VoidPtr = catchVar(&LongValue, V_LOWER_L);
		printf("* Long    : [%p] : [%p] = [%ld].\n", &LongValue, VoidPtr, *((long *) VoidPtr));

		//Example with an 'short' value.
		VoidPtr = catchVar(&ShortValue, V_LOWER_S);
		printf("* Short   : [%p] : [%p] = [%hi].\n", &ShortValue, VoidPtr, *((short *) VoidPtr));

		return V_ZERO;
	}
