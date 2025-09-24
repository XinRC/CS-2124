<div align = "center">

# Lecture 6
## Pointers

</div>

>[!Important]
>Need to work on -> was absent so gotta do own study

### Pointers

To initialize a pointer, which points at a memory address, you need to use `&` to get the address, and `*` for the dereference item. Do note that pointers are **type** sensitive, this means that if the memory address of variale `x` is a string, then the pointer must also be initalied as a string. If a pointer is not pointing anywhere, then we will assign it `nullptr`. Using `*p` gives us the value on what is in that memory address. The term `this` refers to the current object. 

```C++
int x = 17;
cout << &x << endl; // this provides us the memory address of the variable

int* p = &x; // initalize the variable p to the address of x. The * represents that the variable is a pointer.
```

### Const referencing of Pointers 
The below shows "when and why" to use `const` before a certain keyword. 
```C++
const int* p = &x // this shows that the address for the data "x" will not change
int* const q = &x // this makes sure that the variable "q" will not change.
const int* const r = &x // cannot change anything
```

```C++

```


