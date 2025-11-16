#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>

#define	V_FIVE		5
#define	V_MINUS_ONE	-1
#define	V_SEVEN		7
#define	V_THREE		3
#define	V_TWO		2
#define	V_ONE		1
#define V_ZERO  	0

template <class T>
class DynamicArray
	{
		private:
			T *array = nullptr;
			T size = V_ZERO;

		public:
			DynamicArray(const T& size) : array(new T[size]()), size(size)
				{this->fillArray(V_ZERO, size + V_MINUS_ONE, V_TWO);}

			const bool IsPrime(const T& number)
				{
					return (((number == V_TWO) || (number == V_THREE) || (number == V_FIVE) || (number == V_SEVEN)) ||
						((number % V_TWO) && (number % V_THREE) && (number % V_FIVE) && (number % V_SEVEN)));
				}

			static const T& enter_a_value(T *const ptr_value)
				{
					if (ptr_value)
						{
							std::string str_value = {};
							std::getline(std::cin >> std::ws, str_value);
							str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
							std::stringstream(str_value) >> *ptr_value;

							std::cout << "Value entered:\t[" << *ptr_value << "]. OK!" << std::endl;
						}
					else
						std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

					return *ptr_value;
				}

			const T fillArray(const T& start, const T &finish, const T &last_number)
				{
					T counter = V_ZERO;

					for (T idx = start, number = last_number; idx <= finish; number++)
						if ((*this).IsPrime(number))
							{
								counter++;
								*(this->array + idx++) = number;
							}

					return counter;
				}

			void resize(const T& size)
				{
					T *array = new T[size]();
					T counter = V_ZERO;
					T maximum = std::max(this->size, size);
					T minimum = std::min((*this).size, size);

					std::copy((*this).array, (*this).array + minimum, array);

					T last_value = array[minimum + V_MINUS_ONE];

					delete[] this->array;

					this->array = array;
					this->size = size;

					counter = (*this).fillArray(minimum, maximum + V_MINUS_ONE, last_value + V_ONE);
					std::cout << "[" << counter << "] Output results generated." << std::endl;
				}

			void show() const
				{
					std::cout << std::endl << "Displaying the prime number array." << std::endl;
					std::copy(this->array, this->array + this->size, std::ostream_iterator<T>(std::cout, "\t"));
					std::cout << std::endl;
				}

			~DynamicArray()	{delete[] (*this).array;}
	};


int main()
	{
		size_t szt_numbers = V_ZERO;

		std::cout << "Automatic adjuster for dynamic settings." << std::endl;
		std::cout << "Enter the number of items: ";
		szt_numbers = DynamicArray<size_t>::enter_a_value(&szt_numbers);

		DynamicArray<size_t> my_dyn_array(szt_numbers);
		my_dyn_array.show();

		std::cout << std::endl << "Enter the new number of items: ";
		szt_numbers = DynamicArray<size_t>::enter_a_value(&szt_numbers);

		my_dyn_array.resize(szt_numbers);
		my_dyn_array.show();

		return V_ZERO;
	}
