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
		T t_aux_value;	//Template variable declaration.

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
		float flt_t_val_x = V_ZERO;
		float flt_t_val_y = V_ZERO;
		float *ptr_flt_t_val_x = &flt_t_val_x;
		float *ptr_flt_t_val_y = &flt_t_val_y;

		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|     Change of place of any values.    |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "Enter two numeric values:" << std::endl;
		std::cout << "Value [x] : ";
		std::cin >> flt_t_val_x;
		std::cout << "Value [y] : ";
		std::cin >> flt_t_val_y;

		/* Messages before the exchange of values. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|Starting initials. Before the exchange.|" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << std::endl;
		std::cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|\n" << std::endl ;

		swapper(flt_t_val_x, flt_t_val_y);		//First Function that swaps variables.

		/* Messages after the exchange of values. */
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Values exchanged. After the exchange. |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << std::endl;
		std::cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << std::endl;

		swapper(&flt_t_val_x, &flt_t_val_y);		//Second Function that swaps variables.

		/* Value restore messages. */
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|       Restoring initial values.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << std::endl;
		std::cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << std::endl;

		swapper(ptr_flt_t_val_x, ptr_flt_t_val_y);	//Third Function that swaaps variables.

		/* Messages after the new exchange of values. */
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|    Values exchanged. New exchange.    |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << std::endl;
		std::cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << std::endl;

		swapper(*ptr_flt_t_val_x, *ptr_flt_t_val_y);	//Fourth Function that swaaps variables.

		/* Again value restore messages. */
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|    Again restoring initial values.    |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &flt_t_val_x << "] = [" << flt_t_val_x << "]." << std::endl;
		std::cout << "| Value [y] : [" << &flt_t_val_y << "] = [" << flt_t_val_y << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << std::endl;

		return V_ZERO;
	}
