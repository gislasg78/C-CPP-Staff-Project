/* Program that copies one file to another with sequential access. */
#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Symbolic work constants.
#define NULL_CHARACTER		'\0'
#define	CARRIAGE_RETURN		'\n'

#define	_READ_ONLY_FILE_	"\x72\x2b"
#define	_WRITE_ONLY_FILE_	"\x77\x2b"

#define V_ONE			1
#define	V_TWELVE		12
#define	V_ZERO			0

/* General global variable. */
int key = V_ZERO;

/* Prototypes of the functions of this program. */
int CheckErrorFile(const char *strFile, FILE *pFile);
int CopyFile(const char *str_SourceFile, const char *str_TargetFile, const int numRecords);
char *GetFileName(const char *strMessage, char *strFile);
int DumpFile(const char *str_File, const int numRecords);
int CreateFile(const char *str_File);

/* Main function */
int main()
	{
		/* Preliminary working variables. */
		char *strFIn = (char *) malloc(V_TWELVE * sizeof(char));
		char *strFOut = (char *) malloc(V_TWELVE * sizeof(char));
		int numRecords = V_ZERO;

		/* Data entry */
		printf("File Copy.\n");
		GetFileName("Source file : ", strFIn);
		GetFileName("Target file : ", strFOut);

		//Calls to special functions.
		numRecords = CreateFile(strFIn);
		numRecords = DumpFile(strFIn, numRecords);
		numRecords = CopyFile(strFIn, strFOut, numRecords);
		numRecords = DumpFile(strFOut, numRecords);

		//Freeing memory pointers.
		free(strFIn);
		free(strFOut);
	}

int CheckErrorFile(const char *strFile, FILE *pFile)
	{
		if (ferror(pFile))
			{
				printf("\n");
				printf("+---+----+---+----+---+\n");
				printf("| I/O Error detection |\n");
				printf("+---+----+---+----+---+\n");
				printf("| - File:\t\t[%s].\n", strFile);
				printf("| - Address:\t[%p].\n", pFile);
				printf("| - Error number:\t[%d].\n", errno);
				printf("| - Description:\t[%s].\n", strerror(errno));
				printf("+---+----+---+----+---+\n");

				perror("\nBad error in the file. It fucked up!\n->");
				printf("\n");
			}

		if (feof(pFile))
			printf("End of file: [%s] in address: [%p] reached.\n", strFile, pFile);

		return (ferror(pFile) || feof(pFile));
	}

int CopyFile(const char *strSource, const char *strTarget, const int numRecords)
	{
		FILE *pFSource = NULL, *pFTarget = NULL;
		int inpBytes = V_ZERO, inpKey = V_ZERO, outBytes = V_ZERO, outKey = V_ZERO;
		int idx = V_ZERO;

		printf("\nCopy Files.\n");
		printf("- Source file: [%s]. Open mode: [%s].\n", strSource, _READ_ONLY_FILE_);
		printf("- Target file: [%s]. Open mode: [%s].\n", strTarget, _WRITE_ONLY_FILE_);

		if ((pFTarget = fopen(strTarget, _WRITE_ONLY_FILE_)))
			{
				if ((pFSource = fopen(strSource, _READ_ONLY_FILE_)))
					{
						printf("File: [%s] is copied to file: [%s].\n", strSource, strTarget);

						while ((!feof(pFSource) && !ferror(pFSource))
						    && (!feof(pFTarget) && !ferror(pFTarget))
						    && (idx < numRecords))
							{
								if (fscanf(pFSource, "%*c%d%*c%*c%n", &inpKey, &inpBytes) && !feof(pFSource) && !ferror(pFSource) && idx < numRecords)
									{
										if (fprintf(pFTarget, "{%d}.%n\n", outKey = inpKey, &outBytes))
											printf("#: [%d]\t:\t(%d)\t=\t{%d}.\t<%d>\t=\t<%d>.\n", idx++, inpKey, outKey, inpBytes, outBytes);
									}
							}

						CheckErrorFile(strSource, pFSource);
						CheckErrorFile(strTarget, pFTarget);

						printf("\nSize of the source and destination copy files.\n");
						fseek(pFSource, V_ZERO, SEEK_END);
						printf("File size: [%s] with: [%ld] bytes.\n", strSource, ftell(pFSource));
						fseek(pFTarget, V_ZERO, SEEK_END);
						printf("File size: [%s] with: [%ld] bytes.\n", strTarget, ftell(pFTarget));

						printf("File: [%s] was written with: [%d] records out of a total of: [%d].\n", strTarget, idx, numRecords);

						fclose(pFSource);
						fclose(pFTarget);
					}
				else
					CheckErrorFile(strSource, pFSource);
			}
		else
			CheckErrorFile(strTarget, pFTarget);

		return idx;
	}

int CreateFile(const char *strFile)
	{
		char c = NULL_CHARACTER;
		FILE *pFile = NULL;
		int idx = V_ZERO, outBytes = V_ZERO;

		printf("\nCreate file.\n");
		printf("Loading File: [%s]. Opening mode: [%s].\n", strFile, _WRITE_ONLY_FILE_);

		if ((pFile = fopen(strFile, _WRITE_ONLY_FILE_)))
			{
				printf("Capturing file...\n");

				while (!feof(pFile) && !ferror(pFile))
					{
						printf("Code: ");

						if (scanf("%d%*c", &key) == V_ONE)
							printf("Correct entry: [%d]. OK!\n", key);
						else
							{
								scanf("%*[^\n]%*c");
								while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
							}

						if (key == V_ZERO) break;

						if (fprintf(pFile, "(%d).\n%n", key, &outBytes))
							printf("#: [%d]\t:\t[%d].\t<%d>.\n", idx++, key, outBytes);
					}

				CheckErrorFile(strFile, pFile);

				printf("\nSize of the created file.\n");
				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));
				printf("File saved: [%s] with: [%d] records.\n", strFile, idx);

				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		return idx;
	}

int DumpFile(const char *strFile, const int numRecords)
	{
		FILE *pFile = NULL;
		int inpBytes = V_ZERO, idx = V_ZERO;

		printf("\nDump file.\n");
		printf("Unloading File: [%s]. Opening mode: [%s].\n", strFile, _READ_ONLY_FILE_);

		if ((pFile = fopen(strFile, _READ_ONLY_FILE_)))
			{
				printf("Viewing file content...\n");

				while (!feof(pFile) && !ferror(pFile) && idx < numRecords)
					{
						if (fscanf(pFile, "%*c%d%*c%*c%n", &key, &inpBytes) && !feof(pFile) && !ferror(pFile) && idx < numRecords)
							printf("#: [%d]\t:\t[%d].\t<%d>.\n", idx++, key, inpBytes);
					}

				CheckErrorFile(strFile, pFile);

				printf("\nSize of the dump file.\n");
				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));
				printf("File recovered: [%s] with: [%d] records out of a total of: [%d].\n", strFile, idx, numRecords);

				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		return idx;
	}

char *GetFileName(const char *strMessage, char *strFile)
	{
		char c = NULL_CHARACTER;

		if (strFile)
			{
				printf("\n%s", strMessage);

				if (scanf("%[^\n]%*c", strFile) == V_ONE)
					printf("Correct entry: [%s]. OK!\n", strFile);
				else
					{
						scanf("%*[^\n]%*c");
						while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
					}
			}
		else
			printf("No valid memory address allocated for the file name: [%s].\n", strFile);

		return strFile;
	}
