#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
public:
    Employee(string n) : name(n) {}
    virtual void calculatePay() {
        cout << name << ": Base employee pay calculation." << endl;
    }
    virtual ~Employee() {}   // virtual destructor (good practice)
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(string n, double sal) : Employee(n), monthlySalary(sal) {}
    void calculatePay() override {
        cout << name << " (Full-time): Monthly salary = $" << monthlySalary << endl;
    }
};

class Contractor : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    Contractor(string n, double rate, int hours)
        : Employee(n), hourlyRate(rate), hoursWorked(hours) {}
    void calculatePay() override {
        cout << name << " (Contractor): Pay = $" << (hourlyRate * hoursWorked)
             << " (" << hoursWorked << " hrs @ $" << hourlyRate << "/hr)" << endl;
    }
};

int main() {
    cout << "=== Demonstrating Runtime Polymorphism ===" << endl;

    // Base-class pointers to derived objects
    Employee* emp1 = new FullTimeEmployee("Alice", 5000.0);
    Employee* emp2 = new Contractor("Bob", 50.0, 40);

    emp1->calculatePay();   // calls FullTimeEmployee version
    emp2->calculatePay();   // calls Contractor version

    delete emp1;
    delete emp2;
    return 0;
}