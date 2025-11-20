/* Program that generates various C++ STL containers. */

/* Standard work libraries. */
#include <array>
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
#define	V_TEN	10
#define	V_THREE	3
#define	V_TWO	2
#define V_ZERO  0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		auto fn_cmp = [&](int x, int y){return x < y;};
		int counter = V_ZERO;

		/* Creating a arraym vector, list, stack, queue, priority_queue, set and map. */
		std::array<int, V_TEN> myArray = {V_EIGHT, V_ONE, V_SIX, V_FOUR, V_ZERO, V_SEVEN, V_TWO, V_NINE, V_FIVE, V_THREE};
		std::vector<int> myVector = {};
		std::list<int> myList {};
		std::deque<int> myDeq {};
		std::stack<int> myS;
		std::queue<int> myQ;
		std::priority_queue<int> myPQL = {};
		std::priority_queue<int, std::vector<int>, std::greater<int>> myPQG {};
		std::priority_queue<int, std::vector<int>, decltype(fn_cmp)> myPQ(fn_cmp);
		std::set<int> mySet;
		std::map<int, int> myMap;

		/* Main header message. */
		std::cout << "C++ STL library containers." << std::endl;

		/* Display de array. */
		std::cout << std::endl << "Dumping of array." << std::endl;
		for (std::array<int, V_TEN>::const_iterator itc_myArray = myArray.cbegin(); itc_myArray != myArray.cend(); itc_myArray++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myArray << "}." << std::endl;

				/* Sequence containers. */
				myVector.push_back(*itc_myArray);
				myList.push_back(*itc_myArray);
				myDeq.push_back(*itc_myArray);
				myS.push(*itc_myArray); myQ.push(*itc_myArray);
				myPQ.push(*itc_myArray); myPQL.push(*itc_myArray); myPQG.push(*itc_myArray);

				/* Associative containers. */
				mySet.insert(*itc_myArray);
				myMap.insert(std::pair<int, int>(counter, *itc_myArray));
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the vector. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of vector." << std::endl;
		for (std::vector<int>::const_iterator itc_myVec = myVector.cbegin(); itc_myVec != myVector.cend(); itc_myVec++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myVec << "}." << std::endl;
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
