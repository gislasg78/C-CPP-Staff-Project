/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <iostream>

/* Symbolic work constants. */
#define V_ONE   1
#define V_ZERO  0

/* Example class of an infinite counter. */
class InfiniteCounter
	{
		private:
			int start = V_ZERO;
			int step = V_ZERO;
			int stop = V_ZERO;
			int value = start;

		protected:
			static int counter;

		public:
			InfiniteCounter()		{this->counter++; this->capture();}
			InfiniteCounter(int &start, int &step, int &stop) : start(start), step(step), stop(stop) {}
			InfiniteCounter(InfiniteCounter &infinitecounterobject)
				{
					this->start = infinitecounterobject.getStart();
					this->step = infinitecounterobject.getStep();
					this->stop = infinitecounterobject.getStop();
				}

			virtual void capture()
				{
					std::cout << std::endl;
					std::cout << "Generator of infinite number series." << std::endl;
					std::cout << "Start value: ";
					std::cin >> this->start;
					std::cout << "Step  value: ";
					std::cin >> this->step;
					std::cout << "Stop  value: ";
					std::cin >> this->stop;
				}

			const int& getStart()	const	{return this->start;}
			int& getStart()			{return this->start;}

			const int& getStep()	const	{return this->step;}
			int& getStep()			{return this->step;}

			const int& getStop()	const	{return this->stop;}
			int& getStop()			{return this->stop;}

			const int& getValue()	const	{return (*this).value;}
			int& getValue()			{return (*this).value;}

			int operator()()
				{return (this->value >= this->start && this->value < this->stop) ? this->value += this->step : (*this).value = (*this).start + V_ONE;}

			virtual void print()
				{
					std::cout << std::endl;
					std::cout << "Current values ​​of the 'InfiniteCounter' class." << std::endl;
					std::cout << "+ Start:\t[" << this->start << "]." << std::endl;
					std::cout << "+ Step:\t\t[" << this->step << "]." << std::endl;
					std::cout << "+ Stop:\t\t[" << this->stop << "]." << std::endl;
					std::cout << "+ Value:\t[" << (*this).value << "]." << std::endl;
					std::cout << std::endl;
				}

			virtual void reset()		{this->start = this->stop = this->value = V_ZERO; this->step = V_ONE;}

			void setStart(const int &start)	{this->start = start;}
			void setStep(const int &step)	{this->step = step;}
			void setStop(const int &stop)	{this->stop = stop;}

			virtual ~InfiniteCounter() = default;
	};

int InfiniteCounter::counter = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int nums = V_ZERO, start = V_ZERO, step = V_ZERO, stop = V_ZERO;

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of elements: ";
		std::cin >> nums;
		std::cout << "Starting value of the series: ";
		std::cin >> start;
		std::cout << "Interval between each element: ";
		std::cin >> step;
		std::cout << "Stopping point value: ";
		std::cin >> stop;

		/* Create a class with the overloaded 'int' operator to generate series of numbers. */
		InfiniteCounter my_counter(start, step, stop);

		/* We use the generator to take 'n' given values. */
		std::cout << "Generator of series of consecutive numbers according to their interval." << std::endl;

		my_counter.print();
		for (int idx = V_ZERO; idx < nums; idx++)
			{
				std::cout << "#: " << idx << "\t[" << my_counter() << "]." << std::endl;
			}
		my_counter.print();

		/* We use the generator to take 'n' given values. */
		std::cout << std::endl << "Generator of series of consecutive numbers according to a predetermined interval." << std::endl;
		my_counter.reset();
		my_counter.setStart(start);
		my_counter.setStep(step);
		my_counter.getStop() = stop;
		my_counter.print();

		for (int idx = V_ZERO; idx < nums; idx++)
			{
				std::cout << "#: " << idx << "\t[" << my_counter() << "]." << std::endl;
			}
		my_counter.print();

		return V_ZERO;
	}
