#include <cassert>
#include <cstddef>
#include <iostream>
#include <limits>

template <typename T>
constexpr T CARRIAGE_RETURN	{static_cast<T>('\n')};
template <typename T>
constexpr T V_ELEVEN		{static_cast<T>(11)};
template <typename T>
constexpr T V_ONE		{static_cast<T>(1)};
template <typename T>
constexpr T V_TWENTY_THREE	{static_cast<T>(23)};
template <typename T>
constexpr T V_ZERO		{static_cast<T>(0)};

template <typename TX, typename TY>
class MyArray
{
	private:
		TX m_array_size {};
		TY* m_array {nullptr};

	protected:
		static int s_counter;

	public:
		MyArray()
		{s_counter++;}

		MyArray(const TX& array_size) : m_array_size(array_size), m_array(new TY[array_size]())
		{s_counter++;}

		MyArray(const MyArray<TX, TY>& my_array) : m_array_size {my_array.m_array_size}, m_array {nullptr}
		{
			s_counter++;

			if (my_array.m_array && my_array.m_array_size)
			{
				if ((m_array = new TY[m_array_size]{}))
				{
					for (TX idx{}; idx < my_array.m_array_size; idx++)
					{
						m_array[idx] = my_array.m_array[idx];
					}
				}
			}
		}

		MyArray(MyArray<TX, TY>&& my_array) : m_array_size {my_array.m_array_size}, m_array {my_array.m_array}
		{
			my_array.m_array = nullptr;
			my_array.m_array_size = V_ZERO<TX>;
		}

		const TY& operator[](const TX& index) const
		{return (checkLimits(index)) ? m_array[index] : V_ZERO<TY>;}

		TY& operator[](const TX& index)
		{
			static TY local_value {};

			if (checkLimits(index))
				return m_array[index];
			else
				return local_value;
		}

		MyArray<TX, TY>& operator=(const MyArray<TX, TY>& my_array)
		{
			if (this != &my_array)
			{
				if (my_array.m_array && my_array.m_array_size)
				{
					release();

					if (!m_array && !m_array_size)
					{
						m_array_size = my_array.m_array_size;

						if ((m_array = new TY[m_array_size]{}))
						{
							for (TX idx{}; idx < my_array.m_array_size; idx++)
							{
								m_array[idx] = my_array.m_array[idx];
							}
						}
					}
				}
			}

			return *this;
		}

		MyArray<TX, TY>& operator=(MyArray<TX, TY>&& my_array)
		{
			if (this != &my_array)
			{
				if (my_array.m_array && my_array.m_array_size)
				{
					release();

					if (!m_array && !m_array_size)
					{
						m_array_size = my_array.m_array_size;
						m_array = my_array.m_array;

						my_array.m_array = nullptr;
						my_array.m_array_size = V_ZERO<TX>;
					}
				}
			}

			return *this;
		}

		bool checkSize(const TX& array_size = V_ZERO<TX>) const
		{return (array_size > std::numeric_limits<TX>::min() && array_size < std::numeric_limits<TX>::max());}

		bool checkLimits(const TX& index) const
		{return (m_array) && (index >= V_ZERO<TX> && index < m_array_size);}

		void erase(const TX& index)
		{
			if (checkLimits(index) && checkSize(m_array_size))
			{
				TX t_array_size {m_array_size - V_ONE<TX>};
				TY* t_array {new TY[t_array_size]()};

				for (TX idx{}; idx < index; idx++)
					t_array[idx] = *(m_array + idx);

				for (TX idx{index + V_ONE<TX>}; idx < m_array_size; idx++)
					t_array[idx - V_ONE<TX>] = *(m_array + idx);

				release();
				m_array = t_array;
				m_array_size = t_array_size;
			}
		}

		const TY *const &getPtrArray() const
		{return m_array;}

		const TX& getSize() const
		{return m_array_size;}

		const TY& getValue(const TX& index) const
		{return checkLimits(index) ? m_array[index] : V_ZERO<TY>;}

		TY& getValue(const TX& index)
		{
			static TY local_value {};

			if (checkLimits(index))
				return m_array[index];
			else
				return local_value;
		}

		void insert(const TX& index, const TY& value)
		{
			if (checkLimits(index) && checkSize(m_array_size))
			{
				TX t_array_size {m_array_size + V_ONE<TX>};
				TY* t_array {new TY[t_array_size]()};

				for (TX idx{}; idx < index; idx++)
					*(t_array + idx) = m_array[idx];

				t_array[index] = value;

				for (TX idx{index}; idx < m_array_size; idx++)
					*(t_array + idx + V_ONE<TX>) = m_array[idx];

				release();
				m_array = t_array;
				m_array_size = t_array_size;
			}
		}

