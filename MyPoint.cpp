/* This program creates a parent or base class called 'MyPoint' 
   and exemplifies different features of Object Oriented Programming in C++.
*/
#include <iostream>

/* Symbolic work constants. */
#define	V_ONE	1
#define V_ZERO  0

/* Base or parent class of the 'MyPoint' type. */
template <typename T>
class MyPoint
	{
		private:
			T x = V_ZERO, y = V_ZERO;

			template <typename U>
			friend std::istream &operator>> (std::istream& in, MyPoint<U> &myPoint)
				{
					U x = V_ZERO, y = V_ZERO;
					std::cout << "Set new coordinates to the 'MyPoint' object." << std::endl;
					std::cout << "Base coordinates." << std::endl;
					std::cout << "x = ";
					std::cin >> x;
					std::cout << "y = ";
					std::cin >> y;

					myPoint.setX(x);
					myPoint.setY(y);

					return in;
				}

			template <typename U>
			friend std::ostream &operator<< (std::ostream& out, const MyPoint<U> &myPoint)
				{
					std::cout << "Display properties of the 'My Point' object." << std::endl;
					myPoint.viewCounter();
					std::cout << "(x = [" << myPoint.getX() << "]," << " y = [" << myPoint.getY() << "])." << std::endl;

					return out;
				}

		protected:
			static int c;

		public:
			MyPoint()
				{
					this->c++;
					std::cout << "Capture a new object 'MyPoint'." << std::endl;
					this->capture();
				};

			MyPoint(const MyPoint& myPoint)
				{
					this->c++;
					this->x = myPoint.getX();
					this->y = myPoint.getY();
				};

			MyPoint(const T &x, const T &y) : x(x), y(y)	{this->c++;};

			virtual void capture()
				{
					std::cout << "Base coordinates." << std::endl;
					std::cout << "x = ";
					std::cin >> this->x;
					std::cout << "y = ";
					std::cin >> this->y;
				}

			int getX() const	{return this->x;}
			int getY() const	{return this->y;}

			virtual void print() const
				{
					std::cout << "Show properties of the 'My Point' object." << std::endl;
					this->viewCounter();
					std::cout << "(x = [" << this->x << "], y = [" << this->y << "])." << std::endl;
				}

			void setX(const T &x)	{this->x = x;}
			void setY(const T &y)	{this->y = y;}

			void viewCounter() const
				{
					std::cout << "'MyPoint's objects created: " << this->c << std::endl;
				}

			virtual ~MyPoint() = default;
	};

/* Initialization of the static accounting variable of the 'MyPoint' class. */
template <typename T>
int MyPoint<T>::c = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int qty = V_ZERO;
		int x = V_ZERO, y = V_ZERO;

		/* Initial header messages. */
		std::cout << "Creating 'MyPoint' objects on an array." << std::endl;
		std::cout << "How many 'MyPoints' do you want to create? : ";
		std::cin >> qty;

		//The dynamic array of pointers to objects of type 'MyPoint' is created.
		MyPoint<int> **mypoints = new MyPoint<int>* [qty];

		/* Each object of type 'MyPoint' is created and stored in an array of pointers of the same type. */
		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << std::endl << "'MyPoint' #: " << idx + V_ONE << std::endl;
				std::cout << "+ 'X' coordinate: ";
				std::cin >> x;
				std::cout << "+ 'Y' coordinate: ";
				std::cin >> y;

				mypoints[idx] = new MyPoint<int>(x, y);
			}

		/* An internal method of the 'MyPoint' object is used to display the assigned values. */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << std::endl << "'MyPoint' #: " << idx + V_ONE << std::endl;
				mypoints[idx]->print();
			}

		/* New values ​​are reassigned and captured to created objects of type 'MyPoint' */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << std::endl << "'MyPoint' #: " << idx + V_ONE << std::endl;
				std::cin >> *mypoints[idx];
			}

		/* The reassigned values ​​of each instantiated object of type 'MyPoint' are displayed again. */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << std::endl << "'MyPoint' #: " << idx + V_ONE << std::endl;
				std::cout << *mypoints[idx];
			}

		/* All dynamically created instances of objects of type 'MyPoint' are purged. */
		std::cout << std::endl << "Clearing 'MyPoint' objects..." << std::endl;
		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << "Deleting object 'MyPoint' #: " << idx + V_ONE << std::endl;
				delete *(mypoints + idx);
			}

		/* Deleting the array of pointer objects of type 'MyPoint'. */
		std::cout << "Deleting the array of pointers of type 'MyPoint'..." << std::endl;
		delete mypoints;

		return V_ZERO;
	}
