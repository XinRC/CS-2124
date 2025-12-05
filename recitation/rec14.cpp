/*
  rec14_starter code
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>  // max
using namespace std;


// Node type for the linked list
struct Node {
    int data = 0;
    Node* next = nullptr;
};

// Node type for the ternary tree
struct TNode {
    int data = 0;
    TNode* left = nullptr;
    TNode* mid = nullptr;
    TNode* right = nullptr;
};



/////////////////////////////////////////////////////////////////////////
//
// Provided code for use in testing
//
void listPrint(const Node* headPtr);
void listClear(Node*& headPtr);
Node* listBuild(const vector<int>& vals);


//
// Your functions go here
//
//   Task 1 function:
Node* listSum(Node* list_1, Node* list_2) {
    // Base Case:
    if (list_1 == nullptr && list_2 == nullptr) {
        return nullptr;
    }
    // Recursive Condition:
    Node* newNode = new Node;
    
    if (list_1 != nullptr && list_2 != nullptr) { 
        // why segmentation fault when I do list_1 == nullptr to use list_2?
        newNode->data = list_1->data + list_2->data;
        newNode->next = listSum(list_1->next, list_2->next);
    } else if (list_1 != nullptr) {
        newNode->data = list_1->data;
        newNode->next = listSum(list_1->next, nullptr);
    } else {
        newNode->data = list_2->data;
        newNode->next = listSum(nullptr, list_2->next);
    }
    return newNode;
}

//   Task 2 function:
int treeMax(TNode* root) {
    if (root == nullptr) { // makes sure tree is not empty
        throw invalid_argument("There cannot be a maximum for an empty tree");
    }

    // Base Case:
    int max_value = root->data;

    // Recursive Case:
    if (root->left != nullptr) {
        max_value = max(max_value, treeMax(root->left));
    }
    if (root->mid != nullptr) {
        max_value = max(max_value, treeMax(root->mid));
    }
    if (root->right != nullptr) {
        max_value = max(max_value, treeMax(root->right));
    }
    return max_value;
}

//   Task 3 function:
bool palindrome(const char char_array[], int length) {
    // Base Case:
    if (length <= 1) {
        return true;
    }

    if (char_array[0] != char_array[length - 1]) { // checks if value not the same
        return false;
    }
    // Recursive Case: 
    return palindrome(char_array + 1, length - 2); 
}

//   Task 4 function:
bool parity(int value) {
    if (value < 0) { // makes sure value > 0
        throw invalid_argument("Must choose a value greater than 0");
    }
    // Base Case:
    if (value == 0) {
        return true;
    }
    bool sub_problem = parity(value / 2);

    // Recursive Case:
    if (value % 2 == 1) {
        return !sub_problem;
    } else {
        return sub_problem; 
    }
}

//   Task 5 function:
int towers(int n, char start, char spare, char end) {
    // Base Case:
    if (n == 1) {
        return 1; 
    }
    // Recursion Case:
    int move1 = towers(n-1, start, end, spare); // move disk start -> spare ; end is spare
    int move2 = 1; // move disk start -> end (count 1 move)
    int move3 = towers(n-1, spare, start, end); // move disk spare -> end ; start is spare

    return move1 + move2 + move3;
}


int main() {
    // We have provided some test code to save you time. Certainly feel
    // free to write more!

    // Task 1:
    cout << "\n==============\n#1: Testing listSum\n";
    Node* l1 = listBuild({2, 7, 1, 8});
    cout << "List (l1): ";
    listPrint(l1);
    
    Node* l2 = listBuild({9, 1, 4, 1});
    cout << "List (l2): ";
    listPrint(l2);

    Node* l3 = listBuild({3, 1, 4, 1, 5, 9});
    cout << "List (l3): ";
    listPrint(l3);

    cout << "The sum of l1 and l2: ";
    Node* l4 = listSum(l1, l2);
    listPrint(l4);

    cout << "The sum of l1 and l3: ";
    Node* l5 = listSum(l1, l3);
    listPrint(l5);

    cout << "The sum of l3 and l1: ";
    Node* l6 = listSum(l3, l1);
    listPrint(l6);

    listClear(l1);
    listClear(l2);
    listClear(l3);
    listClear(l4);
    listClear(l5);
    listClear(l6);
    
    // Task 2:
    cout << "\n==============\n"
         << "#2) Testing max of Tree.\n";
    //TNode a{1}, b{2}, c{4}, d{-8, &a, &b, &c}, e{-16}, f{-32, &d, &e};
    TNode a{1}, b{20}, c{4}, d{-8, &a, &b, &c}, e{-16}, f{-32, &d, &e};
    cout << "treeMax(&f): " << treeMax(&f) << endl;

    // How do you keep this from crashing? try/catch! Here in main!
    try {
        cout << treeMax(nullptr) << endl;
    } catch (const invalid_argument& e) { // could just do catch (...) but this more specific
        cout << "Caught exception of: " << e.what() << endl;
    }

    // Task 3:
    cout << "\n==============\n"
	 << "#3) Testing palindrome\n";
    cout << boolalpha
	 << "palindrome(\"racecar\", 7): " << palindrome("racecar", 7) << endl
	 << "palindrome(\"noon\", 4): " << palindrome("noon", 4) << endl
	 << "palindrome(\"raceXar\", 7): " << palindrome("raceXar", 7) << endl
	 << "palindrome(\"noXn\", 4): " << palindrome("noXn", 4) << endl;

    // Task 4:
    cout << "\n==============\n"
	 << "#4) Are there an even number of 1's in binary representation?\n";
    cout << boolalpha;
    for (int i = 0; i < 10; ++i) {
        cout << i << ": " << parity(i) << endl;
    }

    // Task 5:
    cout << "\n==============\n"
	 << "#5) How many moves are required for various sized towers?";
    for (int i = 1; i < 30; ++i) {
	cout << "towers(" << i << ", 'a', 'b', 'c'): " 
	     << towers(i, 'a', 'b', 'c') << endl;
    }

    // Task 6:
    /*
    I was correct (for all the values I wrote ... aaacbcc) because it must 
    follow the path before it continues onto the next recursion call. For example, 
    it must first finish the path of the "a" before going down the "b" path
    */
}



//
// The provided utility functions:
//

// listPrint prints out the data values in the list.
// All the values are printed on a single line with blanks separating them.
void listPrint(const Node* headPtr)
{
    const Node* curr = headPtr;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
} // listPrint

// listClear frees up all of the nodes in list setting the the head
// pointer to null.
void listClear(Node*& headPtr)
{
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
} // listClear

// listBuild returns a list with the same values as in the vector.
Node* listBuild(const vector<int>& vals)
{
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
	result = new Node{vals[index-1], result};
    }
    return result;
} // listBuild
