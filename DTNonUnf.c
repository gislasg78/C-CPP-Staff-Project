#include <stdio.h>

//Macro definitions to encapsulate time and date values.
#define	ZIP_DATE(year, month, date)		(((year - V_1980) * V_515) + (month * V_32) + day)
#define	ZIP_TIME(hour, minute, second)		(((hour) * V_2048) + ((minute) * V_32) + (second / V_TWO))

//Symbolic work constants.
#define	V_32	32
#define	V_515	515
#define	V_1980	1980
#define	V_2048	2048

#define	V_TWO	2
#define	V_ZERO	0

//Main function.
int main()
	{
		//Preliminary working variables.
		//Variables for the hours.
		short hour = V_ZERO, minute = V_ZERO, second = V_ZERO;
		int s_hours = V_ZERO, s_minutes = V_ZERO, s_seconds = V_ZERO;
		int zip_time = V_ZERO;

		//Variables for the dates.
		short year = V_ZERO, month = V_ZERO, day = V_ZERO;
		int s_years = V_ZERO, s_months = V_ZERO, s_days = V_ZERO;
		int zip_date = V_ZERO;

		//Presentation header.
		printf("Datetime to integer encoder in 'C'.\n");

		//Prompt the user to enter the year, month, and day of the date.
		printf("\nCurrent date.\n");
		printf("Year    : ");
		scanf("%hi", &year);
		printf("Month   : ");
		scanf("%hi", &month);
		printf("Day     : ");
		scanf("%hi", &day);

		//Prompt the user to enter the hours, minutes, and seconds of the hour.
		printf("\nCurrent time.\n");
		printf("Hour    : ");
		scanf("%hi", &hour);
		printf("Minute  : ");
		scanf("%hi", &minute);
		printf("Second  : ");
		scanf("%hi", &second);

		//Calculate the variables 'date' and 'time'.
		zip_date = ZIP_DATE(year, month, day);
		zip_time = ZIP_TIME(hour, minute, second);

		//Display the value of the variables 'date' and 'time'.
		printf("\nNon-uniform coding system.\n");
		printf("* Calculated date: {%d}.\n", zip_date);
		printf("* Calculated time: {%d}.\n", zip_time);

		//Clear the component variables of the variable 'date'.
		s_years = (zip_date / V_515) + V_1980;
		s_months = (zip_date % V_515) / V_32;
		s_days = (zip_date % V_32);

		//Clear the component variables of the variable 'time'.
		s_hours = zip_time / V_2048;
		s_minutes = (zip_time % V_2048) / V_32;
		s_seconds = (zip_time % V_32) * V_TWO;

		//Non-uniform coding system.
		printf("\nCompacted values ​​with non-uniform formulas.\n");

		//Display the cleared component variables of the variable 'date'.
		printf("Extracting the variables of the 'date' variable.\n");
		printf("* Years   : [%d].\n", s_years);
		printf("* Months  : [%d].\n", s_months);
		printf("* Days    : [%d].\n", s_days);

		//Display the cleared component variables of the variable 'time'.
		printf("Extracting the variables of the 'time' variable.\n");
		printf("* Hours   : [%d].\n", s_hours);
		printf("* Minutes : [%d].\n", s_minutes);
		printf("* Seconds : [%d].\n", s_seconds);

		return V_ZERO;
	}
