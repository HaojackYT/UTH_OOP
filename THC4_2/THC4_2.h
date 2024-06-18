#include <bits/stdc++.h>

using namespace std;

class Point {
    private:
        float x, y;
    public:
        Point(float, float);
        void print();
        friend bool operator < (Point, Point);
};

