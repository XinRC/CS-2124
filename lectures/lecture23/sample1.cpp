// Sample 1

/*
The .cpp will look into the implementation of a linked list class
*/
#include <iostream>

class LinkedList {
    private:
        struct Node {
            int data;
            Node* prev;
            Node* next;

            Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) 
                : data(data), prev(prev), next(next) {}
        }; 
        Node* header;
        Node* trailer;
        size_t size;
    public:
        LinkedList() : size(0) {
            Node* header = new Node(0, nullptr, trailer);
            Node* trailer = new Node(0, header, nullptr);
        }
        // methods: 


};