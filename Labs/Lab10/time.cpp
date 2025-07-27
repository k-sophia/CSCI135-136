/**********
Assignment: Lab10-A

Create a program, time.cpp, that define these functions:
-   int minutesSinceMidnight(Time time);
-   int minutesUntil(Time earlier, Time later);

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

int main() {
    Time a, b;

    cout << "Enter first time:  "; //10 30
    cin >> a.h;
    cin >> a.m;
    
    cout << "Enter second time: "; //13 40
    cin >> b.h;
    cin >> b.m;
    
    cout << endl << "These moments of time are " << minutesSinceMidnight(a) << " and "
         << minutesSinceMidnight(b) << " minutes after midnight.\n"; 
    cout << "The interval between them is " << minutesUntil(a, b) << " minutes.\n";
}

