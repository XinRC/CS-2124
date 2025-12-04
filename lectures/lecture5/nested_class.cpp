// Sample 1

/*
Sample code for Nested Classes
This .cpp will go over the basics of nested classes - primarily focusing on private/public nested classes. 
*/
#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        class Engine { // private nested class
            private:
            public:
                Engine() {} 
                void displayEngine() const { cout << "Engine On" << endl; }
        };
        
        string brand;
        Engine engine;

    public:
        class Door { // public nested class 
            private:
                int doorAmount;
            public:
                Door(int doors = 4) : doorAmount(doors) {}
                int getDoors() const { return doorAmount; }
        };

    private: 
        Door door; // before creating an object of a class, the class must be fully defined (not just foward declared)

    public: 
        Car(const string& brand) : brand(brand), engine(), door(4) {}
        void startEngine() const { engine.displayEngine(); }
        int getDoors() const { return door.getDoors(); }
};

int main() {
    Car car1("Mercedes");
    car1.startEngine();
    cout << "The car has " << car1.getDoors() << " doors." << endl; 
}


