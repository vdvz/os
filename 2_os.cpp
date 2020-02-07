#include <iostream>
#include <sys/types.h>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main()
{	
	int daylight;
	long long timezone ;
	const char* tzname[2];
	time_t t;
	struct tm* sp;
	t = time(nullptr);
	sp = localtime(&t);
	_putenv("TZ=PST");
	_tzset();
	printf("%d %d %d\n", sp->tm_hour, timezone, daylight);
	return 0;
}
