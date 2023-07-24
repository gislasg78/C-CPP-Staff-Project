/***************** K-th root by Newton's Method. *****************
 ** Source Code:	Root.c					**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, August 31, 2023.          	**
 ** Purpose:		This program obtains the k-th root of a	**
 **			given numerical coefficient by Newton's	**
 **			method through iterations of successive	**
 **			series. Even the derivative used	**
 **			to solve this problem is explained.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_ONE		1
#define V_PR_TOL	0.000001;	//Base Precision tolerance.
#define V_ZERO		0

/*****************************************************************
 ** Structure that stores the values of the series of successive**
 ** divisions of Newton's method to obtain the k-th root of a	**
 ** given coefficient.						**
*****************************************************************/
struct strct_root_drvtv
	{
		double dbl_numerator_fx;	//Numerator.
		double dbl_denominator_fpx;	//Denominator.
		double dbl_quotient;		//Quotient.
		double dbl_remainder;		//Remainder.
		double dbl_difference;		//Difference.
	} sd = {V_ZERO};

/*****************************************************************
 ** Function:           absolute.                               **
 ** Explanation:        Returns as a result the positive or     **
 **                     unsigned value of a certain value,      **
 **                     as long as it is subjected to a series  **
 **                     of conditions such as being greater     **
 **                     than zero, to be positive; be zero,     **
 **                     to be zero, and less than zero,         **
 **                     to become positive by sign              **
 **                     neutralization.                         **
 ** Input Parms:        double dbl_value.                       **
 ** Output Parms:       None.                                   **
 ** Result:             the base value (int_value) is           **
 **                     sign-neutralized.                       **
 ****************************************************************/
double absolute(double dbl_value)
	{
		return  (dbl_value==V_ZERO) ? V_ZERO
		: (dbl_value>V_ZERO) ? dbl_value : -dbl_value;
	}

/*****************************************************************
 ** Function:           potency.                                **
 ** Explanation:        Returns a base coefficient raised to the**
 **                     specified power recursively by means of **
 **                     successive multiplications or divisions.**
 **                                                             **
 **                     This function can also be programmed    **
 **                     recursively in the form:                **
 **                     (int_exp == V_ZERO) ? V_ONE : dbl_base  **
 **                      * potency(dbl_base, int_exp - V_ONE);  **
 **                                                             **
 ** Input Parms:        double dbl_base,                        **
 **                     integer int_exp.                        **
 ** Output Parms:       None.                                   **
 ** Result:             dbl_base raised to int_exp.             **
 ****************************************************************/
double potency(double dbl_base, int int_exp)
	{
		double dbl_ret=V_ONE;
		int int_exp_pow=absolute(int_exp);

		for (int int_i=V_ZERO; int_i<int_exp_pow; int_i++)
			{
		        	dbl_ret = (int_exp > V_ZERO) ? dbl_ret * dbl_base :
		                	  (int_exp < V_ZERO) ? dbl_ret / dbl_base : V_ONE;
			}

		return dbl_ret;
        }

/*****************************************************************
 ** Function:		root_derivative.			**
 ** Explanation:	Returns all the previous results needed	**
 **			for the series of divisions that make up**
 **			the Newton's method series to get the	**
 **			'root' of a specified coefficient.	**
 ** Input Parms:	double dbl_initial_x,			**
 **			double dbl_base,			**
 **			integer int_exp.			**
 ** Output Parms:	None.					**
 ** Result:		The numerator "f(x)", the denominator	**
 **			"f'(x)", the quotient and the remainder	**
 **			of a fraction of the series that make up**
 **			Newton's method to obtain the k-th root	**
 **			of a coefficient are calculated as	**
 **			results of a determined numeric value.	**
 ** +---+----+---+----+---+----+---+----+---+----+---+----+---+ **
 ** Procedure:		To calculate the k-th root of a number	**
 **			'n' by Newton's method:			**
 **								**
 **			1. First, an initial estimate for the	**
 **			kth root must be chosen, let's call it	**
 **			'x0'.					**
 **								**
 **			2. Then, the following formula is used	**
 **			to obtain a better approximation of the	**
 **			root:					**
 **			x1 = (1/k) * _				**
 **			{(k - 1) * x0 + n / [x0 ^ (k - 1)]}	**
 **								**
 **			3. The previous step is repeated, using	**
 **			the last approximation obtained, until	**
 **			a desired precision is reached.		**
 **								**
 **			In summary, Newton's method to calculate**
 **			the kth root of a number 'n' consists of**
 **			using an initial estimate and applying	**
 **			the previous formula to obtain a better	**
 **			approximation, repeating the process	**
 **			until the desired precision is reached.	**
 ****************************************************************/
