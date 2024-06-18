#include "THC6_2.h"

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";

    vector<SEmployee> se_list;
    vector<CEmployee> ce_list;
    vector<SCEmployee> sce_list;

    while (1) {
        int a;
        Menu();
        cout << "-Nhap vao qui uoc cua Menu: "; cin >> a;
        if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7) {
            do {
                cout << "-Qui uoc cua Menu khong chinh xac" << "\n";
                cout << "-Vui long nhap lai qui uoc cua Menu: "; cin >> a;
            } while (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7);
        }
        if (a == 1) {
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                SEmployee b;
                se_list.push_back(b);
            }
            cout << "-Danh sach SEmployee ngau nhien: " << "\n";
            for (int i = 0; i < 10; i++) {
                cout << i+1 << ") ";
                se_list[i].print();
                cout << "\n";
            }
        } else if (a == 2) {
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                CEmployee b;
                ce_list.push_back(b);
            }
            cout << "-Danh sach CEmployee ngau nhien: " << "\n";
            for (int i = 0; i < 10; i++) {
                cout << i+1 << ") ";
                ce_list[i].print();
                cout << "\n";
            }
        } else if (a == 3) {
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                SCEmployee b;
                sce_list.push_back(b);
            }
            cout << "-Danh sach SCEmployee ngau nhien: " << "\n";
            for (int i = 0; i < 10; i++) {
                cout << i+1 << ") ";
                ce_list[i].print();
                cout << "\n";
            }
        } else if (a == 4) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (se_list[i].earnings() > se_list[j].earnings()) {
                        SEmployee tmp = se_list[i];
                        se_list[i] = se_list[j];
                        se_list[j] = tmp;
                    }
                }
            }
            cout << "-Danh sach SEmployee sap xep theo thu tu giam dan cua thu nhap: " << "\n";
            for (int i = 0; i < 10; i++) {
                cout << i+1 << ") ";
                se_list[i].print();
                cout << "\nearnings: " << se_list[i].earnings() << "\n";
            }
        } else if (a == 5) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (ce_list[i].earnings() > ce_list[j].earnings()) {
                        CEmployee tmp = ce_list[i];
                        ce_list[i] = ce_list[j];
                        ce_list[j] = tmp;
                    }
                }
            }
            cout << "-Danh sach CEmployee sap xep theo thu tu giam dan cua thu nhap: " << "\n";
            for (int i = 0; i < 10; i++) {
                cout << i+1 << ") ";
                ce_list[i].print();
                cout << "\nearnings: " << ce_list[i].earnings() << "\n";
            }
        } else if (a == 6) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (sce_list[i].earnings() > sce_list[j].earnings()) {
                        SCEmployee tmp = sce_list[i];
                        sce_list[i] = sce_list[j];
                        sce_list[j] = tmp;
                    }
                }
            }
            cout << "-Danh sach SCEmployee sap xep theo thu tu giam dan cua thu nhap: " << "\n";
            for (int i = 0; i < 10; i++) {
                cout << i+1 << ") ";
                sce_list[i].print();
                cout << "\nearnings: " << sce_list[i].earnings() << "\n";
            }
        } else {
            break;
        }
    }
}