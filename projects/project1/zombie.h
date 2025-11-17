#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Survivor;

class Zombie {
    friend std::ostream& operator<<(std::ostream& os, const Zombie& rhs);

    private:
        std::string zombie_name;
        double max_health; 
        double health;
        double damage_inflicted;
        bool is_alive = true;
    public:
        Zombie(const std::string& name, double damage, double health = 0);
        // Big Three: 
        ~Zombie() {}
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& other);

        // getter / setters:
        bool get_is_alive() const;
        void set_is_alive(bool is_alive);
        const std::string& get_name() const;

        // methods [M]
        void take_damage(float damage);
        virtual void attack(const Survivor& survivor) = 0;
}; // zombie

class Shambler : public Zombie {
    private:
    public: 
        Shambler(const std::string& name);
        void attack(Survivor& survivor);
}; // shambler

class Runner : public Zombie {
    private:
    public: 
        Runner(const std::string& name);
        void attack(Survivor& survivor);
}; // runner

class Bomber : public Zombie {
    public: // methods: blow up 
        Bomber(const std::string& name, double damage);
        void attack(Survivor& survivor);
}; // bomber


#endif