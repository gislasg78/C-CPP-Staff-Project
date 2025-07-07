//General Work Libraries.
#include <iostream>
#include <iterator>
#include <vector>

//Symbolic constant of work.
#define	V_ZERO	0

//First '2D Point' template type class.
template <typename T>
class Point2D
	{
		private:
			T x = V_ZERO, y = V_ZERO;

			template <typename U>
			friend std::istream& operator>> (std::istream& in, Point2D<U> &Sp2D);
			template <typename U>
			friend std::ostream &operator<< (std::ostream &os, const Point2D<U> &Sp2D);

		protected:
			static int c;

		public:
			Point2D()				{this->c++; this->capture();}
			Point2D (T &x, T &y) : x(x), y(y)	{this->c++;};

			virtual void capture()
				{
					std::cout << "Capturing coordinates of a 'Point2D' object..." << std::endl;
					std::cout << "x = "; std::cin >> this->x;
					std::cout << "y = "; std::cin >> this->y;
				}

			T getX() const				{return this->x;};
			T getY() const				{return this->y;};

			virtual void print() const
				{
					std::cout << "Displaying values ​​of a 'Point2D' type object..." << std::endl;
					std::cout << "2D Point # " << this->c << std::endl;
					std::cout << "(x = [" << this->x << "], y = [" << this->y << "])." << std::endl;
				};

			void setX(const T &x)			{this->x = x;};
			void setY(const T &y)			{this->y = y;};

			virtual ~Point2D() = default;
	};

//Initialization of the static count value of created 2D points.
template <typename T>
int Point2D<T>::c = V_ZERO;

//Second '3D Point' template type class inherits its attributes and methods from the '2D Point' class.
template <typename T>
class Point3D : public Point2D<T>
	{
		private:
			T z = V_ZERO;

			template <typename U>
			friend std::istream &operator>> (std::istream& in, Point3D<U> &Sp3D);
			template <typename U>
			friend std::ostream &operator<< (std::ostream &os, const Point3D<U> &Sp3D);

		public:
			Point3D()				{this->capture();}

			Point3D(T &x, T &y, T &z) : Point2D<T>(x, y), z(z) {};

			virtual void capture()
				{
					Point2D<T>::capture();
					std::cout << "Capturing coordinates of a 'Point3D' object..." << std::endl;
					std::cout << "z = "; std::cin >> this->z;
				}

			T getZ() const				{return this->z;};

			void print() const
				{
					Point2D<T>::print();
					std::cout << "Displaying values ​​of a 'Point3D' type object..." << std::endl;
					std::cout << "3D Point # " << this->c << std::endl;
					std::cout << "(x = [" << this->getX() << "], y = [" << this->getY() << "], z = [" << this->z << "])." << std::endl;
				};

			void setZ(const T &z) {this->z = z;};

			virtual ~Point3D() = default;
	};

//Line class.
template <typename T>
class Line
	{

		private:
			/* Storing a vector of 'Point2D' objects. */
			std::vector<Point2D<T>> vSp2D{};

		public:
			/* Add a 'Point2D' class to the 'Point2D' point vector. */
			void add(const Point2D<T> &Sp2D)
				{
					std::cout << "2D Point:\t(x = [" << Sp2D.getX() << "], y = [" << Sp2D.getY() << "])." << std::endl;
					vSp2D.push_back(Sp2D);
				};

			/* Clear 'Point2D' point vector. */
			void clear()
				{
					std::cout << "All the points that made up the line have been cleaned." << std::endl;
					vSp2D.clear();
				};

			/* Print saved 'Point2D' classes. */
			virtual void print() const
				{
					std::cout << "'Point2D' classes added to the 'Line' class." << std::endl;

					for (auto it_vSp2D = std::begin(vSp2D); it_vSp2D != std::end(vSp2D); it_vSp2D++)
						{
							std::cout << "2D Point:\t(x = [" << it_vSp2D->getX() << "], y = [" << it_vSp2D->getY() << "])." << std::endl;
						}

					std::cout << "[" << vSp2D.size() << "] 'Point2D' classes contained." << std::endl;
				};
	};

//Overloading the >> operator to read 'x' and 'y' values ​​from std::cin for 'Point2D' object.
template <typename T>
inline std::istream &operator>> (std::istream &in, Point2D<T> &Sp2D)
	{
		T x = V_ZERO, y = V_ZERO;

		std::cout << "Setting coordinates of a 'Point2D' type object..." << std::endl;
		std::cout << "x = "; std::cin >> x;	//Read the value of 'x'.
		std::cout << "y = "; std::cin >> y;	//Read the value of 'y'.

		Sp2D.setX(x); Sp2D.setY(y);

		std::cout << "New 'Point2D' coordinates established." << std::endl << std::endl;

		return in;
	}

