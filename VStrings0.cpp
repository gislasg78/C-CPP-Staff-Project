#include <iostream>

constexpr int	V_ZERO	{};

template<typename T>
class Transfer
{
	private:
		T* ptr {};

	public:
		Transfer(T* _ptr = nullptr) : ptr {_ptr}	{}

		Transfer(const Transfer& t)
		{ptr = new T; *ptr = *t.ptr;}

		Transfer(Transfer&& t) noexcept : ptr {t.ptr}
		{t.ptr = nullptr;}

		Transfer& operator=(const Transfer& t)
		{
			if (&t != this)
			{
				delete ptr;

				ptr = new T;
				*ptr = *t.ptr;
			}

			return *this;
		}

		Transfer& operator=(Transfer&& t) noexcept
		{
			if (&t != this)
			{
				delete ptr;

				ptr = t.ptr;
				t.ptr = nullptr;
			}

			return *this;
		}

		T& operator*()	const	{return *ptr;}
		T* operator->()	const	{return ptr;}
		bool isNull()	const	{return ptr == nullptr;}

		~Transfer()		{delete ptr;}
};

class Resource
{
	public:
		Resource()  {std::cout << "Resource acquired!\n";}
		~Resource() {std::cout << "Resource destroyed!\n";}
};

int main()
{
	Transfer<Resource> mainres {Transfer<Resource> {new Resource}};
	mainres = Transfer<Resource> {new Resource};

	return V_ZERO;
}
