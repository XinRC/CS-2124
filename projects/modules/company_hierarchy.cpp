/*
company_hierarchy.cpp focuses on multiple inheritance and virtual classes
*/
#include <iostream>
#include <string>
using namespace std;

// YOUR CLASSES HERE
class Person {
    private:
        string name; 
    public:
        Person(const string& name) : name(name) {}
        const string& getName() const { return name; }
        virtual void displayInfo() {
            cout << "Person: "  << name << endl;
        }
};

class Employee : virtual public Person {
    private:
        double salary;
    public:
        Employee(const string& name, double salary) : Person(name), salary(salary) {}
        double get_salary() const { return salary; }
        void displayInfo() {
            cout << "Employee: "  << getName() << " - $" << salary << endl;
        }
        void work() { cout << "Employee Working..." << endl; }
};

class TeamLeader : virtual public Person {
    private:
        int amount_of_team_members;
    public:
        TeamLeader(const string& name, int team_member_amount) 
            : Person(name), amount_of_team_members(team_member_amount) {}
        int get_team_member_amount() const { return amount_of_team_members; }
        void displayInfo() {
            cout << "TeamLeader: " << getName() << " - " << amount_of_team_members << " team members" << endl;
        }
        void leadMeeting() {
            cout << "TeamLeader leading meeting..." << endl; 
        }
};

class Manager : public Employee, public TeamLeader {
    public:
        Manager(const string& name, double salary, int team_members_amount) 
            : Person(name), Employee(name, salary), TeamLeader(name, team_members_amount) {}
        void displayInfo() {
            Person::displayInfo();
            Employee::displayInfo();
            TeamLeader::displayInfo();
            cout << "Manager: " << getName() << endl;
        }
};

int main() {
    Manager mgr("Sarah Johnson", 5000, 10);
    
    mgr.displayInfo();      // Should work without ambiguity
    mgr.work();            // Should call the right version
    mgr.leadMeeting();     // Manager-specific method
    
    cout << "Name: " << mgr.getName() << endl;  // Should work without scope resolution
    
    return 0;
}
