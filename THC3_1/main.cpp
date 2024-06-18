#include "THC3_1.h"

int main () {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";

    vector<CauhoiTN> tmp_storage;

    while (1) {
        int a = 0;
        Menu();
        cout << "-Nhap vao qui uoc cua MENU: "; cin >> a;
        if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8) {
            do {
                cout << "-Qui uoc cua MENU khong chinh xac" << "\n";
                cout << "-Vui long nhap lai qui uoc cua MENU: "; cin >> a;
            } while (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8);
        }
        cin.ignore();
        if (a == 1) {
            tmp_storage.clear();
            cout << "-Tao mot de thi trac nghiem moi thanh cong" << "\n";
        } else if (a == 2) {
            CauhoiTN b;
            b.nhap();
            tmp_storage.push_back(b);
            cout << "-Them mot cau hoi moi tu ban phim vao de thi hien hanh thanh cong" << "\n";
        } else if (a == 3) {
            if (tmp_storage.size() != 0) {
                for (int i = 0; i < tmp_storage.size(); i++) {
                    cout << "Cau " << i+1 << ": ";
                    tmp_storage[i].xuat();
                }
            } else {
                cout << "-Hien dang khong co cau hoi trong danh sach de thi hien hanh" << "\n";
            }
        } else if (a == 4) {
            string f_name;
            cout << "-Nhap vao ten file (vi du LTHDT-CN15B.TTN): ";
            getline(cin, f_name);
            if (tmp_storage.size() != 0) {
                ofstream o(f_name);
                if (o.is_open()) {
                    for (int i = 0; i < tmp_storage.size(); i++) {
                        tmp_storage[i].ghifile(o);
                    }
                    cout << "-Luu danh sach cau hoi vao file " << f_name << " thanh cong" << "\n";
                    o.close();
                }
            } else {
                cout << "-Luu danh sach cau hoi vao file " << f_name << " that bai" << "\n";
                cout << "-Hien dang khong co cau hoi trong danh sach de thi hien hanh de luu" << "\n";
            }
        } else if (a == 5) {
            string f_name;
            cout << "-Nhap vao ten file (vi du LTHDT-CN15B.TTN): ";
            getline(cin, f_name);
            ifstream i(f_name);
            if (i.is_open()) {
                while (i.peek() != EOF) {
                    CauhoiTN b;
                    b.docfile(i);
                    tmp_storage.push_back(b);
                }
                cout << "-Doc noi dung file " << f_name << " vao bo nho thanh cong" << "\n";
                i.close();
            } else {
                cout << "-Doc noi dung file " << f_name << " vao bo nho that bai" << "\n";
                cout << "-Khong tim thay file " << f_name << "\n";
            }
        } else if (a == 6) {
            if (tmp_storage.size() != 0) {
                int cnt = 0;
                for (int i = 0; i < tmp_storage.size(); i++) {
                    int b;
                    cout << "Cau " << i+1 << ": ";
                    b = tmp_storage[i].kiemtra();
                    if (b == 1) {
                        cnt ++;
                    }
                }
                cout << "-So cau tra loi dung cua thi sinh: " << cnt << "\n";
            } else {
                cout << "-Hien dang khong co cau hoi trong danh sach de thi hien hanh de kiem tra" << "\n";
            }
        } else if (a == 7) {
            if (tmp_storage.size() > 1) {
                vector<CauhoiTN> same_storage;
                vector<int> cnt_storage;
                for (int i = 0; i < tmp_storage.size(); i++) {
                    if (!check_exist(same_storage, tmp_storage[i])) {
                        int cnt = 0;
                        for (int j = 0; j < tmp_storage.size(); j++) {
                            if (giongnhau(tmp_storage[i], tmp_storage[j])) {
                                cnt++;
                            }
                        }
                        if (cnt > 1) {
                            same_storage.push_back(tmp_storage[i]);
                            cnt_storage.push_back(cnt);
                        }
                    }
                }
                if (same_storage.size() != 0) {
                    for (int i = 0; i < same_storage.size(); i++) {
                        cout << "Cau " << i+1 << ": ";
                        same_storage[i].xuat();
                        cout << "-So cau hoi trong danh sach de thi hien hanh cua cau nay: " << cnt_storage[i] << "\n"; 
                    }
                } else {
                    cout << "-Khong co cau hoi bi trung trong danh sach de thi hien hanh" << "\n";
                }
            } else {
                cout << "-So luong cau hoi trong danh sach de thi hien hanh qua it (<2)" << "\n";
            }
        } else {
            break;
        }
    }
    return 0;
}