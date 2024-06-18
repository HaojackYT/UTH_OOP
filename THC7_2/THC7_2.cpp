#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "Ho va ten : Tang Chi Hao" << "\n";
    cout << "MSSV : 079205023491" << "\n";
    
    vector<int> tmp_storage;
    map<int, int> mp;

    int n;
    cout << "Nhap vao so luong phan tu cua mang cac so nguyen: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tmp_storage.push_back(x);
        mp[x]++;
    }
    
    cout << "a) Co " << mp.size() << " gia tri nguyen khac nhau trong mang" << "\n";

    cout << "b) Danh sach so lan xuat hien gia tri cua cac phan tu trong mang: " << "\n";
    cout << left << setw(7) << "Gia tri" << " ";
    cout << left << setw(16) << "So lan xuat hien" << "\n";
    for (pair<int, int> it : mp) {
        cout << left << setw(7) << it.first << " ";
        cout << left << setw(16) << it.second << "\n";
    }

    cout << "c) Danh sach cac gia tri khac nhau trong mang: " << "\n";
    for (int i = 0; i < tmp_storage.size(); i++) {
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if ((*it).second == 1 && tmp_storage[i] == (*it).first) {
                cout << tmp_storage[i] << " ";
            }
        }
    }
}