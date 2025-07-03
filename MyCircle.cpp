//Classes and uniform initialization.
#include <iostream>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_PI	3.14159265
#define	V_TWO	2
#define	V_ZERO	0

/* Circle Class. */
template <class T>
class Circle
	{
		private:
			const int id = V_ZERO;
			const double PI = V_PI;
			T radius = V_ZERO;

			template <class C>
			friend std::istream &operator>> (std::istream& in, Circle<C> &circle)
				{circle.capture(); return in;}

			template <class C>
			friend std::ostream& operator<< (std::ostream &out, const Circle<C> &circle)
				{circle.print(); return out;}

		protected:
			static int c;

		public:
			Circle()							{(*this).c++; this->capture();}
			Circle(const int& id, const T& radius) : id(id), radius(radius)	{this->c++;}
			Circle(const T &radius) : id(V_ZERO), radius(radius)		{this->c++;}

			Circle(const Circle<T>& circle) : id(circle.getId()), radius(circle.getRadius())
				{(*this).c++;};
			Circle(Circle<T>&& circle) : id(circle.getId()), radius(circle.getRadius())
				{this->c--; circle.reset();}

			Circle<T>& operator=(const Circle<T>& circle)
				{this->copy(circle); return *this;}
			Circle<T>& operator=(const Circle<T>&& circle)
				{this->c--; this->copy(circle); circle.reset(); return *this;}

			Circle<T>& operator()()
				{
					std::cout << "Show the current values ​​of a 'Circle' object." << std::endl;
					this->see(); this->watch();
					return *this;
				}

			Circle<T>& operator++()			{++this->radius; return *this;}
			Circle<T>& operator++(int)		{(*this).radius++; return *this;}
			Circle<T>& operator--()			{--(*this).radius; return *this;}
			Circle<T>& operator--(int)		{this->radius--; return *this;}

			operator T()			const	{return this->id;}

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

			const int &getId()		const	{return this->id;}
			const T& getPI()		const	{return this->PI;}
			const T& getRadius()		const	{return this->radius;}

			T& getRadius()				{return (*this).radius;}

			const bool isitme(Circle<T>& circle)	const
				{return (this == &circle);};

			virtual Circle<T>& move(Circle<T>&& circle)
				{(*this).c--; this->copy(circle); circle.reset(); return *this;}

			virtual void print()		const
				{
					std::cout << "Display the current values ​​of a 'Circle' object." << std::endl;
					(*this).see(); (*this).view();
				}

			virtual void reset()			{this->radius = V_ZERO;}

			virtual void see()		const
				{
					std::cout << "(ID = [" << (*this).id << "] : [" << this->id << "], PI = [" << (*this).PI << "] : [" << this->PI << "], Radius = [" << (*this).radius << "] : [" << this->radius << "], Counter = [" << (*this).c << "] : [" << this->c << "])." << std::endl;
					std::cout << "(Area = [" << this->area() << "] : [" << (*this).area() << "], Perimeter = [" << this->perimeter() << "] : [" << (*this).perimeter() << "])." << std::endl;
				}

			void setRadius(const T &radius)		{this->radius = radius;}

			virtual void view()		const
				{
					std::cout << std::endl << "Information about the 'Circle' object." << std::endl;
					std::cout << "+ ID:\t\t[" << this->id << "] = [" << (*this).id << "]." << std::endl;
					std::cout << "+ Counter:\t[" << this->c << "] = [" << (*this).c << "]." << std::endl;
					std::cout << "+ PI Value:\t[" << this->PI << "] = [" << (*this).PI << "]." << std::endl;
					std::cout << "+ Radius:\t[" << this->radius << "] = [" << (*this).radius << "]." << std::endl;
					std::cout << "+ Area:\t\t[" << this->area() << "] = [" << (*this).area() << "]." << std::endl;
					std::cout << "+ Perimeter:\t[" << this->perimeter() << "] = [" << (*this).perimeter() << "]." << std::endl;
				}

			virtual void watch()		const
				{
					std::cout << "(ID = [" << this->id << "], PI = [" << this->PI << "], Radius = [" << this->radius << "], Counter = [" << this->c << "])." << std::endl;
					std::cout << "(Area = [" << this->area() << "], Perimeter = [" << this->perimeter() << "])." << std::endl;
				}

			virtual ~Circle() = default;
	};

template <class T>
int Circle<T>::c = V_ZERO;

/* Cylinder Class. */
template <typename T>
class Cylinder
	{
		private:
			Circle<T> base;
			T height = V_ZERO;

		public:
			Cylinder(T radius, T height) : base(radius), height(height)	{}

			virtual void print() const
				{
					std::cout << std::endl << "Information about the 'Cylinder." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "]." << std::endl;
					std::cout << "+ Volume:\t[" << (*this).volume() << "]." << std::endl;
					(&base)->print();
				}

			const T& getHeight()	const		{return (*this).height;}
			T& getHeight()				{return this->height;}

			void setHeight(const T& height)		{this->height = height;}

			const T volume() const		{return base.area() * this->height;}

			virtual ~Cylinder() = default;
	};

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

				std::cout << "Object created #:\t[" << static_cast<int>(*array_Circle[idx]) << "]." << std::endl;
				std::cout << "Asigned radius:\t\t[" << (*array_Circle[idx]).getRadius() << "]." << std::endl;
				std::cout << "Is it me?:\t\t[" << array_Circle[idx]->isitme(*array_Circle[idx]) << "]." << std::endl;
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

				array_Cylinder[idx] = new Cylinder<double>(radius, height);
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
