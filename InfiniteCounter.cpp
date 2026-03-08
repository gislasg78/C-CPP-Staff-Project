/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <iostream>
#include <limits>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define V_ONE   	1
#define V_ZERO  	0

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
			InfiniteCounter() : start(V_ZERO), step(V_ZERO), stop(V_ZERO), value(V_ZERO)
				{this->counter++; this->capture();}
			InfiniteCounter(int &start, int &step, int &stop) : start(start), step(step), stop(stop), value(start)
				{(*this).counter++;}
			InfiniteCounter(InfiniteCounter &ic_object)
				{
					this->counter++;

					this->start = ic_object.getStart();
					this->step = ic_object.getStep();
					this->stop = ic_object.getStop();
					this->value = ic_object.getStart();
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

					this->value = this->start;
				}

			static void enter_a_pause(const std::string& str_Message)
				{
					std::cout << str_Message;
					std::cin.clear();
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
				}

			const int& getStart()	const	{return this->start;}
			int& getStart() 		{return this->start;}

			const int& getStep()	const	{return this->step;}
			int& getStep()			{return this->step;}

			const int& getStop()	const	{return this->stop;}
			int& getStop()			{return this->stop;}

			const int& getValue()	const	{return (*this).value;}

			int operator()()
				{
					int value = this->value;

					if ((this->value >= this->start && this->value <= this->stop) ||
					    (this->value >= this->stop && this->value <= this->start))
						this->value += this->step;
					else
						{
							value = this->value = this->start;
							this->value += this->step;
						}

					return value;
				}

			 int operator[](const int &index)
				{
					int value = this->start;
					int max_index = (this->step) ? ((this->stop - this->start) / this->step) + V_ONE : V_ONE;
					int current_index = index % max_index;

					for (int idx = V_ZERO; idx < current_index && idx < max_index; idx++)
						value += this->step;

					return value;
				}

			virtual void print()
				{
					std::cout << std::endl;
					std::cout << "Current values ​​of the 'InfiniteCounter' class." << std::endl;
					std::cout << "+ Start:\t[" << this->start << "]." << std::endl;
					std::cout << "+ Step:\t\t[" << this->step << "]." << std::endl;
					std::cout << "+ Stop:\t\t[" << this->stop << "]." << std::endl;
					std::cout << "* Value:\t[" << (*this).value << "]." << std::endl;
					std::cout << std::endl;
				}

			virtual void reset()		{this->start = this->value = V_ZERO; this->stop = this->step = V_ONE;}

			void setStart(const int &start)	{this->start = this->value = start;}
			void setStep(const int &step)	{this->step = step;}
			void setStop(const int &stop)	{this->stop = stop;}

			virtual ~InfiniteCounter() = default;
	};

/* Initialize counter of created class instances. */
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

		/* The latest updated values ​​are printed. */
		my_counter.print();
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* The numbers within the specified range are generated one by one. */
		std::cout << std::endl << "List of sequential numbers generated within a range." << std::endl;
		for (int idx = V_ZERO; idx < nums; idx++)
			std::cout << "#: [" << idx << "]\t=\t[" << my_counter() << "]." << std::endl;
		InfiniteCounter::enter_a_pause("Press the ENTER key to continue...");

		/* The latest updated values ​​are printed. */
		my_counter.print();
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* New values ​​are set for the object being treated. */
		my_counter.getStart() = stop;
		my_counter.getStep() = -step;
		my_counter.getStop() = start;

		/* The latest updated values ​​are printed. */
		my_counter.print();
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* Numbers within the specified range are queried one by one by their index. */
		std::cout << std::endl << "List of sequential numbers calculated within a range." << std::endl;
		for (int idx = V_ZERO; idx < nums; idx++)
			std::cout << "#: [" << idx << "]\t=\t[" << my_counter[idx] << "]." << std::endl;
		InfiniteCounter::enter_a_pause("Press the ENTER key to continue...");

		/* The latest updated values ​​are printed. */
		my_counter.print();
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		return V_ZERO;
	}
