/********** Trigonometric functions of sine and cosine. **********
 ** Source Code:	Sin_Cos.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, December 31, 2026.		**
 ** Purpose:		Calculates through the Taylor series	**
 **			the trigonometric functions of sine and	**
 **			cosine according to a determined value	**
 **			that is expressed in radians.		**
 **			Most of the math functions were		**
 **			implemented.				**
 **								**
 **			The Taylor power series to solve for	**
 **			the trigonometric function of sine is:	**
 **								**
 **			sin(x)= (x^1 / 1!) - (x^3 / 3!) +	**
 **				(x^5 / 5!) - (x^7 / 7!) +	**
 **				(x^9 / 9!) - (x^11 / 11!) +	**
 **				[...].	Odd numbers.		**
 **								**
 **			The Taylor power series to solve for	**
 **			the trigonometric function of cosine is:**
 **								**
 **                     cos(x)= (x^0 / 0!) - (x^2 / 2!) +       **
 **                             (x^4 / 4!) - (x^6 / 6!) +       **
 **                             (x^8 / 8!) - (x^10 / 10!) +     **
 **                             [...]	Pair (Even) numbers.	**
 **								**
*****************************************************************/
/* C Standard Libraries. */
#include <stdio.h>

/* Working Macros. */
#define EVEN_AND_ODD(value, addneutr)	((V_TWO) * (value) + (addneutr))
#define RADIANS(angle)			((angle) * (V_PI) / (V_HALF_CIRC))

/* Alphanumeric Work Constants. */
#define	CARRIAGE_RETURN			'\n'
#define	NULL_CHARACTER			'\0'

/* Numeric Symbolic Constants. */
#define V_HALF_CIRC			180.0
#define V_MINUS_ONE			-1
#define	V_NUM_TERMS			11
#define V_ONE				1
#define	V_PI				3.14159265359
#define	V_TWO				2.0
#define V_ZERO				0

/*----------------------------------------------------------------
 ** This is an enumerated type that is considered by default	--
 ** to be an integer, consisting of two consecutive values,	--
 ** zero and one, which are the additive neuters required for	--
 ** the powers and factorials of the trigonometric sine and	--
 ** cosine functions, and is sent to the corresponding function	--
 ** in charge of calculating them.				--
 **-------------------------------------------------------------*/
enum enm_fn_sin_cos
	{
		enm_fn_cosine = V_ZERO,
		enm_fn_sine = V_ONE
	};

/* Enumeration with type entry variables and its reseting. */
enum enm_type_entry
	{
		enm_type_entry_char,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short,
		enm_type_entry_sizet
	};

/* Enumeration for memory area reset system. */
enum enm_type_reset
	{
		enm_type_reset_NO,
		enm_type_reset_YES
	};

/* Prototypes of the functions to be used in this program. */
double dbl_factorial(const double dbl_num);
double dbl_potency(const double dbl_base, const double dbl_exp);
double sinus_cosinus(const double dbl_angle, const size_t szt_num_terms, const enum enm_fn_sin_cos enm_fn_addneutr);
double tangent(const double dbl_angle, const size_t szt_num_terms);
void view_outcomes(const double dbl_value, const double dbl_radians, const double dbl_PI, const size_t szt_num_terms, const double dbl_sine, const double dbl_cosine, const double dbl_tangent);

/*****************************************************************
 ** Function:		double dbl_factorial			**
 **				(const double dbl_num).		**
 ** Explanation:	Gets the value of the factorial of any	**
 **			integer by recursively multiplying it by**
 **			its descendant surrogate numbers.	**
 ** Input Parms:	const double dbl_num.			**
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
*****************************************************************/
double dbl_factorial(const double dbl_num)
	{
		return (dbl_num < V_ONE) ? V_ONE : dbl_num * dbl_factorial(dbl_num + V_MINUS_ONE);
	}

