/*************** Solution of a quadratic equation. ***************
 ** Source Code:	Equation.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, August 31, 2023.          	**
 ** +---+----+---+----+---+----+---+----+---+----+---+----+---+ **
 ** Purpose:		How to solve a quadratic equation whose **
 **			roots are negative:			**
 **								**
 **			1. First, write the equation in its	**
 **			standard form: ax² + bx + c = 0.	**
 **								**
 **			2. Next, identify the values of 'a',	**
 **			'b', and 'c'.				**
 **								**
 **			3. Find the discriminant of the		**
 **			equation, which is defined as b² - 4ac.	**
 **			If the discriminant is negative, then	**
 **			the equation has complex or imaginary	**
 **			roots.					**
 **								**
 **			4. Now, use the general formula to find **
 **			the roots of the equation:		**
 **			x = (-b ± √(b² - 4ac)) / 2a.		**
 **								**
 **			5. Since the discriminant is negative,	**
 **			the part under the radical sign will be **
 **			negative, which means that the roots	**
 **			will be complex or imaginary.		**
 **			However, since the roots are specified	**
 **			to be negative, then they must be	**
 **			complex conjugate with negative real	**
 **			part.					**
 ** 			6. Therefore, the roots of the equation	**
 **			will be of the form:			**
 **			x = (-b ± i√(-discriminant)) / 2a,	**
 **			where i is the imaginary unit (√-1).	**
 **								**
 ** 			7. If you want to obtain the roots in	**
 **			the form of complex numbers, simply	**
 **			perform the necessary operations to	**
 **			simplify the expression. For example,	**
 **			if the discriminant is -25, then the	**
 **			roots would be x = (-b ± 5i) / 2a.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

/*****************************************************************
 * Macros used to obtain respectively:				**
 * 1. The common denominator.					**
 * 2. The discriminant of the equation and,			**
 * 3. the operation to obtain simple root.			**
 ****************************************************************/
#define DENOMINATOR(c_a)		( V_TWO * (c_a) )
#define DISCRIMINATE(c_a, c_b, c_c)	( ( (c_b) * (c_b) ) - ( V_FOUR * (c_a) * (c_c) ) )
#define SINGLE_ROOT(c_a, c_b)		( (-c_b) / ( V_TWO * (c_a) ) )
#define UNIQUE_ROOT(c_b, c_c)		( (-c_c) / (c_b) )

//Numeric Symbolic Constants.
#define V_FOUR		4.0		//Intercalated discriminant.
#define V_PR_TOL	0.000001;	//Base Precision tolerance.
#define V_ONE		1		//Numerical value 01.
#define V_TWO		2.0		//Numerical value 02.0.
#define V_ZERO		0		//Zero numeric value.

//Symbolic Character Constants.
#define NULL_CHARACTER	'\0'

/*****************************************************************
 * Main work structures that contain the sensitive information	**
 * that is thrown by the calculations to obtain the roots of a	**
 * second degree equation, whether these are in the set of real	**
 * numbers or imaginary numbers.				**
*****************************************************************/
/*--------------------------------------------------------------**
 * Data structure that collects internal calculation information**
 * to obtain the square root of a certain value by Newton's	**
 * method.							**
 *--------------------------------------------------------------*/
struct str_square_root
	{
		double dbl_preapproach;		//Previous approach.
		double dbl_newapproach;		//Current approximation.
		double dbl_prequotient;		//Previous quotient.
		double dbl_addends;		//Addends updated.
		double dbl_newquotient;		//Current ratio.
		double dbl_base_denominator;	//Base denominator.
		double dbl_difference;		//Effective difference.
		double dbl_epsilon;		//Precision tolerance.
	}	ssr = {V_ZERO};

/*--------------------------------------------------------------**
 * Result structure that returns the real part and the imaginary**
 * part of both roots of a quadratic equation, as applicable.	**
 *--------------------------------------------------------------*/
struct str_quadratic_equation_royal_imaginary_parts
	{
		double	dbl_royal_part;          //Royal part.
		double	dbl_imaginary_part;      //Imaginary part.
	}	sqerip = {V_ZERO};

