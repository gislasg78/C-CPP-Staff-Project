#include <iostream>
#include <limits>
#include <memory>

constexpr int CARRIAGE_RETURN	{'\n'};
constexpr int V_ZERO		{};

class Person
{
	private:
		std::string name {};
		std::weak_ptr<Person> partner {};

	public:
		explicit Person(const std::string& _name) : name(_name)
		{
			std::cout << std::endl << "Person created." << std::endl;
			std::cout << "+ Name:\t[" << name << "]." << std::endl;
		}

		friend void associate_up(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)
		{
			if (p1 && p2)
			{
				if (p1->partner.lock() != p2)
				{
					p1->partner = p2;
					p2->partner = p1;

					std::cout << std::endl << "[" << p1->name << "] is now a partner of: {" << p2->name << "}." << std::endl;
				}
				else
					std::cout << "\n[" << p1->name << "] and [" << p2->name << "] are already partners.\n";
			}
		}

		const std::string& getName() const
		{
			return name;
		}

		std::shared_ptr<Person> getPartner() const
		{
			return partner.lock();
		}

		void printInfo() const
		{
			std::cout << "\nPerson information.\n";
			std::cout << "- Name:\t\t[" << name << "].\n";

			if (auto currentPartner = partner.lock())
			{
				std::cout << "- Partner:\t[" << currentPartner->getName() << "].\n";
			}
			else
			{
				std::cout << "- Partner:\t[None].\n";
			}
		}

		void setPartner(const std::shared_ptr<Person>& newPartner)
		{
			partner = newPartner;
		}

		~Person()
		{
			std::cout << std::endl << "Person destroyed." << std::endl;
			std::cout << "- Person:\t[" << name << "]." << std::endl;
		}
};

void enter_a_pause(const std::string& str_Message)
{
	std::cout << str_Message;
	std::cin.clear();
	std::cin.get();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
}

int main()
{
	std::cout << "Shared pointers exercise." << std::endl;

	std::shared_ptr<Person> laura   {std::make_shared<Person>("Laura")};
	enter_a_pause("Press the ENTER key to continue...");

	std::shared_ptr<Person> richard {std::make_shared<Person>("Richard")};
	enter_a_pause("Press the ENTER key to continue...");

	associate_up(laura, richard);
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Smart pointer counter." << std::endl;
	std::cout << std::endl << "* Laura's Info." << std::endl;
	std::cout << "\t+ Counter:\t[" << laura.use_count() << "]." << std::endl;
	std::cout << "\t+ Name:\t\t[" << laura->getName() << "]." << std::endl;
	std::cout << "\t+ Partner:\t[" << laura->getPartner()->getName() << "]." << std::endl;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "* Richard's Info." << std::endl;
	std::cout << "\t+ Counter:\t[" << richard.use_count() << "]." << std::endl;
	std::cout << "\t+ Name:\t\t[" << richard->getName() << "]." << std::endl;
	std::cout << "\t+ Partner:\t[" << richard->getPartner()->getName() << "]." << std::endl;
	enter_a_pause("Press the ENTER key to continue...");

	laura->printInfo();
	enter_a_pause("Press the ENTER key to continue...");

	richard->printInfo();
	enter_a_pause("Press the ENTER key to continue...");

	associate_up(richard, laura);
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Smart pointer counter." << std::endl;
	std::cout << std::endl << "* Laura's Info." << std::endl;
	std::cout << "\t+ Counter:\t[" << laura.use_count() << "]." << std::endl;
	std::cout << "\t+ Name:\t\t[" << laura->getName() << "]." << std::endl;
	std::cout << "\t+ Partner:\t[" << laura->getPartner()->getName() << "]." << std::endl;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "* Richard's Info." << std::endl;
	std::cout << "\t+ Counter:\t[" << richard.use_count() << "]." << std::endl;
	std::cout << "\t+ Name:\t\t[" << richard->getName() << "]." << std::endl;
	std::cout << "\t+ Partner:\t[" << richard->getPartner()->getName() << "]." << std::endl;
	enter_a_pause("Press the ENTER key to continue...");

	laura->printInfo();
	enter_a_pause("Press the ENTER key to continue...");

	richard->printInfo();
	enter_a_pause("Press the ENTER key to continue...");

	return V_ZERO;
}
