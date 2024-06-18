#include "THC6_2.h"

CEmployee::CEmployee(const string &first,
    const string &last, const string &ssn, double sales, double rate)
    : Employee(first, last, ssn) {
        setGrossSales(sales);
        setCommissionRate(rate);
}

CEmployee::CEmployee() : Employee() {
    double CommissionRate[9] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    setGrossSales((rand() % 100) + 1);
    setCommissionRate(CommissionRate[rand() % 9]);
}

void CEmployee::setGrossSales(double sales) {
    if (sales >= 0.0) {
        grossSales = sales;
    } else {
        throw invalid_argument("Gross Sales must be >= 0.0");
    }
}

double CEmployee::getGrossSales() const {
    return grossSales;
}

void CEmployee::setCommissionRate(double rate) {
    if (rate > 0.0 && rate < 1.0) {
        commissionRate = rate;
    } else {
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }
}

double CEmployee::getCommissionRate() const {
    return commissionRate;
}

double CEmployee::earnings() const {
    return getCommissionRate() * getGrossSales();   
}

void CEmployee::print() const {
    cout << "commission employee: ";
    Employee::print();
    cout << "\ngross sales: " << getGrossSales()
        << "\ncommission rate: " << getCommissionRate();
}