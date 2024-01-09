/************ PI generator by the MonteCarlo method. *************
 ** Source Code:	PI_Monte.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.          	**
 ** Purpose:		This program proposes obtaining the	**
 **			irrational number PI through the	**
 **			MonteCarlo method, which consists of	**
 **			generating a series of random points in	**
 **			an imaginary square plane, and obtaining**
 **			the quotient between the number of	**
 **			points 'p(x,y)' that fall in a circle of**
 **			the form: 'x^2 + y^2', in such a way	**
 **			that the quotient obtained between the	**
 **			number of points generated and the	**
 **			number of points entered by the user is	**
 **			multiplied by the coefficient '4', and	**
 **			is get an approximation to PI.		**
 **								**
 **			To obtain a good approximation of the	**
 **			irrational number PI by the Monte Carlo **
 **			method, it is estimated that 'k' points	**
 **			generated is equal to: 74356 and the	**
 **			number 'n' of points to be generated to	**
 **			calculate said approximation is equal	**
 **			to: 94673, in such a way so that:	**
 **								**
 **			PI = 4 * ('k' / 'n') = 			**
 **			PI = 4 * ( 74356 / 94673 ), literally,	**
 **			is PI.					**
*****************************************************************/
//C Standard Libraries.
#include <iostream>
#include <time.h>

//Symbolic Macros.
#define RANDOM_GENERATOR(s)		((V_MULTIPLIER * (s) + V_INCREMENTER) % V_MODULUS)
#define SUM_OF_QUOTIENTS(n, a_apx)	((((n)/(a_apx)) + (a_apx)) / V_TWO)
#define	SUM_OF_SQUARES(x, y)		(((x) * (x)) + ((y) * (y)))

//Work Numeric Symbolic Constants.
#define V_EPSILON			0.00001
#define	V_INCREMENTER			13849
#define V_MODULUS			65536
#define V_MULTIPLIER			25173
#define V_RESIDUAL_MODULUS		65535

//Auxiliary Numeric Symbolic Constants.
#define V_FOUR				4.0
#define V_ONE				1.0
#define V_TWO				2.0
#define V_ZERO				0

/*****************************************************************
 ** Class:		PI_Monte.				**
 ** Explanation:	This class generates the irrational	**
 **			number PI as a result by implementing	**
 **			its own calculation methods, including	**
 **			the square root, the obtaining of random**
 **			numbers and the absolute value of a	**
 **			certain number, in order to have all	**
 **			these numerical methods implemented in	**
 **			the same parent class.			**
 ** Attributes:		private:				**
 **			static int sttc_int_Counting_PI_Monte;	**
 **			long lng_circle_points_inside=V_ZERO;	**
 **								**
 ** Methods:		private:				**
 **				static size_t			**
 **				sttc_szt_Counting_PI_Monte;	**
 **                     	size_t szt_circle_points_inside;**
 **								**
 **			protected:				**
 **				double abs			**
 **				(const double dbl_value)	**
 **				const;				**
 **				double rnd			**
 **				(size_t *ptr_szt_random_seed)	**
 **				const;				**
 **				double sqr			**
 **				(const double dbl_num)		**
 **				const;				**
 **								**
 **			public:					**
 **				PI_Monte()			**
 **			{this->sttc_int_Counting_PI_Monte++;};	**
 **				double get_dbl_PI_Monte		**
 **				(const size_t			**
 **					szt_points_counting);	**
 ** Result:		The main method that must be called from**
 **			this class is the one that obtains the	**
 **			irrational number PI by the Monte Carlo **
 **			method, which positions a certain number**
 **			of points with abscissas and ordinates	**
 **			obtained randomly and determining if	**
 **			these points are within a circle plane	**
 **			that is It is obtained by adding the	**
 **			squares of said abscissas and ordinates	**
 **			of each point read.			**
 ****************************************************************/
class PI_Monte
	{
		//Private attributes and methods.
		private:
			//Number of instantiated objects of a given class 'PI_Monte'.
			static size_t sttc_szt_Counting_PI_Monte;
			//Number of circles within a circle plane.
			size_t szt_circle_points_inside = V_ZERO;

		//Protected attributes and methods.
		protected:
			//Absolute value of a number.
			double abs(const double dbl_value) const;
			//Random number generated by mixed congruential method.
			double rnd(size_t *ptr_szt_random_seed) const;
			//Square root by Newton's Method.
			double sqr(const double dbl_num) const;

		//Public attributes and methods.
		public:
			//Intrinsic constructor of the 'PI_Monte' class.
			PI_Monte() {this->sttc_szt_Counting_PI_Monte++;};

			//Obtains the irrational number PI by the MonteCarlo method.
			double get_dbl_PI_Monte(const size_t szt_points_counting);
	};

/* ---------------------------------------------------------------
 * This is a global variable belonging to the			--
 * 'PI_Monte' class that is initialized to zero,		--
 * and later in its respective constructors it is increased by	--
 * one unit for each instance generated.			--
 * -------------------------------------------------------------*/
