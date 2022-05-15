/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 F
*/

class Coord3D {
    public:
        double x;
        double y;
        double z;
};

class Particle{
    public:
        double x;
        double y;
        double z;
        double vx;
        double vy;
        double vz;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
    Particle *p = new Particle();
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    return p;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p){
    Coord3D temp;
    temp.x = p->x;
    temp.y = p->y;
    temp.z = p->z;
    return temp;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt){
    p->x = p->x + (p->vx * dt);
    p->y = p->y + (p->vy * dt);
    p->z = p->z + (p->vz * dt);
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
    delete p;
}