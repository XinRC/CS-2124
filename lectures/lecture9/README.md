<div align = "center">
  
# Lecture 9 
## Copy Control 

</div>

### Copy Control

When working with classes, there are often 3 methods to be implemented - (5 in the modern day, but only 3 will be discussed here). The three are: `destructor`, `copy constructor`, and `copy assignment operator`. 

### Destructor

Destructor is always automatically ran when the class goes out of scope. This method is particularly useful when dealing with heap memory the destructor is able to automatically clear up the heap once the object goes out of scope. To create a destructor, it is just `~` sign and the constructor name (without the parameters). 

### Copy Constructor

Copy constructor is as the name says - it allows the creation of an object based on another object of the same class. However, be sure to fully initalize it with the constructor to prevent shallow copying.


### Copy assignment operator

Copy Assignment Operator is by assigning an already formed object equal to the another object of the same class. The syntax for the copy constructor and assignment operator is very similar since they do relatively the same thing; however, to created a copy assignment operator, we must overload the = operator by using `Class& operator=(const Class&)`. 

Another thing to note for the copy assignment operator, it is best to make sure that you do not assign the object to itself. 

Code for the **Big Three** will be in the .cpp files as example. 