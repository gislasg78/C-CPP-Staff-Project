#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FD_READ		0
#define FD_WRITE	1

#define	V_MINUS_ONE	-1

#define	V_ONE		1
#define	V_TWO		2
#define	V_ZERO		0

/* Writing thread. */
void *thread1 (void *p)
	{
		int fd = V_ZERO;
		char message[] = "Greetings from Thread '1'!";

		fd = *(int *) p;

		write(fd, message, strlen(message) + V_ONE);

		return (NULL);
	}

/* Reading thread. */
void *thread2 (void *p)
	{
		int fd = V_ZERO;
		char buffer[BUFSIZ];

		fd = *(int *) p;

		read(fd, buffer, BUFSIZ);
		printf("Thread '2' received: [%s].\n", buffer);

		return (NULL);
	}

int main()
	{
		int fp[V_TWO] = {V_ZERO, V_ZERO};
		pthread_t thd;
		int p = V_ZERO, r1 = V_ZERO, r2 = V_ZERO;

		/* Create a pipe. */
		if(((p = pipe(fp)) == V_MINUS_ONE))
			{
				perror("Pipe");
				exit(V_ONE);
			}

		/* Spawn the first thread and the read end of the pipe. */
		r1 = pthread_create(&thd, NULL, thread1, (void *) &fp[FD_WRITE]);

		/* Spawn the second thread and the write end of the pipe. */
		r2 = pthread_create(&thd, NULL, thread2, (void *) &fp[FD_READ]);

		if( r1 != V_ZERO || r2 != V_ZERO )
			{
				perror("Thread");
				exit(V_ONE);
			}

		/* Wait here. */
		puts("Done!");
		puts("Press the ENTER key to continue...");
		getchar();

		return(V_ZERO);
	}
