#include <cassert>
#include <cstddef>
#include <iostream>
#include <limits>

template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};
template <typename T>
constexpr T V_ELEVEN		{T(11)};
template <typename T>
constexpr T V_ZERO		{T(0)};

template <typename T>
class MyArray
{
	private:
		std::size_t m_array_size {};
		T* m_array {nullptr};

	public:
		MyArray() = default;

		MyArray(const std::size_t& array_size) : m_array_size(array_size), m_array(new T[array_size]())
		{}

		MyArray(const MyArray<T>& my_array) : m_array_size {my_array.m_array_size}, m_array {nullptr}
		{
			if (my_array.m_array && my_array.m_array_size)
			{
				if ((m_array = new T[m_array_size]{}))
				{
					for (std::size_t idx{}; idx < my_array.m_array_size; idx++)
					{
						m_array[idx] = my_array.m_array[idx];
					}
				}
			}
		}

		MyArray(MyArray<T>&& my_array) : m_array_size {my_array.m_array_size}, m_array {my_array.m_array}
		{
			my_array.m_array = nullptr;
			my_array.m_array_size = V_ZERO<size_t>;
		}

		MyArray<T>& operator=(const MyArray<T>& my_array)
		{
			if (this != &my_array)
			{
				if (my_array.m_array && my_array.m_array_size)
				{
					release();

					if (!m_array && !m_array_size)
					{
						m_array_size = my_array.m_array_size;

						if ((m_array = new T[m_array_size]{}))
						{
							for (std::size_t idx{}; idx < my_array.m_array_size; idx++)
							{
								m_array[idx] = my_array.m_array[idx];
							}
						}
					}
				}
			}

			return *this;
		}

		MyArray<T>& operator=(MyArray<T>&& my_array)
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
						my_array.m_array_size = V_ZERO<size_t>;
					}
				}
			}

			return *this;
		}

		bool checkLimits(const std::size_t& index) const
		{return (m_array) && (index >= V_ZERO<size_t> && index < m_array_size);}

		const T* const& getPtrArray() const
		{return m_array;}

		const std::size_t& getSize() const
		{return m_array_size;}

		const T& getValue(const std::size_t& index) const
		{return checkLimits(index) ? m_array[index] : V_ZERO<T>;}

		void print() const
		{
			int counter{};

			std::cout << std::endl << "Dynamic array information." << std::endl;
			std::cout << "- Address size:\t\t(" << &m_array_size << ")." << std::endl;
			std::cout << "> Content size:\t\t{" << m_array_size << "}." << std::endl << std::endl;

			std::cout << "+ Address pointer:\t(" << &m_array << ")." << std::endl;
			std::cout << "+ Content address:\t[" << m_array << "]." << std::endl;

			if (m_array && m_array_size)
				{
					std::cout << "> First element:\t{" << *m_array << "}." << std::endl;

					std::cout << std::endl << "* List of items. *" << std::endl;

					for (std::size_t idx{}; idx < m_array_size; idx++)
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
				m_array_size = V_ZERO<size_t>;
			}
		}

		void restore()
		{
			if (m_array && m_array_size)
				for (std::size_t idx{}; idx < m_array_size; idx++)
					m_array[idx] = V_ZERO<size_t>;
		}

		void setSize(const std::size_t& array_size)
		{
			if (array_size)
			{
				release();

				if (!m_array && !m_array_size)
				{
					m_array_size = array_size;
					m_array = new T[m_array_size]{};
				}
			}
		}

		void setValue(const std::size_t& index, const T& value)
		{if (checkLimits(index)) m_array[index] = value;}

		~MyArray()
		{release();}
};

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

	MyArray<int> my_array {V_ELEVEN<size_t>};
	for (size_t idx{}; idx < my_array.getSize(); idx++)
	{
		my_array.setValue(idx, static_cast<int>(idx));
		std::cout << "#: [" << idx << "] = [" << my_array.getValue(idx) << "]." << std::endl;
	}
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Copy constructor. " << std::endl;
	MyArray<int> your_array {my_array};
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	your_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Copy assignment." << std::endl;
	MyArray<int> her_array;
	her_array = my_array;
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	her_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Move constructor." << std::endl;
	MyArray<int> his_array {std::move(your_array)};
	your_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	his_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Move assignment." << std::endl;
	MyArray<int> our_array;
	our_array = std::move(my_array);
	my_array.print();
	enter_a_pause("Press the ENTER key to continue...");
	his_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Builder with size information." << std::endl;
	MyArray<int> their_array{V_ELEVEN<size_t>};
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

	std::cout << std::endl << "Restoring..." << std::endl;
	their_array.restore();
	their_array.print();
	enter_a_pause("Press the ENTER key to continue...");

	std::cout << std::endl << "Address & Size." << std::endl;
	std::cout << "> (" << their_array.getPtrArray() << ")." << std::endl;
	std::cout << "> [" << their_array.getSize() << "]." << std::endl;

	std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
	std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

	return EXIT_SUCCESS;
}
