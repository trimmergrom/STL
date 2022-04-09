#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>       /* time_t, time, ctime */

int main()
{
	std::string check_time;
	time_t rawtime;
	time(&rawtime);
	check_time = ctime(&rawtime);
	std::cout << check_time << std::endl;
	//std::cout << ctime(&rawtime) << typeid(ctime(&rawtime)) <<std::endl;

	return 0;
}