/* This program uses a 'void' type function to store a certain value
   depending on the type of variable you want to return. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic work constants. */
#define	V_LOWER_C	'\x63'
#define V_LOWER_D       '\x64'
#define	V_LOWER_F	'\x66'
#define	V_LOWER_I	'\x69'
#define V_LOWER_L       '\x6c'
#define V_LOWER_S       '\x73'

#define V_ZERO  	0

//Function that receives and returns a pointer of type 'void'.
void *catchVar(void **VoidPtrPtr, char typ)
	{
		void *VoidPointer = NULL;

		if (typ == V_LOWER_C)
			{
				//If the variable is of type 'character'.
				if (VoidPointer = malloc(sizeof(char)))
					{
						printf("\nEnter a character value  : ");
						scanf(" %c", (char *) VoidPointer);  //A space must come before '%c' to clear the buffer.
						printf("[%c].\n", *((char*) VoidPointer));
					}
				else
					perror("There is not enough memory space for the char variable allocation...");
			}
		else if (typ == V_LOWER_D)
			{
				//If the variable is of type 'double precision floating point'.
				if (VoidPointer = malloc(sizeof(double)))
					{
						printf("\nEnter a double value     : ");
						scanf("%lf", (double *) VoidPointer);
						printf("[%lf].\n", *((double*) VoidPointer));
					}
				else
					perror("There is not enough memory space for the double variable allocation...");
			}
		else if (typ == V_LOWER_F)
			{
				//If the variable is of type 'single precision floating point'.
				if (VoidPointer = malloc(sizeof(float)))
					{
						printf("\nEnter a float value      : ");
						scanf("%f", (float *) VoidPointer);
						printf("[%f].\n", *((float*) VoidPointer));
					}
				else
					perror("There is not enough memory space for the float variable allocation...");
			}
		else if (typ == V_LOWER_I)
			{
				//If the variable is of type 'integer'.
				if (VoidPointer = malloc(sizeof(int)))
					{
						printf("\nEnter an integer value   : ");
						scanf("%d", (int *) VoidPointer);
						printf("[%d].\n", *((int*) VoidPointer));
					}
				else
					perror("There is not enough memory space for the int variable allocation...");
			}
		else if (typ == V_LOWER_L)
			{
				//If the variable is of type 'long'.
				if (VoidPointer = malloc(sizeof(long)))
					{
						printf("\nEnter a long  value      : ");
						scanf("%ld", (long *) VoidPointer);
						printf("[%ld].\n", *((long*) VoidPointer));
					}
				else
					perror("There is not enough memory space for the long variable allocation...");
			}
		else if (typ == V_LOWER_S)
			{
				//If the variable is of type 'short'.
				if (VoidPointer = malloc(sizeof(short)))
					{
						printf("\nEnter a short value      : ");
						scanf("%hi", (short *) VoidPointer);
						printf("[%hi].\n", *((short*) VoidPointer));
					}
				else
					perror("There is not enough memory space for the short variable allocation...");
			}

		 //We return the memory address of the empty pointer.
		if (VoidPointer)
			{
				*VoidPtrPtr = VoidPointer;
				printf("+ Receiver: [%p] : [%p] : [%p].\n", &VoidPtrPtr, VoidPtrPtr, *VoidPtrPtr);
			}

		return VoidPointer;
	}

