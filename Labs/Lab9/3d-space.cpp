/**********
Assignment: Lab9-A

Write a program, 3d-space.cpp, that defines the function:
-   double length(Coord3D *p);

Have a main function that tests your code.
**********/

#include <iostream>
#include <cmath>
using namespace std;

/*
    class type that represents coordinates in 3D
*/
class Coord3D {
    public: //coordinates
        double x;
        double y;
        double z;
};

/*
    Computes the length of the vector 
    @p:         coordinates of a point P passed as a pointer
    @return:    distance from the origin to the point
*/
double length(Coord3D *p) { 
    return sqrt(pow(p->x,2) + pow(p->y,2) + pow(p->z,2));
}

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}