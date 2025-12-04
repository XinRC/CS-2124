#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

namespace Land_Vehicle_Namespace {
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
}
#endif