/****** Exchange values between any two variables in C++. ********
 ** Source Code:	SwapVals.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
 ** Purpose:		This program uses a function that uses	**
 **			templates in its formal parameters and	**
 **			that specifically takes care of		**
 **			swapping any two values and returning	**
 **			them inverted.				**
*****************************************************************/
//C Standard Libraries.
#include <iostream>
#include <stdio.h>

//Work Symbolic Constants.
#define V_ZERO	0

//Using the namespace 'std'.
using namespace	std;

/*****************************************************************
 ** Function:		swapper.				**
 ** Explanation:	This function doesn't actually return	**
 **			any value, it just swaps two variables	**
 **			that are passed to that function as	**
 **			formal parameters in its function header**
 **			and swaps them between them, so it uses	**
 **			a template and references to the memory	**
 **			addresses of said variables.		**
 ** Input Parms:	T &left_value,				**
 **			T &right_value.				**
 ** Outputt Parms:	T &left_value,				**
 **			T &right_value.				**
 ** Result:		This function primarily swaps the values**
 **			of two variables passed as current	**
 **			parameters and returns them in the same **
 **			way in the same variables.		**
 ****************************************************************/
template <typename T>
void swapper (T &left_value, T &right_value)
	{
		T temp_value;	//Template' variable declaration.

		/*------------------------------------------------
		 * Variables occupying an intermediate temporary--
		 * variable in the scope of this function are	--
		 * swapped.					--
		 *----------------------------------------------*/
		temp_value = left_value;
		left_value = right_value;
		right_value = temp_value;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function of this program shows	**
 **			a series of messages before and after	**
 **			calling a generic function that		**
 **			exchanges the values contained in two	**
 **			variables and shows their respective	**
 **			results before and after the operation	**
 **			executed by said exchange function.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The main function, itself, just displays**
 **			a series of messages before and after	**
 **			exchanging the value of two		**
 **			user-supplied variables.		**
 ****************************************************************/
int main()
	{
		/* Initialization of preliminary variables. */
		float t_val1 = V_ZERO, t_val2 = V_ZERO;

		cout << "+---|----+---|----+---|----+---|" << endl;
		cout << "|Change of place of any values.|" << endl;
		cout << "+---|----+---|----+---|----+---|" << endl;

		cout << "Enter two numeric values:" << endl;
		cout << "First  Value : ";
		cin >> t_val1;
		cout << "Second Value : ";
		cin >> t_val2;

		/* Messages before the exchange of values. */
		cout << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "|Starting initials. Before the exchange.|" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Left  value : [" << &t_val1 << "] = [" << t_val1 << "]." << endl;
		cout << "| Right value : [" << &t_val2 << "] = [" << t_val2 << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---+\n" << endl ;

		swapper(t_val1, t_val2); //Function that swaps variables.

		/* Messages after the exchange of values. */
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Values exchanged. After the exchange. |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Left  value : [" << &t_val1 << "] = [" << t_val1 << "]." << endl;
		cout << "| Right value : [" << &t_val2 << "] = [" << t_val2 << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << endl;

		swapper(t_val1, t_val2); //Function that swaps variables.

		/* Value restore messages. */
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Restoring initial values.             |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Left  value : [" << &t_val1 << "] = [" << t_val1 << "]." << endl;
		cout << "| Right value : [" << &t_val2 << "] = [" << t_val2 << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << endl;

		return V_ZERO;
	}
