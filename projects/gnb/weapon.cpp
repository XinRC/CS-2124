#include "weapon.h"

#include <iostream>
#include <vector>
using namespace std; 

// constructor 
Weapon::Weapon(const std::string& name, double damage) : weapon_name(name), damage(damage) {}

ostream& operator<<(std::ostream& os, const Weapon& rhs) { // gun/melee have different outputs
    rhs.displayStats(os);
    return os;  
}

// getters / setters
const string& Weapon::get_weapon_name() const { return weapon_name; }
double Weapon::get_damage()  const { return damage; }

// methods [M]
double Weapon::doDamage() { return damage; } // [M] do damage

// ======================== CHILD CLASSES ======================== //

Gun::Gun(const std::string& name, double damage, bool reload_speed, bool shoot_twice = false) 
    : Weapon(name, damage), reload_speed(reload_speed), shoot_twice(shoot_twice) {}
ostream& Gun::displayStats(std::ostream& os) const {
    os << "(" << get_weapon_name() << "| DMG: " << get_damage() << "| Reload Speed: " << reload_speed;
    return os; 
}

Melee::Melee(const std::string& name, double damage, bool can_hold = false) 
    : Weapon(name, damage), can_hold_fast(can_hold) {}
ostream& Melee::displayStats(std::ostream& os) const {
    os << "(" << get_weapon_name() << "| DMG: " << get_damage();
    return os;
}
