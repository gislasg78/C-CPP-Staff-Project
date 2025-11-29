/* Testing values: 1; 5, 3; 2, 1, 7, 4, 2; */

#include <iostream>
#include <set>

#define V_TWO   2
#define V_ZERO  0

int main()
	{
		int t = V_ZERO;

		std::cout << "Calculating the amount of candy for a monkey." << std::endl;
		std::cout << "T number: ";
		std::cin >> t;

		while (t--)
			{
				int k = V_ZERO, n = V_ZERO;

				std::cout << "Number of bags for candy: ";
				std::cin >> n;
				std::cout << "Final reduced quantity of bags: ";
				std::cin >> k;

				std::multiset<int> bags;

				std::cout << std::endl << "Capture the amount of candy per bag." << std::endl;
				for (int idx = V_ZERO; idx < n; idx++)
					{
						int candy_count = V_ZERO;
						std::cout << "Candies for bag #: [" << idx << "] of: [" << n << "]: ";
						std::cin >> candy_count;
						bags.insert(candy_count);
					}

				int total_candies = V_ZERO;

				for (int idx = V_ZERO; idx < k; idx++)
					{
						auto last_it = --bags.end();
						int candy_count = *last_it;
						total_candies += candy_count;

						bags.erase(last_it);
						bags.insert(candy_count / V_TWO);
					}

				std::cout << std::endl << "Total candies: [" << total_candies << "]." << std::endl;
			}

		return V_ZERO;
	}
