<div align="center">

# Lecture 26
## Exception Handling

</div>

Just like in Python, C++ allows a program to try and catch an error before it can crash the program. The syntax for exception handling is very similar to that of pythons, with a `try` and `catch(condition)` scenario. There can be multiple `catch()` phrases for handling different types of exceptions that might be thrown - like in Python, the order matters. There is also a "catch all" exception catcher that uses the syntax `catch(...).

There are three components, `throw` which creates the object and message, `try` to monitor for exceptions, and `catch` to handle specific exception types. 

### Base and Types of Errors:
- `exception`: Base class
- `runtime_error`: Errors detected at runtime
- `logic_error`: Error in program logic
- `invalid_argument`: Invalid argument passed
- `out_of_range`: Argument for out of valid range
- `bad_alloc`: Memory allocation failure
- `bad_cast`: Dynamic cast failure
- `ios_base::failure`: I/O stream error