// stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << "TOP: " << stack.top() << endl;
    stack.pop(); // removes the top-most item

    while(!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}