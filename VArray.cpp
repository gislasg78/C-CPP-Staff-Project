#include <cassert>
#include <cstddef>
#include <iostream>

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

		const T& getValue(const std::size_t& index) const
		{
			return checkLimits(index) ? m_array[index] : V_ZERO<T>;
		}

		void reassignment(const std::size_t& array_size)
		{
			release();

			if (!m_array && !m_array_size)
			{
				m_array_size = array_size;
				m_array = new T[array_size]();
			}
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

		const std::size_t& getSize() const
		{return m_array_size;}

		void setValue(const std::size_t& index, const T& value)
		{if (checkLimits(index)) m_array[index] = value;}

		~MyArray()
		{
			release();
		}
};

int main()
{
	std::cout << "Test Class Array Values." << std::endl;

	MyArray<int> my_array {V_ELEVEN<size_t>};
	for (size_t i{}; i < my_array.getSize(); i++)
	{
		my_array.setValue(i, static_cast<int>(i));
		std::cout << "[" << my_array.getValue(i) << "]." << '\t';
	}

	std::cout << std::endl;
	MyArray<int> your_array {my_array};
	for (size_t i{}; i < my_array.getSize(); i++)
	{
		std::cout << "[" << my_array.getValue(i) << "]." << '\t';
	}

	std::cout << std::endl;
	MyArray<int> her_array;
	her_array = my_array;
	for (size_t i{}; i < her_array.getSize(); i++)
	{
		std::cout << "[" << her_array.getValue(i) << "]." << '\t';
	}

	std::cout << std::endl;
	MyArray<int> his_array {std::move(your_array)};
	for (size_t i{}; i < his_array.getSize(); i++)
	{
		std::cout << "[" << his_array.getValue(i) << "]." << '\t';
	}

	std::cout << std::endl;
	MyArray<int> our_array;
	our_array = std::move(my_array);
	for (size_t i{}; i < our_array.getSize(); i++)
	{
		std::cout << "[" << our_array.getValue(i) << "]." << '\t';
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}
