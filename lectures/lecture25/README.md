<div align = "center">

# Lecture 25
## Recursion

</div>

### Recursion 

Recursion is a way to to work a big problem into workable smaller problems. The technique allows a functions to esentially call itself to break the problem into manageable chunks. It is important to note two things when implementing the recrursive technique, the `base case` and the `recursive step`. The base case is the if statement that would determine when the recursion stops, and the recursive step is what keeps the algorithm to continue recursing (until it hits the base case). 

Do note that although recursion is a rather helpful technique, sometimes it is very inefficient. Do note the efficency before implementing it into a program. Below is an example of the recursion technique done in C++ code.  

```C++
int factorial(int n) {
    // Base Case: Factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive Step: n * factorial(n-1)
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl; 
}
```