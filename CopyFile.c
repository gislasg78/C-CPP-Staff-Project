/* Program that copies one file to another with sequential access. */
#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NULL_CHARACTER	'\0'
#define	CARRIAGE_RETURN	'\n'

#define	_F_READ_ONLY	"\x72"
#define	_F_WRITE_ONLY	"\x77"

#define	V_TWELVE	12
#define	V_ZERO		0

int key = V_ZERO;

int CheckErrorFile(const char *strFile, FILE *pFile);
int CopyFile(const char *str_SourceFile, const char *str_TargetFile);
char *GetFileName(const char *strMessage, char *strFile);
int DumpFile(const char *str_File);
int LoadFile(const char *str_File);

int main()	/* Main function */
	{
		char *strFIn = (char *) malloc(V_TWELVE * sizeof(char));
		char *strFOut = (char *) malloc(V_TWELVE * sizeof(char));

		/* Data entry */
		printf("File Copy.\n");
		GetFileName("Source file : ", strFIn);
		GetFileName("Target file : ", strFOut);

		LoadFile(strFIn);
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
				printf("Error detection in file I/O operations.\n");
				printf("- File:\t\t[%s].\n", strFile);
				printf("- Error number:\t[%d].\n", errno);
				printf("- Description:\t[%s].\n", strerror(errno));

				perror("\nBad error in the file. It fucked up!\n->");
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

		if (pFTarget = fopen(strTarget, _F_WRITE_ONLY))
			{
				if (pFSource = fopen(strSource, _F_READ_ONLY))
					{
						printf("File: [%s] is copied to file: [%s].\n", strSource, strTarget);

						while ((!feof(pFSource) && !ferror(pFSource))
						    && (!feof(pFTarget) && !ferror(pFTarget)))
							{
								fscanf(pFSource, "%d", &key);

								if (!feof(pFSource) && !ferror(pFSource))
									{
										fprintf(pFTarget, "%d\n", key);
										printf("#:[%d].\t[%d].\n", idx++, key);
									}
							}

						CheckErrorFile(strSource, pFSource);
						CheckErrorFile(strTarget, pFTarget);
						printf("File [%s] wroten with: [%d] records.\n", strTarget, idx);

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

int DumpFile(const char *strFile)
	{
		FILE *pFile = NULL;
		int idx = V_ZERO;

		printf("\nDump File: [%s].\n", strFile);

		if (pFile = fopen(strFile, _F_READ_ONLY))
			{
				printf("File content.\n");

				while (!feof(pFile) && !ferror(pFile))
					{
						fscanf(pFile, "%d", &key);

						if (!feof(pFile) && !ferror(pFile))
							printf("#:[%d].\t[%d].\n", idx++, key);
					}

				CheckErrorFile(strFile, pFile);
				printf("File recovered: [%s] with: [%d] records.\n", strFile, idx);

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
				printf("%s", strMessage);
				scanf("%s", strFile);

				scanf("%*[^\n]%*c");
				while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}
		else
			printf("No valid memory address allocated for the file name.");

		return strFile;
	}

int LoadFile(const char *strFile)
	{
		FILE *pFile = NULL;
		int idx = V_ZERO;

		printf("\nLoading File: [%s].\n", strFile);
		if (pFile = fopen(strFile, _F_WRITE_ONLY))
			{
				printf("Capturing file...\n");

				while (!feof(pFile) && !ferror(pFile))
					{
						printf("Code: ");
						scanf("%d", &key);

						if (key == V_ZERO) break;

						fprintf(pFile, "%d\n", key);
						printf("#:[%d].\t[%d].\n", idx++, key);
					}

				CheckErrorFile(strFile, pFile);
				printf("File saved: [%s] with: [%d] records.\n", strFile, idx);

				fclose(pFile);
			}
		else
			CheckErrorFile(strFile, pFile);

		return idx;
	}
