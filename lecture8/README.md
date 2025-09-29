<div align = "center"> 

# Lecture 8
## 

</div>

> [!Important]
> - Explict vs. Implicit -> explicit is better
> - Shallow vs deep copy -> deep copy better > shallow copy creating a shortcut to the original file, deep copy is an actual duplication. 
> - copy by construct vs copy by assignment > datatype x = y -> constructor: x = y > copy assignment
> - Deconstructor requires ~ before the datatype name aka: given a class named `DType` then the deconstructor would be `~DType`. Deconstructors used to free up space 

Explicit: no implicit conversion where you must pass through a specific made data type. "Don't use the constructur for type conversion, only use it when I call the class"
Shallow vs deep copy. The new function copies the value deeply -> requires the keyword. Copying is also initaliziation. 


```C++
class {
  explicit Thing(int x);
}
```
