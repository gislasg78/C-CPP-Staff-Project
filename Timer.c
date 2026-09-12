/************* Generate a random number every second. ************
 ** Source Code:	Timer.c					**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, December 31, 2026.		**
 ** Purpose:		The primary function of this program is	**
 **			to exploit different functions from the	**
 **			C library 'time.h' to simulate a timer	**
 **			that generates random numbers every so	**
 **			often and also displays various		**
 **			information about the date and time of	**
 **			the computer that is running the	**
 **			program.				**
*****************************************************************/
/* C Standard Libraries. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Symbolic constants of minimum and maximum limits. */
#define V_LOWER_LIMIT_SECS		1
#define V_UPPER_LIMIT_SECS		30

/* Intermediate symbolic constants. */
#define V_REFERENCE_YEAR		1900
#define GENERATE_RANDOM(v, minV, maxV)	(((v) % ((maxV) - (minV) + (V_ONE))) + (minV))

/* Work Symbolic Constants. */
#define V_ELEVEN			11
#define V_ONE				1
#define V_SEVEN				7
#define	V_TEN				10
#define	V_TWELVE			12
#define V_ZERO				0

/* Static array of characters with the names of the days of the week. */
char chr_Day_Week[V_SEVEN][V_TEN] =
	{"Sunday", "Monday", "Tuesday" , "Wednesday", "Thursday", "Friday", "Saturday"};

