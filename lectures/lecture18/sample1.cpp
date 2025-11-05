// Sample 1

/*
Sample code for Overriding 
*/
#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brandModel;
        int wheels_amount;
    public:
        Car(const string& name, int wheels_amount = 4 )
            : brandModel(name), wheels_amount(wheels_amount) {}

        virtual void start_engine() { cout << "Starting engine of the " << brandModel << "." << endl; }
}; // car 

class Autocycle : public Car {
    private:
    public:
        Autocycle(const string& name, int wheels_amount = 3) : Car(name, wheels_amount) {}
}; // autocycle 

class Sports : public Car {
    private:
    public: 
        using Car::Car;

        void start_engine() { 
            cout << "Bvvrrrrr ... " << endl; 
            // Car::start_engine();
        }
}; // sports 

class Convertible : public Car {
    private:
    public:
        using Car::Car; // this instead of the constructor
}; // convertible

int main() {
    Sports mercedes_gullwing("Mercedes Gullwing");
    mercedes_gullwing.start_engine();
    mercedes_gullwing.Car::start_engine();

    cout << endl;

    Autocycle vanderhall_gts("Vanderhall GTS");
    vanderhall_gts.start_engine();
}


/* Notes:
> If your derived class is also using your parent class's constructor, you can type:
    "using Parent::Parent;"" instead of retying an entire constructor

*/