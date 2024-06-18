#include "THBTTH_2.h"

float Vehicle::getX() {
    return this->x;
}

float Vehicle::getV() {
    return this->v;
}

void Vehicle::capNhatViTri(float dt) {
    this->x += this->v * dt;
}

void Vehicle::dieuChinhTocDo() {
    this->v += static_cast<double>(rand()) / RAND_MAX * 2 - 1;
}