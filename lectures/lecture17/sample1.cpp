// Sample 1

/*
Sample code for Abstract and Protected
Given a base class and a derived class (of the base class), this .cpp will utilize
the protected mode and talk briefly about "Hiding"
*/

#include <iostream>
#include <string>
using namespace std;


class Vehicle {
    private:
        string brandName;
        string element;
        int wheels;
    protected:
        const string& getName() const { return brandName; }
        int getWheels() const { return wheels; }
        void setWheels(int wheelsAmount) { wheels = wheelsAmount; }
    public:
        Vehicle(const string& name, const string& element, int wheels)
            : brandName(name), element(element), wheels(wheels) {}
        
};

class Boat : public Vehicle {
    private:
    public:
        Boat(const string& name, const string& element = "water", int wheels = 0)
            : Vehicle(name, element, wheels) {}
        void displayName() const { cout << getName() << endl; }
        void displayNameBoat(const Boat& other) { other.displayName(); }
        /* void displayNameCar(const Car& other) { other.displayName(); }
        This would not work since const Car& is a sibling class
        */ 
};

class Car : public Vehicle {
    private:
    public:
        Car(const string& name, const string& element = "land", int wheels = 4)
            : Vehicle(name, element, wheels) {}
        void displayName() const { cout << getName() << endl; }
        
};


int main() {
    Boat Baylinder("Bayliner", "water", 0);
    Boat Monaco("Monaco", "water", 0);
    Car Mercedes("Mercedes", "land", 4);
    
    // Mercedes.getName(); does not work since we are trying to access it from main()
    Baylinder.displayName(); 
    Baylinder.displayNameBoat(Monaco); // can access items of same class - not sibling class

}