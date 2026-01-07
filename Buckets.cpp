/* This program creates a class of type 'Bucket' that stores in two arrays
   the characters of the variables to be stored and their status of occupied or unoccupied,
   and overloads the 'new' and 'delete' operators to exemplify their proper use. */

/* Libraries Standards of Work. */
#include <algorithm>
#include <cstddef>
#include <exception>
#include <iostream>
#include <new>
#include <sstream>

/* Symbolic work constants. */
#define	NULL_CHARACTER	'\0'

#define	V_CHAR_LOWER_Y	'\x79'
#define	V_CHAR_UPPER_Y	'\x59'

/* Working numerical constants. */
#define	V_ONE		1
#define	V_TEN		10
#define	V_ZERO		0
#define	V_4096		4096

/* Class type Exception for memory segment allocation errors. */
class MemorySegmentAllocationException: public std::exception
	{
		public:
			const char* what() const noexcept override
				{
					return "Damn! Memory Segment Allocation Error. Bucket Array already occupied.";
				}
	};

/* 'Bucket' type class to house memory blocks of a given size in an array of a given size. */
struct Bucket
	{
		static constexpr std::size_t number_of_buckets{ V_TEN };
		static constexpr std::size_t size_of_bucket{ V_4096 };

		std::byte matrix_buckets[number_of_buckets][size_of_bucket]{};
		bool bucket_used[number_of_buckets]{};

		static void *allocate_memory(Bucket& bucket, std::size_t bytes)
			{
				if (bytes <= size_of_bucket)
					{
						for (std::size_t idx{}; idx < number_of_buckets; idx++)
							{
								if (!bucket.bucket_used[idx])
									{
										bucket.bucket_used[idx] = true;
										return bucket.matrix_buckets[idx];
									}
							}
					}

				throw MemorySegmentAllocationException();
			}

		void static deallocate_memory(Bucket& bucket, void *ptr)
			{
				for (std::size_t idx{}; idx < number_of_buckets; idx++)
					{
						if (bucket.matrix_buckets[idx] == ptr)
							{
								bucket.bucket_used[idx] = false;
								return;
							}
					}
			}
	};

/* Global declaration of an instance of a class of type 'Bucket'. */
Bucket bucket;

/* Improvised 'Template' type function to capture a given string of characters. */
template <typename T>
const T& capture_a_value(T* const ptr_value)
	{
		if (ptr_value)
			{
				std::string str_value{};
				std::getline(std::cin >> std::ws, str_value);
				str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
				std::stringstream(str_value) >> *ptr_value;

				std::cout << "Value entered: [" << *ptr_value << "]. OK!" << std::endl;
			}
		else
			std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

		return *ptr_value;
	}

/* Overloading the 'new' operator whose argument is a number of characters to assign. */
void* operator new (size_t bytes)
	{
		return Bucket::allocate_memory(bucket, bytes);
	}

/* Overloading the 'delete' operator whose argument is a 'void' pointer to be evicted. */
void operator delete (void* ptr)
	{
		return Bucket::deallocate_memory(bucket, ptr);
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char chr_response = NULL_CHARACTER;
		int first_value = V_ZERO, second_value = V_ZERO, third_value = V_ZERO;
		size_t counter = V_ZERO;

		/* Capture of values ​​to be assigned to integer type pointers. */
		std::cout << "Overloading of the 'new' and 'delete' operators." << std::endl;
		std::cout << "First  value : ";
		first_value = capture_a_value<int>(&first_value);
		std::cout << "Second value : ";
		second_value = capture_a_value<int>(&second_value);
		std::cout << "Third value  : ";
		third_value = capture_a_value<int>(&third_value);

		/* Information about the assigned 'Bucket'. */
		std::cout << std::endl << "Bucket Information." << std::endl;
		std::cout << "+ Quantity of buckets:\t[" << Bucket::number_of_buckets << "]." << std::endl;
		std::cout << "+ Size of each bucket:\t[" << Bucket::size_of_bucket << "]." << std::endl << std::endl;

		/* Assignment of independent dynamic objects of integer type. */
		std::cout << "Generating new dynamic objects..." << std::endl;

		int *first_tray = new int {first_value};
		int *second_tray = new int {second_value};
		int *third_tray = new int {third_value};

		/* Dumping information from assigned integer pointers. */
		std::cout << std::endl << "Traying Information." << std::endl;
		std::cout << "First  Tray :\t{" << std::hex << first_tray << "}\t=\t[" << std::dec << *first_tray << "]." << std::endl;
		std::cout << "Second Tray :\t{" << std::hex << second_tray << "}\t=\t[" << std::dec << *second_tray << "]." << std::endl;
		std::cout << "Third  Tray :\t{" << std::hex << third_tray << "}\t=\t[" << std::dec << *third_tray << "]." << std::endl;

		/* Destruction of assigned integer pointers. */
		std::cout << std::endl << "Deleting created dynamic objects..." << std::endl;

		delete third_tray;
		delete second_tray;
		delete first_tray;

		/* One-by-one generation of a dynamic object of type 'character' until the maximum number of buckets. */
		std::cout << std::endl << "Generating new elements infinitely with overloaded 'new' and 'delete' operators..." << std::endl;

		/* Test to detect if the memory segment allocation error exception is triggered. */
		try
			{
				std::cout << "Infinite loop of generating piles inside buckets..." << std::endl;
				std::cout << "Do you wish to continue the allocation operation? (y/n) : ";

				chr_response = capture_a_value<char>(&chr_response);

				/* A loop that assigns character by character to the 'Bucket' class until it is exhausted. */
				while ((chr_response == V_CHAR_LOWER_Y || chr_response == V_CHAR_UPPER_Y) && counter <= Bucket::number_of_buckets)
					{
						new char;	//Use the available memory of the 'Bucket' but do not save it.

						std::cout << std::endl << "Char Assignment #: [" << std::dec << counter++ + V_ONE << "] of: [" << Bucket::number_of_buckets << "]." << std::endl;
						std::cout << "Do you wish to continue the allocation operation? (y/n) : ";

						chr_response = capture_a_value<char>(&chr_response);
					}
			}
		catch (const std::exception& e)
			{
				std::cout << std::endl << "Exception ocurred: [" << e.what() << "]." << std::endl;
			}

		return V_ZERO;
	}
