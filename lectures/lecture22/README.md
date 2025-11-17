<div align = "center" >

# Lecture 21
# Vector Iterators 

</div>

As known, the standard template library (by using `std`) hosts many tools and items to use. One of them being iterators. Iterators are used for traversal - but this file will only focus on the **forward iterator**. 

The first step is to declare an iterator - each container must use their own iterator. The syntax would look like:

```C++
vector<int>::iterator p; 
```

Every contain has two methods, `begin` and `end` that returns iterators. Obviously, `begin` returns the iterator that points to the first element, and `end` returns the iterator that points **past** the last element. Given that we have already initalized the above vector, we can traverse and display our iterator in a very specific way:
```C++
vector<int>::iterator p = v.begin();
cout << *p << endl; // displays the value at iterator
++p; // traversing by 1
cout << *p << end; 
```

Likewise, some may ask what is the point of the `.end()` method if it points **past** the last element, well it can be used as the condition for loops. 