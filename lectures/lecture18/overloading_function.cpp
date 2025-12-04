// Sample 2

/*
Sample code for Overloading
*/
#include <iostream>
#include <string>
using namespace std;

class Addition{
    private:
    public:
        Addition() {}
        int add(int a, int b) { return a + b; }
        double add(double a, double b) { return a + b; }
        string add(const string& a, const string& b) { return a + b; }
};

int main() {
    Addition adding;
    cout << adding.add(1, 2) << endl; 
    cout << adding.add(1.4, 2.5) << endl;
    cout << adding.add("Hello", "-World") << endl;
}