//Overloading the std::cout operator to receive a '2D Point' object type.
template <typename T>
inline std::ostream &operator<< (std::ostream &os, const Point2D<T> &Sp2D)
	{
		std::cout << "Showing values ​​of a 'Point2D' type object..." << std::endl;
		std::cout << "2D Point # " << Sp2D.c << std::endl;
		std::cout << "(x = [" << Sp2D.getX() << "], y = [" << Sp2D.getY() << "])." << std::endl;

		return os;
	};

//Overloading the >> operator to read 'x', 'y' and 'z' values ​​from std::cin for 'Point3D' object.
template <typename T>
inline std::istream &operator>> (std::istream& in, Point3D<T> &Sp3D)
	{
		T x = V_ZERO, y = V_ZERO, z = V_ZERO;

		std::cout << "Setting coordinates of a 'Point3D' type object..." << std::endl;
		std::cout << "x = "; std::cin >> x;	//Read the value of 'x'.
		std::cout << "y = "; std::cin >> y;	//Read the value of 'y'.
		std::cout << "z = "; std::cin >> z;	//Read the value of 'z'.

		Sp3D.setX(x); Sp3D.setY(y); Sp3D.setZ(z);

		std::cout << "New 'Point3D' coordinates established." << std::endl << std::endl;

		return in;
	};

//Overloading the std::cout operator to receive a '3D Point' object type.
template <typename T>
inline std::ostream &operator<< (std::ostream &os, const Point3D<T> &Sp3D)
	{
		std::cout << "Showing values ​​of a 'Point3D' type object..." << std::endl;
		std::cout << "3D Point # " << Sp3D.c << std::endl;
		std::cout << "(x = [" << Sp3D.getX() << "], y = [" << Sp3D.getY() << "], z = [" << Sp3D.getZ() << "])." << std::endl;

		return os;
	};

int main()
	{
		int int_2D_x = V_ZERO, int_2D_y = V_ZERO;
		int int_3D_x = V_ZERO, int_3D_y = V_ZERO, int_3D_z = V_ZERO;

		std::cout << "Coordinates of two points in the 2D Cartesian plane & 3D plane." << std::endl;

		std::cout << std::endl;
		std::cout << "First Point 2D." << std::endl;
		std::cout << "- X Coord: "; std::cin >> int_2D_x;
		std::cout << "- Y Coord: "; std::cin >> int_2D_y;

		std::cout << std::endl;
		std::cout << "Second Point 3D." << std::endl;
		std::cout << "- X Coord: "; std::cin >> int_3D_x;
		std::cout << "- Y Coord: "; std::cin >> int_3D_y;
		std::cout << "- Z Coord: "; std::cin >> int_3D_z;

		std::cout << std::endl;
		std::cout << "Results." << std::endl;
		std::cout << "--------" << std::endl;

		std::cout << "Generating an instance of a class template of type '2D Point'." << std::endl;
		Point2D<int> Sp2D = Point2D<int>(int_2D_x, int_2D_y);
		Sp2D.print();
		std::cout << Sp2D << std::endl;

		std::cout << "Generating an instance of a class template of type '3D Point'." << std::endl;
		Point3D<int> Sp3D = Point3D<int>(int_3D_x, int_3D_y, int_3D_z);
		Sp3D.print();
		std::cout << Sp3D << std::endl;

		std::cout << "Change of 'x' & 'y' coordinates of the '2D Point' object." << std::endl;
		Sp2D.capture();
		Sp2D.print();
		std::cout << Sp2D << std::endl;

		std::cout << "Change of 'x' & 'y' coordinates of the '3D Point' object." << std::endl;
		Sp3D.capture();
		Sp3D.print();
		std::cout << Sp3D << std::endl;

		std::cout << "Setting new coordinates for '2D Point' object." << std::endl;
		std::cin >> Sp2D;
		Sp2D.print();
		std::cout << Sp2D << std::endl;

		std::cout << "Setting new coordinates for '3D Point' object." << std::endl;
		std::cin >> Sp3D;
		Sp3D.print();
		std::cout << Sp3D << std::endl;

		std::cout << "Polymorphism by assigning a '3D Point' class to a '2D Point' object." << std::endl;
		Point2D<int> Sp2x3D = Point3D<int>();
		Sp2x3D.print();
		std::cout << Sp2x3D << std::endl;

		std::cout << "Setting new coordinates for '2D Point' in '3D Point' class." << std::endl;
		Sp2x3D.capture();
		Sp2x3D.print();
		std::cout << Sp2x3D;

		std::cin >> Sp2x3D;
		Sp2x3D.print();
		std::cout << Sp2x3D << std::endl;

		std::cout << "The necessary points are added and displayed in a 'Line' class." << std::endl;
		Line<int> line;
		line.add(Sp2D);
		line.add(Sp3D);
		line.add(Sp2x3D);
		line.print();
		line.clear();
		std::cout << "Program finished..." << std::endl;

		return V_ZERO;
	}
