#include <iostream>
#include <vector>

#define	V_PI		3.1415926
#define V_EULER		2.7182818
#define	V_GOLDEN	1.6180339
#define V_ZERO  	0

template <typename T>
class Vector
	{
		public:
			std::vector<T> data{};

			Vector(std::initializer_list<T> list) : data(list) {}

			//Function to convert to another C type (default will be T).
			template <typename C = T>
			Vector<C> convert() const
				{
					Vector<C> result = {};

					for (const T& value : data)
						{
							result.data.push_back(static_cast<C>(value));   //We convert T to C
						}

					return result;
				}

			void print() const
				{
					std::cout << std::endl << "Printing values ​​in the vector." << std::endl;
					std::cout << "Type: [" << typeid(data).name() << "]." << std::endl;

					for (const T& value : data)
						{
							std::cout << "[" << value << "].\t";
						}

					std::cout << std::endl;
				}
	};

//Main function.
int main()
	{
		/* Initial presentation header. */
		std::cout << "Program that uses templates to convert objects." << std::endl;

		Vector<double> v1{V_GOLDEN, V_EULER, V_PI};   //Vector of types 'doubles'.
		v1.print();

		//Convert from 'double' to 'float' using template with C = 'float'.
		Vector<float> v2 = v1.convert<float>();
		v2.print();  //It should display the values converted to 'float' type.

		//Convert from 'double' to 'int' using template with C = 'int'.
		Vector<int> v3 = v1.convert<int>();
		v3.print(); //It should display the values converted to 'int' type.

		return V_ZERO;
	}
