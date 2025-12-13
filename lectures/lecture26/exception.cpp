#include <iostream>
#include <stdexcept> // must include this
using namespace std;

int main() {
    try {
        throw runtime_error("Something went wrong...");
    } catch (const runtime_error& e) {
        cout << "Runtime error... " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Generic exception... " << e.what() << endl;
    } catch (...) {
        cout << "Catches unknown exceptions... " << endl;
    }
}
/*\
assert(expression) can be used to test assumptions made by programmers but must be 
included using <assert.h>
*/