#include <iostream>

#define V_ZERO  0

class Point2D
	{
		private:
			friend std::ostream &operator<< (std::ostream &os, const Point2D &p2D);

		protected:
			int int_x=V_ZERO, int_y=V_ZERO;
			static int int_Point_Count;

		public:
			Point2D (int int_x, int int_y) : int_x(int_x), int_y(int_y) {this->int_Point_Count++;};
	};

class Point3D : public Point2D
	{
		private:
			friend std::ostream &operator<< (std::ostream &os, const Point3D &p3D);
			int int_z=V_ZERO;

		public:
			Point3D(int int_x, int int_y, int int_z) : Point2D(int_x, int_y) {this->int_z=int_z;};
	};

int Point2D::int_Point_Count=V_ZERO;

inline std::ostream &operator<< (std::ostream &os, const Point2D &p2D)
	{
		os << "Point # " << p2D.int_Point_Count << std::endl;
		os << "p(" << p2D.int_x << "," << p2D.int_y << ")" << std::endl;

		return os;
	};

inline std::ostream &operator<< (std::ostream &os, const Point3D &p3D)
	{
		os << "Point # " << p3D.int_Point_Count << std::endl;
		os << "p(" << p3D.int_x << "," << p3D.int_y << "," << p3D.int_z << ")" << std::endl;

		return os;
	};

int main()
	{
		int int_2D_x=V_ZERO, int_2D_y=V_ZERO;
		int int_3D_x=V_ZERO, int_3D_y=V_ZERO, int_3D_z=V_ZERO;

		std::cout << "Coordinates of two points in the 2D & 3D Cartesian plane." << std::endl;

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

		Point2D p2D = Point2D(int_2D_x, int_2D_y);
		std::cout << p2D << std::endl;

		Point2D pPD = Point3D(int_3D_x, int_3D_y, int_3D_z);
		std::cout << pPD << std::endl;

		Point3D p3D = Point3D(int_3D_x, int_3D_y, int_3D_z);
		std::cout << p3D << std::endl;

		return V_ZERO;
	}
