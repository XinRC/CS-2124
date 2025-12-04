
#include <iostream>
#include "vehicle.h"
using namespace std;

namespace Land_Vehicle_Namespace {
    Land_Vehicle::Land_Vehicle(const string& name, int wheel_amount) 
        : name(name), wheel_amount(wheel_amount) {}

    void Land_Vehicle::display_name() const { cout << name << "...Vrrrrrr" << endl; }
    int Land_Vehicle::get_wheel_amount() const { return wheel_amount; }
    void Land_Vehicle::set_wheel_amount(int wheels) { wheel_amount = wheels; }
}