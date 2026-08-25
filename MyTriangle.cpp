#include <iostream>
#include <limits>

#define	CARRIAGE_RETURN			'\n'

#define V_FOUR				4
#define V_ONE_POINT_SEVENTY_THREE	1.73
#define V_THREE				3
#define V_ZERO				0

template <typename T>
class EquilateralTriangle
{
	private:
		T side {};

		template <typename U>
		friend void displayResults (const EquilateralTriangle<U>& eq_tr);

		friend std::ostream& operator<< (std::ostream& os, const EquilateralTriangle<T>& eq_tr)
		{eq_tr.print(); return os;}

		friend std::istream& operator>> (std::istream& is, EquilateralTriangle& eq_tr)
		{eq_tr.capture(); return is;}

	protected:
		static std::size_t counter;

	public:
		EquilateralTriangle() : side(V_ZERO)
		{(*this).counter++; (*this).capture();}
		EquilateralTriangle(const T& _side) : side(_side)
		{this->counter++;}

		EquilateralTriangle(const EquilateralTriangle<T>& eq_tr) : side(eq_tr.side)
		{this->counter++;}
		EquilateralTriangle(EquilateralTriangle<T>&& eq_tr) : side (eq_tr.side)
		{(*this).counter++; eq_tr.side = V_ZERO;}

		EquilateralTriangle<T>& operator= (const EquilateralTriangle<T>& eq_tr)
		{this->copy(eq_tr); return *this;}
		EquilateralTriangle<T>& operator= (EquilateralTriangle<T>&& eq_tr)
		{(*this).copy(eq_tr); eq_tr.side = V_ZERO; return *this;}

		operator T() const			{return side;}

		void capture()
		{
			std::cout << std::endl << "Equilateral Triangle Capture Info." << std::endl;
			std::cout << "+ Enter a length side: ";
			std::cin >> (*this).side;
		}

		void copy(const EquilateralTriangle<T>& eq_tr)
		{this->side = eq_tr.side;}

		const T getArea() const			{return side * V_THREE;}
		const T getCircumference() const	{return (V_ONE_POINT_SEVENTY_THREE * side * side) / V_FOUR;}

		const T& getSide() const		{return side;}
		T& getSide()				{return side;}

		void print() const
		{
			std::cout << "Equilateral Triangle Results." << std::endl;
			std::cout << "+ Counter:\t\t[" << (*this).counter << "]." << std::endl;
			std::cout << "+ Side:\t\t\t[" << this->side << "]." << std::endl;
			std::cout << "* Area:\t\t\t{" << this->getArea() << "}." << std::endl;
			std::cout << "* Circumference:\t{" << this->getCircumference() << "}." << std::endl;
		}

		void setSide(const T& _side = V_ZERO)	{side = _side;}

		~EquilateralTriangle()			{counter--;}
};

template <typename T>
std::size_t EquilateralTriangle<T>::counter {V_ZERO};

template <typename T>
void displayResults (const EquilateralTriangle<T>& eq_tr)
{
	std::cout << "Equilateral Triangle Outcomes." << std::endl;
	std::cout << "+ Counter:\t\t[" << eq_tr.counter << "]." << std::endl;
	std::cout << "+ Side:\t\t\t[" << eq_tr.side << "]." << std::endl;
	std::cout << "* Area:\t\t\t{" << eq_tr.getArea() << "}." << std::endl;
	std::cout << "* Circumference:\t{" << eq_tr.getCircumference() << "}." << std::endl;
}

void enter_a_pause(const std::string& str_Message)
{
	std::cout << str_Message;
	std::cin.clear();
	std::cin.get();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
}

int main()
{
	std::cout << "Equilateral Triangle Single Problem." << std::endl;

	EquilateralTriangle<double> eq_tr1 {};
	std::cout << std::endl << eq_tr1;
	enter_a_pause("Press the ENTER key to continue...");

	EquilateralTriangle<double> eq_tr2 {};
	std::cout << std::endl << eq_tr2;
	enter_a_pause("Press the ENTER key to continue...");

	EquilateralTriangle<double> eq_temp {V_THREE};
	std::cout << std::endl << eq_temp;
	enter_a_pause("Press the ENTER key to continue...");

	EquilateralTriangle<double> eq_tr3 {eq_tr1};
	std::cout << std::endl << eq_tr3;
	enter_a_pause("Press the ENTER key to continue...");

	EquilateralTriangle<double> eq_tr4 {std::move(eq_temp)};
	std::cout << std::endl << eq_temp;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << eq_tr4;
	enter_a_pause("Press the ENTER key to continue...");

	eq_temp = eq_tr1;
	eq_tr1 = eq_tr2;
	eq_tr2 = eq_temp;

	std::cout << std::endl << eq_tr1;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << eq_tr2;
	enter_a_pause("Press the ENTER key to continue...");

	eq_temp = std::move(eq_tr1);
	eq_tr1 = std::move(eq_tr2);
	eq_tr2 = std::move(eq_temp);

	std::cout << std::endl << eq_tr1;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << eq_tr2;
	enter_a_pause("Press the ENTER key to continue...");

	std::swap(eq_tr1, eq_tr2);

	std::cout << std::endl << eq_tr1;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << eq_tr2;
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl;
	displayResults(eq_tr1);
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl;
	displayResults(eq_tr2);
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "(" << (double) eq_tr1 << ", " << double(eq_tr2) << ")." << std::endl;

	std::cout << std::endl << "Done!" << std::endl;
	std::cout << "This program has ended." << std::endl;
	enter_a_pause("Press the ENTER key to continue...");

	return EXIT_SUCCESS;
}
