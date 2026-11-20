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
#include <string.h>
#include <time.h>

/* Intermediate symbolic constants. */
#define GENERATE_RANDOM(v, minV, maxV)	(((v) % ((maxV) - (minV) + (V_ONE))) + (minV))
#define V_REFERENCE_YEAR		1900

/* Symbolic work constants.*/
#define	CARRIAGE_RETURN			'\n'
#define	NULL_CHARACTER			'\0'

/* Symbolic constants of minimum and maximum limits. */
#define V_LOWER_LIMIT_SECS		1
#define V_UPPER_LIMIT_SECS		45

/* Work Symbolic Constants. */
#define V_ELEVEN			11
#define V_ONE				1
#define V_SEVEN				7
#define	V_TEN				10
#define	V_TWELVE			12
#define V_ZERO				0

/* Static array of characters with the names of the days of the week. */
const char chr_Day_Name[V_SEVEN][V_TEN] =
	{"Sunday", "Monday", "Tuesday" , "Wednesday", "Thursday", "Friday", "Saturday"};

/* Static array of characters with the names of the months of the year. */
const char chr_Month_Name[V_TWELVE][V_ELEVEN] =
	{"January", "February", "March" , "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/* Enumeration with type entry variables and its reseting. */
enum enm_type_entry
	{
		enm_type_entry_char,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short,
		enm_type_entry_sizet
	};

/* Enumeration for memory area reset system. */
enum enm_type_reset
	{
		enm_type_reset_NO,
		enm_type_reset_YES
	};

/* Preliminary function prototypes. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK);
size_t displayRandom(const size_t szt_random_seed, const size_t szt_quantity_numbers, const size_t szt_minValue, const size_t szt_maxValue);
long int showTimePanel(long* const tm_elapsed_seconds);

/* Function that gets a correct type value depending on its option. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK)
	{
		/* Preliminary working variables. */
		static char chr_storage = NULL_CHARACTER;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Convert the specified enumerated type to an 'integer'. */
		int option_type_entry = (int) enm_type_data;

		/* Validate if the obtained memory addresses are valid. */
		if (void_var_address)
			{
				/* Initialize the specified memory area. */
				if (enm_type_reset_OK == enm_type_reset_YES)
					{
						switch(enm_type_data)
							{
								case enm_type_entry_char:
									*((char *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_double:
									*((double *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_float:
									*((float *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_int:
									*((int *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_long:
									*((long *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_short:
									*((short *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_sizet:
									*((size_t *) void_var_address) = V_ZERO;
									break;

								default:
									fputs("\nUnrecognized Option!\n", stderr);
									fprintf(stderr, "The selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
									break;
							}
					}

				/* Incoming message. */
				printf("%s", str_Message);

				/* Selection of validating case of the type of variable to generate. */
				switch(enm_type_data)
					{
						/* Get a correct character value. */
						case enm_type_entry_char:
							if ((int_fields = scanf("%c%*c%n", (char *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, *((char *) void_var_address), *((char *) void_var_address), *((char *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point double precision value. */
						case enm_type_entry_double:
							if ((int_fields = scanf("%lf%*c%n", (double *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%lf]. Characters: [%d]. OK!\n", int_fields, *((double *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point single precision value. */
						case enm_type_entry_float:
							if ((int_fields = scanf("%f%*c%n", (float *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%f]. Characters: [%d]. OK!\n", int_fields, (double) *((float *) void_var_address), int_chars);
							break;

						/* Get a correct integer value. */
						case enm_type_entry_int:
							if ((int_fields = scanf("%d%*c%n", (int *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%d]. Characters: [%d]. OK!\n", int_fields, *((int *) void_var_address), int_chars);
							break;

						/* Get a correct long int value. */
						case enm_type_entry_long:
							if ((int_fields = scanf("%ld%*c%n", (long *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%ld]. Characters: [%d]. OK!\n", int_fields, *((long *) void_var_address), int_chars);
							break;

						/* Get a correct short int value. */
						case enm_type_entry_short:
							if ((int_fields = scanf("%hi%*c%n", (short *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%hi]. Characters: [%d]. OK!\n", int_fields, *((short *) void_var_address), int_chars);
							break;

						/* Get a correct unsigned long int value. */
						case enm_type_entry_sizet:
							if ((int_fields = scanf("%zu%*c%n", (size_t *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%zu]. Characters: [%d]. OK!\n", int_fields, *((size_t *) void_var_address), int_chars);
							break;

						/* It is specified that if the option is incorrect, an error message should be sent. */
						default:
							fputs("\nUnrecognized Option!\n", stderr);
							fprintf(stderr, "The selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
							break;
					}

				/* Verify that exactly one field is captured and saved at the given address. */
				if ((int_fields != V_ONE) || !(int_chars))
					{
						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* Get an incorrect entried value. */
						fputs("\nThe value entered is not valid!\n", stderr);
						fprintf(stderr, "Press ENTER to continue...");

						/* Proceed to clear all characters present in the buffer. */
						int_chars = V_ZERO;
						int_fields = scanf("%*[^\n]%*c%n", &int_chars);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* We must always clear the input buffer of impurities. */
						fputs("\nPress the ENTER key to clear the input buffer...", stderr);
						while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}
					}
			}
		else
			{
				fputs("\nUnrecognized Memory Address!\n", stderr);
				fprintf(stderr, "The memory address: [%p] to hold the variable is not valid!\n", void_var_address);
			}

		/* Return of void pointer key value. */
		return (void_var_address) ? void_var_address : &chr_storage;
	}

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
		printf("\nGenerating sequences of random numbers.\n");
		printf("+ Minimum value:\t[%zu].\n", szt_minValue);
		printf("+ Maximum value:\t[%zu].\n", szt_maxValue);
		printf("+ Quantity numbers:\t[%zu].\n", szt_quantity_numbers);
		printf("+ Random seed:\t\t[%zu].\n", szt_random_seed);

		/* Generate a random number for every second that elapses. */
		printf("\nProgressive random numbers.\n");

		/* Generate a random number for every second that elapses. */
		for (size_t szt_iter = V_ZERO; szt_iter < szt_quantity_numbers; szt_iter++)
			{
				/* Manually count each generated random number. */
				szt_counter++;

				/* Waiting time in clock cycles equal to one second. */
				do
					clck_clock_ticks_latency = clock() / CLOCKS_PER_SEC;
				while(clck_clock_ticks_latency < (long int)(szt_iter));

				/* A value random is generated every second. */
				int int_random_value = rand();	//Generate a random number for every second that elapses.
				size_t szt_random_value = (size_t) GENERATE_RANDOM((size_t) int_random_value, szt_minValue, szt_maxValue);
				printf("# (%2zu)\t:\t[%d]\t:\t{%zu}.\n", szt_iter, int_random_value, szt_random_value);
			}

		/* Output results generated. */
		printf("[%zu] Output generated results.\n", szt_quantity_numbers);

		/* Return the number of random numbers generated. */
		return szt_counter;
	}

/*****************************************************************
 ** Function:		long int showTimePanel			**
 **				(long * const			**
 **					tm_elapsed_seconds).	**
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
 ** Input Parms:	long * const tm_elapsed_seconds.	**
 ** Output Parms:	long * const tm_elapsed_seconds.	**
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
long int showTimePanel(long* const tm_elapsed_seconds)
	{
		/* Preliminary Working Variables. */
		char chr_pause = NULL_CHARACTER;

		/* Variable that contains the time spent by the processor. */
		clock_t clck_clock_ticks_latency = clock();
		double dbl_factor_ticks_latency = (double) ((double) clck_clock_ticks_latency / (double) CLOCKS_PER_SEC);

		/* The 'time' function returns the number of seconds since zero hours on January 1, 1970. */
		time_t t_elapsed_seconds = time(&t_elapsed_seconds);

		/*The 'tm' type structure is obtained, which stores all the details since January 1, 1970. */
		struct tm *ptr_strct_tm_dt = localtime(&t_elapsed_seconds);

		/* 'ctime' displays the current date and time in a character string format. */
		printf("%c%s", CARRIAGE_RETURN, ctime(&t_elapsed_seconds));

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
		printf("+--------+--------+--------+-------+----+\n");
		printf("| Factor:\t[%lf].\n", dbl_factor_ticks_latency);
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
		printf("| %s,\t%s %02d, %04d.\n", chr_Day_Name[ptr_strct_tm_dt->tm_wday], chr_Month_Name[ptr_strct_tm_dt->tm_mon], ptr_strct_tm_dt->tm_mday, ptr_strct_tm_dt->tm_year + V_REFERENCE_YEAR);
		printf("+--------+--------+--------+-------+----+\n");
		printf("| HH:MM:SS:\t[%02d:%02d:%02d].\n", ptr_strct_tm_dt->tm_hour, ptr_strct_tm_dt->tm_min, ptr_strct_tm_dt->tm_sec);
		printf("+===|====+===|====+===|====+===|===+====|\n");

		/* Introduce and enforce a mandatory pause. */
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Return the number of seconds from January 1th, 1970, to the present moment. */
		return (tm_elapsed_seconds) ? *tm_elapsed_seconds = t_elapsed_seconds : t_elapsed_seconds;
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
		char chr_key = NULL_CHARACTER;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;

		/* Data entry format message. */
		static char str_Message[BUFSIZ] = {NULL_CHARACTER};	//Intentional redundant initial initialization.
		memset(str_Message, V_ZERO, sizeof(str_Message));

		/* Generate the automatic entry request sequence. */
		if ((int_fields = snprintf(str_Message, sizeof(str_Message), "Number of values ​​to generate from: [%d] to: [%d] : %n", V_LOWER_LIMIT_SECS, V_UPPER_LIMIT_SECS, &int_chars)))
			{
				/* Preliminary accounting variables. */
				size_t szt_counter = V_ZERO;
				size_t szt_maxValue = V_ZERO;
				size_t szt_minValue = V_ZERO;
				size_t szt_quantity_numbers = V_ZERO;
				size_t szt_random_seed = V_ZERO;

				/* Confirmation that the formatting string has been successfully created. */
				printf("Information on the formatted character string.\n");
				printf("+ Chars:\t[%d].\n", int_chars);
				printf("+ Fields:\t[%d].\n", int_fields);
				printf("+ String:\t{%s}.\n", str_Message);
				chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

				/* Call the function that displays the current date and time panel. */
				szt_random_seed = (size_t) showTimePanel((long *) &szt_random_seed);

				/* Welcome messages from this program. */
				printf("%c", CARRIAGE_RETURN);
				printf("+===|====+===|====+===|====+===|====+===|\n");
				printf("|        PC Clock Cycles Program.       |\n");
				printf("+===|====+===|====+===|====+===|====+===|\n");
				szt_quantity_numbers = *((size_t *) GetEntry(str_Message, &szt_quantity_numbers, enm_type_entry_sizet, enm_type_reset_YES));

				/* Verification that the value is in a given range. */
				if (szt_quantity_numbers >= V_LOWER_LIMIT_SECS && szt_quantity_numbers <= V_UPPER_LIMIT_SECS)
					{
						/* Request minimum and maximum values. */
						szt_minValue = *((size_t *) GetEntry("Minimum value: ", &szt_minValue, enm_type_entry_sizet, enm_type_reset_YES));
						szt_maxValue = *((size_t *) GetEntry("Maximum value: ", &szt_maxValue, enm_type_entry_sizet, enm_type_reset_YES));

						/* Verify that the values ​​range are positive and not zero. */
						if (szt_minValue && szt_maxValue)
							{
								/* Swap minimum and maximum values ​​if they are inverted. */
								if (szt_minValue > szt_maxValue || szt_maxValue < szt_minValue)
									{
										printf("\nSwapping minimum and maximum values...\n");

										/* Swapping of values ​​between the 'minimum' and 'maximum' variables. */
										size_t szt_tempValue = szt_minValue;
										szt_minValue = szt_maxValue;
										szt_maxValue = szt_tempValue;

										/* Messages with the values ​​swapped. */
										printf("\nExchanged values.\n");
										printf("+ Maximum:\t[%zu].\n", szt_maxValue);
										printf("+ Minimum:\t[%zu].\n", szt_minValue);
									}

								/* Display the generated numbers at intervals of approximately one second. */
								szt_counter = displayRandom(szt_random_seed, szt_quantity_numbers, szt_minValue, szt_maxValue);
								printf("\n[%zu] Random numbers generated.\n", szt_counter);
								chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));
							}
						else
							{
								fputs("\n\'Minimum\' and \'maximum\' variables with unrecognized values.\n", stderr);
								fprintf(stderr, "Fail! Values: [%zu] and: [%zu] must be non-zero.\n", szt_minValue, szt_maxValue);
							}
					}
				else
					{
						fputs("\nIncorrect number of values ​​to generate!\n", stderr);
						fprintf(stderr, "Mistake! Value: [%zu] is not between: [%d] and: [%d].\n", szt_quantity_numbers, V_LOWER_LIMIT_SECS, V_UPPER_LIMIT_SECS);
					}
			}
		else
			{
				fputs("\nError generating the format string!\n", stderr);
				fprintf(stderr, "The formatting string could not be successfully created!\n");
			}


		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}
