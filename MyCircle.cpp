/* This program calculates the area and perimeter of an instantiated class
   called 'Circle' and this is used to calculate another instantiable class
   called 'Cylinder'. */

//Classes and uniform initialization.
#include <iostream>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_PI	3.14159265
#define	V_TWO	2
#define	V_ZERO	0


/* Circle Class. Base Class.*/
template <class T>
class Circle
	{
		private:
			const int id = V_ZERO;
			const double PI = V_PI;
			T radius = V_ZERO;

			template <class C = T>
			friend std::istream &operator>> (std::istream& in, Circle<C> &circle)
				{circle.capture(); return in;}
			template <class C = T>
			friend std::ostream& operator<< (std::ostream &out, const Circle<C>& circle)
				{circle.print(); return out;}

		protected:
			static int counter;

		public:
			Circle() : id(V_ZERO), radius(V_ZERO)
				{(*this).counter++; this->capture();}
			Circle(const int& id, const T& radius) : id(id), radius(radius)
				{this->counter++;}
			Circle(const T &radius) : id(V_ZERO), radius(radius)
				{this->counter++;}

			Circle(const Circle<T>& circle) : id(circle.getId()), radius(circle.getRadius())
				{(*this).counter++;};
			Circle(Circle<T>&& circle) : id(circle.getId()), radius(circle.getRadius())
				{this->counter--; circle.reset();}

			Circle<T>& operator= (const Circle<T>& circle)
				{this->copy(circle); return *this;}
			Circle<T>& operator= (const Circle<T>&& circle)
				{this->counter--; (*this).copy(circle); circle.reset(); return *this;}

			Circle<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Circle' object." << std::endl;
					this->see(); this->watch(); return *this;
				}

			Circle<T>& operator++()			{++this->radius; return *this;}
			Circle<T>& operator++(int)		{(*this).radius++; return *this;}
			Circle<T>& operator--()			{--(*this).radius; return *this;}
			Circle<T>& operator--(int)		{this->radius--; return *this;}

			operator int()			const	{return this->id;}
			operator double()		const	{return this->PI;}

			const T area()			const	{return PI * this->radius * (*this).radius;}
			const T perimeter()		const	{return V_TWO * PI * (*this).radius;}

			virtual void capture()
				{
					std::cout << "Capture of the radius of the 'Circle' object." << std::endl;
					std::cout << "Enter the desired radius: ";
					std::cin >> (*this).radius;
				}

			virtual Circle<T>& copy(const Circle<T>& circle)
				{(*this).radius = circle.getRadius(); return *this;}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const int &getId()		const	{return this->id;}
			const double& getPI()		const	{return this->PI;}
			const T& getRadius()		const	{return this->radius;}

			T& getRadius()				{return (*this).radius;}

			const bool isitme(Circle<T>& circle)	const
				{return (this == &circle);};

			virtual Circle<T>& move(Circle<T>&& circle)
				{(*this).counter--; this->copy(circle); circle.reset(); return *this;}

			virtual void print()		const
				{
					std::cout << "Display the current values ​​of a 'Circle' object." << std::endl;
					(*this).see(); (*this).view();
				}

			virtual void reset()			{this->radius = V_ZERO;}

			virtual void see()		const
				{
					std::cout << "(ID = [" << (*this).id << "] : [" << this->id << "] = ";
					std::cout << "[" << typeid((*this).id).name() << "] : [" << typeid(this->id).name() << "], ";
					std::cout << "PI = [" << (*this).PI << "] : [" << this->PI << "] = ";
					std::cout << "[" << typeid((*this).PI).name() << "] : [" << typeid(this->PI).name() << "], ";
					std::cout << "Radius = [" << (*this).radius << "] : [" << this->radius << "] = ";
					std::cout << "[" << typeid((*this).radius).name() << "] : [" << typeid(this->radius).name() << "], ";
					std::cout << "Counter = [" << (*this).counter << "] : [" << this->counter << "] = ";
					std::cout << "[" << typeid((*this).counter).name() << "] : [" << typeid(this->counter).name() << "])." << std::endl;
					std::cout << "(Area = [" << this->area() << "] : [" << (*this).area() << "], ";
					std::cout << "Perimeter = [" << this->perimeter() << "] : [" << (*this).perimeter() << "])." << std::endl;
				}

			void setRadius(const T &radius = V_ZERO)	{this->radius = radius;}

			virtual void view()		const
				{
					std::cout << std::endl << "Information about the 'Circle' object." << std::endl;
					std::cout << "+ ID:\t\t[" << this->id << "] : [" << (*this).id << "] = ";
					std::cout << "[" << typeid(this->id).name() << "] : [" << typeid((*this).id).name() << "]." << std::endl;
					std::cout << "+ Counter:\t[" << this->counter << "] : [" << (*this).counter << "] = ";
					std::cout << "[" << typeid(this->counter).name() << "] : [" << typeid((*this).counter).name() << "]." << std::endl;
					std::cout << "+ PI Value:\t[" << this->PI << "] : [" << (*this).PI << "] = ";
					std::cout << "[" << typeid(this->PI).name() << "] : [" << typeid((*this).PI).name() << "]." << std::endl;
					std::cout << "+ Radius:\t[" << this->radius << "] : [" << (*this).radius << "] = ";
					std::cout << "[" << typeid(this->radius).name() << "] : [" << typeid((*this).radius).name() << "]." << std::endl;
					std::cout << "+ Area:\t\t[" << this->area() << "] : [" << (*this).area() << "]." << std::endl;
					std::cout << "+ Perimeter:\t[" << this->perimeter() << "] : [" << (*this).perimeter() << "]." << std::endl;
				}

			virtual void watch()		const
				{
					std::cout << "(ID = [" << this->id << "], ";
					std::cout << "PI = [" << this->PI << "], ";
					std::cout << "Radius = [" << this->radius << "], ";
					std::cout << "Counter = [" << this->counter << "])." << std::endl;
					std::cout << "(Area = [" << this->area() << "], ";
					std::cout << "Perimeter = [" << this->perimeter() << "])." << std::endl;
				}

			virtual ~Circle() = default;
	};

