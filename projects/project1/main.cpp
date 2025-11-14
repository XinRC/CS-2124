// Side Project 1:

/*
Guts and Blackpowder through pure code. 

Future Scaling:
- ROLES:
    Chaplain, Musician, Sappers
- ZOMBIES:
    Zapper, Igniter, Cuirassier 
- INVENTORY:
    Deployables, 
- GENERAL:
    Random Map Generator
*/ 

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

// ============================SURVIVOR CLASS============================ //
class Survivor {
    private:
        string survivor_class; 
        double health; 
        bool is_injured; 
        vector<Weapon*> inventory;

    public:
        Survivor(const string& survivor_class, double health = 100) 
            : survivor_class(survivor_class), health(health), is_injured(false) {}

        // big three:
        ~Survivor() {
            for (size_t i = 0; i < inventory.size(); ++i) {
                delete inventory[i];
                inventory[i] = nullptr;
            } 
            inventory.clear();
        }
        Survivor(const Survivor& other) 
            : survivor_class(other.survivor_class), health(other.health), 
                is_injured(false) {}
        Survivor& operator=(const Survivor& other) {
            if (this != &other) {
                survivor_class = other.survivor_class; 
                health = other.health;
                is_injured = false; 
            } return *this; 
        }
        // methods: (attacking), holdfast/charge/ lose health

        void loseHealth(double health_deduction) { health - health_deduction; }

}; // survivor 

class Infantry : public Survivor {
    public:
        using Survivor::Survivor; 
}; // infantry 

class Officer : public Survivor {
    public:
        using Survivor::Survivor; 
        // charging 
}; // officer

class Seaman : public Survivor {
    public:
        using Survivor::Survivor; 
}; // seaman

class Medic : public Survivor {
    private: 

    public:
        using Survivor::Survivor; 
        // get supplies 
        // heal 

}; // medic 

// ============================WEAPON CLASS============================ //
class Weapon {
    private:
        string weapon_name; 
        double damage; 
    public:
        Weapon(const string& name, double damage) 
            : weapon_name(name), damage(damage) {}
        double doDamage() { return damage; }
}; // weapon

class Gun : public Weapon {
    private:
        bool shoot_twice;
        double reload_speed;
    public:
        Gun(const string& name, double damage, bool reload_speed, bool shoot_twice = false) 
            : Weapon(name, damage), reload_speed(reload_speed), shoot_twice(shoot_twice) {}
}; // gun

class Melee : public Weapon {
    private:
        bool can_hold_fast; 
    public:
        Melee(const string& name, double damage, bool can_hold = false ) 
            : Weapon(name, damage), can_hold_fast(can_hold) {}
}; 

// ============================ZOMBIE CLASS=========================== //
// Zombie Class -> Shambler, Runner, Bomber
class Zombie {
    private:
        string zombie_name;
        double health;
        double damage_inflicted;
    public:
        Zombie(const string& name, double damage, double health = 0)
            : zombie_name(name), damage_inflicted(damage) {}

        // Big Three: 
        ~Zombie() {}
        Zombie(const Zombie& other) 
            : zombie_name(other.zombie_name), damage_inflicted(other.damage_inflicted) {}
        Zombie& operator=(const Zombie& other) {
            zombie_name = other.zombie_name;
            damage_inflicted = other.damage_inflicted; 
        }
}; // zombie

class Shambler : public Zombie {
    private:
    public: // method grab, hit
        Shambler(const string& name) 
            : Zombie(name, 20, 100) {}
        void grab(const Survivor& survivor) { }
}; // shambler

class Runner : public Zombie {
    private:
    public: // methods: tackle
        Runner(const string& name) 
        : Zombie(name, 35, 50) {}
}; // runner

class Bomber : public Zombie {
    public: // methods: blow up 
        Bomber(const string& name, double damage) 
            : Zombie(name, 0, 1) {}
}; // bomber

// =============================MAP CLASS============================= //
class Map {
    friend ostream& operator<<(ostream& os, const Map& rhs) {
        os << "( Loading " << rhs.map_name << "... )";
        return os;
    }
    private:
        string map_name;
    public:
        Map(const string& map_name) : map_name(map_name) {}
}; // map

// ============================MAIN/FUNCS============================ //
int main() {
    // Initializaiton:
    vector<Survivor*> team; // use dynamic memory allocation for **new** survivors
    Map London("London");
    cout << London << endl; 
}