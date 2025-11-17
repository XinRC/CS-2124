#include "zombie.h"
#include "survivor.h"

#include <iostream> 
#include <string>
using namespace std; 

// constructor
Zombie::Zombie(const std::string& name, double damage, double health = 0)
    : zombie_name(name), damage_inflicted(damage) {}

ostream& operator<<(ostream& os, const Zombie& rhs) {
    os << "(" << rhs.zombie_name << ": " << rhs.health << "/" << rhs.max_health << ")"; // (Zombie Name: health/max_health)
    return os;
}

// big three 
Zombie::Zombie(const Zombie& other) 
    : zombie_name(other.zombie_name), damage_inflicted(other.damage_inflicted) {}
Zombie& Zombie::operator=(const Zombie& other) {
    zombie_name = other.zombie_name;
    damage_inflicted = other.damage_inflicted; 
}

// getter / setters
bool Zombie::get_is_alive() const { return is_alive; }
void Zombie::set_is_alive(bool is_alive) { this->is_alive = is_alive; }
const string& Zombie::get_name() const { return zombie_name; }

// methods
void Zombie::take_damage(float damage) { // [M] take damage 
    if (is_alive) {
        health -= damage; 
        if (health <= 0) {
            is_alive = false; 
        }
    }
}

// ======================== CHILD CLASSES ======================== //

Shambler::Shambler(const std::string& name) : Zombie(name, 20, 100) {}
void Shambler::attack(Survivor& survivor) { // hitting
    if (survivor.get_is_alive()) {
        survivor.set_health(survivor.get_health() - 15);
    }
}

Runner::Runner(const std::string& name) : Zombie(name, 35, 50) {}
void Runner::attack(Survivor& survivor) { // tackle
    if (survivor.get_is_alive()) {
        survivor.set_health(survivor.get_health() - 30); 
    }
}

Bomber::Bomber(const std::string& name, double damage) : Zombie(name, 0, 1) {}
void Bomber::attack(Survivor& survivor) { // bomb
    if (survivor.get_is_alive()) {
        survivor.set_health(0);
        survivor.set_is_alive(false);
    }
}
