/*  Immediately Next Greater Element using Stacks.
    Testing values: 6: {4, 5, 2, 25, 7, 8}. */

/* Libraries Standards of Work. */
#include <iostream>
#include <stack>
#include <vector>

/* Symbolic work constants. */
#define V_MINUS_ONE	-1
#define V_ONE		1
#define V_ZERO		0

/* Function that calculates the inmediately nearest larger elements. */
const std::vector<int> NGE(const std::vector<int>& v)
	{
		std::stack<int> st;
		std::vector<int> nge(v.size());

		for (size_t idx = V_ZERO; idx < v.size(); idx++)
			{
				while(!st.empty() && v[idx] > v[st.top()])
					{
						nge[st.top()] = idx;
						st.pop();
					}

				st.push(idx);
			}

		while (!st.empty())
			{
				nge[st.top()] = V_MINUS_ONE;
				st.pop();
			}

		return nge;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int numbers = V_ZERO;

		std::cout << "Inmediately Next Greater Element." << std::endl;
		std::cout << "Quantity: ";
		std::cin >> numbers;

		/* Creation of the vector that will store the values ​​to be determined. */
		std::vector<int> v(numbers);

		std::cout << std::endl << "Capture the elements." << std::endl;
		for (int idx = V_ZERO; idx < numbers; idx++)
			{
				std::cout << "Enter the element #: [" << idx + V_ONE << "] of [" << numbers << "]: ";
				std::cin >> v[idx];
			}

		/* Vector that will store the index positions of each value determined to be the inmediately largest. */
		std::vector<int> nge = NGE(v);

		std::cout << std::endl << "Inmediately Next Greater Elements List." << std::endl;
		for (int idx = V_ZERO; idx < numbers; idx++)
			{
				std::cout << "[" << v[idx] << "] = [" << (nge[idx] == V_MINUS_ONE ? V_MINUS_ONE : v[nge[idx]]) << "].\t";
			}
		std::cout << std::endl;

		return V_ZERO;
	}
