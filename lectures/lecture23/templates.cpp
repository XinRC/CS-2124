// Sample 2

/*
The .cpp will look into templates and their usage. Templates in C++ is very 
similar to operator overloading for different types. However instead of 
having different actions for each different type, no matter the type, the 
action would be the same
*/

#include <iostream>
using namespace std;

// creating the template
template <typename T>
void printingItem(T item) { cout << item << endl; }

int main() {
    printingItem(9.8);
    printingItem("Word");
    printingItem(6);
    printingItem(false);
}