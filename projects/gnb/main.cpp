// Side Project:

/*
Guts and Blackpowder through pure code. 

Future Scaling:
- ROLES:
    Chaplain, Musician, Sappers
- ZOMBIES:
    Zapper, Igniter, Cuirassier 
- INVENTORY:
    Deployables, 
- GENERAL:
    Random map generator, random miss chance (gun), charge
*/ 
#include "zombie.h"
#include "weapon.h"
#include "survivor.h"
#include "map.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main() {
    // Initializaiton:
    vector<Survivor*> team; // use dynamic memory allocation for **new** survivors
    Map London("London");
    cout << London << endl; 
}