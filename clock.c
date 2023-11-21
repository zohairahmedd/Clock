#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void tfh(int hour, int minute, int second);
void th(int hour, int minute, int second);

int main() {

    int hour, minute, second;
    char clockType;

    time_t s; // time_t is data type in C used for time representation from a certain point in time
    struct tm* curr_time; // struct tm holds the broken down calendar time in the C library. in this case, the pointer curr_time can be used to access a struct tm object
    s = time(NULL); // returns the time as the number of seconds passed since january 1, 1970 into variable s (53 years in seconds)
    curr_time = localtime(&s); // takes pointer to a time_t, s in this case, and returns a pointer to a struct tm, curr_time in this case, that holds the time information in a simple format
    hour = curr_time->tm_hour; // retrieves current hour from the system's time. in this case, it is used to access the tm_hour member of the struct tm that curr_time points to ->
    minute = curr_time->tm_min; // retrieves current minute from the system's time. in this case, it is used to access the tm_min member of the struct tm that curr_time points to ->
    second = curr_time->tm_sec; // retrieves current seconds from the system's time. in this case, it is used to access the tm_sec member of the struct tm that curr_time points to ->

    printf("A. 24 Hour Clock\nB. 12 Hour Clock\nInput either A or B: ");
    scanf("%c", &clockType);

    if (clockType == 'a' || clockType == 'A') { // if they want twenty four hour clock, function call to use that clock
        tfh(hour, minute, second);
    }

    if (clockType == 'b' || clockType == 'B') { // if they want twelve hour clock, function call to use that clock
        th(hour, minute, second);
    }

    return 0;
}

void tfh(int hour, int minute, int second) {
    while (1) { // this is an infinite loop so the time will infinitely update

        system("clear"); // this function clears the output so that the timer won't appear an infinite number of times. every second will replace the previous clocks output
        printf("%.02d : %.02d : %.02d", hour, minute, second);

        fflush(stdout); // immediately empty the buffer with any data that should be written. without this terminal will display nothing... 

        second++; // 1 second will be added to previous clock output

        if (second == 60) { // if second is 60, add 1 minute to previous output and redeclare second as 0
            minute++;
            second = 0;
        }

        if (minute == 60) { // if minute is 60, add 1 hour to previous output and redeclare minute as 0
            hour++;
            minute = 0;
        }

        if (hour == 24) { // if hours is 60, redeclare all times to 0 as a full day has passed
            hour = 0;
            minute = 0;
            second = 0;
        }

        sleep(1); // pauses the program for exactly 1 second, meaning each clock output will take 1 second to update, imitating a real digital clock

    }

}

void th(int hour, int minute, int second) {

    while (1) { // this is an infinite loop so the time will infinitely update

        system("clear"); // this function clears the output so that the timer won't appear an infinite number of times. every second will replace the previous clocks output

        if (hour > 12) { // if current time is beyond noon (12pm) then the if statement will allow PM to be displayed after the time
            int dummy;
            dummy = hour - 12;
            printf("%.02d : %.02d : %.02d PM", dummy, minute, second);
        }

        if (hour < 12) { // if current time is before noon (12pm) then the if statement will allow AM to be displayed after the time
            printf("%.02d : %.02d : %.02d AM", hour, minute, second);
        }

        fflush(stdout); // immediately empty the buffer with any data that should be written. without this terminal will display nothing... 

        second++; // 1 second will be added to previous clock output

        if (second == 60) { // if second is 60, add 1 minute to previous output and redeclare second as 0
            minute++;
            second = 0;
        }

        if (minute == 60) { // if minute is 60, add 1 hour to previous output and redeclare minute as 0
            hour++;
            minute = 0;
        }

        if (hour == 12) { // if hours is 60, redeclare all times to 0 as a full day has passed
            hour = 0;
            minute = 0;
            second = 0;
        }

        sleep(1); // pauses the program for exactly 1 second, meaning each clock output will take 1 second to update, imitating a real digital clock
    }

}
