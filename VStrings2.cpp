#include <iostream>
#include <string>

#define V_ZERO  0

class String
	{
		private:
			std::string *ptr = nullptr;

		public:
			String() : ptr(new std::string)	{}
			String(const std::string &str) : ptr(new std::string(str))	{}

			const std::string& content() const {return *ptr;}

			~String()   {delete ptr;}
	};

int main()
	{
		String foo {"First Example"};
		String bar ("Second Example");

		std::cout << "Outcomes." << std::endl;
		std::cout << "foo's content: [" << foo.content() << "]." << std::endl;
		std::cout << "bar's content: [" << bar.content() << "]." << std::endl;

		return V_ZERO;
	}
