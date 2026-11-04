/* Program that copies one file to another with sequential access. */

/* Standard Work Libraries. */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN			'\n'
#define NULL_CHARACTER			'\0'

/* File opening modes. */
#define	_FILE_MODE_READ_UPDATE_		"\x72\x2b"
#define	_FILE_MODE_WRITE_UPDATE_	"\x77\x2b"

/* Symbolic work constants. */
#define V_ONE				1
#define	V_ZERO				0

/* Enumeration with type entry variables and its reseting. */
enum enm_type_entry
	{
		enm_type_entry_char,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short,
		enm_type_entry_sizet,
	};

/* Enumeration for memory area reset system. */
enum enm_type_reset
	{
		enm_type_reset_NO,
		enm_type_reset_YES
	};

/* General global variable. */
int key = V_ZERO;

/* Prototypes of the functions of this program. */
int CheckErrorFile(const char *const strFile, FILE *pFile);
size_t CopyFile(const char *const str_SourceFile, const char *const str_TargetFile, const size_t numRecords);
size_t CreateFile(const char *const str_File);
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK);
char *GetFileName(const char *const str_Message, void *const void_var_address, const size_t size_of_var_address);
size_t DumpFile(const char *const str_File, const size_t numRecords);

/* Main function */
int main()
	{
		/* Preliminary working variables. */
		char chr_key = NULL_CHARACTER;
		char *source_file = NULL;
		char *target_file = NULL;
		size_t numRecords = V_ZERO;

		/* Verify that the assigned pointers have been validly created. */
		if ((source_file = (char *) calloc(BUFSIZ, sizeof(char))))
			{
				if ((target_file = (char *) calloc(BUFSIZ, sizeof(char))))
					{
						/* Data entry */
						printf("File Copy.\n");
						source_file = GetFileName("\n> Source file : ", source_file, BUFSIZ);
						target_file = GetFileName("\n> Target file : ", target_file, BUFSIZ);

						/* Calls to special functions. */
						numRecords = CreateFile(source_file);
						chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

						numRecords = DumpFile(source_file, numRecords);
						chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

						numRecords = CopyFile(source_file, target_file, numRecords);
						chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

						numRecords = DumpFile(target_file, numRecords);
						chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

						/* Freeing memory file pointers. */
						puts("\nFreeing allocated memory...");
						free(source_file);
						source_file = NULL;

						free(target_file);
						target_file = NULL;

						chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));
					}
				else
					fprintf(stderr, "\nNo memory available to store the output filename!\n");
			}
		else
			fprintf(stderr, "\nNo memory available to store the input filename!\n");

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}

/* A function that returns whether an end-of-file or an error occurred for a file pointer. */
int CheckErrorFile(const char *const strFile, FILE *pFile)
	{
		if (strFile)
			{
				if (pFile)
					{
						/* Display messages regarding the type of error that occurred in the file. */
						if (ferror(pFile))
							{
								printf("\n");
								printf("+---+----+---+----+---+\n");
								printf("| I/O Error detection |\n");
								printf("+---+----+---+----+---+\n");
								printf("| - File:\t\t[%s].\n", strFile);
								printf("| - Address:\t[%p].\n", (void *) pFile);
								printf("| - Error number:\t[%d].\n", errno);
								printf("| - Description:\t[%s].\n", strerror(errno));
								printf("+---+----+---+----+---+\n");

								perror("\nBad error in the file. It fucked up!\n->");
								printf("\n");
							}

						/* Display the result of the End-of-File (EOF) indicator for a given file. */
						if (feof(pFile))
							printf("End of file: [%s] in address: [%p] reached.\n", strFile, (void *) pFile);
					}
				else
					fputs("\nFatal error! No file is open, the file is closed, or its memory address is invalid!\n", stderr);
			}
		else
			fputs("\nThe file name was not assigned or is invalid!\n", stderr);

		/* Return the critical result of the file error check. */
		return (strFile && pFile) ? (ferror(pFile) || feof(pFile)) : V_ZERO;
	}

