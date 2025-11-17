#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map {
    friend std::ostream& operator<<(std::ostream& os, const Map& rhs);
    private:
        std::string map_name;
    public:
        Map(const std::string& map_name);
}; // map

#endif