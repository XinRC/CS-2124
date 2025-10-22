<div align = "center">

# Lecture 4
## Vectors and References

</div> 


### Ways to Initialize a Vector:

Parenthesis: 
- `vector<int> numbers(2, 3)` would create a vector with the size of **2** whos value is **3**. The vector would look like: `<3,3>`

Curly Braces (Uniform Initaliization):
- `vector<int> {1, 2, 3, 4}` would create a vector with it's specific values from initialization. The vector would look like: `<1,2,3,4>`

---

### Ranged Loop 
```C++
int main() {
  vector<int> numbers{1,2,3,4,5}

  // given a variable (value), loop through data from (numbers)
  for (int value : numbers) {
    cout << value << endl;
  }
}
```

---

### References
Usually, we are often getting a "copy" of an element, in python terms, it would be an `alias`. However, to ensure the "copied" item also gets changed, we must reference to the original, allows us to change the item. To create a reference to the original, allowing us to modify the item, we must use a `&` after the datatype. However, when if we do **not** want to modify the original, we could also use `const <datatype>&`, if you try to modified the const reference, you will run into an error. In general, the three are called.

- **By Value**
- **By Reference**
- **By Constant reference**

---

### Prototyping
It is good advice to have the `main` function as the program's first function. However, it is required that the other functions called by `main` be in front, to resolve this issue, we can create a prototype allows `main` to be run first by having the function's definition before the main function. For example, having `void sampleFunction(int x, int y);` in before the main function but it's actual function definition after the main function would still work. It would overall make the program easier to look at. 


```C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
  string name;
  int month;
  int day;
  int year;
};

void displayInfor(const vector<Person>& person); // prototype


int main(){
    vector <Person> person;
    person.push_back({"Alfred", 9, 15, 2006});
    person.push_back({"Jocelyn", 12, 24, 2005});
    
    displayInfor(person);
}

void displayInfor(const vector<Person>& personVariable){
    for (const Person& p : personVariable) {
        cout << p.name << " " << "with the birthdate of " << p.month << "/" << p.day << "/" << p.year << endl;
    }
}
```


### Dictionary 

<div align = "center">
  
| Term | Definition |
| :---  | :--- |
| cerr | Stands for (standard error), compared to `cout`, `cerr` is unbuffered, meaning there is no delay and it would be immediately written to the output without being buffered through the memory| 
| .size() | The current number of items in a vector. | 
| .capacity() | The amount of memory a vector has allocated. The capacity **must** be greater than or equal to its size. |

</div> 
