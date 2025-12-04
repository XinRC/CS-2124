// Sample 1

/*
Sample code for Functions, Classes, and Parameters.
Functions, classes, and parameters are relatively the same compared to that of python's. 
Though again, before creating a variable, you are required to state the data type of the 
variable. 

The return type "void" means we will not be returning anything. 
*/

#include <iostream>
#include <string>
using namespace std;

class ResidentEvil{
    private: // items under this can ONLY be called by this methods of this class
        string name;
        int rank;
    public: // items under this cause be called by any object
        ResidentEvil(const string& name) // this is a constructor, we will discuss it at a later time
            : name(name) {}

        void displayName() const { cout << "The game name is: " << name << endl; } // getter function (name)
        void displayRank() const { cout << "The rank is: "<< rank << endl; } // getter function (rank)
        void setRank(int rank) { this->rank = rank; } // setter function
        
        
};

int main() {
    ResidentEvil ResidentEvil4("Resident Evil 4"); // creating the class

    ResidentEvil4.displayName(); // displays the name 
    ResidentEvil4.setRank(1); // sets our rank 
    ResidentEvil4.displayRank(); // displays the rank
}