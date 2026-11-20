/* The purpose of this program is to read information from a file and a directory,
   respectively, extracting the most essential and specific content from each. */

/* Standard Work Libraries. */
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'

/* Expected response. */
#define	V_CHR_LOWER_Y	0x79
#define	V_CHR_UPPER_Y	0x59

/* Symbolic Work Constants. */
#define	V_ONE		1
#define	V_ZERO		0

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
char* GetString(const char *const str_Message);

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

/* Function that performs a specified pause with a warning message. */
char* GetString(const char *const str_Message)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Create a persistent chain. */
		static char string[BUFSIZ] = {NULL_CHARACTER};
		memset(string, V_ZERO, sizeof(string));

		/* Header message. */
		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if ((int_fields = scanf("%[^\n]%*c%n", string, &int_chars)) == V_ONE)
			{
				/* Get a correct string value. */
				printf("\nCaptured chain information.\n");
				printf("+ Fields: [%d].\n", int_fields);
				printf("+ Value:  [%s].\n", string);
				printf("+ Chars:  [%d].\n", int_chars);
			}
		else
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

				/* Clear the input buffer until a carriage return followed by a line feed, or an end-of-file, is encountered. */
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

		/* Return of a string value. */
		return string;
	}

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		char chr_key = V_CHR_LOWER_Y, chr_pause = NULL_CHARACTER;
		DIR *directory = NULL;

		/* Pointers to the character strings for both the filename and the directory name. */
		char *ptr_str_directory = NULL;
		char *ptr_str_filename = NULL;

		/* Self-initializing static array to store the current path. */
		char *ptr_s_path = NULL;
		static char s_path[BUFSIZ];
		memset(s_path, V_ZERO, sizeof(s_path));

		/* Structures for reading a file entry from a directory. */
		struct dirent *file = NULL;
		struct stat fstat;
		memset(&fstat, V_ZERO, sizeof(struct stat));

		/* Time trackers. */
		size_t counter = V_ZERO;
		time_t t_elapsed_seconds = time(&t_elapsed_seconds);

		/* Display the current working directory. */
		ptr_s_path = getcwd(s_path, sizeof(s_path));
		printf("Display the current working directory.\n");
		printf("\x27%s\x27 : %p\x2e\n", s_path, ptr_s_path);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Code block for obtaining information from a given file. */
		printf("\nObtaining information from files.\n");
		ptr_str_filename = GetString("Type a filename: ");

		stat(ptr_str_filename, &fstat);	//Obtain the statistics record for a given file.

		printf("\nFile information read.\n");
		printf("%s", ctime(&t_elapsed_seconds));
		printf("%s is %ld bytes long.\n", ptr_str_filename, fstat.st_size);
		printf("It was modified on %s", ctime(&fstat.st_mtime));
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Code block for retrieving information from a specific directory. */
		t_elapsed_seconds = time(&t_elapsed_seconds);

		/* Capture the path of the directory to be scanned. */
		printf("\nObtaining information from directories.\n");
		ptr_str_directory = GetString("Type a directory: ");

		/* Display the current system date and time. */
		printf("\nDirectory information read.\n");
		printf("%s", ctime(&t_elapsed_seconds));

		/* A loop that ensures the files contained in a specific directory are read. */
		if ((directory = opendir(ptr_str_directory)))
			{
				while ((file = readdir(directory)) && (chr_key == V_CHR_LOWER_Y || chr_key == V_CHR_UPPER_Y))	//Read each file entry from the specified directory.
					{
						stat(file->d_name, &fstat);	//Function to extract information from each file.

						/* Dumping of information from each file read from the specified directory. */
						printf("\n# %zu.\n", counter++);
						printf("* File: %s\n", file->d_name);
						printf("+ Type: %s.\n", (S_ISDIR(fstat.st_mode)) ? "Directory" : "File");
						printf("+ Size: %ld bytes long.\n", fstat.st_size);
						printf("+ It was modified on %s\n", ctime(&fstat.st_mtime));

						chr_key = *((char *) GetEntry("Do you want to continue reading the next file from the specified directory (y/n)? : ", &chr_key, enm_type_entry_char, enm_type_reset_YES));
					}

				printf("[%zu] Output results generated.\n", counter);
				chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

				closedir(directory);
			}

		/* Change to the directory specified by the user. */
		printf("\nChange to the directory specified by the user.\n");
		ptr_str_directory = GetString("Enter the directory to change: ");

		/* Check whether the directory was changed correctly. */
		if (chdir(ptr_str_directory))
			printf("\nThe directory: '%s' was not found!\n", ptr_str_directory);
		else
			printf("\nChanged to the directory: \'%s\'\n", ptr_str_directory);

		/* Introduce a calculated intermediate pause. */
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Print the current directory to verify that it has been changed. */
		ptr_s_path = getcwd(s_path, sizeof(s_path));
		printf("\nDisplay the current working directory.\n");
		printf("Current working directory: \'%s\' in address: %p\x2e\n", s_path, ptr_s_path);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}
