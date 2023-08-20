/****************** Fibonacci Number Generator *******************
 ** Source Code:	Fibonacc.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, September 30, 2023.		**
 ** Purpose:		The purpose of this program is to	**
 **			generate a vector whose structure stores**
 **			the numbers used to calculate each	**
 **			record or series of Fibonacci numbers,	**
 **			and in this way, certain calculation	**
 **			records can be consulted to find out	**
 **			what the final Fibonacci number is given**
 **			a series of given terms with the pair of**
 **			initial values to consider.		**
 **								**
 **			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
*****************************************************************/
//C Standard Libraries.
#include <iostream>
#include <vector>

//Work Symbolic Constants.
#define	V_LIM_MIN	1
#define V_LIM_MAX	45
#define V_ZERO		0

//Using the standard space name.
using namespace std;

/*--------------------------------------------------------------**
 * Data structure that stores the generated calculation record	--
 * number, the first and second numbers and the sum of these	--
 * that are part of the generation of the Fibonacci series of	--
 * numbers.							--
 *--------------------------------------------------------------*/
struct strct_record_Fibonacci
	{
		int int_idx;
		int int_First_Number;
		int int_Second_Number;
		int int_Addition;
	};

/*****************************************************************
 ** Function:		vector<struct strct_record_Fibonacci>	**
 **			getVectorFiboSeries			**
 **				(const int int_Quantity,	**
 **				 const int int_First_Number,	**
 **				 const int int_Second_Number)	**
 ** Explanation:	This function's primary objective is to **
 **			generate a structure-type vector that	**
 **			stores the control fields for the	**
 **			generation of the Fibonacci number	**
 **			series through cycles and returns each	**
 **			record that was obtained from the	**
 **			calculation until the number of terms	**
 **			desired by the user is reached.		**
 ** Input Parms:	const int int_Quantity.			**
 **			const int int_First_Number.		**
 **			const int int_Second_Number.		**
 ** Output Parms:	None.					**
 ** Result:		The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
vector<struct strct_record_Fibonacci> getVectorFiboSeries(const int int_Quantity, const int int_First_Number, const int int_Second_Number)
	{
		struct strct_record_Fibonacci st_rec_Fibo = {V_ZERO};
		vector<struct strct_record_Fibonacci> vec_st_rec_Fibo;

		st_rec_Fibo.int_First_Number=int_First_Number;
		st_rec_Fibo.int_Second_Number=int_Second_Number;

		cout << endl;
		cout << "Generating the Fibonacci Series..." << endl;

		for (int int_idx=V_ZERO; int_idx<int_Quantity; int_idx++)
			{
				st_rec_Fibo.int_idx=int_idx;
				st_rec_Fibo.int_Addition=st_rec_Fibo.int_First_Number+st_rec_Fibo.int_Second_Number;

				vec_st_rec_Fibo.push_back(st_rec_Fibo);

				cout << "# [" << st_rec_Fibo.int_idx << "]:\t[" << st_rec_Fibo.int_First_Number << "]\t+\t[" << st_rec_Fibo.int_Second_Number << "]\t=\t[" << st_rec_Fibo.int_Addition << "]." << endl;

				st_rec_Fibo.int_First_Number=st_rec_Fibo.int_Second_Number;
				st_rec_Fibo.int_Second_Number=st_rec_Fibo.int_Addition;
			}

		cout << endl;

		return vec_st_rec_Fibo;
	};

/*****************************************************************
 ** Function:		viewVectorFiboSeries			**
 **			(vector<struct strct_record_Fibonacci	**
 **			 vec_st_rec_Fibo>			**
 ** Explanation:	The final goal of this procedure is to	**
 **			display the vector generated in the	**
 **			'getVectorFiboSeries' function returned **
 **			as an intrinsic part of its return	**
 **			value, and to display the message series**
 **			of the structure content stored in the	**
 **			vector of Fibonacci numbers by		**
 **			traversing an iterator.			**
 ** Input Parms:	vector<struct strct_record_Fibonacci	**
 **			 vec_st_rec_Fibo>			**
 ** Output Parms:	None.					**
 ** Result:		Returns each calculation record for the **
 **			generation of Fibonacci series numbers. **
 **								**
 ** 			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
void viewVectorFiboSeries(vector<struct strct_record_Fibonacci> vec_st_rec_Fibo)
	{
		vector<struct strct_record_Fibonacci>::iterator it_vec_st_rec_Fibo;

		cout << "Number of records calculated: [" << vec_st_rec_Fibo.size() << "]." << endl;

		for (it_vec_st_rec_Fibo=begin(vec_st_rec_Fibo); it_vec_st_rec_Fibo!=end(vec_st_rec_Fibo); it_vec_st_rec_Fibo++)
			cout << "# [" << it_vec_st_rec_Fibo->int_idx << "]:\t[" << it_vec_st_rec_Fibo->int_First_Number << "]\t+\t[" << it_vec_st_rec_Fibo->int_Second_Number << "]\t=\t[" << it_vec_st_rec_Fibo->int_Addition << "]." << endl;

		cout << endl;
	};

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function of this program	**
 **			requests three values: First, the number**
 **			of records that the series will contain:**
 **			Second, the first reference value;	**
 **			Third and last, the second reference	**
 **			value. With these current parameters,	**
 **			the functions 'getVectorFiboSeries' and	**
 **			'setVectorFiboSeries' will be called to	**
 **			observe the detailed calculations of	**
 **			each record of the Fibonacci series.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		This main function calls the		**
 **			aforementioned functions to calculate	**
 **			and display the structure vector that	**
 **			stores the unit records of the		**
 **			Fibonacci series, given a specified	**
 **			number of terms.			**
 **								**
 ** 			The calculation procedure is as follows:**
 **			x=0, y=1; sum from '0' to 'n':		**
 **				{z=x+y; x=y; y=z}.		**
 ****************************************************************/
int main()
	{
		vector<struct strct_record_Fibonacci> vec_st_rec_Fibo;

		int int_Quantity=V_ZERO;
		int int_First_Number=V_ZERO;
		int int_Second_Number=V_ZERO;

		cout<<"Numbers of Fibonacci to generate from [" << V_LIM_MIN << "] to [" << V_LIM_MAX << "]: ";
		cin>>int_Quantity;

		if (int_Quantity >= V_LIM_MIN && int_Quantity <= V_LIM_MAX)
			{
				cout<<"First  number: ";
				cin>>int_First_Number;

				cout<<"Second number: ";
				cin>>int_Second_Number;

				vec_st_rec_Fibo=getVectorFiboSeries(int_Quantity, int_First_Number, int_Second_Number);
				viewVectorFiboSeries(vec_st_rec_Fibo);
			}
		else
			cout << "The number [" << int_Quantity << "] is out of range from [" << V_LIM_MIN << "] to [" << V_LIM_MAX << "]." << endl;

		return V_ZERO;
	}
