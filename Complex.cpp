/* This program exemplifies the use of a class that functions
   to store complex numbers and perform mathematical operations
   with those numbers. */

/* Libraries Standards of Work. */
#include <iostream>
#include <sstream>

/* Symbolic work constants. */
constexpr int  V_MINUS_TWO	{-2};
constexpr int  V_ONE		{1};
constexpr char V_PLUS_SIGN	{0x2b};
constexpr int  V_ZERO		{};

/* Class to handle custom exceptions. */
class ComplexNumberFormatErrorException : public std::exception
	{
		public:
			const char* what() const noexcept override
				{
					return "Damn! Invalid complex number format.";
				}
	};


/* Definition of the 'Complex' class. */
template <typename TX, typename TY>
class Complex
	{
		private:
			/* Member variables of the 'Complex' class. */
			TX real {V_ZERO};
			TY imaginary {V_ZERO};

			/* Overloading of the '>>' extraction operator. */
			template <typename U, typename V>
			friend std::istream& operator>> (std::istream& in, Complex<U, V>& complex);

			/* Overloading of the '<<' insertion operator. */
			template <typename U, typename V>
			friend std::ostream& operator<< (std::ostream& out, const Complex<U, V>& complex);

		protected:
			/* Static variable for counting class instances. */
			static int counter;

		public:
			/* Default constructor. */
			Complex() : real(V_ZERO), imaginary(V_ZERO)				{(*this).counter++;}

			/* Constructor with mandatory parameters. */
			Complex(TX _real, TY _imaginary = V_ZERO) : real(_real), imaginary(_imaginary)
				{this->counter++;}

			/* Copy Builder. */
			Complex(const Complex<TX, TY>& complex) : real(complex.real), imaginary(complex.imaginary)
				{this->counter++;}

			/* Motion Builder. */
			Complex(Complex<TX, TY>&& complex) : real(complex.real), imaginary(complex.imaginary)
				{(*this).counter--; complex.reset();}

			/* Overloaded copy assignment operator. */
			Complex<TX, TY>& operator= (const Complex<TX, TY>& complex)
				{this->copy(complex); return *this;}

			/* Overloaded movement assignment operator. */
			Complex<TX, TY>& operator= (Complex<TX, TY>&& complex)
				{this->counter--; (*this).copy(complex); complex.reset(); return *this;}

			/* Overloading the addition operator. */
			Complex<TX, TY> operator+ (Complex<TX, TY>& complex)
				{return Complex<TX, TY>{this->real + complex.getReal(), this->imaginary + complex.getImaginary()};}

			Complex<TX, TY> operator+ (Complex<TX, TY>&& complex)
				{return Complex<TX, TY>{this->real + complex.getReal(), this->imaginary + complex.getImaginary()};}

			/* Overloading the subtraction operator. */
			Complex<TX, TY> operator- (Complex<TX, TY>& complex)
				{return Complex<TX, TY>{(*this).real - complex.getReal(), (*this).imaginary - complex.getImaginary()};}

			Complex<TX, TY> operator- (Complex<TX, TY>&& complex)
				{return Complex<TX, TY>{(*this).real - complex.getReal(), (*this).imaginary - complex.getImaginary()};}

			/* Member function to copy objects. */
			virtual Complex<TX, TY>& copy (const Complex<TX, TY>& complex)
				{this->real = complex.getReal(); this->imaginary = complex.getImaginary(); return *this;}

			/* Functions that access the member variables of the 'Complex' class. */
			const int& getCounter()		const			{return (*this).counter;}

			const TX& getReal()		const			{return this->real;}
			TX& getReal()						{return (*this).real;}

			const TY& getImaginary()	const			{return this->imaginary;}
			TY& getImaginary()					{return (*this).imaginary;}

			/* Member function to move objects. */
			virtual Complex<TX, TY>& move (Complex<TX, TY>&& complex)
				{(*this).counter--; this->copy(complex); complex.reset(); return *this;}

			/* Member function to reset the member variables of the number class 'Complex'. */
			void reset()						{(*this).real = (*this).imaginary = V_ZERO;}

			/* Modifying functions to the member variables of the 'Complex' class. */
			void setBoth (const TX& _real = V_ZERO, const TY& _imaginary = V_ZERO)
				{(*this).real = _real; (*this).imaginary = _imaginary;}

			void setReal (const TX& _real = V_ZERO)			{this->real = _real;}
			void setImaginary (const TY& _imaginary = V_ZERO)	{this->imaginary = _imaginary;}

			/* Virtual destructor for polymorphism and inheritance. */
			virtual ~Complex() = default;
	};

