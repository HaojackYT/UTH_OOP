#include "THC3_2.h"

int main () {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";

    vector<SinhVien> tmp_list;

    while (1) {
        int a = 0;
        cout << "===============================MENU=================================" << "\n";
        cout << "+Nhap danh sach sinh vien tu ban phim = '1'" << "\n";
        cout << "+Nhap danh sach sinh vien tu file = '2'" << "\n";
        cout << "+Xuat danh sach sinh vien ra man hinh = '3'" << "\n";
        cout << "+Xuat danh sach sinh vien ra file = '4'" << "\n";
        cout << "+In danh sach sinh vien du dieu kien du thi = '5'" << "\n";
        cout << "+In danh sach cac sinh vien co ho la 'Nguyen' = '6'" << "\n";
        cout << "+In danh sach cac sinh vien co cung ten voi mot sinh vien khac = '7'" << "\n";
        cout << "+Thoat chuong trinh = '8'" << "\n";
        cout << "====================================================================" << "\n";
        cout << "-Nhap vao qui uoc cua MENU: "; cin >> a;
        if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8) {
            do {
                cout << "-Qui uoc cua MENU khong chinh xac" << "\n";
                cout << "-Vui long nhap lai qui uoc cua MENU: "; cin >> a;
            } while (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8);
        }
        cin.ignore();
        if (a == 1) {
            int b = 0;
            cout << "-Nhap vao so luong sinh vien mong muon them vao danh sach hien hanh (>0): "; cin >> b;
            if (b <= 0) {
                do {
                    cout << "-Qui uoc so luong sinh vien khong chinh xac" << "\n";
                    cout << "-Vui long nhap lai so luong sinh vien mong muon them vao danh sach hien hanh (>0): "; cin >> b;
                } while (b <= 0);
            }
            cin.ignore();
            for (int i = 0; i < b; i++) {
                SinhVien b;
                b.nhap();
                tmp_list.push_back(b);
            }
            cout << "-Nhap danh sach sinh vien tu ban phim thanh cong" << "\n";
        } else if (a == 2) {
            string f_name;
            cout << "Nhap vao ten file (vi du LTHDT-CN15B.TTN): ";
            getline(cin, f_name);
            ifstream i(f_name);
            if (i.is_open()) {
                while (i.peek() != EOF) {
                    SinhVien b;
                    b.docfile(i);
                    tmp_list.push_back(b);
                }
                cout << "-Nhap danh sach sinh vien tu file " << f_name << " thanh cong" << "\n";
                i.close();
            } else {
                cout << "-Nhap danh sach sinh vien tu file " << f_name << " that bai" << "\n";
                cout << "-Khong tim thay file " << f_name << "\n";
            }
        } else if (a == 3) {
            if (tmp_list.size() != 0) {
                for (int i = 0; i < tmp_list.size(); i++) {
                    tmp_list[i].xuat();
                }
                cout << "-Xuat danh sach sinh vien ra man hinh thanh cong" << "\n";
            } else {
                cout << "-Hien dang khong co sinh vien trong danh sach hien hanh" << "\n";
            }
        } else if (a == 4) {
            string f_name;
            cout << "-Nhap vao ten file (vi du LTHDT-CN15B.TTN): ";
            getline(cin, f_name);
            ofstream o(f_name);
            if (o.is_open()) {
                for (int i = 0; i < tmp_list.size(); i++) {
                    tmp_list[i].ghifile(o);
                }
                cout << "-Xuat danh sach sinh vien ra file " << f_name << " thanh cong" << "\n";
                o.close();
            }
        } else if (a == 5) {
            vector<SinhVien> exam_list;
            for (int i = 0; i < tmp_list.size(); i++) {
                if (tmp_list[i].get_DiemQT() >= 3.0) {
                    exam_list.push_back(tmp_list[i]);
                }
            }
            if (exam_list.size() != 0) {
                for (int i = 0; i < exam_list.size(); i++) {
                    exam_list[i].xuat();
                }
            } else {
                cout << "-Hien dang khong co sinh vien trong danh sach du dieu kien du thi" << "\n";
            }
        } else if (a == 6) {
            vector<SinhVien> Nguyen_list;
            for (int i = 0; i < tmp_list.size(); i++) {
                if ((tmp_list[i].get_Hoten()).substr(0, 6) == "Nguyen") {
                    Nguyen_list.push_back(tmp_list[i]);
                }
            }
            if (Nguyen_list.size() != 0) {
                for (int i = 0; i < Nguyen_list.size(); i++) {
                    Nguyen_list[i].xuat();
                }
            } else {
                cout << "-Hien dang khong co sinh vien trong danh sach co ho la 'Nguyen'" << "\n";
            }
        } else if (a == 7) {
            vector<SinhVien> Hoten_list;
            for(int i = 0; i < tmp_list.size()-1; i++) {
                int b = 0;
                for(int j = i+1; j < tmp_list.size(); j++) {
                    if (tmp_list[i].get_Hoten() == tmp_list[j].get_Hoten()) {
                        if (b == 0) {
                            Hoten_list.push_back(tmp_list[i]);
                            b = 1;
                        }
                        Hoten_list.push_back(tmp_list[j]);
                    }
                }
            }
            if (Hoten_list.size() != 0) {
                for (int i = 0; i < Hoten_list.size(); i++) {
                    Hoten_list[i].xuat();
                }
            } else {
                cout << "-Hien dang khong co sinh vien trong danh sach co cung ten voi mot so sinh vien khac" << "\n";
            }
        } else {
            break;
        }
    }
    return 0;
}