/*****************************************************************
 ** Function:		double dbl_potency			**
 **				(const double dbl_base,		**
 **				 const double dbl_exp).		**
 ** Explanation:	Returns a base coefficient raised to the**
 **			specified power recursively by means of	**
 **			successive multiplications or divisions.**
 **								**
 **			This function can also be programmed	**
 **			recursively in the form:		**
 **				(dbl_exp > V_ZERO) ? 		**
 **					dbl_potency(dbl_base,	**
 **					dbl_exp + V_MINUS_ONE)	**
 **					* dbl_base :		**
 **				(dbl_exp == V_ZERO) ? V_ONE :	**
 **				(dbl_exp < V_ZERO) ?		**
 **					dbl_potency(dbl_base,	**
 **					dbl_exp + V_ONE)	**
 **					/ dbl_base :		**
 **					V_ONE;			**
 ** Input Parms:	const double dbl_base,			**
 **			const double dbl_exp.			**
 ** Output Parms:	None.					**
 ** Result:		The base raised to a positive power	**
 **			results in a series of products in	**
 **			sequence from 1 to 'n', while a base	**
 **			raised to a negative power results in a	**
 **			series of quotients in sequence from 1	**
 **			to '-n' .				**
*****************************************************************/
double dbl_potency(const double dbl_base, const double dbl_exp)
	{
		return	(dbl_exp > V_ZERO) ? dbl_potency(dbl_base, dbl_exp + V_MINUS_ONE) * dbl_base :
			(dbl_exp == V_ZERO) ? V_ONE :
			(dbl_exp < V_ZERO) ? dbl_potency(dbl_base, dbl_exp + V_ONE) / dbl_base : V_ONE;
	}

