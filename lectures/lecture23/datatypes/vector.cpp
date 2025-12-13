// vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    nums.push_back(7);
    nums.push_back(8);
    nums.pop_back();

    for (int values : nums) {
        cout << values << " "; 
    }
} 