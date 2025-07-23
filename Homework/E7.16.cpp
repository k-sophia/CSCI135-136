/**********
Define a structure Point:
- A point had an x-coordinate and a y-corrdinate

Write a double function named distance(Point a, Point b)
that computes the distance from a to b.

Write a program that reads the coordinates of the
points, calls your function, and displays the results.
**********/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main() {
    Point point1, point2;
    cout << "Enter 1st point x-coordinate: ";
    cin >> point1.x;
    cout << "Enter 1st point y-coordinate: ";
    cin >> point1.y;
    cout << "\nEnter 2nd point x-coordinate: ";
    cin >> point2.x;
    cout << "Enter 2nd point y-coordinate: ";
    cin >> point2.y;

    cout << "\nDistance between points: " << distance(point1, point2) << endl;
}