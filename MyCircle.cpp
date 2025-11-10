/* This program calculates the area and perimeter of an instantiated class
   called 'Circle' and this is used to calculate another instantiable class
   called 'Cylinder'. */

/* Classes and uniform initialization. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

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

			Circle<T>& operator=(const T& radius)
				{this->radius = radius; return *this;}
			Circle<T>& operator=(const Circle<T>& circle)
				{this->copy(circle); return *this;}
			Circle<T>& operator=(Circle<T>&& circle)
				{(*this).counter--; this->copy(circle); circle.reset(); return *this;}

			Circle<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Circle' object." << std::endl;
					this->see(); this->view(); this->watch(); return *this;
				}

			Circle<T> operator+(const Circle<T>& circle)
				{
					Circle<T> object_circle(circle.getRadius());
					object_circle.getRadius() += (*this).radius;
					return object_circle;
				}
			Circle<T>& operator+=(const Circle<T>& circle)
				{(*this).radius += circle.getRadius(); return *this;}
			Circle<T>& operator+=(const T& radius)
				{this->radius += radius; return *this;}

			Circle<T>& operator++()			{++this->radius; return *this;}
			Circle<T>& operator++(int)		{(*this).radius++; return *this;}
			Circle<T>& operator--()			{--(*this).radius; return *this;}
			Circle<T>& operator--(int)		{this->radius--; return *this;}

			Circle<T> operator-(const Circle<T>& circle)
				{
					Circle<T> object_circle(circle.getRadius());
					object_circle.getRadius() -= (*this).radius;
					return object_circle;
				}
			Circle<T>& operator-=(const Circle<T>& circle)
				{(*this).radius -= circle.getRadius(); return *this;}
			Circle<T>& operator-=(const T& radius)
				{this->radius -= radius; return *this;}

			operator int()			const	{return this->id;}
			operator double()		const	{return this->PI;}

			const T area()			const	{return PI * this->radius * (*this).radius;}
			const T perimeter()		const	{return V_TWO * PI * (*this).radius;}

			virtual void capture()
				{
					std::cout << "Capture of the radius of the 'Circle' object." << std::endl;
					std::cout << "Enter the desired radius: ";
					(*this).radius = (*this).enter_a_data(&this->radius);
				}

			template <typename C = T>
			const Circle<C> convert()	const
				{
					Circle<C> converted_circle(V_ZERO);
					converted_circle.setRadius(static_cast<C>(this->radius));
					return converted_circle;
				}

			template <typename C = T>
			const Circle<C> convert(const Circle<T> &circle)	const
				{
					Circle<C> converted_circle(V_ZERO);
					converted_circle.getRadius() = static_cast<C>(circle.getRadius());
					return converted_circle;
				}

			virtual Circle<T>& copy(const Circle<T>& circle)
				{(*this).radius = circle.getRadius(); return *this;}

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

			const T	getDiameter()		const	{return this->radius * V_TWO;}
			const int &getId()		const	{return this->id;}
			const double& getPI()		const	{return this->PI;}
			const T& getRadius()		const	{return this->radius;}

			T& getRadius()				{return (*this).radius;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()				{return this->PI;}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			getValue()				{return this->id;}

			const bool isitme(Circle<T>& circle)	const		{return (this == &circle);};

			virtual Circle<T>& move(Circle<T>&& circle)
				{(*this).counter--; this->copy(circle); circle.reset(); return *this;}

			virtual void print()		const
				{
					std::cout << "Display the current values ​​of a 'Circle' object." << std::endl;
					(*this).see(); (*this).view(); (*this).watch();
				}

			virtual void reset()					{this->radius = V_ZERO;}

			void setDiameter(const T& diameter = V_ZERO)		{this->radius = diameter / V_TWO;}
			void setRadius(const T &radius = V_ZERO)		{this->radius = radius;}

			virtual void see()		const
				{
					std::cout << "Brief information about the 'Circle' object." << std::endl;
					std::cout << "+ ID:\t\t[" << this->id << "]." << std::endl;
					std::cout << "+ Counter:\t[" << (*this).counter << "]." << std::endl;
					std::cout << "+ PI Value:\t[" << this->PI << "]." << std::endl;
					std::cout << "+ Diameter:\t[" << (*this).radius * V_TWO << "]." << std::endl;
					std::cout << "+ Radius:\t[" << this->radius << "]." << std::endl;
					std::cout << "+ Area:\t\t[" << this->area() << "]." << std::endl;
					std::cout << "+ Perimeter:\t[" << (*this).perimeter() << "]." << std::endl << std::endl;
				}

			virtual void swap()					{return;}

			virtual void view()		const
				{
					std::cout << "Extended information about the 'Circle' object." << std::endl;
					std::cout << "+ ID:\t\t[" << this->id << "]\t\t:\t[" << (*this).id << "]\t\t=\t";
					std::cout << "[" << typeid(this->id).name() << "]\t:\t[" << typeid((*this).id).name() << "]." << std::endl;
					std::cout << "+ Counter:\t[" << this->counter << "]\t\t:\t[" << (*this).counter << "]\t\t=\t";
					std::cout << "[" << typeid(this->counter).name() << "]\t:\t[" << typeid((*this).counter).name() << "]." << std::endl;
					std::cout << "+ PI Value:\t[" << this->PI << "]\t:\t[" << (*this).PI << "]\t=\t";
					std::cout << "[" << typeid(this->PI).name() << "]\t:\t[" << typeid((*this).PI).name() << "]." << std::endl;
					std::cout << "+ Diameter:\t[" << (*this).radius * V_TWO << "]\t\t:\t[" << this->radius * V_TWO << "]." << std::endl;
					std::cout << "+ Radius:\t[" << this->radius << "]\t\t:\t[" << (*this).radius << "]\t\t=\t";
					std::cout << "[" << typeid(this->radius).name() << "]\t:\t[" << typeid((*this).radius).name() << "]." << std::endl;
					std::cout << "+ Area:\t\t[" << this->area() << "]\t:\t[" << (*this).area() << "]." << std::endl;
					std::cout << "+ Perimeter:\t[" << this->perimeter() << "]\t:\t[" << (*this).perimeter() << "]." << std::endl << std::endl;
				}

			virtual void watch()		const
				{
					std::cout << "Specific information about the 'Circle' object." << std::endl;
					std::cout << "(ID = [" << this->id << "], ";
					std::cout << "PI = [" << this->PI << "], ";
					std::cout << "Diameter = [" << (*this).radius * V_TWO << "], ";
					std::cout << "Radius = [" << this->radius << "], ";
					std::cout << "Counter = [" << this->counter << "])." << std::endl;
					std::cout << "(Area = [" << this->area() << "], ";
					std::cout << "Perimeter = [" << this->perimeter() << "])." << std::endl << std::endl;
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

			Cylinder<T>& operator=(const T& height)
				{(*this).height = height; return *this;}
			Cylinder<T>& operator=(const Cylinder<T>& cylinder)
				{this->copy(cylinder); return *this;}
			Cylinder<T>& operator=(Cylinder<T>&& cylinder)
				{(*this).counter--; this->copy(cylinder); cylinder.reset(); return *this;}

			Cylinder<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Cylinder' object." << std::endl;
					this->see(); this->view(); this->watch(); return *this;
				}

			Cylinder<T> operator+(const Cylinder<T>& cylinder)
				{
					Cylinder<T> object_cylinder(cylinder.getHeight());
					object_cylinder.getHeight() += (*this).height;
					return object_cylinder;
				}
			Cylinder<T>& operator+=(const Cylinder<T>& cylinder)
				{(*this).getRadius() += cylinder.getRadius(); this->height += cylinder.getHeight(); return *this;}
			Cylinder<T>& operator+=(const T& height)
				{this->height += height; return *this;}

			Cylinder<T>& operator++()		{++this->height; return *this;}
			Cylinder<T>& operator++(int)		{(*this).height++; return *this;}
			Cylinder<T>& operator--()		{--(*this).height; return *this;}
			Cylinder<T>& operator--(int)		{this->height--; return *this;}

			Cylinder<T> operator-(const Cylinder<T>& cylinder)
				{
					Cylinder<T> object_cylinder(cylinder.getHeight());
					object_cylinder.getHeight() -= (*this).height;
					return object_cylinder;
				}
			Cylinder<T>& operator-=(const Cylinder<T>& cylinder)
				{(*this).getRadius() -= cylinder.getRadius(); this->height -= cylinder.getHeight(); return *this;}
			Cylinder<T>& operator-=(const T& height)
				{this->height -= height; return *this;}

			operator int()			const	{return Circle<T>::getId();}
			operator double()		const	{return Circle<T>::getPI();}

			virtual void capture()	override
				{
					std::cout << "Capture of the height of the 'Cylinder' object." << std::endl;
					std::cout << "Enter the desired height: ";
					(*this).height = (*this).enter_a_data(&this->height);
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
					converted_cylinder.getRadius() = static_cast<C>(cylinder.getRadius());
					converted_cylinder.getHeight() = static_cast<C>(cylinder.getHeight());
					return converted_cylinder;
				}

			virtual Cylinder<T>& copy(const Cylinder<T>& cylinder)
				{Circle<T>::setRadius(cylinder.getRadius()); (*this).height = cylinder.getHeight(); return *this;}
			virtual Cylinder<T>& copy(const Circle<T>& circle) override
				{Circle<T>::copy(circle); return *this;}

			const T& getHeight()		const	{return (*this).height;}
			T& getHeight()				{return this->height;}

			template <typename U = T>
			typename std::enable_if<std::is_floating_point<T>::value, U>::type
			getValue()				{return Circle<T>::getPI();}

			template <typename U = T>
			typename std::enable_if<std::is_integral<T>::value, U>::type
			getValue()				{return Circle<T>::getId();}

			virtual void explore()	override
				{std::cout << *this << std::endl; std::cin >> *this; std::cout << *this << std::endl;}

			const bool isitme(Cylinder<T>& cylinder)	const
				{return (this == &cylinder);};

			virtual Cylinder<T>& move(Cylinder<T>&& cylinder)
				{(*this).counter--; this->copy(cylinder); cylinder.reset(); return *this;}
			virtual Cylinder<T>& move(Circle<T>&& circle) override
				{(*this).counter--; Circle<T>::copy(circle); circle.reset(); Circle<T>::move(std::move(circle)); return *this;}

			virtual void print()		const override
				{
					std::cout << "Display the current values ​​of a 'Cylinder' object." << std::endl;
					(*this).see(); (*this).view(); (*this).watch();
					Circle<T>::print();
				}

			virtual void reset()		override
				{(*this).height = V_ZERO; this->getRadius() = V_ZERO;}

			virtual void see()		const override
				{
					std::cout << "Brief information about the object 'Cylinder'." << std::endl;
					std::cout << "+ Height:\t[" << (*this).height << "]." << std::endl;
					std::cout << "+ Volume:\t[" << (*this).volume() << "]." << std::endl << std::endl;
					Circle<T>::see();
				}

			void setHeight(const T& height = V_ZERO)	{this->height = height;}

			virtual void swap()		override
				{T temp = this->height; this->getHeight() = this->getRadius(); this->setRadius(temp);}

			virtual void view()		const override
				{
					std::cout << "Extended information about the 'Cylinder' object." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "]\t\t:\t[" << (*this).height << "]\t=\t";
					std::cout << "[" << typeid(this->height).name() << "]\t:\t[" << typeid((*this).height).name() << "]." << std::endl;
					std::cout << "+ Volume:\t[" << this->volume() << "]\t:\t[" << (*this).volume() << "]." << std::endl << std::endl;
					Circle<T>::view();
				}

			const T volume()		const		{return this->area() * this->height;}

			virtual void watch()		const override
				{
					std::cout << "Specific information about the 'Cylinder' object." << std::endl;
					std::cout << "(Height = [" << this->height << "], ";
					std::cout << "Volume = [" << this->volume() << "])." << std::endl << std::endl;
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
		quantity = Circle<int>::enter_a_value(&quantity);

		/* The dynamic array of pointers to objects of type 'Circle' is created. */
		Circle<double> **array_Circle = new Circle<double>* [quantity];

		/* Each object of type 'Circle' is created and stored in an array of pointers of the same type. */
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Cylinder' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cout << "Radius = "; radius = Circle<double>::enter_a_value(&radius);
				std::cout << "Height = "; height = Circle<double>::enter_a_value(&height);

				array_Circle[idx] = new Cylinder<double>(idx + V_ONE, radius, height);

				std::cout << std::endl << "Object 'Cylinder' created and assigned." << std::endl;
				std::cout << "+ ID Value:\t\t[" << static_cast<int>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "+ PI Value:\t\t[" << static_cast<double>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "+ Radius:\t\t[" << (*array_Circle[idx]).getRadius() << "]." << std::endl;
				std::cout << "+ Diameter:\t\t[" << (*array_Circle[idx]).getDiameter() << "]." << std::endl;
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				if (Cylinder<double>* my_cylinder = dynamic_cast<Cylinder<double>*>(array_Circle[idx]))
					{
						std::cout << "+ Height:\t\t[" << (*my_cylinder).getHeight() << "] = [" << my_cylinder->getHeight() << "]." << std::endl;
						std::cout << "+ Cylinder:\t\t[" << my_cylinder->getValue() << "]." << std::endl;
						Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
					}

				if (Circle<double>* my_circle = dynamic_cast<Circle<double>*>(*(array_Circle + idx)))
					{
						std::cout << "+ Circle:\t\t[" << my_circle->getValue() << "]." << std::endl;
						Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
					}

				std::cout << "+ Is it me?:\t\t[" << std::boolalpha << array_Circle[idx]->isitme(*array_Circle[idx]) << "]." << std::endl;
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* An internal method of the 'Circle' object is used to display the assigned values. */
		std::cout << std::endl << "Enlarged printout of information for a 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Circle[idx]->print();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* New values ​​are reassigned and captured to created objects of type 'Point2D' */
		std::cout << std::endl << "Capturing and modifying new values ​​to a 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << std::endl << "Recapturing the information of a 'Circle' class." << std::endl;
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				std::cin >> *(*(array_Circle + idx));
				std::cout << *array_Circle[idx];
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
			}

		/* Using the overloaded increment and decrement operators in the 'Circle' class. */
		std::cout << std::endl << "Increment and decrement the values ​​of the 'Circle' class." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				/* Different nomenclatures with pointer notation and array notation. */
				std::cout << std::endl << "'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				array_Circle[idx]->print();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Increase the radius of the 'Circle' object. */
				std::cout << std::endl << "Increase the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx])++;
				(*array_Circle[idx]).print();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Initial exchange of values. */
				std::cout << std::endl << "Initial exchange of values." << std::endl;

				if (Cylinder<double>* my_cylinder = dynamic_cast<Cylinder<double>*>(array_Circle[idx]))
					(*my_cylinder).swap();
				else
					array_Circle[idx]->swap();

				array_Circle[idx]->print();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Final exchange of values. */
				std::cout << std::endl << "Final exchange of values." << std::endl;
				if (Cylinder<double>* my_cylinder = dynamic_cast<Cylinder<double>*>(array_Circle[idx]))
					my_cylinder->swap();
				else
					(*array_Circle[idx]).swap();

				(*array_Circle[idx]).print();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Decrease the radius of the 'Circle' object. */
				std::cout << std::endl << "Decrease the radius of the 'Circle' object." << std::endl;
				(*array_Circle[idx])--;
				(*array_Circle[idx]).print();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Increase the radius of the 'Circle' object. */
				std::cout << std::endl << "Increase the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx)))++;
				(*(*(array_Circle + idx))).see();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Decrease the radius of the 'Circle' object. */
				std::cout << std::endl << "Decrease the radius of the 'Circle' object." << std::endl;
				(*(*(array_Circle + idx)))--;
				(*(*(array_Circle + idx))).see();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Various ways to call methods on an array of object pointers (pointer of pointers). */
				std::cout << std::endl << "Initialize the radius of the 'Circle' object." << std::endl;
				array_Circle[idx]->reset();
				(*array_Circle[idx]).reset();
				(*(array_Circle + idx))->reset();
				(*(*(array_Circle + idx))).reset();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Observing initialized values ​​of the 'Circle' object. */
				std::cout << std::endl << "Observing initialized values ​​of the 'Circle' object." << std::endl;
				array_Circle[idx]->watch();
				(*array_Circle[idx]).watch();
				(*(array_Circle + idx))->watch();
				(*(*(array_Circle + idx))).watch();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

				/* Calling in various ways to an overloaded operator. */
				std::cout << std::endl << "Displaying information about the 'Circle' object." << std::endl;
				(*array_Circle[idx])();
				(*(*(array_Circle + idx)))();
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
		}

		/* All dynamically created instances of objects of type 'Circle' are purged. */
		std::cout << std::endl << "Clearing 'Circle' objects..." << std::endl;
		for (int idx = V_ZERO; idx < quantity; idx++)
			{
				std::cout << "Deleting object 'Circle' #: [" << idx + V_ONE << "] of: [" << quantity << "]." << std::endl;
				delete *(array_Circle + idx);
				Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");
			}

                /* Deleting the array of pointer objects of type 'Circle'. */
                std::cout << "Deleting the array of pointers of type 'Circle'..." << std::endl;
		delete [] array_Circle;
		Circle<double>::enter_a_pause("\nPress the ENTER key to continue...");

		return V_ZERO;
	}
