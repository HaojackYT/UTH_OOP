#include <bits/stdc++.h>

using namespace std;

class CauhoiTN {
    private:
        string question, answer_A, answer_B, right_answer;
    public:
        void nhap();
        void docfile(ifstream&);
        void ghifile(ostream&);
        bool kiemtra(); 
        void xuat();
        friend bool giongnhau(CauhoiTN, CauhoiTN);
};

void Menu();
void space_2_underscore(string& a);
void underscore_2_space(string& a);
bool check_exist(vector<CauhoiTN> a, CauhoiTN b);