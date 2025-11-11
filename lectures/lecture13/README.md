<div align="center"> 

# Lecture 13
# Cyclic Association and Namespaces

</div>

### Cyclic Association

Cyclic Assosciation allows for inner methods of a class to be declared inside, but defined outside. This is similar to "prototyping" of regular functions - declaring it first before defining it later on. However, to name is outside the function, we must use a specific syntax: `[return type] className::methodName() {}`

```C++
// assume all #include files are included

class Name {
    private:
        string name;
    public:
        // declared inside
        Name(const string& name); 
        void displayText() const; 
};

// defined outside 
Name::Name(const string& name) : name(name) {}
void Name::displayText() const { cout << "Text" << endl; } 
```


### Namespaces 
Namespaces can be considered as containers. Suppose within a program, there is two functions named the same thing - by using a namespace for it, we can keep the same

Namespaces allow for two or more entities to have the same namespace.
