<div align="center">

# Lecture 18
## Inheritance: Poly / Non-Member, Overloading vs. Overriding

</div>


### Poly / Non-Member

For polymorphism, nonmember functions can also be used. However, `getter` functions would be very useful for these cases. 

### Overloading vs. Overriding

Overriding is when we create a method that will be overridden in it's derived class.

 Overloading is when functions have the same name but different parameters. the compiler picks the most specific overload based on compile-time arguments.

``` C++
class Addition() {
    public:
        int add(int a, int b) { return a + b; }
        double add(double a, double b) { return a + b; }
        string add(const string& a, const string& b) { return a + b; }
        int add(int a, int b, int c) { return a + b + c; }
};
```


<!---https://cse.engineering.nyu.edu/jsterling/cs2124/LectureNotes/04.Inheritance.html-->