#include <iostream>
#include <sys/types.h>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

int main()
{
        int daylight;
        long long timezone ;
        char* tzname[2];
        time_t t;
        struct tm* sp;
        t = time(0);
        printf("%s \n",ctime(&t));
        sp = localtime(&t);
        char* tz = "TZ=America/Los_Angeles";
        putenv(tz);
        tzset();
        t = time(0);
        printf("%s \n",ctime(&t));
        printf("%d %d %d\n", sp->tm_hour, daylight, timezone);
        char* s = getenv("TZ");
        printf("ENV: %s\n",s);
        return 0;
}

