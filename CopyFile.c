/* Program that copies one file to another with sequential access. */

/* Standard Work Libraries. */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN		'\n'
#define NULL_CHARACTER		'\0'

/* File opening modes. */
#define	_READ_ONLY_FILE_	"\x72\x2b"
#define	_WRITE_ONLY_FILE_	"\x77\x2b"

/* Symbolic work constants. */
#define V_ONE			1
#define	V_ZERO			0

/* General global variable. */
int key = V_ZERO;

/* Prototypes of the functions of this program. */
int CheckErrorFile(const char *const strFile, FILE *pFile);
int CopyFile(const char *str_SourceFile, const char *str_TargetFile, const int numRecords);
int CreateFile(const char *const str_File);
char *GetFileName(const char *strMessage, char *strFile);
char GetPause(const char *const str_Message);
int DumpFile(const char *str_File, const int numRecords);

/* Main function */
int main()
	{
		/* Preliminary working variables. */
		char *strFIn = (char *) calloc(BUFSIZ, sizeof(char));
		char *strFOut = (char *) calloc(BUFSIZ, sizeof(char));
		int numRecords = V_ZERO;

		/* Data entry */
		printf("File Copy.\n");
		GetFileName("> Source file : ", strFIn);
		GetFileName("> Target file : ", strFOut);

		/* Calls to special functions. */
		numRecords = CreateFile(strFIn);
		GetPause("Press the ENTER key to continue...");

		numRecords = DumpFile(strFIn, numRecords);
		GetPause("Press the ENTER key to continue...");

		numRecords = CopyFile(strFIn, strFOut, numRecords);
		GetPause("Press the ENTER key to continue...");

		numRecords = DumpFile(strFOut, numRecords);
		GetPause("Press the ENTER key to continue...");

		/* Freeing memory file pointers. */
		puts("\nFreeing allocated memory...");
		free(strFIn);
		free(strFOut);
		GetPause("Press the ENTER key to continue...");

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		GetPause("Press the ENTER key to continue...");

		return V_ZERO;
	}

/* A function that returns whether an end-of-file or an error occurred for a file pointer. */
int CheckErrorFile(const char *const strFile, FILE *pFile)
	{
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

		if (feof(pFile))
			printf("End of file: [%s] in address: [%p] reached.\n", strFile, (void *) pFile);

		return (ferror(pFile) || feof(pFile));
	}

