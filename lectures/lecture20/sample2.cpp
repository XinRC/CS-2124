// Sample 2

/*
Sample code for Linked List: Basics
The .cpp  will go over the basics of a Linked Lists Implementation for C++.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;

    Node(int value) : data(value), previous(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), length(0) { 
        Node* current = other.head;
        while (current != nullptr) {
            append(current->data);
            current = current->next;
        }
    }

    // assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                append(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    ~LinkedList() { clear(); }

    void append(int value) {
        Node* newNode = new Node(value); 
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        } 
        length++;
    }

    int getLength() const { return length; }

    Node* find(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; 
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        length++; 
    }

    bool removeHead() {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->previous = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        length--;
        return true;
    }

    bool removeAt(int position) {
        if (position < 0 || position >= length) {
            return false;
        }

        if (position == 0) {
            return removeHead();
        }

        if (position == length - 1) {
            return removeTail();
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        length--;
        return true;
    }

    bool removeValue(int value) {
        if (head == nullptr) {
            return false;
        }

        if (head->data == value) {
            return removeHead();
        }

        if (tail->data == value) {
            return removeTail();
        }

        Node* current = head->next; 
        while (current != nullptr && current != tail) {
            if (current->data == value) {
                current->previous->next = current->next;
                current->next->previous = current->previous;
                delete current;
                length--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    
    bool removeTail() {
        if (tail == nullptr) return false;
        
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete temp;
        }
        length--;
        return true;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        length = 0;
    }

    LinkedList copy() const {
        return LinkedList(*this);
    }

    
    LinkedList concatenate(const LinkedList& other) const {
        LinkedList result = this->copy();
        Node* current = other.head;
        while (current != nullptr) {
            result.append(current->data); 
            current = current->next;
        }
        return result;
    }

    void display() {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> "; 
            }
            current = current->next;
        }
        cout << " -> NULL" << endl;
        cout << "Length: " << length << endl; 
    }

    bool isEmpty() const {
        return head == nullptr;
    }  
};

int main() {
    // Test the implementation
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.display();
    
    list.insertAtHead(0);
    list.display();
    
    list.removeValue(2);
    list.display();
    
    return 0;
}