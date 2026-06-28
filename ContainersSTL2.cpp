/* Program that exemplifies the use of data sets for both numeric values ​​and objects,
   and in turn combined with each other for both ordered and unordered sets,
   combined in turn with each other for both sets with unique keys and with multiple keys.*/

/* Standard work libraries. */
#include <iostream>
#include <set>
#include <unordered_set>

/* Symbolic work constants. */
const std::string str_First_Name	{"Gustavo"};
const std::string str_Last_Name		{"Islas"};

template <typename T>
constexpr T V_100_5		{T(100.5)};
template <typename T>
constexpr T V_ONE_HUNDRED	{T(100)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Example of a 'Student' structure. */
template <typename T, typename U>
struct Student
	{
		T m_id {V_ZERO<int>};
		std::string m_name {};
		U m_age {V_ZERO<int>};

		Student(const T& id, const std::string& name, const U& age) : m_id(id), m_name(name), m_age(age) {};

		bool operator==(const Student<T, U>& student) const
			{return ((this->m_id == student.m_id) && (this->m_name == student.m_name) && (this->m_age == student.m_age));}

		bool operator>(const Student<T, U>& student) const
			{return (((*this).m_id > student.m_id) && ((*this).m_name > student.m_name) && ((*this).m_age > student.m_age));}

		bool operator<(const Student<T, U>& student) const
			{return (((*this).m_id < student.m_id) && ((*this).m_name < student.m_name) && ((*this).m_age < student.m_age));}

		void print() const
			{
				std::cout << "{id:\t[" << (*this).m_id << "],\tname:\t[" << (*this).m_name << "],\tage:\t[" << (*this).m_age << "]}." << std::endl;
			}
	};

/* Example of a 'Student' structure hash function. */
template <typename T, typename U>
struct MyStudentHashFunction
	{
		std::size_t operator()(const Student<T, U>& student) const
			{return (std::hash<T>{}(student.m_id) | std::hash<std::string>{}(student.m_name) | std::hash<U>{}(student.m_age));}
	};

//Main function.
int main()
	{
		/* Preliminary working variables. */
		// Another testing values: {5, 10, 4, 20, 5, 5, 15, 15, 25, 60, 35, 30, 40, 45, 20, 10, 5, 4}
		const int my_array[] = {12, 7, 11, 10, 13, 3, 3, 20, 1, 16, 9, 4, 14, 8, 16, 17};	//Raw arrangement of integer values.
		std::size_t h1 = std::hash<std::string>{}(str_First_Name);
		std::size_t h2 = std::hash<std::string>{}(str_Last_Name);

		/* Test of values ​​converted to Hash. */
		std::cout << "Test values ​​for conversion to Hash." << std::endl;
		std::cout << "+ h1:\t\t[" << h1 << "]\t=\t[" << str_First_Name << "]." << std::endl;
		std::cout << "+ h2:\t\t[" << h2 << "]\t=\t[" << str_Last_Name << "]." << std::endl;
		std::cout << "+ int:\t\t[" << std::hash<int>{}(V_ONE_HUNDRED<int>) << "]\t\t\t=\t[" <<  V_ONE_HUNDRED<int> << "]." << std::endl;
		std::cout << "+ float:\t[" << std::hash<float>{}(V_100_5<float>) << "]\t=\t[" << V_100_5<float> << "]." << std::endl << std::endl;

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
		std::set<Student<int, int>> ss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of ordered unique object instances." << std::endl;
		for (const Student<int, int>& item : ss)
			item.print();
		std::cout << std::endl;

		/* Testing values ​​with an unordered set of unique values ​​using object instances. */
		std::unordered_set<Student<int, int>, MyStudentHashFunction<int, int>> uss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of unordered unique object instances." << std::endl;
		for (const Student<int, int>& item : uss)
			item.print();
		std::cout << std::endl;

		/* Testing values with an ordered set of non-unique values using object instances. */
		std::multiset<Student<int, int>> mss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of ordered non-unique object instances." << std::endl;
		for (const Student<int, int>& item : mss)
			item.print();
		std::cout << std::endl;

		/* Testing values ​​with an unordered set of non-unique values ​​using object instances. */
		std::unordered_multiset<Student<int, int>, MyStudentHashFunction<int, int>> umss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "Joseph", 40}, {11, "Robert", 60}, {13, "Michael", 10}};

		std::cout << "A set of unordered non-unique object instances." << std::endl;
		for (const Student<int, int>& item : umss)
			item.print();

		return EXIT_SUCCESS;
	}
