/**************** Generator of a character string. ***************
 ** Source Code:	Gets.c					**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, December 31, 2026.		**
 ** Purpose:		This program attempts to replace the	**
 **			old C function 'gets' with a custom	**
 **			prototype that takes as arguments the	**
 **			maximum number of characters to store	**
 **			in a character pointer and limits the	**
 **			string input until a specific output	**
 **			character is pressed.			**
*****************************************************************/
/* C Standard Libraries. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Work Symbolic Constants. */
#define V_ZERO			0
#define V_ONE			1

/* Symbolic Character Constants. */
#define CARRIAGE_RETURN		'\n'
#define NULL_CHARACTER		'\0'
#define	TABULATOR		'\t'

/*****************************************************************
 ** Function:		char *read_string			**
 **				(const size_t szt_num_chars,	**
 **				 char **ptr_chr_string,		**
 **				 size_t *const			**
 **					ptr_szt_idx_chars,	**
 **				const char chr_exit_char).	**
 ** Explanation:	In this function, a contiguous memory	**
 **			area is allocated for the character	**
 **			string and the length given by		**
 **			'szt_num_chars' plus the unit is	**
 **			calculated, through a loop that is	**
 **			responsible for obtaining the captured	**
 **			character and subsequently validating	**
 **			that it is different from a character	**
 **			output provided as an argument to the	**
 **			function.				**
 **			In this function, the array notation is	**
 **			used for the dynamically created pointer**
 **			and the notation itself is used for the	**
 **			given pointer.				**
 **			At the end of the character string,	**
 **			at position 'szt_num_chars' a null	**
 **			character is placed or added.		**
 ** Input Parms:	const size_t szt_num_chars,		**
 ** 			char **ptr_chr_string,			**
 **			size_t *const ptr_szt_idx_chars,	**
 **			const char chr_exit_char.		**
 ** Output Parms:	char **ptr_chr_string,			**
 **			size_t *const ptr_szt_idx_chars.	**
 ** Result:		Function 'gets' that returns a string of**
 **			characters, whose characters are in a	**
 **			contiguous region of memory defined by	**
 **			the user.				**
 **			They occupy or use local scope work	**
 **			variables within the function.		**
 ****************************************************************/
