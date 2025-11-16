#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>

#define V_ONE   1
#define V_ZERO  0

struct Person
	{
		std::string name {};
		int age {V_ZERO};

		Person(std::string name, int age) : name(name), age(age) {};

		std::pair<std::string, int> key() const
			{
				return {(*this).name, (*this).age};
			}

		const bool operator==(const Person& other) const
			{
				return this->name == other.name && this->age == other.age;
			}

		virtual ~Person() = default;
	};

template <>
struct std::hash<Person>
	{
		const std::size_t operator()(const Person& person) const
			{
				const std::size_t h1 = std::hash<std::string>{}(person.name);
				const std::size_t h2 = std::hash<int>{}(person.age);

				return h1 ^ (h2 << V_ONE);
			}
	};

template <>
struct std::hash<std::pair<std::string, int>>
	{
		std::size_t operator()(const std::pair<std::string, int>& pair_person) const
			{
				const std::size_t h1 = std::hash<std::string>{}(pair_person.first);
				const std::size_t h2 = std::hash<int>{}(pair_person.second);

				return h1 ^ (h2 << V_ONE);
			}
	};

int main()
	{
		std::hash<Person> hash_Person;
		std::unordered_map<Person, std::string> my_unordered_map;

		Person p1{"Ana", 25};
		Person p2{"Edwin", 47};
		Person p3{"Juan", 30};

		my_unordered_map[p1] = "Employee A";
		my_unordered_map[p2] = "Employee B";
		my_unordered_map[p3] = "Employee C";

		std::cout << "Hash Values." << std::endl;
		std::cout << "+ P1: [" << hash_Person(p1) << "]." << std::endl;
		std::cout << "+ P2: [" << hash_Person(p2) << "]." << std::endl;
		std::cout << "+ P3: [" << hash_Person(p3) << "]." << std::endl;

		std::cout << std::endl << "Employees' Names." << std::endl;
		std::cout << "+ {" << my_unordered_map[p1] << "}." << std::endl;
		std::cout << "+ {" << my_unordered_map[p2] << "}." << std::endl;
		std::cout << "+ {" << my_unordered_map[p3] << "}." << std::endl;

		return V_ZERO;
	}
