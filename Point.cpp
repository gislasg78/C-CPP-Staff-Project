#include <iostream>

//Symbolic constant of work.
#define V_ZERO  0

//Namespace to hold both types of 2D and 3D points.
namespace SpacePoints
	{
		//First '2D Point' template type class.
		template <typename T>
		class Point2D
			{
				private:
					template <typename U>
					friend std::ostream &operator<< (std::ostream &os, const SpacePoints::Point2D<U> &Sp2D);

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
							std::cout << "2D Point #" << this->c << ":\t(" << this->x << ", " << this->y << ")." << std::endl;
						};

			};

		//Initialization of the static count value of created 2D points.
		template <typename T>
		int Point2D<T>::c = V_ZERO;


		//Second '3D Point' template type class inherits its attributes and methods from the '2D Point' class.
		template <typename T>
		class Point3D : public Point2D<T>
			{
				private:
					template <typename U>
					friend std::ostream &operator<< (std::ostream &os, const SpacePoints::Point3D<U> &Sp3D);

					T z = V_ZERO;

				public:
					Point3D(T x, T y, T z) : Point2D<T>(x, y), z(z) {};

					T getZ() const {return this->z;};
					void setZ(const T z) {this->z = z;};

					void print()
						{
							Point2D<T>::print();
							std::cout << "3D Point #" << this->c << ":\t(" << this->z << ")." << std::endl;
						};
			};


	//Overloading the std::cout operator to receive a '2D Point' object type.
	template <typename T>
	inline std::ostream &operator<< (std::ostream &os, const SpacePoints::Point2D<T> &Sp2D)
		{
			os << "* 2D Point #" << Sp2D.c << ":\t(" << Sp2D.x << ", " << Sp2D.y << "). *" << std::endl;

			return os;
		};

	//Overloading the std::cout operator to receive a '3D Point' object type.
	template <typename T>
	inline std::ostream &operator<< (std::ostream &os, const SpacePoints::Point3D<T> &Sp3D)
		{
			os << "* 3D Point #" << Sp3D.c << ":\t(" << Sp3D.getX() << ", " << Sp3D.getY() << ", " << Sp3D.getZ() << "). *" << std::endl;

			return os;
		};
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
		SpacePoints::Point2D<int> Sp2D = SpacePoints::Point2D<int>(int_2D_x, int_2D_y);
		Sp2D.print();
		std::cout << Sp2D << std::endl;

		std::cout << "Generating an instance of a class template of type 3D Point." << std::endl;
		SpacePoints::Point3D<int> Sp3D = SpacePoints::Point3D<int>(int_3D_x, int_3D_y, int_3D_z);
		Sp3D.print();
		std::cout << Sp3D << std::endl;

		std::cout << "Change of 'x' & 'y' coordinates of the 2D Point." << std::endl;
		Sp2D.setX(int_3D_x);
		Sp2D.setY(int_3D_y);
		Sp2D.print();
		std::cout << Sp2D << std::endl;

		std::cout << "Change of 'x' & 'y' coordinates of the 3D Point." << std::endl;
		Sp3D.setX(int_2D_x);
		Sp3D.setY(int_2D_y);
		Sp3D.print();
		std::cout << Sp3D << std::endl;

		std::cout << "Polymorphism by assigning a 3D Point to a 2D Point type." << std::endl;
		SpacePoints::Point2D<int> Sp2x3D = SpacePoints::Point3D<int>(int_3D_x, int_3D_y, int_3D_z);
		Sp2x3D.print();
		std::cout << Sp2x3D << std::endl;

		return V_ZERO;
	}
