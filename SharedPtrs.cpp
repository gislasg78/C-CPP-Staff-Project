#include <iostream>
#include <memory>

constexpr int V_ZERO {};

class Person
{
	public:
		std::string name {};
		std::weak_ptr<Person> partner {};

		Person(const std::string& _name) : name(_name)
		{
			std::cout << std::endl << "Shared pointer created." << std::endl;
			std::cout << "Person: [" << name << "]." << std::endl;
		}

		friend void associate_up(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)
		{
			if (p1 && p2)
			{
				p1->partner = p2;
				p2->partner = p1;

				std::cout << std::endl << "[" << p1->name << "] is now a partner of: {" << p2->name << "}." << std::endl;
			}
		}

		~Person()
		{
			std::cout << std::endl << "Shared pointer destroyed." << std::endl;
			std::cout << "Person: [" << name << "]." << std::endl;
		}
};

int main()
{
	std::cout << "Shared pointers exercise." << std::endl;

	std::shared_ptr<Person> laura   {std::make_shared<Person>("Laura")};
	std::shared_ptr<Person> richard {std::make_shared<Person>("Richard")};

	associate_up(laura, richard);
	std::cout << std::endl << "Laura Counter:\t\t[" << laura.use_count() << "]." << std::endl;
	std::cout << "Richard Counter:\t[" << richard.use_count() << "]." << std::endl;

	associate_up(richard, laura);
	std::cout << std::endl << "Laura Counter:\t\t[" << laura.use_count() << "]." << std::endl;
	std::cout << "Richard Counter:\t[" << richard.use_count() << "]." << std::endl;

	return V_ZERO;
}
