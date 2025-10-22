/****************** Discrete Fourier Transform. ******************
 ** Source Code:        Fourier.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		We have another way of characterizing	**
 **			L.T.I systems very powerful tool for 	**
 **			determine outputs when inputs.		**
 **			They are sinusoids or a combination of	**
 **			these.					**
 **			It allows you to make applications that	**
 **			in the temporal domain are difficult to	**
 **			understand (e.g. filtering).		**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				1.5, 2.5, 3.5, 4.5, 5.5, 6.5.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//C Standard Constants.
#define V_ONE			1
#define V_TWO			2
#define V_ZERO			0
#define NULL_CHARACTER		'\0'

//C Limit Constants.
#define V_LOWER_LIMIT_DFT	1
#define	V_UPPER_LIMIT_DFT	10

/* ------------------------------------------------------------	--
 * The following is a structure defined to store a complex	--
 * number, which contains a real part and an imaginary part.	--
 * ------------------------------------------------------------	*/
typedef struct strct_ComplexNumber
	{
		double real;
		double imag;
	} t_s_ComplexNumber;

/*****************************************************************
 ** Function:		t_s_ComplexNumber addComplexNumber	**
 **				(t_s_ComplexNumber		**
 **					firstNumber,		**
 **				 t_s_ComplexNumber		**
 **					secondNumber);		**
 ** Explanation:	In this function, the primary objective	**
 **			is to add two complex numbers, in such	**
 **			a way that to perform its own addition	**
 **			it is a requirement that their		**
 **			respective real parts of each be added	**
 **			simultaneously with the respective	**
 **			imaginary parts of each.		**
 ** Input Parms:	t_s_ComplexNumber firstNumber,		**
 **			t_s_ComplexNumber secondNumber.		**
 ** Output Parms:	None.					**
 ** Result:		The result returned by this function is	**
 **			a complex number that contains the real	**
 **			parts and the imaginary parts duly added**
 **			of two complex numbers previously passed**
 **			by argument.				**
 ****************************************************************/
t_s_ComplexNumber addComplexNumbers(t_s_ComplexNumber firstNumber, t_s_ComplexNumber secondNumber)
	{
		t_s_ComplexNumber goal_ComplexNumber;

		goal_ComplexNumber.real = firstNumber.real + secondNumber.real;
		goal_ComplexNumber.imag = firstNumber.imag + secondNumber.imag;

		return (goal_ComplexNumber);
	}

/*****************************************************************
 ** Function:		t_s_ComplexNumber multiplyComplexNumber	**
 **				(t_s_ComplexNumber		**
 **					firstNumber,		**
 **				 t_s_ComplexNumber		**
 **					secondNumber);		**
 ** Explanation:	The purpose of this function is to	**
 **			multiply two complex numbers, in such a	**
 **			way that two key situations are met:	**
 **			first, the new number returned in its	**
 **			real part is returned the product of	**
 **			the real parts of the two numbers passed**
 **			as an argument and is subtracted from	**
 **			the product of their respective		**
 **			imaginary parts; the second,		**
 **			the imaginary part of the complex number**
 **			returned is the result of the product of**
 **			the real part of the first by the	**
 **			imaginary part of the second and said	**
 **			product is added to the product of the	**
 **			imaginary part of the first by the real	**
 **			part of the second.			**
 ** Input Parms:	t_s_ComplexNumber firstNumber,		**
 **			t_s_ComplexNumber secondNumber.		**
 ** Output Parms:	None.					**
 ** Result:		This is summarized as follows:		**
 **			c.real = a.real * b.real -		**
 **				a.imag * b.imag;		**
 **			c.imag = a.real * b.imag +		**
 **				a.imag * b.real.		**
 ****************************************************************/
t_s_ComplexNumber multiplyComplexNumbers(t_s_ComplexNumber firstNumber, t_s_ComplexNumber secondNumber)
	{
		t_s_ComplexNumber goal_ComplexNumber;

		goal_ComplexNumber.real = firstNumber.real * secondNumber.real - firstNumber.imag * secondNumber.imag;
		goal_ComplexNumber.imag = firstNumber.real * secondNumber.imag + firstNumber.imag * secondNumber.real;

		return (goal_ComplexNumber);
	}

