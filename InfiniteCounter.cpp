/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <iostream>

/* Symbolic work constants. */
#define V_ONE   1
#define V_ZERO  0

class InfiniteCounter
	{
		private:
			int start = V_ZERO;
			int step = V_ZERO;

		protected:
			static int counter;

		public:
			InfiniteCounter()		{this->counter++; this->capture();}
			InfiniteCounter(int &start, int &step) : start(start), step(step) {}
			InfiniteCounter(InfiniteCounter &infinitecounterobject)
				{
					this->start = infinitecounterobject.start;
					this->step = infinitecounterobject.step;
				}

			virtual void capture()
				{
					std::cout << std::endl;
					std::cout << "Generator of infinite number series." << std::endl;
					std::cout << "Start value: ";
					std::cin >> this->start;
					std::cout << "Step  value: ";
					std::cin >> this->step;
				}

			int getStart()	const		{return this->start;}
			int getStep()	const		{return this->step;}

			int operator()()		{return this->start += this->step;}

			virtual void print()
				{
					std::cout << std::endl;
					std::cout << "Current values ​​of the 'InfiniteCounter' class." << std::endl;
					std::cout << "Start:\t[" << this->start << "]." << std::endl;
					std::cout << "Step:\t[" << this->step << "]." << std::endl;
					std::cout << std::endl;
				}

			virtual void reset()		{this->start = V_ZERO; this->step = V_ONE;}

			void setStart(const int &start)	{this->start = start;}
			void setStep(const int &step)	{this->step = step;}

			virtual ~InfiniteCounter() = default;
	};

int InfiniteCounter::counter = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int nums = V_ZERO, start = V_ZERO, step = V_ZERO;

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of elements: ";
		std::cin >> nums;
		std::cout << "Starting value of the series: ";
		std::cin >> start;
		std::cout << "Interval between each element: ";
		std::cin >> step;

		/* Create a class with the overloaded 'int' operator to generate series of numbers. */
		InfiniteCounter my_counter(start, step);

		/* We use the generator to take 'n' given values. */
		std::cout << std::endl << "Generator of series of consecutive numbers according to their interval." << std::endl;

		my_counter.print();
		for (int idx = V_ZERO; idx < nums; idx++)
			{
				std::cout << "#: " << idx << "\t[" << my_counter() << "]." << std::endl;
			}
		my_counter.print();

		/* We use the generator to take 'n' given values. */
		std::cout << std::endl << "Generator of series of consecutive numbers according to a predetermined interval." << std::endl;
		my_counter.reset();
		my_counter.print();

		for (int idx = V_ZERO; idx < nums; idx++)
			{
				std::cout << "#: " << idx << "\t[" << my_counter() << "]." << std::endl;
			}
		my_counter.print();

		return V_ZERO;
	}
