#include "THC3_2.h"

string SinhVien::get_Hoten() {
    return this->Hoten;
}

float SinhVien::get_DiemQT() {
    return this->DiemQT;
}

void SinhVien::nhap() {
    cout << "+Nhap vao MSSV cua sinh vien: ";
    getline(cin, this->MSSV);
    cout << "+Nhap vao ho ten cua sinh vien: ";
    getline(cin, this->Hoten);
    cout << "+Nhap vao so buoi vang cua sinh vien: "; cin >> this->SBV;
    if (this->SBV < 0) {
        do {
            cout << "+So buoi vang cua sinh vien khong hop le" << "\n";
            cout << "+Vui long nhap lai so buoi vang cua sinh vien: "; cin >> this->SBV;
        } while (this->SBV < 0);
    }
    cout << "+Nhap vao diem thuc hanh cua sinh vien: "; cin >> this->DiemTH;
    if (this->DiemTH < 0) {
        do {
            cout << "+Diem thuc hanh cua sinh vien khong hop le" << "\n";
            cout << "+Vui long nhap lai diem thuc hanh cua sinh vien: "; cin >> this->DiemTH;
        } while (this->DiemTH < 0);
    }
    cout << "+Nhap vao diem giua ki cua sinh vien: "; cin >> this->DiemGK;
    if (this->DiemGK < 0) {
        do {
            cout << "+Diem giua ki cua sinh vien khong hop le" << "\n";
            cout << "+Vui long nhap lai diem giua ki cua sinh vien: "; cin >> this->DiemGK;
        } while (this->DiemGK < 0);
    }
    if (this->SBV <= 5) {
        this->DiemQT = (10 - this->SBV*2)*0.2 + this->DiemTH*0.3 + this->DiemGK*0.5;
    } else {
        this->DiemQT = 0;
    }
    cin.ignore();
}

void SinhVien::docfile(ifstream& i) {
    string s_file;
    getline(i, s_file);
    stringstream ss(s_file);
    string s;
    vector<string> s_storage;
    while (ss >> s) {
        s_storage.push_back(s);
    }
    underscore_2_space(s_storage[1]);
    this->MSSV = s_storage[0];
    this->Hoten = s_storage[1];
    this->SBV = stoi(s_storage[2]);
    this->DiemTH = stof(s_storage[3]);
    this->DiemGK = stof(s_storage[4]);
    if (this->SBV <= 5) {
        this->DiemQT = (10 - this->SBV*2)*0.2 + this->DiemTH*0.3 + this->DiemGK*0.5;
    } else {
        this->DiemQT = 0;
    }
}

void SinhVien::ghifile(ostream& o) {
    string s = this->Hoten;
    space_2_underscore(s);
    string s_file = this->MSSV + " " + s + " " + to_string(this->SBV) + " " + to_string(this->DiemTH) + " " + to_string(this->DiemGK);
    o << s_file << "\n";
}

void SinhVien::xuat() {
    cout << "MSSV: " << this->MSSV << "\n";
    cout << "Ho ten: " << this->Hoten << "\n";
    cout << "So buoi vang: " << this->SBV << "\n";
    cout << "Diem thuc hanh: " << this->DiemTH << "\n";
    cout << "Diem giua ki: " << this->DiemGK << "\n";
    cout << "Diem qua trinh: " << this->DiemQT << "\n";
}

void space_2_underscore(string& a) {
    replace(a.begin(), a.end(), ' ', '_');
}
void underscore_2_space(string& a) {
    replace(a.begin(), a.end(), '_', ' ');
}