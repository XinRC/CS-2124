#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    auto find_ex = find(v.begin(), v.end(), 3);
    if (find_ex != v.end()) {
        cout << *find_ex << endl; // prints "3" 
    }
}

/* other algorithms
find_if(begin, end, lambda func)
find_if_not(begin, end, lambda func)
search(begin, end, pattern's begin, pattern's end) // given a subsequence pattern
find_end(begin, end, pattern's begin, pattern's end) // to find the last subsequence pattern
count(begin, end, value)
count_if(begin, end, lambda expression)
*/