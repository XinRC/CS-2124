#include <iostream>
#include "sample1.h"
using namespace std;
using namespace Land_Vehicle_Namespace; 

int main() {
    Land_Vehicle GullWing("Mercedes Gullwing", 3);
    GullWing.display_name();
    GullWing.set_wheel_amount(4);
    cout << "Gullwing wheel amount: " << GullWing.get_wheel_amount() << endl; 
}

/*
MacOS: g++ -std=c++17 *.cpp -o [.exe name]
Windows: g++ *.cpp -o [.exe name]

./[.exe name] to run the file
*/