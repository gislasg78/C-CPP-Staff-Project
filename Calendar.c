/* This program aims to provide general processing
   with various implemented date and time functions. */

//Standard work libraries.
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

//List of types with the options to try for this Calendar program.
enum enm_CalendarOptions
	{
		enm_CO_set_start_date = V_ONE,
		enm_CO_number_of_days,
		enm_CO_day_of_week,
		enm_CO_get_easter_sunday,
		enm_CO_capture_date,
		enm_CO_capture_time,
		enm_CO_difference_between_dates,
		enm_CO_obtain_julian_year,
		enm_CO_check_leap_year,
		enm_CO_check_sum_of_days,
		enm_CO_validate_date,
		enm_CO_validate_time,
		enm_CO_write_date,
		enm_CO_write_time,
		enm_CO_exit_menu
	};

//Global table of the names of the days of the week.
static char day_name[V_SEVEN][V_TEN] = {"Saturday", "Sunday", "Monday",
					"Tuesday", "Wednesday", "Thursday",
					"Friday"};

//Global table of the names of the months of the year.
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
int DaysInMonth(const int year, const int month);
int DayOfWeek(const int day, int month, int year);
int DifferenceBetweenDates(int start_first_day, int start_first_month, int start_first_year, int first_day, int first_month, int first_year, int start_second_day, int start_second_month, int start_second_year, int second_day, int second_month, int second_year);
void EasterSunday(const int year, int *month_east, int *day_east);
void EntryDate(int *day, int *month, int *year);
void EntryTime(int *hour, int *minute, int *second);
int GetEntry(int *data_value);
int GetResponse(const char *str_Message);
int JulianYear(const int day, const int month, const int year, int *days_rest);
int LeapYear(const int year);
int Menu(int *start_day, int *start_month, int *start_year, int *day, int *month, int *year, int *hour, int *minute, int *second, int *option, int *counter);
int SelectMenu(int *start_day, int *start_month, int *start_year, int *day, int *month, int *year, int *hour, int *minute, int *second, enum enm_CalendarOptions enm_CO_myOption, int *counter);
void SolveJulianYear(const int year, const int julianyeardays, int *julian_month, int *julian_day);
void SolveSumOfDays(const int start_day, const int start_month, const int start_year, int sumofdays, int *day, int *month, int *year);
int SumOfDays(const int start_day, const int start_month, const int start_year, const int day, const int month, const int year);
int ValidDate(const int day, const int month, const int year);
int ValidTime(const int hour, const int minute, const int second);
void WriteDate(const int day, const int month, const int year);
void WriteTime(const int hour, const int minute, const int second);