struct strct_root_drvtv root_derivative(
					double dbl_initial_x,
					double dbl_base,
					int int_exp)
	{
		/*------------------------------------------------
		 ** Results obtained from the series of		--
		 ** consecutive divisions by Newton's method.	--
		 ** These results have to be initialized	--
		 ** previously.					--
		 **---------------------------------------------*/
		sd.dbl_numerator_fx = V_ZERO;	//Numerator.
		sd.dbl_denominator_fpx = V_ZERO;//Denominator.
		sd.dbl_quotient = V_ZERO;	//Quotient.
		sd.dbl_remainder = V_ZERO;	//Remainder.
		sd.dbl_difference = V_ZERO;	//Difference.

		/*------------------------------------------------
		 ** The Function f(x) = [x ^ k] is obtained for	--
		 ** the numerator.				--
		 **---------------------------------------------*/
		sd.dbl_numerator_fx = potency(dbl_initial_x, int_exp) - dbl_base;

		/*------------------------------------------------
		 ** The derivative of the Function f(x) is	--
		 ** obtained for the denominator as f'(x).	--
		 ** Said derivative: f'(x) = [k * x ^ (k - 1)]. --
		 **---------------------------------------------*/
		sd.dbl_denominator_fpx = int_exp * potency(dbl_initial_x, int_exp - V_ONE);

		/*------------------------------------------------
		 ** The quotient is obtained by dividing:	--
		 ** f(x) / f'(x) which is the same as saying:	--
		 ** [x ^ k] / [k * x ^ (k - 1)].		--
		 **---------------------------------------------*/
		sd.dbl_quotient = sd.dbl_numerator_fx / sd.dbl_denominator_fpx;

		/*------------------------------------------------
		 ** The residual difference between the starting--
		 ** value 'x' and the quotient [f(x) / f'(x)] is--
		 ** obtained.					--
		 **---------------------------------------------*/
		sd.dbl_remainder = dbl_initial_x - sd.dbl_quotient;

		/*------------------------------------------------
		 ** The difference between the residual quantity--
		 ** and the initial value for 'x' is obtained.	--
		 **---------------------------------------------*/
		sd.dbl_difference = sd.dbl_remainder - dbl_initial_x;

		return sd;
	}

/*****************************************************************
 ** Function:		root.					**
 ** Explanation:	Returns the kth root of a given base	**
 **			value through a series of iterations of	**
 **			Newton's method.			**
 ** Input Parms:	double dbl_base,			**
 **			integer int_exp.			**
 ** Output Parms:	None.					**
 ** Result:		the kth root (int_exp) of the given	**
 **			base (dbl_base).			**
 ****************************************************************/
double root(double dbl_base, int int_exp)
	{
		//Structure with the results of the derivative.
		struct strct_root_drvtv sdv = {V_ZERO};

		//Control initial values.
		double dbl_initial_x = V_ONE;	//Bootstrap value.
		double dbl_epsilon = V_PR_TOL;	//Precision tolerance.

		do
			{
				/*------------------------------------------------
				 ** This function returns as its result a	--
				 ** structure with all the result values of the --
				 ** applied derivative.				--
				 *----------------------------------------------*/
				sdv = root_derivative(dbl_initial_x, dbl_base, int_exp);

				/*------------------------------------------------
				 ** The initial value of 'x' now receives the	--
				 ** residual value.				--
				 **---------------------------------------------*/
				dbl_initial_x = sdv.dbl_remainder;
			}
		while (absolute(sdv.dbl_difference) >= dbl_epsilon);

		return dbl_initial_x;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	Main module in which the objectives of	**
 **			this program are developed.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		In this main function, the base and	**
 **			exponent (root) coefficients are	**
 **			requested as input values to call the	**
 **			function in charge of carrying out the	**
 **			iterations by Newton's method to obtain	**
 **			the result of the k-th root of a given	**
 **			value.					**
 ****************************************************************/
int main()
	{
		double dbl_base=V_ZERO;
		double dbl_root=V_ZERO;
		int int_exp=V_ZERO;

		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("|  Raíces k-ésimas por el Método de Newton.  |\n");
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("Base: ");
		scanf("%lf", &dbl_base);
		printf("Raíz: ");
		scanf("%d", &int_exp);

		dbl_root=root(dbl_base, int_exp);

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|----+-\n");
		printf("| Resultados obtenidos para una raíz k-ésima. |\n");
		printf("+---|----+---|----+---|----+---|----+---|----+.\n");
		printf("| Base      : [%lf].\n", dbl_base);
		printf("| Raíz      : [%d].\n", int_exp);
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("| Resultado : [%lf].\n", dbl_root);
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("\n");

		return int_exp;
	}
