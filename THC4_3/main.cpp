#include "THC4_3.h"

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";
    
    vector<Fraction> tmp_storage;

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
            int n;
            cout << "-Nhap vao n: "; cin >> n;
            srand(time(NULL));
            for (int i = 0; i < 100; i++) {
                Fraction a(n);
                tmp_storage.push_back(a);
            }
            cout << "-Danh sach cac phan so hien hanh:" << "\n";
            print_vector(tmp_storage);
        } else if (a == 2) {
            if (tmp_storage.size() != 0) {
                vector<Fraction> half_storage;
                for(int i = 0; i < tmp_storage.size(); i++) {
                    if (tmp_storage[i].get_numerator() * 2 <= tmp_storage[i].get_denominator()) {
                        half_storage.push_back(tmp_storage[i]);
                    }
                }
                if (half_storage.size() != 0) {
                    cout << "-Danh sach cac phan so hien hanh khong vuot qua 1/2:" << "\n";
                    print_vector(half_storage);
                } else {
                    cout << "-Khong co phan so khong vuot qua 1/2 trong danh sach phan so hien hanh" << "\n";
                }
            } else {
                cout << "-Khong co phan so trong danh sach phan so hien hanh" << "\n";
            }
        } else if (a == 3) {
            if (tmp_storage.size() != 0) {
                vector<Fraction> only_storage;
                for (int i = 0; i < tmp_storage.size(); i++) {
                    if (cnt_exist(tmp_storage, tmp_storage[i]) == 1) {
                        only_storage.push_back(tmp_storage[i]);
                    }
                }
                if (only_storage.size() != 0) {
                    cout << "-Danh sach cac phan so khong trung nhau:" << "\n";
                    print_vector(only_storage);
                } else {
                    cout << "-Khong co phan so khong trung nhau trong danh sach phan so hien hanh" << "\n";
                }
            } else {
                cout << "-Khong co phan so trong danh sach phan so hien hanh" << "\n";
            }
        } else if (a == 4) {
            if (tmp_storage.size() > 1) {
                cout << "-Danh sach cac phan so hien hanh:" << "\n";
                print_vector(tmp_storage);
                int b,c;
                cout << "-Nhap vao so thu tu cua phan so thu nhat: "; cin >> b;
                cout << "-Nhap vao so thu tu cua phan so thu hai: "; cin >> c;
                if ((b < 1 && b > tmp_storage.size()) || (c < 1 && c > tmp_storage.size())) {
                    do {
                        cout << "-So thu tu cua phan so thu nhat hoac thu hai khong chinh xac" << "\n";
                        cout << "-Vui long nhap lai so thu tu cua phan so thu nhat: "; cin >> b;
                        cout << "-Vui long nhap lai so thu tu cua phan so thu hai: "; cin >> c;
                    } while ((b < 1 && b > tmp_storage.size()) || (c < 1 && c > tmp_storage.size()));
                }
                cout << "-Tong cua 2 phan so: " << tmp_storage[b-1] + tmp_storage[c-1] << "\n";
                cout << "-Hieu cua 2 phan so: " << tmp_storage[b-1] - tmp_storage[c-1] << "\n";
                cout << "-Tich cua 2 phan so: " << tmp_storage[b-1] * tmp_storage[c-1] << "\n";
                cout << "-Thuong cua 2 phan so: " << tmp_storage[b-1] / tmp_storage[c-1] << "\n";
            } else {
                cout << "-Su dung cac toan tu '+','-','*','/' that bai" << "\n";
                cout << "-So luong phan so trong danh sach phan so hien hanh qua it (<2)" << "\n";
            }
        } else if (a == 5) {
            if (tmp_storage.size() > 1) {
                cout << "-Danh sach cac phan so hien hanh:" << "\n";
                print_vector(tmp_storage);
                int b,c;
                cout << "-Nhap vao so thu tu cua phan so thu nhat: "; cin >> b;
                cout << "-Nhap vao so thu tu cua phan so thu hai: "; cin >> c;
                if ((b < 1 && b > tmp_storage.size()) || (c < 1 && c > tmp_storage.size())) {
                    do {
                        cout << "-So thu tu cua phan so thu nhat hoac thu hai khong chinh xac" << "\n";
                        cout << "-Vui long nhap lai so thu tu cua phan so thu nhat: "; cin >> b;
                        cout << "-Vui long nhap lai so thu tu cua phan so thu hai: "; cin >> c;
                    } while ((b < 1 && b > tmp_storage.size()) || (c < 1 && c > tmp_storage.size()));
                }
                int d = tmp_storage[b-1] == tmp_storage[c-1];
                int e = tmp_storage[b-1] != tmp_storage[c-1];
                int f = tmp_storage[b-1] >= tmp_storage[c-1];
                int g = tmp_storage[b-1] <= tmp_storage[c-1];
                cout << "-Phan so thu nhat == phan so thu hai: " << d << "\n";
                cout << "-Phan so thu nhat != phan so thu hai: " << e << "\n";
                cout << "-Phan so thu nhat >= phan so thu hai: " << f << "\n";
                cout << "-Phan so thu nhat <= phan so thu hai: " << g << "\n";
            } else {
                cout << "-Su dung cac toan tu '==','!=','>=','<=' that bai" << "\n";
                cout << "-So luong phan so trong danh sach phan so hien hanh qua it (<2)" << "\n";
            }
        } else if (a == 6) {
            Fraction b;
            cout << "-Nhap vao tu so va mau so cua phan so (vi du 3 4): ";cin >> b;
            tmp_storage.push_back(b);
            cout << tmp_storage.size() << ") " << b << " da duoc them vao danh sach phan so hien hanh" << "\n";
        } else {
            break;
        }
    }
    return 0;
}