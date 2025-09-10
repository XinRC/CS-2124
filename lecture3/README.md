<div align = "center">

# Lecture 3
## Structures, Encapsulation, Data Hiding

</div>

> [!Important]
>  - Encapsulation, Data Hidin
>      - Struct
>      - Const methods
>      - Overloading output operator


### Structures:
Structures and classes are very similar - the only difference being that structures are by default, public, while classes by default, are private. However, structures can also be defined as private if necessary. Like classes, structures can have private/public/protected attributes, constructors, and methods. 

```C++
// To create a structure:
struct Person {

  int age;
  string name;

  // You can create "methods"
  void announceName(){
    cout << name << " is of age " << age << endl;
  }
};

int main() {
  Person person1;
  person1.name = "John";
  person1.age = 20;

  person1.announceName();
}
```


</br>

---

### Const Methods:
Using "const" in front of a variable ensure that the variable doesn't change, however it may bring up an error when we run it on a method function since it may possibly change the variable's data. If we were to put `const` outside the method we are creating, it will ensure that the method (void), would not modify the data/variables we want.

```C++

// Although the function does not need the parameters since it is in a class function, to ensure the previous stated `const` variables don't change, we will leave `const` outside the parenthesis
void eating() const {
  cout << name << " is eating." << endl;
}

```
</br>

---

### Overloading Output Operator (<<)
Adding `friend std::ostream& operator <<(std::ostream& os, const Person& rhs);` into he class would grant the operator `std::ostream& operator <<(std::ostream& os, const Person& rhs){}` function access to private data and members. After, you can create the function either inside or outside the class. This means the follow code overloaded the `<<` method. 

```C++
class ...{
  friend std::ostream& operator<<(std::ostream& os, const Person& rhs); // Allows us to create a function (after the friend keyword) to access the information from the class
};

// This function could be put inside/outside the class:
std::ostream& operator<<(std::ostream& os, const Person& rhs){
  os << "Person: " << rhs.name << " with the age of " << rhs.age;
  return os;
}
```

</br>

---

### Dictionary:

<div align = "center"> 
  
| Term | Defintion |
| :---: | :--- | 
| `os` | Parameter name for an object of type `ostream&` (referencing output stream). It is refers to the left hand side of the '<<' operator. It is the opposite of 'rhs'. This is similar to 'repr' from python. | 
| `rhs` | The opposite of `os`, it refers to the right hand side of the `<<` operator. | 
| `friend` | Keyword that allows a function (another class access) to a private/protected member of the class it was defined in | 
| `operator`| Keyword that allows for the overloading of an operator |



</div>
