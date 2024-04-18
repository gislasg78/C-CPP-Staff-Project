#include <iostream>

#define V_ZERO  0

template <typename T>
class Point2D
	{
		private:
			template <typename U>
			friend std::ostream &operator<< (std::ostream &os, const Point2D<U> &p2D);

		protected:
			static int c;
			T x = V_ZERO, y = V_ZERO;

		public:
			Point2D (T x, T y) : x(x), y(y) {this->c++;};

			T getX() const {return this->x;};
			T getY() const {return this->y;};

			void setX(const T x) {this->x = x;};
			void setY(const T y) {this->y = y;};

			virtual void print()
				{
					std::cout << "2D Point #" << this->c << ": (" << this->x << ", " << this->y << ")" << std::endl;
				};

	};

template <typename T>
int Point2D<T>::c=V_ZERO;

template <typename T>
class Point3D : public Point2D<T>
	{
		private:
			template <typename U>
			friend std::ostream &operator<< (std::ostream &os, const Point3D<U> &p3D);

			T z = V_ZERO;

		public:
			Point3D(T x, T y, T z) : Point2D<T>(x, y), z(z) {};

			T getZ() const {return this->z;};

			void setZ(const T z) {this->z = z;};

			void print()
				{
					Point2D<T>::print();
					std::cout << "3D Point #" << this->c << ": (" << this->z << ")" << std::endl;
				};
	};


template <typename U>
inline std::ostream &operator<< (std::ostream &os, const Point2D<U> &p2D)
	{
		os << "2D Point #" << p2D.c << ": (" << p2D.x << ", " << p2D.y << ")" << std::endl;

		return os;
	};

template <typename U>
inline std::ostream &operator<< (std::ostream &os, const Point3D<U> &p3D)
	{
		os << "3D Point #" << p3D.c << ": (" << p3D.getX() << ", " << p3D.getY() << ", " << p3D.getZ() << ")" << std::endl;

		return os;
	};


int main()
	{
		int int_2D_x = V_ZERO, int_2D_y = V_ZERO;
		int int_3D_x = V_ZERO, int_3D_y = V_ZERO, int_3D_z = V_ZERO;

		std::cout << "Coordinates of two points in the 2D Cartesian plane & 3D plane." << std::endl;

		std::cout << std::endl;
		std::cout << "First Point 2D." << std::endl;
		std::cout << "X Coord: ";
		std::cin >> int_2D_x;
		std::cout << "Y Coord: ";
		std::cin >> int_2D_y;

		std::cout << std::endl;
		std::cout << "Second Point 3D." << std::endl;
		std::cout << "X Coord: ";
		std::cin >> int_3D_x;
		std::cout << "Y Coord: ";
		std::cin >> int_3D_y;
		std::cout << "Z Coord: ";
		std::cin >> int_3D_z;

		std::cout << std::endl;
		std::cout << "Results." << std::endl;
		std::cout << "--------" << std::endl;

		std::cout << "Generating an instance of a class template of type 2D Point." << std::endl;
		Point2D<int> p2D = Point2D<int>(int_2D_x, int_2D_y);
		p2D.print();
		std::cout << p2D << std::endl;

		std::cout << "Generating an instance of a class template of type 3D Point." << std::endl;
		Point3D<int> p3D = Point3D<int>(int_3D_x, int_3D_y, int_3D_z);
		p3D.print();
		std::cout << p3D << std::endl;

		std::cout << "Change of 'x' & 'y' coordinates of the 2D Point." << std::endl;
		p2D.setX(int_3D_x);
		p2D.setY(int_3D_y);
		p2D.print();
		std::cout << p2D << std::endl;

		std::cout << "Change of 'x' & 'y' coordinates of the 3D Point." << std::endl;
		p3D.setX(int_2D_x);
		p3D.setY(int_2D_y);
		p3D.print();
		std::cout << p3D << std::endl;

		std::cout << "Polymorphism by assigning a 3D Point to a 2D Point type." << std::endl;
		Point2D<int> p2x3D = Point3D<int>(int_3D_x, int_3D_y, int_3D_z);
		p2x3D.print();
		std::cout << p2x3D << std::endl;

		return V_ZERO;
	}
