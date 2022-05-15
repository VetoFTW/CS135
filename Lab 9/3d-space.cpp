/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 A B C E
*/

#include <iostream>
#include <cmath>

class Coord3D {
    public:
        double x;
        double y;
        double z;
};

double length(Coord3D *p){
    return sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    return length(p1) < length(p2) ? p2 : p1;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}

Coord3D* createCoord3D(double x, double y, double z){
        Coord3D *myCoord = new Coord3D;
        Coord3D coord = {x, y, z};
        *myCoord = coord;
    return myCoord;
}

void deleteCoord3D(Coord3D *p){
    delete p;
}