/*--------------------------------------------------------------**
 * Structure of results that are returned by the solution of a  **
 * quadratic equation.                                          **
 *--------------------------------------------------------------*/
struct str_quadratic_equation
	{
	        /* Quadratic term.			Coefficient 'a'.*/
		double	dbl_quadratic_term_a;
		/* Linear term.				Coefficient 'b' */
	        double	dbl_lineal_term_b;
		/* Constant or independent term.	Coefficient 'c'.*/
	        double	dbl_constant_term_c;

		/* Discriminating.	Result in the coefficient 'd'.  */
	        double	dbl_discriminating_d;

		/* Both roots of the quadratic equation.		**
		 * With their respective real parts and imaginary parts.*/
	        struct	str_quadratic_equation_royal_imaginary_parts
			dbl_first_root_x1;	//First root.	Value x1.
	        struct str_quadratic_equation_royal_imaginary_parts
	                dbl_second_root_x2;	//Second root.	Value x2.

	}	sqe = {V_ZERO};

/*****************************************************************
 ** Function:		getpause.				**
 ** Explanation:	This function shows a specific message	**
 **			on the screen to indicate a given pause,**
 **			and returns the key that was pressed to	**
 **			continue with the execution of the	**
 **			program as a result.			**
 ** Input Parms:	const char *str_Message,		**
 ** Output Parms:	None.					**
 ** Result:		The function returns the character	**
 **			entered with the Enter key to have	**
 **			paused this program.			**
 ****************************************************************/
char getpause (const char *str_Message)
	{
		static char chr_Car=NULL_CHARACTER;

		printf("%s", str_Message);
		scanf("%*c%c", &chr_Car);

		return (chr_Car);
	}

/*****************************************************************
 ** Function:		absolute.				**
 ** Explanation:	Returns as a result the positive or 	**
 **			unsigned value of a certain value,	**
 **			as long as it is subjected to a series	**
 **			of conditions such as being greater	**
 **			than zero, to be positive; be zero,	**
 **			to be zero, and less than zero,		**
 **			to become positive by sign		**
 **			neutralization.				**
 ** Input Parms:	double dbl_value,			**
 ** Output Parms:	None.					**
 ** Result:		the base value (dbl_value) is		**
 **			sign-neutralized.			**
 ****************************************************************/
double absolute(double dbl_value)
	{
		return	(dbl_value == V_ZERO) ? V_ZERO
			: (dbl_value > V_ZERO) ? dbl_value : -dbl_value;
	}

/*****************************************************************
 ** Function:		square_root.				**
 ** Explanation:	We are going to make a function that	**
 **			calculates the square root of a number	**
 **			'n' pof Newton's method.		**
 **			This method is stated as follows:	**
 **			Let 'r[i]' be the approximate square	**
 **			root of 'n'.				**
 **			The following approximate root 'r[i+1]'	**
 **			calculates in function of the above	**
 **			like so:				**
 **			r[i+1] = {(n / r[i] + r[i]) / 2}.	**
 **								**
 **			The process described is repeated until	**
 **			the difference in absolute value of the	**
 **			last two computed approximations, be as	**
 **			small as we want (taking into account	**
 **			the limits set by the compiler).	**
 **								**
 **			According to this, the last The last	**
 **			approximation will be a valid root,	**
 **			when it is fulfilled that:		**
 **			abs(r[i] - r[i+1]) <= e.		**
 ** Input Parms:	double dbl_base,			**
 ** Output Parms:	None.					**
 ** Result:		{(n / 'r[i]') + 'r[i]'} / 2.		**
 ****************************************************************/
