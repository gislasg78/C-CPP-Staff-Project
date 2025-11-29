/* Monk and the Magical Candy Bags.
	Imagine a monk named Monk who has a bag of candy.
	On each turn, Monk can choose a bag of candy, and the number of candies in that bag is halved
	(rounded down if odd).
	Furthermore, Monk can repeatedly choose bags with more candy until a certain number of operations have been performed.

	The task is to maximize the amount of candy Monk can obtain after performing 'k' operations
	(where in each operation a bag is chosen, one candy is taken from it, and then the number of candies is halved).
	Monk initially has 'n' bags of candy with different quantities.
*/

/* Standard work libraries. */
#include <iostream>
#include <queue>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_TWO	2
#define	V_ZERO	0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int number_of_bags = V_ZERO, number_of_operations = V_ZERO;

		/* Initial presentation messages. */
		std::cout << "Monk and the Magical Candy Bags." << std::endl;
		std::cout << "Bags: ";
		std::cin >> number_of_bags;		/* N = number of bags. */
		std::cout << "Operations: ";
		std::cin >> number_of_operations;	/* K = number of operations. */

		/* Definition of the ascending priority queue. */
		std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

		/* We read the quantities of candy in each bag. */
		std::cout << std::endl << "Amount of candy per bag." << std::endl;
		for (int idx = V_ZERO; idx < number_of_bags; idx++)
			{
				int number_of_candies = V_ZERO;
				std::cout << "Sweets for bag #: [" << idx + V_ONE << "] of: [" << number_of_bags << "]: ";
				std::cin >> number_of_candies;
				maxHeap.push(number_of_candies);	/* We insert each quantity of candies into the maxHeap. */
			}

		int totalCandies = V_ZERO;

		/* We perform 'k' number of operations. */
		for (int idx = V_ZERO; idx < number_of_operations; idx++)
			{
				/* We extract the maximum (the bag with the most candy). */
				int maxCandies = maxHeap.top();
				maxHeap.pop();

				/* Monk takes a candy from the current or concurrent bag. */
				totalCandies += maxCandies;

				/* We reduced the amount of candy in this bag by half. */
				maxCandies /= V_TWO;

				/* We will reinsert the current bag with the new calculated amount of candy. */
				maxHeap.push(maxCandies);
			}

		/* The priority stack is emptied to display the current values. */
		int counter = V_ZERO;
		std::cout << std::endl << "Dumping the existing values." << std::endl;
		while (!maxHeap.empty())
			{
				std::cout << "#: [" << counter++ + V_ONE << "] = {" << maxHeap.top() << "}." << std::endl;
				maxHeap.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* We print the total number of candies that 'Monk' has taken in each operation 'k'. */
		std::cout << std::endl << "Total candies: [" << totalCandies << "]." << std::endl;

		return V_ZERO;
	}
