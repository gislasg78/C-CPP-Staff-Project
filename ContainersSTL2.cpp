/* Program that exemplifies the use of data sets for both numeric values ​​and objects,
   and in turn combined with each other for both ordered and unordered sets,
   combined in turn with each other for both sets with unique keys and with multiple keys.*/

/* Standard work libraries. */
#include <iostream>
#include <set>
#include <unordered_set>

/* Symbolic work constants. */
#define	V_FIRST_NAME	"Gustavo"
#define	V_LAST_NAME	"Islas"

#define	V_100_5		100.5
#define	V_ONE_HUNDRED	100
#define V_ZERO		0

/* Example of a 'Student' structure. */
struct Student
	{
		int id = V_ZERO;
		std::string name {};
		int age = V_ZERO;

		Student(const int& id, const std::string& name, const int& age) : id(id), name(name), age(age) {};

		const bool operator==(const Student& other) const
			{return ((this->id == other.id) && (this->name == other.name) && (this->age == other.age));}

		const bool operator>(const Student& other) const
			{return (((*this).id > other.id) && ((*this).name > other.name) && ((*this).age > other.age));}

		const bool operator<(const Student& other) const
			{return (((*this).id < other.id) && ((*this).name < other.name) && ((*this).age < other.age));}

		void print() const
			{
				std::cout << "{id:\t[" << (*this).id << "],\tname:\t[" << (*this).name << "],\tage:\t[" << (*this).age << "]}." << std::endl;
			}
	};

/* Example of a 'Student' structure hash function. */
struct MyStudentHashFunction
	{
		const std::size_t operator()(const Student& other) const
			{return (std::hash<int>{}(other.id) + std::hash<std::string>{}(other.name) + std::hash<int>{}(other.age));}
	};

//Main function.
int main()
	{
		/* Preliminary working variables. */
		// Another testing values: {5, 10, 4, 20, 5, 5, 15, 15, 25, 60, 35, 30, 40, 45, 20, 10, 5, 4}
		const int my_array[] = {12, 7, 11, 10, 13, 3, 3, 20, 1, 16, 9, 4, 14};	//Raw arrangement of integer values.
		std::size_t h1 = std::hash<std::string>{}(V_FIRST_NAME);
		std::size_t h2 = std::hash<std::string>{}(V_LAST_NAME);

		/* Test of values ​​converted to Hash. */
		std::cout << "Test values ​​for conversion to Hash." << std::endl;
		std::cout << "+ h1:\t\t[" << h1 << "]." << std::endl;
		std::cout << "+ h2:\t\t[" << h2 << "]." << std::endl;
		std::cout << "+ int:\t\t[" << std::hash<int>{}(V_ONE_HUNDRED) << "]." << std::endl;
		std::cout << "+ float:\t[" << std::hash<float>{}(V_100_5) << "]." << std::endl << std::endl;

		/* Testing values ​​on sorted set of unique numeric values. */
		std::set<int> s(std::begin(my_array), std::end(my_array));

		std::cout << "A set of ordered unique numerical values." << std::endl;
		for (const int& item : s)
			std::cout << "[" << item << "].\t";
		std::cout << std::endl << "+ Size: [" << s.size() << "]." << std::endl << std::endl;

		/* Testing values ​​on unsorted set of unique numeric values. */
		std::unordered_set<int> us(std::begin(my_array), std::end(my_array));

		std::cout << "A set of unordered unique numerical values." << std::endl;
		for (const int& item : us)
			std::cout << "[" << item << "].\t";
		std::cout << std::endl;

		std::cout << "+ Size: [" << us.size() << "]." << std::endl;
		std::cout << "+ Num buckets: [" << us.bucket_count() << "]." << std::endl;
		std::cout << "+ Load factor: [" << us.load_factor() << "]." << std::endl << std::endl;

		/* Testing values ​​on sorted set of non-unique numeric values. */
		std::multiset<int> ms(std::begin(my_array), std::end(my_array));

		std::cout << "A set of ordered non-unique numerical values." << std::endl;
		for (const int& item : ms)
			std::cout << "[" << item << "].\t";
		std::cout << std::endl << "+ Size: [" << ms.size() << "]." << std::endl << std::endl;

		/* Testing values ​​on unsorted set of non-unique numeric values. */
		std::unordered_multiset<int> ums(std::begin(my_array), std::end(my_array));

		std::cout << "A set of unordered non-unique numerical values." << std::endl;
		for (const int& item : ums)
			std::cout << "[" << item << "].\t";
		std::cout << std::endl;

		std::cout << "+ Size: [" << ums.size() << "]." << std::endl;
		std::cout << "+ Num buckets: [" << ums.bucket_count() << "]." << std::endl;
		std::cout << "+ Load factor: [" << ums.load_factor() << "]." << std::endl << std::endl;

		/* Testing values with an ordered set of unique values using object instances. */
		std::set<Student> ss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of ordered unique object instances." << std::endl;
		for (const Student& item : ss)
			item.print();
		std::cout << std::endl;

		/* Testing values ​​with an unordered set of unique values ​​using object instances. */
		std::unordered_set<Student, MyStudentHashFunction> uss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of unordered unique object instances." << std::endl;
		for (const Student& item : uss)
			item.print();
		std::cout << std::endl;

		/* Testing values with an ordered set of non-unique values using object instances. */
		std::multiset<Student> mss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of ordered non-unique object instances." << std::endl;
		for (const Student& item : mss)
			item.print();
		std::cout << std::endl;

		/* Testing values ​​with an unordered set of non-unique values ​​using object instances. */
		std::unordered_multiset<Student, MyStudentHashFunction> umss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of unordered non-unique object instances." << std::endl;
		for (const Student& item : umss)
			item.print();

		return V_ZERO;
	}