template <class T>
int Circle<T>::counter = V_ZERO;


/* Cylinder Class. Derived Class*/
template <typename T>
class Cylinder : public Circle<T>
	{
		private:
			T height = V_ZERO;

			template <class C = T>
			friend std::istream &operator>> (std::istream& in, Cylinder<C> &cylinder)
				{cylinder.capture(); return in;}
			template <class C = T>
			friend std::ostream& operator<< (std::ostream &out, const Cylinder<C>& cylinder)
				{cylinder.print(); return out;}

		public:
			Cylinder() : Circle<T>(V_ZERO, V_ZERO), height(V_ZERO)
				{(*this).counter++; this->capture();}
			Cylinder(const int &id, const T &radius, const T &height) : Circle<T>(id, radius), height(height)
				{this->counter++;}
			Cylinder(const T &radius, const T &height) : Circle<T>(radius), height(height)
				{(*this).counter++;}
			Cylinder(const T &height) : Circle<T>(V_ZERO, V_ZERO), height(height)
				{this->counter++;}

			Cylinder(const Cylinder<T>& cylinder) : Circle<T>(cylinder.getId(), cylinder.getRadius()), height(cylinder.getHeight())
				{(*this).counter++;};
			Cylinder(Cylinder<T>&& cylinder) : Circle<T>(cylinder.getId(), cylinder.getRadius()), height(cylinder.getHeight())
				{this->counter--; cylinder.reset();}

			Cylinder<T>& operator= (const Cylinder<T>& cylinder)
				{this->copy(cylinder); return *this;}
			Cylinder<T>& operator= (const Cylinder<T>&& cylinder)
				{this->counter--; (*this).copy(cylinder); cylinder.reset(); return *this;}

			Cylinder<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Cylinder' object." << std::endl;
					this->see(); this->watch(); return *this;
				}

			Cylinder<T>& operator++()		{++this->height; return *this;}
			Cylinder<T>& operator++(int)		{(*this).height++; return *this;}
			Cylinder<T>& operator--()		{--(*this).height; return *this;}
			Cylinder<T>& operator--(int)		{this->height--; return *this;}

			operator int()			const	{return Circle<T>::getId();}
			operator double()		const	{return Circle<T>::getPI();}

			virtual void capture()
				{
					std::cout << "Capture of the height of the 'Cylinder' object." << std::endl;
					std::cout << "Enter the desired height: ";
					std::cin >> (*this).height;
					Circle<T>::capture();
				}

			virtual Cylinder<T>& copy(const Cylinder<T>& cylinder)
				{Circle<T>::setRadius(cylinder.getRadius()); (*this).height = cylinder.getHeight(); return *this;}

			const T& getHeight()		const	{return (*this).height;}
			T& getHeight()				{return this->height;}

			virtual void explore()
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const bool isitme(Cylinder<T>& cylinder)	const
				{return (this == &cylinder);};

			virtual Cylinder<T>& move(Cylinder<T>&& cylinder)
				{(*this).counter--; this->copy(cylinder); cylinder.reset(); return *this;}

			virtual void print()		const
				{
					std::cout << std::endl << "Information about the 'Cylinder." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "]." << std::endl;
					std::cout << "+ Volume:\t[" << (*this).volume() << "]." << std::endl << std::endl;
					Circle<T>::print();
				}

			virtual void reset()				{(*this).height = V_ZERO; this->getRadius() = V_ZERO;}

			virtual void see()		const
				{
					std::cout << "(Height = [" << (*this).height << "] : [" << this->height << "] = ";
					std::cout << "[" << typeid((*this).height).name() << "] : [" << typeid(this->height).name() << "], ";
					std::cout << "Volume = [" << (*this).volume() << "] : [" << this->volume() << "])." << std::endl;
					Circle<T>::see();
				}

			void setHeight(const T& height = V_ZERO)	{this->height = height;}

			virtual void view()		const
				{
					std::cout << std::endl << "Information about the 'Cylinder' object." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "] : [" << (*this).height << "] = ";
					std::cout << "[" << typeid(this->height).name() << "] : [" << typeid((*this).height).name() << "]." << std::endl;
					std::cout << "+ Volume:\t[" << this->volume() << "] : [" << (*this).volume() << "]." << std::endl;
					Circle<T>::view();
				}

			const T volume()		const		{return this->area() * this->height;}

			virtual void watch()		const
				{
					std::cout << "(Height = [" << this->height << "], ";
					std::cout << "Volume = [" << this->volume() << "])." << std::endl;
					Circle<T>::watch();
				}

			virtual ~Cylinder() = default;
	};


