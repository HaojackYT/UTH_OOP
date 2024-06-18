#include "THBTTH_2.h"

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";

    vector<pair<int, Motorcycle>> MotorcycleList;
    vector<pair<int, Car>> CarList;
    vector<pair<int, Truck>> TruckList;

    float L, dt;
    int n, N_MAX1, N_MAX2, N_MAX3, timestepCount = 0;
    int createdMotorcycleNumber = 0;
    int createdCarNumber = 0;
    int createdTruckNumber = 0;
    cout << "Nhap vao chieu dai duong (L): "; cin >> L;
    cout << "Nhap vao khoang cach thoi gian giua cac timestep (dt): "; cin >> dt;
    cout << "Nhap vao so timesteps (n): "; cin >> n;
    cout << "Nhap vao so luong xe may toi da tai mot thoi diem (N_MAX1): "; cin >> N_MAX1;
    cout << "Nhap vao so luong xe con toi da tai mot thoi diem (N_MAX2): "; cin >> N_MAX2;
    cout << "Nhap vao so luong xe tai toi da tai mot thoi diem (N_MAX3): "; cin >> N_MAX3;
    ofstream o("mophong.txt");
    srand(time(NULL));
    if (o.is_open()) {
        while(n--) {
            trafficSimulation(MotorcycleList, createdMotorcycleNumber, N_MAX1, L, dt);
            trafficSimulation(CarList, createdCarNumber, N_MAX2, L, dt);
            trafficSimulation(TruckList, createdTruckNumber, N_MAX3, L, dt);
            timestepCount++;
            o << "-Timestep: " << timestepCount << "\n";
            for (int i = 0; i < MotorcycleList.size(); i++) {
                o << "+So xe may: " << MotorcycleList[i].first << " - Vi tri: " << MotorcycleList[i].second.getX() << " - Toc do hien tai: " << MotorcycleList[i].second.getV() << "\n";
            }
            for (int i = 0; i < CarList.size(); i++) {
                o << "+So xe con: " << CarList[i].first << " - Vi tri: " << CarList[i].second.getX() << " - Toc do hien tai: " << CarList[i].second.getV() << "\n";
            }
            for (int i = 0; i < TruckList.size(); i++) {
                o << "+So xe tai: " << TruckList[i].first << " - Vi tri: " << TruckList[i].second.getX() << " - Toc do hien tai: " << TruckList[i].second.getV() << "\n";
            }
        }
        cout << "Luu danh sach timesteps vao file mophong.txt thanh cong" << "\n";
    }
}