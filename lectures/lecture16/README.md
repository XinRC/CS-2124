<div align="center">

# Lecture 16
## Inheritance: Constructor, Override

</div>

### Constructor
For inherited classes, constructors are not inheritied. This means that for each derived class, you must write a seperate constructuor for each. However to initialize the parameter from the constructor class, we must use the parent class to initalize the parameter. However say we don't use Animal, then the default base constructor will be called. 

### Override
We went over this material on the previous lecture but derived classes can override their parent class's methods. And can use the keyword `virtual` to make sure the derived class's method was being used. 