size_t PI_Monte::sttc_szt_Counting_PI_Monte = V_ZERO;

/*****************************************************************
 ** Class:		PI_Monte.				**
 **			double PI_Monte::abs			**
 **				(const double dlb_value) const;	**
 ** Explanation:	Returns as a result the positive or 	**
 **			unsigned value of a certain value,	**
 **			as long as it is subjected to a series	**
 **			of conditions such as being greater	**
 **			than zero, to be positive; be zero,	**
 **			to be zero, and less than zero,		**
 **			to become positive by sign		**
 **			neutralization.				**
 ** Input Parms:	const double dbl_value,			**
 ** Output Parms:	None.					**
 ** Result:		the base value (dbl_value) is		**
 **			sign-neutralized.			**
 ****************************************************************/
double PI_Monte::abs(const double dbl_value) const
	{
		return	(dbl_value > V_ZERO) ? dbl_value :
			(dbl_value == V_ZERO) ? V_ZERO :
			(dbl_value < V_ZERO) ? -dbl_value : V_ZERO;
	};

/*****************************************************************
 ** Class:		PI_Monte.				**
 **			double PI_Monte::rnd			**
 **				(size_t *ptr_szt_random_seed)	**
 **				const;				**
 ** Explanation:	Pseudorandom numbers.			**
 **			An algorithm that generates a random or	**
 **			apparently random sequence of numbers is**
 **			called a random number generator.	**
 **			The most commonly used method for	**
 **			generating random numbers is the linear	**
 **			congruential method.			**
 **			Each number in the sequence 'r[i]',	**
 **			is calculated from its predecessor	**
 **			'r[¡-¡]' using the following formula:	**
 **								**
 **			'r[i]' = (coefficient_multiplier *	**
 **			'r[i-1]' + coefficient_incrementor) %	**
 **				coefficient_remainder_modular_	**
 **				integer_division.		**
 **								**
 **			The sequence thus generated is more	**
 **			correctly called a pseudo-random	**
 **			sequence, since each number generated	**
 **			depends on the previously generated one.**
 **			The following algorithm, presented as a	**
 **			C function, generates a number out of	**
 **			65536 random numbers and will not cause	**
 **			an override on a computer that supports	**
 **			an integer range of -2^31 to 2^31.	**
 **								**
 **			The call to this function passes the	**
 **			parameter by reference, in order to	**
 **			generate a different random number each	**
 **			time.					**
 **								**
 **			The function generates numbers 		**
 **			in-integers between 0 and 65535.	**
 **			For most applications, these numbers	**
 **			should be within two within a required	**
 **			interval.				**
 **								**
 ** Input Parms:	long *ptr_szt_random_seed.		**
 ** Output Parms:	long *ptr_szt_random_seed.		**
 ** Result:		We often require a random value between **
 **			zero and one. For this purpose we can	**
 +*			use a modified version.			**
 ****************************************************************/
double PI_Monte::rnd(size_t *ptr_szt_random_seed) const
	{
		return ( (double) (*ptr_szt_random_seed = RANDOM_GENERATOR(*ptr_szt_random_seed) ) / (double) V_RESIDUAL_MODULUS );
	};

/*****************************************************************
 ** Class:		PI_Monte.				**
 **			double PI_Monte::sqr			**
 **				(const double dbl_num) const;	**
 ** Explanation:	In this method the square root of a	**
 **			number 'n' is calculated by Newton's	**
 **			method.					**
 **								**
 **			This method is stated as follows:	**
 **			let 'r[¡]' be the approximate square	**
 **			root of 'n'.				**
 **								**
 **			The next approximate root 'r[i+1]' is	**
 **			calculated based on the previous root,	**
 **			such that:				**
 **								**
 **			'r[i+1]' = {(n / 'r[i]') + 'r[i]'} / 2.	**
 **								**
 **			The described process is repeated until	**
 **			the difference in absolute value of the	**
 **			last two calculated approximations is as**
 **			minuscule as specified (taking into	**
 **			account the limits set by the compiler).**
 **								**
 **			According to this, the last		**
 **			approximation will be a valid square	**
 **			root, when the surrogate criterion is	**
 **			met:					**
 **								**
 **			absolute_value('r[¡]' - 'r[¡+1]')	**
 **				<= epsilon_value.		**
 ** Input Parms:	const double dbl_num.			**
 ** Output Parms:	None.					**
 ** Result:		Care must be taken that the formal input**
 **			parameter does not receive a negative	**
 **			number as a current parameter, since the**
 **			k-th even roots of negative numbers have**
 **			no solution in the set of real numbers,	**
 **			that is, it must be avoided because an	**
 **			infinite cycle could be created in this	**
 **			method, by trying to return the square	**
 **			root of said number by series of	**
 **			quotients.				**
 ****************************************************************/
