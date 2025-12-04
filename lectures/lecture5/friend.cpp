// Sample 2

/*
Sample code for Nested Classes and Friend
This .cpp will go over nested classes and the usage of the keyword "friend" which requires the usage of operaton overloading for the operator "<<".
*/

#include <iostream>
#include <string>
using namespace std;

class USMilitary{
    friend ostream& operator<<(ostream& os, const USMilitary& rhs) {
        os << "The " << rhs.branch << " utilizes the " << rhs.weapon << endl; 
        return os; 
    }

    private:
        class Firearm {

            private:
                string firearmName;
                string caliber; 
            public:
                Firearm(const string& name, string caliber) : firearmName(name), caliber(caliber) {}

                friend ostream& operator<<(ostream& os, const USMilitary::Firearm& rhs) {
                    os << "(" << rhs.firearmName << " - " << rhs.caliber << ")" << endl; 
                    return os; 
                }
        };

        string branch;
        Firearm weapon;

    public:
        USMilitary(const string& branch, const string& firearmName, string caliber) 
            : branch(branch), weapon(firearmName, caliber) {}
};


int main() {
    USMilitary Marines("Marines", "Sig Sauer M18", "9mm"); 

    cout << Marines << endl; 

} // main
