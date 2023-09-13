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
 ** Input Parms:	T *ptr_t_left_value,			**
 **			T *ptr_t_right_value.			**
 ** Outputt Parms:	T *ptr_t_left_value,			**
 **			T *ptr_t_right_value.			**
 ** Result:		This function primarily swaps the values**
 **			of two variables passed as current	**
 **			parameters and returns them in the same **
 **			way in the same variables.		**
 ****************************************************************/
template <typename T>
void swapper(T *ptr_t_left_value, T *ptr_t_right_value)
	{
		T t_aux_value, *ptr_t_aux_value=&t_aux_value;

		/*------------------------------------------------
		 * Variables occupying an intermediate temporary--
		 * variable in the scope of this function are	--
		 * swapped.					--
		 *----------------------------------------------*/
		*ptr_t_aux_value = *ptr_t_left_value;
		*ptr_t_left_value = *ptr_t_right_value;
		*ptr_t_right_value = *ptr_t_aux_value;
	}

/*****************************************************************
 ** Function:		swapper.				**
 ** Explanation:	This function doesn't actually return	**
 **			any value, it just swaps two variables	**
 **			that are passed to that function as	**
 **			formal parameters in its function header**
 **			and swaps them between them, so it uses	**
 **			a template and references to the memory	**
 **			addresses of said variables.		**
 ** Input Parms:	T &t_left_value,			**
 **			T &t_right_value.			**
 ** Outputt Parms:	T &t_left_value,			**
 **			T &t_right_value.			**
 ** Result:		This function primarily swaps the values**
 **			of two variables passed as current	**
 **			parameters and returns them in the same **
 **			way in the same variables.		**
 ****************************************************************/
template <typename T>
void swapper (T &t_left_value, T &t_right_value)
	{
		T t_aux_value;	//Template' variable declaration.

		/*------------------------------------------------
		 * Variables occupying an intermediate temporary--
		 * variable in the scope of this function are	--
		 * swapped.					--
		 *----------------------------------------------*/
		t_aux_value = t_left_value;
		t_left_value = t_right_value;
		t_right_value = t_aux_value;
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
		float flt_t_val_x=V_ZERO, flt_t_val_y=V_ZERO;

		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "|     Change of place of any values.    |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "Enter two numeric values:" << endl;
		cout << "Value [x] : ";
		cin >> flt_t_val_x;
		cout << "Value [y] : ";
		cin >> flt_t_val_y;

		/* Messages before the exchange of values. */
		cout << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "|Starting initials. Before the exchange.|" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << endl;
		cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---|\n" << endl ;

		swapper(flt_t_val_x, flt_t_val_y); //First Function that swaps variables.

		/* Messages after the exchange of values. */
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Values exchanged. After the exchange. |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << endl;
		cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << endl;

		swapper(&flt_t_val_x, &flt_t_val_y); //Second Function that swaps variables.

		/* Value restore messages. */
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "|       Restoring initial values.       |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << endl;
		cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---|" << endl;
		cout << endl;

		return V_ZERO;
	}
