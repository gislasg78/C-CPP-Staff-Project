/*************************************************
 **		PERPETUAL CALENDAR		**
 ** ------------------------------------------- **
 ** Given a date (day, month, year).		**
 ** Given a time (hour, minute, second).	**
 **						**
 ** Indicate the corresponding day of the week.	**
 ** Indicate the corresponding total seconds.	**
 **						**
 ** 		Calendar.c			**
 ************************************************/
#include <stdio.h>
#include <stdlib.h>

//Macro definition to encapsulate time.
#define SECONDS(hour, minute, second)	(((hour) * V_3600) + ((minute) * V_60) + (second))

//Symbolic work constants.
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'

//Numerical symbolic constants
#define	V_8		8
#define	V_11		11
#define	V_15		15
#define	V_19		19
#define V_22		22
#define	V_23		23
#define V_25		25
#define	V_29		29
#define	V_30		30
#define V_31		31
#define V_32		32
#define	V_59		59
#define	V_60		60
#define	V_100		100
#define	V_114		114
#define	V_365		365
#define	V_366		366
#define V_400		400
#define	V_451		451
#define	V_1582		1582
#define	V_3600		3600

//Numerical constants of ordinary work.
#define	V_FIVE		5
#define	V_FOUR		4
#define	V_ONE		1
#define	V_SEVEN		7
#define	V_TEN		10
#define	V_THREE		3
#define V_TWELVE	12
#define	V_TWO		2
#define	V_ZERO		0

static char day_name[V_SEVEN][V_TEN] = {"Saturday", "Sunday", "Monday",
					"Tuesday", "Wednesday", "Thursday",
					"Friday"};

struct months_table
	{
		int month_numberofmonth;
		char month_nameofmonth[V_TEN];
		int month_totaldays;
	}
	months_array[V_TWELVE] =
		{
		 {1, "January", 31}, {2, "February", 28}, {3, "March", 31},
		 {4, "April", 30}, {5, "May", 31}, {6, "June", 30},
		 {7, "July", 31}, {8, "August", 31}, {9, "September", 30},
		 {10, "October", 31}, {11, "November", 30}, {12, "December", 31}
		};

//Prototype functions.
void DateEntry(int *day, int *month, int *year);
int DayOfWeek(const int day, int month, int year);
int DaysInMonth(const int month, const int year);
char GetPause(const char *str_Message);
int JulianYear(const int day, const int month, const int year);
void EasterSunday(const int year, int *month_east, int *day_east);
int LeapYear(const int year);
void SolveSumOfDays(const int sumofdays, int *day, int *month, int *year);
int SumOfDays(int day, int month, int year);
void TimeEntry(int *hour, int *minute, int *second);
int ValidDate(const int day, const int month, const int year);
int ValidTime(const int hour, const int minute, const int second);
void WriteDate(const int day, const int month, const int year);
void WriteTime(const int hour, const int minute, const int second);

//Main function.
int main()
	{
		//Preliminary working variables.
		int day = V_ZERO, month = V_ZERO, year = V_ZERO;
		int hour = V_ZERO, minute = V_ZERO, second = V_ZERO;
		int month_east = V_ZERO, day_east = V_ZERO;

		//Validation of the entry date.
		DateEntry(&day, &month, &year);
		if (ValidDate(day, month, year))
			{
				EasterSunday(year, &month_east, &day_east);
				JulianYear(day, month, year);
				SolveSumOfDays(SumOfDays(day, month, year), &day, &month, &year);
				WriteDate(day, month, year);
			}

		//Validation of the entry time.
		TimeEntry(&hour, &minute, &second);
		if (ValidTime(hour, minute, second))
			{
				WriteTime(hour, minute, second);
			}

		return V_ZERO;
	}

//Function that receives the date data.
void DateEntry(int *day, int *month, int *year)
	{
		printf("\nDate validity checker.\n");
		printf("Please enter the following requested data.\n");
		printf("Year   (%04d ->) : ", V_1582);
		scanf("%d", year);
		printf("Month  (%02d - %02d) : ", V_ONE, V_TWELVE);
		scanf("%d", month);
		printf("Day    (%02d - %02d) : ", V_ONE, V_31);
		scanf("%d", day);
	}

//Function that calculates the number of the day of the week that corresponds to a date.
int DayOfWeek(const int day, int month, int year)
	{
		if (month <= V_TWO)
			{
				month += V_TWELVE;
				year--;
			}

		return ((day + V_TWO * month + V_THREE * (month + V_ONE) / V_FIVE + year + year / V_FOUR - year / V_100 + year / V_400 + V_TWO) % V_SEVEN);
	}

