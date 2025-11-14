// Sample 1

/*
Sample code for Pointers : Classes (->) and `this`
This .cpp will go over pointers for classes, specifically with a focus on the keyword `this` and a bit on (->). Do note that (->)
is most often used for dynamic memory 
*/
#include <iostream>
#include <string>
using namespace std; 

class Car {
    private:
        string name;
        string type;
    public: 
        Car(const string& name, const string& type) {
            this->name = name;
            this->type = type;
        } // instead of using this, we can also initalize it using : name(name), type(type), car_partner(nullptr) 
        void displayName() const { cout << name << endl; }
        void displayType() const { cout << type << endl; }
};

int main() {
    Car* gClass = new Car("Mercedes", "Luxury"); // dynamic memory item

    // calling methods on dynamic memory item using ->
    gClass->displayName();
    gClass->displayType();

    delete gClass; // must remember to delete the item
}