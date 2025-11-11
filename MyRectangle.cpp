//Friend functions.
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

#define	CARRIAGE_RETURN	'\n'

#define	V_TWO		2
#define V_ZERO		0

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
					std::cout << std::endl << "Capturing a 'Rectangle' object." << std::endl;
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

			const T& getHeight() const		{return this->height;}
			const T& getWidth() const		{return this->width;}

			T& getHeight()				{return (*this).height;}
			T& getWidth()				{return (*this).width;}

			T getArea()				{return this->width * this->height;}
			T getPerimeter()			{return V_TWO * (*this).width + V_TWO * (*this).height;}

			void setHeight(const T& height)		{(*this).height = height;}
			void setWidth(const T& width)		{(*this).width = width;}

			virtual ~Rectangle() = default;

			template <typename U>
			friend const Rectangle<U> obtain_results (const Rectangle<U>& rect);
	};

template <typename T>
int Rectangle<T>::counter = V_ZERO;

template <typename U>
const Rectangle<U> obtain_results (const Rectangle<U>& rect)
	{
		Rectangle<U> rec(rect.getWidth(), rect.getHeight());

		std::cout << std::endl << "Rectangle's outcomes." << std::endl;
		std::cout << "+ Counter:\t[" << rec.counter << "]." << std::endl;
		std::cout << "+ Width:\t[" << rec.getWidth() << "]." << std::endl;
		std::cout << "+ Height:\t[" << rec.getHeight() << "]." << std::endl;
		std::cout << "> Area:\t\t[" << rec.getArea() << "]." << std::endl;
		std::cout << "> Perimeter:\t[" << rec.getPerimeter() << "]." << std::endl << std::endl;

		return rec;
	}

int main()
	{
		Rectangle<int> foo;
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		Rectangle<int> bar;
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		Rectangle<int> baz;
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		obtain_results<int>(foo);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		obtain_results<int>(bar);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		obtain_results<int>(baz);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		foo = obtain_results<int>(bar);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		bar = obtain_results<int>(baz);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		baz = obtain_results<int>(foo);
		Rectangle<int>::enter_a_pause("Press ENTER to continue...");

		return V_ZERO;
	}
