/*************************************************
 **		PERPETUAL CALENDAR		**
 ** ------------------------------------------- **
 ** Given a date (day, month, year).		**
 ** Indicate the corresponding day of the week.	**
 **						**
 ** 		Calendar.c			**
 ************************************************/
#include <stdio.h>
#include <stdlib.h>

#define	V_29		29
#define V_31		31
#define	V_100		100
#define V_400		400
#define	V_1582		1582

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

void DateEntry(const int baseyear, int *const day, int *const month, int *const year);
int DayOfWeek(const int day, int month, int year);
int JulianYear(int day, int month, int year);
int LeapYear(int year);
int SumOfDays(const int baseyear, int day, int month, int year);
int ValidDate(const int baseyear, const int day, const int month, const int year);
void WriteDate(const int day, const int month, const int year);

int main()
	{
		int day = V_ZERO, month = V_ZERO, year = V_ZERO;

		DateEntry(V_1582, &day, &month, &year);

		if (ValidDate(V_1582, day, month, year))
			{
				JulianYear(day, month, year);
				SumOfDays(V_1582, day, month, year);
				WriteDate(day, month, year);
			}

		return V_ZERO;
	}

void DateEntry(const int baseyear, int *const day, int *const month, int *const year)
	{
		printf("Date validity checker.\n");
		printf("Please enter the following requested data.\n");
		printf("Year  (%04d ->) : ", baseyear);
		scanf("%d", year);
		printf("Month (%02d - %02d) : ", V_ONE, V_TWELVE);
		scanf("%d", month);
		printf("Day   (%02d - %02d) : ", V_ONE, V_31);
		scanf("%d", day);
	}

int DayOfWeek(const int day, int month, int year)
	{
		if (month <= V_TWO)
			{
				month += V_TWELVE;
				year--;
			}

		return ((day + V_TWO * month + V_THREE * (month + V_ONE) / V_FIVE + year + year / V_FOUR - year / V_100 + year / V_400 + V_TWO) % V_SEVEN);
	}

int JulianYear(int day, int month, int year)
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

int LeapYear(int year)
	{
		return ((year % V_FOUR == V_ZERO) && (year % V_100 != V_ZERO) || (year % V_400 == V_ZERO));
	}

int SumOfDays (const int baseyear, int day, int month, int year)
	{
		int cumofdays = V_ZERO;

		for (int int_year = baseyear; int_year <= year; int_year++)
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

		printf("\nSum of days: {%d} : [%d].\n", baseyear, cumofdays);

		return (cumofdays);
	}

int ValidDate(const int baseyear, const int day, const int month, const int year)
	{
		char chr = V_ZERO;
		int limitdays = V_ZERO, yearB = V_ZERO, monthB = V_ZERO, dayB = V_ZERO;

		yearB = (year >= baseyear);
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
			printf("\nInvalid year: [%d]. Out of range: [>=%d].\n", year, baseyear);

		if (!(dayB && monthB && yearB))
			{
				printf("\n");
				printf("Data not valid for the date.\n");
				printf("Press ENTER key to continue...");
				scanf("%*c%c", &chr);
			}

		return (dayB && monthB && yearB);
	}

void WriteDate(const int day, const int month, const int year)
	{
		int d = V_ZERO;

		d = DayOfWeek(day, month, year);

		printf("\n");
		printf("[%04d/%02d/%02d].\n", year, month, day);
		printf("%s, %s %02d, %04d.\n", day_name[d], months_array[month - V_ONE].month_nameofmonth, day, year);
	}
