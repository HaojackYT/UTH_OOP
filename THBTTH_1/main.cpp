#include "THBTTH_1.h"

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";

    vector<pair<int, Vehicle>> VehicleList;

    float L, dt;
    int n, N_MAX, createdVehicleNumber = 0, timestepCount = 0;
    cout << "Nhap vao chieu dai duong (L): "; cin >> L;
    cout << "Nhap vao khoang cach thoi gian giua cac timestep (dt): "; cin >> dt;
    cout << "Nhap vao so timesteps (n): "; cin >> n;
    cout << "Nhap vao so luong xe toi da tai mot thoi diem (N_MAX): "; cin >> N_MAX;
    ofstream o("mophong.txt");
    if (o.is_open()) {
        while(n--) {
            for (int i = 0; i < VehicleList.size(); i++) {
                VehicleList[i].second.capNhatViTri(dt);
                VehicleList[i].second.dieuChinhTocDo();
            }
            vector<pair<int, Vehicle>> tmp_storage;
            for (int i = 0; i < VehicleList.size(); i++) {
                if (VehicleList[i].second.getX() < L) {
                    tmp_storage.push_back(VehicleList[i]);
                }
            }
            VehicleList.clear();
            for (int i = 0; i < tmp_storage.size(); i++) {
                VehicleList.push_back(tmp_storage[i]);
            }
            if (VehicleList.size() < N_MAX) {
                Vehicle a;
                VehicleList.push_back({createdVehicleNumber, a});
                createdVehicleNumber++;
            }
            timestepCount++;
            o << "-Timestep: " << timestepCount << "\n";
            for (int i = 0; i < VehicleList.size(); i++) {
                o << "+So xe: " << VehicleList[i].first << " - Vi tri: " << VehicleList[i].second.getX() << " - Toc do hien tai: " << VehicleList[i].second.getV() << "\n";
            }
        }
        cout << "Luu danh sach timesteps vao file mophong.txt thanh cong" << "\n";
    }
}