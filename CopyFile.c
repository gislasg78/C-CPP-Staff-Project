/* Program that copies one file to another with sequential access. */
#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NULL_CHARACTER		'\0'
#define	CARRIAGE_RETURN		'\n'

#define	_READ_ONLY_FILE_	"\x72\x2b"
#define	_WRITE_ONLY_FILE_	"\x77\x2b"

#define	V_TWELVE		12
#define	V_ZERO			0

int key = V_ZERO;

int CheckErrorFile(const char *strFile, FILE *pFile);
int CopyFile(const char *str_SourceFile, const char *str_TargetFile);
char *GetFileName(const char *strMessage, char *strFile);
int DumpFile(const char *str_File);
int CreateFile(const char *str_File);

int main()	/* Main function */
	{
		char *strFIn = (char *) malloc(V_TWELVE * sizeof(char));
		char *strFOut = (char *) malloc(V_TWELVE * sizeof(char));

		/* Data entry */
		printf("File Copy.\n");
		GetFileName("Source file : ", strFIn);
		GetFileName("Target file : ", strFOut);

		CreateFile(strFIn);
		DumpFile(strFIn);
		CopyFile(strFIn, strFOut);
		DumpFile(strFOut);

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
				printf("| - Error number:\t[%d].\n", errno);
				printf("| - Description:\t[%s].\n", strerror(errno));
				printf("+---+----+---+----+---+\n");

				perror("\nBad error in the file. It fucked up!\n->");
				printf("\n");
			}

		if (feof(pFile))
			printf("End of file: [%s] reached.\n", strFile);

		return (ferror(pFile) || feof(pFile));
	}

int CopyFile(const char *strSource, const char *strTarget)
	{
		FILE *pFSource = NULL, *pFTarget = NULL;
		int idx = V_ZERO;

		printf("\nCopy Files.\n");
		printf("- Source file: [%s]. Open mode: [%s].\n", strSource, _READ_ONLY_FILE_);
		printf("- Target file: [%s]. Open mode: [%s].\n", strTarget, _WRITE_ONLY_FILE_);

		if (pFTarget = fopen(strTarget, _WRITE_ONLY_FILE_))
			{
				if (pFSource = fopen(strSource, _READ_ONLY_FILE_))
					{
						printf("File: [%s] is copied to file: [%s].\n", strSource, strTarget);

						while ((!feof(pFSource) && !ferror(pFSource))
						    && (!feof(pFTarget) && !ferror(pFTarget)))
							{
								if (fscanf(pFSource, "%*c%d%*c%*c", &key) && !feof(pFSource) && !ferror(pFSource))
									{
										fprintf(pFTarget, "{%d}.\n", key);
										printf("#: [%d]\t:\t{%d}.\n", idx++, key);
									}
							}

						CheckErrorFile(strSource, pFSource);
						CheckErrorFile(strTarget, pFTarget);
						printf("File: [%s] was written with: [%d] records.\n", strTarget, idx);

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
		int idx = V_ZERO;

		printf("\nCreate file.\n");
		printf("Loading File: [%s]. Opening mode: [%s].\n", strFile, _WRITE_ONLY_FILE_);

		if (pFile = fopen(strFile, _WRITE_ONLY_FILE_))
			{
				printf("Capturing file...\n");

				while (!feof(pFile) && !ferror(pFile))
					{
						printf("Code: ");

						if (scanf("%d", &key))
							printf("Correct entry: [%d]. OK!\n", key);
						else
							{
								scanf("%*[^\n]%*c");
								while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
							}

						if (key == V_ZERO) break;

						fprintf(pFile, "[%d].\n", key);
						printf("#: [%d]\t:\t[%d].\n", idx++, key);
					}

				CheckErrorFile(strFile, pFile);
				printf("File saved: [%s] with: [%d] records.\n", strFile, idx);

				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		return idx;
	}

int DumpFile(const char *strFile)
	{
		FILE *pFile = NULL;
		int idx = V_ZERO;

		printf("\nDump file.\n");
		printf("Unloading File: [%s]. Opening mode: [%s].\n", strFile, _READ_ONLY_FILE_);

		if (pFile = fopen(strFile, _READ_ONLY_FILE_))
			{
				printf("Viewing file content...\n");

				while (!feof(pFile) && !ferror(pFile))
					{
						if (fscanf(pFile, "%*c%d%*c%*c", &key) && !feof(pFile) && !ferror(pFile))
							printf("#: [%d]\t:\t[%d].\n", idx++, key);
					}

				CheckErrorFile(strFile, pFile);
				printf("File recovered: [%s] with: [%d] records.\n", strFile, idx);

				fseek(pFile, V_ZERO, SEEK_END);
				printf("File size: [%s] with: [%ld] bytes.\n", strFile, ftell(pFile));

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

				if (scanf("%s", strFile))
					printf("Correct entry: [%s]. OK!\n", strFile);
				else
					{
						scanf("%*[^\n]%*c");
						while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
					}
			}
		else
			printf("No valid memory address allocated for the file name.");

		return strFile;
	}
