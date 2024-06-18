#include <bits/stdc++.h>

using namespace std;

class SinhVien {
    private:
        string MSSV, Hoten;
        int SBV;
        float DiemTH, DiemGK, DiemQT;
    public:
        string get_Hoten();
        float get_DiemQT();

        void nhap();
        void docfile(ifstream&);
        void ghifile(ostream&);
        void xuat();
};

void space_2_underscore(string&);
void underscore_2_space(string&);