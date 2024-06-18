#include <bits/stdc++.h>

using namespace std;

class Vehicle {
    private:
        float x, v;
    public:
        Vehicle(float x = 0, float v = 1) : x(x), v(v) {}
        float getX();
        float getV();
        void capNhatViTri(float);
        void dieuChinhTocDo();
};