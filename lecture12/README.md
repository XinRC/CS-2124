<div align = "center">
  
# Lecture 12
## Operator Overloading

</div>

Operator overloading pretty much allows us to to overload different operators to do different thing. This is very similar to python's \_\_xx__ methods in the classes where we are able to redefined what operators do. What we CANNOT do with operator overloading is:

- Manipulate built in types like `int`, etc.
- Change the precedence of operators
- Change associativity
- Can't overload an operator that is not even an operator. `**` in python represents exponentation, but since in C++ it does not represent anything, then that means we cannot overload it.

A key point to note that when overloading operators, C++ ALWAYS tries to convert the operator expression to a function call of `operator[operator sign]`. In the past, we overloaded `<<`, thus the function name would look like: `operator<<`. Key notes: [] and assignment operators are FORCED to be member operators while input/output are very much prefered to be non-member operators. Combination and unary operators are usually member functions while binary are usually non-member functions.

Friending for non-member:
- input output are usually friends
- binary arithmetic are usually not friends
- two relational operator would be usually implemented as friends (=== and <), but after those two, the others like (!=, <=, etc) would not be.

Conversion operators:
