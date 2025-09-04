<div align = "center">

# Lecture 1
## Basics of C++

</div>

```C++
// First C++ Code
#include <iostream> 

// Curly brackets signal the beginning/end of a block code chain. Semicolons represent the end of code command
int main() {

  std::cout << "Hello World" << std::endl;
}

/* Results:
"Hello World"
*/
```

<div align = "center">
  
| **Basic Code** | **Definition** |
| :---: | :--- |
| // | Method to create single line comments |
| /* */ | Method to create multi-line comments |
| #include | Similar to python's `import` function | 
| #include \<iostream\> | Includes the files to allow users to input/output data | 
| int main() | `int` refers to the data type, `main()` is the function name, parameters can be put within the `()`
| std::cout | Command to display the data after `<<` | 
| std::endl | Command to end the line and start a new line, similar to `\n` | 

</div>

Every program requires a "main" function - it will always be the first function to be ran when the program is being compiled. It is not always necessary to write a `std::cout` or `std::endl`, instead you can use `using namespace std;` at the initalization area to get rid of the need to type "std::" everytime, see below. 

```C++
#include <iostream>
using namespace std;

int main(){

  cout << "Does not require the \"std\" text" << endl; 
}

/* Results:
"Does not require the "std" text"
*/
```
</br>

---

### Variables
Every variable must have a *type* and it can only hold items of that predefined type. This is true not just for variables by also for function parameters and function return types. Although you are not required to initialize a variable, if you were to retrieve the data, it would either point at "0" or point at the previous memory module. Variables types is in the following chart below.

<div align = "center">

| **Initialization** | **Explaination** | 
| :---:| :--- | 
| int n = 53; | `int` is the data type, `n` is the name, `53;` is the value | 
| char c = 'c'; | `char` is the data type, `c` is the name, `'c';` is the value </br> <sub>Do note for `char`, you must use '' to represent the value </sub>
| double d = 43.634; | `double` is the data type, `d` is the name, `43.634;` is the value </br> <sub>Do note `double` is just a gloried `float` that can hold more values</sub>
|string s = "Text"; | `string` is the data type, `s` is the name, `"Text";` is the value

</div>

Since strings is not a built-in data type for C++, we must `#include <string>` to make strings a datatype. Different to python, C++'s strings are also mutable. 

```C++
#include <iostream>
#include <string>
using namespace std;

int main(){

  int a = 19;
  float b;
  b = 17.98;
  int result = a + b;

  string greeting = "Hello!";

  cout << result << endl;
  cout << greeting;
}

/* Results:
36
"Hello!"
*/
```
You can also initalize multiple variables in one line using: `int a, b, c;`. If you want to make a data type constant, all you have to do is type `const` before the datatype: `const double pi = 3.1415;`

</br>

---

### Conditions
```C++
#include <iostream>
using namespace std;

int main(){

  int x = 17;

  if (x > 17){
    cout << "x is larger than 17";
  }
  else if (x < 17){
    cout << "x is smaller than 17";
  }
  else{
    cout << "x is 17";
  }
}
```

</br>

---

### Logical Operators

<div align = "center">
  
| Operators | Definition |
| :---: | :--- |
| && | and |
| !() | not |
| \|\| | or | 
| ++ | increment by 1 |
| -- | decrement by 1 | 

<sub>Do note ++x and x++ is different, `++x` is to increment first and then use the x value while `x++` is to use the x value first and then increment.</sub>

</div>

</br>

---

### Loops

- **While Loops:**
  - Condition/s must be in parenthese

```C++
int main(){

  int x = 1;

  while(x<=3){
  cout << x;
  x++; // Increments "x" by 1 each time the while loop runs
  }
}

/* Results:
123
*/
```
<div align = "center">

<sub>Assuming the `#include` sections and other necessary initialization code is at the beginning</sub>

</div>

- **For Loops:**
  - Has three parts within the parenthese. The initalization, the condition, the updation. Although you can leave some sections empty, you must keep their semicolon to ensure the structure remains clear. 

Example 1 - Full sections of for loop:
```C++
int main(){

  for(int i = 2; i < 5; i++){
    cout << i;
  }
}

/* Results:
234
*/
```

</br>

Example 2 - Empty sections of for loop:
```C++
int main(){

  int x = 1;
  for(; x < 4 || x == 1;){
    cout << x;
    x++;
  }
}

/* Results:
123
*/
```

</br>

- **Do While:**
  - Always execute the body of the loop at least once.
  - Rarely used but still a useful loop.
```C++
int main(){

  // Initalizer:
  int x = 1;
  do{
    cout<<x;
    x++;
  } while (x < 5);
}

/* Results:
1234
*/
```

<div align = "center">

<sub>**Do note that scopes of reference is very important. Make sure items are not being called from out of their scopes**</sub>

</div>

</br>

---

### User I/O
This allows users to interact with the code through inputting data. Some commands include the following.

<div align = "center"> 

| Code | Definition | Example |
| :---: | :--- | :--- |
| cout | Displays the data | cout << "x represents"; |
| cin | Allows for user input | cin >> variable_name |
| getline(cin, var); | Temporary user data storage | getline(cin, user_age);

</div> |

```C++
int main(){

  string f_name, l_name;
  cout << "What is your first" << " and last name? ";
  cin >> f_name >> l_name;
  cout << "Nice to meet you " << f_name << " " << l_name;
}

/* Results
Nice to meet you {inputted first name} {inputted last name}
*/
```