//Function that receives and returns a pointer of type 'void'.
void *bringVar(void *VoidPointer, char typ)
	{
		if (typ == V_LOWER_C)
			{
				//If the variable is of type 'character'.
				printf("\nEnter a character value -> ");
				scanf(" %c", (char *) VoidPointer);	//A space must come before '%c' to clear the buffer.
				printf("[%c].\n", *((char *) VoidPointer));
			}
		else if (typ == V_LOWER_D)
			{
				//If the variable is of type 'double'.
				printf("\nEnter a double    value -> ");
				scanf("%lf", (double *) VoidPointer);
				printf("[%lf].\n", *((double *) VoidPointer));
			}
		else if (typ == V_LOWER_F)
			{
				//If the variable is of type 'single precision floating point'.
				printf("\nEnter a floating  value -> ");
				scanf("%f", (float *) VoidPointer);
				printf("[%f].\n", *((float *) VoidPointer));
			}
		else if (typ == V_LOWER_I)
			{
				//If the variable is of type 'integer'.
				printf("\nEnter an integer  value -> ");
				scanf("%d", (int *) VoidPointer);
				printf("[%d].\n", *((int *) VoidPointer));
			}
		else if (typ == V_LOWER_L)
			{
				//If the variable is of type 'long'.
				printf("\nEnter  a long     value -> ");
				scanf("%ld", (long *) VoidPointer);
				printf("[%ld].\n", *((long *) VoidPointer));
			}
		else if (typ == V_LOWER_S)
			{
				//If the variable is of type 'integer'.
				printf("\nEnter  a short    value -> ");
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
		char CharValue = V_ZERO, *CharPtr = NULL;
		double DoubleValue = V_ZERO, *DoublePtr = NULL;
		float FloatValue = V_ZERO, *FloatPtr = NULL;
		int IntegerValue = V_ZERO, *IntegerPtr = NULL;
		long LongValue = V_ZERO, *LongPtr = NULL;
		short ShortValue = V_ZERO, *ShortPtr = NULL;

		/* Preliminary working variables. */
		void *VoidPtr = NULL;

		printf("Program that returns a 'void' type pointer and converts it.\n");

		//Example with a 'char' value.
		VoidPtr = bringVar(&CharValue, V_LOWER_C);
		printf("* Char    : [%p] : [%p] = [%c].\n", &CharValue, VoidPtr, *((char *) VoidPtr));

		if (VoidPtr = catchVar((void **) &CharPtr, V_LOWER_C))
			{
				printf("* Char    : [%p] : [%p] : [%p] = [%c].\n", &CharPtr, CharPtr, VoidPtr, *((char *) VoidPtr));
				free(VoidPtr);
			}

		//Example with a 'double precision floating point' value.
		VoidPtr = bringVar(&DoubleValue, V_LOWER_D);
		printf("* Double  : [%p] : [%p] = [%lf].\n", &DoubleValue, VoidPtr, *((double *) VoidPtr));

		if (VoidPtr = catchVar((void **) &DoublePtr, V_LOWER_D))
			{
				printf("* Double  : [%p] : [%p] : [%p] = [%lf].\n", &DoublePtr, DoublePtr, VoidPtr, *((double *) VoidPtr));
				free(VoidPtr);
			}

		//Example with a 'single precision floating point' value.
		VoidPtr = bringVar(&FloatValue, V_LOWER_F);
		printf("* Float   : [%p] : [%p] = [%f].\n", &FloatValue, VoidPtr, *((float *) VoidPtr));

		if (VoidPtr = catchVar((void **) &FloatPtr, V_LOWER_F))
			{
				printf("* Float   : [%p] : [%p] : [%p] = [%f].\n", &FloatPtr, FloatPtr, VoidPtr, *((float *) VoidPtr));
				free(VoidPtr);
			}

		//Example with an 'integer' value.
		VoidPtr = bringVar(&IntegerValue, V_LOWER_I);
		printf("* Integer : [%p] : [%p] = [%d].\n", &IntegerValue, VoidPtr, *((int *) VoidPtr));

		if (VoidPtr = catchVar((void **) &IntegerPtr, V_LOWER_I))
			{
				printf("* Integer : [%p] : [%p] : [%p] = [%d].\n", &IntegerPtr, IntegerPtr, VoidPtr, *((int *) VoidPtr));
				free(VoidPtr);
			}

		//Example with an 'long' value.
		VoidPtr = bringVar(&LongValue, V_LOWER_L);
		printf("* Long    : [%p] : [%p] = [%ld].\n", &LongValue, VoidPtr, *((long *) VoidPtr));

		if (VoidPtr = catchVar((void **) &LongPtr, V_LOWER_L))
			{
				printf("* Long    : [%p] : [%p] : [%p] = [%ld].\n", &LongPtr, LongPtr, VoidPtr, *((long *) VoidPtr));
				free(VoidPtr);
			}

		//Example with an 'short' value.
		VoidPtr = bringVar(&ShortValue, V_LOWER_S);
		printf("* Short   : [%p] : [%p] = [%hi].\n", &ShortValue, VoidPtr, *((short *) VoidPtr));

		if (VoidPtr = catchVar((void **) &ShortPtr, V_LOWER_S))
			{
				printf("* Short   : [%p] : [%p] : [%p] = [%hi].\n", &ShortPtr, ShortPtr, VoidPtr, *((short *) VoidPtr));
				free(VoidPtr);
			}

		return V_ZERO;
	}
