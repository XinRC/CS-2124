// Sample 3

/*
Sample code for Inheritance for Copy Controls.

*/

#include <iostream>
using namespace std;

class IoT {
    friend ostream& operator<<(ostream& os, const IoT& rhs);

    protected:
        double price;
    public:
        IoT(double price) : price(price) {}
        IoT& operator=(const IoT& other) {
            if (this != &other) {
                price = other.price;
            };
            return *this;
        }
        virtual ~IoT() {}
}; // IoT 

class Camera : public IoT { // works with copy control
    private:
    public: 
        using IoT::IoT; // basic constructor
        Camera(const Camera& other) : IoT(other) {}  // copy constructor
        Camera& operator=(const Camera& other) { // assignment operator -> uses Base's
            if (this != &other) {
                IoT::operator=(other);
            };
            return *this;
        }
        ~Camera() {} // destructor

        // double getPrice() const { return IoT::price; }
}; // camera


class Computer : public IoT {
    friend ostream& operator<<(ostream& os, const Computer& rhs); 
    private:
        int storage;
    public:
        Computer(double price, int storage) : IoT(price), storage(storage) {}
        Computer(const Computer& other) : IoT(other), storage(other.storage) {} // copy constructor
        Computer& operator=(const Computer& other) { // assignment operator
            if (this != &other) {
                IoT::operator=(other);
                storage = other.storage;
            }; 
            return *this;
        }
        ~Computer() {} // destructor

}; // computer 


int main() {
    // Testing Camera class:
    // Camera camera1(600);
    // Camera camera2(500);
    // Camera camera3(camera1); // copy constructor
    // camera1 = camera2; // assignment operator

    // Testing Computer class:
    // Computer computer1(1000, 256);
    // Computer computer2(1500, 512);
    // Computer computer3(computer1); // copy constructor
    // computer1 = computer2; // assignment operator

}


// overloaded << friends
ostream& operator<<(ostream& os, const IoT& rhs) {
    os << "$" << rhs.price << endl;
    return os;
}

ostream& operator<<(ostream& os, const Computer& rhs) {
    os << "$" << rhs.IoT::price << " with " << rhs.storage << " GB" << endl;
    return os;
}