#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string> 

class Weapon {
    friend std::ostream& operator<<(std::ostream& os, const Weapon& rhs);

    private:
        std::string weapon_name; 
        double damage; 
    public:
        Weapon(const std::string& name, double damage);
        virtual std::ostream& displayStats(std::ostream& os) const = 0; 
        
        // getter / setters:
        const std::string& get_weapon_name() const;
        double get_damage()  const;
        double doDamage();
}; // weapon

class Gun : public Weapon {
    private:
        bool shoot_twice;
        double reload_speed;
    public: // shoot + reload, check stats, 
        Gun(const std::string& name, double damage, bool reload_speed, bool shoot_twice = false);
        std::ostream& displayStats(std::ostream& os) const;
}; // gun

class Melee : public Weapon {
    private:
        bool can_hold_fast; 
    public:
        Melee(const std::string& name, double damage, bool can_hold = false);
        std::ostream& displayStats(std::ostream& os) const;
}; // melee

#endif