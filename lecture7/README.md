<div align = "center"> 

# Lecture 7
## Pointers 2 

</div>

### Association vs. Composition 
When we want a class to utilize another class we defined, this is called composition (also called containment). As seen below, whenever we initialize a hero object, we ALWAYS also initiate a Comrades object. But this causes an issue, perhaps not every hero has a comrade (or starts out with one).
```C++
class Comrades {
};

class Hero {
public:
private:
  string name;
  Weapon primary;
}
```
So how can we resolve this issue to offer better handling between classes? Pointers! Instead of initalizing a class inside another class, we can initialize a pointer class - first pointed at null - later pointing at other items if necessary. 

```C++
class Comrades {
};

class Hero {
public:
private:
  string name;
  Comrades* pComrades = nullptr;
}
```

---

### Pointer Warnings:
There are a few warnings to heed when using pointers - especially with heaps.

1. Never `delete` a pointer twice - it will most likely crash your program. However, if your pointer is assigned `nullptr`, then it is not a big deal for you to delete it twice.
2. Memory leaks are horrible - it takes up a lot of space in the heap - never lose the address of an item on the heap. This means to make sure to keep a pointer pointing at the address and make sure to delete the item in the heap when you are done with it.
3. If a pointer is pointing at an item that no longer exist in the heap, be sure to set the pointer equal to `nullptr`.
4.  It is advised to not use multiple (2+) pointers pointing at the same memory address.  
