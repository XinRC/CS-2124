// Sample 1

/*
Sample code for Inheritance: Copy Control
The .cpp will go over Copy Control and the Big Three. This first example will not
utilize vectors/heap allocation. 
*/
#include <iostream>
#include <string>
using namespace std; 

class Cookie {
    friend ostream& operator<<(ostream& os, const Cookie& rhs) {
        os << rhs.cookie_name << " is partnered with: ";
        if (rhs.cookie_twin != nullptr) {
            os << rhs.cookie_twin->cookie_name << endl; 
        } else {
            os << "None" << endl;
        } return os; 
    }

    private:
        string cookie_name;
        Cookie* cookie_twin; // pointer to a partner cookie
    public:
        Cookie(const string cookie) 
            : cookie_name(cookie), cookie_twin(nullptr) {} // constructor

        ~Cookie() { // this will automatically run
            cookie_twin = nullptr; // set cookie_twin pointer to nullptr
        } // destructor

        Cookie(const Cookie& other) // copy constructor
            : cookie_name(other.cookie_name), cookie_twin(other.cookie_twin) {} // uses other.data

        Cookie& operator=(const Cookie& other) { // copy assignment operator
            if (this != &other) { // makes sure we don't assign to the same item
                cookie_name = other.cookie_name;
                cookie_twin = other.cookie_twin;
            }
            return *this;
        }

        void setCookie(Cookie& other) {
            cookie_twin = &other; 
        }

};

int main () {
    Cookie CC("Chocolate Chip");
    Cookie SC("Sugar Cookie");
    CC.setCookie(SC);
    cout << CC << endl;

    Cookie DC(CC); // copy constructor
    cout << DC << endl;

    DC = SC; // copy assignment operator
    cout << DC << endl;

    // automatically runs deconstructor after }
}