		void print() const
		{
			int counter{};

			std::cout << std::endl << "Dynamic array information." << std::endl;
			std::cout << "< Counter:\t\t<" << s_counter << ">." << std::endl;
			std::cout << "- Address size:\t\t(" << &m_array_size << ")." << std::endl;
			std::cout << "> Content size:\t\t{" << m_array_size << "}." << std::endl << std::endl;

			std::cout << "+ Address pointer:\t(" << &m_array << ")." << std::endl;
			std::cout << "+ Content address:\t[" << m_array << "]." << std::endl;

			if (m_array && m_array_size)
				{
					std::cout << std::endl << "> First element:\t{" << *m_array << "}." << std::endl;
					std::cout << "* List of items. *" << std::endl;

					for (TX idx{}; idx < m_array_size; idx++)
					{
						std::cout << "#: [" << counter++ << "]\t:\t(" << &m_array[idx] << ")\t=\t{" << m_array[idx] << "}." << std::endl;
					}

					std::cout << "[" << counter << "] Output results generated." << std::endl;
				}

			std::cout << std::endl;
		}

		void release()
		{
			if (m_array && m_array_size)
			{
				delete [] m_array;
				m_array = nullptr;
				m_array_size = V_ZERO<TX>;
			}
		}

		void restore()
		{
			if (m_array && m_array_size)
				for (TX idx{}; idx < m_array_size; idx++)
					m_array[idx] = V_ZERO<TX>;
		}

		void setSize(const TX& array_size)
		{
			if (m_array && m_array_size && checkSize(array_size))
			{
				TX t_array_size {array_size};
				TY* t_array {new TY[t_array_size]()};

				for (TX idx{}; idx < t_array_size && idx < m_array_size; idx++)
					t_array[idx] = *(m_array + idx);

				release();
				m_array = t_array;
				m_array_size = t_array_size;
			}
			else
			{
				m_array_size = array_size;
				m_array = new TY[m_array_size]{};
			}
		}

		void setValue(const TX& index, const TY& value)
		{if (checkLimits(index)) m_array[index] = value;}

		~MyArray()
		{release(); s_counter--;}
};

template <typename TX, typename TY>
int MyArray<TX, TY>::s_counter {V_ZERO<int>};

void enter_a_pause(const std::string& str_Message)
{
	std::cout << str_Message;
	std::cin.clear();
	std::cin.get();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
}

int main()
{
	std::cout << "Test Class Array Values." << std::endl;

	MyArray<size_t, int> my_array {V_TWENTY_THREE<size_t>};

	std::cout << std::endl << "Loading data..." << std::endl;
	for (size_t idx{}; idx < my_array.getSize(); idx++)
	{
		my_array.getValue(idx) = static_cast<int>(idx);
		my_array.setValue(idx, static_cast<int>(idx));
		my_array[idx] = static_cast<int>(idx);

		std::cout << "#: [" << idx << "] = [" << my_array.getValue(idx) << "]." << std::endl;
	}
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Printing initial data..." << std::endl;
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Inserting a value..." << std::endl;
	my_array.insert(V_ZERO<size_t>, V_TWENTY_THREE<size_t>);
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Deleting a value..." << std::endl;
	my_array.erase(V_ZERO<size_t>);
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Unloading data..." << std::endl;
	for (size_t idx{}; idx < my_array.getSize(); idx++)
	{
		std::cout << "#: [" << idx << "] = [" << my_array[idx] << "]." << std::endl;
	}
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Copy constructor." << std::endl;
	MyArray<size_t, int> your_array {my_array};
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	your_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Copy assignment." << std::endl;
	MyArray<size_t, int> her_array;
	her_array = my_array;
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	her_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Move constructor." << std::endl;
	MyArray<size_t, int> his_array {std::move(your_array)};
	your_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	his_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Move assignment." << std::endl;
	MyArray<size_t, int> our_array;
	our_array = std::move(my_array);
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	his_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Builder with size information." << std::endl;
	MyArray<size_t, int> their_array{V_TWENTY_THREE<size_t>};
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Releasing..." << std::endl;
	their_array.release();
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Setting size array..." << std::endl;
	their_array.setSize(V_ELEVEN<size_t>);
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Setting size array..." << std::endl;
	their_array.setSize(V_TWENTY_THREE<size_t>);
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Setting size array..." << std::endl;
	their_array.setSize(V_ELEVEN<size_t>);
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Restoring..." << std::endl;
	their_array.restore();
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Releasing..." << std::endl;
	their_array.release();
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Inserting a value..." << std::endl;
	their_array.insert(V_ZERO<size_t>, V_ELEVEN<size_t>);
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Deleting a value..." << std::endl;
	their_array.erase(V_ZERO<size_t>);
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Restoring..." << std::endl;
	their_array.restore();
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Setting size array..." << std::endl;
	their_array.setSize(V_TWENTY_THREE<size_t>);
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Address & Size." << std::endl;
	std::cout << "> (" << their_array.getPtrArray() << ")." << std::endl;
	std::cout << "> [" << their_array.getSize() << "]." << std::endl;

	std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
	std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

	return EXIT_SUCCESS;
}
