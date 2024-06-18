#include "THC4_2.h"

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

void Point::print() {
    cout << "(" << this->x << "," << this->y << ")" << "\n";
}

bool operator < (Point a, Point b) {
    float distance1 = sqrt(a.x * a.x + a.y * a.y);
    float distance2 = sqrt(b.x * b.x + b.y * b.y);
    return distance1 < distance2;
} 