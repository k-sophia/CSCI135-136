/**********
Define a structure Triangle:
- Contains three Point members

Write a function that computes the 'perimeter()' of
a Triangle.

Write a program that reads the coordinates of the 
points, calls your function, and displays the result.
**********/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double cord_x;
    double cord_y;
};

struct Triangle {
    Point x;
    Point y;
    Point z;
};

double distance(Point a, Point b) {
    return sqrt(pow((a.cord_x - b.cord_x), 2) + pow((a.cord_y - b.cord_y), 2));
}

double perimeter(Triangle a) {
    double one = distance(a.x, a.y);
    double two = distance(a.y, a.z);
    double three = distance(a.z, a.x);

    return one + two +three;
}

int main() {
    Point point1, point2, point3;
    cout << "Enter 1st point x-coordinate: ";
    cin >> point1.cord_x;
    cout << "Enter 1st point y-coordinate: ";
    cin >> point1.cord_y;
    cout << "\nEnter 2nd point x-coordinate: ";
    cin >> point2.cord_x;
    cout << "Enter 2nd point y-coordinate: ";
    cin >> point2.cord_y;
    cout << "\nEnter 3rd point x-coordinate: ";
    cin >> point3.cord_x;
    cout << "Enter 2rd point y-coordinate: ";
    cin >> point3.cord_y;

    Triangle triangle;
    triangle.x = point1;
    triangle.y = point2;
    triangle.z = point3;
    cout << "\nPerimater of Triangle: " << perimeter(triangle) << endl;
}