double square_root(double dbl_base)
	{
		/*------------------------------------------------
		 * Initialization of the variables of the	--
		 * structure used for the calculations of the	--
		 * quadratic equation.				--
		------------------------------------------------*/
		ssr.dbl_preapproach = V_ZERO;	//Previous approach.
		ssr.dbl_newapproach = V_ONE;	//Current approximation.
		ssr.dbl_prequotient = V_ZERO;	//Previous quotient.
		ssr.dbl_addends = V_ZERO;	//Addends updated.
		ssr.dbl_newquotient = V_ZERO;	//Current ratio.
		ssr.dbl_base_denominator = V_TWO;//Base denominator.
		ssr.dbl_difference = V_ZERO;	//Effective difference.
		ssr.dbl_epsilon = V_PR_TOL;	//Precision tolerance.

		do
			{
				/*--------------------------------
				 * Previous approximation value.--
				 *------------------------------*/
				ssr.dbl_preapproach = ssr.dbl_newapproach;

				/*--------------------------------
				 * First quotient: (n / 'r[i]').--
				 *------------------------------*/
				ssr.dbl_prequotient = dbl_base / ssr.dbl_preapproach;

				/*--------------------------------
				 * Sum of the first quotient:	--
				 * (n / 'r[i]') plus 'r[i]'.	--
				 *------------------------------*/
				ssr.dbl_addends = ssr.dbl_prequotient + ssr.dbl_preapproach;

				/*--------------------------------
				 * Division of sum by two:	--
				 * {(n / 'r[i]') + 'r[i]'} / 2.	--
				 *------------------------------*/
				ssr.dbl_newquotient = ssr.dbl_addends / ssr.dbl_base_denominator;

				/*--------------------------------
				 * The new estimate is assigned --
				 * the new quotient.		--
				 *------------------------------*/
				ssr.dbl_newapproach = ssr.dbl_newquotient;

				/*--------------------------------
				 * Difference of initial rough	--
				 * and current rough estimate.	--
				 *------------------------------*/
				ssr.dbl_difference = ssr.dbl_newapproach - ssr.dbl_preapproach;

			}
		while (absolute(ssr.dbl_difference) >= ssr.dbl_epsilon);

		return ssr.dbl_newapproach;
	}

/*****************************************************************
 ** Function:		quadratic_equation.			**
 ** Explanation:	In this function, we define the roots	**
 ** 			that takes the coefficients 'a', 'b',	**
 **			and 'c' of a quadratic equation of the	**
 **			form: ax^2 + bx + c = 0.		**
 **								**
 **			The function calculates the discriminant**
 **			[(b ^ 2) - (4 * a * c)] to determine the**
 **			type of roots of The equation.		**
 **								**
 **			If the discriminant is greater than zero**
 **			there are two distinct real roots.	**
 **								**
 **			If the discriminant is equal to zero,	**
 **			there is a real and double root.	**
 **								**
 **			If the discriminant is less than zero,	**
 **			there are complex conjugate roots.	**
 ** Input Parms:	double dbl_coefficient_a,		**
 **			double dbl_coefficient_b,		**
 **			double dbl_coefficient_c.		**
 ** Output Parms:	None.					**
 ** Result:		It returns a structure with the		**
 **			fundamental information of the quadratic**
 **			equation that is:			**
 **								**
 **			1. The introduced coefficients of the	**
 **			quadratic equation.			**
 **								**
 **			2. The main determinant or discriminant.**
 **								**
 **			3. The roots 'x1' and 'x2' of the	**
 **			quadratic equation with their respective*+
 **			real parts and imaginary parts.		**
 ****************************************************************/
