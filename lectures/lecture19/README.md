<div align="center">

# Lecture 19
## Inheritance: Copy Control and Polymorphic Constructors

</div>

### Polymorphism inside Constructors

Usage of `virtual clone` to specify type's copy constructor through polymorphism - this is because constructors cannot be virtual. That means in the constructor, everything will only ever use the base case methods since the derived items technically havent been created yet. 

### Inherited Copy Controls

This is particularly important for copy/assignment controls. For derived classes, the copy constructor and assignment must explictedly call the base class's. Also for deconstructors, it is a good idea to put the keyword `virtual` in front of the base class. 