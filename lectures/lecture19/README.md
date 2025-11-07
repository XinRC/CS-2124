<div align="center">

# Lecture 19
## Inheritance: Copy Control and Polymorphic Constructors

</div>

### Polymorphism inside Constructors

Polymorphism cannot exist inside constructors since constructors disregard any form of `virtual` methods. This means that if the constructor were to call a virtual method, it would not run the derived class's method but the base class's since the derived object would not have been created yet. To combat this issue, it is best to create an "initialize" method to manually initialize what needed to be done in the constructor, `sample1.cpp` provides an example of it. 

```C++
class Base {
    public:
        Base () {
            displayText();
        }
        virtual void displayText() { cout << "Base Method" << endl; }
        
};

class Derived : public Base {
    public:
        Derived() : Base() {}
        void displayText() { cout << "Derived Method" << endl; }

};

int main() {
    Derived der;
}

/* Output:
Base Method
*/
```

### Inherited Copy Controls

For inherited copy controls, only a few specific things need to be done for both the base/derived class. The requirements are as followed. 

1. Copy constructor for the **derived** class must be initalized by the **base** constructor using `: Base()`
2. Assignment operator for the **derived** class must call the **base** class's assignment operator (yes the base class would need a base assignment operator). This means within the **derived** class's overloading, the **base** class's assignment operator must be ran by using `Base::operator=();`
3. Destructor would be normal for the **derived** class, however; for the **base** class, the keyword `virtual` must be put in front of it to ensure the **derived** class's destructor also runs.

Examples for this topic is included in: `sample2.cpp` and `sample3.cpp`
