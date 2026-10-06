#include <stdio.h>

#define V_ZERO  0

void begin() __attribute__ ((constructor));
void end() __attribute__ ((destructor));

int main()
	{
		printf("Hello World!\n");

		return V_ZERO;
	}

void begin()
	{
		printf("Starting the program...\n");
	}

void end()
	{
		printf("Finishing the program...\n");
	}
