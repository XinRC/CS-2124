<div align = "center">

# Lecture 2
## Functions, Classes, and Parameters

</div>

Objectives:

- Struct / Class
    - struct is a public
    - class is private
- Creating functions
- public vs. private -> public is be mutable
- methods
    - a friend function
    - methods are private but functions can be public if declared
- "setter"
- constructor??
- using "&" symbol = result of that??
- rhs meaning ->
- nested classes
- "friend" creating method?


```C++
// creating a class since we want it to be private

class Date{
  friend ostream& operator<<(ostream& os, const Date& rhs);
public:
  Date(int m, int d, int y): month(m), day(d), year(y) {}
private:
  int month, day, year;
};

ostream& operator<<(ostream& os, const Date& rhs){
  os << rhs.month << "/" << rhs.day << '/' << rhs.year;
  return os;
}
```

