// Sample 3

/*
Sample code for Polymorphism and Non-Members
*/
#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;
        string color;
    public:
        Car(const string& brand, const string& color) : brand(brand), color(color) {}
        const string& get_brand() const { return brand; }
        const string& get_color() const { return color; }
        void set_color(const string& color) { this->color = color; }
};

class Luxury : public Car {
    private:
        int year;
    public:
        Luxury(const string& brand, const string& color, int year) : Car(brand, color), year(year) {}
        int get_year() const { return year; }        
};

class Sports : public Car {
    private:
        bool modded;
    public:
        Sports(const string& brand, const string& color, bool modded = false)
            : Car(brand, color), modded(modded) {}
        bool get_modded() const { return modded; }
};

// non member methods
void display_luxury(const Luxury& car) {
    cout << "The " << car.get_color() << " " << car.get_brand() << " is made in " << car.get_year() << "." << endl;
}

void display_sports(const Sports& car) {
    string is_modded = "";
    if (car.get_modded() == false) {
        is_modded = " not";
    } 
    cout << "The " << car.get_color() << " " << car.get_brand() << " is" << is_modded << " modded." << endl;
}


int main() {
    Luxury mercedes_gullwing("Mercedes Benz", "black", 1956);
    Sports porsche_spyder("Porsche", "red", true);

    display_luxury(mercedes_gullwing);
    display_sports(porsche_spyder);
}