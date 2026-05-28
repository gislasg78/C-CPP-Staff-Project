/* This program creates a class of type 'Bucket' that stores in two arrays
   the characters of the variables to be stored and their status of occupied or unoccupied,
   and overloads the 'new' and 'delete' operators to exemplify their proper use. */

/* Libraries Standards of Work. */
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <new>
#include <sstream>

/* Symbolic work constants. */
template <typename T>
constexpr T ACCENT_MARK			{T(0x7e)};
template <typename T>
constexpr T CARRIAGE_RETURN		{T('\n')};
template <typename T>
constexpr T NORMAL_SPACE		{T('\x20')};
template <typename T>
constexpr T NULL_CHARACTER		{T('\0')};
template <typename T>
constexpr T V_CHAR_LOWER_Y		{T('\x79')};
template <typename T>
constexpr T V_CHAR_UPPER_Y		{T('\x59')};

/* Working numerical constants. */
template <typename T>
constexpr T MAX_NUMBER_OF_BUCKETS	{T{32}};
template <typename T>
constexpr T MAX_SIZE_OF_BUCKET		{T(4096)};
template <typename T>
constexpr T V_ONE			{T(1)};
template <typename T>
constexpr T V_ZERO			{T(0)};

/* Class type Exception for memory segment allocation errors. */
class MemorySegmentAllocationException: public std::exception
	{
		public:
			const char* what() const noexcept override
				{
					return "Damn! Memory Segment Allocation Error. Inner Bucket Array already occupied.";
				}
	};

/* 'Bucket' type class to house memory blocks of a given size in an array of a given size. */
struct Bucket
	{
		/* Symbolic static constants of the number of buckets and the size per bucket. */
		static constexpr std::size_t number_of_buckets { MAX_NUMBER_OF_BUCKETS<size_t> };
		static constexpr std::size_t size_of_bucket { MAX_SIZE_OF_BUCKET<size_t> };

		/* Two-dimensional matrix with the number of rows related to the number of buckets
		and columns according to the size per bucket. */
		std::byte matrix_buckets[number_of_buckets][size_of_bucket]{};
		bool bucket_used[number_of_buckets]{};

		/* Static member function to house the required memory. */
		static void *allocate_memory(Bucket& bucket, std::size_t num_bytes)
			{
				if (num_bytes > size_of_bucket)
					throw std::bad_alloc();

				for (std::size_t idx{}; idx < number_of_buckets; idx++)
					{
						if (!bucket.bucket_used[idx])
							{
								bucket.bucket_used[idx] = true;
								return bucket.matrix_buckets[idx];
							}
					}

				throw MemorySegmentAllocationException();
			}

		/* Static member function to deallocate (free up) the required memory. */
		void static deallocate_memory(Bucket& bucket, void *bucket_ptr, size_t num_bytes)
			{
				for (std::size_t idx{}; idx < number_of_buckets; idx++)
					{
						if (static_cast<void*>(bucket.matrix_buckets[idx]) == bucket_ptr)
							{
								if (num_bytes > size_of_bucket)
									throw std::overflow_error("Requested freed size exceeds bucket size.");

								for (std::size_t ind{}; ind < size_of_bucket && ind < num_bytes; ind++)
									bucket.matrix_buckets[idx][ind] = static_cast<std::byte>(NULL_CHARACTER<char>);

								bucket.bucket_used[idx] = false;
								break;
							}
					}
			}
};

/* Global declaration of an instance of a class of type 'Bucket'. */
Bucket bucket;	//Default Class constructors, assigment operators and destructor.

/* Improvised 'Template' type function to capture a given string of characters. */
template <typename T>
const T& capture_a_value(T* const ptr_value)
	{
		if (ptr_value)
			{
				std::string str_value {std::string()};

				if (std::getline(std::cin >> std::ws, str_value))
					{
						str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
						std::stringstream(str_value) >> *ptr_value;

						std::cout << "+ Characters:\t\t[" << std::cin.gcount() << "]." << std::endl;
						std::cout << "+ Value entered:\t[" << *ptr_value << "]. OK!" << std::endl << std::endl;
					}
				else
					{
						std::cerr << std::endl << std::endl << "Incorrect input information." << std::endl;

						if (std::cin.eof())
							std::cerr << "* EOF detected! *" << std::endl;

						if (std::cin.fail())
							std::cerr << "* Keyboard error detected! *" << std::endl;

						char c{};
						while (std::cin.get(c)) {}

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);

						std::cerr << "> Throwing overflow exception..." << std::endl << std::endl;
						throw std::overflow_error("The information coming from the keyboard input is overloaded.");
					}
			}
		else
			{
				std::cerr << std::endl << "A valid memory address was not provided." << std::endl << std::endl;
				throw std::runtime_error("The memory location must be valid and not a null pointer.");
			}

		return (ptr_value) ? *ptr_value : V_ZERO<T>;
	}

/* Overloading the 'new' operator whose argument is a number of characters to assign. */
void* operator new(size_t num_bytes)
	{
		return Bucket::allocate_memory(bucket, num_bytes);
	}

/* Overloading the 'delete' operator whose argument is a 'void' pointer to be evicted. */
void operator delete(void* bucket_ptr)
	{
		return Bucket::deallocate_memory(bucket, bucket_ptr, bucket.size_of_bucket);
	}

