#include <bits/stdc++.h>

using namespace std;

class Fraction {
    private:
        int numerator, denominator;
    public:
        Fraction();
        Fraction(int);
        Fraction(int, int);
        int get_numerator();
        int get_denominator();
        friend int gcd(int, int);
        void abbreviate(int&, int&);
        friend Fraction operator + (Fraction, Fraction);
        friend Fraction operator - (Fraction, Fraction);
        friend Fraction operator * (Fraction, Fraction);
        friend Fraction operator / (Fraction, Fraction);
        friend bool operator == (Fraction, Fraction);
        friend bool operator != (Fraction, Fraction);
        friend bool operator >= (Fraction, Fraction);
        friend bool operator <= (Fraction, Fraction);
        friend istream& operator >> (istream& i, Fraction& a);
        friend ostream& operator << (ostream& o, Fraction a);
};
void Menu();
void print_vector(vector<Fraction>);
int cnt_exist(vector<Fraction>, Fraction);