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

/* Symbolic Work Constants. */
#define	V_ONE		1
#define	V_ZERO		0

/* Function that performs a specified pause with a warning message. */
char GetPause(const char *const str_Message)
	{
		/* Preliminary working variables. */
		char chr_key = NULL_CHARACTER;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Header message. */
		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if ((int_fields = scanf("%c%*c%n", &chr_key, &int_chars)) == V_ONE)
			{
				/* Get a correct character value. */
				printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, chr_key, chr_key, chr_key, int_chars);
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

				chr_key = (char) int_key;
			}

		/* Return of key value. */
		return chr_key;
	}

/* Function that performs a specified pause with a warning message. */
char* GetString(const char *const str_Message)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Create a persistent chain. */
		static char string[BUFSIZ];
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
		printf("\x27%s\x27 : %p\n", s_path, ptr_s_path);
		GetPause("Press the ENTER key to continue...");

		/* Code block for obtaining information from a given file. */
		printf("\nObtaining information from files.\n");
		ptr_str_filename = GetString("Type a filename: ");

		stat(ptr_str_filename, &fstat);	//Obtain the statistics record for a given file.

		printf("\nFile information read.\n");
		printf("%s", ctime(&t_elapsed_seconds));
		printf("%s is %ld bytes long.\n", ptr_str_filename, fstat.st_size);
		printf("It was modified on %s", ctime(&fstat.st_mtime));
		GetPause("Press the ENTER key to continue...");

		/* Code block for retrieving information from a specific directory. */
		t_elapsed_seconds = time(&t_elapsed_seconds);

		printf("\nObtaining information from directories.\n");
		ptr_str_directory = GetString("Type a directory: ");

		printf("\nDirectory information read.\n");
		printf("%s", ctime(&t_elapsed_seconds));
		GetPause("Press the ENTER key to continue...");

		/* A loop that ensures the files contained in a specific directory are read. */
		if ((directory = opendir(ptr_str_directory)))
			{
				while ((file = readdir(directory)))
					{
						stat(file->d_name, &fstat);

						printf("\n# %lu.\n", counter++);
						printf("* File: %s\n", file->d_name);
						printf("+ Type: %s.\n", (S_ISDIR(fstat.st_mode)) ? "Directory" : "File");
						printf("+ Size: %ld bytes long.\n", fstat.st_size);
						printf("+ It was modified on %s\n", ctime(&fstat.st_mtime));

						GetPause("Press the ENTER key to continue...");
					}

				printf("[%lu] Output results generated.\n", counter);
				GetPause("Press the ENTER key to continue...");

				closedir(directory);
			}

		/* Change to the directory specified by the user. */
		printf("\nChange to the directory specified by the user.\n");
		ptr_str_directory = GetString("Enter the directory to change: ");

		if (chdir(ptr_str_directory))
			printf("\nThe directory: '%s' was not found!\n", ptr_str_directory);
		else
			printf("\nChanged to the directory: \'%s\'\n", ptr_str_directory);

		/* Print the current directory to verify that it has been changed. */
		ptr_s_path = getcwd(s_path, sizeof(s_path));
		printf("\nDisplay the current working directory.\n");
		printf("Current working directory: \'%s\' in address: %p\n", s_path, ptr_s_path);
		GetPause("Press the ENTER key to continue...");

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
