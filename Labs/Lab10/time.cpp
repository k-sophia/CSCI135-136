/**********
Assignment: Lab10

Create a program named time.cpp. 

Given datatypes:
-   class Time
-   enum Genre
-   class Movie
-   class Timeslot

Given functions:
-   void printTime(Time time);
-   void printMovie(Movie m);

Define these functions:
-   int minutesSinceMidnight(Time time);
-   int minutesUntil(Time earlier, Time later);
-   Time addMinutes(Time time0, int min);
-   printTimeSlot(Timeslot ts);
-   TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
-   bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 

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
    prints a Time object in "H:M" format (24-hour clock) 
*/
void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

/*
    @return:    the number of minutes from 0:00AM (midnight) until time
*/
int minutesSinceMidnight(Time time) {
    return time.m + 60*time.h;
}

/*
    @return:    the difference in minutes between earlier and later
                if earlier is after later, the result will be negative
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

/*
    genre enumeration for categorizing movies.
*/
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

/*
    class for representing a movie
*/
class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

/*
    class for representing a scheduled showing of a movie with a start time.
*/
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

/*
    prints information about a Movie
    format: "<title> <GENRE> (<duration> min)"
*/
void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

/*
    prints information about a TimeSlot
    format: "<title> <GENRE> (<duration> min) [starts at H:M ,ends by H:M]"
*/
void printTimeSlot(TimeSlot ts) {
    printMovie(ts.movie);
    cout << " [starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";

    ts.startTime = addMinutes(ts.startTime, ts.movie.duration);
    printTime(ts.startTime);
    cout << "]" << endl;
}

/*
    @return:    a TimeSlot for the movie nextMovie
                scheduled immediately after the time slot ts
*/
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot next;
    next.movie = nextMovie;
    next.startTime =  addMinutes(ts.startTime, ts.movie.duration);
    return next;
}

/*
    @return:    true if the two time slots overlap
                false otherwise
*/
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    int time_between;
    bool first_slot_earliest =  minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime);

    if(first_slot_earliest) {
        Time end = addMinutes(ts1.startTime, ts1.movie.duration);
        time_between = minutesUntil(end, ts2.startTime);
    }
    else {
        Time end = addMinutes(ts2.startTime, ts2.movie.duration);
        time_between = minutesUntil(end, ts1.startTime);
    }

    if (time_between < 0) {
        return true;
    }
    
    return false;
}

int main() {
    //test timeOverlap
    Movie movie1 = {"Coraline", THRILLER, 100};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Megamind", COMEDY, 96};

    TimeSlot first = {movie1, {9, 15}};  
    TimeSlot second = {movie2, {10, 30}};
    TimeSlot third = {movie3, {16, 45}};

    cout << "Does movie 1 and 2 overlap? "
         << (timeOverlap(first, second) ? "Yes\n" : "No\n"); 
    cout << "Does movie 2 and 3 overlap? "
         << (timeOverlap(second, third) ? "Yes\n" : "No\n"); 

    /* 
    //test scheduleAfter
    Movie movie1 = {"Coraline", THRILLER, 100};
    Movie movie2 = {"Megamind", COMEDY, 96};

    TimeSlot first = {movie1, {9, 15}};  
    TimeSlot second = scheduleAfter(first, movie2);

    printTimeSlot(first);
    printTimeSlot(second);
    */

    /* 
    //test printTimeSlot
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 

    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    */

    /* 
    //test addMinutes
    Time a;
    int minutes;

    cout << "Enter time: ";
    cin >> a.h >> a.m;
    cout << "Minutes to add: ";
    cin >> minutes;

    a = addMinutes(a, minutes);
    cout << "\nThe time is now ";
    printTime(a);
    cout << endl;
    */

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

