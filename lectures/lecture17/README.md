<div align="center">

# Lecture 17
## Inheritance: Abstract, Protected, Hiding

</div>

### Abstract

Guaranteeds a consistent interface for all dervied classes and enforces requirements. This is however purely used as interfaces. What it does:

- Forbids objects from being greated for the class
- One method must be **pure** virtual
- **Pure** virtual methods must be declared as virtual and have `=0` before the semicolon
- It remains a pure virtual method from the base class to the dervied class unless it is also implemented in the dervied class.

### Protected

Addition to `public` and `private` modes, there is also the `protected` mode. The protected mode allows a derived class direct access to the member while keeping that private to the rest of the program. This means instead of needing a public getter method, we can have the data in the `protected` mode allows direct access to the item without needing a public getter method.


### Hiding

Within the protected mode we cannot get item of another dervied class of the base, we can only use protected mode items on the same derived class. This means they can access methods from the same derived class, but cannot access methods of a sibling class