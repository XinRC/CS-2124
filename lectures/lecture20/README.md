<div align="center">

# Lecture 20
## Inheritance: Multiple Inheritances
## Linked List: Basics

</div>

### Inheritance: Multiple Inheritances:

Allows a class to inherit from more than just one base class.

```C++
class Base0 {};
class Base1 : public Base0 {};
class Base2 : public Base 0 {};
class Derived : public Base1, public Base2 {};

```

Diamond Problem and Virtual Inheritance is when a class inheritates the same grandparents from their parent class. For example, if both parents have the same grandparents, the derived class if trying to call a grandparent method would have to specify which method they want to use, whether to use `Base1::Base0` or `Base2::Base0` - especially when the grandparent has a data value then both `Base1::Base0` and `Base2::Base0` must be specified. Instead we can use:

```C++
class Base0 {};
class Base1 : virtual public Base0 {};
class Base2 : virtual public Base0 {};
class Derived : public Base1, public Base2 {};
```

This tells C++ that we only want **one** shared instance of the Base0 for Derived.

For constructors, likewise the leftmost parent class will be initalized faster than the one to its right. This means for Derived, Base1 will be initalized before Base2. 

However this also means we must initalize all parent/grandparent for the derived class's constructor. Ultimately the rule is to **always** initalized parents and **sometimes** the `virtual` grandparents in the constructor. Aka if you have multiple parents, intialize them, if you have `virtual` grandparents, initalize them, `nonvirtual` grandparents, do NOT initate them. 


### Linked List: Basics:

Instead of using arrays or vectors, linked lists can help minimize different strains like faced by arrays/vectors:

- No out-of-bounds check
- Passing an array to a function requires passing the size
- Must know size when we write the program

OVerall using dynamic arrays can be slow if we keep adding/removing items from inside the container

To create a linked list we can use pointers since we are supposed to **point** at an item. But first we need nodes that hold data, we can implement this using a struct.

```C++
struct Node {
    int data;
    Node* next;
    Node* before; 
}
```

Some required functionalities include:

- length
- find an element that has a particular value
- insert a value at the beginning / head
- remove head
- remove other than head 
- remove the first element in the list that has a particular value
- remove all elements from a list
- create a copy of a list
- append one list onto another (non destructive)