struct str_quadratic_equation quadratic_equation(double dbl_coefficient_a,
						double dbl_coefficient_b,
						double dbl_coefficient_c)
	{
		/*********************************************************
		 * All the variables of the structure that will return	**
		 * the results of the quadratic equation are previously	**
		 * initialized.						**
		 ********************************************************/
		//Quadratic term.		Coefficient 'a'
		sqe.dbl_quadratic_term_a = V_ZERO;
		//Linear term.			Coefficient 'b'
		sqe.dbl_lineal_term_b = V_ZERO;
		//Constant or independent term.	Coefficient 'c'.
		sqe.dbl_constant_term_c = V_ZERO;
		//Discriminating.		Result in the coefficient 'd'.
		sqe.dbl_discriminating_d = V_ZERO;
		//First root. Value 'x1'. Royal part.
		sqe.dbl_first_root_x1.dbl_royal_part = V_ZERO;
		//First root. Value 'x1'. Imaginary part.
		sqe.dbl_first_root_x1.dbl_imaginary_part = V_ZERO;
		//Second root. Value 'x2'. Royal part.
		sqe.dbl_second_root_x2.dbl_royal_part = V_ZERO;
		//Second root. Value 'x2'. Imaginary part.
		sqe.dbl_second_root_x2.dbl_imaginary_part = V_ZERO;

		//Value is assigned to Quadratic term.	Coefficient 'a'.
		sqe.dbl_quadratic_term_a = dbl_coefficient_a;
		//Value is assigned to Middle ground.	Coefficient 'b'.
	 	sqe.dbl_lineal_term_b = dbl_coefficient_b;
		//Value is assigned to Independent term.Coefficient 'c'.
		sqe.dbl_constant_term_c = dbl_coefficient_c;

		//Discriminating. Result in the coefficient 'd'.
		sqe.dbl_discriminating_d = DISCRIMINATE(dbl_coefficient_a, dbl_coefficient_b, dbl_coefficient_c);

		/*------------------------------------------------
		 * The quadratic term must necessarily be	--
		 * different from zero in order to have a valid	--
		 * quadratic equation.				--
		------------------------------------------------*/
		if (sqe.dbl_quadratic_term_a == V_ZERO)
			if (sqe.dbl_lineal_term_b == V_ZERO)
				;	//Null sentence. The equation is degenerate.
			else
				{
					/*********************************************************
					 * To obtain the real, unique and duplicate root,
					 * it is necessary to modify the calculation, in such a	**
					 * way that said root is calculated when the coefficient**
					 * 'a' is zero, but the coefficient 'b' is different	**
					 *  from zero, with the formula x = -c / b.		**
					*********************************************************/
					sqe.dbl_first_root_x1.dbl_royal_part = UNIQUE_ROOT(dbl_coefficient_b, dbl_coefficient_c);
					sqe.dbl_second_root_x2.dbl_royal_part = sqe.dbl_first_root_x1.dbl_royal_part;
				}
		else
				{
					/*********************************************************
					 * If the discriminant of the quadratic equation	**
					 * is equal to zero, then it means that the equation	**
					 * has a same unique root in the set of real numbers.	**
					*********************************************************/
					if (sqe.dbl_discriminating_d == V_ZERO)
						{
							sqe.dbl_first_root_x1.dbl_royal_part =
								SINGLE_ROOT(dbl_coefficient_a, dbl_coefficient_b);

							sqe.dbl_second_root_x2.dbl_royal_part =
								sqe.dbl_first_root_x1.dbl_royal_part;
						}

					/*********************************************************
					 * If the discriminant of the quadratic equation is	**
					 * greater than zero, then it means that the equation	**
					 * has two distinct roots in the set of real numbers.	**
					*********************************************************/
					if (sqe.dbl_discriminating_d > V_ZERO)
						{
							sqe.dbl_first_root_x1.dbl_royal_part =
								(-dbl_coefficient_b
								+ square_root(sqe.dbl_discriminating_d))
								 / DENOMINATOR(dbl_coefficient_a);

							sqe.dbl_second_root_x2.dbl_royal_part =
								(-dbl_coefficient_b
								- square_root(sqe.dbl_discriminating_d))
								/ DENOMINATOR(dbl_coefficient_a);
						}

					/*********************************************************
					 * If the discriminant of the quadratic equation	**
					 * is less than zero, then it means that the equation	**
					 * has two complex and conjugate roots in the set of	**
					 * imaginary numbers.					**
					*********************************************************/
					if (sqe.dbl_discriminating_d < V_ZERO)
						{
							sqe.dbl_first_root_x1.dbl_royal_part =
								SINGLE_ROOT(dbl_coefficient_a, dbl_coefficient_b);
							sqe.dbl_second_root_x2.dbl_royal_part =
								sqe.dbl_first_root_x1.dbl_royal_part;

							sqe.dbl_first_root_x1.dbl_imaginary_part =
								square_root(-sqe.dbl_discriminating_d)
								/ DENOMINATOR(dbl_coefficient_a);
							sqe.dbl_second_root_x2.dbl_imaginary_part =
								-sqe.dbl_first_root_x1.dbl_imaginary_part;
						}

				}

		return sqe;
	}

