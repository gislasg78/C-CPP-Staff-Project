#include <iostream>

#define V_ZERO  0

template <typename T>
class MyPoint
	{
		private:
			T x = V_ZERO, y = V_ZERO;

		public:
			MyPoint(const T &x, const T &y) : x(x), y(y) {this->c++;};

			static int c;

			void setX(const T &x)	{this->x = x;}
			void setY(const T &y)	{this->y = y;}

			void print() const	{std::cout << std::endl << "#: " << this->c << " (x=[" << this->x << "], y=[" << this->y << "])." << std::endl;}

			int getX() const	{return this->x;}
			int getY() const	{return this->y;}
	};

template <typename T>
int MyPoint<T>::c = V_ZERO;

int main()
	{
		int qty = V_ZERO;
		int x = V_ZERO, y = V_ZERO;

		std::cout << "Creating points on a plane." << std::endl;
		std::cout << "How many 'MyPoints' do you want to create? : ";
		std::cin >> qty;

		MyPoint<int> **mypoints = new MyPoint<int>* [qty];

		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << std::endl << "Point #: " << idx << std::endl;
				std::cout << "'X' coordinate: ";
				std::cin >> x;
				std::cout << "'Y' coordinate: ";
				std::cin >> y;

				mypoints[idx] = new MyPoint<int>(x, y);
			}

		for (int idx = V_ZERO; idx < qty; idx++)
			{
				std::cout << std::endl << "Point #: " << idx << std::endl;
				mypoints[idx]->print();
			}

		std::cout << std::endl << "Clearing objects..." << std::endl;

		for (int idx = V_ZERO; idx < qty; idx++)
			{
				delete mypoints[idx];
			}

		delete mypoints;

		return V_ZERO;
	}