/*****************************************************************
 ** Function:		void calculateDFT			**
 **				(t_s_ComplexNumber		**
 **					*X_ComplexNumbers,	**
 **				 const double *const 		**
 **					x_realNumbers,		**
 **				 const int int_NumItems);	**
 ** Explanation:	The purpose of this function is to	**
 **			calculate the Discrete Fourier Transform**
 **			using two nested cycles.		**
 **			The first, assigns to the first complex	**
 **			number in its real part the value of the**
 **			array of floating point numbers and in	**
 **			its imaginary part the value zero.	**
 **			The second calculates the value 't'	**
 **			using the formula:			**
 **				t = k * 2 * PI / N * n,		**
 **			and to the second complex number,	**
 **			in its real part it assigns the cosine	**
 **			of -t and in its imaginary part the	**
 **			sine of - t.				**
 ** Input Parms:	t_s_ComplexNumber *X_ComplexNumber,	**
 **			const double *const x_realNumbers,	**
 **			const int int_NumItems.			**
 ** Output Parms:	t_s_ComplexNumber *X_ComplexNumber.	**
 ** Result:		The result of this function is to	**
 **			overwrite the array containing the	**
 **			complex number structure with the	**
 **			calculations made with sines and cosines**
 **			of the value 't' and return the results	**
 **			to be displayed on the screen.		**
 ****************************************************************/
void calculateDFT(t_s_ComplexNumber *X_ComplexNumbers, const double *const x_realNumbers, const int int_NumItems)
	{
		/* Declaration of local scope variables. */
		double t = V_ZERO;
		t_s_ComplexNumber firstNumber, secondNumber;

		/* Cycles for the calculation of each real value obtained in the captured array of real numbers. */
		for (int int_idx = V_ZERO; int_idx < int_NumItems; int_idx++)
			{
				for (int int_ind = V_ZERO; int_ind < int_NumItems; int_ind++)
					{
						/* The real of 't_s_ComplexNumber' is the real passed as current argument. */
						firstNumber.real = x_realNumbers[int_ind];
						secondNumber.imag = V_ZERO;

						/* ----------------------------------------------------------------------------	--
						 * The 'k' value is multiplied by 2, by PI and said result is divided by	--
						 * the product of 'N' x 'n'.							--
						 * ----------------------------------------------------------------------------	*/
						t = int_idx * V_TWO * M_PI / int_NumItems * int_ind;

						/* ----------------------------------------------------------------------------	--
						 * The new 't_s_ComplexNumber' has the real cosine '-t'				--
						 * and the imaginary sine '-t'.							--
						 * ---------------------------------------------------------------------------- */
						secondNumber.real = cos(-t);
						secondNumber.imag = sin(-t);

						/* Multiplication and addition of the numbers 't_s_ComplexNumbers' obtained. */
						secondNumber = multiplyComplexNumbers(firstNumber, secondNumber);
						X_ComplexNumbers[int_idx] = addComplexNumbers(X_ComplexNumbers[int_idx], secondNumber);
					}
			}

		/* Print on the screen the results obtained from the calculation with the real numbers. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Obtaining DFT calculations.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");

		/* Display the results of the calculated arrangements on the screen itself. */
		for (int int_idx = V_ZERO; int_idx < int_NumItems; int_idx++)
			printf("#: [%d] of [%d].\t:\tValue: [%lf].\t=\tReal: [%lf].\tImaginary: [%lf].\t<j>.\n", int_idx + V_ONE, int_NumItems, x_realNumbers[int_idx], X_ComplexNumbers[int_idx].real, X_ComplexNumbers[int_idx].imag);
	}

/*****************************************************************
 ** Function:		void initializeDFT			**
 **				(t_s_ComplexNumber		**
 **				 **X_ComplexNumbers,		**
 **				 double **x_realNumbers,	**
 **				 const int int_NumItems);	**
 ** Explanation:	The purpose of this function is to	**
 **			create and initialize the pointer	**
 **			structure of complex number pointers,	**
 **			as well as to create, initialize and	**
 **			capture the real number pointer pointer	**
 **			that will be used to calculate the	**
 **			Discrete Fourier Transform, taking into	**
 **			account that in the same formal		**
 **			parameters will override the respective	**
 **			current parameters of this function.	**
 ** Input Parms:	t_s_ComplexNumber **X_ComplexNumbers,	**
 **			t_s_ComplexNumber **x_realNumbers,	**
 **			const int int_NumItems.			**
 ** Output Parms:	t_s_ComplexNumber **X_ComplexNumbers,	**
 **                     t_s_ComplexNumber **x_realNumbers.	**
 ** Result:		This function returns as results in its	**
 **			own arguments of the function definition**
 **			the array with the complex number	**
 **			structure and the array with the created**
 **			and initialized double precision	**
 **			floating point numbers.			**
 **			The latter, also captured.		**
 ****************************************************************/
