/* Creation of intermediate files for sorting. */
#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define	NULL_CHARACTER		'\0'
#define	CARRIAGE_RETURN		'\n'

#define	_WRITE_FILE_ONLY_	"\x77\x2b"

#define	V_TWELVE		12
#define	V_ZERO			0

struct s_tmp_file
	{
		FILE *pFileTMP;
		int num_records;
	} *ptr_st_File;

int CheckErrorFile(const char *strFile, FILE *pFile);
void CreateTempFiles(int num_files);
char *GetFileName(const char *strMessage, char *strFile);

int main()
	{
		char c = NULL_CHARACTER;
		int num_files = V_ZERO;

		printf("Temporary File Creator.\n");
		printf("How many intermediate files do you want to create? : ");

		if (scanf("%d", &num_files))
			{
				printf("Correct entry: [%d]. OK!\n", num_files);
				CreateTempFiles(num_files);
			}
		else
			{
				scanf("%*[^\n]%*c");
				while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}
	}

void CreateTempFiles(int num_files)
	{
		char c = V_ZERO, fileName[V_TWELVE];

		if (num_files)
			if (ptr_st_File = (struct s_tmp_file *) malloc(num_files * sizeof(struct s_tmp_file)))
				{
					for (int idx = V_ZERO; idx < num_files; idx++)
						{
							printf("\nCapture temporary file names.\n");
							printf("#: [%d].\n", idx);
							GetFileName("- File name : ", fileName);

							(ptr_st_File + idx)->pFileTMP = fopen(fileName, _WRITE_FILE_ONLY_);
							CheckErrorFile(fileName, ptr_st_File[idx].pFileTMP);

							printf("- Records   : ");

							if (scanf("%d", &(ptr_st_File + idx)->num_records))
								printf("\nCorrect entry: [%d]. OK!\n", ptr_st_File[idx].num_records);
							else
								{
									scanf("%*[^\n]%*c");
									while((c = getchar()) != CARRIAGE_RETURN && c != EOF);
								}


							printf("** [%d]. [%p] = [%s]. [%d]. **\n", idx, ptr_st_File[idx].pFileTMP, fileName, (ptr_st_File + idx)->num_records);
							fclose((ptr_st_File[idx].pFileTMP));
						}

					free(ptr_st_File);
				}
			else
				printf("Insufficient memory to create file pointer array.\n");
		else
			printf("Invalid number of files to use: [%d].\n", num_files);
	}

int CheckErrorFile(const char *strFile, FILE *pFile)
	{
		int idx = V_ZERO;

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

		return (feof(pFile) && ferror(pFile));
	}

char *GetFileName(const char *strMessage, char *strFile)
	{
		char c = NULL_CHARACTER;

		if (strFile)
			{
				printf("%s", strMessage);

				if (scanf("%s", strFile))
					printf("\nCorrect entry: [%s]. OK!\n", strFile);
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
