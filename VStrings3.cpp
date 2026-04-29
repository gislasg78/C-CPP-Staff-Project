#include <cstring>
#include <iostream>

constexpr size_t	V_ONE	{1};
constexpr size_t	V_ZERO	{};

class Hire
{
	private:
		char *data{};
		size_t length{};

	public:
		Hire(const char* _data = nullptr, const size_t _length = V_ZERO) : data(const_cast<char*>(_data)), length(_length)
		{
			if (_data && _length)
			{
				if ((data = new char[length + V_ONE]()))
				{
					for (size_t i{}, j{}; data && i < length && j < std::strlen(_data); i++, j++)
						data[i] = _data[j];

					data[length] = V_ZERO;
				}
				else
				{
					std::cerr << std::endl << "It is not possible to allocate new memory blocks." << std::endl;
					throw std::invalid_argument("The memory allocation has failed!");
				}
			}
			else
			{
				if ((data = new char[length = V_ONE]()) == nullptr)
				{
					std::cerr << std::endl << "It is not possible to allocate new memory blocks." << std::endl;
					throw std::bad_alloc();
				}
			}
		}

		Hire& operator= (const Hire& hire);
		friend std::ostream& operator<< (std::ostream& os, const Hire& hire);

		~Hire()
		{
			if (data)
			{
				length = V_ZERO;
				delete[] data;
				data = nullptr;
			}
		}
};

std::ostream& operator<< (std::ostream& os, const Hire& hire)
{
	os << "Visualization of the 'Hire' object." << std::endl;
	os << "+ Pointer direction:\t(" << &hire.data << ")." << std::endl;

	if (hire.data)
	{
		os << "* First position:\t[" << *hire.data << "]." << std::endl;
		os << "* Content pointer:\t{" << hire.data << "}." << std::endl;
	}

	os << "+ Length of string:\t<" << hire.length << ">." << std::endl;
	return os;
};

Hire& Hire::operator= (const Hire& hire)
{
	if (this != &hire)
	{
		Hire::~Hire();

		length = hire.length;

		if ((data = new char[length + V_ONE]()))
		{
			for (size_t i{}, j{}; data && i < length && j < std::strlen(hire.data); i++, j++)
				data[i] = hire.data[j];

			data[length] = V_ZERO;
		}
		else
		{
			std::cerr << std::endl << "It is not possible to allocate new memory blocks." << std::endl;
			throw std::runtime_error("The memory allocation has failed!");
		}
	}

	return *this;
};

int main()
{
	std::string str_noun = std::string();

	std::cout << "Creation of objects of the type 'Hire'." << std::endl;
	std::cout << "Enter your full name: ";
	std::getline(std::cin >> std::ws, str_noun);
	const char* str_Name = str_noun.c_str();

	Hire someone(str_Name, std::strlen(str_Name));
	Hire employee;

	std::cout << std::endl << str_Name << "." << std::endl;
	std::cout << someone;

	std::cout << std::endl << "Employee." << std::endl;
	std::cout << employee;

	std::cout << std::endl << "Employee = " << str_Name << "." << std::endl;
	employee = someone;
	std::cout << employee;

	std::cout << std::endl << str_Name << " = Employee." << std::endl;
	someone = employee;
	std::cout << someone;

	std::cout << std::endl << str_Name << " = " << str_Name << "." << std::endl;
	someone = someone;
	std::cout << someone;

	std::cout << std::endl << "Employee = Employee." << std::endl;
	employee = employee;
	std::cout << employee;

	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended." << std::endl;

	return V_ZERO;
}