void initializeDFT(t_s_ComplexNumber **X_ComplexNumbers, double **x_realNumbers, const int int_NumItems)
	{
		/* Initial declaration of work variables. */
		double *x = NULL;
		t_s_ComplexNumber *X = NULL;

		/* Generation and initialization of the array of complex numbers. */
		if (X = (t_s_ComplexNumber *) malloc(int_NumItems * sizeof(t_s_ComplexNumber)))
			for (int int_idx = V_ZERO; int_idx < int_NumItems; int_idx++)
				{
					/* A preventive initialization is performed per element. */
					X[int_idx].real = V_ZERO;
					X[int_idx].imag = V_ZERO;
				}
		else
			{
				perror("Insufficient memory to accommodate Complex Numbers pointer...");
				exit(EXIT_FAILURE);
			}

		/* Generation and initialization of the array of floating point real numbers. */
		if (x = (double *) malloc(int_NumItems * sizeof(double)))
			for (int int_idx = V_ZERO; int_idx < int_NumItems; int_idx++)
				{
					/* A preventive initialization is performed per element. */
					*(x + int_idx) = V_ZERO;

					/* Request to capture each value of the array of numbers in double precision. */
					printf("Floating point value to enter #: [%d] of [%d] : ", int_idx + V_ONE, int_NumItems);
					scanf("%lf", &x[int_idx]);
				}
		else
			{
				perror("Insufficient memory to accommodate Real Numbers pointer...");
				exit(EXIT_FAILURE);
			}

		/* Reassignment of locally created pointers to override the addresses of received arguments. */
		*X_ComplexNumbers = X;
		*x_realNumbers = x;
	}


/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function we have a way to	**
 **			express the signal as an infinite sum of**
 **			sinusoids using this decomposition of	**
 **			the signal together with the frequency	**
 **			response we have a simple way to	**
 **			determine the output of a stationary	**
 **			system.					**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Relevant points:			**
 **				1. Allocate memory for the array**
 **				(vector) that will store the	**
 **				sequence of real numbers 'x'.	**
 **				2. Block of statements that	**
 **				generate the arrays, their	**
 **				capture and their calculations.	**
 **				3. Enter the sequence of real	**
 **				numbers contained in the array	**
 **				of the same type 'x'.		**
 **				4. Calculate the discrete	**
 **				Fourier transform and return it	**
 **				in the complex array 'X'.	**
 **				5. Display on the screen the	**
 **				results obtained from the	**
 **				Discrete Fourier Transform	**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				1.5, 2.5, 3.5, 4.5, 5.5, 6.5.	**
*****************************************************************/
int main()
	{
		/* Local work variables in the main program. */
		double *x_realNumbers = NULL;
		int int_NumItems = V_ZERO;
		t_s_ComplexNumber *X_ComplexNumbers = NULL;

		/* Main splash screen messages of this program. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Discrete Fourier Transform.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Amount of real values to enter between [%d] and [%d] : ", V_LOWER_LIMIT_DFT, V_UPPER_LIMIT_DFT);
		scanf("%d", &int_NumItems);

		/* Allocate memory for t_s_ComplexNumbers number array 'X' and floating point number array 'x'. */
		if (int_NumItems >= V_LOWER_LIMIT_DFT  && int_NumItems <= V_UPPER_LIMIT_DFT)
			{
				initializeDFT(&X_ComplexNumbers, &x_realNumbers, int_NumItems);
				calculateDFT(X_ComplexNumbers, x_realNumbers, int_NumItems);

				free(X_ComplexNumbers);	/* Free memory from the array of complex numbers. */
				free(x_realNumbers);	/* Free memory from the array of real numbers. */
			}
		else
			printf("Mistake! Value: [%d] is not in the range of [%d] and [%d].\n", int_NumItems, V_LOWER_LIMIT_DFT, V_UPPER_LIMIT_DFT);

		return V_ZERO;
	}
