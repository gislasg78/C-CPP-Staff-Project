/* This program creates a parent or base class called 'Point2D'
   and exemplifies different features of Object Oriented Programming in C++. */

/* Common work libraries. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'
#define	TABULATOR	'\t'

#define	V_ONE	1
#define V_ZERO  0

/* Base or parent class of the 'Point2D' type. */
template <typename T>
class Point2D
	{
		private:
			const int id = V_ZERO;
			T x = V_ZERO, y = V_ZERO;

			friend std::istream &operator>> (std::istream& in, Point2D<T> &Point2D)
				{Point2D.capture(); return in;}
			friend std::ostream& operator<< (std::ostream &out, const Point2D<T>& Point2D)
				{Point2D.print(); return out;}

		protected:
			static int counter;

		public:
			Point2D() : id(V_ZERO), x(V_ZERO), y(V_ZERO)
				{this->counter++; this->capture();}
			Point2D(const int &id) : id(id), x(V_ZERO), y(V_ZERO)
				{(*this).counter++;}
			Point2D(const T &x, const T &y) : id(V_ZERO), x(x), y(y)
				{(*this).counter++;}
			Point2D(const int &id, const T &x, const T &y) : id(id), x(x), y(y)
				{this->counter++;}

			Point2D(const Point2D<T>& Point2D) : id(Point2D.getId()), x(Point2D.getX()), y(Point2D.getY())
				{this->counter++;}
			Point2D(Point2D<T>&& Point2D) : id(Point2D.getId()), x(Point2D.getX()), y(Point2D.getY())
				{(*this).counter--; Point2D.reset();}

			Point2D<T>& operator=(const T& value)
				{(*this).x = value; (*this).y = value; return *this;}
			Point2D<T>& operator=(const Point2D<T> &Point2D)
				{this->copy(Point2D); return *this;}
			Point2D<T>& operator=(Point2D<T> &&Point2D)
				{this->counter--; (*this).copy(Point2D); Point2D.reset(); return *this;}

			Point2D<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Point2D' object." << std::endl;
					this->see(); this->view(); this->watch(); return *this;
				}

			Point2D<T> operator+(const Point2D<T>& point2D)
				{
					Point2D<T> object_Point2D(point2D.getX(), point2D.getY());
					object_Point2D.getX() += (*this).x;
					object_Point2D.getY() += (*this).y;
					return object_Point2D;
				}
			Point2D<T>& operator+=(const Point2D<T>& Point2D)
				{this->x += Point2D.getX(); this->y += Point2D.getY(); return *this;}
			Point2D<T>& operator+=(const T& value)
				{(*this).x += value; (*this).y += value; return *this;}

			Point2D<T>& operator++()	{++this->x; ++this->y; return *this;}
			Point2D<T>& operator++(int)	{(*this).x++; (*this).y++; return *this;}
			Point2D<T>& operator--()	{--(*this).x; --(*this).y; return *this;}
			Point2D<T>& operator--(int)	{this->x--; this->y--; return *this;}

			Point2D<T> operator-(const Point2D<T>& point2D)
				{
					Point2D<T> object_Point2D(point2D.getX(), point2D.getY());
					object_Point2D.getX() -= (*this).x;
					object_Point2D.getY() -= (*this).y;
					return object_Point2D;
				}
			Point2D<T>& operator-=(const Point2D<T>& Point2D)
				{(*this).x -= Point2D.getX(); (*this).y -= Point2D.getY(); return *this;}
			Point2D<T>& operator-=(const T& value)
				{this->x -= value; this->y -= value; return *this;}

			const T operator!=(const Point2D<T>& Point2D) const
				{return ((this->id != Point2D.getId()) || (this->x != Point2D.getX()) || (this->y != Point2D.getY()));}
			const T operator==(const Point2D<T>& Point2D) const
				{return ((this->id == Point2D.getId()) && (this->x == Point2D.getX()) && (this->y == Point2D.getY()));}
			const T operator>(const Point2D<T>& Point2D) const
				{return (((*this).x > Point2D.getX()) || ((*this).y > Point2D.getY()));}
			const T operator>=(const Point2D<T>& Point2D) const
				{return (((*this).x >= Point2D.getX()) || ((*this).y >= Point2D.getY()));}
			const T operator<(const Point2D<T>& Point2D) const
				{return (((*this).x < Point2D.getX()) || ((*this).y < Point2D.getY()));}
			const T operator<=(const Point2D<T>& Point2D) const
				{return (((*this).x <= Point2D.getX()) || ((*this).y <= Point2D.getY()));}

			const T operator>>(Point2D<T>& point2D)
				{point2D.setX(this->x); point2D.setY(this->y); return this->id;}
			Point2D<T>& operator<<(const Point2D<T>& point2D)
				{(*this).setX(point2D.getX()); (*this).setY(point2D.getY()); return *this;}

			operator int()		const	{return this->id;}
			operator double()	const	{return ((this->y) ? ((double) (*this).x / (double) (*this).y) : V_ZERO);}

			virtual void capture()
				{
					std::cout << "Capture the coordinates of a 'Point2D' object." << std::endl;
					std::cout << "+ X Coord = "; (*this).x = (*this).enter_a_data(&this->x);
					std::cout << "+ Y Coord = "; this->y = this->enter_a_data(&(*this).y);
				}

			template <typename C = T>
			const Point2D<C> convert()	const
				{
					Point2D<C> converted_Point2D(V_ZERO, V_ZERO);
					converted_Point2D.setX(static_cast<C>(this->getX()));
					converted_Point2D.setY(static_cast<C>(this->getY()));
					return converted_Point2D;
				}

			template <typename C = T>
			const Point2D<C> convert(const Point2D<T>& other_Point2D)	const
				{
					Point2D<C> converted_Point2D(V_ZERO, V_ZERO);
					converted_Point2D.getX() = static_cast<C>(other_Point2D.getX());
					converted_Point2D.getY() = static_cast<C>(other_Point2D.getY());
					return converted_Point2D;
				}

			virtual Point2D<T>& copy(const Point2D<T> &Point2D)
				{this->x = Point2D.getX(); this->y = Point2D.getY(); return *this;}

			static const T &enter_a_data(T *const ptr_data)
				{
					if (ptr_data)
						if (std::cin >> *ptr_data)
							std::cout << "Value entered:\t[" << *ptr_data << "]. OK!" << std::endl;
						else
							{
								*ptr_data = V_ZERO;
								std::cerr << "Error! The input does not have a valid value." << std::endl;
							}
					else
						std::cerr << "A valid memory address was not provided." << std::endl;

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);

					return *ptr_data;
				};

			static void enter_a_pause(const std::string& str_Message)
				{
					std::cout << str_Message;
					std::cin.clear();
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
				}

			static const T& enter_a_value(T *const ptr_value)
				{
					if (ptr_value)
						{
							std::string str_value {};
							std::getline(std::cin >> std::ws, str_value);
							str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
							std::stringstream(str_value) >> *ptr_value;

							std::cout << "Value entered:\t[" << *ptr_value << "]. OK!" << std::endl;
						}
					else
						std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

					return *ptr_value;
				}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const int& getId()	const	{return this->id;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()			{return ((this->y) ? ((double) (*this).x / (double) (*this).y) : V_ZERO);}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			getValue()			{return this->getId();}

			const T& getX()		const	{return this->x;}
			const T& getY()		const	{return this->y;}

			T& getX()			{return (*this).x;}
			T& getY()			{return (*this).y;}

			const bool isitme(Point2D<T>& Point2D)	const
				{return (this == &Point2D);}

			virtual Point2D<T>& move(Point2D<T> &&Point2D)
				{this->counter--; this->copy(Point2D); Point2D.reset(); return *this;}

			virtual void print()	const
				{
					std::cout << "Display the current values ​​of a 'Point2D' object." << std::endl;
					(*this).see(); (*this).view(); (*this).watch();
				}

			virtual void reset()		{this->x = V_ZERO; this->y = V_ZERO;}

			void setXY(const T &x = V_ZERO, const T &y = V_ZERO)
				{(*this).x = x; (*this).y = y;}

			void setX(const T &x = V_ZERO)	{this->x = x;}
			void setY(const T &y = V_ZERO)	{this->y = y;}

			virtual void see()	const
				{
					std::cout << "Brief information about the 'Point2D' object." << std::endl;
					std::cout << "+ ID:\t\t[" << (*this).id << "]." << std::endl;
					std::cout << "+ Counter:\t[" << this->counter << "]." << std::endl;
					std::cout << "+ X Coord:\t[" << (*this).x << "]." << std::endl;
					std::cout << "+ Y Coord:\t[" << (*this).y << "]." << std::endl << std::endl;
				}

			virtual void swap()		{T temp = (*this).x; (*this).x = (*this).y; (*this).y = temp;}

			virtual void view()	const
				{
					std::cout << "Extended information about the 'Point2D' object." << std::endl;
					std::cout << "+ ID:\t\t[" << (*this).id << "]\t:\t[" << this->id << "]\t=\t";
					std::cout << "[" << typeid((*this).id).name() << "]\t:\t[" << typeid(this->id).name() << "]." << std::endl;
					std::cout << "+ Counter:\t[" << (*this).counter << "]\t:\t[" << this->counter << "]\t=\t";
					std::cout << "[" << typeid((*this).counter).name() << "]\t:\t[" << typeid(this->counter).name() << "]." << std::endl;
					std::cout << "+ X Coord:\t[" << (*this).x << "]\t:\t[" << this->x << "]\t=\t";
					std::cout << "[" << typeid((*this).x).name() << "]\t:\t[" << typeid(this->x).name() << "]." << std::endl;
					std::cout << "+ Y Coord:\t[" << (*this).y << "]\t:\t[" << this->y << "]\t=\t";
					std::cout << "[" << typeid((*this).y).name() << "]\t:\t[" << typeid(this->y).name() << "]." << std::endl << std::endl;
				}

			virtual void watch()	const
				{
					std::cout << "Specific information about the 'Point2D' object." << std::endl;
					std::cout << "(ID = [" << this->id << "], ";
					std::cout << "Counter = [" << this->counter << "])." << TABULATOR;
					std::cout << "(X Coord = [" << this->x << "], ";
					std::cout << "Y Coord = [" << this->y << "])." << std::endl << std::endl;
				}

			virtual ~Point2D() = default;
	};

