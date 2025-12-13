// set
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> set = {1,4,3,2,5,6,5};
    set.insert(7);
    set.insert(1);
    set.erase(4);
    
    // automatically sorted
    for (int value : set) { 
        cout << value << " "; 
    }
} // items in sets can only be in the set once. 