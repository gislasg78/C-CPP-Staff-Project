#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

void viewConcurrentTime()
{
	std::time_t tt {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
	std::time_t tx = std::time(nullptr);

	std::tm my_tm_tt, my_tm_tx;

	#ifdef _WIN32
		localtime_s(&my_tm_tt, &tt);
		localtime_s(&my_tm_tx, &tx);
	#else
		localtime_r(&tt, &my_tm_tt);
		localtime_r(&tx, &my_tm_tx);
	#endif

	std::cout << std::endl << "Current date and time." << std::endl;
	std::cout << '\x5b' << std::put_time(&my_tm_tt, "%Y-%m-%d - %H:%M:%S") << '\x5d' << '\x2e' << std::endl;
	std::cout << '\x5b' << std::put_time(&my_tm_tt, "%A, %B %d, %Y - %H:%M:%S") << '\x5d' << '\x2e' << std::endl;
	std::cout << my_tm_tx.tm_hour << '\x3a' << my_tm_tx.tm_min << '\x3a' << my_tm_tx.tm_sec << '\x2e' << std::endl;
}

int main()
{
	std::cout << "Simultaneous time display." << std::endl;

	viewConcurrentTime();

	return EXIT_SUCCESS;
}
