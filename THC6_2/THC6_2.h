#include <bits/stdc++.h>

using namespace std;

class Employee {
    private:
        string firstName, lastName, socialSecurityNumber;
    public:
        Employee(const string &, const string &, const string &);
        Employee();
        
        void setFirstName(const string &);
        string getFirstName() const;
        
        void setLastName(const string &);
        string getLastName() const;
        
        void setSocialSecurityNumber(const string &);
        string getSocialSecurityNumber() const;

        virtual double earnings() const = 0;
        virtual void print() const;
};

class SEmployee : public Employee {
    private:
        double weeklySalary;
    public:
        SEmployee(const string &, const string &,
        const string &, double = 0.0);
        SEmployee();
        
        void setWeeklySalary(double);
        double getWeeklySalary() const;

        virtual double earnings() const;
        virtual void print() const;
};

class CEmployee : public Employee {
    private:
        double grossSales;
        double commissionRate;
    public:
        CEmployee(const string &, const string &,
        const string &, double = 0.0, double = 0.0);
        CEmployee();

        void setCommissionRate(double);
        double getCommissionRate() const;

        void setGrossSales(double);
        double getGrossSales() const;

        virtual double earnings() const;
        virtual void print() const;
};

class SCEmployee : public CEmployee {
    private:
        double baseSalary;
    public:
        SCEmployee(const string &, const string &,
            const string &, double = 0.0, double = 0.0, double = 0.0);
        SCEmployee();

        void setBaseSalary(double);
        double getBaseSalary() const;

        virtual double earnings() const;
        virtual void print() const;
};

void Menu();