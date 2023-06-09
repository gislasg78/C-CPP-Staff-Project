/*********************************************************
 ** Source Code:	Conta.c				**
 ** Author:		Gustavo Islas Gálvez.		**
 ** Creation Date:	Friday, June 09, 2023.		**
 ** Purpose:		Count the characters of a	**
 **			specific given file.		**
*********************************************************/
/* C Standard Libraries. */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Work Symbolic Constants Declarations */
#define	ZERO_VALUE			0
#define	ONE_VALUE			1
#define TWO_VALUE			2
#define	V_255				255

/* Symbolic Constants Declarations. */
#define NULL_CHARACTER			'\x0'
#define	_READ_ONLY_FILE			"r"

/*********************************************************
 ** Function:		getpause.			**
 ** Explanation:	This function returns as a	**
 **			result a character pressed and	**
 **			unwrapped as a pause.		**
 ** Input Parms:	A constant pointer to string of **
 **			that is displayed as a message	**
 **			on the screen.			**
 **			*str_Message.			**
 ** Output Parms:	None.				**
 ** Result:		Bring back the held down	**
 ** 			character from keyboard.	**
 ********************************************************/
char getpause (const char *str_Message)
    {
    	static char chr_Car=NULL_CHARACTER;

	printf("%s", str_Message);
	scanf("%*c%c", &chr_Car);

	return (chr_Car);
    }

/*********************************************************
 ** Function:		CounterBytes.			**
 ** Explanation:	This function reckon the	**
 ** 			characters of a given file	**
 **			entered.			**
 ** Input Parms:	A constant pointer to string of **
 **			characters that contains the	**
 ** 			scan file name and path.	**
 **			* str_FileName.			**
 ** Output Parms:	None.				**
 ** Result:		Calculate the characters number **
 **			of given file.			**
 ********************************************************/
long CounterBytes (const char *str_FileName)
	{
		FILE *pFile=NULL;
		unsigned char ch_Readed_Char=NULL_CHARACTER;
		long lng_Counter_Bytes=ZERO_VALUE;

		/* Specific file is opened in read-only mode. */
		if ( (pFile = fopen(str_FileName, _READ_ONLY_FILE)) != NULL )
			{
				/* The file name and its respective path are observed
				   by command line. */
				printf("\nFile to explore: [%s].\n", str_FileName);

				/* Display a ruler to view the message beginning. */
				printf("+----|----+----|----+----|----+----|----+----|" \
					   "----+----|----+----|----+----|--+\n");

				/* Each char will be read at a time and
				   show on the screen. */
				/* It takes effect until there is an error or
				   the end of file are reached. */
				while (!ferror(pFile) && !feof(pFile))
					{
						/* A char is achieved as long as
						   there is no error. */
						ch_Readed_Char=fgetc(pFile);

						/* Count each successfully retrieved character
						   one by one. */
						lng_Counter_Bytes++;

						/* Vital information of the extracted character
						   is displayed in ascii, hexadecimal and octal
						   formats at the reading time. */
						printf("Got back character: [%ld] ",
						        lng_Counter_Bytes);
						printf("ASCII Code: [%3.u]. ", ch_Readed_Char);
						printf("Hexadecimal: [%x]. ", ch_Readed_Char);
						printf("Octal: [%o].\r", ch_Readed_Char);
					}

				/* Display a slider to show the end of file scanning. */
				printf("\n+----|----+----|----+----|----+----|----+----|" \
					   "----+----|----+----|----+----|--+\n");

				/* A non-zero value means perfect operation. */
				if (!ferror(pFile))
					{
						/* Watched File Character Final Posting Message. */
						printf("Scouted file [%s] has [%ld] total chars.\n",
						        str_FileName, lng_Counter_Bytes);

						fclose(pFile);		/* The opened file is closed. */
						clearerr(pFile);	/* The file buffer is purged. */
					}
				else
					{
						/* The file couldn't be checked out correctly,
						   therefore it's sent to fatal error message. */
						printf("File [%s] couldn't be read successfully." \
							   "\n", str_FileName);
						printf("\nError number:\t\t[%d].\n"    \
						       "Error description:\t[%s].\n",  \
						        errno, strerror(errno));

						perror("\nBad error in reading the file.\n" \
						       "It fucked up!\n->");
					}
			}
		else
			{
				/* The file couldn't be opened, so execution aborts. */
				printf("File [%s] couldn't be opened properly.\n",
				        str_FileName);
				printf("\nError number:\t\t[%d].\n" \
				       "Error description:\t[%s].\n", \
				        errno, strerror(errno));

				perror("\nError during file opening. " \
				       "Fateful mistake!\n->");
			}

		return(lng_Counter_Bytes);
	}

/*****************************************************************
 ** Function:	main().						**
 ****************************************************************/
int main(int int_argc, char *ch_argv[])
	{
		/* Work Variables Declaration of the primary function. */
		char str_FileNameCounting[V_255]={NULL_CHARACTER};
		long lng_counter_bytes=ZERO_VALUE;

		printf("***************************************************\n");
		printf("**Step-by-step character counter of a given file.**\n");
		printf("***************************************************\n");

		/* Check the number of arguments passed through
		   the command line. */
		if (int_argc==TWO_VALUE)
			{
				/* Open the file indicated by argument #1. */
				strcpy(str_FileNameCounting,ch_argv[ONE_VALUE]);

				/* Call the function that counts the characters
				   of file and display them on the screen. */
				lng_counter_bytes=CounterBytes(str_FileNameCounting);
			}
		else
			{
				/* Request the user to capture the name and path
				   of file to show up. */
				printf("Enter the path and name of the file to track: ");

				if (scanf("%s", str_FileNameCounting))
					{
						/* Call the function 'CounterBytes' to count
						character by character until EOF. */
						lng_counter_bytes=CounterBytes \
						                 (str_FileNameCounting);
					}
			}

		/* Pause message to close the program. */
		getpause("\nThis program has ended successfully." \
				 "\nPress the ENTER key to finish it...");

		return(lng_counter_bytes);
	}
