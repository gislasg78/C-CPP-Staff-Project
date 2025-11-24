#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#define V_ZERO  0

int main()
{
    std::cout << "Obtaining the current date and time of the operating system." << std::endl;
    
    // Get the current time from the system clock.
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for use with C-style functions.
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);

    // Convert time_t to tm (local time).
    std::tm local_tm = *std::localtime(&time_now);

    // Format the time as a string.
    std::cout << "Current time: "  << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << std::endl;
    std::cout << std::put_time(&local_tm, "[%A, %B %d, %Y] - [%H:%M:%S].") << std::endl;

    return V_ZERO;
}