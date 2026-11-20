/* This program converts a 2-byte (16-bit) short integer into a character string
   representing its binary form, and shifts each bit both to the left
   (equivalent to multiplication by powers of two '2')
   and to the right (equivalent to division by powers of two '2'). */

/* Standard Work Libraries. */
#include <limits.h>
#include <stdio.h>

/* Compile-time predefined macros for calculating the size of a given variable. */
#define	SIZE_BINARY(n)		(sizeof(n) * (V_EIGHT))
#define SIZE_BINARY_MAX(n)	((sizeof(n) * (V_EIGHT)) + (V_ONE))

/* Numeric Symbolic Constants. */
#define	CARRIAGE_RETURN		'\n'	//Value: 0xC == 13.
#define	NULL_CHARACTER		'\0'	//Value: 0x00 == 0.
#define	V_CHAR_DIGIT_ZERO	'\x30'	//Value: '0'.
#define	V_CHAR_DIGIT_ONE	'\x31'	//Value: '1'.

/* Program Startup Values. */
#define	V_0X0001		0x0001	//Value: +1.
#define	V_0X00FF		0x00FF	//Value: 255 == 2^8 - 1.
#define	V_0X8000		0x8000	//Value: 32768 == 2^15.
#define V_0XAAAA		0xAAAA	//Value: 43690.
#define	V_0XFFFF		0xFFFF	//Value: 65535 == 2^16 - 1.

/* Numeric Symbolic Constants. */
#define	V_EIGHT			8
#define V_ONE			1
#define	V_ZERO			0

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

/* Function Prototypes. */
char *binString(unsigned short number);
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK);

/* Ensure that unsigned short has exactly 16 value bits. */
_Static_assert(USHRT_MAX == V_0XFFFF, "This program requires a 16-bit unsigned short int.");

/* A function that converts a 16-bit short integer into a string of 'zeros' and 'ones'. */
char *binString(unsigned short number)
	{
		/* Preliminary Working Variables. */
		const size_t size_bin = SIZE_BINARY(number);	//Size in bits of the study variable.
		static char bin[SIZE_BINARY_MAX(number)];	//Character pointer with the binary number.

		/* Construction of the binary character string, character by character. */
		for (size_t idx = V_ZERO; idx < size_bin; idx++)
			{
				bin[idx] = number & V_0X8000 ? V_CHAR_DIGIT_ONE : V_CHAR_DIGIT_ZERO;
				number = (unsigned short) (number << V_ONE);
			}

		/* Terminate the string with the end-of-string character (null character). */
		bin[size_bin] = NULL_CHARACTER;

		/* Return the value of the string pointer created with binary digits. */
		return (bin);
	}

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

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		char chr_pause = NULL_CHARACTER;
		size_t counter = V_ZERO;
		unsigned short a = V_0XAAAA, b = V_0X00FF, c = V_ZERO;

		/* Initial Header Message. */
		printf("Example Exercise Involving Bit Swaps.\n");

		/* Bitwise operation using the 'AND' conjunction. */
		c = a & b;

		printf("\n\'AND\x27 Bitwise operation conjunction.\n");
		printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
		printf("+     &: [%5u] - {%04x} - <%s>.\n", b, b, binString(b));
		printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Bitwise operation using the 'OR' disjunction. */
		c = a | b;

		printf("\n\x27OR\x27 Bitwise operation disjunction.\n");
		printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
		printf("+     |: [%5u] - {%04x} - <%s>.\n", b, b, binString(b));
		printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Bitwise operation using the 'XOR' exclusive-disjunction. */
		c = a ^ b;

		printf("\n\x27XOR\x27 Bitwise operation exclusive-disjunction.\n");
		printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
		printf("+     ^: [%5u] - {%04x} - <%s>.\n", b, b, binString(b));
		printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Bit test with 'one's complement' with 'a' variable. */
		c = ~a;

		printf("\n\x22One\x27s Complement\x22 \'a\' Bitwise operation.\n");
		printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
		printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Bit test with 'one's complement' with 'b' variable. */
		c = ~b;

		printf("\n\x22One\x27s Complement\x22 \'b\' Bitwise operation.\n");
		printf("+ Start: [%5u] - {%04x} - <%s>.\n", b, b, binString(a));
		printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Bit shift to the left (leftward bit shift). Bit deployment with a leftward shift. */
		a = V_0X0001;	//Value: +1.
		counter = V_ZERO;
		printf("\nLeft bit shift (multiplication by powers of two \'2\').\n");

		/* Cycle for executing the left-shift (leftward) behavior. */
		for (size_t idx = V_ZERO; idx < SIZE_BINARY(a); idx++)
			{
				printf("# (%2lu) - [%5u] - {%04x} - <%s>.\n", counter++, (unsigned int) a, (unsigned int) a, binString(a));
				a = (unsigned short) (a << V_ONE);
			}
		printf("[%zu] Output results generated.\n", counter);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Bit shift to the right (rightward bit shift). Bit deployment with a rightward shift. */
		a = V_0X8000;	//Value: 32768 == 2¹⁵.
		counter = V_ZERO;
		printf("\nRight bit shift (division by powers of two \'2\').\n");

		/* Cycle for executing the right-shift (rightward) behavior. */
		for (size_t idx = V_ZERO; idx < SIZE_BINARY(a); idx++)
			{
				printf("# (%2lu) - [%5u] - {%04x} - <%s>.\n", counter++, (unsigned int) a, (unsigned int) a, binString(a));
				a >>= V_ONE;
			}
		printf("[%zu] Output results generated.\n", counter);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}
