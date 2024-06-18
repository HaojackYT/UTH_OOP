#include "THC6_2.h"

Employee::Employee(const string &first, const string &last,
    const string &ssn)
    : firstName(first), lastName(last), socialSecurityNumber(ssn) {}

void Employee::setFirstName(const string &first) {
    firstName = first;
}

string Employee::getFirstName() const {
    return firstName;
}

void Employee::setLastName(const string &last) {
    lastName = last;
}

string Employee::getLastName() const {
    return lastName;
}

void Employee::setSocialSecurityNumber(const string &ssn) {
    socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void Employee::print() const {
    cout << getFirstName() << " " << getLastName() 
    << "\nsocial security number: " << getSocialSecurityNumber();
}

Employee::Employee() {
    char tmp_first = 'a' + rand() % 26;
    char tmp_last = 'a' + rand() % 26;
    char tmp_ssn = 'a' + rand() % 26;
    this->firstName = tmp_first;
    this->lastName = tmp_last;
    this->socialSecurityNumber = tmp_ssn;
}