//Number of days in a given month and year.
int DaysInMonth(const int month, const int year)
	{
		int limitdays = months_array[month - V_ONE].month_totaldays;

		if ((month == V_TWO) && (LeapYear(year))) limitdays = V_29;

		return limitdays;
	}

//Function that obtains the Easter Sunday of a given date.
void EasterSunday(const int year, int *month_east, int *day_east)
	{
		int a = V_ZERO, b = V_ZERO, c = V_ZERO, d = V_ZERO, e = V_ZERO;
		int f = V_ZERO, g = V_ZERO, h = V_ZERO, i = V_ZERO, k = V_ZERO;
		int l = V_ZERO, m = V_ZERO;

		//Gauss algorithm for calculating Easter Sunday.
		a = year % V_19;
		b = year / V_100;
		c = year % V_100;
		d = b / V_FOUR;
		e = b % V_FOUR;

		//Intermediate calculations of the Gauss algorithm.
		f = (b + V_8) / V_25;
		g = (b - f + V_ONE) / V_THREE;
		h = (V_19 * a + b - d - g + V_15) % V_30;
		i = c / V_FOUR;
		k = c % V_FOUR;
		l = (V_32 + V_TWO * e + V_TWO * i - h - k) % V_SEVEN;
		m = (a + V_11 * h + V_22 * l) / V_451;

		//Final results.
		*month_east = (h + l - V_SEVEN * m + V_114) / V_31;
		*day_east = ((h + l - V_SEVEN * m + V_114) % V_31) + V_ONE;

		//Print the result.
		printf("\nEaster Sunday: {%d}.\n", year);
		printf("Month: [%s]. Day : [%d].\n", months_array[*month_east - V_ONE].month_nameofmonth, *day_east);
	}

//Function that makes a pause.
char GetPause(const char *str_Message)
	{
		//Preliminary working variables.
		char chr_key = NULL_CHARACTER;

		printf("%s", str_Message);

		//Validate data entry as correct.
		if (scanf("%c", &chr_key))
			{
				scanf("%*[^\n]%*c");
				while ((chr_key = getchar()) != CARRIAGE_RETURN && chr_key != EOF);
			};

		return chr_key;
	}

//Function that obtains the current Julian Year.
int JulianYear(const int day, const int month, const int year)
	{
		int clusterdays = V_ZERO;

		for (int int_month = V_ZERO; int_month < (month - V_ONE); int_month++)
			{
				int limitdays = months_array[int_month].month_totaldays;

                                if ((int_month == V_ONE) && (LeapYear(year))) limitdays = V_29;

				clusterdays += limitdays;
			}

		clusterdays += day;

		printf("\nJulian Year: {%d} : [%d].\n", year, clusterdays);

		return (clusterdays);
	}

//Function that obtains the current Julian year.
int LeapYear(const int year)
	{
		return ((year % V_FOUR == V_ZERO) && (year % V_100 != V_ZERO) || (year % V_400 == V_ZERO));
	}

//Function that reconverts the number of days obtained into its variables of day, month and year.
void SolveSumOfDays(const int sumofdays, int *day, int *month, int *year)
	{
		//Clear the component variables of 'sumofdays'.
		int days_remaining = sumofdays - V_ONE;	//We subtract 1 because we started from day one.
		*year = V_1582;
		*month = V_ONE;
		*day = V_ONE;

		//We return the converted values ​​to the parameters of this function.
		while (days_remaining >= (LeapYear(*year) ? V_366 : V_365))
			{
				days_remaining -= (LeapYear(*year) ? V_366 : V_365);
				(*year)++;
			}

		while (days_remaining >= DaysInMonth(*month, *year))
			{
				days_remaining -= DaysInMonth(*month, *year);
				(*month)++;
			}

		*day += days_remaining;

		//Display the cleared component variables.
		printf("\nConverted date.\n");
		printf("[%04d/%02d/%02d].\n", *year, *month, *day);
	}

//Function that loops through the number of days in a year starting from 1582-01-01.
int SumOfDays (int day, int month, int year)
	{
		int cumofdays = V_ZERO;

		for (int int_year = V_1582; int_year <= year; int_year++)
			{
				int max_month = (int_year < year) ? V_TWELVE : month - V_ONE;

		                for (int int_month = V_ZERO; int_month < max_month; int_month++)
					{
						int limitdays = months_array[int_month].month_totaldays;

						if ((int_month == V_ONE) && (LeapYear(int_year))) limitdays = V_29;

						cumofdays += limitdays;
					}
			}

                cumofdays += day;

		printf("\nSum of days: {%d} : [%d].\n", V_1582, cumofdays);

		return (cumofdays);
	}

