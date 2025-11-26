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
#include <unordered_map>
#include <unordered_set>
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
		std::set<int> myASet; std::set<int, std::greater<int>> myDSet;
		std::unordered_set<int> myUSet;
		std::map<int, int> myAMap; std::map<int, int, std::greater<int>> myDMap;
		std::unordered_map<int, int> myUMap;

		/* Main header message. */
		std::cout << "C++ STL library containers." << std::endl;

		/* Display de array. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Array." << std::endl;
		for (const int& item : myArray)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Array." << std::endl;
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
				myDSet.insert(*itc_myArray);
				myASet.insert(*itc_myArray);
				myUSet.insert(*itc_myArray);
				myAMap.insert(std::pair<int, int>(counter, *itc_myArray));
				myDMap.insert(std::pair<int, int>(counter, *itc_myArray));
				myUMap.insert(std::pair<int, int>(counter, *itc_myArray));
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the vector. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Vector." << std::endl;
		for (const int& item : myVector)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Vector." << std::endl;
		for (std::vector<int>::const_iterator itc_myVec = myVector.cbegin(); itc_myVec != myVector.cend(); itc_myVec++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myVec << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the list. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of List." << std::endl;
		for (const int& item : myList)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "List." << std::endl;
		for (std::list<int>::const_iterator itc_myList = myList.cbegin(); itc_myList != myList.cend(); itc_myList++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myList << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the deque. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Deque." << std::endl;
		for (const int& item : myDeq)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Deque." << std::endl;
		for (std::deque<int>::const_iterator itc_myDeq = myDeq.cbegin(); itc_myDeq != myDeq.end(); itc_myDeq++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myDeq << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the stack. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Stack." << std::endl;
		while (!myS.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myS.top() << "}." << std::endl;
				myS.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the queue. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Queue." << std::endl;
		while (!myQ.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myQ.front() << "}." << std::endl;
				myQ.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the first Priority Queue (from highest to lowest order). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of first Priority Queue (least)." << std::endl;
		while (!myPQL.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myPQL.top() << "}." << std::endl;
				myPQL.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the second Priority Queue (from lowest to highest order). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of second Priority Queue (greatest)." << std::endl;
		while (!myPQG.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myPQG.top() << "}." << std::endl;
				myPQG.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the third Priority Queue (from owner lambda function). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of third Priority Queue (owner)." << std::endl;
		while (!myPQ.empty())
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << myPQ.top() << "}." << std::endl;
				myPQ.pop();
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the Set (Ascending). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Set (Ascending)." << std::endl;
		for (const int& item : myASet)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Set (Ascending)." << std::endl;
		for (std::set<int>::const_iterator itc_myASet = myASet.cbegin(); itc_myASet != myASet.cend(); itc_myASet++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myASet << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the Set (Descending). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Set (Descending)." << std::endl;
		for (const int& item : myDSet)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Set (Descending)." << std::endl;
		for (std::set<int>::const_iterator itc_myDSet = myDSet.cbegin(); itc_myDSet != myDSet.cend(); itc_myDSet++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myDSet << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the Unordered Set. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Unordered Set." << std::endl;
		for (const int& item : myUSet)
			std::cout << "#: [" << counter++ << "]\t=\t{" << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Unordered Set." << std::endl;
		for (std::unordered_set<int>::const_iterator itc_myUSet = myUSet.cbegin(); itc_myUSet != myUSet.cend(); itc_myUSet++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << *itc_myUSet << "}." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the Map (Ascending). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Map (Ascending)." << std::endl;
		for (const std::pair<const int, int>& item : myAMap)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << item.first << "} = [" << item.second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Map (Ascending)." << std::endl;
		for (std::map<int, int>::const_iterator itc_myAMap = myAMap.cbegin(); itc_myAMap != myAMap.cend(); itc_myAMap++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << itc_myAMap->first << "} = [" << itc_myAMap->second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the Map (Descending). */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Map (Descending)." << std::endl;
		for (const std::pair<const int, int>& item : myDMap)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << item.first << "} = [" << item.second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Map (Descending)." << std::endl;
		for (std::map<int, int>::const_iterator itc_myDMap = myDMap.cbegin(); itc_myDMap != myDMap.cend(); itc_myDMap++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << itc_myDMap->first << "} = [" << itc_myDMap->second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		/* Display the Unordered Map. */
		counter = V_ZERO;
		std::cout << std::endl << "Dumping of Unordered Map." << std::endl;
		for (const std::pair<const int, int>& item : myUMap)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << item.first << "} = [" << item.second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		counter = V_ZERO;
		std::cout << std::endl << "Unordered Map." << std::endl;
		for (std::unordered_map<int, int>::const_iterator itc_myUMap = myUMap.cbegin(); itc_myUMap != myUMap.cend(); itc_myUMap++)
			{
				std::cout << "#: [" << counter++ << "]\t=\t{" << itc_myUMap->first << "} = [" << itc_myUMap->second << "]." << std::endl;
			}
		std::cout << "[" << counter << "] Output generated results." << std::endl;

		return V_ZERO;
	}
