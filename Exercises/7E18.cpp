/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.18
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point A;
    Point B;
    Point C;
};

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double perimeter(Triangle z) {
    return distance(z.A, z.B) + distance(z.A, z.C) + distance(z.B, z.C);
}