/* Function that gets a correct type value depending on its option. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Convert the specified enumerated type to an 'integer'. */
		int option_type_entry = (int) enm_type_data;

		/* Validate if the obtained memory addresses are valid. */
		if (void_var_address)
			{
				/* Initialize the specified memory area. */
				if (enm_type_reset_OK == enm_type_reset_YES)
					{
						switch(enm_type_data)
							{
								case enm_type_entry_char:
									*((char *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_double:
									*((double *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_float:
									*((float *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_int:
									*((int *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_long:
									*((long *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_short:
									*((short *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_sizet:
									*((size_t *) void_var_address) = V_ZERO;
									break;

								default:
									fputs("\nUnrecognized Option!", stderr);
									fprintf(stderr, "\nThe selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
									break;
							}
					}

				/* Incoming message. */
				printf("%s", str_Message);

				/* Selection of validating case of the type of variable to generate. */
				switch(enm_type_data)
					{
						/* Get a correct character value. */
						case enm_type_entry_char:
							if ((int_fields = scanf("%c%*c%n", (char *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, *((char *) void_var_address), *((char *) void_var_address), *((char *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point double precision value. */
						case enm_type_entry_double:
							if ((int_fields = scanf("%lf%*c%n", (double *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%lf]. Characters: [%d]. OK!\n", int_fields, *((double *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point single precision value. */
						case enm_type_entry_float:
							if ((int_fields = scanf("%f%*c%n", (float *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%f]. Characters: [%d]. OK!\n", int_fields, (double) *((float *) void_var_address), int_chars);
							break;

						/* Get a correct integer value. */
						case enm_type_entry_int:
							if ((int_fields = scanf("%d%*c%n", (int *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%d]. Characters: [%d]. OK!\n", int_fields, *((int *) void_var_address), int_chars);
							break;

						/* Get a correct long int value. */
						case enm_type_entry_long:
							if ((int_fields = scanf("%ld%*c%n", (long *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%ld]. Characters: [%d]. OK!\n", int_fields, *((long *) void_var_address), int_chars);
							break;

						/* Get a correct short int value. */
						case enm_type_entry_short:
							if ((int_fields = scanf("%hi%*c%n", (short *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%hi]. Characters: [%d]. OK!\n", int_fields, *((short *) void_var_address), int_chars);
							break;

						/* Get a correct unsigned long int value. */
						case enm_type_entry_sizet:
							if ((int_fields = scanf("%zu%*c%n", (size_t *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%zu]. Characters: [%d]. OK!\n", int_fields, *((size_t *) void_var_address), int_chars);
							break;

						/* It is specified that if the option is incorrect, an error message should be sent. */
						default:
							fputs("\nUnrecognized Option!", stderr);
							fprintf(stderr, "\nThe selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
							break;
					}

				/* Verify that exactly one field is captured and saved at the given address. */
				if ((int_fields != V_ONE) || !(int_chars))
					{
						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* Get an incorrect entried value. */
						fputs("\nThe value entered is not valid!\n", stderr);
						fprintf(stderr, "Press ENTER to continue...");

						/* Proceed to clear all characters present in the buffer. */
						int_chars = V_ZERO;
						int_fields = scanf("%*[^\n]%*c%n", &int_chars);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* We must always clear the input buffer of impurities. */
						fputs("\nPress the ENTER key to clear the input buffer...", stderr);
						while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}
					}
			}
		else
			fprintf(stderr, "\nThe memory address to hold the variable is not valid!\n");

		/* Return of void pointer key value. */
		return void_var_address;
	}

/*****************************************************************
 ** Function:		double sinus_cosinus			**
 **				(const double dbl_angle,	**
 **				 const size_t szt_num_terms,	**
 **				 const enum enm_fn_sin_cos	**
 **					enm_fn_addneutr).	**
 ** Explanation:	The value of the sine or cosine is	**
 **			obtained as a result, depending on an	**
 **			additive neutral passed as a parameter, **
 **			of a certain value in angles expressed	**
 **			in radians, through the Taylor series.	**
 ** Input Parms:	const double dbl_angle,			**
 **			const size_t szt_num_terms,		**
 **			const enum enm_fn_sin_cos		**
 **				enm_fn_addneutr.		**
 **								**
 **			Note:					**
 **			* The default enumerated type is an	**
 **			  integer (int) type.			**
 **								**
 ** Output Parms:	None.					**
 ** Result:		To calculate the trigonometric function **
 **			of sine, the Taylor number series	**
 **			applied with 'odd' numbers is:		**
 **								**
 **			sin(x)= (x^1 / 1!) - (x^3 / 3!)	+	**
 **				(x^5 / 5!) - (x^7 / 7!)	+	**
 **				(x^9 / 9!) - (x^11 / 11!) +	**
 **				[...]	Odd numbers.		**
 **								**
 **			To calculate the trigonometric function **
 **			of cosine, the Taylor number series	**
 **			applied with 'even' numbers is:		**
 **								**
 **			cos(x)=	(x^0 / 0!) - (x^2 / 2!) +	**
 **				(x^4 / 4!) - (x^6 / 6!) + 	**
 **				(x^8 / 8!) - (x^10 / 10!) +	**
 **				[...]	Pair/Even numbers.	**
 **								**
*****************************************************************/
double sinus_cosinus(const double dbl_angle, const size_t szt_num_terms, const enum enm_fn_sin_cos enm_fn_addneutr)
	{
		/* Preliminary Working Variables. */
		double dbl_outcome = V_ZERO;

		/* Cycle in which the trigonometric functions 'sine' and/or 'cosine' are calculated. */
		for (size_t szt_idx = V_ZERO; szt_idx < szt_num_terms; szt_idx++)
			dbl_outcome += dbl_potency((double)V_MINUS_ONE, (double)szt_idx)
			* dbl_potency(dbl_angle, EVEN_AND_ODD((double)szt_idx, (size_t)enm_fn_addneutr))
			/ dbl_factorial(EVEN_AND_ODD((double)szt_idx, (size_t)enm_fn_addneutr));

		/* Return of the calculated value. */
		return dbl_outcome;
	}

/*****************************************************************
 ** Function:		double tangent				**
 **				(const double dbl_angle,	**
 **				 const size_t szt_num_terms).	**
 ** Explanation:	This function returns the trigonometric	**
 **			function of tangent by simply dividing	**
 **			the trigonometric functions of sine and	**
 **			cosine respectively, without resorting	**
 **			to independent power series to		**
 **			calculate it.				**
 **								**
 **			Remember that the power of the		**
 **			numerator and the factorial of the	**
 **			denominator, respectively, are odd for	**
 **			the sine and even for the cosine.	**
 **								**
 ** Input Parms:	const double dbl_angle,			**
 **			const size_t szt_num_terms.		**
 ** Output Parms:	None.					**
 ** Result:		Returns sine divided by cosine:		**
 **				sine(x)	/ cosine(x).		**
*****************************************************************/
double tangent(const double dbl_angle, const size_t szt_num_terms)
	{
		return	sinus_cosinus(dbl_angle, szt_num_terms, enm_fn_sine) /
			sinus_cosinus(dbl_angle, szt_num_terms, enm_fn_cosine);
	}

/*****************************************************************
 ** Function:		void view_outcomes			**
 **				(const double dbl_value,	**
 **				 const double dbl_radians,	**
 **				 const double dbl_PI,		**
 **				 const size_t szt_num_terms,	**
 **				 const double dbl_sine,		**
 **				 const double dbl_cosine,	**
 **				 const double dbl_tangent).	**
 ** Explanation:	The purpose of this function is		**
 **			to display the final output results of	**
 **			calculations performed using Taylor	**
 **			series to determine the sine and cosine	**
 **			trigonometric functions, based on	**
 **			a given value in degrees converted	**
 **			into radians.				**
 ** Input Parms:	const double dbl_value.			**
 **			const double dbl_radians.		**
 **			const double dbl_PI.			**
 **			const size_t szt_num_terms.		**
 **			const double dbl_sine.			**
 **			const double dbl_cosine.		**
 **			const double dbl_tangent.		**
 ** Output Parms:	None.					**
 ** Result:		This function does not return any	**
 **			result, as its sole purpose is		**
 **			to display the final output messages	**
 **			on the screen, showing the calculations	**
 **			performed by the aforementioned		**
 **			trigonometric functions.		**
*****************************************************************/
void view_outcomes(const double dbl_value, const double dbl_radians, const double dbl_PI, const size_t szt_num_terms, const double dbl_sine, const double dbl_cosine, const double dbl_tangent)
	{
		/* Preliminary Working Variables. */
		char chr_pause = NULL_CHARACTER;

		/* Output messages for calculation results. */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+  Results of the Sine and Cosine.  +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| + Degrees\t:\t[%lf].\n", dbl_value);
		printf("| + Radians\t:\t[%lf].\n", dbl_radians);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| - PI Value\t:\t[%lf].\n", dbl_PI);
		printf("| - Terms\t:\t[%zu].\n", szt_num_terms);
		printf("+---|----+---|----+---|----+---|----|\n");
		printf("| * Sine\t:\t[%lf].\n", dbl_sine);
		printf("| * Cosine\t:\t[%lf].\n", dbl_cosine);
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("| * Tangent\t:\t[%lf].\n", dbl_tangent);
		printf("+===|====+===|====+===|====+===|====+\n");

		/* Request a pause before continuing. */
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	Main module in which the objectives of	**
 **			this program are developed.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The resulting values of the		**
 **			trigonometric functions of the sine and	**
 **			cosine of an angle expressed in radians **
 **			are obtained.				**
 **								**
 **			Specific formula to calculate the sine	**
 **			or cosine:				**
 **								**
 **			For 'i'=0 to 'n':			**
 **				{ (-1 ^'i') *			**
 **				[ 'x' ^ (2 * 'i' + 'a') /	**
 **				 (2 * 'i' + 'a')! ] +		**
 **				[...] }				**
 **								**
 **			Where 'a' is an additive neutral that	**
 **			can be zero to compute the trigonometric*+
 **			function of cosine (even numbers)	**
 **			and one to compute the trigonometric	**
 **			function of sine (odd numbers).		**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		char chr_pause = NULL_CHARACTER;
		double dbl_cosine = V_ZERO;
		double dbl_radians = V_ZERO;
		double dbl_sine = V_ZERO;
		double dbl_tangent = V_ZERO;
		double dbl_value = V_ZERO;

		/* Initial header messages. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ Taylor Series 'Sine' & 'Cosine'.  +\n");
		printf("+---|----+---|----+---|----+---|----+\n");

		/* Request the number of degrees to be converted into radians. */
		dbl_value = *((double *) GetEntry("Degress: ", &dbl_value, enm_type_entry_double, enm_type_reset_YES));

		/* Obtaining preliminary variables. */
		dbl_radians = (double) RADIANS(dbl_value);					//Obtaining the function 'radians' given a base 'x'.
		dbl_sine = sinus_cosinus(dbl_radians, (size_t) V_NUM_TERMS, enm_fn_sine);	//Obtaining the function 'sine' given a base 'x'.
		dbl_cosine = sinus_cosinus(dbl_radians, (size_t) V_NUM_TERMS, enm_fn_cosine);	//Obtaining the function 'cosine' given a base 'x'.
		dbl_tangent = tangent(dbl_radians, (size_t) V_NUM_TERMS);			//Obtaining the function 'tangent' given a base 'x'.

		/* Final program information messages. */
		view_outcomes(dbl_value, dbl_radians, (double) V_PI, (size_t) V_NUM_TERMS, dbl_sine, dbl_cosine, dbl_tangent);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}
