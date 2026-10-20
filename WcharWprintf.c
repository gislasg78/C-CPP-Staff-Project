#include <locale.h>
#include <wchar.h>

#define V_CHAR_DIGIT_ONE	'\x31'
#define	V_CHAR_DIGIT_TWO	'\x32'
#define	V_CHAR_DIGIT_THREE	'\x33'
#define	V_SET_LOCALE		"en_US.UTF-8"

#define SAD			0x1f641
#define HAPPY			0x1f600
#define MEH			0x1f610
#define HUH			0x1f914

#define	V_ONE			1
#define V_THREE			3
#define V_ZERO			0

int main()
	{
		wchar_t mood[V_THREE] = { SAD, HAPPY, MEH };
		wchar_t *moodstr[V_THREE] = { L"sad", L"happy", L"meh" };
		int x = V_ZERO;
		wint_t m = V_ZERO;

		setlocale(LC_ALL, V_SET_LOCALE);

		/* Prompt for input */
		wprintf(L"What is your mood?\n");
		for(x = V_ZERO; x < V_THREE; x++)
			wprintf(L"%d: %lc %ls\n", x + V_ONE, mood[x], moodstr[x]);

		wprintf(L"Choice: ");
		m = getwchar();

		/* Output the choice */
		switch (m)
			{
				case V_CHAR_DIGIT_ONE:
					wprintf(L"%lc Sad\n", SAD);
					break;

				case V_CHAR_DIGIT_TWO:
					wprintf(L"%lc Happy\n", HAPPY);
					break;

				case V_CHAR_DIGIT_THREE:
					wprintf(L"%lc Meh\n", MEH);
					break;

				default:
					wprintf(L"%lc Huh?\n", HUH);
			}

		return V_ZERO;
	}
