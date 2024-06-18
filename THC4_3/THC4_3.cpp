#include "THC4_3.h"

void Menu() {
    cout << "=================================================MENU==================================================" << "\n";
    cout << "-Nhap n tu ban phim, sinh ngau nhien 100 phan so co tu va mau la so nguyen duong khong vuot qua n = '1'" << "\n";
    cout << "-In ra man hinh cac phan so trong cac phan so da sinh khong vuot qua 1/2 = '2'" << "\n";
    cout << "-In ra man hinh cac phan so khong trung nhau tu cac phan so da sinh ra = '3'" << "\n";
    cout << "-Su dung cac toan tu '+','-','*','/' = '4'" << "\n";
    cout << "-Su dung cac toan tu '==','!=','>=','<=' = '5'" << "\n";
    cout << "-Su dung cac toan tu '<<','>>' = '6'" << "\n";
    cout << "-Thoat chuong trinh = '7'" << "\n";
    cout << "=======================================================================================================" << "\n";
}

void print_vector(vector<Fraction> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << i + 1 << ") ";
        cout << a[i] << "\n";
    }
}

int cnt_exist(vector<Fraction> a, Fraction b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) {
            cnt++;
        }
    }
    return cnt;
}

Fraction::Fraction() {
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(int a) {
    this->numerator = (rand() % a) + 1;
    this->denominator = (rand() % a) + 1;
}

Fraction::Fraction(int a, int b) {
    this->numerator = a;
    this->denominator = b;
}

int Fraction::get_numerator() {
    return this->numerator;
}

int Fraction::get_denominator() {
    return this->denominator;
}

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

void abbreviate(int &a, int &b) {
    if (a != 0) {
        int c = gcd(a, b);
        a /= c;
        b /= c;
    }
}

Fraction operator + (Fraction a, Fraction b) {
    Fraction c;
    c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    abbreviate(c.numerator, c.denominator);
    return c;
}

Fraction operator - (Fraction a, Fraction b) {
    Fraction c;
    c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    abbreviate(c.numerator, c.denominator);
    return c;
}

Fraction operator * (Fraction a, Fraction b) {
    Fraction c;
    c.numerator = a.numerator * b.numerator;
    c.denominator = a.denominator * b.denominator;
    abbreviate(c.numerator, c.denominator);
    return c;
}

Fraction operator / (Fraction a, Fraction b) {
    Fraction c;
    c.numerator = a.numerator * b.denominator;
    c.denominator = a.denominator * b.numerator;
    abbreviate(c.numerator, c.denominator);
    return c;
}

bool operator == (Fraction a, Fraction b) {
    return ((a.numerator * b.denominator) == (b.numerator * a.denominator));
}

bool operator != (Fraction a, Fraction b) {
    return ((a.numerator * b.denominator) != (b.numerator * a.denominator));
}

bool operator >= (Fraction a, Fraction b) {
    return ((a.numerator / a.denominator) >= (b.numerator / b.denominator));
}

bool operator <= (Fraction a, Fraction b) {
    return ((a.numerator / a.denominator) <= (b.numerator / b.denominator));
}

istream& operator >> (istream& i, Fraction& a) {
    i >> a.numerator >> a.denominator;
}

ostream& operator << (ostream& o, Fraction a) {
    o << a.numerator << "/" << a.denominator;
}