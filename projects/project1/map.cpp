#include "map.h"
#include <iostream>
using namespace std;

Map::Map(const std::string& map_name) : map_name(map_name) {}

ostream& operator<<(ostream& os, const Map& rhs) {
    os << "( Loading " << rhs.map_name << "... )";
    return os;
}

