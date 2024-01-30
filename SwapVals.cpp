/****** Exchange values between any two variables in C++. ********
 ** Source Code:	SwapVals.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
 ** Purpose:		This program uses a function that uses	**
 **			templates in its formal parameters and	**
 **			that specifically takes care of		**
 **			swapping any two values and returning	**
 **			them inverted.				**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				Left  Value [x] : 100.		**
 **				Right Value [y] : 200.		**
 ****************************************************************/
//C Standard Libraries.
#include <iostream>
#include <stdio.h>

//Work Symbolic Constants.
#define V_ZERO	0


/*****************************************************************
 ** Function:		template <typename T> void swapper	**
 **				(T *ptr_t_left_value,		**
 **				 T *ptr_t_right_value).		**
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
		T t_aux_value, *ptr_t_aux_value = &t_aux_value;

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
 ** Function:		template <typename T> void swapper	**
 **				(T &t_left_value,		**
 **				 T &t_right_value).		**
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
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				Left  Value [x] : 100.		**
 **				Right Value [y] : 200.		**
 ****************************************************************/
int main()
	{
		/* Initialization of preliminary variables. */
		int int_t_left_value = V_ZERO;
		int int_t_right_value = V_ZERO;
		int *ptr_int_t_left_value = &int_t_left_value;
		int *ptr_int_t_right_value = &int_t_right_value;

		/* Incomings request window. */
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
                std::cout << "|     Change of place of any values.    |" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "Enter two numeric values:" << std::endl;
		std::cout << "Value [x] : ";
		std::cin >> int_t_left_value;
		std::cout << "Value [y] : ";
		std::cin >> int_t_right_value;


		/* Call to the function that only changes the values of the specified variables. */
		/* Messages before the exchange of values. */
		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "| Starting values. Before the exchange. |" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|         Source input variables.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &int_t_left_value << "] = [" << int_t_left_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << &int_t_right_value << "] = [" << int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|        Source mapping pointers.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &ptr_int_t_left_value << "]." << std::endl;
		std::cout << "| Value [x] : [" << ptr_int_t_left_value << "] = [" << *ptr_int_t_left_value << "]." << std::endl;
		std::cout << "|---+----+---+----+---+----+---+----+---|" << std::endl;
		std::cout << "| Value [y] : [" << &ptr_int_t_right_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << ptr_int_t_right_value << "] = [" << *ptr_int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;

		/* Messages after the exchange of values. */
		swapper(int_t_left_value, int_t_right_value);		//First Function that swaps variables.

		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "| Values exchanged. After the exchange. |" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|         Source input variables.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &int_t_left_value << "] = [" << int_t_left_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << &int_t_right_value << "] = [" << int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|        Source mapping pointers.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &ptr_int_t_left_value << "]." << std::endl;
		std::cout << "| Value [x] : [" << ptr_int_t_left_value << "] = [" << *ptr_int_t_left_value << "]." << std::endl;
		std::cout << "|---+----+---+----+---+----+---+----+---|" << std::endl;
		std::cout << "| Value [y] : [" << &ptr_int_t_right_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << ptr_int_t_right_value << "] = [" << *ptr_int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;

		/* Value restore messages. */
		swapper(&int_t_left_value, &int_t_right_value);		//Second Function that swaps variables.

		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|       Restoring initial values.       |" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|         Source input variables.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &int_t_left_value << "] = [" << int_t_left_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << &int_t_right_value << "] = [" << int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|        Source mapping pointers.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &ptr_int_t_left_value << "]." << std::endl;
		std::cout << "| Value [x] : [" << ptr_int_t_left_value << "] = [" << *ptr_int_t_left_value << "]." << std::endl;
		std::cout << "|---+----+---+----+---+----+---+----+---|" << std::endl;
		std::cout << "| Value [y] : [" << &ptr_int_t_right_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << ptr_int_t_right_value << "] = [" << *ptr_int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;


		/* Call to the function that only changes the pointers of the specified variables. */
		/* Messages before the exchange of values. */
		swapper(ptr_int_t_left_value, ptr_int_t_right_value);	//First Function that swaps pointers.

		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "| Values exchanged. After the exchange. |" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|         Source input variables.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &int_t_left_value << "] = [" << int_t_left_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << &int_t_right_value << "] = [" << int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|        Source mapping pointers.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &ptr_int_t_left_value << "]." << std::endl;
		std::cout << "| Value [x] : [" << ptr_int_t_left_value << "] = [" << *ptr_int_t_left_value << "]." << std::endl;
		std::cout << "|---+----+---+----+---+----+---+----+---|" << std::endl;
		std::cout << "| Value [y] : [" << &ptr_int_t_right_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << ptr_int_t_right_value << "] = [" << *ptr_int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;

		/* Value restore messages. */
		swapper(*ptr_int_t_left_value, *ptr_int_t_right_value);	//Second Function that swaps pointers.

		std::cout << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|       Restoring initial values.       |" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+===|" << std::endl;
		std::cout << "|         Source input variables.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &int_t_left_value << "] = [" << int_t_left_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << &int_t_right_value << "] = [" << int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|        Source mapping pointers.       |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "| Value [x] : [" << &ptr_int_t_left_value << "]." << std::endl;
		std::cout << "| Value [x] : [" << ptr_int_t_left_value << "] = [" << *ptr_int_t_left_value << "]." << std::endl;
		std::cout << "|---+----+---+----+---+----+---+----+---|" << std::endl;
		std::cout << "| Value [y] : [" << &ptr_int_t_right_value << "]." << std::endl;
		std::cout << "| Value [y] : [" << ptr_int_t_right_value << "] = [" << *ptr_int_t_right_value << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|" << std::endl;

		return V_ZERO;
	}
