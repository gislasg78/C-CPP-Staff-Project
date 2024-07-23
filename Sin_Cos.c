/********** Trigonometric functions of sine and cosine. **********
 ** Source Code:	Sin_Cos.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, November 30, 2024.		**
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
 **                             [...]	Pair numbers.		**
 **								**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Working Macros.
#define EVEN_AND_ODD(value, addneutr)	(V_TWO * (value) + (addneutr))
#define RADIANS(angle)			((angle) * V_PI / V_HALF_CIRC)

//Numeric Symbolic Constants.
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

/*****************************************************************
 ** Function:		double dbl_factorial			**
 **				(const size_t szt_num).		**
 ** Explanation:	Gets the value of the factorial of any	**
 **			integer by recursively multiplying it by**
 **			its descendant surrogate numbers.	**
 ** Input Parms:	const size_t szt_num.			**
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
*****************************************************************/
double dbl_factorial(const size_t szt_num)
	{
		return (szt_num < V_ONE) ? V_ONE : (double) szt_num * dbl_factorial(szt_num + V_MINUS_ONE);
	}

/*****************************************************************
 ** Function:		double dbl_potency			**
 **				(const double dbl_base,		**
 **				 const size_t szt_exp).		**
 ** Explanation:	Returns a base coefficient raised to the**
 **			specified power recursively by means of	**
 **			successive multiplications or divisions.**
 **								**
 **			This function can also be programmed	**
 **			recursively in the form:		**
 **				(int_exp > V_ZERO) ? 		**
 **					dbl_potency(dbl_base,	**
 **					int_exp + V_MINUS_ONE)	**
 **					* dbl_base :		**
 **				(int_exp == V_ZERO) ? V_ONE :	**
 **				(int_exp < V_ZERO) ?		**
 **					dbl_potency(dbl_base,	**
 **					int_exp + V_ONE)	**
 **					/ dbl_base :		**
 **					V_ONE;			**
 ** Input Parms:	const double dbl_base,			**
 **			const size_t szt_exp.			**
 ** Output Parms:	None.					**
 ** Result:		The base raised to a positive power	**
 **			results in a series of products in	**
 **			sequence from 1 to 'n', while a base	**
 **			raised to a negative power results in a	**
 **			series of quotients in sequence from 1	**
 **			to '-n' .				**
*****************************************************************/
double dbl_potency(const double dbl_base, const size_t szt_exp)
	{
		return	(szt_exp < V_ONE) ? V_ONE : dbl_potency(dbl_base, szt_exp + V_MINUS_ONE) * dbl_base;
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
		double dbl_outcome = V_ZERO;

		for (size_t szt_idx = V_ZERO; szt_idx < szt_num_terms; szt_idx++)
			dbl_outcome += dbl_potency(V_MINUS_ONE, szt_idx)
			* dbl_potency(dbl_angle, EVEN_AND_ODD(szt_idx, enm_fn_addneutr))
			/ dbl_factorial(EVEN_AND_ODD(szt_idx, enm_fn_addneutr));

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
		double dbl_cosine = V_ZERO;
		double dbl_radians = V_ZERO;
		double dbl_sine = V_ZERO;
		double dbl_tangent = V_ZERO;
		double dbl_value = V_ZERO;

		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+   Taylor Series Sine & Cosine.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Degrees: ");
		scanf("%lf", &dbl_value);

		/* Obtaining preliminary variables. */
		dbl_radians = RADIANS(dbl_value);					//Obtaining the function 'radians' given a base 'x'.
		dbl_sine = sinus_cosinus(dbl_radians, V_NUM_TERMS, enm_fn_sine);	//Obtaining the function 'sine' given a base 'x'.
		dbl_cosine = sinus_cosinus(dbl_radians, V_NUM_TERMS, enm_fn_cosine);	//Obtaining the function 'cosine' given a base 'x'.
		dbl_tangent = tangent(dbl_radians, V_NUM_TERMS);			//Obtaining the function 'tangent' given a base 'x'.

		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+  Results of the Sine and Cosine.  +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| Degrees\t: [%lf].\n", dbl_value);
		printf("| Radians\t: [%lf].\n", dbl_radians);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| PI Value\t: [%lf].\n", V_PI);
		printf("| Terms\t\t: [%d].\n", V_NUM_TERMS);
		printf("+--------+--------+--------+--------+\n");
		printf("| Sine\t\t: [%lf].\n", dbl_sine);
		printf("| Cosine\t: [%lf].\n", dbl_cosine);
		printf("+---|----+---|----+---|----+---|----|\n");
		printf("| Tangent\t: [%lf].\n", dbl_tangent);
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("\n");

		return V_ZERO;
	}
