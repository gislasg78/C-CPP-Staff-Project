/* The purpose of this program is to convert Cartesian (rectangular) coordinates to polar coordinates,
   and polar coordinates to Cartesian (rectangular) coordinates. */

/* Standard Work Libraries. */
#include <math.h>
#include <stdio.h>

/* Macros to convert from 'radians' to 'degrees' and from 'degrees' to 'radians'. */
#define	DEGREES(radians)	((radians) * (V_ONE_HUNDRED_EIGHTY) / (M_PI))
#define	RADIANS(degrees)	((degrees) * (M_PI) / (V_ONE_HUNDRED_EIGHTY))

/* Symbolic Work Constants. */
#define	V_ONE_HUNDRED_EIGHTY	180.0
#define V_ZERO			0

//Main function.
int main()
{
	/* Preliminary Working Variables. */
	double A_x = V_ZERO, A_y = V_ZERO, B_radius = V_ZERO, B_angle = V_ZERO;

	/* Initial Header Message. */
	printf("Cartesian-to-Polar coordinate converter and vice versa.\n\n");

	/* Convert Cartesian (Rectangular) Coordinates to Polar Coordinates. */
	printf("Cartesian to Polar Coordinates.\n");
	printf("+ Enter 'X' coordinate of Point 'A': ");
	scanf("%lf", &A_x);
	printf("+ Enter 'Y' coordinate of Point 'A': ");
	scanf("%lf", &A_y);

	printf("\nPoint 'A' is represented in polar coordinates as (%g, %g degrees).\n\n", hypot(A_x, A_y), DEGREES(atan2(A_y, A_x)));

	/* Convert Polar Coordinates to Cartesian (Rectangular) Coordinates. */
	printf("Polar to Cartesian Coordinates.\n");
	printf("+ Enter 'radius' of Point 'B': ");
	scanf("%lf", &B_radius);
	printf("+ Enter 'angle'  of Point 'B' in Degrees: ");
	scanf("%lf", &B_angle);

	printf("\nPoint 'B' is represented in cartesian coordinates as (%g, %g).\n\n", B_radius * cos(RADIANS(B_angle)), B_radius * sin(RADIANS(B_angle)));

	/* Program Termination Messages. */
	printf("Done!\n");
	printf("This program has ended.\n");

	return V_ZERO;
}
