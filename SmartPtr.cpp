#include <iostream>
#include <memory>

#define V_ZERO  0

class MyClass
	{
		private:
			int data = V_ZERO;

		public:
			MyClass(int value) : data(value)
				{
					std::cout << "An object called 'My Class' has been created with the data: [" << data << "]." << std::endl;
				}

			~MyClass()
				{
					std::cout << "An object called 'My Class' has been destroyed with the data: [" << data << "]." << std::endl;
				}

			void printData()
				{
					std::cout << "The data value of this class 'My Class' is: [" << data << "]." << std::endl;
				}
	};

int main()
	{
		int unique_value = V_ZERO;
		int shared_value = V_ZERO;

		std::cout << "Enter an integer value to create the 'MyClass' class with a smart single pointer: ";
		std::cin >> unique_value;

		//Using smart single pointer.
		std::unique_ptr<MyClass> singlePointer = std::make_unique<MyClass>(unique_value);
		singlePointer->printData();

		std::cout << "Enter an integer value to create the 'MyClass' class with a smart shared pointer: ";
		std::cin >> shared_value;

		//Using smart shared pointer.
		std::shared_ptr<MyClass> firstsharedPointer = std::make_shared<MyClass>(shared_value);
		std::shared_ptr<MyClass> secondsharedPointer = firstsharedPointer;

		firstsharedPointer->printData();
		secondsharedPointer->printData();

		//Using smart weak pointer.
		std::weak_ptr<MyClass> weakPointer = firstsharedPointer;

		//Verifying the existence of the smart weak pointer before attempting to access it.
		if (auto sharedweakPointer = weakPointer.lock())
			{
				std::cout << "The object contained in the weak smart pointer still persists, exists, and can be accessed." << std::endl;
				sharedweakPointer->printData();
			}
		else
			{
				std::cout << "The object contained in the weak smart pointer was already worth a damn and ceased to exist." << std::endl;
			}

		//The object will be automatically destroyed when the scope in which it is contained finishes executing.

		return V_ZERO;
	}
