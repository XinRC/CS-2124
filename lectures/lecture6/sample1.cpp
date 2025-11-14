// Sample 1

/*
Sample code for Pointers: Basics and Const
This .cpp will go over the bare-bones pointer basics. There will be further demonstration on classes (->) 
with pointers, dynamic memory, and smart pointers. 
*/
#include <iostream>
using namespace std;

int main() {
    cout << "======BARE BONES======" << endl;  
    int value = 6;
    int *p = &value; // p holds the address of value

    cout << p << endl; 
    cout << *p << endl; 
    cout << endl; 

    cout << "==CONST AND POINTERS==" << endl;
    int x = 5; 
    int y = 6;

    
    const int* v = &x; // allowed to only change the address
    v = &y; // works : changing the address
    // *v = 9; // does NOT work : changing the value

    int* const q = &x; // allowed to only change the value 
    // q = &y // does NOT work : changing the address
    *q = 93; // works: changing the value  

    const int* const g = &x; // does not allow to change anything
    // g = &x; // does NOT work : changing the address
    // *g = 3; // does NOT work : changing the value
}