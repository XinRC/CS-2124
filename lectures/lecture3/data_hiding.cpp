// Sample 1

/*
Sample code for Encapsulation and Data Hiding
For this .cpp file, although ceratinly structs can be used for encapsulation and 
data hiding, it is most often associated with classes. 

Items from the private parts of the class is untouchable by every element BESIDES
items within the same class. This is the essence of encapsulation and data hiding.
*/
#include <iostream>
#include <string>
using namespace std;

class WaterBottles{
    friend ostream& operator<<(ostream& os, const WaterBottles& rhs);

    private:
        string name;
        int ounces;

    public:
        WaterBottles(const string& name, int ounces) : name(name), ounces(ounces) {}
        const string getName() const { return name; }
        int getOunces() const { return ounces; }
        void setOunces(int newOunce) { ounces = newOunce; }
}; // WaterBottles 



int main() {
    WaterBottles Yeti("Yeti", 40);

    // required to use a getter/setter function to access the variable data
    cout << Yeti << endl;
    Yeti.setOunces(50);
    cout << "[NEW] " << Yeti << endl;

} // main

ostream& operator<<(ostream& os, const WaterBottles& rhs) {
    os << rhs.name << " has a bottle of " << rhs.ounces << "oz.";
    return os;
} // ostream << 