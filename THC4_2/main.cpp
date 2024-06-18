#include "THC4_2.h"

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";
    
    vector<Point> tmp_storage;

    ifstream f("THC4_2.txt");
    if (f.is_open()) {
        string n;
        getline(f, n);
        string s_file;
        for (int i = 0; i < stoi(n); i++) {
            if (getline(f, s_file)) {
                stringstream ss(s_file);
                string num;
                vector<float> num_storage;
                while (ss >> num) {
                    num_storage.push_back(stof(num));
                }
                Point a(num_storage[0], num_storage[1]);
                tmp_storage.push_back(a);
            }
        }
        if (tmp_storage.size() != 0) {
            cout << "-Thu tu cac diem tu file 'THC4_2.txt'" << "\n";
            for (int i = 0; i < tmp_storage.size(); i++) {
                cout << i+1 << ") ";
                tmp_storage[i].print();
            }
        } else {
            cout << "-Khong co cac diem trong file 'THC4_2.txt' hoac so diem co trong file khai bao <= 0" << "\n";
        }
        f.close();
    } else {
        cout << "-Doc noi dung file 'THC4_2.txt' vao bo nho that bai" << "\n";
        cout << "-Khong tim thay file 'THC4_2.txt'" << "\n";
    }
    if (tmp_storage.size() != 0) {
        sort(tmp_storage.begin(), tmp_storage.end());
        cout << "-Thu tu cac diem sap xep tang dan theo khoang cach den goc toa do" << "\n";
        for (int i = 0; i < tmp_storage.size(); i++) {
            cout << i+1 << ") ";
            tmp_storage[i].print();
        }
    }
    return 0;
}