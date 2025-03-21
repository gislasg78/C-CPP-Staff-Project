/* This program uses a 'void' type function to store a certain value
   depending on the type of variable you want to return. */
#include <stdio.h>
#include <stdlib.h>

#define	V_LOWER_C	'\x63'
#define	V_LOWER_D	'\x64'
#define	V_LOWER_F	'\x66'
#define	V_LOWER_I	'\x69'
#define	V_LOWER_L	'\x6c'
#define	V_LOWER_S	'\x73'

#define V_ZERO  	0

//Function that receives and returns a pointer of type 'void'.
void *catchVar(void **vd_ptr_ptr, char typ)
	{
		void *vd_ptr = NULL;

		if (typ == V_LOWER_C)
			{
				//If the variable is of type 'character'.
				if (vd_ptr = malloc(sizeof(char)))
					{
						printf("Enter a char  value : ");
						scanf(" %c", (char *) vd_ptr);  //A space must come before '%c' to clear the buffer.
						printf("[%c].\n", *((char*) vd_ptr));
					}
				else
					perror("There is not enough memory space for the char variable allocation...");
			}
		else if (typ == V_LOWER_D)
			{
				//If the variable is of type 'double precision floating point'.
				if (vd_ptr = malloc(sizeof(double)))
					{
						printf("Enter a double value: ");
						scanf("%lf", (double *) vd_ptr);
						printf("[%lf].\n", *((double*) vd_ptr));
					}
				else
					perror("There is not enough memory space for the double variable allocation...");
			}
		else if (typ == V_LOWER_F)
			{
				//If the variable is of type 'single precision floating point'.
				if (vd_ptr = malloc(sizeof(float)))
					{
						printf("Enter a float value : ");
						scanf("%f", (float *) vd_ptr);
						printf("[%f].\n", *((float*) vd_ptr));
					}
				else
					perror("There is not enough memory space for the float variable allocation...");
			}
		else if (typ == V_LOWER_I)
			{
				//If the variable is of type 'integer'.
				if (vd_ptr = malloc(sizeof(int)))
					{
						printf("Enter an int  value : ");
						scanf("%d", (int *) vd_ptr);
						printf("[%d].\n", *((int*) vd_ptr));
					}
				else
					perror("There is not enough memory space for the int variable allocation...");
			}
		else if (typ == V_LOWER_L)
			{
				//If the variable is of type 'long'.
				if (vd_ptr = malloc(sizeof(long)))
					{
						printf("Enter a long  value : ");
						scanf("%ld", (long *) vd_ptr);
						printf("[%ld].\n", *((long*) vd_ptr));
					}
				else
					perror("There is not enough memory space for the long variable allocation...");
			}
		else if (typ == V_LOWER_S)
			{
				//If the variable is of type 'short'.
				if (vd_ptr = malloc(sizeof(short)))
					{
						printf("Enter a short value : ");
						scanf("%hi", (short *) vd_ptr);
						printf("[%hi].\n", *((short*) vd_ptr));
					}
				else
					perror("There is not enough memory space for the short variable allocation...");
			}

		 //We return the memory address of the empty pointer.
		if (vd_ptr)
			{
				*vd_ptr_ptr = vd_ptr;
				printf("+ Receiver: [%p] : [%p] : [%p].\n", &vd_ptr_ptr, vd_ptr_ptr, *vd_ptr_ptr);
			}

		return vd_ptr;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		void *CharPtr = NULL, *DoublePtr = NULL, *FloatPtr = NULL, *IntegerPtr = NULL, *LongPtr = NULL, *ShortPtr = NULL;
		void *VoidPtr = NULL;

		printf("Program that returns a 'void' type pointer and converts it.\n");

		//Example with a 'char' value.
		if (VoidPtr = catchVar(&CharPtr, V_LOWER_C))
			{
				printf("* Char    : [%p] : [%p] : [%p] = [%c].\n", &CharPtr, CharPtr, VoidPtr, *((char *) VoidPtr));
				free(VoidPtr);
			}

		//Example with a 'double precision floating point' value.
		if (VoidPtr = catchVar(&DoublePtr, V_LOWER_D))
			{
				printf("* Double  : [%p] : [%p] : [%p] = [%lf].\n", &DoublePtr, DoublePtr, VoidPtr, *((double *) VoidPtr));
				free(VoidPtr);
			}

		//Example with a 'single precision floating point' value.
		if (VoidPtr = catchVar(&FloatPtr, V_LOWER_F))
			{
				printf("* Float   : [%p] : [%p] : [%p] = [%f].\n", &FloatPtr, FloatPtr, VoidPtr, *((float *) VoidPtr));
				free(VoidPtr);
			}

		//Example with an 'integer' value.
		if (VoidPtr = catchVar(&IntegerPtr, V_LOWER_I))
			{
				printf("* Integer : [%p] : [%p] : [%p] = [%d].\n", &IntegerPtr, IntegerPtr, VoidPtr, *((int *) VoidPtr));
				free(VoidPtr);
			}

		//Example with an 'long' value.
		if (VoidPtr = catchVar(&LongPtr, V_LOWER_L))
			{
				printf("* Long    : [%p] : [%p] : [%p] = [%ld].\n", &LongPtr, LongPtr, VoidPtr, *((long *) VoidPtr));
				free(VoidPtr);
			}

		//Example with an 'short' value.
		if (VoidPtr = catchVar(&ShortPtr, V_LOWER_S))
			{
				printf("* Short   : [%p] : [%p] : [%p] = [%hi].\n", &ShortPtr, ShortPtr, VoidPtr, *((short *) VoidPtr));
				free(VoidPtr);
			}

		return V_ZERO;
	}
