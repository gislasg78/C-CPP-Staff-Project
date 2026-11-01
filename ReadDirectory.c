/* The purpose of this program is to read information from a file and a directory,
   respectively, extracting the most essential and specific content from each. */

/* Standard Work Libraries. */
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

/* Symbolic Work Constants. */
#define	V_ZERO	0

//Main function.
int main()
{
	/* Preliminary Working Variables. */
	DIR *directory = NULL;

	static char s_directory[BUFSIZ];
	static char s_filename[BUFSIZ];
	static char s_path[BUFSIZ];

	struct dirent *file = NULL;
	struct stat fstat;

	size_t counter = V_ZERO;
	time_t t_elapsed_seconds = time(&t_elapsed_seconds);

	/* Display the current working directory. */
	getcwd(s_path, sizeof(s_path));
	printf("Display the current working directory.\n");
	printf("\'%s\'\n", s_path);

	/* Code block for obtaining information from a given file. */
	printf("\nObtaining information from files.\n");
	printf("Type a filename: ");
	scanf("%[^\n]%*c", s_filename);

	stat(s_filename, &fstat);

	printf("\nFile information read.\n");
	printf("%s", ctime(&t_elapsed_seconds));
	printf("%s is %ld bytes long.\n", s_filename, fstat.st_size);
	printf("It was modified on %s", ctime(&fstat.st_mtime));

	/* Code block for retrieving information from a specific directory. */
	t_elapsed_seconds = time(&t_elapsed_seconds);

	printf("\nObtaining information from directories.\n");
	printf("Type a directory: ");
	scanf("%[^\n]%*c", s_directory);

	printf("\nDirectory information read.\n");
	printf("%s", ctime(&t_elapsed_seconds));

	/* A loop that ensures the files contained in a specific directory are read. */
	if ((directory = opendir(s_directory)))
	{
		while ((file = readdir(directory)))
		{
			stat(file->d_name, &fstat);

			printf("\n");
			printf("# %lu.\n", counter++);
			printf("* File: %s\n", file->d_name);
			printf("+ Type: %s.\n", (S_ISDIR(fstat.st_mode)) ? "Directory" : "File");
			printf("+ Size: %ld bytes long.\n", fstat.st_size);
			printf("+ It was modified on %s\n", ctime(&fstat.st_mtime));
		}

		printf("[%lu] Output results generated.\n", counter);

		closedir(directory);
	}

	/* Program termination messages. */
	printf("\nDone!\n");
	printf("This program has ended.\n");

	return V_ZERO;
}
