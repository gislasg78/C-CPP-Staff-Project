//Move constructor/assignment.
#include <iostream>
#include <string>

#define V_ZERO  0

class VString
	{
		private:
			std::string *ptr = nullptr;

		public:
			VString (const std::string &str) : ptr(new std::string(str)) {}
			VString (VString&& x) : ptr(x.ptr) {x.ptr = nullptr;}

			VString& operator=(VString&& x)
				{delete ptr; ptr = x.ptr; x.ptr = nullptr; return *this;}
			VString operator+(const VString& rhs)
				{return VString(this->content() + rhs.content());}

			const std::string& content() const {return *ptr;}

			~VString () {delete ptr;}
	};


int main ()
	{
		VString foo ("This is a test prayer. ");
		VString bar = VString("This is a compound sentence.");

		foo = foo + bar;

		std::cout << "Movement builders." << std::endl;
		std::cout << "bar's content: [" << bar.content() << "]." << std::endl;
		std::cout << "foo's content: [" << foo.content() << "]." << std::endl;

		return V_ZERO;
	}
