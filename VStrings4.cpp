#include <iostream>
#include <limits>

constexpr char CARRIAGE_RETURN	{'\n'};
constexpr int V_ZERO		{};

template <typename T>
class Auto_ptr
{
	private:
		T *ptr{nullptr};

	public:
		Auto_ptr(T *_ptr = nullptr) : ptr(_ptr)
		{}

		Auto_ptr(const Auto_ptr& auto_ptr)
		{
			if (auto_ptr.ptr)
			{
				this->ptr = new T{*auto_ptr.ptr};
			}
		}

		Auto_ptr(Auto_ptr&& auto_ptr)
		{
			if (auto_ptr.ptr)
			{
				this->ptr = new T{*auto_ptr.ptr};
				delete auto_ptr.ptr;
				auto_ptr.ptr = nullptr;
			}
		}

		Auto_ptr& operator= (const Auto_ptr& auto_ptr)
		{
			if (this != &auto_ptr)
			{
				if (auto_ptr.ptr)
				{
					release();

					if ((*this).ptr == nullptr)
					{
						(*this).ptr = new T{*auto_ptr.ptr};
					}
				}
			}

			return *this;
		}

		Auto_ptr& operator= (Auto_ptr&& auto_ptr)
		{
			if (this != &auto_ptr)
			{
				if (auto_ptr.ptr)
				{
					release();

					if ((*this).ptr == nullptr)
					{
						(*this).ptr = new T{*auto_ptr.ptr};
						delete auto_ptr.ptr;
						auto_ptr.ptr = nullptr;
					}
				}
			}

			return *this;
		}

		const T* const& getPtr() const
		{
			return this->ptr;
		}

		void print() const
		{
			std::cout << std::endl << "Contents of the Auto Pointer." << std::endl;
			std::cout << "+ Storage Address:\t(" << &(*this).ptr << ")." << std::endl;
			std::cout << "+ Address Contained:\t[" << this->ptr << "]." << std::endl << std::endl;
		}

		void release()
		{
			if (this->ptr)
			{
				delete this->ptr;
				this->ptr = nullptr;
			}
		}

		~Auto_ptr()
		{
			release();
		}
};

class Resource
{
	public:
		Resource()
		{std::cout << std::endl << "* Acquired resource. *" << std::endl;}

		~Resource()
		{std::cout << std::endl << "* Resource destroyed. *" << std::endl;}
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
	std::cout << "Deep copy constructor and deep assignment operator." << std::endl;

	/* Deep copy builders. */
	Auto_ptr<Resource> recourse;
	Auto_ptr<Resource> resort	{new Resource{}};
	Auto_ptr<Resource> resource	{resort};

	std::cout << std::endl << "Deep copy constructors invoked..." << std::endl;
	std::cout << std::endl << "Resource Object:\t{Recourse}." << std::endl;
	recourse.print();
	std::cout << std::endl << "Resource Object:\t{Resort} <- New Resource." << std::endl;
	resort.print();
	std::cout << std::endl << "Resource Object:\t{Resource} <- Resort." << std::endl;
	resource.print();

	enter_a_pause("Press the ENTER key to continue...");

	/* Deep move constructor builders. */
	Auto_ptr<Resource> device	{std::move(resort)};

	std::cout << std::endl << "Deep move constructor invoked..." << std::endl;
	std::cout << std::endl << "Resource Object:\t{Resort}." << std::endl;
	resort.print();
	std::cout << std::endl << "Resource Object:\t{Device} <- Resort." << std::endl;
	device.print();
	enter_a_pause("Press the ENTER key to continue...");

	/* Deep copy assignment operator. */
	std::cout << std::endl << "Deep copy assignment operator." << std::endl;
	recourse = resource;

	std::cout << std::endl << "Resource Object:\t{Resource}." << std::endl;
	resource.print();
	std::cout << std::endl << "Resource Object:\t{Recourse} <- Resource." << std::endl;
	recourse.print();

	enter_a_pause("Press the ENTER key to continue...");

	/* Deep move allocation operator. */
	std::cout << std::endl << "Deep move assignment operator." << std::endl;
	resort = std::move(recourse);

	std::cout << std::endl << "Resource Object:\t{Resort} <- Recourse." << std::endl;
	resort.print();
	std::cout << std::endl << "Resource Object:\t{Recourse}." << std::endl;
	recourse.print();

	enter_a_pause("Press the ENTER key to continue...");

	return V_ZERO;
}
