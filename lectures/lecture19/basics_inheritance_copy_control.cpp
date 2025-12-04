// Sample 2

/*
Sample code for Inheritance for Copy Controls.
This .cpp file will cover the very basics of inherited copy controls. A better example may be in the works
for the future.
*/

#include <iostream>
using namespace std;

class Base {
    private:
    public:
        Base() { cerr << "Base Constructor" << endl; }
        Base(const Base& other) { cerr << "Base Copy Constructor" << endl; }
        Base& operator=(const Base& other) {
            if (this != &other) {
                cerr << "Base Assignment Operator" << endl;
            }
            return *this;
        }
        virtual ~Base() { cerr << "Base Destructor" << endl; }
};


class Derived : public Base {
    private:
    public:
        Derived() { cerr << "Default Derived Constructor" << endl; } // default constructor
        Derived(const Derived& der) : Base(der) { // correct copy constructor
            cerr << "Derived Copy Contructor" << endl; 
        } 
        Derived& operator=(const Derived& other) { // assignment operator
            if (this != &other) {
                Base::operator=(other); // calls base's assignment operator
                cerr << "Derived Operator" << endl;
            }
            return *this;
        }
        ~Derived() { // since base's destructor is virtual, it will also call this destructor
            cerr << "Derived Destructor" << endl; 
        }
};


int main() {
    // Testing (uncomment the code to test):

    //Derived der;
    //Derived der2; 
    //Derived der3(der);
    //cout << "==" << endl;
    //der = der2;

}