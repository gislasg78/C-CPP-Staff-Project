/* Program that generates various containers. */

/* Standard work libraries. */
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

/* Symbolic work constants. */
#define	V_EIGHT	8
#define	V_FIVE	5
#define	V_FOUR	4
#define	V_NINE	9
#define V_ONE   1
#define	V_SEVEN	7
#define	V_SIX	6
#define	V_THREE	3
#define	V_TWO	2
#define V_ZERO  0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		auto fn_cmp = [&](int x, int y){return x < y;};
		int counter = V_ZERO;

		/* Creating a vector, list, stack, queue, priority_queue and set. */
		std::vector<int> myVector = {V_EIGHT, V_ONE, V_SIX, V_FOUR, V_ZERO, V_SEVEN, V_TWO, V_NINE, V_FIVE, V_THREE};
		std::list<int> myList;
		std::deque<int> myDeq {};
		std::stack<int> myS;
		std::queue<int> myQ;
		std::priority_queue<int> myPQL = {};
		std::priority_queue<int, std::vector<int>, std::greater<int>> myPQG {};
		std::priority_queue<int, std::vector<int>, decltype(fn_cmp)> myPQ(fn_cmp);
		std::set<int> mySet;
		std::map<int, int> myMap;

		/* Main header message. */
		std::cout << "Vectors and priority queues." << std::endl;

		/* Flip the vector. */
		std::cout << std::endl << "Dumping of vector." << std::endl;
		for (std::vector<int>::const_iterator itc_myVec = myVector.cbegin(); itc_myVec != myVector.cend(); itc_myVec++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myVec << "}." << std::endl;

				/* Sequence containers. */
				myList.push_back(*itc_myVec);
				myDeq.push_back(*itc_myVec);
				myS.push(*itc_myVec); myQ.push(*itc_myVec);
				myPQ.push(*itc_myVec); myPQL.push(*itc_myVec); myPQG.push(*itc_myVec);

				/* Associative containers. */
				mySet.insert(*itc_myVec);
				myMap.insert(std::pair<int, int>(counter, *itc_myVec));
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the list. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of list." << std::endl;
		for (std::list<int>::const_iterator itc_myList = myList.cbegin(); itc_myList != myList.cend(); itc_myList++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myList << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the deque. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of deque." << std::endl;
		for (std::deque<int>::const_iterator itc_myDeq = myDeq.cbegin(); itc_myDeq != myDeq.end(); itc_myDeq++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myDeq << "}." << std::endl;
			}

		/* Display the stack. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of stack." << std::endl;
		while (!myS.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myS.top() << "}." << std::endl;
				myS.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the queue. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of queue." << std::endl;
		while (!myQ.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myQ.front() << "}." << std::endl;
				myQ.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the first priority queue (from highest to lowest order). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of first priority queue (least)." << std::endl;
		while (!myPQL.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myPQL.top() << "}." << std::endl;
				myPQL.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the second priority queue (from lowest to highest order). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of second priority queue (greatest)." << std::endl;
		while (!myPQG.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myPQG.top() << "}." << std::endl;
				myPQG.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the third priority queue (from owner lambda function). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of third priority queue (owner)." << std::endl;
		while (!myPQ.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myPQ.top() << "}." << std::endl;
				myPQ.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the set. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of set." << std::endl;
		for (std::set<int>::const_iterator itc_mySet = mySet.cbegin(); itc_mySet != mySet.cend(); itc_mySet++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_mySet << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the map. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of map." << std::endl;
		for (std::map<int, int>::const_iterator itc_myMap = myMap.cbegin(); itc_myMap != myMap.cend(); itc_myMap++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << itc_myMap->first << "} = [" << itc_myMap->second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		return V_ZERO;
	}
