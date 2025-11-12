/* Program that exemplifies a 'Rectangle' class
   with some external 'friend' implementations and functions. */

/* Standard work libraries. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define	V_TWO		2
#define V_ZERO		0

/* 'Rectangle' class. */
template <typename T>
class Rectangle
	{
		private:
			T width = V_ZERO, height = V_ZERO;

		protected:
			static int counter;

		public:
			Rectangle() : width(V_ZERO), height(V_ZERO)
				{this->counter++; this->capture();}
			Rectangle(const T &width, const T &height) : width(width), height(height)
				{(*this).counter++;}

			Rectangle<T>& operator= (const Rectangle<T>& rectangle)
				{(*this).copy(rectangle); return *this;}

			void capture()
				{
					std::cout << "Capturing a 'Rectangle' object." << std::endl;
					std::cout << "Enter the width: ";
					this->width = Rectangle<T>::enter_a_value(&this->width);
					std::cout << "Enter the height: ";
					(*this).height = Rectangle<T>::enter_a_value(&(*this).height);
				}

			virtual Rectangle<T>& copy(const Rectangle<T>& rectangle)
				{
					(*this).width = rectangle.getWidth();
					this->height = rectangle.getHeight();
					return *this;
				}

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

			const T& getHeight() const			{return this->height;}
			const T& getWidth() const			{return this->width;}

			T& getHeight()					{return (*this).height;}
			T& getWidth()					{return (*this).width;}

			T getArea()					{return this->width * this->height;}
			T getPerimeter()				{return V_TWO * (*this).width + V_TWO * (*this).height;}

			virtual void print()
				{
					std::cout << "Rectangle's outcomes." << std::endl;
					std::cout << "+ Counter:\t[" << this->counter << "]." << std::endl;
					std::cout << "+ Width:\t[" << this->width << "]." << std::endl;
					std::cout << "+ Height:\t[" << this->height << "]." << std::endl;
					std::cout << "> Area:\t\t[" << this->getArea() << "]." << std::endl;
					std::cout << "> Perimeter:\t[" << this->getPerimeter() << "]." << std::endl << std::endl;
				}

			void setHeight(const T& height = V_ZERO)	{(*this).height = height;}
			void setWidth(const T& width = V_ZERO)		{(*this).width = width;}

			virtual ~Rectangle() = default;

			template <typename U>
			friend const Rectangle<U> obtain_results (const Rectangle<U>& rect);
	};

template <typename T>
int Rectangle<T>::counter = V_ZERO;

/* Helpful function for visualizing results of the 'Rectangle' object. */
template <typename U>
const Rectangle<U> obtain_results (const Rectangle<U>& rect)
	{
		Rectangle<U> rec(rect.getWidth(), rect.getHeight());

		std::cout << "Rectangle's outcomes." << std::endl;
		std::cout << "+ Counter:\t[" << rec.counter << "]." << std::endl;
		std::cout << "+ Width:\t[" << rec.getWidth() << "]." << std::endl;
		std::cout << "+ Height:\t[" << rec.getHeight() << "]." << std::endl;
		std::cout << "> Area:\t\t[" << rec.getArea() << "]." << std::endl;
		std::cout << "> Perimeter:\t[" << rec.getPerimeter() << "]." << std::endl << std::endl;

		return rec;
	}

//Main function.
int main()
	{
		std::cout << "Generating Rectangle class' instances." << std::endl;

		/* Foo's instantiation. */
		std::cout << std::endl << "Foo's instantiation." << std::endl;
		Rectangle<int> foo;
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		/* Bar's instantiation. */
		std::cout << std::endl << "Bar's instantiation." << std::endl;
		Rectangle<int> bar;
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		/* Baz's instantiation. */
		std::cout << std::endl << "Baz's instantiation." << std::endl;
		Rectangle<int> baz;
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");


		/* Foo's visualization. */
		std::cout << std::endl << "Foo's visualization." << std::endl;
		obtain_results<int>(foo);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		/* Bar's visualization. */
		std::cout << std::endl << "Bar's visualization." << std::endl;
		obtain_results<int>(bar);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		/* Baz's visualization. */
		std::cout << std::endl << "Baz's visualization." << std::endl;
		obtain_results<int>(baz);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");


		/* Foo's reasignation. */
		std::cout << std::endl << "Foo's reasignation." << std::endl;
		foo = obtain_results<int>(bar);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		/* Bar's reasignation. */
		std::cout << std::endl << "Bar's reasignation." << std::endl;
		bar = obtain_results<int>(baz);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		/* Baz's reasignation. */
		std::cout << std::endl << "Baz's reasignation." << std::endl;
		baz = obtain_results<int>(foo);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		return V_ZERO;
	}
