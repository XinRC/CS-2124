// Sample 1

/*
Sample code for Pointers: Dynamic Memory
This .cpp will go over dynamic memory and the usage of heaps. 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LandVehicle {

    friend ostream& operator<<(ostream& os, const LandVehicle& rhs) {
        os << "(" << rhs.name << ", wheel amount: " << rhs.wheel_amount << ")"; 
        return os; 
    }

    private:
        string name;
        int wheel_amount;
    public:
        // constructors
        LandVehicle(const string& name, int wheels = 4) 
            : name(name), wheel_amount(wheels) {}

        // getters 
        const string& display_name() const { return name; }
        int display_wheel_amount() const { return wheel_amount; }

        // setters
        void set_name(const string& name) { this->name = name; }
        void set_wheel_amount(int wheel_amount) {this->wheel_amount = wheel_amount; }

        // basic methods
        void start_engine() { cout << "Starting engine of " << name << endl; }

        ostream& display(ostream& os = cout) {
            os << name << " is the car brand." << endl;
            return os; 
        }
};

int main() {
    vector<LandVehicle*> landVehicles;

    // initalizing 3 Land Vehicle Items"
    LandVehicle* Car = new LandVehicle("Car", 4);
    LandVehicle* Motorcycle = new LandVehicle("Motorcycle", 2);
    LandVehicle* Tank = new LandVehicle("Tank", 14); 

    landVehicles.push_back(Car);
    landVehicles.push_back(Motorcycle);
    landVehicles.push_back(Tank);


    // looping through the vector to run certain methods:

    /*
    for (size_t i = 0; i < landVehicles.size(); ++i) {
        landVehicles[i]->display();
    }
    */

    for (size_t i = 0; i < landVehicles.size(); ++i) {
        cout << *landVehicles[i] << endl; 
    }

    // delete items from heap & setting pointers to nullptr
    for (size_t i = 0; i < landVehicles.size(); ++i) {
        delete landVehicles[i];
        landVehicles[i] = nullptr;
    }

    landVehicles.clear();
}