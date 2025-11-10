// Sample 1

/*
Sample code for Inheritance: Multiple Inheritances
The .cpp will go over the utilization of multiple inheritances - particularly for the diamond problem and 
how to resolve that issue using virtualization of the grandparent class. 
*/


#include <iostream>
#include <string>
using namespace std;

class USMilitary {
    private:
        string rank;
    public:
        USMilitary(const string& rank) : rank(rank) {}
        const string& getRank() const { return rank; }
        virtual void deployment() = 0;
}; // USMilitary

void USMilitary::deployment() { cout << "Getting deployed by sea." << endl; } // USMilitary Method

class Army : virtual public USMilitary {
    private:
        string regiment;
    public:
        Army(const string rank, const string regiment) 
        : USMilitary(rank), regiment(regiment) {}
        const string getRegiment() const { return regiment; }
        virtual void deployment() { cout << "Getting deployed by land." << endl; }
}; // Army

class SpecialForces : virtual public USMilitary {
    private:
    public:
        using USMilitary::USMilitary;
        virtual void deployment() { cout << "Getting deployed by air." << endl; }
}; // SpecialForces

class Rangers : public Army, public SpecialForces {
    private:
    public:
        Rangers(const string& rank, string regiment = "75th") 
            : USMilitary(rank), Army(rank, regiment),
                SpecialForces(rank) {}
        void deployment() { Rangers::SpecialForces::deployment(); } // calls SpecialForce's deployment method
}; // Rangers 


int main() {
    Rangers Alex("Captain", "75th" );
    cout << Alex.getRank() << " of the " << Alex.getRegiment() << " Regiment." << endl; 
    Alex.deployment();
} // main