/*****************************************************************
 ** Function:		view_info_quadratic_equation_		**
 **			discriminating.				**
 ** Explanation:	The expression 'd' = b^2 - 4*a*c is	**
 **			called the discriminant 'd'.		**
 **								**
 **			Conditions for the discriminant 'd':	**
 **			If 'd' is equal to zero, then there is	**
 **			a unique duplicate root	in the set of	**
 **			real numbers.				**
 **								**
 **			If 'd' is greater than zero, then there	**
 **			are two real roots.			**
 **								**
 **			If 'd' is less than zero, then there	**
 **			are two complex roots of the form:	**
 **			x + y'i'; x - y'i'.			**
 **								**
 **			Conditions of the coefficients:		**
 **			'a', 'b' & 'c' of the quadratic		**
 **			equation:				**
 **			If 'a' is equal to zero:		**
 **				If 'b' is equal to 0:		**
 **					we will print a message **
 **					saying that the		**
 **					equation is unwound.	**
 **				Else				**
 **					there exists a unique	**
 **					root with value -c / b.	**
 **				End If.				**
 **			End If.					**
 ** Input Parms:	struct str_quadratic_equation sqe	**
 ** Output Parms:	None.					**
 ** Result:		It combines the validations for both	**
 **			the values of the coefficients of the	**
 **			quadratic equation and the value thrown	**
 **			by the discriminant or determinant	**
 **			of it.					**
 ****************************************************************/
void view_info_quadratic_equation_discriminating(struct str_quadratic_equation sqeq)
	{
		if (sqe.dbl_discriminating_d == V_ZERO)
			{
				printf("| Las raíces de la ecuación son números reales e iguales.	|\n");
				printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
				printf("| Raíz 'x1'         : [%g].\n", sqeq.dbl_first_root_x1.dbl_royal_part);
				printf("| Raíz 'x2'         : [%g].\n", sqeq.dbl_second_root_x2.dbl_royal_part);
			}

		if (sqe.dbl_discriminating_d > V_ZERO)
			{
				printf("| Las raíces de la ecuación son números reales y diferentes.	|\n");
				printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
				printf("| Raíz 'x1'         : [%g].\n", sqeq.dbl_first_root_x1.dbl_royal_part);
				printf("| Raíz 'x2'         : [%g].\n", sqeq.dbl_second_root_x2.dbl_royal_part);
			}


		if (sqe.dbl_discriminating_d < V_ZERO)
			{
				printf("| Las raíces de la ecuación son números complejos y conjugados.	|\n");
				printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
				printf("| Raíz 'x1'.    Real: [%g]. Imaginaria: [%g]'i'.\n",
					sqeq.dbl_first_root_x1.dbl_royal_part,
					sqeq.dbl_first_root_x1.dbl_imaginary_part);
				printf("| Raíz 'x2'.    Real: [%g]. Imaginaria: [%g]'i'.\n",
					sqeq.dbl_second_root_x2.dbl_royal_part,
					sqeq.dbl_second_root_x2.dbl_imaginary_part);
			}
	}

