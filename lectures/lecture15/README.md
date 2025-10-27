<div align="center">

# Lecture 15 
## Inheritance: Substituability, Slicing, and Polymorphism 

</div>


### Overview  
This document explores three key aspects of inheritance in C++:  
1. **Substitutability** — The principle that a derived object can be used wherever a base object is expected.  
2. **Slicing** — The loss of derived class information when assigning or copying derived objects into base class objects.  
3. **Polymorphism** — The mechanism that allows objects of different derived types to behave differently when accessed through base class pointers or references.

---

### 1. Substitutability  

#### Definition  
Substitutability is a cornerstone of inheritance. It states that **anywhere a base object is expected, a derived object can be substituted**. This principle supports the idea that a derived class **is-a** base class.

> **Principle of Substitutability:**  
> Wherever you can use a `Base`, you should also be able to use a `Derived`.

### Example  
```cpp
class Animal {
public:
    virtual void eat() { cout << "Animal eating\n"; }
};

class Tiger : public Animal {
public:
    void eat() override { cout << "Tiger eating\n"; }
};

void feed(Animal& a) {
    a.eat();
}

int main() {
    Tiger tigger;
    feed(tigger);  // Valid substitution
}
```


## Slicing  

### Definition  
**Object slicing** occurs when a derived object is assigned or copied into a base object.  
Only the **base portion** of the derived object is copied, while all the extra data or overridden behavior specific to the derived class is lost. There is something called the **slicing problem**

### Example  
```cpp
class Base {
public:
    virtual void identify() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void identify() override { cout << "Derived\n"; }
    void extra() { cout << "Extra behavior\n"; }
};

int main() {
    Derived d;
    Base b = d;   // Slicing occurs here
    b.identify(); // Outputs: Base
}
```


---

### ⚙️ **Polymorphism**
markdown
## Polymorphism  

### Definition  
**Polymorphism** allows base class pointers or references to invoke the **correct overridden method** of a derived class at runtime.  
It is implemented through **virtual functions** in C++ and enables dynamic behavior.

### Example  
```cpp
class Animal {
public:
    virtual void eat() { cout << "Animal eating\n"; }
};

class Lion : public Animal {
public:
    void eat() override { cout << "Lion eating\n"; }
};

int main() {
    Lion simba;
    Animal* ptr = &simba;  // Base pointer to derived object
    ptr->eat();            // Outputs: Lion eating
}
```