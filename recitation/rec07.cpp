#include <iostream>
using namespace std;

int greatestCommonDivisor(int x, int y);

// Put your Rational class here. Note, friend functions should have
// just their prototypes inside the class. Their definitions should
// appear below main.
class Rational {

    // friend declarations
    friend ostream& operator<<(ostream& os, const Rational& rhs); 
    friend istream& operator>>(istream& is, Rational& rhs); 
    friend bool operator==(const Rational& lhs, const Rational& rhs); 
    friend bool operator<(const Rational& lhs, const Rational& rhs);
    
    private:
        int num;
        int den; 

        void normalize(); // normalize declaration 


    public:
        Rational(int num = 0, int den = 1); // constructur 

        // methods
        Rational& operator+=(const Rational& rhs);  

        // incrementations: ++ (PRE AND POST) 
        Rational& operator++(); //pre
        Rational operator++(int); //post

        explicit operator bool() const; // does not modify & no implicit conversion
        

};


// Any functions that are not members oe friends should have
// prototypes here and their definitions after main. 
Rational operator+(const Rational& lhs, const Rational& rhs); 
bool operator!=(const Rational& lhs, const Rational& rhs); 
Rational& operator--(Rational& rhs); // prefix --
Rational operator--(Rational& rhs, int); //postfix --
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs); 


int main()
{
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;     // Implement += as a member
    cout << "a = " << a << endl;
    
    // Implement + as non-member, but NOT as a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    //
    // PLEASE CHECK OUT NOW
    //

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing? Why SHOULDN'T it compile?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    } 

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    } 

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : " 
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;

} // main


int greatestCommonDivisor(int x, int y)
{
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
} // greatestCommonDivisor



// Method Functions Definition: 
// DONE: constructor, normalize, +=, ++ 
Rational::Rational(int numerator, int denominator) // constructor 
    : num(numerator), den(denominator)
    { normalize(); }

void Rational::normalize() {
    if (den == 0) { // Would technically be undefined but -> we'll make it 1
        den = 1; 
    }
    if (den < 0) { // Make the numerator carry the negative sign
        num = -num;
        den = -den; 
    }

    int gcd = greatestCommonDivisor(abs(num), den);
    num /= gcd; // gets numerator from gcd
    den /= gcd;  // gets denominator from gcd

    if (num == 0) { // writes 0 like (0/1)
        den = 1;
    }
}

Rational& Rational::operator+=(const Rational& rhs) {
    num = (num * rhs.den) + (rhs.num * den);
    den = den * rhs.den;
    normalize();
    return *this; 
}

Rational& Rational::operator++() { //prefix
    num += den; // uses the above += 
    normalize();
    return *this; 
}
Rational Rational::operator++(int) { //postfix
    Rational temp(*this); //creating a temp object for the current object "de"ref
    num += den; 
    normalize();
    return temp;
}

Rational::operator bool() const {
    return !(num == 0);
}

// Friend Functions Definition: 
// DONE: << , >>, ==, < 
ostream& operator<<(ostream& os, const Rational& rhs) {
    os << rhs.num << "/" << rhs.den; 
    return os;
}

istream& operator>>(istream& is, Rational& rhs) {
    char slash; //throwaway char
    is >> rhs.num >> slash >> rhs.den; 
    rhs.normalize();
    return is;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.num == rhs.num && lhs.den == rhs.den; 
}


bool operator<(const Rational& lhs, const Rational& rhs) { // === DOING RN ===
    return (lhs.num * rhs.den) < (rhs.num * lhs.den);
}


// Any functions that are not members should have
// their definitions here...
// DONE: +, !=, --, <= 
// NOT DONE: >, >= 
Rational operator+(const Rational& lhs, const Rational& rhs) { // Not returning a ref
    Rational result(lhs); // "copying" lhs so we can have a temp object called result
    result += rhs;
    return result; 
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}


Rational& operator--(Rational& rhs) { //prefix
    rhs += Rational(-1); // subtracting 1)
    return rhs;
}

Rational operator--(Rational& rhs, int) { //postfix
    Rational temp(rhs);
    rhs += Rational(-1);
    return temp;
}


// can only use < since its the only declared friend 
bool operator<=(const Rational& lhs, const Rational& rhs) {
    return !(rhs < lhs); // makes sure we also count in the = 
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return rhs < lhs; 
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs); 
}