char *read_string(const size_t szt_num_chars, char **ptr_chr_string, size_t *const ptr_szt_idx_chars, const char chr_exit_char)
	{
		/* Preliminary working variables. */
		char *ptr_chr_new_str = NULL;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;
		size_t szt_idx_chars = V_ZERO;

		/* Validation cycle to assign captured characters to the allocated memory space. */
		if ((szt_num_chars < SIZE_MAX) && (ptr_chr_new_str = (char *) calloc((szt_num_chars + V_ONE), sizeof(char))))
			{
				/* The main, core loop for reading each character from the keyboard and storing it in the dynamically created buffer. */
				while ((((int_key = getchar()) != EOF) && (int_key != TABULATOR) && (int_key != chr_exit_char) && (szt_idx_chars < szt_num_chars)))
					ptr_chr_new_str[szt_idx_chars++] = (char) int_key;

				*(ptr_chr_new_str + szt_idx_chars) = NULL_CHARACTER;

				/* Get an incorrect entried value. */
				fputs("\nClearing the remainder of the input buffer...\n", stderr);
				fprintf(stderr, "Press ENTER to continue...");

				/* Proceed to clear all characters present in the buffer. */
				int_chars = V_ZERO;
				int_fields = scanf("%*[^\n]%*c%n", &int_chars);
				printf("\nFields: [%d]. Characters: [%d].\n", int_fields, int_chars);

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
		else
			perror("Insufficient memory space to accommodate the character pointer...");

		/* Return both the number of characters placed and the maximum storage length of the string. */
		if (ptr_chr_string) *ptr_chr_string = ptr_chr_new_str;
		if (ptr_szt_idx_chars) *ptr_szt_idx_chars = szt_idx_chars;

		/* Return the dynamically allocated and created pointer containing the requested string. */
		return ptr_chr_new_str;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function, what is sought is**
 **			for the user to enter by keyboard the	**
 **			number of characters that the memory	**
 **			area where the string will be stored	**
 **			will have, and subsequently, the user is**
 **			asked to enter each character that will	**
 **			be stored until finishing with car	**
 **			return.					**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The function returns as a result the	**
 **			information generated by the memory	**
 **			allocation to the string.		**
 **			Such information is its maximum length,	**
 **			its effective size, its memory address,	**
 **			its content and the delimiter used for	**
 **			this purpose.				**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		char *ptr_chr_new_str = NULL;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		size_t szt_idx_chars = V_ZERO;
		size_t szt_num_chars = V_ZERO;

		/* Information entry window. */
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("+    Generator of a character string.   +\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("+ String length : ");

		/* Validate the number of characters that the character string to be created must have. */
		if ((int_fields = scanf("%zu%*c%n", &szt_num_chars, &int_chars)) == V_ONE)
			{
				/* Get a correct entered value. */
				printf("\nFields: [%d]. Input value: [%zu]. Characters: [%d]. OK!\n", int_fields, szt_num_chars, int_chars);

				/* The character string is captured, character by character, into a dynamic buffer. */
				putchar(CARRIAGE_RETURN);
				puts("Capture and storage of the characters in your string.");
				printf("+ Text string   : ");

				/* Validate the creation of the new character string. */
				if ((ptr_chr_new_str = read_string(szt_num_chars, &ptr_chr_new_str, &szt_idx_chars, CARRIAGE_RETURN)))
					{
						/* Obtaining the exact number of characters with which the string will be created. */
						printf("\n");
						printf("+===|====+===|====+===|====+===|====+===|\n");
						printf("| General information about the string. |\n");
						printf("+===|====+===|====+===|====+===|====+===|\n");
						printf("|       Target output variables.        |\n");
						printf("+---|----+---|----+---|----+---|----+---|\n");
						printf("| Length  : <%p> = {%zu}.\n", (void *) (&szt_idx_chars), szt_idx_chars);
						printf("| Maximum : <%p> = {%zu}.\n", (void *) (&szt_num_chars), szt_num_chars);
						printf("+---|----+---|----+---|----+---|----+---|\n");
						printf("|     Target mapping string pointer.    |\n");
						printf("+---|----+---|----+---|----+---|----+---|\n");
						printf("| Address : <%p>.\n", (void *) (&ptr_chr_new_str));
						printf("| Pointer : <%p>.\n", (void *) ptr_chr_new_str);
						printf("| Content : {%s}.\n", ptr_chr_new_str);
						printf("+===|====+===|====+===|====+===|====+===|\n");

						/* Character-by-character dump of the created character string. */
						printf("\n");
						printf("+===|====+===|====+===|====+===|====+===|\n");
						printf("|Dump the string character by character.|\n");
						printf("+===|====+===|====+===|====+===|====+===|\n");

						/* Character-by-character dumping cycle. */
						for (size_t szt_idx_char = V_ZERO; szt_idx_char < szt_idx_chars; szt_idx_char++)
							printf("# (%zu)\t:\t<%p>\t=\t{%c}.\n", szt_idx_char, (void *) (ptr_chr_new_str + szt_idx_char), *(ptr_chr_new_str + szt_idx_char));

						printf("[%zu] Obtained output results.\n", szt_idx_chars);

						/* Free memory area that stores the pointer to the created character string. */
						fputs("\nClearing the character string from dynamic memory...\n", stderr);
						free(ptr_chr_new_str);
						ptr_chr_new_str = NULL;
					}
				else
					fprintf(stderr, "Insufficient memory space to accommodate the character pointer!\n");
			}
		else
			fprintf(stderr, "\nError while capturing the length of the requested string!\n");

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