double PI_Monte::sqr(const double dbl_num) const
	{
		double dbl_prev_approx = V_ZERO;
		double dbl_approach = V_ONE;

		do
			{
				dbl_prev_approx = dbl_approach;
				dbl_approach = SUM_OF_QUOTIENTS(dbl_num, dbl_prev_approx);
			}
		while (PI_Monte::abs(dbl_approach - dbl_prev_approx) >= V_EPSILON);

		return dbl_approach;
	};

/*****************************************************************
 ** Class:		PI_Monte.				**
 **			double PI_Monte::get_dbl_PI_Monte	**
 **				(const size_t szt_points);	**
 ** Explanation:	This method calculates through the	**
 **			Monte Carlo model the irrational number	**
 **			PI, which consists of receiving a	**
 **			certain number of points that must be	**
 **			randomly placed within the imaginary	**
 **			surface of a circle, expressed by the	**
 **			formula 'x² + y²', in which the		**
 **			abscissas and ordinates of each point	**
 **			are arbitrarily generated and it is	**
 **			determined if the sum of their squares	**
 **			is less than unity; if so, one of those	**
 **			points is counted within that surface.	**
 **								**
 **			At the end, the number of points that	**
 **			were able to be placed inside the circle**
 **			is divided by the total number of	**
 **			points, and then, said quotient is	**
 **			multiplied by the coefficient 4,	**
 **			giving said approximation to PI.	**
 ** Input Parms:	const size_t szt_points_counting,	**
 ** Output Parms:	None.					**
 ** Result:		If the sample space given by: 'x²+y²'	**
 **			is less than unity (1), a point is added**
 **			to 'n' giving 'k'.			**
 **			At the end, divide 'k' / 'n' and	**
 **			multiply 4.0 * ('k' / 'n').		**
 ****************************************************************/
double PI_Monte::get_dbl_PI_Monte(const size_t szt_points_counting)
	{
		size_t szt_random_seed = V_ZERO;

		double dbl_coord_x = V_ZERO;
		double dbl_coord_y = V_ZERO;

		/* The 'time' function returns the number of seconds since zero hours on January 1, 1970. */
		time_t t_tm_seconds = V_ZERO;
		time (&t_tm_seconds);

		/* ------------------------------------------------------------------------------------	--
		 * The 'szt_random_seed' value sets the starting point for generating pseudorandom	--
		 * numbers. In other words, it initializes the pseudorandom number generator based on	--
		 * the value of its argument.								--
		 * ------------------------------------------------------------------------------------ */
		szt_random_seed = (unsigned) (t_tm_seconds % V_RESIDUAL_MODULUS);

		for (size_t szt_idx = V_ZERO; szt_idx < szt_points_counting; szt_idx++)
			{
				dbl_coord_x = PI_Monte::rnd(&szt_random_seed);
				dbl_coord_y = PI_Monte::rnd(&szt_random_seed);

				if(PI_Monte::sqr(SUM_OF_SQUARES(dbl_coord_x, dbl_coord_y)) <= V_ONE)
					this->szt_circle_points_inside++;
			}

		return (V_FOUR * (double) this->szt_circle_points_inside) / (double) szt_points_counting;
	};


/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This main module asks the user as	**
 **			keyboard input for the number of points	**
 **			that he wants to be used as the number	**
 **			of terms to calculate the value of PI by**
 **			the MonteCarlo method, and then the	**
 **			method of the instantiated class is	**
 **			called to obtain the value IP approx.	**
 **								**
 **			It should be remembered that the ideal	**
 **			would be that the number of points	**
 **			placed 'k' in a sample space 'x²+y²<=1'	**
 **			is such that 'k'/'n' ~= 0.78539816339.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The approximation of the irrational	**
 **			number 'PI' by the Monte Carlo method	**
 **			is displayed on the screen.		**
 **			It is recommended that the number of	**
 **			terms to be entered is in the range of	**
 **			2¹⁰ and 2²⁰.				**
 ****************************************************************/
int main()
	{
		double dbl_PI_MonteCarlo = V_ZERO;
		size_t szt_points_counting = V_ZERO;

		PI_Monte pi_monte;

		std::cout << "+---|----+---|----+---|----+---|---" << std::endl;
		std::cout << "| Results Monte Carlo PI Method.  |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|---" << std::endl;
		std::cout << "Points's Number to get PI: ";
		std::cin >> szt_points_counting;

		dbl_PI_MonteCarlo = pi_monte.get_dbl_PI_Monte(szt_points_counting);

		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|---" << std::endl;
		std::cout << "| Results Monte Carlo PI Method.  |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|---" << std::endl;
		std::cout << "| Terms PI :\t[" << szt_points_counting << "]." << std::endl;
		std::cout << "| Value PI :\t[" << dbl_PI_MonteCarlo << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|---" << std::endl;

		return V_ZERO;
	}
