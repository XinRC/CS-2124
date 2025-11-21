// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    friend ostream& operator<<(ostream& os, const List& rhs) { 
        // output operator; print item all data of linked list
        List::Node* curr = rhs.header->next; // creating traversal node
        while (curr != rhs.trailer) {
            os << curr->data; // data of the current traversal
            if (curr->next != rhs.trailer) {
                os << " "; 
            }
            curr = curr->next; 
        }
        return os;
    }

    private:
        struct Node { // nodes 
            int data = 0;
            Node* prev = nullptr;
            Node* next = nullptr; 
        };
        Node* header;
        Node* trailer;
        size_t llist_size;

    public:
    // ------------------- TASK ONE ------------------- //
        List() : llist_size(0) { // default constructor
            header = new Node;
            trailer = new Node{0, nullptr, header};
            header->next = trailer;
            trailer->prev = header;
        }

        void push_back(int data) { //
            Node* newNode = new Node{data, trailer->prev, trailer};
            trailer->prev->next = newNode; // set trailer's prev's next to new
            trailer->prev = newNode;
            ++llist_size;
        }

        void pop_back() {
            if (llist_size > 0) { // make sure ll_list is not just header/trailer
                Node* last = trailer->prev;
                last->prev->next = trailer; // set last's prev item to trailer
                trailer->prev = last->prev; // vice verse to above
                delete last; // not returning anything
                --llist_size; 
            }
        }

        int& front() { return header->next->data; } // non const front

        const int& front() const { return header->next->data; } // const front

        int& back() { return trailer->prev->data; } // non const back

        const int& back() const { return trailer->prev->data; } // const back

        size_t size() const { return llist_size; }

    // ------------------- TASK TWO ------------------- //
    void push_front(int data) {
        Node* newNode = new Node{data, header, header->next};
        header->next->prev = newNode;
        header->next = newNode; 
        ++llist_size;
    }

    void pop_front() {
        if (llist_size > 0) {
            Node* first = header->next; 
            header->next = first->next; 
            first->next->prev = header;
            delete first;
            --llist_size;
        }
    }

    void clear() {
        while (llist_size > 0) {
            pop_back(); 
        }
    }

    // ------------------- TASK THREE ------------------- //
    // just for traversal
    int& operator[](size_t index) { // no longer check for size cause return issue
        Node* curr = header->next;
        for (size_t i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    const int& operator[](size_t index) const {
        Node* curr = header->next;
        for (size_t i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    // ------------------- TASK FOUR ------------------- //
    class iterator {
        friend class List;
        private:
            Node* current;
        public:
            iterator(Node* node = nullptr) : current(node) {} // current instance
            iterator& operator++() {
                current = current->next;
                return *this;
            }
            iterator& operator--() {
                current = current->prev;
                return *this;
            }
            friend bool operator==(const iterator& curr_node, const iterator& other_iter) { 
                return curr_node.current == other_iter.current; }

            friend bool operator!=(const iterator& curr_node, const iterator& other_iter) { 
                return curr_node.current != other_iter.current; } 

            int& operator*() const { return current->data; }
    };
    
    // List's begin / end
    iterator begin() {
        return iterator(header->next); // start at beginning
    }
    iterator end() {
        return iterator(trailer); // past the last node
    }
    // ------------------- TASK FIVE ------------------- //
    iterator insert(iterator itr, int data) {
        Node* newNode = new Node{data, itr.current->prev, itr.current}; // create new for insert item
        itr.current->prev->next = newNode; // rearrange sequence
        itr.current->prev = newNode; 
        ++llist_size;
        return iterator(newNode);
    }
    // ------------------- TASK SIX ------------------- //
    iterator erase(iterator itr) {
        // make sure itr not the head or trail (also that there is nodes in llist)
        if (llist_size == 0 || itr.current == header || itr.current == trailer){
            return end();
        }
        Node* toBeDeleted = itr.current; 
        iterator result(toBeDeleted->next); // creating iterator for current's next
        toBeDeleted->prev->next = toBeDeleted->next; // rearranging sequence
        toBeDeleted->next->prev = toBeDeleted->prev; 

        delete toBeDeleted; 
        --llist_size;
        return result; 
    }

};

// Task 1
void printListInfo(const List& myList) { // DONE
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// Does not compile because of the const in the front 
/*
void changeFrontAndBackConst(const List& theList) {
    theList.front() = 17;
    theList.back() = 42;
}
*/

// compiles
void changeFrontAndBack(List& theList) {
    theList.front() = 17;
    theList.back() = 42;
}


// Task 4 --> actually for task 3
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}
/*
// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}    
*/
int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    
    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    printListInfo(myList);
    cout << "===================\n";

    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1; // use the non const
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";


    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";
    /* // ================================================ >

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
    */ // ================================================ > 
}
