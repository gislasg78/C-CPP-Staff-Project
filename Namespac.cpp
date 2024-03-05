#include <iostream>

#define	V_ZERO	0

#define	V_60	60
#define	V_100	100
#define	V_3600	3600
#define	V_10000	10000


namespace dateSpace
	{
		void int_toDate(int int_date_YYYYMMDD, int *int_year, int *int_month, int *int_day)
			{
				*int_year = int_date_YYYYMMDD / V_10000;
				*int_month = (int_date_YYYYMMDD - *int_year * V_10000) / V_100;
				*int_day = int_date_YYYYMMDD - *int_year * V_10000 - *int_month * V_100;
			}
	}

namespace timeSpace
	{
		void int_toTime(int int_time_seconds, int &int_hour, int &int_minute, int &int_second)
			{
				int_hour = int_time_seconds / V_3600;
				int_time_seconds %= V_3600;

				int_minute = int_time_seconds / V_60;
				int_second = int_time_seconds % V_60;
			}
	}


int main()
	{
		int int_date_YYYYMMDD = V_ZERO;
		int int_year = V_ZERO;
		int int_month = V_ZERO;
		int int_day = V_ZERO;

		int int_time_seconds = V_ZERO;
		int int_hour = V_ZERO;
		int int_minute = V_ZERO;
		int int_second = V_ZERO;

		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+    Date and time space names.     +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Date Format (YYYYMMDD)   : ";
		std::cin >> int_date_YYYYMMDD;
		std::cout << "Time Format (In Seconds) : ";
		std::cin >> int_time_seconds;

		dateSpace::int_toDate(int_date_YYYYMMDD, &int_year, &int_month, &int_day);

		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+Information extracted from the date+" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Year\t:\t[" << int_year << "]." << std::endl;
		std::cout << "Month\t:\t[" << int_month << "]." << std::endl;
		std::cout << "Day\t:\t[" << int_day << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

		timeSpace::int_toTime(int_time_seconds, int_hour, int_minute, int_second);

		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+Information extracted from the time+" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Hour\t:\t[" << int_hour << "]." << std::endl;
		std::cout << "Minute\t:\t[" << int_minute << "]." << std::endl;
		std::cout << "Second\t:\t[" << int_second << "]." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

		return V_ZERO;
	}
