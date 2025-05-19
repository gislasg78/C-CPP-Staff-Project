#include <cstddef>
#include <iostream>
#include <new>

#define	V_TEN	10
#define	V_ZERO	0
#define	V_4096	4096

struct Bucket
	{
		const static size_t size_bucket{ V_4096 };
		static const size_t number_buckets{ V_TEN };

		std::byte matrix_buckets[number_buckets][size_bucket]{};
		bool bucket_used[number_buckets]{};

		void *allocate_memory(size_t bytes)
			{
				if (bytes > size_bucket)
					throw std::bad_alloc();

				for (size_t idx{}; idx < number_buckets; idx++)
					{
						if (!bucket_used[idx])
							{
								bucket_used[idx] = true;
								return matrix_buckets[idx];
							}
					}

				throw std::bad_alloc();
			}

		void deallocate_memory(void *ptr)
			{
				for (size_t idx{}; idx < number_buckets; idx++)
					{
						if (matrix_buckets[idx] == ptr)
							{
								bucket_used[idx] = false;
								return;
							}
					}
			}
	};


Bucket bucket;

void* operator new (size_t n_bytes)
	{
		return bucket.allocate_memory(n_bytes);
	}

void operator delete (void* ptr)
	{
		return bucket.deallocate_memory(ptr);
	}


int main()
	{
		unsigned int first_value = V_ZERO, second_value = V_ZERO;

		std::cout << "Overloading of the 'new' and 'delete' operators." << std::endl;
		std::cout << "First  value : ";
		std::cin >> first_value;
		std::cout << "Second value : ";
		std::cin >> second_value;

		std::cout << std::endl << "Bucket." << std::endl;
		std::cout << "+ Size of data:\t\t[" << bucket.size_bucket << "]\t:\t[" << Bucket::size_bucket << "]." << std::endl;
		std::cout << "+ Number of buckets:\t[" << bucket.number_buckets << "]\t:\t[" << Bucket::number_buckets << "]." << std::endl << std::endl;

		std::cout << "Generating new dynamic objects..." << std::endl;

		auto first_tray = new unsigned int {first_value};
		auto second_tray = new unsigned int {second_value};

		std::cout << "First  Tray :\t[" << first_tray << "]\t:\t[" << std::hex << *first_tray << "]." << std::endl;
		std::cout << "Second Tray :\t[" << second_tray << "]\t:\t[" << std::hex << *second_tray << "]." << std::endl;

		std::cout << "Deleting created dynamic objects..." << std::endl;

		delete second_tray;
		delete first_tray;

		std::cout << std::endl << "Generating new elements infinitely with overloaded 'new' and 'delete' operators..." << std::endl;

		try
			{
				while (true)
					{
						new char;
						std::cout << "Char Assignment..." << std::endl;
					}
			}
		catch (const std::exception& e)
			{
				std::cout << "Exception ocurred: [" << e.what() << "]." << std::endl;
			}

		return V_ZERO;
	}
