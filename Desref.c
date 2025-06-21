#include <stdio.h>

#define	V_EIGHT	8
#define	V_FIVE	5
#define V_FOUR	4
#define V_ONE	1
#define	V_SEVEN	7
#define V_SIX	6
#define	V_THREE	3
#define	V_TWO	2
#define V_ZERO  0

struct str_example
	{
		int x, y;
	} str_ex, *ptr_str_ex = &str_ex;

int main()
	{
		str_ex.x = V_ONE;
		str_ex.y = V_TWO;

		printf("[%d]\t:\t[%d].\n", ptr_str_ex->x, ptr_str_ex->y);

		ptr_str_ex->x = V_THREE;
		ptr_str_ex->y = V_FOUR;

		printf("[%d]\t:\t[%d].\n", str_ex.x, str_ex.y);

		(&str_ex)->x = V_FIVE;
		(&str_ex)->y = V_SIX;

		printf("[%d]\t:\t[%d].\n", ptr_str_ex->x, ptr_str_ex->y);

		(*ptr_str_ex).x = V_SEVEN;
		(*ptr_str_ex).y = V_EIGHT;

		printf("[%d]\t:\t[%d].\n", str_ex.x, str_ex.y);

		return V_ZERO;
	}
