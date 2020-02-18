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
        /*
        daylight to a nonzero value if daylight savings time rules apply during some part of the year
        */
        int daylight;
        /*
        The difference between Coordinated Universal Time (UTC) and local standard time in seconds.
        */
        long long timezone ;
        /*
        tzname contains two strings, which are the standard names of the pair of time zones 
        (standard and Daylight Saving) that the user has selected. 
        tzname[0] is the name of the standard time zone (for example, "EST"), 
        and tzname[1] is the name for the time zone when Daylight Saving Time is in use (for example, "EDT"). 
        These correspond to the std and dst strings (respectively) from the TZ environment variable. 
        If Daylight Saving Time is never used, tzname[1] is the empty string. 
        */
        char* tzname[2];
        time_t t;
        t = time(0);
        printf("%s \n",ctime(&t));
        char* tz = "TZ=America/Los_Angeles";
        putenv(tz);
        //tzset();
        t = time(0);
        /*
        The localtime() function converts the calendar time timep to broken-down time representation, 
        expressed relative to the user's specified timezone.        
        equivalent to asctime(localtime(&t))
        */
       
        printf("%s \n", ctime(&t));
        char* s = getenv("TZ");
        printf("ENV: %s\n",s);
        return 0;
}