/*****************************************************************
 ** Function:		view_info_quadratic_equation.		**
 ** Explanation:	This procedure launches a series of	**
 **			messages on the screen that contain all	**
 **			the information collected from the	**
 **			quadratic equation in the data structure**
 **			used for this purpose.			**
 ** Input Parms:	struct str_quadratic_equation sqe	**
 ** Output Parms:	None.					**
 ** Result:		It sends a series of stylized messages  **
 ** 			on the screen with all the information	**
 **			collected in the data structure used to **
 **			save all the calculations made of the	**
 **			quadratic equation.			**
 **			+---|----+---|----+---|----+---|----+-- **
 ** Test Examples:	Coeff 'a'	Coeff 'b'	Coeff'c'**
 **			+1		-5		+6	**
 **			+2		-7		+3	**
 **			-1		+7		-10	**
 **			+1		-2		+1	**
 **			+1		+1		+1	**
 **			+1		-4		+4	**
 **			+7		+21		-28	**
 **			-1		+4		-7	**
 **			+6		-5		+1	**
 **			+1		-5		-84	**
 **			+4		-6		+2	**
 ****************************************************************/
void view_info_quadratic_equation(struct str_quadratic_equation sqeq)
	{
		printf("\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
		printf("| Información de cálculo de la ecuación de segundo grado.       |\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
		printf("| Coeficiente   'a' : [%lf].\n", sqeq.dbl_quadratic_term_a);
		printf("| Coeficiente   'b' : [%lf].\n", sqeq.dbl_lineal_term_b);
		printf("| Coeficiente   'c' : [%lf].\n", sqeq.dbl_constant_term_c);
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
		printf("| Discriminante 'd' : [%lf].\n", sqeq.dbl_discriminating_d);
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");

                if (sqe.dbl_quadratic_term_a == V_ZERO)
                        if (sqe.dbl_lineal_term_b == V_ZERO)
                                {
                                        printf("| La ecuación cuadrática está degenerada por coeficientes ceros.|\n");
                                }
                        else
                                {
                                        printf("| La ecuación cuadrática tiene una única raíz duplicada [x1=x2].|\n");
					view_info_quadratic_equation_discriminating(sqeq);
				}
		else
			view_info_quadratic_equation_discriminating(sqeq);

		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
		printf("\n");
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This program calculates the square root	**
 **			of a number 'n' by Newton's method.	**
 **			This method is stated as follows:	**
 **			Let 'r[i]' be the approximate square	**
 **			root of 'n'.				**
 **			The following approximate root 'r[i+1]'	**
 **			is computed in function of the former.	**
 **			Thus, the iterative calculation formula **
 **			is: r[i+1] = {(n / r[i] + r[i]) / 2}.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		When applying the Newton's method	**
 **			formula for the first time to obtain	**
 **			the kth root, there is an approximation **
 **			variable above that contains the initial**
 **			starting value.				**
 **			For successive occasions, said previous **
 **			approximation value contains the last	**
 **			approximation effectively calculated.	**
 **			Then, a function is called that returns +*
 **			the absolute value of the difference	**
 **			between the previous approximate value	**
 **			and the current approximate value, and	**
 **			said effective difference is compared if**
 **			it is greater than or equal to the	**
 **			expected degree of precision (epsilon), **
 **			in such a way that Fortunately, the	**
 **			iterative calculation of the formula is	**
 **			kept in an internal loop until the value**
 **			of the desired precision tolerance is	**
 **			reached.				**
 **			Finally, the kth root is returned to the**
 **			calculation of the quadratic equation to**
 **			finally print the result.		**
 ****************************************************************/
int main()
	{
		double dbl_coefficient_a = V_ZERO;
		double dbl_coefficient_b = V_ZERO;
		double dbl_coefficient_c = V_ZERO;

		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");
		printf("|          Solución de una ecuación de segundo grado.           |\n");
		printf("+---+----+---+----+---+----+---+----+---+----+---+----+---+----+-\n");

		printf("Coeficiente 'a' : ");
		scanf("%lf", &dbl_coefficient_a);

		printf("Coeficiente 'b' : ");
		scanf("%lf", &dbl_coefficient_b);

		printf("Coeficiente 'c' : ");
		scanf("%lf", &dbl_coefficient_c);

		view_info_quadratic_equation(quadratic_equation(dbl_coefficient_a, dbl_coefficient_b, dbl_coefficient_c));

		getpause("Este programa ha terminado con éxito.\n"
		"Presione la tecla ENTRAR para finalizarlo...");

		return V_ZERO;
	}