//Main function.
int main()
	{
		//Preliminary working variables.
		int counter = V_ZERO;
		int day = V_ONE, month = V_ONE, year = V_ONE;
		int start_day = V_ONE, start_month = V_ONE, start_year = V_ONE;
		int hour = V_ZERO, minute = V_ZERO, second = V_ZERO;

		int option = Menu(&start_day, &start_month, &start_year, &day, &month, &year, &hour, &minute, &second, &option, &counter);

		return V_ZERO;
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
int DaysInMonth(const int year, const int month)
	{
		int limitdays = months_array[month - V_ONE].month_totaldays;

		if ((month == V_TWO) && (LeapYear(year))) limitdays = V_29;

		return limitdays;
	}

//Function that calculates the difference between two given dates.
int DifferenceBetweenDates(int start_first_day, int start_first_month, int start_first_year, int first_day, int first_month, int first_year, int start_second_day, int start_second_month, int start_second_year, int second_day, int second_month, int second_year)
	{
		/* Preliminary working variables. */
		int difference_total_number_of_days = V_ZERO;
		int total_number_of_days_first_date = V_ZERO, total_number_of_days_second_date = V_ZERO;

		printf("Calculating the difference between two specific dates.\n");

		/* First calculation date. */
		printf("Departure date for the first date.\n");
		EntryDate(&start_first_day, &start_first_month, &start_first_year);

		printf("First departure date.\n");
		EntryDate(&first_day, &first_month, &first_year);

		/* Second calculation date. */
		printf("Departure date for the second date.\n");
		EntryDate(&start_second_day, &start_second_month, &start_second_year);

		printf("Second departure date.\n");
		EntryDate(&second_day, &second_month, &second_year);

		/* Calculation of the number of days for each date obtained from its starting date. */
		total_number_of_days_first_date = SumOfDays(start_first_day, start_first_month, start_first_year, first_day, first_month, first_year);
		total_number_of_days_second_date = SumOfDays(start_second_day, start_second_month, start_second_year, second_day, second_month, second_year);
		difference_total_number_of_days = total_number_of_days_second_date - total_number_of_days_first_date;

		/* Date report output messages. */
		printf("\n");
		printf("+===+====+===+====+===+====+===+====+\n");
		printf("| Difference in days between dates. |\n");
		printf("+===+====+===+====+===+====+===+====+\n");
		printf("|            First Date.            |\n");
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("| Start  : [%04d/%02d/%02d].\n", start_first_year, start_first_month, start_first_day);
		printf("| First  : [%04d/%02d/%02d].\n", first_year, first_month, first_day);
		printf("| Days   : [%d].\n", total_number_of_days_first_date);
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("|           Second Date.            |\n");
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("| Start  : [%04d/%02d/%02d].\n", start_second_year, start_second_month, start_second_day);
		printf("| Second : [%04d/%02d/%02d].\n", second_year, second_month, second_day);
		printf("| Days   : [%d].\n", total_number_of_days_second_date);
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("| Diff   : [%d].\n", difference_total_number_of_days);
		printf("+===+====+===+====+===+====+===+====+\n");

		return difference_total_number_of_days;
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
	}

//Function that receives the date data.
void EntryDate(int *day, int *month, int *year)
	{
		printf("\nDate validity checker.\n");
		printf("Please enter the following requested data.\n");
		printf("Year   (%04d ->) : ", V_ONE);
		*year = GetEntry(year);
		printf("Month  (%02d - %02d) : ", V_ONE, V_TWELVE);
		*month = GetEntry(month);
		printf("Day    (%02d - %02d) : ", V_ONE, V_31);
		*day = GetEntry(day);
	}

//Function that receives the date data.
void EntryTime(int *hour, int *minute, int *second)
	{
		printf("\nTime validity checker.\n");
		printf("Please enter the following requested data.\n");
		printf("Hour   (%02d - %02d) : ", V_ZERO, V_23);
		*hour = GetEntry(hour);
		printf("Minute (%02d - %02d) : ", V_ZERO, V_59);
		*minute = GetEntry(minute);
		printf("Second (%02d - %02d) : ", V_ZERO, V_59);
		*second = GetEntry(second);
	}

//Validate a correct input from the keyboard.
int GetEntry(int *data_value)
	{
		//Preliminary working variables.
		int int_key = NULL_CHARACTER;
		int value_data = V_ZERO;

		//Validate data entry as correct.
		if (scanf("%d%*c", &value_data) == V_ONE)
			{
				//Get a correct integer value.
				printf("\nInput value: [%d]. OK!\n", value_data);
				*data_value = value_data;
			}
		else
			{
				//Get an incorrect integer value.
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
			}

		return value_data;
	}

//Function that obtains a response.
int GetResponse(const char *str_Message)
	{
		//Preliminary working variables.
		int int_key = NULL_CHARACTER;
		char chr_key = V_ZERO;

		printf("%s", str_Message);

		//Validate data entry as correct.
		if (scanf("%c%*c", &chr_key) == V_ONE)
				//Get a correct character value.
				printf("\nInput value: [%x] : [%d] = [%c]. OK!\n", chr_key, chr_key, chr_key);
		else
			{
				//Get an incorrect character value.
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
			};

		return int_key;
	}

//Function that obtains the current Julian Year and its remainder days.
int JulianYear(const int day, const int month, const int year, int *daysrest)
	{
		/* Preliminary working variables. */
		int clusterdays = V_ZERO;

		for (int int_month = V_ONE; int_month < month; int_month++)
			clusterdays += DaysInMonth(year, int_month);

		clusterdays += day;

		//Obtaining the remaining days of the year from the number of Julian days.
		*daysrest = (LeapYear(year) ? V_366 : V_365) - clusterdays;

		return clusterdays;
	}

//Function that obtains the current Julian year.
int LeapYear(const int year)
	{
		return (((year % V_FOUR == V_ZERO) && (year % V_100 != V_ZERO)) || (year % V_400 == V_ZERO));
	}

//Menu for processing calendar dates and times.
int Menu(int *start_day, int *start_month, int *start_year, int *day, int *month, int *year, int *hour, int *minute, int *second, int *option, int *counter)
	{
		/* Preliminary working variables. */
		enum enm_CalendarOptions enm_CO_myOption = (enum enm_CalendarOptions) *option;
		*counter = V_ZERO;

		/* Maintenance options. */
		while (enm_CO_myOption != enm_CO_exit_menu)
			{
				/* Display of menu options. */
				printf("\n");
				printf("+===+====+===+====+===+====+\n");
				printf("|   Calendar Menu Options. |\n");
				printf("+===+====+===+====+===+====+\n");
				printf("| [01]. Set start date.    |\n");
				printf("| [02]. Get number of days.|\n");
				printf("| [03]. Get day of week.   |\n");
				printf("| [04]. Get easter sunday. |\n");
				printf("| [05]. Capture a date.    |\n");
				printf("| [06]. Capture a time.    |\n");
				printf("| [07]. Dates Difference.  |\n");
				printf("| [08]. Obtain julian year.|\n");
				printf("| [09]. Check leap year.   |\n");
				printf("| [10]. Check sum of days. |\n");
				printf("| [11]. Validate date.     |\n");
				printf("| [12]. Validate time.     |\n");
				printf("| [13]. Write date.        |\n");
				printf("| [14]. Write time.        |\n");
				printf("| [15]. Exit this menu.    |\n");
				printf("+===+====+===+====+===+====+\n");
				printf("Option: ");

				/* Converting an integer to an enumerated type. */
				*option = GetEntry(option);
				enm_CO_myOption = (enum enm_CalendarOptions) *option;

				/* Execute the requested operation. */
				*option = SelectMenu(start_day, start_month, start_year, day, month, year, hour, minute, second, enm_CO_myOption, counter);
			}

		return *option;
	}

//Menu that executes the operation of a given selection.
int SelectMenu(int *start_day, int *start_month, int *start_year, int *day, int *month, int *year, int *hour, int *minute, int *second, enum enm_CalendarOptions enm_CO_myOption, int *counter)
	{
		/* Preliminary working variables. */
		int start_first_day = V_ZERO, start_first_month = V_ZERO, start_first_year = V_ZERO;
		int first_day = V_ZERO, first_month = V_ZERO, first_year = V_ZERO;
		int start_second_day = V_ZERO, start_second_month = V_ZERO, start_second_year = V_ZERO;
		int second_day = V_ZERO, second_month = V_ZERO, second_year = V_ZERO;
		int difference_between_dates = V_ZERO;
		int day_easter = V_ZERO, month_easter = V_ZERO;
		int day_of_week = V_ZERO, days_in_month = V_ZERO;
		int julian_year = V_ZERO, days_rest = V_ZERO;
		int julian_month = V_ZERO, julian_day = V_ZERO;
		int leap_year = V_ZERO;
		int sum_of_days = V_ZERO;
		int sum_year = V_ZERO, sum_month = V_ZERO, sum_day = V_ZERO;

		if (enm_CO_myOption != enm_CO_exit_menu) (*counter)++;	//Record successful transactions.

		switch(enm_CO_myOption)
			{
				case enm_CO_set_start_date:
					EntryDate(start_day, start_month, start_year);
					if (ValidDate(*start_day, *start_month, *start_year))
						{
							printf("\nValid date: [%04d-%02d-%02d]. OK!\n", *start_year, *start_month, *start_day);
						}
					else
						{
							printf("\nInvalid date!\n");
							*start_day = *start_month = *start_year = V_ONE;
						}
					break;

				case enm_CO_number_of_days:
					days_in_month = DaysInMonth(*year, *month);
					printf("\nTotal Days in Month.\n");
					printf("+ Year  : [%04d].\n", *year);
					printf("+ Month : [%02d].\n", *month);
					printf("+ Days  : [%d].\n", days_in_month);
					break;

				case enm_CO_day_of_week:
					day_of_week = DayOfWeek(*day, *month, *year);
					printf("\n[%s], [%04d-%02d-%02d].\n", day_name[day_of_week], *year, *month, *day);
					break;

				case enm_CO_get_easter_sunday:
					EasterSunday(*year, &month_easter, &day_easter);
					printf("\nEaster Sunday: {%d}.\n", *year);
					printf("- Month : {%d} = [%s].\n", month_easter, months_array[month_easter - V_ONE].month_nameofmonth);
					printf("- Day   : [%d].\n", day_easter);
					break;

				case enm_CO_capture_date:
					EntryDate(day, month, year);
					if (ValidDate(*day, *month, *year))
						{
							printf("\nValid date: [%04d-%02d-%02d]. OK!\n", *year, *month, *day);
						}
					else
						{
							printf("\nInvalid date!\n");
							*day = *month = *year = V_ONE;
						}
					break;

				case enm_CO_capture_time:
					EntryTime(hour, minute, second);
					if (ValidTime(*hour, *minute, *second))
						{
							printf("\nValid time: [%02d:%02d:%02d]. OK!\n", *hour, *minute, *second);
						}
					else
						{
							printf("\nInvalid time!\n");
							*hour = *minute = *second = V_ZERO;
						}
					break;

				case enm_CO_difference_between_dates:
					difference_between_dates = DifferenceBetweenDates(start_first_day, start_first_month, start_first_year, first_day, first_month, first_year, start_second_year, start_second_month, start_second_day, second_day, second_month, second_year);

					printf("\nDifference between dates: [%d].\n", difference_between_dates);
					break;

				case enm_CO_obtain_julian_year:
					julian_year = JulianYear(*day, *month, *year, &days_rest);
					printf("\nJulian Year Days.\n");
					printf("- Year  : {%d} : [%d].\n", *year, julian_year);
					printf("- Rest  : {%d} : [%d].\n", *year, days_rest);

					SolveJulianYear(*year, julian_year, &julian_month, &julian_day);
					printf("\nJulian Year converted.\n");
					printf("- Year  : {%d} : [%d].\n", *year, julian_year);
					printf("- Month : {%d} = [%s].\n", julian_month, months_array[julian_month - V_ONE].month_nameofmonth);
					printf("- Day   : [%d].\n", julian_day);
					break;

				case enm_CO_check_leap_year:
					leap_year = LeapYear(*year);
					printf("\nLeap Year: {%04d} = [%d].\n", *year, leap_year);
					break;

				case enm_CO_check_sum_of_days:
					printf("\nResolution of sum of days from a start date.\n");

					sum_of_days = SumOfDays(*start_day, *start_month, *start_year, *day, *month, *year);
					printf("Sum of days.\n");
					printf("- Begin : [%04d-%02d-%02d].\n", *start_year, *start_month, *start_day);
					printf("- End   : [%04d-%02d-%02d].\n", *year, *month, *day);
					printf("- Year  : {%d} : [%d].\n", *start_year, sum_of_days);

					SolveSumOfDays(*start_day, *start_month, *start_year, sum_of_days, &sum_day, &sum_month, &sum_year);
					printf("\nSolve sum of days.\n");
					printf("- Begin : [%04d-%02d-%02d].\n", *start_year, *start_month, *start_day);
					printf("- Year  : {%d} : [%d].\n", *start_year, sum_of_days);
					printf("+ End   : [%04d-%02d-%02d].\n", sum_year, sum_month, sum_day);
					break;

				case enm_CO_validate_date:
					if (ValidDate(*day, *month, *year))
						{
							printf("\nValid date: [%04d-%02d-%02d]. OK!\n", *year, *month, *day);
						}
					else
						{
							printf("\nInvalid date!\n");
							*day = *month = *year = V_ONE;
						}
					break;

				case enm_CO_validate_time:
					if (ValidTime(*hour, *minute, *second))
						{
							printf("\nValid time: [%02d:%02d:%02d]. OK!\n", *hour, *minute, *second);
						}
					else
						{
							printf("\nInvalid time!\n");
							*hour = *minute = *second = V_ZERO;
						}
					break;

				case enm_CO_write_date:
					WriteDate(*day, *month, *year);
					break;

				case enm_CO_write_time:
					WriteTime(*hour, *minute, *second);
					break;

				case enm_CO_exit_menu:
					printf("\nLeaving this menu...\n");
					break;

				default:
					printf("\nInvalid captured option: [%d]. Please correct it!\n", (int) enm_CO_myOption);
					break;
			}

		printf("\nOperations performed: [%d].\n", *counter);
		GetResponse("Press the ENTER key to continue...");

		return (int) enm_CO_myOption;
	}

//Function that converts the days in a year in Julian format to their corresponding month and day.
void SolveJulianYear(const int year, const int julianyeardays, int *julian_month, int *julian_day)
	{
		//Preliminary working variables.
		int days_remaining = julianyeardays, limitdays = (LeapYear(year) ? V_366 : V_365);

		//Validates if the number of days in Julian format is valid.
		if (julianyeardays >= V_ONE && julianyeardays <= limitdays)
			{
				for (*julian_month = V_ONE; days_remaining > DaysInMonth(year, *julian_month); (*julian_month)++)
					days_remaining -= DaysInMonth(year, *julian_month);

				*julian_day = days_remaining;
			}
		else
			printf("\nInvalid Julian Year days: {%d} : [%d]. Out of range: [%d] and [%d].\n", year, julianyeardays, V_ONE, limitdays);
	}

//Function that reconverts the number of days obtained into its variables of day, month and year.
void SolveSumOfDays(const int start_day, const int start_month, const int start_year, int sumofdays, int *day, int *month, int *year)
	{
		//Clear the component variables of 'sumofdays'.
		int daysrest = V_ZERO;
		JulianYear(start_day, start_month, start_year, &daysrest);
		int days_remaining = sumofdays - daysrest;
		*day = V_ONE;

		//We return the converted values ​​to the parameters of this function.
		for (*year = start_year + V_ONE; days_remaining >= (LeapYear(*year) ? V_366 : V_365); (*year)++)
			days_remaining -= (LeapYear(*year) ? V_366 : V_365);

		for (*month = V_ONE; days_remaining >= DaysInMonth(*year, *month); (*month)++)
			days_remaining -= DaysInMonth(*year, *month);

		*day += days_remaining;
	}

//Function that loops through the number of days in a year starting from '1582-01-01' for instance.
int SumOfDays(const int start_day, const int start_month, const int start_year, const int day, const int month, const int year)
	{
		//Preliminary working variables.
		int daysrest = V_ZERO;
		JulianYear(start_day, start_month, start_year, &daysrest);
		int cumofdays = daysrest - V_ONE;

		//Cycle of iterations to add days from a given year.
		for (int int_year = start_year + V_ONE; int_year <= year; int_year++)
			{
				int max_month = (int_year < year) ? V_TWELVE : month - V_ONE;

				for (int int_month = V_ONE; int_month <= max_month; int_month++)
					{
						int limitdays = DaysInMonth(int_year, int_month);

						cumofdays += limitdays;
					}
			}

                cumofdays += day;

		return cumofdays;
	}

//This function validates that a date is perfectly correct.
int ValidDate(const int day, const int month, const int year)
	{
		int limitdays = V_ZERO, yearB = V_ZERO, monthB = V_ZERO, dayB = V_ZERO;

		yearB = (year >= V_ONE);
		monthB = (month >= V_ONE && month <= V_TWELVE);
		dayB = (day >= V_ONE && day <= V_31);

		if (yearB)
			if (monthB)
				if (dayB)
					{
						limitdays = DaysInMonth(year, month);

						dayB = (day >= V_ONE && day <= limitdays);

						if (dayB)
							printf("\n** Correct date. **\n");
						else
							printf("\nInvalid day: [%d]. Out of range: [%d] and [%d] for month: [%d].\n", day, V_ONE, limitdays, month);
					}
				else
					printf("\nInvalid day: [%d]. Out of range: [%d] and [%d].\n", day, V_ONE, V_31);
			else
				printf("\nInvalid month: [%d]. Out of range: [%d] and [%d].\n", month, V_ONE, V_TWELVE);
		else
			printf("\nInvalid year: [%d]. Out of range: [>=%d].\n", year, V_ONE);

		if (!(dayB && monthB && yearB))
			{
				printf("\nData not valid for the date.\n");
				GetResponse("Press ENTER key to continue...");
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
					printf("\n** Correct time. **\n");
				else
					printf("\nInvalid second: [%d]. Out of range: [%d] and [%d].\n", second, V_ZERO, V_59);
			else
				printf("\nInvalid minute: [%d]. Out of range: [%d] and [%d].\n", minute, V_ZERO, V_59);
		else
			printf("\nInvalid hour: [%d]. Out of range: [%d] and [%d].\n", hour, V_ZERO, V_23);

		if (!(hourB && minuteB && secondB))
			{
				printf("\nData not valid for the time.\n");
				GetResponse("Press ENTER key to continue...");
			}

		return (hourB && minuteB && secondB);
	}

//Function that writes a correctly validated date.
void WriteDate(const int day, const int month, const int year)
	{
		int d = V_ZERO;

		d = DayOfWeek(day, month, year);

		printf("\nFormatted date.\n");
		printf("[%04d/%02d/%02d].\n", year, month, day);
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

		printf("\nFormatted time.\n");
		printf("[%02d:%02d:%02d].\n", s_hours, s_minutes, s_seconds);
		printf("Seconds Time: {%d}.\n", t);
	}
