<div align = "center">

# Lecture 6
## Pointers

</div>


### Pointers
Pointers are variables that point at a specific memory address. By having access to the memory address, we are also able to access the value in the memory address. Do note that pointers are **type** sensitive, this means that if the memory address of variale `x` is a string, then the pointer must also be initialized as a string. If a pointer is not pointing anywhere, it is good practice to assign it as `nullptr`. 

<div align = "center">

| Pointer Keyword | Definition | 
| :---: | :--- | 
| `&` | When used before the value of a variable `&x`, it provides the memory address of the value at the variable |
| `*` | **Use 1:** Initializing variable as a pointer `int *p = &x` <br> **Use 2:** Dereference item to extract the value at the pointer `cout << *p;` |

</div>

Pointer Basics Example: 
```C++
int x = 17;

cout << &x << endl; // this provides us the memory address of the variable

int* p = &x; // initialize pointer p to an integer value address

cout << p << endl; // displays address (address of 17)
cout << *p << endl; // displays value (17)
```

Do note when initializing a pointer, the `*` is for the **first** variable to the right. This means `int* p, q` would **only** initalize `p` as an int pointer, not `q`. To initiate both as a pointer, we would do `int *p, *q`. The `*` is not required to be right after the data type, it is much clearer that `p` is a pointer when we put `*` right before the variable. 

#### Usage of `->` 
Given a class that has attributes or methods, say we want to access an object's attribute or use a method on the object with a pointer. There are two methods to use, with one being the "better" choice. 

1. (*pointerName).attribute/method()
2. pointerName `->` attribute/method()

The 2nd one looks much nicer and that is what is commonly used. 

#### Keyword `this`
The keyword `this` refers to the current object being called upon. This is similar to python's `self` parameter. We can use `this` to clarify when we are talking about the object's member/variable. 

---

### Association 
There will be a more in depth focus in the next lecture; however, a more brief introduction. Association is the relationship between 2 classes and utilizing a method from one class by the other class. 

---

### Const and Pointers
As stated before, `const` ensures that an item will not be modified. For pointers, there are 3 ways on where and what the `const` keyword do. 

1. `const int* p = &x;` : This means means the value of `x` is a constant. We are **only** able to change the address, not the value.
2. `int* const p = &x;` : This means that the variable `p` is a constant. We are **only** able to change value, not the address. 
3. `const int* const p = &x;` : This means both the value of `x` and the variable `p` are constants.

To better explain it, look at the following code. 
```C++
const int* p = &x; // allows us to change the address ONLY
p = &y; // works
*p = 42; // does NOT work

int const *q = &x; // allows us to change the value at the address ONLY
q = &y; // does NOT work
*q = 42; // works

const int* const r = &x; // cannot change anything
r = &y; // does NOT work
*r = 42; // does NOT work
```

---

### Dynamic Memory
Other names for it includes: "heap" or "free store", and it is a part of the memory that is considered permananent - at least until the program ends. Below are some of the uses and calls for the heap.

<div align = "center">

| Keyword/Term | Definition | 
| :---: | :--- | 
| `new` datatype() | Creates a new entry into the heap with the datatype of whatever you assign it. The keyword returns an address so we need to immediately assign it to a pointer. |
| `delete` pointerName | This deletes the item from the heap, freeing up the memory. However, the pointer still points at the item in the heap despite it not existing. To combat this, we can manually set the pointer to `nullptr` | 
| Dangling Pointer | Refers to a pointer that is pointing at a spot in the heap that no longer exist. These pointers should be set to `nullptr` as a good practice. | 

</div>

---

### Filling Vector Using Pointers
The [site](https://cse.engineering.nyu.edu/jsterling/cs2124/LectureNotes/03.Pointers.html#this) offers an easly comprehension on how to correctly fill vectors using pointers.
