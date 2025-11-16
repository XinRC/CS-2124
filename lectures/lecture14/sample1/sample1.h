#ifndef SAMPLE1_H
#define SAMPLE1_H
#include <iostream>
#include <string>

class Land_Vehicle {
    private:
        std::string name;
        int wheel_amount;
    public:
        // using forward declaration
        Land_Vehicle(const std::string& name, int wheel_amount); 
        void display_name() const;
        int get_wheel_amount() const;
        void set_wheel_amount(int wheels);
};

#endif