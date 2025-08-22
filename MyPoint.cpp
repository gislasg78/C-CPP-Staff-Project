/* This program creates a parent or base class called 'Point2D'
   and exemplifies different features of Object Oriented Programming in C++.
*/
/* Common work libraries. */
#include <iostream>
#include <limits>

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

			Point2D<T>& operator= (const Point2D<T> &Point2D)
				{this->copy(Point2D); return *this;}
			Point2D<T>& operator= (Point2D<T> &&Point2D)
				{this->counter--; (*this).copy(Point2D); Point2D.reset(); return *this;}

			Point2D<T>& operator()()
				{
					std::cout << "Show the current values ​​of a '2D Point'." << std::endl;
					this->see(); this->view(); this->watch(); return *this;
				}

			Point2D<T>& operator++()	{++this->x; ++this->y; return *this;}
			Point2D<T>& operator++(int)	{(*this).x++; (*this).y++; return *this;}
			Point2D<T>& operator--()	{--(*this).x; --(*this).y; return *this;}
			Point2D<T>& operator--(int)	{this->x--; this->y--; return *this;}

			operator int()		const	{return this->id;}

			virtual void capture()
				{
					std::cout << "Capture the coordinates of a '2D Point'." << std::endl;
					std::cout << "+ X Coord = "; std::cin >> this->x;
					std::cout << "+ Y Coord = "; std::cin >> this->y;
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
					converted_Point2D.setX(static_cast<C>(other_Point2D.getX()));
					converted_Point2D.setY(static_cast<C>(other_Point2D.getY()));
					return converted_Point2D;
				}

			virtual Point2D<T>& copy(const Point2D<T> &Point2D)
				{this->x = Point2D.getX(); this->y = Point2D.getY(); return *this;}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const int& getId()	const	{return this->id;}
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
					std::cout << "Display the current values ​​of a '2D Point'." << std::endl;
					(*this).see(); (*this).view();
				}

			virtual void reset()		{this->x = V_ZERO; this->y = V_ZERO;}

			void setXY(const T &x = V_ZERO, const T &y = V_ZERO)
				{(*this).x = x; (*this).y = y;}

			void setX(const T &x = V_ZERO)	{this->x = x;}
			void setY(const T &y = V_ZERO)	{this->y = y;}

			virtual void see()	const
				{
					std::cout << "(ID = [" << (*this).id << "] : [" << this->id << "] = ";
					std::cout << "[" << typeid((*this).id).name() << "] : [" << typeid(this->id).name() << "], ";
					std::cout << "Counter = [" << (*this).counter << "] : [" << this->counter << "] = ";
					std::cout << "[" << typeid((*this).counter).name()<< "] : [" << typeid(this->counter).name() << "])." << TABULATOR;
					std::cout << "(X Coord = [" << this->x << "] : [" << (*this).x << "] = ";
					std::cout << "[" << typeid((*this).x).name() << "] : [" << typeid(this->x).name() << "], ";
					std::cout << "Y Coord = [" << this->y << "] : [" << (*this).y << "] = ";
					std::cout << "[" << typeid((*this).y).name() << "] : [" << typeid(this->y).name() << "])." << std::endl;
				}

			virtual void swap()		{T temp = (*this).x; (*this).x = (*this).y; (*this).y = temp;}

			virtual void view()	const
				{
					std::cout << std::endl << "Information about the '2D Point' object." << std::endl;
					std::cout << "+ ID:\t\t[" << (*this).id << "] : [" << this->id << "] = ";
					std::cout << "[" << typeid((*this).id).name() << "] : [" << typeid(this->id).name() << "]." << std::endl;
					std::cout << "+ Counter:\t[" << (*this).counter << "] : [" << this->counter << "] = ";
					std::cout << "[" << typeid((*this).counter).name() << "] : [" << typeid(this->counter).name() << "]." << std::endl;
					std::cout << "+ X Coord:\t[" << (*this).x << "] : [" << this->x << "] = ";
					std::cout << "[" << typeid((*this).x).name() << "] : [" << typeid(this->x).name() << "]." << std::endl;
					std::cout << "+ Y Coord:\t[" << (*this).y << "] : [" << this->y << "] = ";
					std::cout << "[" << typeid((*this).y).name() << "] : [" << typeid(this->y).name() << "]." << std::endl << std::endl;
				}

			virtual void watch()	const
				{
					std::cout << "(ID = [" << this->id << "], ";
					std::cout << "Counter = [" << this->counter << "])." << TABULATOR;
					std::cout << "(X Coord = [" << this->x << "], ";
					std::cout << "Y Coord = [" << this->y << "])." << std::endl;
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

			Point3D<T>& operator= (const Point3D<T> &Point3D)
				{this->copy(Point3D); return *this;}
			Point3D<T>& operator= (Point3D<T> &&Point3D)
				{this->counter--; (*this).copy(Point3D); Point3D.reset(); return *this;}

			Point3D<T>& operator()()
				{
					std::cout << "Show the current values ​​of a '3D Point'." << std::endl;
					this->see(); this->watch(); return *this;
				}

			Point3D<T>& operator++()	{++this->z; return *this;}
			Point3D<T>& operator++(int)	{(*this).z++; return *this;}
			Point3D<T>& operator--()	{--(*this).z; return *this;}
			Point3D<T>& operator--(int)	{this->z--; return *this;}

			operator int()		const	{return (*this).getId();}

			virtual void capture()
				{
					std::cout << "Capture the coordinates of a '3D Point'." << std::endl;
					std::cout << "+ Z Coord = "; std::cin >> this->z;
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
					converted_Point3D.setX(static_cast<C>(other_Point3D.getX()));
					converted_Point3D.setY(static_cast<C>(other_Point3D.getY()));
					converted_Point3D.setZ(static_cast<C>(other_Point3D.getZ()));
					return converted_Point3D;
				}

			virtual Point3D<T>& copy(const Point3D<T> &Point3D)
				{this->setX(Point3D.getX()); this->setY(Point3D.getY()); this->setZ(Point3D.getZ()); return *this;}
			virtual Point3D<T>& copy(const Point2D<T> &Point2D)
				{(*this).setX(Point2D.getX()); (*this).setY(Point2D.getY()); return *this;}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

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
					std::cout << "Display the current values ​​of a '3D Point'." << std::endl;
					(*this).see(); (*this).view(); (*this).watch();
				}

			virtual void reset()		{this->z = V_ZERO;}

			void setZ(const T &z = V_ZERO)	{(*this).z = z;}

			virtual void see()	const
				{
					std::cout << "(Z Coord = [" << this->z << "] : [" << (*this).z << "] = ";
					std::cout << "[" << typeid((*this).z).name() << "] : [" << typeid(this->z).name() << "])." << std::endl;
					Point2D<T>::see();
				}

			virtual void view()	const
				{
					std::cout << std::endl << "Information about the '3D Point' object." << std::endl;
					std::cout << "+ Z Coord:\t[" << (*this).z << "] : [" << this->z << "] = ";
					std::cout << "[" << typeid((*this).z).name() << "] : [" << typeid(this->z).name() << "]." << std::endl;
					Point2D<T>::view();
				}

			virtual void watch()	const
				{
					std::cout << "(Z Coord = [" << this->z << "])." << std::endl;
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
		std::cin >> quantity;

		/* The dynamic array of pointers to objects of type 'Point2D' is created. */
		Point2D<int> **array_Point2D = new Point2D<int>* [quantity];

		/* Each object of type 'Point2D' is created and stored in an array of pointers of the same type. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << "x = "; std::cin >> x;
				std::cout << "y = "; std::cin >> y;
				std::cout << "z = "; std::cin >> z;

				array_Point2D[idx] = new Point3D<int>(idx + V_ONE, x, y, z);

				std::cout << std::endl << "Object created and assigned." << std::endl;
				std::cout << "+ ID Value:\t[" << static_cast<int>(*array_Point2D[idx]) << "]." << std::endl;
				std::cout << "+ Values:\tId: [" << array_Point2D[idx]->getId() << "].\t(x = [" << (*array_Point2D[idx]).getX() << "], y = [" << (*array_Point2D[idx]).getY() << "])." << std::endl;

				if (Point3D<int> *my_Point3D = dynamic_cast<Point3D<int>*>(array_Point2D[idx]))
					std::cout << "\t\t\t\t(z = [" << (*my_Point3D).getZ() << "])." << std::endl;

				std::cout << "+ Is it me?:\t[" << array_Point2D[idx]->isitme(*array_Point2D[idx]) << "]." << std::endl;

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.
			}

		/* An internal method of the 'Point2D' object is used to display the assigned values. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Point2D[idx]->print();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.
			}

		/* New values ​​are reassigned and captured to created objects of type 'Point2D' */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cin >> *(*(array_Point2D + idx));
				std::cout << *array_Point2D[idx];

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.
			}

		/* Using the overloaded increment and decrement operators in the 'Point2D' class. */
		std::cout << std::endl << "Increment and decrement the values ​​of the 'Point2D' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				/* Display header. */
				std::cout << std::endl << "'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Point2D[idx]->print();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				/* Different nomenclatures with pointer notation with 'Point2D' objects and array notation. */
				std::cout << std::endl << "Increment by one unit the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx])++;
				(*array_Point2D[idx]).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx]).swap();
				(*array_Point2D[idx]).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Decrement by one unit the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx])--;
				(*array_Point2D[idx]).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*array_Point2D[idx]).swap();
				(*array_Point2D[idx]).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Increment by one unit the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx)))++;
				(*(*(array_Point2D + idx))).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx))).swap();
				(*(*(array_Point2D + idx))).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Decrement by one unit the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx)))--;
				(*(*(array_Point2D + idx))).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				std::cout << std::endl << "Exchange values ​​in the units of the coordinates of a '2D Point' object." << std::endl;
				(*(*(array_Point2D + idx))).swap();
				(*(*(array_Point2D + idx))).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				/* Various ways to call methods on an array of object pointers (pointer of pointers). */
				std::cout << std::endl << "Initializing the values ​​in the units of the coordinates of a 'Point2D' object." << std::endl;
				array_Point2D[idx]->reset();
				(*array_Point2D[idx]).reset();
				(*(array_Point2D + idx))->reset();
				(*(*(array_Point2D + idx))).reset();

				array_Point2D[idx]->see();
				(*array_Point2D[idx]).see();
				(*(array_Point2D + idx))->see();
				(*(*(array_Point2D + idx))).see();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.


				/* Calling in various ways to an overloaded operator. */
				std::cout << std::endl << "Succinct display of the coordinate values ​​of a 'Point2D' object." << std::endl;
				(*array_Point2D[idx])();
				(*(*(array_Point2D + idx)))();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the bufer.
			}

		/* All dynamically created instances of objects of type 'Point2D' are purged. */
		std::cout << std::endl << "Clearing 'Point2D' objects..." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << "Deleting object 'Point2D' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				delete *(array_Point2D + idx);
			}

		/* Deleting the array of pointer objects of type 'Point2D'. */
		std::cout << "Deleting the array of pointers of type 'Point2D'..." << std::endl;
		delete [] array_Point2D;

		return V_ZERO;
	}
