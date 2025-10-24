/* The purpose of this program is to give the values ​​of the probability density function
   and the cumulative distribution function of the Normal Probability Distribution
   by solving its integral using the Simpson method.
*/

/* Standard Work Libraries. */
#include <math.h>
#include <stdio.h>

/* Symbolic Work Constants. */
#define	V_100000	100000
#define	V_FOUR		4
#define	V_MIDDLE	0.5
#define	V_ONE		1
#define	V_THREE		3
#define V_TWO		2
#define	V_ZERO		0

/* Function to calculate the probability density function (PDF) of the standard normal distribution. */
double normalPDF(double x)
	{
		return exp(-x * x / V_TWO) / sqrt(V_TWO * M_PI);
	}

/* Function to calculate the cumulative distribution function (CDF) of the standard normal distribution. */
double normalCDF(double x)
	{
		/* Preliminary Working Variables. */
		const int n = V_100000;  /* Number of subdivisions for Simpson's approximation. */
		double sum = V_ZERO;

		/* Approximation of the integral using Simpson's formula. */
		for (int i = V_ZERO; i <= n; i++)
			{
				double xi = i * x / n;
				double yi = normalPDF(xi);

				if (i > V_ZERO && i < n)
					{
						if (i % V_TWO == V_ZERO)
							{
								sum += V_TWO * yi;
							}
						else
							{
								sum += V_FOUR * yi;
							}
					}
				else
					{
						sum += yi;
					}
			}

		double integral = sum * (x / n) / V_THREE;

		/* Normalize the CDF value to obtain a result between zero and unity. */
		return V_MIDDLE * (V_ONE + integral);
	}


//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		double x = V_ZERO;

		/* Prompt the user for the value to calculate the PDF and CDF. */
		printf("Normal Probability Distribution.\n");
		printf("Enter a value to calculate the distribution: ");
		scanf("%lf", &x);

		/* Calculate and display the PDF and CDF. */
		double pdf = normalPDF(x);	/* Probability Density Function (PDF). */
		double cdf = normalCDF(x);	/* Cumulative Distribution Function (CDF). */

		printf("\nNormal Probability Distribution Function.\n");
		printf("+ Probability Density Function\t\t(PDF):\t[%lf] = [%lf].\n", x, pdf);
		printf("+ Cumulative Distribution Function\t(CDF):\t[%lf] = [%lf].\n", x, cdf);

		return V_ZERO;
	}
