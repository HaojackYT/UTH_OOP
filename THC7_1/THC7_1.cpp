#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Point {
    private:
        T x,y;
    public:
        Point(T x = 0, T y = 0) : x(x), y(y) {}
        void set_x(T);
        void set_y(T);
        void print();
        double distance(Point);
};

template<typename T>
void Point<T>::set_x(T x) {
    this->x = x;
}

template<typename T>
void Point<T>::set_y(T y) {
    this->y = y;
}

template<typename T>
void Point<T>::print() {
    cout << "(" << this->x << ", " << this->y << ")" << "\n";
}

template<typename T>
double Point<T>::distance(Point<T> a) {
    return sqrt((this->x - a.x)*(this->x - a.x) + (this->y - a.y)*(this->y - a.y));
}

template<typename T> 
void hoanvi(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
bool compareToOrigin(Point<T> a, Point<T> b) {
    Point<T> origin(0,0);
    return a.distance(origin) < b.distance(origin);
}

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";

    int ia = 1, ib = 2;
    float fa = 3.0f, fb = 4.0f;
    char ca = 'a', cb = 'b';
    
    cout << "Hai doi so kieu nguyen:" << "\n";
    cout << "ia = " << ia << " , ib = " << ib << "\n"; 
    hoanvi(ia, ib);
    cout << "Sau khi goi ham hoanvi(ia, ib):" << "\n";
    cout << "ia = " << ia << " , ib = " << ib << "\n";

    cout << "Hai doi so kieu thuc:" << "\n";
    cout << "fa = " << fixed << setprecision(1) << fa << " , fb = " << fb << "\n"; 
    hoanvi(fa, fb);
    cout << "Sau khi goi ham hoanvi(fa, fb):" << "\n";
    cout << "fa = " << fixed << setprecision(1) << fa << " , fb = " << fb << "\n";

    cout << "Hai doi so kieu ky tu:" << "\n";
    cout << "ca = " << ca << " , cb = " << cb << "\n"; 
    hoanvi(ca, cb);
    cout << "Sau khi goi ham hoanvi(ca, cb):" << "\n";
    cout << "ca = " << ca << " , cb = " << cb << "\n"; 

    vector<Point<int>> tmp_storage;

    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        Point<int> a;
        a.set_x(rand() % 100);
        a.set_y(rand() % 100);
        tmp_storage.push_back(a);
    }
    cout << "\nDanh sach Point ngau nhien:" << "\n";
    for (int i = 0; i < tmp_storage.size(); i++) {
        cout << i+1 << ") ";
        tmp_storage[i].print();
    }

    Point<int> origin(0, 0);
    sort(tmp_storage.begin(), tmp_storage.end(), compareToOrigin<int>);
    cout << "Danh sach Point sap xep theo thu tu tang dan khoang cach den goc toa do:" << "\n";
    for (int i = 0; i < tmp_storage.size(); i++) {
        cout << i+1 << ") ";
        tmp_storage[i].print();
        cout << "Khoang cach den goc toa do: " << tmp_storage[i].distance(origin) << "\n";
    }
}