<div align = "center">

<sub>C++ considers spaces (white spaces, tabs, and new lines) as the end of a data point. This means that if you were to type "Alfredo Zaus," it would cleanly seperate `f_name = Alfredo` and `l_name = Zaus`. Similarly you can also type "Alfredo" in first, enter, and then type "Zaus.</sub>
  
</div>

If you do not need the data from the user's saved into its own variable, you can use the `getline(cin, var);` that will replace the variable with the newer user input. However, this is only possible for string inputs.
```C++

int main(){

  string name;
  cout << "Give me your first name: ";
  getline(cin, name);
  cout << "Your first name is " << name <<. What is your last name: ";
  getline(cin, name);
  cout << "Your last name is " << name;
}
```

<div align = "center">

<sub>See how the name variable, `name` was used for the user's first name and then replaced with the user's inputted last name</sub>
  
</div>

---

### File I/O

To utilize file I/O, the `<fstream>` file must be included. The following chart consists of the commands that can be use to manipulate an external file. 

<div align = "center">

| Code | Definition |
| :---: | :--- | 
| ofstream | Creates and writes on files|
| ifstream | Reads from files|
| fstream | Does both ofstream and ifstream |
| `FileVariableName`("FileName.txt"); | Goes after one of the three above streams, it is the variable you will use to read/write from the file with | 

</div>

</br>

- **Writing from a file:**
```C++
#include <iostream>, #include <fstream>
using namespace std;

int main(){
  ofstream myfile("FileName.txt");

  // In case myfile cannot be created or opened:
  if (!myfile.is_open()){
    cerr << "Cannot create/open the file" << endl;
    return 1;
  }

  // If it can be opened and created, we will write the sentence before closing the file:
  myfile << "First sentence of the new file";
  myfile.close();
}
```

```C++
#include <iostream>, #include <fstream>
using namespace std;

int main(){
  ofstream myfile2;
  myfile2.open("FileName.txt");

  // In case myfile2 cannot be created or opened:
  if (!myfile2.is_open()){
    cerr << "Cannot create/open the file" << endl;
    return 1;
  }

  // If it can be opened and created, we will write the sentence before closing the file:
  myfile2 << "First sentence of the new file";
  myfile2.close();
}
```

- **Reading from a file:**
```C++
#include <iostream>, #include <fstream>, #include <string>
using namespace std;

int main(){

  ifstream myfile3("FileName.txt");

  // Check if my file exists, otherwise run an error
  if (myfile3.is_open()){
    string line;
    while (getline(myfile3, line)){
      cout << line << endl;
    }
  myfile3.close();
  }

  else cerr << "File does not exist";
  return 0;
}
```

- **Using fstream instead of ofstream/ifstream

To use fstream is a bit more complicated, when opening the file, you should explictedly choose how to interact with it, there are many different modes but below are several.

<div align = "center">

| Mode | Definition | Example |
| :---: | :--- | :--- | 
| ios::in | Open file for input reasons | myfile.open("FileName.txt", ios::in); |
| ios::out | Open file for output reasons | myfile.open("FileName.txt, ios::out); | 
| ios::binary | Open file in binary mode | myfile.open("FileName.txt, ios::binary); |
| ios::app | Open file for appending mode | myfile.open("FileName.txt, ios::app | 

</div>

```C++
#include <iostream>, #include <fstream>
using namespace std;

int main(){

  // Method 1
  fstream myfile4;
  myfile4.open("FileName.txt", ios::app | ios::binary);

  // Method 2
  fstream myfile5("FileName.txt", ios::in | ios::out);


  myfile4.close();
  myfile5.close()

}
```

---

### Vectors and Arrays

- In C++, vectors is similar to python's lists - it is an resizable array. C++'s arrays on the other hand is nonresizable. Generally speaking, vectors is used more often.
- Every item in the vectors/arrays must have the same datatype.
- To use vectors, you must `#include <vector>`

**Methods of Vectors**

<div align = "center">

| Method Name | Explaination |
| :---: | :--- |  
| vector<data_type> vector_name; = {}| Declares an empty vector of integers, with `vector_name(#)` will provide us the inital size | 
| vector_name.push_back(#); | Adds an element to the end of the vector | 
| vector_name.pop_back(); | Removes the last element from the vector | 

</div>

**Methods of Arrays**

<div align = "center">
  
| Method Name | Explaination |
| :---: | :--- |
| int foo \[2\] = {2, 5};| Initialization of the array with a length of 2 and array name of "foo" |
| foo\[1\] = 2; | Giving the index 1 of the array the value of "2" |
| x = foo\[1\] | Gives the variable "x" the value of the item at index 1 |

Do note that for regular arrays, the vector methods does not work on it - for example you cannot use `.pop_back()`. 

</div>

--- 

### Multidimensional Arrays 

Multidimensional arrays is very similar to python's multidimensional arrays. Given an array `int shelf`, you can retrieve information using `int shelf \[4\]\[5\]\[2\], but do note that with more dimensions, the more amount of dimension is needed. 

---

### Resources to use:
- [cplusplus](https://cplusplus.com/doc/tutorial/variables/) 
- [w3schools](https://www.w3schools.com/cpp/default.asp)
- [learncpp](https://www.learncpp.com/) 
