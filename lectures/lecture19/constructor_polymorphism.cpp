// Sample 1

/*
Sample code for Polymorphism inside Constructors 
*/

#include <iostream>
#include <string>
using namespace std;

class Base {
    private:
    public:
        Base() {
            // displayText(); // bad idea since it will run the non virtual method "Base Text"
        }
        virtual void displayText() const { cout << "Base Text" << endl; }
        virtual void initalize() { displayText(); } // initalization function, must be manually called 
};

class Derived : public Base {
    private:
    public:
        Derived() : Base() {}
        void displayText() const { cout << "Derived Text" << endl; }
};


int main() {
    Derived der;
    der.initalize();
}