#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define	V_MINUS_ONE	-1
#define	V_ZERO		0

int main()
	{
		char template[] = "solution_XXXXXX";
		char newname[] = "solution1";
		int r = V_ZERO;

		/* Create a temporary file. */
		puts("Creating a temporary file.");

		if(((r = mkstemp(template)) == V_MINUS_ONE))
			{
				printf("Errno = [%d].\n", errno);
				perror("File creation error");
			}

		printf("File '%s' created!\n", template);

		/* Rename it! */
		printf("Renaming '%s' to '%s'.\n", template, newname);

		if(((r = rename(newname, template)) == V_MINUS_ONE))
			{
				printf("Errno = [%d].\n", errno);
				perror("Renaming error");
			}
		else
			{
				printf("File '%s' renamed to '%s'.\n", template, newname);
			}

		/* Delete it! */
		printf("Deleting file '%s'.\n", newname);

		if(((r = unlink(newname)) == V_MINUS_ONE))
			{
				printf("Errno = [%d].\n", errno);
				perror("Deleting error");
			}
		else
			{
				printf("File '%s' deleted!\n", newname);
			}

		return V_ZERO;
	}
