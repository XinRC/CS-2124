// Sample 1

/*
Sample code for Inheritance: Constructor, Override
The .cpp will gover inheritance with demonstrations on constructor of inherited 
classes and overriding of parent methods.
*/

#include <iostream>
#include <string>
using namespace std;

class Military {
    private:
        string terrain;
    public:
        Military(const string& terrain) : terrain(terrain) {}
        const string& getTerrain() const { return terrain; }
        // keyword 'virtual' lets us use derived class's method instead
        virtual void march() { cout << "Marching..." << endl; } 
};

class Army : public Military {
    private:
        string regiment;
    public: 
        // each derived class must have their own constructor
        Army(const string& regiment, const string& terrain = "land") 
            : Military(terrain), regiment(regiment) {}
        // by using the virtual keyword, we use the derived function instead
        void march() { cout << "Marching ... Army Style" << endl; }
};

int main() {
    Army army1("75th");
    army1.march(); // march like Army
    army1.Military::march(); // march like Military
}