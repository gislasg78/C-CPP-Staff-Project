#include <algorithm>
#include <iostream>
#include <iterator>

#define	V_FIVE		5
#define	V_MINUS_ONE	-1
#define	V_SEVEN		7
#define	V_THREE		3
#define	V_TWO		2
#define	V_ONE		1
#define V_ZERO  	0

class DynamicArray
	{
		private:
			size_t *array = nullptr;
			size_t size = V_ZERO;

		public:
			DynamicArray(const size_t& size) : array(new size_t[size]()), size(size)
				{this->fillArray(V_ZERO, size + V_MINUS_ONE, V_TWO);}

			const bool IsPrime(const size_t& number)
				{
					return (((number == V_TWO) || (number == V_THREE) || (number == V_FIVE) || (number == V_SEVEN)) ||
						((number % V_TWO) && (number % V_THREE) && (number % V_FIVE) && (number % V_SEVEN)));
				}

			void fillArray(const size_t& start, const size_t &finish, const size_t &last_number)
				{
					for (size_t idx = start, number = last_number; idx <= finish; number++)
						if ((*this).IsPrime(number)) *(this->array + idx++) = number;
				}

			void resize(const size_t& size)
				{
					size_t *array = new size_t[size]();
					std::copy((*this).array, (*this).array + std::min((*this).size, size), array);
					delete[] this->array;

					this->array = array;
					(*this).fillArray(std::min(this->size, size), std::max(this->size, size) + V_MINUS_ONE, (*this).array[(*this).size + V_MINUS_ONE] + V_ONE);
					this->size = size;
				}

			void show() const
				{
					std::cout << std::endl << "Displaying the array elements." << std::endl;
					std::copy(this->array, this->array + size, std::ostream_iterator<size_t>(std::cout, "\t"));
					std::cout << std::endl;
				}

			~DynamicArray()  {delete[] (*this).array;}
	};


int main()
	{
		size_t numbers = V_ZERO;

		std::cout << "Automatic adjuster for dynamic settings." << std::endl;
		std::cout << "Enter the number of items: ";
		std::cin >> numbers;

		DynamicArray dyn_array(numbers);
		dyn_array.show();

		std::cout << std::endl << "Enter the new number of items: ";
		std::cin >> numbers;

		dyn_array.resize(numbers);
		dyn_array.show();

		return V_ZERO;
	}
