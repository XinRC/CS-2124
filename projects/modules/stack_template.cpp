#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class Stack{
    private:
        vector<T> stack_items;
        size_t length;
    public:
        Stack() : length(0) {} // constructor 
        Stack(const Stack& other) : { // copy constructor
            if (this != &other) {
                length = other.length;
                stack_items = other.stack_items;
            } 
            return *this;
        } 

        // methods 
        size_t size() const { return length; }
        bool isEmpty() const { return length == 0 ? true : false; }
        T peek() const { 
            if isEmpty(){
                throw out_of_range("The stack is empty");
            } return stack_items[length-1]; 
        }

        void push(const T& pushed_value) { 
            stack_items.push_back(pushed_value);
            ++length;
        }
        T pop() { 
            if isEmpty() {
                throw out_of_range("The stack is empty")
            }
            T popped_item = stack_items[length-1];
            stack_items.pop_back();
            --length; 
            return popped_item;
        }
};


int main() {
    cout << "=== TEST 1: INTEGER STACK ===" << endl;
    Stack<int> intStack;
    
    cout << "Pushing numbers: 10, 20, 30" << endl;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    cout << "Stack size: " << intStack.size() << endl;
    cout << "Top element: " << intStack.peek() << endl;
    
    cout << "\nPopping elements:" << endl;
    while (!intStack.isEmpty()) {
        cout << "Popped: " << intStack.pop() << endl;
    }
    
    cout << "\n=== TEST 2: STRING STACK (Browser History) ===" << endl;
    Stack<string> browserHistory;
    
    cout << "Visiting websites..." << endl;
    browserHistory.push("google.com");
    browserHistory.push("github.com");
    browserHistory.push("stackoverflow.com");
    
    cout << "Current page: " << browserHistory.peek() << endl;
    cout << "Going back..." << endl;
    cout << "Back to: " << browserHistory.pop() << endl;
    cout << "Now at: " << browserHistory.peek() << endl;
    
    cout << "\n=== TEST 3: CHAR STACK (Parentheses Checker) ===" << endl;
    Stack<char> charStack;
    string expression = "((a + b) * (c - d))";
    
    cout << "Checking expression: " << expression << endl;
    bool balanced = true;
    
    for (char ch : expression) {
        if (ch == '(') {
            charStack.push(ch);
        } else if (ch == ')') {
            if (charStack.isEmpty()) {
                balanced = false;
                break;
            }
            charStack.pop();
        }
    }
    
    if (balanced && charStack.isEmpty()) {
        cout << "Expression is balanced!" << endl;
    } else {
        cout << "Expression is NOT balanced!" << endl;
    }
    
    cout << "\n=== TEST 4: DOUBLE STACK (Calculator Memory) ===" << endl;
    Stack<double> calculatorStack;
    
    // Simulating calculator operations
    cout << "Entering numbers: 5.5, 3.2, 7.8" << endl;
    calculatorStack.push(5.5);
    calculatorStack.push(3.2);
    calculatorStack.push(7.8);
    
    cout << "Last entered: " << calculatorStack.peek() << endl;
    cout << "Undo last entry..." << endl;
    calculatorStack.pop();
    cout << "Now last entered: " << calculatorStack.peek() << endl;
    
    cout << "\n=== TEST 5: COPY STACK ===" << endl;
    Stack<int> originalStack;
    originalStack.push(100);
    originalStack.push(200);
    originalStack.push(300);
    
    // Create a copy
    Stack<int> copiedStack = originalStack;
    
    cout << "Original stack top: " << originalStack.peek() << endl;
    cout << "Copied stack top: " << copiedStack.peek() << endl;
    
    // Modify original
    originalStack.pop();
    cout << "\nAfter popping original:" << endl;
    cout << "Original stack top: " << originalStack.peek() << endl;
    cout << "Copied stack top: " << copiedStack.peek() << " (should still be 300)" << endl;
    
    return 0;
}