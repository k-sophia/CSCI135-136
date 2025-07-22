/**********
Assignment: Lab9

Write a program, 3d-space.cpp, that defines the function:
-   double length(Coord3D *p);
-   Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);

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

/*
    @p1, @p2:   the coordinates of two points (passed as pointers)
    @return:    the pointer of the point that is farther away from the origin
*/
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if(length(p1) > length(p2)) { //which greater distance
        return p1;
    }
    return p2;
}

int main() {
    //Test fartherFromOrigin
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?

    /* 
    //Test length
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
    */
}