// Sample 1

/*
Sample code for Pointers: Smart Pointers
Although not on the exam, this .cpp will go over modern smart pointers that automatically clear the heap when the 
object goes out of the scope - a rather useful tool. However, to use smart pointers, we must include <memory>
*/ 
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class BodiesOfWater{

    friend ostream& operator<<(ostream& os, const BodiesOfWater& rhs) {
        os << rhs.name << " is ";
        if (rhs.saltWater != true) {
            os << "not ";
        } os << "salt water." << endl; 
        return os; 
    }

    private:
        string name;
        bool saltWater;
    public:
        BodiesOfWater(const string& name, bool saltWater) 
            : name(name), saltWater(saltWater) {}

        const string& getName() const { return name; }
        void startSwimming() { cout << "Swimming in the " << name << endl; }
};

int main() {
    vector<unique_ptr<BodiesOfWater>> water; // new vector syntax 

    // initialize smart pointers
    unique_ptr<BodiesOfWater> Lake = make_unique<BodiesOfWater>("Lake", false);
    unique_ptr<BodiesOfWater> Ocean = make_unique<BodiesOfWater>("Ocean", true);
    unique_ptr<BodiesOfWater> River = make_unique<BodiesOfWater>("River", false);

    /* 
    Need to use move() since unique_ptrs cannot be copied. This means we either use
    move() or we directly push the initalization (make_unique<...>(...)) into 
    the vector, see below comment for implementation. 
    */
    // water.push_back(make_unique<BodiesOfWater>("Sea", true)); 
     
    water.push_back(move(Lake));
    water.push_back(move(Ocean));
    water.push_back(move(River));

    for (size_t i = 0; i < water.size(); i++) {
        water[i]->startSwimming(); 
    }

    // Should automatically clear heap since we are using a smart pointer
}