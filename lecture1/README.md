<div align = "center">

# Lecture 1
## Basics of C++

</div>

#### Variables
Every variable must have a *type* and it can only hold items of that predefined type. This is true not just for variables by also for function parameters and function return types. If you do not initialize a variable, if you were to retrieve the data, it would either point at "0" or point at the previous memory module. To make a variable: 

- int n;
- double d;
- string s;

Just to note, we must #include <string> since strings is not built into language. 

#### Conditions

#### Logical Operators

- and is represented as &&
- not is represented as !()
- or is represented as ||

#### Loops

- While Loops:
  - Conditions must be in parenthese
  - pre-decrement operator would be `-- variable`
  - Scopes are very important

- For Loops:
  - Has three parts within the parenthese
 
- Do While:
  - Always execute the body of the loop at least once
 
#### Storage

Vectors can *only* hold integers. They are similar to python's list. 
Local Arrays: 

- Can only hold intgers and they are fixed size. Generally speaking, vectors are much easier to use.


#### Strings

- Must be included using: `#include <string>`
- Strings in this case *is* mutable

#### File I/O

- Must be included using: `include <fstream>`
