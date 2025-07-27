/**********
Assignment: Lab10

Create a program, time.cpp, that define these functions:
-   int minutesSinceMidnight(Time time);
-   int minutesUntil(Time earlier, Time later);
-   Time addMinutes(Time time0, int min);

Have a main function that tests your code.
**********/

#include <iostream>
using namespace std;

/*
    class for representing time in the 24-hour format
*/
class Time { 
    public:
        int h; // Hours (0 to 23)
        int m; // Minutes (0 to 59)
};

/*
    @return:    the number of minutes from 0:00AM (midnight) until time
*/
int minutesSinceMidnight(Time time) {
    return time.m + 60*time.h;
}

/*
    @return:    The difference in minutes between earlier and later
                If earlier is after later, the result will be negative
*/
int minutesUntil(Time earlier, Time later) {
    int minutes = later.m - earlier.m;
    minutes += 60*later.h - 60*earlier.h;

    return minutes;
}

/*
    adds a number of minutes to a given time
    assume the result remains within the same day (≤ 23:59)
    @return:    time object that is min minutes after time0
*/
Time addMinutes(Time time0, int min) {
    int hour = 0;
    int mins = time0.m + min;
    
    if(mins >= 60) { //if total minutes exceed one hour
        hour = mins/60; //get how many full hour
        mins -= 60*hour; //subtract hours from minutes
    }

    time0.h += hour;
    time0.m = mins;
    return time0;
}

int main() {
    //test addMinutes
    Time a;
    int minutes;

    cout << "Enter time: ";
    cin >> a.h >> a.m;
    cout << "Minutes to add: ";
    cin >> minutes;

    a = addMinutes(a, minutes);
    cout << "\nThe time is now " << a.h << ":" << a.m << ".\n";

    /* 
    // test minutesSinceMidnight and minutesUntil
    Time a, b;
    cout << "Enter first time:  "; //10 30
    cin >> a.h >> a.m;
    cout << "Enter second time: "; //13 40
    cin >> b.h >> b.m;
    
    cout << endl << "These moments of time are " << minutesSinceMidnight(a) << " and "
         << minutesSinceMidnight(b) << " minutes after midnight.\n"; 
    cout << "The interval between them is " << minutesUntil(a, b) << " minutes.\n";
    */
}

