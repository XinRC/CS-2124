// Sample 1

/*
Sample code for Structures
Structures is an item very similar to that of classes though by default all the data is public. 
*/

#include <iostream>
#include <string>
using namespace std;

int greatestCommonFactor(int x, int y); // protoype 

struct Point { // Point
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {} // constructor
    void displayPoint() { cout << "(" << x << ", " << y << ")" << endl; } // display method
}; // Point

struct Fraction { // Fraction
    int num;
    int den;

    Fraction(int numerator, int denominator) : num(numerator), den(denominator) {} // constructor
    friend ostream& operator<<(ostream& os, const Fraction& rhs); // ostream prototype
    Fraction simplifyFract() { // simplify fraction method
        int gcf = greatestCommonFactor(abs(num), den);
        return Fraction(num /gcf, den/gcf);
    }
}; // fraction


int greatestCommonFactor(int x, int y) { // gretestCommonFactor
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
} // greatestCommonFactor

Fraction findSlope(Point& point1, Point& point2) {
    int num;
    int den;
    if (point1.x == point2.x || point1.y == point2.y) {
        return Fraction(0, 0);
    } else {
        num = point1.y - point2.y;
        den = point1.x - point2.x;
    };
    return (Fraction(num, den).simplifyFract());
} // findSlope 

int main() {
    Point point1(1,2);
    Point point2(3,6);
    point1.displayPoint();
    point2.displayPoint();
    cout << findSlope(point1, point2) << endl; 
} // main 


ostream& operator<<(ostream& os, const Fraction& rhs) { // overload operator << for Fraction
    os << rhs.num << "/" << rhs.den << endl;
    return os;
} 
