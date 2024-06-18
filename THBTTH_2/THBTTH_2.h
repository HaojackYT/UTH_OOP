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

class Motorcycle : public Vehicle {};

class Car : public Vehicle {};

class Truck : public Vehicle {};

template <typename T>
void trafficSimulation(vector<pair<int, T>> &vt, int &createdTNumber, int N_MAX, float L, float dt) {
    for (int i = 0; i < vt.size(); i++) {
        vt[i].second.capNhatViTri(dt);
        vt[i].second.dieuChinhTocDo();
    }
    vector<pair<int, T>> tmp_vt;
    for (int i = 0; i < vt.size(); i++) {
        if (vt[i].second.getX() < L) {
            tmp_vt.push_back(vt[i]);
        }
    }
    vt.clear();
    for (int i = 0; i < tmp_vt.size(); i++) {
        vt.push_back(tmp_vt[i]);
    }
    if (vt.size() < N_MAX) {
        T a;
        vt.push_back({createdTNumber, a});
        createdTNumber++;
    }
}