/**********
Assignment: Lab9-F

Write a new program, particle.cpp, and declare a
new class Particle, which
-  stores position and velocity of the particle

Provide the following programming interface:
-   Particle* createParticle(double x, double y, double z, double vx, double vy, double vz);
-   void setVelocity(Particle *p, double vx, double vy, double vz);
-   Coord3D getPosition(Particle *p);
-   void move(Particle *p, double dt);
-   void deleteParticle(Particle *p);

May copy anything from 3d-space.cpp
**********/

#include <iostream>
#include <cmath>
using namespace std;

/*
    class type that represents coordinates in 3D
*/
class Coord3D {
    public://coordinates
        double x;
        double y;
        double z;
};

/*
    class type that stores position and velocity of the particle
*/
class Particle {
    public:
        //position
        double x;
        double y;
        double z;
        //velocity
        double vx;
        double vy;
        double vz;
};

/*
    dynamically allocate memory for a particle and initialize it
*/
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
    Particle *p = new Particle;
    *p = {x, y, z, vx, vy, vz};
    return p;
}

/*
    set its velocity to (vx, vy, vz)
*/
void setVelocity(Particle *p, double vx, double vy, double vz) {
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

/*
    get its current position
*/
Coord3D getPosition(Particle *p) {
    double x = p->x;
    double y = p->y;
    double z = p->z;

    Coord3D *q = new Coord3D;
    *q = {x, y, z}; //only positions
    return *q;
}

/*
    update particle's position after elapsed time dt
*/
void move(Particle *p, double dt) { //the object’s new position after the elapsed time dt
    p->x = p->x + p->vx * dt;
    p->y = p->y + p->vy * dt;
    p->z = p->z + p->vz * dt;
}

/*
    delete all memory allocated for the particle passed by pointer
*/
void deleteParticle(Particle *p) {
    delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}