//Function that receives the date data.
void TimeEntry(int *hour, int *minute, int *second)
	{
		printf("\nTime validity checker.\n");
		printf("Please enter the following requested data.\n");
		printf("Hour   (%02d - %02d) : ", V_ZERO, V_23);
		scanf("%d", hour);
		printf("Minute (%02d - %02d) : ", V_ZERO, V_59);
		scanf("%d", minute);
		printf("Second (%02d - %02d) : ", V_ZERO, V_59);
		scanf("%d", second);
	}

//This function validates that a date is perfectly correct.
int ValidDate(const int day, const int month, const int year)
	{
		int limitdays = V_ZERO, yearB = V_ZERO, monthB = V_ZERO, dayB = V_ZERO;

		yearB = (year >= V_1582);
		monthB = (month >= V_ONE && month <= V_TWELVE);
		dayB = (day >= V_ONE && day <= V_31);

		if (yearB)
			if (monthB)
				if (dayB)
					{
						limitdays = months_array[month - V_ONE].month_totaldays;

						if ((month == V_TWO) && (LeapYear(year))) limitdays = V_29;

						dayB = (day >= V_ONE && day <= limitdays);

						if (dayB)
							printf("\nCorrect date.\n");
						else
							printf("\nInvalid day: [%d]. Out of range: [%d] and [%d] for month: [%d].\n", day, V_ONE, limitdays, month);
					}
				else
					printf("\nInvalid day: [%d]. Out of range: [%d] and [%d].\n", day, V_ONE, V_31);
			else
				printf("\nInvalid month: [%d]. Out of range: [%d] and [%d].\n", month, V_ONE, V_TWELVE);
		else
			printf("\nInvalid year: [%d]. Out of range: [>=%d].\n", year, V_1582);

		if (!(dayB && monthB && yearB))
			{
				printf("\nData not valid for the date.\n");
				GetPause("Press ENTER key to continue...");
			}

		return (dayB && monthB && yearB);
	}

//This function validates that a time is perfectly correct.
int ValidTime(const int hour, const int minute, const int second)
	{
		int hourB = V_ZERO, minuteB = V_ZERO, secondB = V_ZERO;

		hourB = (hour >= V_ZERO && hour <= V_23);
		minuteB = (minute >= V_ZERO && minute <= V_59);
		secondB = (second >= V_ZERO && second <= V_59);

		if (hourB)
			if (minuteB)
				if (secondB)
					printf("\nCorrect time.\n");
				else
					printf("\nInvalid second: [%d]. Out of range: [%d] and [%d].\n", second, V_ZERO, V_59);
			else
				printf("\nInvalid minute: [%d]. Out of range: [%d] and [%d].\n", minute, V_ZERO, V_59);
		else
			printf("\nInvalid hour: [%d]. Out of range: [%d] and [%d].\n", hour, V_ZERO, V_23);

		if (!(hourB && minuteB && secondB))
			{
				printf("\nData not valid for the time.\n");
				GetPause("Press ENTER key to continue...");
			}

		return (hourB && minuteB && secondB);
	}

//Function that writes a correctly validated date.
void WriteDate(const int day, const int month, const int year)
	{
		int d = V_ZERO;

		d = DayOfWeek(day, month, year);

		printf("\n[%04d/%02d/%02d].\n", year, month, day);
		printf("%s, %s %02d, %04d.\n", day_name[d], months_array[month - V_ONE].month_nameofmonth, day, year);
	}

//Function that writes a correctly validated time.
void WriteTime(const int hour, const int minute, const int second)
	{
		//Preliminary working variables.
		int s_hours = V_ZERO, s_minutes = V_ZERO, s_seconds = V_ZERO;
		int t = V_ZERO;

		t = SECONDS(hour, minute, second);

		//Clear the component variables of the variable 'time'.
                s_hours = t / V_3600;
                s_minutes = (t % V_3600) / V_60;
                s_seconds = t % V_60;

		printf("\nConverted time.\n");
		printf("[%02d:%02d:%02d].\n", s_hours, s_minutes, s_seconds);
		printf("Seconds Time: {%d}.\n", t);
	}
