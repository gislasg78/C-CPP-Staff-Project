//Move constructor/assignment & const casting.
#include <iostream>
#include <string>

#define	NULL_CHARACTER	'\0'
#define	TABULATOR	'\t'
#define V_ZERO		0

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


void print(char *str)
	{
		std::cout << std::endl << "Conversions to constants." << std::endl;

		for (int idx = V_ZERO; str[idx] != NULL_CHARACTER; idx++)
			std::cout << "[" << *(str + idx) << "]." << TABULATOR;

		std::cout << std::endl << "[" << str << "]." << std::endl;
	}


int main ()
	{
		const char *cte_str = "This is a sample of constant symbolic text.";

		VString foo ("This is a test prayer. ");
		VString bar = VString("This is a compound sentence.");

		foo = foo + bar;

		std::cout << "Movement builders." << std::endl;
		std::cout << "bar's content: [" << bar.content() << "]." << std::endl;
		std::cout << "foo's content: [" << foo.content() << "]." << std::endl;

		print(const_cast<char*>(cte_str));

		return V_ZERO;
	}
