// linked list
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst = {1,2,3,4,5};
    lst.push_front(0);
    lst.push_back(6);

    for (int value: lst) {
        cout << value << " -> "; 
    } cout << "end"; 
}