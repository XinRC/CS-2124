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
Namespaces can be considered as containers. Suppose within a program, there is two functions named the same thing - by using a namespace for it, we can keep the same function name for them but specify the namespace for which the program resides in. To call a method that reside in a namespace, there are a few methods:

- `using namespace [Namespace Name]` - in the global scope would provide a broader scope for the namespace to be used.
- `using namespace [Namespace Name]` - in a function scope would provide a limited scope for the namespace to be used.
- `[Namespace Name]::[Function Name]` - is the most explicit option, allowing you to specify which function of which namespace you want to use. 