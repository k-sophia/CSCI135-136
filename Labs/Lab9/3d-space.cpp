/**********
Assignment: Lab9

Write a program, 3d-space.cpp, that defines the function:
-   double length(Coord3D *p);
-   Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
-   void move(Coord3D *ppos, Coord3D *pvel, double dt);

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

/*
    Computes object’s new coordinates after the time interval dt
    Update the object’s position ppos with its new position coordinates
    @pps:       the position of an object
    @pvel:      the velocity of an object
    @dt:        time interval
*/
void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x = ppos->x + pvel->x * dt; //update the object’s position ppos

    ppos->y = ppos->y + pvel->y * dt;

    ppos->z = ppos->z + pvel->z * dt;
}

int main() {
    //Test move
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl; // prints: 2 -10 100.4

    /* 
    //Test fartherFromOrigin
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl;
    */

    /* 
    //Test length
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
    */
}