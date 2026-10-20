#include <locale.h>
#include <monetary.h>
#include <stdio.h>
#include <string.h>

#define V_AMOUNT	123456.78
#define	V_SET_LOCALE	"Spanish"

#define	V_THIRTY_TWO	32
#define	V_ZERO		0

int main()
	{
		char *r = NULL;
		const double amount = V_AMOUNT;
		const size_t size = V_THIRTY_TWO;

		char buffer[size];
		memset(buffer, V_ZERO, size);

		if ((r = setlocale(LC_ALL, V_SET_LOCALE)))
			{
				fprintf(stderr, "Unable to set locale!\n");
			}
		else
			{
				strfmon(buffer, size, "%n", amount);
				puts(buffer);
			}

		return V_ZERO;
	}
