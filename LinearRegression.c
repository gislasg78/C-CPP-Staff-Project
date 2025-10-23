/* This program obtains the slope and the intercept of a set of two-dimensional points
   by calculating the linear regression function using the least squares method. */

/* Standard work libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_ZERO	0

/* Structure to represent a 2D point with 'x' and 'y' coordinates. */
typedef struct
	{
		double x;
		double y;
	} Point2D;

/* Function to calculate the slope of a line in a linear regression. */
double getSlope(Point2D points[], int number)
	{
		/* Preliminary working variables. */
		double sumXY = V_ZERO, sumX = V_ZERO, sumY = V_ZERO, sumX2 = V_ZERO;

		/* Calculate the necessary summations of this function. */
		for (int idx = V_ZERO; idx < number; idx++)
			{
				sumXY += points[idx].x * points[idx].y;
				sumX += points[idx].x;
				sumY += points[idx].y;
				sumX2 += points[idx].x * points[idx].x;
			}

		/* Calculate the slope of the line of this function. */
		double slope = (number * sumXY - sumX * sumY) / (number * sumX2 - sumX * sumX);
		return slope;
	}

/* Function to calculate the y-intercept of the line of the linear regression function. */
double getOrdinateAtOrigin(Point2D points[], int number, double slope)
	{
		/* Preliminary working variables. */
		double sumX = V_ZERO, sumY = V_ZERO;

		/* Calculate the sums needed for this function. */
		for (int idx = V_ZERO; idx < number; idx++)
			{
				sumX += points[idx].x;
				sumY += points[idx].y;
			}

		/* Calculate the y-intercept of this function. */
		double ordinateAtOrigin = (sumY - slope * sumX) / number;
		return ordinateAtOrigin;
	}


//Main function.
int main()
	{
		/* Preliminary working variables. */
		int number = V_ZERO;

		/* Initial presentation headers. */
		printf("Obtaining the slope and intercept of a linear regression of points.\n");
		printf("Enter the number of two-dimensional points: ");
		scanf("%d", &number);

		Point2D points[number];

		/* Prompt the user for the values ​​of the two-dimensional points (x, y). */
		for (int idx = V_ZERO; idx < number; idx++)
			{
				printf("\nCapture of two-dimensional coordinates [%2d] of [%2d].\n", idx + V_ONE, number);
				printf("Enter the value for x[%2d]: ", idx + V_ONE);
				scanf("%lf", &points[idx].x);
				printf("Enter the value for y[%2d]: ", idx + V_ONE);
				scanf("%lf", &points[idx].y);
			}

		/* Calculate the slope and intercept of the linear regression function. */
		double slope = getSlope(points, number);
		double ordinateAtOrigin = getOrdinateAtOrigin(points, number, slope);

		/* Show the final results. */
		printf("\nLinear Regression Outcomes.\n");
		printf("+ Slope:\t\t[%lf].\n", slope);
		printf("+ Ordinate at Origin:\t[%lf].\n", ordinateAtOrigin);

		return V_ZERO;
	}
