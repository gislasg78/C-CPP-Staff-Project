#include <iostream>
#include <unordered_set>

#define V_ZERO  0

struct Student
	{
		int id = V_ZERO;
		std::string name {};
		int age = V_ZERO;

		Student(const int& id, const std::string& name, const int& age) : id(id), name(name), age(age) {};

		const bool operator==(const Student& other) const
			{return ((this->id == other.id) && (this->name == other.name) && (this->age == other.age));}

		void print_student() const
			{
				std::cout << "{id =[" << (*this).id << "], name = [" << (*this).name << "], age = [" << (*this).age << "]}." << std::endl;
			}
	};

struct StudentMyHashFunction
	{
		const std::size_t operator()(const Student& other) const
			{return (std::hash<int>{}(other.id) + std::hash<std::string>{}(other.name) + std::hash<int>{}(other.age));}
	};

int main()
	{
		std::size_t h1 = std::hash<std::string>{}("Hello");
		std::size_t h2 = std::hash<std::string>{}("World");

		std::cout << "Hashing Values." << std::endl;
		std::cout << "h1 = [" << h1 << "]." << std::endl;
		std::cout << "h2 = [" << h2 << "]." << std::endl;
		std::cout << "int = [" << std::hash<int>{}(100) << "]." << std::endl;
		std::cout << "float = [" << std::hash<float>{}(100.5) << "]." << std::endl;

		std::unordered_set<int> us = {5, 10, 4, 20, 5, 5, 15, 15, 25, 60, 35, 30, 40, 45, 20, 10, 5, 4};

		std::cout << std::endl << "Set of Numbers." << std::endl;
		for (int item : us)
			std::cout << "[" << item << "].\t";
		std::cout << std::endl;

		std::cout << "Size: [" << us.size() << "]." << std::endl;
		std::cout << "Num buckets: [" << us.bucket_count() << "]." << std::endl;
		std::cout << "Load factor: [" << us.load_factor() << "]." << std::endl;

		std::unordered_set<Student, StudentMyHashFunction> uss = {{5, "Thomas", 50}, {3, "Phillip", 20}, {2, "Andrew", 30}, {7, "John", 40}, {11, "Robert", 60}};

		std::cout << std::endl << "Set of Students." << std::endl;
		for (const Student& item : uss)
			item.print_student();

		return V_ZERO;
	}
