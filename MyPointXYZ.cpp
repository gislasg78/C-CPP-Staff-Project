/* This program exemplifies the use of constructors, destructors,
   virtual and overridden functions as well as inheritance
   between classes in C++ with simple examples of 2D and 3D points.*/

/* Standard C libraries. */
#include <iostream>
#include <limits>

/* Symbolic work constants. */
constexpr char CARRIAGE_RETURN{'\n'};
constexpr int V_ZERO{};

/* Parent Class. */
template <typename TX, typename TY>
class Point2D
{
	private:
		TX x{};
		TY y{};

	protected:
		static size_t count;

	public:
		Point2D()						{this->count++;}
		Point2D(const TX& _x) : Point2D(_x, V_ZERO)
		{(*this).count++;}
		Point2D(const TX& _x, const TY& _y) : x(_x), y(_y)
		{this->count++;}

		static void enter_a_pause (const std::string& str_Message)
		{
			std::cout << str_Message;
			std::cin.clear();
			std::cin.get();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
		}

		virtual void print() const
		{
			std::cout << "Counter = {" << count << "}." << std::endl;
			std::cout << "(x = [" << x << "], y = [" << y << "])." << std::endl;
		}

		virtual void reset()					{*this = Point2D();}

		virtual ~Point2D()					{count--;}
};

/* Initialize 'A' class static global variable. */
template <typename TX, typename TY>
size_t Point2D<TX, TY>::count {V_ZERO};

/* Daughter Class. */
template <typename TX, typename TY, typename TZ>
class Point3D : public Point2D<TX, TY>
{
	private:
		TZ z{};

	public:
		Point3D() = default;
		Point3D(const TZ& _z) : Point2D<TX, TY>(), z(_z)					{}
		Point3D(const TX& _x, const TY& _y) : Point2D<TX, TY>(_x, _y)				{}
		Point3D(const TX& _x, const TY& _y, const TZ& _z) : Point2D<TX, TY>(_x, _y), z(_z)	{}

		virtual void print() const override
		{
			Point2D<TX, TY>::print();
			std::cout << "(z = [" << z << "])." << std::endl;
		}

		virtual void reset() override
		{*this = Point3D();}

		virtual ~Point3D() = default;
};

//Main function.
int main()
{
	/* Preliminary working variables. */
	int x{}, y{}, z{};

	std::cout << "Easy creation of 2D and 3D points." << std::endl;

	/* Capture the coordinates of the 2D point. */
	std::cout << std::endl << "'x' and 'y' coordinates for the 2D point." << std::endl;
	std::cout << "+ X Coord: ";
	std::cin >> x;
	std::cout << "+ Y Coord: ";
	std::cin >> y;
	Point2D<int, int>::enter_a_pause("Press the ENTER key to continue...");

	/* Display the captured coordinates for the 2D point. */
	std::cout << std::endl << "2D Point." << std::endl;
	Point2D<int, int> *point2D = new Point2D<int, int>{x, y};
	point2D->print();
	point2D->enter_a_pause("Press the ENTER key to continue...");

	/* Capture the coordinates of the 3D point. */
	std::cout << std::endl << "'x' and 'y' coordinates for the 3D point." << std::endl;
	std::cout << "+ X Coord: ";
	std::cin >> x;
	std::cout << "+ Y Coord: ";
	std::cin >> y;
	std::cout << "+ Z Coord: ";
	std::cin >> z;
	Point2D<int, int>::enter_a_pause("Press the ENTER key to continue...");

	/* Display the captured coordinates for the 3D point. */
	std::cout << std::endl << "3D Point." << std::endl;
	Point3D<int, int, int> *point3D = new Point3D<int, int, int>{x, y, z};
	point3D->print();
	point3D->enter_a_pause("Press the ENTER key to continue...");

	/* Reset the coordinates of each previously captured point. */
	std::cout << std::endl << "2D and 3D point reset." << std::endl;

	/* Reset the 2D point coordinates. */
	std::cout << std::endl << "2D Point." << std::endl;
	point2D->reset();
	point2D->print();
	Point2D<int, int>::enter_a_pause("Press the ENTER key to continue...");
	delete point2D;

	/* Reset the 3D point coordinates. */
	std::cout << std::endl << "3D Point." << std::endl;
	point3D->reset();
	point3D->print();
	Point2D<int, int>::enter_a_pause("Press the ENTER key to continue...");
	delete point3D;

	return V_ZERO;
}
