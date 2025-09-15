<div align = "center">

# Lecture 2
## Functions, Classes, and Parameters

</div>

### Functions
Functions behave the same way they do in python. For every function, you must write what the datatype being returned is, and if there is nothing to be returned, then the "datatype" would be `void`. Similarly, to initialize parameters, the datatype for the variable and data must be made clear. To provide a default variable data information, you can type the datatype, the variable name, then value within the parameters: `int slicesOfPizza = 8`. Another thing to note is the scopes of variables, when you define a variable within a function, the variable is **only** accessible from within that function, if you attempt to call it elsewhere, it will not work. 

```C++
// Note how since the datatype is "void," we will not be returning anything
void introducingYourself(string name, int favoriteNumber = 0){
    // Code block
}

```

#### Prototypes

It is a general rule of thumb to have the self-written functions before `main()` functions since main functions often run on the self-written functions. However in some cases, you may not be able to do such - that is where prototypes come in. As long as you have a prototype, then you would not have to worry about when you are unable to have your self-written functions before the `main()` functions. The syntax for prototypes is very similar to that when defining a function, however instead of having curly braces to continue the rest of the function code, you would immediately end it with a semicolon. Having a protoype promises the compiler that you have defined the function even if it was not in front of the `main(0` function.

```C++
//Prototype:
void functionExample();

int main(){
    functionExample();
    return 0;
};

void functionExample(){
    // Insert code block
}
```
#### Parameter Passing

| Parameter Type | Definition | Example | 
| :---: | :--- | :--- |
| Pass-by-value | When calling a function with a parameter, if you change the data of a parametered variable within the function, it will not affect the main function. | functionName(int x) |
| Pass-by-reference | When calling a function with a parameter, if you change the data of a parametered variable within the function, it will also affect the main function | functionName(int x&) | 
| Pass-by-constant | When calling a function with a parameter, if you try to change the data of a parametered variable within the function, it will raise an error. This makes the parameter **read** only.| functionName( const int &x)| 

</br>

```C++
// Pass-by-value:
void valueFunction(int i){
    i = 5
    // i = 5 within the function. however when called outside of this function, it will still be 1
}

// Pass-by-reference:
void referenceFunction(int i&){
    i = 5
    // i = 5 within the function, when it is called outside the function, it will also be 5
}

// Past-by-const
void constFunction(const int &i){
    i = 5
    // When you try to change i to 5, you will run into an error
}

int main(){
    i = 1
    valueFunction(i);
    referenceFunction(i);
    constFunction(i);
    cout << i;
}
```

</br>

---

### Classes: 
Classes allow developers to create **private** datatypes by default. To create a class in C++, just use the `class` keyword and then type the name of the class. There are 3 types of membership, private, public, and protected.

<div align = "center">

| Membership Type | Definition | 
| :--- | :--- |
| Public | Anyone can call or access the data |
| Private | Only member functions of the class can call or access the data |
| Protected | Only member functions and their child can call or access the data|

</div>

One done, be sure to use curly brackets followed by a semicolon. Class declarations are usually done before the `main()` function. To initalize an item of the class, call the type (this case our type would be "Employee" since that is our class name) before choosing a variable name for the item. Like python, we are able to make methods to run with our classes. You can also create your own **constructors**, constructors is very similar to python's class initializer (\_\_init\_\_).

```C++
class Employee{
public: // makes the data below public to call/access  

    // Creating a constructor:
    Employee(string name, string department, int id_number){
        name = name;
        department = department;
        id_number = id_number

        /* Another way of initializing constructor:
         name = (name), department = (department), id_number  = (id_number) {};
        */
    }

    // Setter function -> enables us to change the name after creation
    void setInformation(string name, string department, int id_number){
        // Creating the class attributes:
        string em_name;
        string em_department;
        int em_id_number;
    }

    // Creating methods:
    void EmployeeInfo() {
        cout << em_name << "'s ID is: " << em_id_number << " and they are in the " << em_department << " department." << endl;
    }


};

int main(){
    /* Difficult way of initializing and giving an object attributes
    Employee employee1;
    employee1.name = "Ada Wong";
    employee1.department = "Espionage";
    employee1.id_number = 1998;
    */

    // Prefered way of initalizing and giving an object attributes
    Employee employee2 = Employee("Leon Kennedy", "Police", "0930");

    // To call a method:
    employee2.EmployeeInfo();
}
```
