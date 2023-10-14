#include<iostream>
using namespace std;

class Person {
        string name;
    public:
        void Name(string n) {
            name = n;
        }
        void display() {
            cout << "Name: " << name << endl;
        }
};
class Employee : public Person {
    private:
        int employee_id;
        float salary;
    public:
        void Data(int e, float s) {
            employee_id = e;
            salary = s;
        }
        void displayData() {
            cout << "Employee ID: " << employee_id << endl;
            cout << "Salary: " << salary << endl;
        }

};

int main() {
    Employee emp;
    emp.Name("John Doe");
    emp.Data(1001, 2500.00);
    emp.display();
    emp.displayData();

   return 0;
}

