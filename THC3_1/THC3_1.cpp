#include "THC3_1.h"

void CauhoiTN::nhap() {
    cout << "-Nhap vao noi dung cau hoi (question): ";
    getline(cin, this->question);
    cout << "+Nhap vao noi dung dap an A (answer_A): ";
    getline(cin, this->answer_A);
    cout << "+Nhap vao noi dung dap an B (answer_B): ";
    getline(cin, this->answer_B);
    cout << "+Nhap vao dap an dung (right_answer) (A/B): ";
    getline(cin, this->right_answer);
    cout << "-Mot cau hoi moi da duoc them vao de thi hien hanh" << "\n";
}

void CauhoiTN::docfile(ifstream& i) {
    string s_file;
    getline(i, s_file);
    stringstream ss(s_file);
    string s;
    vector<string> s_storage;
    while (ss >> s) {
        s_storage.push_back(s);
    }
    underscore_2_space(s_storage[0]);
    underscore_2_space(s_storage[1]);
    underscore_2_space(s_storage[2]);
    this->question = s_storage[0];
    this->answer_A = s_storage[1];
    this->answer_B = s_storage[2];
    this->right_answer = s_storage[3];
}

void CauhoiTN::ghifile(ostream& o) {
    string Cau_hoi = this->question;
    string Dap_an_A = this->answer_A;
    string Dap_an_B = this->answer_B;
    space_2_underscore(Cau_hoi);
    space_2_underscore(Dap_an_A);
    space_2_underscore(Dap_an_B);
    string s_file = Cau_hoi + " " + Dap_an_A + " " + Dap_an_B + " " + right_answer;
    o << s_file << "\n";
}

bool CauhoiTN::kiemtra() {
    cout <<  this->question << "\n";
    cout << "A)" << this->answer_A << "\n";
    cout << "B)" << this->answer_B << "\n";
    string c;
    cout << "-Nhap vao dap an dung (A/B): ";
    getline(cin, c);
    if (c != "A" && c != "B") {
        do {
            cout << "-Qui uoc cua dap an dung khong chinh xac" << "\n";
            cout << "-Vui long nhap lai dap an dung (A/B) cua cau hoi: ";
            getline(cin, c);
        } while (c != "A" && c != "B");
    }
    if (c == this->right_answer) {
        return 1;
    } else {
        return 0;
    }
}

void CauhoiTN::xuat() {
    cout <<  this->question << "\n";
    cout << "A)" << this->answer_A << "\n";
    cout << "B)" << this->answer_B << "\n";
    cout << "Dap an dung (A/B): " << this->right_answer << "\n";
}

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.question == cau2.question 
    && cau1.answer_A == cau2.answer_A 
    && cau1.answer_B == cau2.answer_B 
    && cau1.right_answer == cau2.right_answer);
}

void Menu() {
    cout << "===============================================MENU=================================================" << "\n";
    cout << "+Tao mot de thi trac nghiem moi = '1'" << "\n";
    cout << "+Them mot cau hoi moi tu ban phim vao de thi hien hanh = '2'" << "\n";
    cout << "+In danh sach cau hoi hien dang co trong de thi = '3'" << "\n";
    cout << "+Luu danh sach cau hoi vao file *.TTN [ten file duoc nhap tu ban phim (vi du LTHDT-CN15B.TTN)] = '4'" << "\n";
    cout << "+Doc noi dung mot file *.TTN vao bo nho = '5'" << "\n";
    cout << "+Thi va tinh so cau tra loi dung cua thi sinh = '6'" << "\n";
    cout << "+Kiem tra cau hoi trong danh sach co trung nhau hay khong = '7'" << "\n";
    cout << "+Thoat chuong trinh = '8'" << "\n";
    cout << "====================================================================================================" << "\n";
}

void space_2_underscore(string& a) {
    replace(a.begin(), a.end(), ' ', '_');
}

void underscore_2_space(string& a) {
    replace(a.begin(), a.end(), '_', ' ');
}

bool check_exist(vector<CauhoiTN> a, CauhoiTN b) {
    for (int i = 0; i < a.size(); i++) {
        if (giongnhau(a[i], b)) {
            return 1;
        }
    }
    return 0;
}