/* Defining the '>>' operator overload for std::cin. */
template <typename T, typename U>
std::istream& operator>> (std::istream& in, Complex<T, U>& complex)
	{
		/* Preliminary working variables. */
		std::string str_value {std::string()};
		std::cin >> str_value;

		/* Find the position of the '+' symbol. */
		std::size_t plusPos = str_value.find(V_PLUS_SIGN);

		/* It is validated whether the position returned when searching for the '+' symbol is valid. */
		if (plusPos == std::string::npos)
			{
				/* Handle error if format is not correct. */
				std::cin.setstate(std::ios::failbit);
				throw ComplexNumberFormatErrorException();
			}
		else
			{
				/* Extract the real part and the imaginary part of the complex number from the string. */
				try
					{
						complex.real = std::stod(str_value.substr(V_ZERO, plusPos));
						complex.imaginary = std::stod(str_value.substr(plusPos + V_ONE, str_value.length() - plusPos + V_MINUS_TWO));	//-2 to remove 'i'.
					}
				catch (const std::exception& e)
					{
						std::cerr << "Exception thrown: " << '\x5b' << e.what() << '\x5d' << '\x2e' << std::endl;
					}
			}

		return in;
	}

/* Defining the '<<' operator overload for std::cout. */
template <typename T, typename U>
std::ostream& operator<< (std::ostream& out, const Complex<T, U>& complex)
	{
		std::cout << std::endl << "Information about the class 'Complex' Number." << std::endl;
		std::cout << "> Counter:\t" << '\x5b' << complex.counter << '\x5d' << '\x2e' << std::endl;
		std::cout << "+ Real:\t\t" << '\x5b' << complex.real << '\x5d' << '\x2e' << std::endl;
		std::cout << "+ Imaginary:\t" << '\x5b' << complex.imaginary << '\x5d' << '\x2e' << std::endl;
		std::cout << "* Type:\t\t" << '\x5b' << typeid(complex).name() << '\x5d' << '\x2e' << std::endl;

		return out;
	}

/* Initialization of the static variable for counting class instances. */
template <typename T, typename U>
int Complex<T, U>::counter {V_ZERO};

//Main function.
int main()
	{
		/* Initial header messages. */
		Complex<double, double> *p_complex {new Complex<double, double>{}};

		/* Verify if it is feasible to allocate memory to object number 'Complex'. */
		if ((p_complex))
			{
				std::cout << "Program that tests with exceptions." << std::endl;
				std::cout << *p_complex << std::endl;
				std::cout << "Enter a complex number of the exact form: 'a+bi': ";

				/* Testing and obtaining the complex number of the form: 'a+bi'. */
				try
					{
						try
							{
								std::cin >> *p_complex;
							}
						catch (const std::exception& e)
							{
								std::cerr << "Exception thrown: " << '\x5b' << e.what() << '\x5d' << '\x2e' << std::endl;
								throw e;
							}
					}
				catch (const std::exception& e)
					{
						std::cerr << "Exception thrown: " << '\x5b' << e.what() << '\x5d' << '\x2e' << std::endl;
					}

				/* Sets flag on input as invalid complex number format. */
				if (std::cin.fail())
					{
						std::cerr << std::endl << "Mistake! Incorrect input complex number format." << std::endl;
					}
				else
					{
						std::cout << *p_complex;
						std::cout << std::endl << "Complex number entered: " << '\x5b' << (*p_complex).getReal() << '\x5d' << " + " << '\x5b' << (*p_complex).getImaginary() << '\x5d' << "i" << '\x2e' << std::endl;
					}

				/* Delete the pointer that was successfully created. */
				delete p_complex;
			}
		else
			std::cerr << std::endl << "There is not enough dynamic memory to allocate to the pointer for the number 'Complex'." << std::endl;

		return V_ZERO;
	}