/* Static array of characters with the names of the months of the year. */
char chr_Month_Name[V_TWELVE][V_ELEVEN] =
	{"January", "February", "March" , "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/*****************************************************************
 ** Function:		size_t displayRandom			**
 **			(const size_t szt_random_seed,		**
 **			 const size_t szt_quantity_numbers,	**
 **			 const size_t szt_minValue,		**
 **			 const size_t szt_maxValue).		**
 ** Explanation:	The 'srand' function sets the starting	**
 **			point for generating pseudorandom	**
 **			numbers;				**
 **			in other words, it initializes the	**
 **			pseudorandom number generator based on	**
 **			the value of its argument.		**
 **								**
 **			When this function is not used, the	**
 **			value of the first generated		**
 **			pseudorandom number is always the same	**
 **			for each execution			**
 **			(corresponds to an argument of value 1).**
 ** Input Parms:	const size_t szt_random_seed.		**
 **			const size_t szt_quantity_numbers.	**
 **			const size_t szt_minValue.		**
 **			const size_t szt_maxValue.		**
 ** Output Parms:	None.					**
 ** Result:		Portion of the program that generates	**
 **			the sequence of random numbers each	**
 **			designated time interval.		**
 **								**
 **			The 'clock' function indicates the time	**
 **			spent by the processor in		**
 **			the current process.			**
 **			This time, expressed in seconds,	**
 **			is the result of dividing the value	**
 **			returned by 'clock' by the constant	**
 **			'CLOCKS_PER_SEC'.			**
 **								**
 **			If it is not possible to obtain this	**
 **			time, the 'clock' function returns the	**
 **			value (clock_t) - 1.			**
 **								**
 **			The 'rand' function outputs an integer	**
 **			pseudorandom number between zero and	**
 **			the maximum value for an int.		**
*****************************************************************/
size_t displayRandom(const size_t szt_random_seed, const size_t szt_quantity_numbers, const size_t szt_minValue, const size_t szt_maxValue)
	{
		/* Preliminary working variables. */
		size_t szt_counter = V_ZERO;

		/* Variable that contains the time spent by the processor. */
		clock_t clck_clock_ticks_latency = clock();

		/* Constantly change the random number generation seed. */
		srand((unsigned int) szt_random_seed);

		/* Random number generator. */
		printf("\nGenerating sequences of random numbers...\n");
		for (size_t szt_iter = V_ZERO; szt_iter < szt_quantity_numbers; szt_iter++)
			{
				/* Manually count each generated random number. */
				szt_counter++;

				/* Waiting time in clock cycles equal to one second. */
				do
					clck_clock_ticks_latency = clock() / CLOCKS_PER_SEC;
				while (clck_clock_ticks_latency < (long int)(szt_iter));

				/* A value is generated every second. */
				printf ("# [%ld]:\t[%ld].\n", szt_iter, GENERATE_RANDOM((size_t)rand(), szt_minValue, szt_maxValue));
			}

		/* Output results generated. */
		printf("[%ld] Output generated results.\n", szt_quantity_numbers);

		/* Return the number of random numbers generated. */
		return szt_counter;
	}

/*****************************************************************
 ** Function:		long int showTimePanel().		**
 ** Explanation:	The 'localtime' function converts the	**
 **			number d" seconds elapsed since 0 hours	**
 **			on January 1, 1970, the value obtained	**
 **			by the time function, to the		**
 **			corresponding date and time		**
 **			(corrected based on the time zone in	**
 **			which we are located).			**
 **								**
 **			The result is stored in a structure of	**
 **			type 'tm', defined in 'time.h'.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		This function returns a pointer to the	**
 **			resulting character string or a null	**
 **			pointer if data before January 1, 1970	**
 **			is represented.				**
 **								**
 **			The 'ctime' function converts a time	**
 **			stored as a value of type 'time_t' into	**
 **			a character string of the form.		**
 **								**
 **			The 'localtime' function returns a	**
 **			pointer to the structure containing the	**
 **			result, or a null pointer if the time	**
 **			cannot be interpreted.			**
*****************************************************************/
long int showTimePanel()
	{
		/* Variable that contains the time spent by the processor. */
		clock_t clck_clock_ticks_latency = clock();

		/* The 'time' function returns the number of seconds since zero hours on January 1, 1970. */
		time_t t_elapsed_seconds = time(&t_elapsed_seconds);

		/*The 'tm' type structure is obtained, which stores all the details since January 1, 1970. */
		struct tm *ptr_strct_tm_dt = localtime(&t_elapsed_seconds);

		/* 'ctime' displays the current date and time in a character string format. */
		printf("%s", ctime(&t_elapsed_seconds));

		/* Display of date and time information. */
		printf("+===|====+===|====+===|====+===|===+====|\n");
		printf("|       Date and time information.      |\n");
		printf("+===|====+===|====+===|====+===|===+====|\n");
		printf("| File:\t\t[%s].\n", __FILE__);
		printf("| Line:\t\t[%d].\n", __LINE__);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| Date:\t\t[%s].\n", __DATE__);
		printf("| Time:\t\t[%s].\n", __TIME__);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|    Seconds since January 1th, 1970.   |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Address:\t[%p].\n", (void *) &t_elapsed_seconds);
		printf("| Value:\t[%ld].\n", t_elapsed_seconds);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| Address:\t[%p].\n", (void *) &clck_clock_ticks_latency);
		printf("| Latency:\t[%ld].\n", clck_clock_ticks_latency);
		printf("| Tickness:\t[%ld].\n", CLOCKS_PER_SEC);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|      PC date and time structure.      |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Address:\t[%p].\n", (void *) ptr_strct_tm_dt);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| Year day:\t[%03d].\n", ptr_strct_tm_dt->tm_yday);
		printf("| Week day:\t[%d].\n", ptr_strct_tm_dt->tm_wday);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| YYYY/MM/DD:\t(%04d/%02d/%02d).\n", ptr_strct_tm_dt->tm_year + V_REFERENCE_YEAR, ptr_strct_tm_dt->tm_mon + V_ONE, ptr_strct_tm_dt->tm_mday);
		printf("| DD/MM/YYYY:\t[%02d/%02d/%04d].\n", ptr_strct_tm_dt->tm_mday, ptr_strct_tm_dt->tm_mon + V_ONE, ptr_strct_tm_dt->tm_year + V_REFERENCE_YEAR);
		printf("| MM/DD/YYYY:\t{%02d/%02d/%04d}.\n", ptr_strct_tm_dt->tm_mon + V_ONE, ptr_strct_tm_dt->tm_mday, ptr_strct_tm_dt->tm_year + V_REFERENCE_YEAR);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| %s,\t%s %02d, %04d.\n", chr_Day_Week[ptr_strct_tm_dt->tm_wday], chr_Month_Name[ptr_strct_tm_dt->tm_mon], ptr_strct_tm_dt->tm_mday, ptr_strct_tm_dt->tm_year + V_REFERENCE_YEAR);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| HH:MM:SS:\t[%02d:%02d:%02d].\n", ptr_strct_tm_dt->tm_hour, ptr_strct_tm_dt->tm_min, ptr_strct_tm_dt->tm_sec);
		printf("+===|====+===|====+===|====+===|===+====|\n\n");

		/* Return the number of seconds from January 1th, 1970, to the present moment. */
		return t_elapsed_seconds;
	}

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
		size_t szt_counter = V_ZERO;
		size_t szt_maxValue = V_ZERO;
		size_t szt_minValue = V_ZERO;
		size_t szt_quantity_numbers = V_ZERO;
		size_t szt_random_seed = V_ZERO;

		/* Call the function that displays the current date and time panel. */
		szt_random_seed = (size_t) showTimePanel();

		/* Welcome messages from this program. */
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|        PC Clock Cycles Program.       |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("Quantity values [%d] - [%d]: ", V_LOWER_LIMIT_SECS, V_UPPER_LIMIT_SECS);
		scanf("%zu", &szt_quantity_numbers);

		/* Verification that the value is in a given range. */
		if (szt_quantity_numbers >= V_LOWER_LIMIT_SECS && szt_quantity_numbers <= V_UPPER_LIMIT_SECS)
			{
				/* Request minimum and maximum values. */
				printf("Minimum value: ");
				scanf("%zu", &szt_minValue);
				printf("Maximum value: ");
				scanf("%zu", &szt_maxValue);

				/* Verify that the values ​​range are positive and not zero. */
				if (szt_minValue && szt_maxValue)
					{
						/* Swap minimum and maximum values ​​if they are inverted. */
						if (szt_minValue > szt_maxValue || szt_maxValue < szt_minValue)
							{
								printf("\nSwapping minimum and maximum values...\n");
								size_t szt_tempValue = szt_minValue;
								szt_minValue = szt_maxValue;
								szt_maxValue = szt_tempValue;
							}

						/* Display the generated numbers at intervals of approximately one second. */
						szt_counter = displayRandom(szt_random_seed, szt_quantity_numbers, szt_minValue, szt_maxValue);
						printf("\n[%ld] Random numbers generated.\n", szt_counter);
					}
				else
					printf("\nFail! Values: [%ld] and: [%ld] must be non-zero.\n", szt_minValue, szt_maxValue);
			}
		else
			printf("\nMistake! Value: [%ld] is not between: [%d] and: [%d].\n", szt_quantity_numbers, V_LOWER_LIMIT_SECS, V_UPPER_LIMIT_SECS);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