/* Initialization of the static accounting variable of the 'Point2D' class. */
template <typename T>
int Point2D<T>::counter = V_ZERO;

/* Derived class of the 'Point2D' type thru 'Point3D' class. */
template <typename T>
class Point3D : public Point2D<T>
	{
		private:
			Point2D<T> base;
			T z = V_ZERO;

			friend std::istream &operator>> (std::istream& in, Point3D<T> &Point3D)
				{Point3D.capture(); return in;}
			friend std::ostream& operator<< (std::ostream &out, const Point3D<T>& Point3D)
				{Point3D.print(); return out;}

		public:
			Point3D() : Point2D<T>(V_ZERO, V_ZERO), z(V_ZERO)
				{this->counter++; this->capture();}
			Point3D(const int &z) : Point2D<T>(V_ZERO, V_ZERO), z(z)
				{(*this).counter++;}
			Point3D(const T &x, const T &y) : Point2D<T>(x, y), z(V_ZERO)
				{(*this).counter++;}
			Point3D(const T &x, const T &y, const T &z) : Point2D<T>(x, y), z(z)
				{(*this).counter++;}
			Point3D(const int &id, const T &x, const T &y, const T &z) : Point2D<T>(id, x, y), z(z)
				{this->counter++;}

			Point3D(const Point3D<T>& Point3D) : Point2D<T>(Point3D.getId(), Point3D.getX(), Point3D.getY()), z(Point3D.getZ())
				{this->counter++;}
			Point3D(Point3D<T>&& Point3D) : Point2D<T>(Point3D.getId(), Point3D.getX(), Point3D.getY()), z(Point3D.getZ())
				{(*this).counter--; Point3D.reset();}

			Point3D<T>& operator=(const T& value)
				{(*this).z = value; return *this;}
			Point3D<T>& operator=(const Point3D<T> &Point3D)
				{this->copy(Point3D); return *this;}
			Point3D<T>& operator=(Point3D<T> &&Point3D)
				{this->counter--; (*this).copy(Point3D); Point3D.reset(); return *this;}

			Point3D<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Point3D' object." << std::endl;
					this->see(); this->watch(); return *this;
				}

			Point3D<T> operator+(const Point3D<T>& point3D)
				{
					Point3D<T> object_Point3D(point3D.getX(), point3D.getY(), point3D.getZ());
					object_Point3D.getX() += (*this).getX();
					object_Point3D.getY() += (*this).getY();
					object_Point3D.getZ() += (*this).getZ();
					return object_Point3D;
				}
			Point3D<T>& operator+=(const Point3D<T>& Point3D)
				{(*this).getX() += Point3D.getX(); (*this).getY() += Point3D.getY(); this->z += Point3D.getZ(); return *this;}
			Point3D<T>& operator+=(const T& value)
				{this->z += value; return *this;}

			Point3D<T>& operator++()	{++this->z; return *this;}
			Point3D<T>& operator++(int)	{(*this).z++; return *this;}
			Point3D<T>& operator--()	{--(*this).z; return *this;}
			Point3D<T>& operator--(int)	{this->z--; return *this;}

			Point3D<T> operator-(const Point3D<T>& point3D)
				{
					Point3D<T> object_Point3D(point3D.getX(), point3D.getY(), point3D.getZ());
					object_Point3D.getX() -= (*this).getX();
					object_Point3D.getY() -= (*this).getY();
					object_Point3D.getZ() -= (*this).getZ();
					return object_Point3D;
				}
			Point3D<T>& operator-=(const Point3D<T>& Point3D)
				{(*this).getX() -= Point3D.getX(); (*this).getY() -= Point3D.getY(); this->z -= Point3D.getZ(); return *this;}
			Point3D<T>& operator-=(const T& value)
				{this->z -= value; return *this;}

			const T operator!=(const Point3D<T>& Point3D) const
				{return ((this->getId() != Point3D.getId()) || (this->getX() != Point3D.getX()) || (this->getY() != Point3D.getY()) || (this->z != Point3D.getZ()));}
			const T operator==(const Point3D<T>& Point3D) const
				{return ((this->getId() == Point3D.getId()) && (this->getX() == Point3D.getX()) && (this->getY() == Point3D.getY()) && (this->z != Point3D.getZ()));}
			const T operator>(const Point3D<T>& Point3D) const
				{return ((*this).z > Point3D.getZ());}
			const T operator>=(const Point3D<T>& Point3D) const
				{return ((*this).z >= Point3D.getZ());}
			const T operator<(const Point3D<T>& Point3D) const
				{return ((*this).z < Point3D.getZ());}
			const T operator<=(const Point3D<T>& Point3D) const
				{return ((*this).z <= Point3D.getZ());}

			const T operator>>(Point3D<T>& point3D)
				{point3D.setX(this->x); point3D.setY(this->y); point3D.setZ(this->z); return this->getId();}
			const T operator>> (const T& z)
				{return this->z;}
			Point3D<T>& operator<<(const Point3D<T>& point3D)
				{(*this).setX(point3D.getX()); (*this).setY(point3D.getY()); (*this).z = point3D.getZ(); return *this;}
			Point3D<T>& operator<<(const T& z)
				{(*this).z = z; return *this;}

			operator int()		const	{return (*this).getId();}
			operator double()	const	{return (*this).getZ();}

			virtual void capture()
				{
					std::cout << "Capture the coordinates of a 'Point3D' object." << std::endl;
					std::cout << "+ Z Coord = "; this->z = this->enter_a_data(&this->z);
					Point2D<T>::capture();
				}

			template <typename C = T>
			const Point3D<C> convert()	const
				{
					Point3D<C> converted_Point3D(V_ZERO, V_ZERO, V_ZERO);
					converted_Point3D.setX(static_cast<C>(this->getX()));
					converted_Point3D.setY(static_cast<C>(this->getY()));
					converted_Point3D.setZ(static_cast<C>(this->getZ()));
					return converted_Point3D;
				}

			template <typename C = T>
			const Point3D<C> convert(const Point3D<T>& other_Point3D)	const
				{
					Point3D<C> converted_Point3D(V_ZERO, V_ZERO, V_ZERO);
					converted_Point3D.getX() = static_cast<C>(other_Point3D.getX());
					converted_Point3D.getY() = static_cast<C>(other_Point3D.getY());
					converted_Point3D.getZ() = static_cast<C>(other_Point3D.getZ());
					return converted_Point3D;
				}

			virtual Point3D<T>& copy(const Point3D<T> &Point3D)
				{this->setX(Point3D.getX()); this->setY(Point3D.getY()); this->setZ(Point3D.getZ()); return *this;}
			virtual Point3D<T>& copy(const Point2D<T> &Point2D)
				{(*this).setX(Point2D.getX()); (*this).setY(Point2D.getY()); return *this;}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()			{return this->getZ();}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			getValue()			{return this->getId();}

			const T& getZ()		const	{return this->z;}
			T& getZ()			{return (*this).z;}

			const bool isitme(Point3D<T>& Point3D)	const
				{return (this == &Point3D);}

			virtual Point3D<T>& move(Point3D<T> &&Point3D)
				{this->counter--; this->copy(Point3D); Point3D.reset(); return *this;}
			virtual Point3D<T>& move(Point2D<T> &&Point2D)
				{this->counter--; (*this).copy(Point2D); Point2D.reset(); return *this;}

			virtual void print()	const
				{
					std::cout << "Display the current values ​​of a 'Point3D' object." << std::endl;
					(*this).see(); (*this).view(); (*this).watch();
				}

			virtual void reset()		{Point2D<T>::reset(); this->z = V_ZERO;}

			void setZ(const T &z = V_ZERO)	{(*this).z = z;}

			virtual void see()	const
				{
					std::cout << "Brief information about the 'Point3D' object." << std::endl;
					std::cout << "+ Z Coord:\t[" << this->z << "]." << std::endl << std::endl;
					Point2D<T>::see();
				}

			virtual void view()	const
				{
					std::cout << "Extended information about the 'Point3D' object." << std::endl;
					std::cout << "+ Z Coord:\t[" << (*this).z << "]\t:\t[" << this->z << "]\t=\t";
					std::cout << "[" << typeid((*this).z).name() << "]\t:\t[" << typeid(this->z).name() << "]." << std::endl << std::endl;
					Point2D<T>::view();
				}

			virtual void watch()	const
				{
					std::cout << "Specific information about the 'Point3D' object." << std::endl;
					std::cout << "(Z Coord = [" << this->z << "])." << std::endl << std::endl;
					Point2D<T>::watch();
				}

			virtual ~Point3D() = default;
	};

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int quantity = V_ZERO;
		int x = V_ZERO, y = V_ZERO, z = V_ZERO;

		/* Initial header messages. */
		std::cout << "Creating 'Point2D' objects on an array." << std::endl;
		std::cout << "How many 'Point2D' do you want to create? : ";
		quantity = Point2D<int>::enter_a_value(&quantity);

		/* The dynamic array of pointers to objects of type 'Point2D' is created. */
		Point2D<int> **array_Point2D = new Point2D<int>* [quantity];

		/* Each object of type 'Point2D' is created and stored in an array of pointers of the same type. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << "+ x = "; x = Point2D<int>::enter_a_value(&x);
				std::cout << "+ y = "; y = Point2D<int>::enter_a_value(&y);
				std::cout << "+ z = "; z = Point2D<int>::enter_a_value(&z);

				array_Point2D[idx] = new Point3D<int>(idx + V_ONE, x, y, z);

				std::cout << std::endl << "Object created and assigned." << std::endl;
				std::cout << "+ ID Value:\t[" << static_cast<int>(*array_Point2D[idx]) << "]." << std::endl;
				std::cout << "+ [x] / [y]:\t[" << static_cast<double>(*array_Point2D[idx]) << "]." << std::endl;
				std::cout << "+ Values:\tId: [" << array_Point2D[idx]->getId() << "].\t(x = [" << (*array_Point2D[idx]).getX() << "], y = [" << (*array_Point2D[idx]).getY() << "])." << std::endl;
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				if (Point3D<int> *my_Point3D = dynamic_cast<Point3D<int>*>(array_Point2D[idx]))
					{
						std::cout << "\t\t\t\t(z = [" << (*my_Point3D).getZ() << "])." << std::endl;
						std::cout << "+ Point3D:\t[" << my_Point3D->getValue() << "]." << std::endl;
						Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
					}

				std::cout << "+ Point2D:\t[" << array_Point2D[idx]->getValue() << "]." << std::endl;
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				if (Point2D<int>* my_Point2D = dynamic_cast<Point2D<int>*>(*(array_Point2D + idx)))
					{
						std::cout << "+ Point2D:\t[" << my_Point2D->getValue() << "]." << std::endl;
						Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
					}


				std::cout << "+ Is it me?:\t[" << std::boolalpha << array_Point2D[idx]->isitme(*array_Point2D[idx]) << "]." << std::endl;
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* An internal method of the 'Point2D' object is used to display the assigned values. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Point2D[idx]->print();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* New values ​​are reassigned and captured to created objects of type 'Point2D' */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cin >> *(*(array_Point2D + idx));
				std::cout << *array_Point2D[idx];
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* Using the overloaded increment and decrement operators in the 'Point2D' class. */
		std::cout << std::endl << "Increment and decrement the values ​​of the 'Point2D' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				/* Display header. */
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Point2D[idx]->print();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Different nomenclatures with pointer notation with 'Point2D' objects and array notation. */
				std::cout << std::endl << "Increment by one unit the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx])++;
				(*array_Point2D[idx]).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx]).swap();
				(*array_Point2D[idx]).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Decrement by one unit the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx])--;
				(*array_Point2D[idx]).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx]).swap();
				(*array_Point2D[idx]).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Increment by one unit the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx)))++;
				(*(*(array_Point2D + idx))).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx))).swap();
				(*(*(array_Point2D + idx))).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Decrement by one unit the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx)))--;
				(*(*(array_Point2D + idx))).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx))).swap();
				(*(*(array_Point2D + idx))).watch();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Various ways to call methods on an array of object pointers (pointer of pointers). */
				std::cout << std::endl << "Initializing the values ​​in the units of the coordinates of a 'Point2D' object." << std::endl;
				array_Point2D[idx]->reset();
				(*array_Point2D[idx]).reset();
				(*(array_Point2D + idx))->reset();
				(*(*(array_Point2D + idx))).reset();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Observing initialized values ​​of the 'Circle' object. */
				std::cout << std::endl << "Observing initialized values ​​of the 'Point2D' object." << std::endl;
				array_Point2D[idx]->see();
				(*array_Point2D[idx]).see();
				(*(array_Point2D + idx))->see();
				(*(*(array_Point2D + idx))).see();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Calling in various ways to an overloaded operator. */
				std::cout << std::endl << "Succinct display of the coordinate values ​​of a 'Point2D' object." << std::endl;
				(*array_Point2D[idx])();
				(*(*(array_Point2D + idx)))();
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* All dynamically created instances of objects of type 'Point2D' are purged. */
		std::cout << std::endl << "Clearing 'Point2D' objects..." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << "Deleting object 'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				delete *(array_Point2D + idx);
				Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* Deleting the array of pointer objects of type 'Point2D'. */
		std::cout << "Deleting the array of pointers of type 'Point2D'..." << std::endl;
		delete [] array_Point2D;
		Point2D<int>::enter_a_pause("\nPress the ENTER key to continue...");

		return V_ZERO;
	}
