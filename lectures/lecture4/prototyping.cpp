// Sample 2

/*
Sample code for Prototyping
The .cpp file go over the basics of prototyping. Usually, we would want 
the main() function to the first function in the program, this can be done
using prototyping that allows functions required by main() to be initalized
before it is defined
*/
#include <iostream>
#include <string>
using namespace std;

int addingNumbers(int a, int b);
int subtractNumbers(int a, int b);

int main() {
    int numberAdd = addingNumbers(5,4);
    int numberSub = subtractNumbers(6, 8);
    cout << "Adding: " << numberAdd << endl;
    cout << "Subtracting: " << numberSub << endl;
}

int addingNumbers(int a, int b) {
    int temp = a + b;
    return temp;
}

int subtractNumbers(int a, int b) {
    int temp = a - b;
    return temp;
}