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

		static void *allocate_memory(Bucket &bucket, size_t bytes)
			{
				if (bytes > size_bucket)
					throw std::bad_alloc();

				for (size_t idx{}; idx < number_buckets; idx++)
					{
						if (!bucket.bucket_used[idx])
							{
								bucket.bucket_used[idx] = true;
								return bucket.matrix_buckets[idx];
							}
					}

				throw std::bad_alloc();
			}

		void static deallocate_memory(Bucket& bucket, void *ptr)
			{
				for (size_t idx{}; idx < number_buckets; idx++)
					{
						if (bucket.matrix_buckets[idx] == ptr)
							{
								bucket.bucket_used[idx] = false;
								return;
							}
					}
			}
	};


Bucket bucket;

void* operator new (size_t n_bytes)
	{
		return Bucket::allocate_memory(bucket, n_bytes);
	}

void operator delete (void* ptr)
	{
		return Bucket::deallocate_memory(bucket, ptr);
	}


int main()
	{
		int64_t first_value = V_ZERO, second_value = V_ZERO, third_value = V_ZERO;

		std::cout << "Overloading of the 'new' and 'delete' operators." << std::endl;
		std::cout << "First  value : ";
		std::cin >> first_value;
		std::cout << "Second value : ";
		std::cin >> second_value;
		std::cout << "Third value  : ";
		std::cin >> third_value;

		std::cout << std::endl << "Bucket." << std::endl;
		std::cout << "+ Size of data:\t\t[" << Bucket::size_bucket << "]." << std::endl;
		std::cout << "+ Number of buckets:\t[" << Bucket::number_buckets << "]." << std::endl << std::endl;

		std::cout << "Generating new dynamic objects..." << std::endl;

		auto first_tray = new int64_t {first_value};
		auto second_tray = new int64_t {second_value};
		auto third_tray = new int64_t {third_value};

		std::cout << "First  Tray :\t[" << first_tray << "]\t:\t[" << std::hex << *first_tray << "]." << std::endl;
		std::cout << "Second Tray :\t[" << second_tray << "]\t:\t[" << std::hex << *second_tray << "]." << std::endl;
		std::cout << "Third  Tray :\t[" << third_tray << "]\t:\t[" << std::hex << *third_tray << "]." << std::endl;

		std::cout << "Deleting created dynamic objects..." << std::endl;

		delete third_tray;
		delete second_tray;
		delete first_tray;

		std::cout << std::endl << "Generating new elements infinitely with overloaded 'new' and 'delete' operators..." << std::endl;

		try
			{
				std::cout << "Infinite loop of generating piles inside buckets..." << std::endl;
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
