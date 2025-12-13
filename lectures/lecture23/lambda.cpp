/*
The .cpp will look into lambda functions. Lambda functions are small
anonymous functions that can be written directly in the code. This
does not require you to name or declare the function seperately. You can
also pass a lambda function as an argument for another function.

basic Lambda Syntax:
[capture list](parameters){code}; 
where the capture list hast exterior variables the lambda have access to
*/
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; ++i) {
        auto show_img = [&i](){ cout << "Number: " << i << endl; }; // defining lambda func
        show_img(); // calling lambda func
    } 
}