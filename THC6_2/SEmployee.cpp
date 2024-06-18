#include "THC6_2.h"

SEmployee::SEmployee(const string &first,
    const string &last, const string &ssn, double salary)
    : Employee(first, last, ssn) {
        setWeeklySalary(salary);
}

SEmployee::SEmployee() : Employee() {
    setWeeklySalary((rand() % 700) + 70);
}

void SEmployee::setWeeklySalary(double salary) {
    if (salary >= 0.0) {
        weeklySalary = salary;
    } else {
        throw invalid_argument("Weekly salary must be >= 0.0");
    }
}

double SEmployee::getWeeklySalary() const {
    return weeklySalary;
}

double SEmployee::earnings() const {
    return getWeeklySalary();
}

void SEmployee::print() const {
    cout << "salaried employee: ";
    Employee::print();
    cout << "\nweekly salary: " << getWeeklySalary();
}