/* The purpose of this program is to create a class that returns
   the next element in a given range created by the user. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define V_ONE   	1
#define V_ZERO  	0

/* Example class of an infinite counter. */
template <typename T>
class InfiniteCounter
	{
		private:
			T start = V_ZERO;
			T step = V_ZERO;
			T stop = V_ZERO;
			T value = start;

			friend std::istream& operator>> (std::istream& in, InfiniteCounter<T> &ic_object)
				{ic_object.capture(); return in;}
			friend std::ostream& operator<< (std::ostream& out, const InfiniteCounter<T> &ic_object)
				{ic_object.print(); return out;}

		protected:
			static int counter;

		public:
			InfiniteCounter() : start(V_ZERO), step(V_ZERO), stop(V_ZERO), value(V_ZERO)
				{this->counter++; this->capture();}
			InfiniteCounter(T& _start, T& _step, T& _stop) : start(_start), step(_step), stop(_stop), value(_start)
				{(*this).counter++;}
			InfiniteCounter(InfiniteCounter<T>& ic_object) : start(ic_object.getStart()), step(ic_object.getStep()), stop(ic_object.getStop()), value(ic_object.getStart())
				{this->counter++;}

			InfiniteCounter<T>& operator=(const InfiniteCounter<T>& ic_object)
				{this->copy(ic_object); return *this;}

			T operator()()
				{
					T _value = this->value;

					if ((this->value >= this->start && this->value <= this->stop) ||
					    (this->value >= this->stop && this->value <= this->start))
						this->value += this->step;
					else
						{
							_value = this->value = this->start;
							this->value += this->step;
						}

					return _value;
				}

			 T operator[](const T &index) const
				{
					T _value = this->start;
					T max_index = (this->step) ? ((this->stop - this->start) / this->step) + V_ONE : V_ONE;
					T current_index = index % max_index;

					for (T idx = V_ZERO; idx < current_index && idx < max_index; idx++)
						_value += this->step;

					return _value;
				}

			operator T()	{return this->value;}

			virtual void capture()
				{
					std::cout << std::endl;
					std::cout << "Generator of infinite number series." << std::endl;

					std::cout << "Starting value of the series: ";
					(*this).start = InfiniteCounter<int>::enter_a_value(&this->start);

					std::cout << "Interval between each element: ";
					(*this).step = InfiniteCounter<int>::enter_a_value(&this->step);

					std::cout << "Stopping point value: ";
					(*this).stop = InfiniteCounter<int>::enter_a_value(&this->stop);

					this->value = this->start;
				}

			virtual void copy(const InfiniteCounter<T>& ic_object)
				{
					this->start = ic_object.getStart();
					this->step = ic_object.getStep();
					this->stop = ic_object.getStop();
					this->value = ic_object.getStart();
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


			const T& getStart()	const	{return this->start;}
			T& getStart()	 		{return this->start;}

			const T& getStep()	const	{return this->step;}
			T& getStep()			{return this->step;}

			const T& getStop()	const	{return this->stop;}
			T& getStop()			{return this->stop;}

			const T& getValue()	const	{return (*this).value;}

			virtual void print() const
				{
					std::cout << std::endl;
					std::cout << "Current values ​​of the 'InfiniteCounter' class." << std::endl;
					std::cout << "+ Start:\t[" << this->start << "]." << std::endl;
					std::cout << "+ Step:\t\t[" << this->step << "]." << std::endl;
					std::cout << "+ Stop:\t\t[" << this->stop << "]." << std::endl;
					std::cout << "* Value:\t[" << (*this).value << "]." << std::endl;
					std::cout << std::endl;
				}

			virtual void reset()
				{this->start = this->value = V_ZERO; this->stop = this->step = V_ONE;}

			void setStart(const T& _start = V_ZERO)	{this->start = this->value = _start;}
			void setStep(const T& _step = V_ONE)	{this->step = _step;}
			void setStop(const T& _stop = V_ZERO)	{this->stop = _stop;}
			void setValues(const T& _start = V_ZERO, const T& _step = V_ONE, const T& _stop = V_ZERO)
				{this->value = _start;}

			virtual ~InfiniteCounter() = default;
	};

/* Initialize counter of created class instances. */
template <typename T>
int InfiniteCounter<T>::counter = V_ZERO;

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int nums = V_ZERO, start = V_ZERO, step = V_ZERO, stop = V_ZERO;

		/* Generate a range of infinite series of numbers. */
		std::cout << "Generator a range of infinite series of numbers." << std::endl;
		std::cout << "Number of elements: ";
		nums = InfiniteCounter<int>::enter_a_value(&nums);

		std::cout << "+ Start value: ";
		start = InfiniteCounter<int>::enter_a_value(&start);

		std::cout << "+ Step  value: ";
		step = InfiniteCounter<int>::enter_a_value(&step);

		std::cout << "+ Stop  value: ";
		stop = InfiniteCounter<int>::enter_a_value(&stop);

		/* Create a class with the overloaded 'int' operator to generate series of numbers. */
		InfiniteCounter<int> my_counter = InfiniteCounter<int>(start, step, stop);
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* The latest updated values ​​are printed. */
		std::cout << my_counter;
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* The numbers within the specified range are generated one by one. */
		std::cout << std::endl << "List of sequential numbers generated within a range." << std::endl;
		for (int idx = V_ZERO; idx < nums; idx++)
			std::cout << "#: [" << idx << "]\t=\t[" << my_counter() << "]." << std::endl;
		InfiniteCounter<int>::enter_a_pause("Press the ENTER key to continue...");

		/* The latest updated values ​​are printed. */
		my_counter.print();
		std::cout << "> Last Value:\t{" << static_cast<int>(my_counter) << "}." << std::endl;
		my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* New values ​​are set for the object being treated. */
		InfiniteCounter<int> _my_counter {my_counter};
		_my_counter = my_counter;
		_my_counter.copy(my_counter);

		_my_counter.print();
		_my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* The latest updated values ​​are printed. */
		std::cout << std::endl << "Modification of the values ​​of the new object 'InfiniteCounter'." << std::endl;
		_my_counter.getStart() = my_counter.getStop();
		_my_counter.getStep() = -my_counter.getStep();
		_my_counter.getStop() = my_counter.getStart();

		std::cout << _my_counter;
		_my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* Numbers within the specified range are queried one by one by their index. */
		std::cout << std::endl << "List of sequential numbers calculated within a range." << std::endl;
		for (int idx = V_ZERO; idx < nums; idx++)
			std::cout << "#: [" << idx << "]\t=\t[" << _my_counter[idx] << "]." << std::endl;
		InfiniteCounter<int>::enter_a_pause("Press the ENTER key to continue...");

		/* The latest updated values ​​are printed. */
		_my_counter.print();
		std::cout << "> Last Value:\t{" << static_cast<int>(_my_counter) << "}." << std::endl;
		_my_counter.enter_a_pause("Press the ENTER key to continue...");

		/* Notices of termination of this program. */
		std::cout << std::endl;
		std::cout << "Done!" << '\n';
		std::cout << "This program has ended." << '\n';

		return V_ZERO;
	}
