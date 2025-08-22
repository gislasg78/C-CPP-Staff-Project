/* This program calculates the area and perimeter of an instantiated class
   called 'Circle' and this is used to calculate another instantiable class
   called 'Cylinder'. */

//Classes and uniform initialization.
#include <iostream>
#include <limits>

/* Character constants. */
#define	CARRIAGE_RETURN	'\n'

/* Symbolic work constants. */
#define	V_ONE		1
#define	V_PI		3.14159265
#define	V_TWO		2
#define	V_ZERO		0


/* Circle Class. Base Class.*/
template <class T>
class Circle
	{
		private:
			const int id = V_ZERO;
			const double PI = V_PI;
			T radius = V_ZERO;

			friend std::istream &operator>> (std::istream& in, Circle<T> &circle)
				{circle.capture(); return in;}
			friend std::ostream& operator<< (std::ostream &out, const Circle<T>& circle)
				{circle.print(); return out;}

		protected:
			static int counter;

		public:
			Circle() : id(V_ZERO), radius(V_ZERO)
				{(*this).counter++; this->capture();}
			Circle(const T &radius) : id(V_ZERO), radius(radius)
				{this->counter++;}
			Circle(const int& id, const T& radius) : id(id), radius(radius)
				{this->counter++;}

			Circle(const Circle<T>& circle) : id(circle.getId()), radius(circle.getRadius())
				{(*this).counter++;};
			Circle(Circle<T>&& circle) : id(circle.getId()), radius(circle.getRadius())
				{this->counter--; circle.reset();}

			Circle<T>& operator= (const Circle<T>& circle)
				{this->copy(circle); return *this;}
			Circle<T>& operator= (Circle<T>&& circle)
				{(*this).counter--; this->copy(circle); circle.reset(); return *this;}

			Circle<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Circle' object." << std::endl;
					this->see(); this->view(); this->watch(); return *this;
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

			template <typename C = T>
			const Circle<C> convert()	const
				{
					Circle<C> converted_circle(V_ZERO);
					converted_circle.setRadius(static_cast<C>(this->getRadius()));
					return converted_circle;
				}

			template <typename C = T>
			const Circle<C> convert(const Circle<T> &circle)	const
				{
					Circle<C> converted_circle(V_ZERO);
					converted_circle.setRadius(static_cast<C>(circle.getRadius()));
					return converted_circle;
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
					(*this).see(); (*this).view(); (*this).watch();
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

			void setRadius(const T &radius = V_ZERO)		{this->radius = radius;}

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
					std::cout << std::endl << "(ID = [" << this->id << "], ";
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


/* Cylinder Class. Derived Class.*/
template <typename T>
class Cylinder : public Circle<T>
	{
		private:
			Circle<T> base;
			T height = V_ZERO;

			friend std::istream &operator>> (std::istream& in, Cylinder<T> &cylinder)
				{cylinder.capture(); return in;}
			friend std::ostream& operator<< (std::ostream &out, const Cylinder<T>& cylinder)
				{cylinder.print(); return out;}

		public:
			Cylinder() : Circle<T>(V_ZERO, V_ZERO), height(V_ZERO)
				{(*this).counter++; this->capture();}
			Cylinder(const T &height) : Circle<T>(V_ZERO, V_ZERO), height(height)
				{this->counter++;}
			Cylinder(const T &radius, const T &height) : Circle<T>(radius), height(height)
				{(*this).counter++;}
			Cylinder(const int &id, const T &radius, const T &height) : Circle<T>(id, radius), height(height)
				{this->counter++;}

			Cylinder(const Cylinder<T>& cylinder) : Circle<T>(cylinder.getId(), cylinder.getRadius()), height(cylinder.getHeight())
				{(*this).counter++;};
			Cylinder(Cylinder<T>&& cylinder) : Circle<T>(cylinder.getId(), cylinder.getRadius()), height(cylinder.getHeight())
				{this->counter--; cylinder.reset();}

			Cylinder<T>& operator= (const Cylinder<T>& cylinder)
				{this->copy(cylinder); return *this;}
			Cylinder<T>& operator= (Cylinder<T>&& cylinder)
				{(*this).counter--; this->copy(cylinder); cylinder.reset(); return *this;}

			Cylinder<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Cylinder' object." << std::endl;
					this->see(); this->view(); this->watch(); return *this;
				}

			Cylinder<T>& operator++()		{++this->height; return *this;}
			Cylinder<T>& operator++(int)		{(*this).height++; return *this;}
			Cylinder<T>& operator--()		{--(*this).height; return *this;}
			Cylinder<T>& operator--(int)		{this->height--; return *this;}

			operator int()			const	{return Circle<T>::getId();}
			operator double()		const	{return Circle<T>::getPI();}

			virtual void capture() override
				{
					std::cout << "Capture of the height of the 'Cylinder' object." << std::endl;
					std::cout << "Enter the desired height: ";
					std::cin >> (*this).height;
					Circle<T>::capture();
				}

			template <typename C = T>
			const Cylinder<C> convert()	const
				{
					Cylinder<C> converted_cylinder(V_ZERO);
					converted_cylinder.setRadius(static_cast<C>(this->getRadius()));
					converted_cylinder.setHeight(static_cast<C>(this->getHeight()));
					return converted_cylinder;
				}

			template <typename C = T>
			const Cylinder<C> convert(const Cylinder<T>& cylinder)	const
				{
					Cylinder<C> converted_cylinder(V_ZERO);
					converted_cylinder.setRadius(static_cast<C>(cylinder.getRadius()));
					converted_cylinder.setHeight(static_cast<C>(cylinder.getHeight()));
					return converted_cylinder;
				}

			virtual Cylinder<T>& copy(const Cylinder<T>& cylinder)
				{Circle<T>::setRadius(cylinder.getRadius()); (*this).height = cylinder.getHeight(); return *this;}
			virtual Cylinder<T>& copy(const Circle<T>& circle) override
				{Circle<T>::copy(circle); return *this;}

			const T& getHeight()		const	{return (*this).height;}
			T& getHeight()				{return this->height;}

			virtual void explore() override
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const bool isitme(Cylinder<T>& cylinder)	const
				{return (this == &cylinder);};

			virtual Cylinder<T>& move(Cylinder<T>&& cylinder)
				{(*this).counter--; this->copy(cylinder); cylinder.reset(); return *this;}
			virtual Cylinder<T>& move(Circle<T>&& circle) override
				{(*this).counter--; Circle<T>::copy(circle); circle.reset(); Circle<T>::move(std::move(circle)); return *this;}

			virtual void print()		const override
				{
					std::cout << std::endl << "Information about the 'Cylinder." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "]." << std::endl;
					std::cout << "+ Volume:\t[" << (*this).volume() << "]." << std::endl << std::endl;
					Circle<T>::print();
				}

			virtual void reset()		override	{(*this).height = V_ZERO; this->getRadius() = V_ZERO;}

			virtual void see()		const override
				{
					std::cout << "(Height = [" << (*this).height << "] : [" << this->height << "] = ";
					std::cout << "[" << typeid((*this).height).name() << "] : [" << typeid(this->height).name() << "], ";
					std::cout << "Volume = [" << (*this).volume() << "] : [" << this->volume() << "])." << std::endl;
					Circle<T>::see();
				}

			void setHeight(const T& height = V_ZERO)	{this->height = height;}

			virtual void view()		const override
				{
					std::cout << std::endl << "Information about the 'Cylinder' object." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "] : [" << (*this).height << "] = ";
					std::cout << "[" << typeid(this->height).name() << "] : [" << typeid((*this).height).name() << "]." << std::endl;
					std::cout << "+ Volume:\t[" << this->volume() << "] : [" << (*this).volume() << "]." << std::endl;
					Circle<T>::view();
				}

			const T volume()		const		{return this->area() * this->height;}

			virtual void watch()		const override
				{
					std::cout << std::endl << "(Height = [" << this->height << "], ";
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
				std::cout << std::endl << "'Cylinder' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << "Radius = "; std::cin >> radius;
				std::cout << "Height = "; std::cin >> height;

				array_Circle[idx] = new Cylinder<double>(idx + V_ONE, radius, height);

				std::cout << std::endl << "Object 'Cylinder' created and assigned." << std::endl;
				std::cout << "+ ID Value:\t\t[" << static_cast<int>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "+ PI Value:\t\t[" << static_cast<double>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "+ Radius:\t\t[" << (*array_Circle[idx]).getRadius() << "]." << std::endl;

				if (Cylinder<double>* my_cylinder = dynamic_cast<Cylinder<double>*>(array_Circle[idx]))
					std::cout << "+ Height:\t\t[" << (*my_cylinder).getHeight() << "] = [" << my_cylinder->getHeight() << "]." << std::endl;

				std::cout << "+ Is it me?:\t\t[" << array_Circle[idx]->isitme(*array_Circle[idx]) << "]." << std::endl;

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.
			}

		/* An internal method of the 'Circle' object is used to display the assigned values. */
		std::cout << std::endl << "Enlarged printout of information for a 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Circle[idx]->print();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.
			}

		/* New values ​​are reassigned and captured to created objects of type 'Point2D' */
		std::cout << std::endl << "Capturing and modifying new values ​​to a 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "Recapturing the information of a 'Circle' class." << std::endl;
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cin >> *(*(array_Circle + idx));
				std::cout << *array_Circle[idx];

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.
			}

		/* Using the overloaded increment and decrement operators in the 'Circle' class. */
		std::cout << std::endl << "Increment and decrement the values ​​of the 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				/* Different nomenclatures with pointer notation and array notation. */
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Circle[idx]->print();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.


				/* Increase the radius of the 'Circle' object. */
				std::cout << std::endl << "Increase the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx])++;
				(*array_Circle[idx]).print();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.


				/* Decrease the radius of the 'Circle' object. */
				std::cout << std::endl << "Decrease the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx])--;
				(*array_Circle[idx]).print();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.


				/* Increase the radius of the 'Circle' object. */
				std::cout << std::endl << "Increase the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx)))++;
				(*(*(array_Circle + idx))).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.


				/* Decrease the radius of the 'Circle' object. */
				std::cout << std::endl << "Decrease the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx)))--;
				(*(*(array_Circle + idx))).watch();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.


				/* Various ways to call methods on an array of object pointers (pointer of pointers). */
				std::cout << std::endl << "Initialize the radius of the 'Circle' object." << std::endl;
				array_Circle[idx]->reset();
				(*array_Circle[idx]).reset();
				(*(array_Circle + idx))->reset();
				(*(*(array_Circle + idx))).reset();

				array_Circle[idx]->see();
				(*array_Circle[idx]).see();
				(*(array_Circle + idx))->see();
				(*(*(array_Circle + idx))).see();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.

				/* Calling in various ways to an overloaded operator. */
				std::cout << std::endl << "Displaying information about the 'Circle' object." << std::endl;
				(*array_Circle[idx])();
				(*(*(array_Circle + idx)))();

				/* Pause before continuing. */
				std::cout << std::endl << "Press the ENTER key to continue...";
				std::cin.get();		// Wait for the user to press Enter.
				std::cin.clear();	// Clear the error state.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.
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

		return V_ZERO;
	}
