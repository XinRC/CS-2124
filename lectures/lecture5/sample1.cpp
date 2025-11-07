// Sample 1

/*
Sample code for Nesting Classes 
*/
#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;

        class Engine{ // private nested class
            private:
            public:
                Engine() {} 
                void displayEngine() const { cout << "Engine On" << endl; }
        };
    public:
        class Door { // public nested class 
            private:
                int doorAmount;
            public:
                Door(int doors = 4) : doorAmount(doors) {}
                int getDoors() const { return doorAmount; }
        };

        Car(const string& brand) : brand(brand) {}
};

int main() {

}