/* Copies records identically from one file to another, record by record. */
size_t CopyFile(const char *const strSource, const char *const strTarget, const size_t numRecords)
	{
		/* Preliminary Working Variables. */
		FILE *pFSource = NULL, *pFTarget = NULL;

		/* Preliminary auxiliary variables. */
		size_t counter = V_ZERO;
		int int_fields = V_ZERO;
		int inBytes = V_ZERO, inKey = V_ZERO, outBytes = V_ZERO, outKey = V_ZERO;

		/* Initial presentation headers. */
		printf("\nCopy Files.\n");
		printf("- Source file: [%s]. Open mode: [%s].\n", strSource, _FILE_MODE_READ_UPDATE_);
		printf("- Target file: [%s]. Open mode: [%s].\n", strTarget, _FILE_MODE_WRITE_UPDATE_);

		/* Opening and validation of source and destination files. */
		if ((pFTarget = fopen(strTarget, _FILE_MODE_WRITE_UPDATE_)))
			{
				if ((pFSource = fopen(strSource, _FILE_MODE_READ_UPDATE_)))
					{
						printf("File: [%s] with number: [%d] is copied to file: [%s] with number: [%d].\n", strSource, fileno(pFSource), strTarget, fileno(pFTarget));

						while ((!feof(pFSource) && !ferror(pFSource))
						    && (!feof(pFTarget) && !ferror(pFTarget))
						    && (counter < numRecords))
							{
								if ((int_fields = fscanf(pFSource, "%*c%d%*c%*c%n", &inKey, &inBytes)) && !feof(pFSource) && !ferror(pFSource) && (counter < numRecords))
									{
										if ((int_fields = fprintf(pFTarget, "{%d}.%n\n", outKey = inKey, &outBytes)))
											printf("#: [%lu]\t:\t(%d)\t=\t{%d}.\t<%d>\t=\t<%d>.\n", counter++, inKey, outKey, inBytes, outBytes);
									}
							}

						CheckErrorFile(strSource, pFSource);
						CheckErrorFile(strTarget, pFTarget);

						printf("\nSize of the source and destination copy files.\n");
						fseek(pFSource, V_ZERO, SEEK_END);
						printf("File size: [%s] with: [%ld] bytes.\n", strSource, ftell(pFSource));
						fseek(pFTarget, V_ZERO, SEEK_END);
						printf("File size: [%s] with: [%ld] bytes.\n", strTarget, ftell(pFTarget));
						printf("File: [%s] was written with: [%lu] records out of a total of: [%lu].\n", strTarget, counter, numRecords);
						printf("File: [%s] closed!\n", strSource);
						fclose(pFSource);
					}
				else
					CheckErrorFile(strSource, pFSource);

				printf("File: [%s] closed!\n", strTarget);
				fclose(pFTarget);
			}
		else
			CheckErrorFile(strTarget, pFTarget);

		/* Return the number of copied records. */
		return counter;
	}

/* This function creates and captures a specific file. */
size_t CreateFile(const char *const strFile)
	{
		/* Preliminary Working Variables. */
		FILE *pFile = NULL;

		/* Preliminary auxiliary variables. */
		size_t counter = V_ZERO;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;

		/* Initial presentation headers. */
		printf("\nCreate file.\n");
		printf("Loading File: [%s]. Opening mode: [%s].\n", strFile, _FILE_MODE_WRITE_UPDATE_);

		/* Validate the creation of the source file. */
		if ((strFile) && (pFile = fopen(strFile, _FILE_MODE_WRITE_UPDATE_)))
			{
				printf("Capturing file...\n");
				printf("File number: [%d].\n", fileno(pFile));

				while (!feof(pFile) && !ferror(pFile))
					{
						if (!(key = *((int *) GetEntry("Code: ", &key, enm_type_entry_int, enm_type_reset_YES))))
							break;

						if ((int_fields = fprintf(pFile, "(%d).\n%n", key, &int_chars)))
							printf("#: [%lu]\t:\t[%d].\t<%d>.\n", counter++, key, int_chars);
					}

				CheckErrorFile(strFile, pFile);

				printf("\nSize of the created file.\n");
				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));
				printf("File saved: [%s] with: [%lu] records.\n", strFile, counter);

				printf("File: [%s] closed!\n", strFile);
				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		/* Return the exact number of saved or stored records. */
		return counter;
	}

