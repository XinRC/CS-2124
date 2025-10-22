<div align = "center"> 

# Lecture 8
## Explict, Deconstructor, and Copying

</div>

### Implicit vs. Explicit Constructors

When writing constructors, there are two methods for the constructor to employ. `implict` which allows for automatic conversions, and `explict` which you must manually type out the keyword before the constructor to create a manual conversion. It is normal to have both an implicit and explicit constructor; however, we are unable to initialize a value of the explicit datatype normally since we are not using the implicit form. An example is show below in the code. Often times, explicit is seen as better since it doesn't rely on automatic processes. 

```C++
class Thing {
public:
  Thing(int x){}; // implicit
  explicit Thing(double x){}; // explicit
}

//Methods to correctly initalize an object
int main() {

  Thing t1(6); // works
  Thing t2 = Thing(6.6); // works

  Thing t3 = 6; // works since it is calling the implicit as an int
  Thing t4 = 9.3; // fails because it is calling implicit as a double, should call the explicit form instead
}
```

---

### Deconstructor
Deconstructors is an automatic process that is used to clean up space. They can also be described to be the closing argument and final actions done when the object is going out of the scope - signified by the `}` character. This often goes hand in hand with the `new` and `delete`, with `new` being used in the constructor segment and `delete` being used in the deconstructor segment. To create a deconstructor, the keyword that comes before it is the `~` sign. 

```C++
class Thing {
public: 
  Thing(string n, int id) : student_name(n), student_id(id) { // implicit constructor
    pstudent_id = new int[student_id]; // pointer pointing at the (creation) of a dynamic array 
  }; 

  ~Thing() { // desconstructor
    delete[] pstudent_id  // clears the array but keeps the pointer pointing at it 
  
  }
private:
  string student_name;
  int student_id
  int* pstudent_id; // reminder, this is a pointer
}

/* EXPLAINATION:
pstudent_id is pointing at the address of the student_id array of integer items. It is a dynamic array.
To clear the array to free the memory space, we must use delete[] since [] symbolize we are deleting the array.
For regular item pointers like: pointer = int(5), we would just use the regular delete pointer keyword. 
*/
```

</br>

### Shallow vs. Deep Copy
To put it simply, a shallow copy is creating a shortcut to the original folder while a deep copy is creating a complete new duplicate of file. Shallow copy is like python's `alias` while deep copy is the actual duplication, similar to python's `deepcopy.copy()`. Often times, deepcopies are considered better than it's shallow counterpart. 


</br>

### Copy by Construct vs Copy by Assignment

