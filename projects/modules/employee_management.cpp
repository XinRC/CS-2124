/*
employee_management.cpp utilizes dynamic pointers implemention to keep a databasse of employees and their roles
(along with other valuable data)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Employee {
    friend ostream& operator<<(ostream& os, const Employee& rhs) {
        rhs.display(os);
        return os;
    }
    private:
        string name;
        string id;
        double annual_pay;
        double monthly_pay;
        string field;
        string role;
    public:
        Employee(const string& name, const string& id, double annual_pay, const string& field) 
        : name(name), id(id), annual_pay(annual_pay), field(field) {}
        virtual ostream& display(ostream& os) const = 0;

        // getter / setters
        double get_annual_pay() const { return annual_pay; }
        const string& get_role() const { return role; }
        void set_role(const string& role) { this->role = role; }
        string get_name() const { return name; }
        const string& get_id() const { return id; }
        const string& get_field() const { return field; }
        double get_monthly_pay() const { 
            if (role != "Part Time") {
                return (annual_pay / 12); 
            } else {
                return annual_pay;
            } }

        // methods
        void add_to_annual_pay(double bonus) { annual_pay += bonus; }

        virtual ~Employee() {}
};

ostream& Employee::display(ostream& os) const {
    os << name << " (" << id << ") - " << field << " - ";
    return os;
}

class FullTimeEmployee : public Employee {
    public:
        using Employee::Employee;
        ostream& display(ostream& os) const {
            Employee::display(os);
            os << "Full Time - Salary: $" << get_annual_pay();
            return os;
        }
};

class PartTimeEmployee : public Employee {
    private:
        double hourly_wage;
        int working_hours;
    public:
        PartTimeEmployee(const string& name, const string& id, double hourly_wage, int working_hours, const string& field) 
            : Employee(name, id, hourly_wage * working_hours, field),
                 hourly_wage(hourly_wage), working_hours(working_hours) {}
        ostream& display(ostream& os) const {
            Employee::display(os);
            os << "Part Time - Hourly: $" << hourly_wage;
            return os;
        }
};

class Manager : public Employee {
    private:
        double monthly_bonus;
    public:
        Manager(const string& name, const string& id, double annual_salary, const string& field, double monthly_bonus) 
            : Employee(name, id, annual_salary, field), monthly_bonus(monthly_bonus) {}
        ostream& display(ostream& os) const {
            Employee::display(os);
            os << "Manager - Salary: $" << get_annual_pay();
            return os;
        }
};

class Company {
    private:
        string company_name;
        vector<Employee*> employee_list; 
    public:
        Company(const string& company_name) : company_name(company_name) {}

        // hiring occupation 
        void hireFullTime(const string& name , const string& id, double base_salary, const string& field) {
            Employee* new_employee = new FullTimeEmployee(name, id, base_salary, field);
            employee_list.push_back(new_employee);
            new_employee->set_role("Full Time");
        }
        void hirePartTime(const string& name , const string& id, double hourly_wage, int working_hours, const string& field) {
            Employee* new_employee = new PartTimeEmployee(name, id, hourly_wage, working_hours, field);
            employee_list.push_back(new_employee);
            new_employee->set_role("Part Time");
        }
        void hireManager(const string& name , const string& id, double base_salary, const string& field, double monthly_raise) {
            Employee* new_employee = new Manager(name, id, base_salary, field, monthly_raise);
            employee_list.push_back(new_employee);
            new_employee->set_role("Manager");
            new_employee->add_to_annual_pay(monthly_raise*12);
        }

        void displayAllEmployees() {
            cout <<"EMPLOYEES: " << endl;
            int start = 0;
            for (Employee* employee : employee_list) {
                cout << start + 1 << ". " << *employee << endl;
            }
        }
        

        void calculatePayroll() {
            double total_payroll = 0;
            for (Employee* employee : employee_list) {
                cout << employee->get_name() << ": $" << employee->get_monthly_pay() << endl;
                total_payroll += employee->get_monthly_pay();
            }
            cout << "Total Payroll: $" << total_payroll << endl;
        }

        void giveRaise(const string& id, double raise_amount) {
            for (Employee* employee : employee_list) {
                if (employee->get_id() == id) {
                    bool found = true;
                    employee->add_to_annual_pay(raise_amount);
                    cout << "Gave raise to " << employee->get_name() << ": New salary $" 
                        << employee->get_annual_pay() << endl;
                }
            } 
        }

        void promoteToManager(const string& id, double raise_amount) {
            for (Employee* employee : employee_list) {
                if (employee->get_id() == id) {
                    employee->set_role("Manager");
                    employee->add_to_annual_pay(raise_amount);
                    cout << "Promoted " << employee->get_name() << " to Manager with bonus $" 
                        << raise_amount << endl; 
                }
            }
        }

        void findEmployee(const string& id) {
            bool found = false;
            for (Employee* employee : employee_list) {
                if (employee->get_id() == id) {
                    found = true;
                    cout << "[FOUND]: " << *employee << endl;
                }
            }
            if (found != true) {
                cout << "[NOT FOUND]: " << id << endl;
            }
        }

        void displayDepartmentSummary(const string field) {
            cout << field << " Department:" << endl;
            int amount_in_department = 0;
            for (Employee* employee : employee_list) {
                if (employee->get_field() == field) {
                    cout << "- " << employee->get_name() << " ("
                        << employee->get_role() << ")" << endl;
                    amount_in_department += 1;
                }
            }
            cout << "Total: " << amount_in_department << " employees" << endl;
        }

        // big three
        ~Company() {
            for (size_t i = 0; i < employee_list.size(); ++i) {
                delete employee_list[i];
            }
            employee_list.clear();
        }

};

int main() {
    Company company("Tech Corp");
    
    // Hire different types of employees
    company.hireFullTime("Alice Johnson", "E001", 60000, "Engineering");
    company.hirePartTime("Bob Smith", "E002", 25.0, 20, "Marketing");
    company.hireManager("Carol Davis", "E003", 80000, "Engineering", 5000);
    company.hireFullTime("David Wilson", "E004", 55000, "Sales");
    
    // Test employee operations
    cout << "=== INITIAL EMPLOYEE STATUS ===" << endl;
    company.displayAllEmployees();
    
    cout << "\n=== PAYROLL CALCULATION ===" << endl;
    company.calculatePayroll();
    
    cout << "\n=== PROMOTION TEST ===" << endl;
    company.giveRaise("E001", 5000); // Give Alice a raise
    company.promoteToManager("E004", 6000); // Promote David to manager
    
    cout << "\n=== FIND EMPLOYEE TEST ===" << endl;
    company.findEmployee("E001");
    company.findEmployee("INVALID"); // Should show not found
    
    cout << "\n=== DEPARTMENT SUMMARY ===" << endl;
    company.displayDepartmentSummary("Engineering");

    return 0;
}
