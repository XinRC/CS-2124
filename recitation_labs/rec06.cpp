/*
    Xin Rui Chen
  rec06_start.cpp
  CS2124
 
  Focus: Dynamic arrays and copy control

  KEY NOTES:
  **Entry A pointer to "Entry" that points to Entries
  unsigned is a (+) int

  Assignment operators::
  1. free up resources from lhs
  2. allocate new resources
  3. copying over data
  4. return *this ... 
 */

#include <string>
#include <iostream>
using namespace std;

// 
// Position class [DO NOT MOFIDY]]
// 
class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs)
    {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    } // Position op<<
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position


// 
// Directory class
// 
class Directory {
    // 
    // nested Entry class
    // 
    class Entry { // DO NOT MODIFY]
	friend ostream& operator<<(ostream& os, const Entry& rhs)
        {
	    os << rhs.name << ' ' << rhs.room
	       << ' ' << rhs.phone << ", " << *rhs.pos;
	    return os;
	} // Entry op<<
    public:
        // If position is passed as constant reference, then the field
        // would need to be pointer to const.
	Entry(const string& name, unsigned room, unsigned phone, 
              Position& position)
	    : name(name), room(room), phone(phone), pos(&position) {
	}
	const string& getName() const { return name; }
	unsigned getPhone() const { return phone; }
    private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
    }; // class Entry

    // Overload Directory's output operator
    // ... 
    friend ostream& operator<<(ostream& os, const Directory& rhs) {
        os << "Directory " << rhs.company << endl;
        for (size_t i = 0; i < rhs.size; i++) {
            os << *rhs.entries[i] << endl; 
        } return os;
    }

public:
    // Of course the first function you need to write for this (or
    // any) class is...
    // ???= A constructor
    // ...

    Directory(const string& companyName) // Constructor 
    : company(companyName), capacity(0), size(0), entries(nullptr) {}

    
    
    // We'll get you started with the add method, but obviously you
    // have a lot of work to do here.
    void add(const string& name, unsigned room, unsigned ph, Position& pos)
    {
        if (size == capacity)	{
            // something is missing!!!  Add it! 
            // Resizing (doubling) array if capacity is reached
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            Entry** newEnteries = new Entry*[capacity]; 
            // pointer to an array (Entry) that points to (Entry) that has data points
            for (size_t i = 0; i < size; ++i) {
                newEnteries[i] = entries[i]; // moving old entries data to new entries
            }
            delete[] entries; // deleting the old array -> clears that heap 
            entries = newEnteries; 


        } // otherwise just add the new item 
        entries[size] = new Entry(name, room, ph, pos); // adding the item...
        ++size;
    } // add

    // overloading [] -> return someones (unsigned > 0) number by looking up (string) name
    unsigned operator[](const string& name) const {
        for (size_t i = 0; i < size; i++) {
            if (entries[i]->getName() == name) {
                return entries[i]->getPhone();
            }
        } return 0;
    }

    //
    // === Copy Control ===
    //
    // (get checked out on everything else before starting this)


    // Deconstructor
    ~Directory() { 
    cout << "RUNNING DECONSTRCTOR ==========" << endl; 
    for (size_t i = 0; i < size; i++) {
        delete entries[i]; // clears the heap from entries data
    }
    delete[] entries; // clears the array
    }

    // Copy Constructor
    Directory(const Directory& other) 
        : company(other.company), capacity(other.capacity), size(other.size), 
            entries(new Entry*[other.capacity]) { // simple copy
        cout << "RUNNING COPY CONSTRUCTOR ========" << endl; 
        for (size_t i = 0; i < size; i++) { // manually copy each as new entry
            entries[i] = new Entry(*other.entries[i]); 
            // assigning newly formed heap copy (data) of other to our new obj
        }
    }

    // Assignment Operator
    Directory& operator=(const Directory& other) { 
        cout << "RUNNING ASSIGNMENT OPERATOR ========" << endl;
        if (this != &other) { // cant assign to itself 
            for (size_t i = 1; i < size; i++) { // frees up resource from lhs
                delete entries[i];
            } delete[] entries; 

            // Copying data from rhs(other) to lhs:
            size = other.size;
            capacity = other.capacity;
            company = other.company;
            entries = new Entry*[capacity];

            for (size_t i = 0; i < size; i++) { // copies the data from the entries heap
                entries[i] = new Entry(*other.entries[i]);
            }
        } return *this;
    }

private:	
    Entry** entries; // Notice the type!!! Pointer to Entry pointers.
    size_t size;
    size_t capacity;
    string company;
}; // class Directory

void doNothing(Directory dir)
{ 
    // You need to overload the Directory output operator before
    // uncommenting the next line. == WORKS

     cout << dir << endl;
} // doNothing




int main()
{
	
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	
    
    // Create a Directory == WORKS
    Directory d("HAL");
    // Add someone
    d.add("Marilyn", 123, 4567, boss);
    // print the directory
    cout << d << endl;
    // Use the square bracket operator, aka the Index operator,
    // to access someone's phone extension.
    cout << "d[\"Marilyn\"]: " << d["Marilyn"] << endl;
    cout << "======\n\n";


    // Everything working so far? Get checked out!!!

    Directory d2 = d;	// What function is being used?? == copy operator cause new -> 3 rule 
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << "Directory d:\n" << d << endl;
    cout << "Directory d2:\n" << d2 << endl;

    cout << "Calling doNothing\n"; // == WORKS
    doNothing(d2);
    cout << "Back from doNothing\n";

    // Should display 1592
    cout << d2["Carmack"] << endl;

    Directory d3("IBM");
    d3.add("Torvalds", 628, 3185, techie);
    d3.add("Ritchie", 123, 5813, techie);
    

    d2 = d3;
    // Should display 5813
    cout << d2["Ritchie"] << endl; // == works

    cout << d2 << endl;
    	
} // main



/*
Code Reading Question:
Since its a vector that is doubling its size (4->8), thus the pointer becomes a dangling pointer
This would display a garbage value.

Use index instread
*/