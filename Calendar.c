/*************************************************
 **		PERPETUAL CALENDAR		**
 ** ------------------------------------------- **
 ** Given a date (day, month, year).		**
 ** Indicate the corresponding day of the week.	**
 **						**
 ** 		calendar.c			**
 ************************************************/
#include <stdio.h>
#include <stdlib.h>

#define	V_29		29
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
		char month_nameofmonth[V_TEN];
		int month_totaldays;
	}
	months_array[V_TWELVE] =
		{
		 {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},
		 {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31},
		 {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}
		};

void DateEntry(int *day, int *month, int *year);
int DayOfWeek(int day, int month, int year);
int LeapYear(int year);
void ReadDate(int *day, int *month, int *year);
int ValidDate(int day, int month, int year);
void WriteDate(int day, int month, int year);

int main()
	{
		int day = V_ZERO, month = V_ZERO, year = V_ZERO;

		ReadDate(&day, &month, &year);
		WriteDate(day, month, year);

		return V_ZERO;
	}

void DateEntry(int *day, int *month, int *year)
	{
		printf("Date validity checker.\n");
		printf("Please enter the following requested data.\n");
		printf("Year  (1582 ->) : ");   scanf("%d", year);
		printf("Month (01 - 12) : ");   scanf("%d", month);
		printf("Day   (01 - 31) : ");   scanf("%d", day);
	}

int DayOfWeek(int day, int month, int year)
	{
		if (month <= V_TWO)
			{
				month += V_TWELVE;
				year--;
			}

		return ((day + V_TWO * month + V_THREE * (month + V_ONE) / V_FIVE + year + year / V_FOUR - year / V_100 + year / V_400 + V_TWO) % V_SEVEN);
	}

int LeapYear(int year)
	{
		return ((year % V_FOUR == V_ZERO) && (year % V_100 != V_ZERO) || (year % V_400 == V_ZERO));
	}

void ReadDate(int *day, int *month, int *year)
	{
		int valid_date = V_ZERO;

		while (!valid_date)
			{
				DateEntry(day, month, year);
				valid_date = ValidDate(*day, *month, *year);
			}
	}

int ValidDate(int day, int month, int year)
	{
		char chr = V_ZERO;
		int limitdays = V_ZERO, yearB = V_ZERO, monthB = V_ZERO, dayB = V_ZERO;

		yearB = (year >= V_1582);
		monthB = (month >= V_ONE && month <= V_TWELVE);

		if (monthB)
			{
				limitdays = months_array[month - V_ONE].month_totaldays;

				if ((month == V_TWO) && (LeapYear(year))) limitdays = V_29;

				dayB = (day >= V_ONE && day <= limitdays);
			}
		else
			printf("Wrong month : [%d].\n", month);

		if (!(dayB && monthB && yearB))
			{
				printf("\n");
				printf("Data not valid for the date.\n");
				printf("Press ENTER key to continue...");
				scanf("%*c%c", &chr);
			}

		return (dayB && monthB && yearB);
	}

void WriteDate(int day, int month, int year)
	{
		int d = V_ZERO;

		d = DayOfWeek(day, month, year);

		printf("\n");
		printf("[%04d/%02d/%02d].\n", year, month, day);
		printf("%s, %s %02d, %04d.\n", day_name[d], months_array[month - V_ONE].month_nameofmonth, day, year);
	}
