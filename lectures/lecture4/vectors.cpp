// Sample 1

/*
Sample code for Vectors
The .cpp will go over how to initialize vectors. There are two methods of start-initialization,
both will be discussed
*/

#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> numbers1(5,3);
    vector<int> numbers2{1, 2, 3, 4, 5};

    for(int num : numbers1) {
        cout << num << " ";
    }

    cout << endl;

    for(int num : numbers2) {
        cout << num << " ";
    }

}