//Main function.
int main ()
	{
		/* Preliminary working variables. */
		int quantity = V_ZERO;
		double height = V_ZERO, radius = V_ZERO;

		/* Initial header messages. */
		std::cout << "Creating 'Circle' objects on an array." << std::endl;
		std::cout << "How many 'Circle' do you want to create? : ";
		std::cin >> quantity;

		/* The dynamic array of pointers to objects of type 'Circle' is created. */
		Circle<double> **array_Circle = new Circle<double>* [quantity];

		/* Each object of type 'Circle' is created and stored in an array of pointers of the same type. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << "radius = ";
				std::cin >> radius;

				array_Circle[idx] = new Circle<double>(idx + V_ONE, radius);

				(*array_Circle[idx]).getRadius() = radius;
				(*array_Circle[idx]).setRadius(radius);

				std::cout << std::endl << "Object created and assigned." << std::endl;
				std::cout << "+ ID Value:\t\t[" << static_cast<int>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "+ PI Value:\t\t[" << static_cast<double>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "+ Radius:\t\t[" << (*array_Circle[idx]).getRadius() << "]." << std::endl;
				std::cout << "+ Is it me?:\t\t[" << array_Circle[idx]->isitme(*array_Circle[idx]) << "]." << std::endl;
			}

		/* An internal method of the 'Circle' object is used to display the assigned values. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Circle[idx]->print();
			}

		/* New values ​​are reassigned and captured to created objects of type 'Point2D' */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;

				(*array_Circle[idx]).reset();
				(*array_Circle[idx]).print();

				std::cin >> *(*(array_Circle + idx));
				array_Circle[idx]->print();
			}

		/* The reassigned values ​​of each instantiated object of type 'Point2D' are displayed again. */
		std::cout << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << *array_Circle[idx];
			}

		/* Using the overloaded increment and decrement operators in the 'Circle' class. */
		std::cout << std::endl << "Increment and decrement the values ​​of the 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Circle[idx]->print();

				/* Different nomenclatures with pointer notation and array notation. */
				std::cout << std::endl << "Increase the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx])++;
				(*array_Circle[idx]).print();

				std::cout << std::endl << "Decrease the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx])--;
				(*array_Circle[idx]).print();

				std::cout << std::endl << "Increase the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx)))++;
				(*(*(array_Circle + idx))).print();

				std::cout << std::endl << "Decrease the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx)))--;
				(*(*(array_Circle + idx))).print();

				/* Various ways to call methods on an array of object pointers (pointer of pointers). */
				std::cout << std::endl << "Initialize the radius of the 'Circle' object." << std::endl;
				array_Circle[idx]->reset();
				array_Circle[idx]->print();

				std::cout << std::endl << "Initialize the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx]).reset();
				(*array_Circle[idx]).print();

				std::cout << std::endl << "Initialize the radius of the 'Circle' object." << std::endl;
				(*(array_Circle + idx))->reset();
				(*(array_Circle + idx))->print();

				std::cout << std::endl << "Initialize the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx))).reset();
				(*(*(array_Circle + idx))).print();

				/* Calling in various ways to an overloaded operator. */
				std::cout << std::endl << "Displaying information about the 'Circle' object." << std::endl;
				(*array_Circle[idx])();
				(*(*(array_Circle + idx)))();
		}

		/* All dynamically created instances of objects of type 'Circle' are purged. */
		std::cout << std::endl << "Clearing 'Circle' objects..." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << "Deleting object 'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				delete *(array_Circle + idx);
			}

                /* Deleting the array of pointer objects of type 'Circle'. */
                std::cout << "Deleting the array of pointers of type 'Circle'..." << std::endl;
		delete [] array_Circle;

		/* Automatic initialization of a class of type 'Cylinder'. */
		std::cout << std::endl << "Creating 'Cylinder' objects on an array." << std::endl;
		std::cout << "How many 'Cylinder' do you want to create? : ";
		std::cin >> quantity;

		/* The dynamic array of pointers to objects of type 'Cylinder' is created. */
		Cylinder<double> **array_Cylinder = new Cylinder<double>* [quantity];

		/* Each object of type 'Cylinder' is created and stored in an array of pointers of the same type. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Cylinder' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << "Radius: ";
				std::cin >> radius;
				std::cout << "Height: ";
				std::cin >> height;

				array_Cylinder[idx] = new Cylinder<double>(idx + V_ONE, radius, height);

				std::cout << std::endl << "'Cylinder' created and assigned." << std::endl;
				std::cout << "+ PI Value:\t[" << static_cast<double>(*array_Cylinder[idx]) << "]." << std::endl;

				(*(*(array_Cylinder + idx))).print();
			}

		/* All dynamically created instances of objects of type 'Cylinder' are purged. */
		std::cout << std::endl << "Clearing 'Cylinder' objects..." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << "Deleting object 'Cylinder' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				delete *(array_Cylinder + idx);
			}

                /* Deleting the array of pointer objects of type 'Cylinder'. */
                std::cout << "Deleting the array of pointers of type 'Cylinder'..." << std::endl;
		delete [] array_Cylinder;

		return V_ZERO;
	}
