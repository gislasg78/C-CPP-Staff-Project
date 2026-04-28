#include <iostream>

constexpr size_t V_ZERO {};
constexpr size_t V_ONE	{1};
constexpr size_t V_TEN  {10};

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
				data = new char[length]();

				for (size_t i{}; i < length; i++)
					data[i] = _data[i];
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
				delete[] data;
				data = nullptr;
				length = V_ZERO;
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
	Hire::~Hire();

	length = hire.length;
	data = new char[length]();

	for (size_t i{}; i < length; i++)
		data[i] = hire.data[i];

	return *this;
};

int main()
{
	std::cout << "Creation of objects of the type 'Hire'." << std::endl;

	Hire alex("Alexander", V_TEN);
	Hire employee;

	std::cout << std::endl << "Alexander." << std::endl;
	std::cout << alex;

	std::cout << std::endl << "Employee." << std::endl;
	std::cout << employee;

	std::cout << std::endl << "Employee = Alexander." << std::endl;
	employee = alex;
	std::cout << employee;

	return V_ZERO;
}
