// Sample 2

/*
Sample code for Vector Iterators
The .cpp  will go over how to utilize forward iterators on vectors.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6};
    vector<int>::iterator dataPtr;

    for (dataPtr = data.begin(); dataPtr != data.end(); ++dataPtr) {
        cout << *dataPtr << endl; 
    }

}