/********* Arabic numerals to Roman numerals converter. **********
 ** Source Code:        RomainNm.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		The primary purpose of this program is	**
 **			to convert an Arabic numeral to a Roman	**
 **			numeral, understanding that Roman	**
 **			numerals have limitations in their	**
 **			literal representation.			**
 **			In this way, successive divisions are	**
 **			made and the residues among the ten are	**
 **			obtained, in order to extract each term	**
 **			individually and assign it its		**
 **			corresponding literal.			**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				1767, 2024, 4617, 8678, 9999.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//C Standard Constants.
#define	V_EIGHT			8
#define V_FOUR			4
#define	V_TEN			10
#define	V_ZERO			0

//Storage character buffer length.
#define	V_LENGTH_BUFFER		15

//Working limit constants.
#define	V_LOWER_LIMIT_QTY	0
#define V_LOWER_LIMIT_RMNB	0
#define	V_UPPER_LIMIT_QTY	9999
#define V_UPPER_LIMIT_RMNB	3

//Constant character literals with the value information in Romans.
const char str_Labels[V_FOUR][V_TEN][V_EIGHT] = {
	{"\0", "I\0", "II\0", "III\0", "IV\0", "V\0", "VI\0", "VII\0", "VIII\0", "IX\0"},
	{"\0", "X\0", "XX\0", "XXX\0", "XL\0", "L\0", "LX\0", "LXX\0", "LXXX\0", "XC\0"},
	{"\0", "C\0", "CC\0", "CCC\0", "CD\0", "D\0", "DC\0", "DCC\0", "DCCC\0", "CM\0"},
	{"\0", "M\0", "MM\0", "MMM\0", "_IV_\0", "_V_\0", "_VI_\0", "_VII_\0", "_VIII_\0", "_IX_\0"}
};

/*****************************************************************
 ** Function:		int int_toRomainNumber			**
 **				(int int_value,			**
 **				 char buffer[]);		**
 ** Explanation:	This function covers the purpose of	**
 **			converting an integer to a Roman	**
 **			numeral, performing a series of		**
 **			successive divisions between the ten	**
 **			and obtaining a remainder in each step,	**
 **			in such a way that said remainder is	**
 **			equivalent to a table of literals with	**
 **			the values in Roman numerals, and	**
 **			subsequently, each value equivalent is	**
 **			concatenated until the representation	**
 **			of an Arabic numeral to a Roman numeral	**
 **			is obtained.				**
 ** Input Parms:	int int_value,				**
 **			char buffer[].				**
 ** Output Parms:	char buffer[].				**
 ** Result:		In the name of the function itself, it	**
 **			returns as a result the length that	**
 **			contains the number of characters that	**
 **			were effectively concatenated to convert**
 **			an Arabic value to a Roman value.	**
 ****************************************************************/
int int_toRomainNumber(int int_value, char buffer[])
	{
		/* Initial declaration of work variables. */
		int int_data = int_value;
		int int_pos_buffer = V_ZERO;
		int int_t_place_value_chart[V_FOUR] = {V_ZERO, V_ZERO, V_ZERO, V_ZERO};

		/* Conversion information messages. */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+Arabic to Roman conversion results.+\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("|         Place Value Chart.        +\n");
		printf("+---|----+---|----+---|----+---|----+\n");

		/* Calculate and group each value in the place value table. */
		for (int int_idx = V_LOWER_LIMIT_RMNB; int_idx <= V_UPPER_LIMIT_RMNB; int_idx++)
			{
				/* Arithmetic operations to extract each digit. */
				int_t_place_value_chart[int_idx] = int_value % V_TEN;
				int_value /= V_TEN;

				/* Validate that a given digit is not zero. */
				if (int_t_place_value_chart[int_idx])
					printf("| Row: [%d], Column: [%d] = Value: [%s].\n", int_idx, int_t_place_value_chart[int_idx], str_Labels[int_idx][int_t_place_value_chart[int_idx]]);
			}

		/* Intermediation message. */
		printf("+--------+--------+--------+--------+\n");
		printf("|       Positional gradient.        +\n");
		printf("+--------+--------+--------+--------+\n");

		/* Dump and concatenation of the new character string with Roman numerals. */
		for (int int_ind = V_UPPER_LIMIT_RMNB; int_ind >= V_LOWER_LIMIT_RMNB; int_ind--)
			{
				/* Concatenate each literal according to the extracted digit. */
				int_pos_buffer += sprintf(buffer + int_pos_buffer, "%s", str_Labels[int_ind][int_t_place_value_chart[int_ind]]);

				/* Validate that a given digit is not zero. */
				if (int_t_place_value_chart[int_ind])
					printf("| Row: [%d], Column: [%d] = Value: [%s].\n", int_ind, int_t_place_value_chart[int_ind], str_Labels[int_ind][int_t_place_value_chart[int_ind]]);
			}

		/* Final closing information. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|     Obtained output results.      +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Length:\t[%d].\n", int_pos_buffer);
		printf("| Romain:\t[%s].\n", buffer);
		printf("| Value :\t[%d].\n", int_data);
		printf("+===|====+===|====+===|====+===|====+\n");

		return int_pos_buffer;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function, the function in	**
 **			charge of converting Arabic numerals to	**
 **			Roman numerals is called, extracting by	**
 **			means of residues and successive	**
 **			divisions by ten, each significant	**
 **			figure of the digits that make up the	**
 **			quantity to be converted, and for each	**
 **			extraction a search is made in a table	**
 **			of non-numeric literals such as each	**
 **			extracted digit must be transformed	**
 **			into its equivalent Roman numeral	**
 **			representation.				**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				1767, 2024, 4617, 8678, 9999.	**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		static char buffer[V_LENGTH_BUFFER];
		int int_counting_chars = V_ZERO;
		int int_data = V_ZERO;

		/* Initial presentation messages. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ Convert Arabic to Roman numerals. +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Enter a number between [%d] & [%d] : ", V_LOWER_LIMIT_QTY, V_UPPER_LIMIT_QTY);
		scanf("%d", &int_data);

		/* Validation of allowed intervals. */
		if (int_data >= V_LOWER_LIMIT_QTY && int_data <= V_UPPER_LIMIT_QTY)
			int_counting_chars = int_toRomainNumber(int_data, buffer);
		else
			printf("Mistake! The value: [%d] is not in the range of [%d] and [%d].\n", int_data, V_LOWER_LIMIT_QTY, V_UPPER_LIMIT_QTY);

		return V_ZERO;
	}
