#include <cstring>
#include <iostream>

constexpr size_t	V_NINE	{9};
constexpr size_t	V_ONE	{1};
constexpr size_t	V_ZERO	{};

class Hire
{
	private:
		char *data{};
		size_t length{};

	public:
		Hire(const char* _data = nullptr, const size_t _length = V_ZERO)
		{
			if (_data && _length)
			{
				length = _length;
				data = new char[length + V_ONE]();

				for (size_t i{}, j{}; data && i < length && j < std::strlen(_data); i++, j++)
					data[i] = _data[j];

				data[length] = V_ZERO;
			}
			else
			{
				length = V_ONE;
				data = new char[length]();
			}
		}

		~Hire()
		{
			if (data && length)
			{
				length = V_ZERO;
				delete[] data;
				data = nullptr;
			}
		}

		Hire& operator= (const Hire& hire);
		friend std::ostream& operator<< (std::ostream& os, const Hire& hire);
};

std::ostream& operator<< (std::ostream& os, const Hire& hire)
{
	os << "Visualization of the 'Hire' object." << std::endl;
	os << "+ Pointer direction:\t(" << &hire.data << ")." << std::endl;
	os << "+ First position:\t[" << *hire.data << "]." << std::endl;
	os << "+ Content pointer:\t{" << hire.data << "}." << std::endl;
	os << "+ Length of string:\t<" << hire.length << ">." << std::endl;

	return os;
};

Hire& Hire::operator= (const Hire& hire)
{
	if (this != &hire)
	{
		Hire::~Hire();

		length = hire.length;
		data = new char[length + V_ONE]();

		for (size_t i{}, j{}; data && i < length && j < std::strlen(hire.data); i++, j++)
			data[i] = hire.data[j];

		data[length] = V_ZERO;
	}

	return *this;
};

int main()
{
	std::cout << "Creation of objects of the type 'Hire'." << std::endl;

	Hire alex("Alexander", V_NINE);
	Hire employee;

	std::cout << std::endl << "Alexander." << std::endl;
	std::cout << alex;

	std::cout << std::endl << "Employee." << std::endl;
	std::cout << employee;

	std::cout << std::endl << "Employee = Alexander." << std::endl;
	employee = alex;
	std::cout << employee;

	std::cout << std::endl << "Alexander = Employee." << std::endl;
	alex = employee;
	std::cout << alex;

	std::cout << std::endl << "Alexander = Alexander." << std::endl;
	alex = alex;
	std::cout << alex;

	std::cout << std::endl << "Employee = Employee." << std::endl;
	employee = employee;
	std::cout << employee;

	return V_ZERO;
}
