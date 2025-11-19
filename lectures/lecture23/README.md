<div align = "center"> 

# Lecture 23
## Standard Template Library

</div> 

### Standard Template Library

The purpose of the STL is to provide a *container* class that holds things of a given type - wthese containers can hold a variety of different data structures (an example we have previously used is the vector). Likewise, there are generic algorithms that work with different containers, but to use them, we must `#include <algorithm>`

To run the algorithms property, it is necessary to overload both `<` and `==` for the class, though the assignment operator, copy constructor, and default constructors are also often used. 

#### Containers

Main containers defined in the STL, there will be a focus on the stack and the vector. Do note that (other and a stack and a queue), STL containers make a **copy** of items when adding them or removing them from the container. 

| Item | Definition |
| :---: | :--- |
| Stack | Allows access only to the item at the top of the stack and removed from the top. Uses the ideology of first in, last out. | 
| Queue | Items are added to the back of a queue and removed from the front. Uses the ideolofy of first in, first out. | 
| Vector | Similiar to an array but it is capable of growing |
| Deque | A double ended queue, (pronounced as "deck") | 
| List | Provides a Doubly Linked List | 
| Set | Only one instance of an item can be in the set |
| Multiset | Similar to a set, but multiple instances may be in the container | 
| Map | Like a set, items are looked up with a key. Only one instance can exist in it at a given time | 
| Multimap | |Like a map but there could be multiple instances in one map |

#### Common Features

The STL container types all share certain operations in common - some shown below. (Note that `ContType` refer to the STL container type)

| Operation | Effect | 
| :--- | :---| 
| ContType c | Default constructor |
| ContType c1(c2) | Copy constructor | 
| ContType c(begin, end) | Constructor that uses iterators to begin and end (from another container) to identify the elements to include for `c` |
| c.size() | Returns the number of elements in the container | 
| c.empty() | Returns true if the size is 0 |
| c.begin() | Iterator that points to the beginning of `c` |
| c.end() | Iterator that points to the end of `c` |
| c1 == c2 | Tests if c1 is equal to c2, if they are the same size and their elements are equal | 
| c1 < c2 | Tests if c1 is less than c2 (lexicographically) | 
| c.clear() | Removes all elements, making the container empty |


### Stack

The stack is thought of having a definition like the one below:

```C+++
template <class T>
class stack { // definitions
    pulibc:
        void push(const T&);
        void pop();
        T& top();
        bool empty() const;
        size_t size() const;
}

int main() { // implementation
    stack<int> i_data;
    i_data.push(1);
    i_data.push(2);
    i_data.push(3);

    while (!i_data.empty()) {
        cout << i_data.top() << " ";
        i_data.pop();
    }
    cout << endl;
}
```

### Vectors

We have worked with vectors enough to have a good understanding of them. One thing to note, given a vector `v`, if you attempt to do `v[index]` where index is out of bounds or in general trying to access an invalid entry - no exceptions is thrown, the code will fail in an undefined way. We can use `v.at(index)` instead to catch an exception.

``` C++
vector<int> v;
try {
    cout << v.at(0) << endl; 
    catch (out_of_range e) {
        cout << "Caught out_of_range error\n";
    }
}
```


### Generic Algorithms

The generic algorithms provides us algorithms that we would otherwise have to code ourselves, such algorithm for sorting, searching, and making modification. Some algorithms will be discussed below.

#### Count

The `count` algorithm counts all the elements in a range that are equal to a specific value. It takes:

- an iterator pointing to the beginning
- an iterator pointing pass the end
- the target value 

```C++
int count_data = count(data, &data[size], 1);
```

#### Count_if
 
The `count_if` is very similar to the `count` algorithm, all it does it count up all the elements in a range that has a specific property. It takes three parameters:

- an iterator pointing to the beginning
- an iterator pointing pass the end 
- a boolean function that defines the property 

```C++
bool isEven(int item) {
    reeturn ((item % 2) == 0);
}

int count_data = count_if(data, &data[size], isEven);
```

Note how we are able to pass in a function into an argument. This hints at the, powerful, ability in C++ that allows the argument to point (using a pointer) to the function. 

##### Copy

The `copy` copies the elements from one range, the source, to another, the target. It also takes three parameters:

- an iterator pointing to the beginning
- an iterator pointing pass the end
- an iterator pointing to the beginning of the target range

```C+++
copy(v1.vegin(), v1.end(), v2.begin())
```
