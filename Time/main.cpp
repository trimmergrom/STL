#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>       /* time_t, time, ctime */

int main()
{
	time_t rawtime;

	time(&rawtime);
	std::cout << ctime(&rawtime) << std::endl;

	return 0;
}