#include "THC6_2.h"

SCEmployee::SCEmployee(const string &first, const string &last,
    const string &ssn, double sales, double rate, double salary)
    : CEmployee(first, last, ssn, sales, rate) {
        setBaseSalary(salary);
}

SCEmployee::SCEmployee() : CEmployee() {
    setBaseSalary((rand() % 100) + 10);
}

void SCEmployee::setBaseSalary(double salary) {
    if (salary >= 0.0) {
        baseSalary = salary;
    } else {
        throw invalid_argument("Salary must be >= 0.0");
    }
}

double SCEmployee::getBaseSalary() const {
    return baseSalary;
}

double SCEmployee::earnings() const {
    return getBaseSalary() + CEmployee::earnings();
}

void SCEmployee::print() const {
    cout << "base-salary: ";
    CEmployee::print();
    cout << "; base-salary: " << getBaseSalary();
}