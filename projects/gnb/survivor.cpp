#include "survivor.h"
#include "weapon.h"
#include "zombie.h"

#include <iostream>
#include <vector>
using namespace std; 

// constructor
Survivor::Survivor(const string& name, const string& survivor_class, double max_health) 
    : name(name), survivor_class(survivor_class), health(max_health), max_health(max_health) {}

// big three
Survivor::~Survivor() {
    for (size_t i = 0; i < inventory.size(); ++i) {
        delete inventory[i];
        inventory[i] = nullptr;
    } 
    inventory.clear();
}
Survivor::Survivor(const Survivor& other) 
    : name(other.name), survivor_class(other.survivor_class), health(other.health), max_health(other.max_health) {}

Survivor& Survivor::operator=(const Survivor& other) {
    if (this != &other) {
        name = other.name; 
        survivor_class = other.survivor_class; 
        health = other.health;
        max_health = other.max_health; 
    } return *this; 
}

ostream& operator<<(ostream& os, const Survivor& rhs) { 
    os << "(" << rhs.name << ": " << rhs.health << "/" << rhs.max_health << ")";
    return os;
}

// getter / setters 
bool Survivor::is_health_full() const { return health_full; } 
bool Survivor::get_is_alive() const { return is_alive; }
void Survivor::set_is_alive(bool status) { is_alive = status; }
double Survivor::get_max_health() const { return max_health; }
double Survivor::get_health() const { return health; }
void Survivor::set_health(double amount) { health = amount; } 

// methods [M]
void Survivor::loseHealth(double health_deduction) { // [M] heath deduction
    if (is_alive){
        health -= health_deduction;
        if (health <= 0) {
            is_alive = false;
            cout << "\t" << name << " has died.";
        } 
    } else {
        cout << "\t" << name << " is already dead.";
    }

} 
void Survivor::attack(Weapon& weapon, Zombie& zombie) { // [M] attacking zombie
    if(is_alive) {
        if (zombie.get_is_alive()) {
            zombie.take_damage(weapon.doDamage());
        } else {
            cout << "\t The" << zombie.get_name() << " is already dead.";
        }
    }
}

// ======================== CHILD CLASSES ======================== //

Infantry::Infantry(const string& name) : Survivor(name, "Infantry", 110) {}

Officer::Officer(const string& name) : Survivor(name, "Officer", 110) {}
void Officer::gain_charge() { // [M] gain +1 charge point
    if (current_charge_amount < charging_queue) {
        current_charge_amount += 1; 
        return;
    }
    return;
}

Seaman::Seaman(const string& name) : Survivor(name, "Seaman", 100) {}

Medic::Medic(const string& name) : Survivor(name, "Medic", 90), supplies_amount(max_supplies_amount) {}
void Medic::get_supplies(double amount) { // [M] get supplies
    double addable_amount = max_supplies_amount - supplies_amount;
    if (amount >= addable_amount) {
        supplies_amount += amount; 
    } return; 
} 
void Medic::healing_survivor(Survivor& survivor) { // [M] heal survivor
    if (survivor.is_health_full()) {
        return;
    }
    double needed_health = survivor.get_max_health() - survivor.get_health();
    if (supplies_amount != 0) {
        if (supplies_amount > needed_health) {
            supplies_amount -= needed_health;
            survivor.set_health(survivor.get_max_health());
        } else if (supplies_amount < needed_health) {
            survivor.set_health(survivor.get_health() + supplies_amount);
            supplies_amount = 0; 
        } 
    }
}