/* This function displays the contents of a created file, record by record. */
size_t DumpFile(const char *const strFile, const size_t numRecords)
	{
		/* Preliminary Working Variables. */
		FILE *pFile = NULL;

		/* Preliminary auxiliary variables. */
		size_t counter = V_ZERO;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;

		/* Initial introductory messages. */
		printf("\nDump file.\n");
		printf("Unloading File: [%s]. Opening mode: [%s].\n", strFile, _FILE_MODE_READ_UPDATE_);

		/* Correctly validate the opening of the file for the data dump. */
		if ((pFile = fopen(strFile, _FILE_MODE_READ_UPDATE_)))
			{
				printf("Viewing file content...\n");
				printf("File number: [%d].\n", fileno(pFile));

				while (!feof(pFile) && !ferror(pFile) && counter < numRecords)
					{
						if ((int_fields = fscanf(pFile, "%*c%d%*c%*c%n", &key, &int_chars)) && !feof(pFile) && !ferror(pFile) && (counter < numRecords))
							printf("#: [%lu]\t:\t[%d].\t<%d>.\n", counter++, key, int_chars);
					}

				CheckErrorFile(strFile, pFile);

				printf("\nSize of the dump file.\n");
				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));
				printf("File recovered: [%s] with: [%lu] records out of a total of: [%lu].\n", strFile, counter, numRecords);

				printf("File: [%s] closed!\n", strFile);
				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		/* Return the exact number of records retrieved and read. */
		return counter;
	}

/* Function that gets a correct type value depending on its option. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK)
	{
		/* Preliminary working variables. */
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
									fprintf(stderr, "\nThe selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
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
							if ((int_fields = scanf("%lu%*c%n", (size_t *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%lu]. Characters: [%d]. OK!\n", int_fields, *((size_t *) void_var_address), int_chars);
							break;

						/* It is specified that if the option is incorrect, an error message should be sent. */
						default:
							fprintf(stderr, "\nThe selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
							break;
					}

				/* Verify that exactly one field is captured and saved at the given address. */
				if ((int_fields != V_ONE) || !(int_chars))
					{
						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data entry!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* Get an incorrect entried value. */
						fputs("\nThe value entered is not valid!\n", stderr);
						fprintf(stderr, "Press ENTER to continue...");
						scanf("%*[^\n]%*c");

						/* We must always clear the input buffer of impurities. */
						fputs("\nPress the ENTER key to clear the input buffer...", stderr);
						while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
					}
			}
		else
			fprintf(stderr, "\nThe memory address to hold the variable is not valid!\n");

		/* Return of void pointer key value. */
		return void_var_address;
	}

/* Capture the name of the file to be created. */
char *GetFileName(const char *const str_Message, void *const void_var_address, const size_t size_of_var_address)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Validate the filename correctly. */
		if (void_var_address)
			{
				/* Create a persistent chain. */
				static char str_format[BUFSIZ];
				memset(str_format, V_ZERO, sizeof(str_format));

				/* Construct a format string. */
				if ((int_chars = snprintf(str_format, sizeof(str_format), "%%%lu[^\n]%%*c%%n", size_of_var_address - V_ONE)))
					{
						/* Preliminary header message. */
						printf("%s", str_Message);

						/* Validate the entry of the filename. */
						#pragma GCC diagnostic push
						#pragma GCC diagnostic ignored "-Wformat-nonliteral"
						if ((int_fields = scanf(str_format, (char *) void_var_address, &int_chars)))
						#pragma GCC diagnostic pop
							{
								/* Get a correct string value. */
								printf("\nCaptured chain information.\n");
								printf("+ Fields: [%d].\n", int_fields);
								printf("+ Value:  [%s].\n", (char *) void_var_address);
								printf("+ Chars:  [%d].\n", int_chars);
							}

						/* Verify that exactly one field is captured and saved at the given address. */
						if ((int_fields != V_ONE) || !(int_chars))
							{
								/* Check whether an End-of-File condition occurred during keyboard data input. */
								if (feof(stdin))
									{
										fprintf(stderr, "\nEnd of File (EOF) detected in data entry!\n");
										clearerr(stdin);
										fflush(stdin);
									}

								/* Get an incorrect entried value. */
								fputs("\nThe value entered is not valid!\n", stderr);
								fprintf(stderr, "Press ENTER to continue...");
								scanf("%*[^\n]%*c");

								/* Clear the input buffer until a carriage return followed by a line feed, or an end-of-file, is encountered. */
								fputs("\nPress the ENTER key to clear the input buffer...", stderr);
								while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
							}
					}
				else
					fprintf(stderr, "\nThe format string was not generated correctly! Characters: [%d].\n", int_chars);
			}
		else
			printf("No valid memory address allocated for the file name: [%s].\n", (char *) void_var_address);

		/* Return the pointer to the string containing the filename. */
		return (char *) void_var_address;
	}