/* Overloading the 'delete' operator whose argument is a 'void' pointer to be evicted and quantity of bytes to free. */
void operator delete(void* bucket_ptr, size_t num_bytes)
	{
		return Bucket::deallocate_memory(bucket, bucket_ptr, num_bytes);
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char char_count {NORMAL_SPACE<char>}, *char_ptr {nullptr}, chr_answer {}, chr_response {NULL_CHARACTER<char>};
		int *first_tray {nullptr}, *second_tray {nullptr}, *third_tray {nullptr};
		int first_value = V_ZERO<int>, second_value = {V_ZERO<int>}, third_value = V_ZERO<int>;
		size_t attemps {V_ZERO<size_t>}, counter = {V_ZERO<size_t>};

		/* Capture of values ​​to be assigned to integer type pointers. */
		std::cout << "Overloading of the 'new' and 'delete' operators." << std::endl;

		/* Testing code with null pointer capture. */
		std::cout << std::endl << "Test code to test an input with a null pointer." << std::endl;
		try {first_value = capture_a_value<int>(nullptr);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl << std::endl;}

		/* Capturing data. */
		std::cout << "> First  value: ";
		try {first_value = capture_a_value<int>(&first_value);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		std::cout << "> Second value: ";
		try {second_value = capture_a_value<int>(&second_value);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		std::cout << "> Third  value: ";
		try {third_value = capture_a_value<int>(&third_value);}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* Information about the assigned 'Bucket'. */
		std::cout << std::endl << "Bucket Information." << std::endl;
		std::cout << "+ Quantity of buckets:\t[" << Bucket::number_of_buckets << "]\t=\t[" << MAX_NUMBER_OF_BUCKETS<size_t> << "]." << std::endl;
		std::cout << "+ Size of each bucket:\t[" << Bucket::size_of_bucket << "]\t=\t[" << MAX_SIZE_OF_BUCKET<size_t> << "]." << std::endl << std::endl;

		/* Assignment of independent dynamic objects of integer type. */
		std::cout << "Generating three new dynamic objects..." << std::endl;

		try {first_tray = new int {first_value};}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		try {second_tray = new int {second_value};}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		try {third_tray = new int {third_value};}
		catch (const std::exception& e)
		{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* Dumping information from assigned integer pointers. */
		std::cout << std::endl << "Traying Information." << std::endl;
		std::cout << "- First  Tray:\t(" << &first_tray << ")\t:\t[" << std::hex << first_tray << "]\t=\t{" << std::dec << *first_tray << "}." << std::endl;
		std::cout << "- Second Tray:\t(" << &second_tray << ")\t:\t[" << std::hex << second_tray << "]\t=\t{" << std::dec << *second_tray << "}." << std::endl;
		std::cout << "- Third  Tray:\t(" << &third_tray << ")\t:\t[" << std::hex << third_tray << "]\t=\t{" << std::dec << *third_tray << "}." << std::endl;

		/* Destruction of assigned integer pointers. */
		std::cout << std::endl << "Deleting created dynamic objects..." << std::endl;

		if (first_tray) {delete first_tray; first_tray = nullptr;}
		if (second_tray) {delete second_tray; second_tray = nullptr;}
		if (third_tray) {delete third_tray; third_tray = nullptr;}

		/* One-by-one generation of a dynamic object of type 'character' until the maximum number of buckets. */
		std::cout << std::endl << "Generating new elements infinitely with overloaded 'new' and 'delete' operators..." << std::endl;

		/* Test to detect if the memory segment allocation error exception is triggered. */
		try
			{
				std::cout << "Infinite loop of generating piles inside buckets..." << std::endl;
				std::cout << "Do you wish to continue the allocation operation? (y/n) : ";

				try {chr_response = capture_a_value<char>(&chr_response);}
				catch (const std::exception& e)
				{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

				/* A loop that assigns character by character to the 'Bucket' class until it is exhausted. */
				while ((chr_response == V_CHAR_LOWER_Y<char> || chr_response == V_CHAR_UPPER_Y<char>) && counter < MAX_NUMBER_OF_BUCKETS<size_t>)
					{
						/* Check and validate that they are printable ASCII characters. */
						attemps++;
						char_count = (char_count >= NORMAL_SPACE<char> && char_count <= ACCENT_MARK<char>) ? char_count : NORMAL_SPACE<char>;

						try
							{
								if ((char_ptr = new char{char_count++}))	//Use the available memory of the 'Bucket' but do not save it.
									{
										std::cout << "Char Assignment #: [" << std::dec << counter+ + V_ONE<size_t> << "] of: [" << Bucket::number_of_buckets << "]." << std::endl;
										std::cout << "* Base Address:\t\t(" << &char_ptr << ")." << std::endl;
										std::cout << "* Assigned Address:\t[" << static_cast<void *>(char_ptr) << "]." << std::endl;
										std::cout << "* Value Assigned:\t{" << static_cast<int>(*char_ptr) << "} = <" << *char_ptr << ">." << std::endl << std::endl;

										std::cout << "Would you like to release the previously assigned value? (y/n) : ";
										try {chr_answer = capture_a_value<char>(&chr_answer);}
										catch (const std::exception& e)
										{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

										if ((chr_answer == V_CHAR_LOWER_Y<char>) || (chr_answer == V_CHAR_UPPER_Y<char>))
											{
												std::cout << "> Address released:\t[" << static_cast<void*>(char_ptr) << "]." << std::endl << std::endl;

												counter--;
												char_count--;

												delete char_ptr;
												char_ptr = nullptr;
											}
									}

								counter++;
							}
						catch (const std::exception& e)
						{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}

						std::cout << "Do you wish to continue the allocation operation? (y/n) : ";
						try {chr_response = capture_a_value<char>(&chr_response);}
						catch (const std::exception& e)
						{std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;}
					}
			}
		catch (const std::exception& e)
			{
				std::cerr << "Exception occurred: [" << e.what() << "]." << std::endl;
			}

		std::cout << std::endl << "[" << attemps << "] Output results generated." << std::endl;

		std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
		std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

		return V_ZERO<int>;
	}
