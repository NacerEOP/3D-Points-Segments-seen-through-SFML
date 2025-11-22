#include "point.h"
#include <iostream>


CLpoint::CLpoint() {
    this->x = 0;
    this->y = 0;
}

CLpoint::CLpoint(float x, float y) {
    this->x = x;
    this->y = y;
}

void CLpoint::afficherCoordo() {
    std::cout << "Coordo 2D: x = " << this->x << " , y = " << this->y << std::endl;
}

float CLpoint::getX() {
    return this->x;
}

float CLpoint::getY() {
    return this->y;
}



CLpoint3D::CLpoint3D() : CLpoint(0.0f, 0.0f), z(0.0f)
{
}

CLpoint3D::CLpoint3D(float x, float y, float z) : CLpoint(x, y), z(z)
{
}

void CLpoint3D::afficherCoordo() {
    std::cout << "Coordo 3D: x = " << x << " , y = " << y << " , z = " << this->z << std::endl;
}

float CLpoint3D::getZ() {
    return this->z;
}
