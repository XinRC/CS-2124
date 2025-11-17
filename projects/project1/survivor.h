#ifndef SURVIVOR_H
#define SURVIVOR_H

#include <iostream>
#include <vector>
#include <string>

class Weapon;
class Zombie;

class Survivor {
    friend std::ostream& operator<<(std::ostream& os, const Survivor& rhs);

    private:
        std::string name; 
        std::string survivor_class; 
        double max_health;
        double health; 
        bool health_full = true; 
        bool is_alive = true; 
        std::vector<Weapon*> inventory;

    public:
        Survivor(const std::string& name, const std::string& survivor_class, double max_health);

        // big three:
        ~Survivor();
        Survivor(const Survivor& other); 
        Survivor& operator=(const Survivor& other);
        
        // getters / setters
        bool is_health_full() const;
        bool get_is_alive() const;
        void set_is_alive(bool status);
        double get_max_health() const;
        double get_health() const;
        void set_health(double amount);

        // methods [M]
        void loseHealth(double health_deduction);
        void attack(Weapon& weapon, Zombie& zombie);
}; // survivor 

class Infantry : public Survivor {
    public:
        Infantry(const std::string& name);
}; // infantry 

class Officer : public Survivor {
    private: 
        const int charging_queue = 5;
        int current_charge_amount = 0;
    public:
        Officer(const std::string& name);
        void gain_charge();
}; // officer

class Seaman : public Survivor {
    public:
        Seaman(const std::string& name);
}; // seaman

class Medic : public Survivor {
    private: 
        double supplies_amount; 
        const double max_supplies_amount = 400;
    public:
        Medic(const std::string& name) : Survivor(name, "Medic", 90), supplies_amount(max_supplies_amount) {}
        void get_supplies(double amount) { supplies_amount += amount; } 
        void healing_survivor(Survivor& survivor);
}; // medic 


#endif