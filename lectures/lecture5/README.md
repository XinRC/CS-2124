<div align = "center">

# Lecture 5
## Nested Classes

</div> 

### Nested Classes
Nesting classes is when a class is nested either in the `public` or `private` section of another class. Usually, they are found in the `public` section since it allows the main class easy access to the data and methods of the nested class. Do note that to use the inner class, we must initalize a variable and **make sure** that the class is defined before the initalization. For further demonstration, `sample1.cpp` and `sample2.cpp` are both examples of nested classes.

```C++
class Outer {
    private:
        Inner1 {};
    public:
        Inner2 {};
};
```

---

### Friending Functions
This allows an outside function to access materials from a private section. To use this, we must declare the function as a friend using the keyword `friend`. However, this should be done seldomly - only if absolutely needed. Do note that you can either write the friend function inside or outside the class. The syntax for the `<<` friend operator is below:

```C++
class Test {
    friend ostream& operator<<(ostream& os, const Test& rhs) {
        os << "Testing" << endl; 
        return os; 
    }
    private:
    public:
};
```

<div align = "center"> 
<sub> Demonstration inside the class </sub>
</div>

</br>

```C++
class Test {
    friend ostream& operator<<(ostream& os, const Test& rhs);
    private:
    public:
};

ostream& operator<<(ostream& os, const Test& rhs) {
    os << "Testing" << endl; 
    return os; 
}
```

<div align = "center"> 
<sub> Demonstration outside the class </sub>
</div>

---

### Operation Overloading
When creating a class that has methods, we are able to overload certain operations. This was already done when we created `friend` functions - we overloaded the operator for `<<` using the syntax `operator<<` to overload it. Do note there is a more in depth example done in [Lecture 3's](https://github.com/XinRC/CS-2124/blob/main/lecture3/README.md) notes. 

