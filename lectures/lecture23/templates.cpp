/*
The .cpp will look into templates and their usage. Templates in C++ is very 
similar to operator overloading for different types. However instead of 
having different actions for each different type, no matter the type, the 
action would be the same
*/

#include <iostream>
using namespace std;

// creating the function template
template <typename T>
void printingItem(T item) { cout << item << endl; }

// creating class template
template <typename T, typename Q>
class Box{
    private:
        T t_variable;
        Q q_variable;
    public:
        Box(const T& t_var, const Q& q_var) : t_variable(t_var), q_variable(q_var) {} 

        // getters:
        T get_t() const { return t_variable; }
        Q get_q() const { return q_variable; }

        // setters:
        void set_t(const T& t_var) { t_variable = t_var; }
        void set_q(const Q& q_var) { q_variable = q_var; }
        
        // methods
        void print_box() const { cout << t_variable << " : " << q_variable << endl; }
};

int main() {
    printingItem(9.8);
    printingItem("Word");
    printingItem(6);
    printingItem(false);
}