/* Copies records identically from one file to another, record by record. */
int CopyFile(const char *strSource, const char *strTarget, const int numRecords)
	{
		/* Preliminary Working Variables. */
		FILE *pFSource = NULL, *pFTarget = NULL;

		int counter = V_ZERO;
		int int_fields = V_ZERO;
		int inBytes = V_ZERO, inKey = V_ZERO, outBytes = V_ZERO, outKey = V_ZERO;

		/* Initial presentation headers. */
		printf("\nCopy Files.\n");
		printf("- Source file: [%s]. Open mode: [%s].\n", strSource, _READ_ONLY_FILE_);
		printf("- Target file: [%s]. Open mode: [%s].\n", strTarget, _WRITE_ONLY_FILE_);

		/* Opening and validation of source and destination files. */
		if ((pFTarget = fopen(strTarget, _WRITE_ONLY_FILE_)))
			{
				if ((pFSource = fopen(strSource, _READ_ONLY_FILE_)))
					{
						printf("File: [%s] with number: [%d] is copied to file: [%s] with number: [%d].\n", strSource, fileno(pFSource), strTarget, fileno(pFTarget));

						while ((!feof(pFSource) && !ferror(pFSource))
						    && (!feof(pFTarget) && !ferror(pFTarget))
						    && (counter < numRecords))
							{
								if ((int_fields = fscanf(pFSource, "%*c%d%*c%*c%n", &inKey, &inBytes)) && !feof(pFSource) && !ferror(pFSource) && (counter < numRecords))
									{
										if ((int_fields = fprintf(pFTarget, "{%d}.%n\n", outKey = inKey, &outBytes)))
											printf("#: [%d]\t:\t(%d)\t=\t{%d}.\t<%d>\t=\t<%d>.\n", counter++, inKey, outKey, inBytes, outBytes);
									}
							}

						CheckErrorFile(strSource, pFSource);
						CheckErrorFile(strTarget, pFTarget);

						printf("\nSize of the source and destination copy files.\n");
						fseek(pFSource, V_ZERO, SEEK_END);
						printf("File size: [%s] with: [%ld] bytes.\n", strSource, ftell(pFSource));
						fseek(pFTarget, V_ZERO, SEEK_END);
						printf("File size: [%s] with: [%ld] bytes.\n", strTarget, ftell(pFTarget));

						printf("File: [%s] was written with: [%d] records out of a total of: [%d].\n", strTarget, counter, numRecords);

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

		return counter;
	}

/* This function creates and captures a specific file. */
int CreateFile(const char *const strFile)
	{
		/* Preliminary Working Variables. */
		FILE *pFile = NULL;

		int counter = V_ZERO;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Initial presentation headers. */
		printf("\nCreate file.\n");
		printf("Loading File: [%s]. Opening mode: [%s].\n", strFile, _WRITE_ONLY_FILE_);

		/* Validate the creation of the source file. */
		if ((strFile) && (pFile = fopen(strFile, _WRITE_ONLY_FILE_)))
			{
				printf("Capturing file...\n");
				printf("File number: [%d].\n", fileno(pFile));

				while (!feof(pFile) && !ferror(pFile))
					{
						key = V_ZERO;
						printf("Code: ");

						if ((int_fields = scanf("%d%*c%n", &key, &int_chars)))
							printf("Correct entry! Fields: [%d]. Input value: [%d]. Characters: [%d]. OK!\n", int_fields, key, int_chars);
						else
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

						if (key == V_ZERO) break;

						if ((int_fields = fprintf(pFile, "(%d).\n%n", key, &int_chars)))
							printf("#: [%d]\t:\t[%d].\t<%d>.\n", counter++, key, int_chars);
					}

				CheckErrorFile(strFile, pFile);

				printf("\nSize of the created file.\n");
				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));
				printf("File saved: [%s] with: [%d] records.\n", strFile, counter);

				printf("File: [%s] closed!\n", strFile);
				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		/* Return the exact number of saved or stored records. */
		return counter;
	}

/* This function displays the contents of a created file, record by record. */
int DumpFile(const char *strFile, const int numRecords)
	{
		/* Preliminary Working Variables. */
		FILE *pFile = NULL;
		int counter = V_ZERO;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;

		/* Initial introductory messages. */
		printf("\nDump file.\n");
		printf("Unloading File: [%s]. Opening mode: [%s].\n", strFile, _READ_ONLY_FILE_);

		/* Correctly validate the opening of the file for the data dump. */
		if ((pFile = fopen(strFile, _READ_ONLY_FILE_)))
			{
				printf("Viewing file content...\n");
				printf("File number: [%d].\n", fileno(pFile));

				while (!feof(pFile) && !ferror(pFile) && counter < numRecords)
					{
						if ((int_fields = fscanf(pFile, "%*c%d%*c%*c%n", &key, &int_chars)) && !feof(pFile) && !ferror(pFile) && (counter < numRecords))
							printf("#: [%d]\t:\t[%d].\t<%d>.\n", counter++, key, int_chars);
					}

				CheckErrorFile(strFile, pFile);

				printf("\nSize of the dump file.\n");
				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));
				printf("File recovered: [%s] with: [%d] records out of a total of: [%d].\n", strFile, counter, numRecords);

				printf("File: [%s] closed!\n", strFile);
				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		/* Return the exact number of records retrieved and read. */
		return counter;
	}

/* Capture the name of the file to be created. */
char *GetFileName(const char *strMessage, char *strFile)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Validate the filename correctly. */
		if (strFile)
			{
				/* Preliminary header message. */
				printf("\n%s", strMessage);

				/* Validate the entry of the filename. */
				if ((int_fields = scanf("%[^\n]%*c%n", strFile, &int_chars)))
					printf("\nCorrect entry! Fields: [%d]. Input value: [%s]. Characters: [%d]. OK!\n", int_fields, strFile, int_chars);

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
			printf("No valid memory address allocated for the file name: [%s].\n", strFile);

		/* Return the pointer to the string containing the filename. */
		return strFile;
	}

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

				chr_key = (char) int_key;
			}

		/* Return of key value. */
		return chr_key;
	}
