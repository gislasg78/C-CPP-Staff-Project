/************* Generate a random number every second. ************
 ** Source Code:	Timer.c					**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
 ** Purpose:		The primary function of this program is	**
 **			to exploit different functions from the	**
 **			C library 'time.h' to simulate a timer	**
 **			that generates random numbers every so	**
 **			often and also displays various		**
 **			information about the date and time of	**
 **			the computer that is running the	**
 **			program.				**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Symbolic constants of minimum and maximum limits.
#define V_LOWER_LIMIT_SECS	1
#define V_UPPER_LIMIT_SECS	30

//Intermediate symbolic constants.
#define V_REFERENCE_YEAR	1900
#define V_RESIDUAL_MODULUS	65536

//Work Symbolic Constants.
#define V_ELEVEN		11
#define V_ONE			1
#define	V_TEN			10
#define	V_TWELVE		12
#define V_SEVEN			7
#define V_ZERO			0

/* Static array of characters with the names of the days of the week. */
static char sttc_chr_Day_Week[V_SEVEN][V_TEN] =
	{"Sunday", "Monday", "Tuesday" , "Wednesday", "Thursday", "Friday", "Saturday"};

/* Static array of characters with the names of the months of the year. */
static char sttc_chr_Month_Name[V_TWELVE][V_ELEVEN] =
	{"January", "February", "March" , "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this program, different functions	**
 **			from the 'time.h' C library are used,	**
 **			with the purpose of extracting various	**
 **			information about the date, time and	**
 **			pulses of the PC clock as part of the	**
 **			computer's timing.			**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		This program provides different		**
 **			information regarding time management	**
 **			on an IBM PC and compatible computers.	**
*****************************************************************/
int main()
	{
		/* Declaration of regular variables. */
		size_t szt_random_seed = V_ZERO;
		size_t szt_values_number = V_ZERO;

		/* Variable that contains the time spent by the processor. */
		clock_t clck_clock_ticks_latency = V_ZERO;
		clck_clock_ticks_latency = clock();

		/* The 'time' function returns the number of seconds since zero hours on January 1, 1970. */
		time_t t_tm_seconds = V_ZERO;
		time(&t_tm_seconds);

		/* ------------------------------------------------------------------------------------	--
		 * The 'localtime' function converts the number d" seconds elapsed since 0 hours on	--
		 * January 1, 1970, the value obtained by the time function, to the corresponding date	--
		 * and time (corrected based on the time zone in which we are located). The result is	--
		 * stored in a structure of type tm, defined in 'time.h'.				--
		 * ------------------------------------------------------------------------------------	--
		 * This function returns a pointer to the resulting character string or a null pointer	--
		 * if data before January 1, 1970 is represented.					--
		 * ------------------------------------------------------------------------------------	--
		 * The 'localtime' function returns a pointer to the structure containing the result,	--
		 * or a null pointer if the time cannot be interpreted.					--
		 * ------------------------------------------------------------------------------------	*/
		struct tm *strct_tm_dt = NULL;
		strct_tm_dt = localtime(&t_tm_seconds);

		/* Welcome messages from this program. */
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("|          PC Clock Cycles Program.          |\n");
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("Values between [%d] and [%d]: ", V_LOWER_LIMIT_SECS, V_UPPER_LIMIT_SECS);
		scanf("%ld", &szt_values_number);

		/* ------------------------------------------------------------------------------------	--
		 * The 'ctime' function converts a time stored as a value of type 'time_t' into a	--
		 * character string of the form.							--
		 * ------------------------------------------------------------------------------------	*/
		printf("\n%s", ctime(&t_tm_seconds));

		/* ------------------------------------------------------------------------------------	--
		 * The 'srand' function sets the starting point for generating pseudorandom numbers;	--
		 * In other words, it initializes the pseudorandom number generator based on the	--
		 * value of its argument.								--
		 * ------------------------------------------------------------------------------------	--
		 * When this function is not used, the value of the first generated pseudorandom	--
		 * number is always the same for each execution						--
		 * (corresponds to an argument of value 1).						--
		 * ------------------------------------------------------------------------------------ */
		szt_random_seed = (unsigned) (t_tm_seconds % V_RESIDUAL_MODULUS);
		srand(szt_random_seed);

		/* Verification that the value is in a given range. */
		if (szt_values_number >= V_LOWER_LIMIT_SECS && szt_values_number <= V_UPPER_LIMIT_SECS)
			{
				/* Display of date and time information. */
				printf("+===|====+===|====+===|====+===|===+====|====+\n");
				printf("|         Date and time information.         |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|       Seconds since January 1, 1970.       |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("| Value:\t[%ld].\n", t_tm_seconds);
				printf("| Address:\t[%p].\n", &t_tm_seconds);
				printf("+--------------------------------------------+\n");
				printf("| Latency:\t[%ld].\n", clck_clock_ticks_latency);
				printf("| Tickness:\t[%ld].\n", CLOCKS_PER_SEC);
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|         PC date and time structure.        |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("| Day of year:\t[%03d].\n", strct_tm_dt->tm_yday);
				printf("| Day of week:\t[%d].\n", strct_tm_dt->tm_wday);
				printf("+--------------------------------------------+\n");
				printf("| DD/MM/YYYY:\t[%02d/%02d/%04d].\n", strct_tm_dt->tm_mday, strct_tm_dt->tm_mon + V_ONE, strct_tm_dt->tm_year + V_REFERENCE_YEAR);
				printf("+--------------------------------------------+\n");
				printf("| [%s],\t[%s] [%02d], [%04d].\n", sttc_chr_Day_Week[strct_tm_dt->tm_wday], sttc_chr_Month_Name[strct_tm_dt->tm_mon], strct_tm_dt->tm_mday, strct_tm_dt->tm_year + V_REFERENCE_YEAR);
				printf("+--------------------------------------------+\n");
				printf("| HH:MM:SS:\t[%02d:%02d:%02d].\n", strct_tm_dt->tm_hour, strct_tm_dt->tm_min, strct_tm_dt->tm_sec);
				printf("+===|====+===|====+===|====+===|===+====|====+\n\n");

				/* --------------------------------------------------------------------	--
				 * Portion of the program that generates the sequence of random numbers	--
				 * each designated time interval.					--
				 * --------------------------------------------------------------------	--
				 * The 'clock' function indicates the time spent by the processor in	--
				 * the current process. This time, expressed in seconds, is the result	--
				 * of dividing the value returned by 'clock' by the constant		--
				 *'CLOCKS_PER_SEC'.							--
				 * --------------------------------------------------------------------	--
				 * If it is not possible to obtain this time, the 'clock' function	--
				 * returns the value (clock_t) - 1.					--
				 * --------------------------------------------------------------------	*/
				printf("Generating sequences of random numbers...\n");
				for (size_t szt_iter = V_ZERO; szt_iter < szt_values_number; szt_iter++)
					{
						/* Waiting time in clock cycles equal to one second. */
						do
							clck_clock_ticks_latency = clock() / CLOCKS_PER_SEC;
						while (clck_clock_ticks_latency < szt_iter);

						/* A value is generated every second. */
						printf ("# [%ld]:\t[%d].\n", szt_iter, rand());
					}

				/* --------------------------------------------------------------------	--
				 * The 'rand' function outputs an integer pseudorandom number between	--
				 * zero and the maximum value for an int.				--
				 * --------------------------------------------------------------------	*/
				printf("[%ld] Output generated results.\n", szt_values_number);
			}
		else
			printf("Mistake! Value [%ld] is not between [%d] and [%d].\n", szt_values_number, V_LOWER_LIMIT_SECS, V_UPPER_LIMIT_SECS);

		return V_ZERO;
	}
