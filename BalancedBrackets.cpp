/* Standard work libraries. */
#include <iostream>
#include <map>
#include <stack>

/* Symbolic work constants. */
#define	V_ANGLE_BRACKETS_OPEN	'\x3c'
#define	V_ANGLE_BRACKETS_CLOSE	'\x3e'
#define	V_BRACES_OPEN		'\x7b'
#define	V_BRACES_CLOSE		'\x7d'
#define	V_BRACKETS_OPEN		'\x5b'
#define	V_BRACKETS_CLOSE	'\x5d'
#define	V_PARENTHESES_OPEN	'\x28'
#define	V_PARENTHESES_CLOSE	'\x29'

/* Working numerical constants. */
#define	V_MINUS_FOUR	-4
#define	V_MINUS_ONE	-1
#define	V_MINUS_THREE	-3
#define	V_MINUS_TWO	-2
#define	V_FOUR		4
#define V_ONE		1
#define	V_THREE		3
#define	V_TWO		2
#define V_ZERO		0

/* Function that balances parentheses, brackets, braces, and angle brackets. */
const bool IsBalanced(const std::string& s)
	{
		std::map<char, int> symbols = {{V_PARENTHESES_OPEN, V_MINUS_FOUR}, {V_ANGLE_BRACKETS_OPEN, V_MINUS_THREE}, {V_BRACKETS_OPEN, V_MINUS_TWO}, {V_BRACES_OPEN, V_MINUS_ONE}, {V_PARENTHESES_CLOSE, V_FOUR}, {V_ANGLE_BRACKETS_CLOSE, V_THREE}, {V_BRACKETS_CLOSE, V_TWO}, {V_BRACES_CLOSE, V_ONE}};
		std::stack<int> st;

		for (const char& bracket : s)
			{
				if (symbols[bracket] < V_ZERO)
					{
						st.push(bracket);
					}
				else
					{
						if (st.empty()) return false;

						char top = st.top();
						st.pop();

						if (symbols[top] + symbols[bracket]) return false;
					}
			}

		if (st.empty()) return true;
		return false;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO, numbers = V_ZERO;

		std::cout << "Balanced Brackets Matching." << std::endl;
		std::cout << "Number of values: ";
		std::cin >> numbers;

		/* Introduction of each string of characters with parentheses. */
		std::cout << std::endl << "Capturing character strings with series of parentheses." << std::endl;
		for (int idx = V_ZERO; idx < numbers; idx++)
			{
				std::string s;
				std::cout << "Enter the string #: [" << counter++ + V_ONE << "] of: [" << numbers << "]: ";
				std::cin >> s;

				std::cout << "[" << std::boolalpha << IsBalanced(s) << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		return V_ZERO;
	}
