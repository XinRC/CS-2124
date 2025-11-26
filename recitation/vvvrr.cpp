// rec13_start.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

// Task 9: Function to print list using const_iterator
void printList(const list<int>& lst) {
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

// Task 10: Function to print list using ranged-for
void printListRangedFor(const list<int>& lst) {
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

// Task 11: Function to print every other item using auto
void printEveryOtherAuto(const list<int>& lst) {
    bool print = true;
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) { // AUTO allowed here
        if (print) {
            cout << *iter << " ";
        }
        print = !print;
    }
    cout << endl;
}

// Task 12: Function to find item in list (without auto)
list<int>::const_iterator ourFind(const list<int>& lst, int value) {
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return lst.end();
}

// Task 13: Function to find item in list (with auto)
auto ourFindAuto(const list<int>& lst, int value) { // AUTO allowed here
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) { // AUTO allowed here
        if (*iter == value) {
            return iter;
        }
    }
    return lst.end();
}

// Task 19: ourFind for lists of ints
list<int>::const_iterator ourFindList(const list<int>& lst, int value) {
    cout << "ourFind for lists" << endl;
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return lst.end();
}

// Task 20: ourFind as template
template<typename T, typename U>
T ourFindTemplate(T start, T end, U value) {
    cout << "ourFind template" << endl;
    for (T iter = start; iter != end; ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return end;
}

// Function to check if a number is even (for Task 15)
bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec = {5, 3, 8, 1, 9, 2, 7, 4, 6, 0};
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 2. Initialize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> lst(vec.begin(), vec.end());
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 3. Sort the original vector. Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "List: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < vec.size(); i += 2) {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the same technique.
    cout << "Task 5:\n";
    cout << "Cannot use index operator with list" << endl;

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators. Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = vec.begin(); iter < vec.end(); iter += 2) {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list. Again, do not use auto.
    cout << "Task 7:\n";
    bool print = true;
    for (list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (print) {
            cout << *iter << " ";
        }
        print = !print;
    }
    cout << endl;

    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    cout << "Before sorting: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    lst.sort();
    cout << "After sorting: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printList(lst);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListRangedFor(lst);

    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alternate items in the list
    cout << "Task 11:\n";
    printEveryOtherAuto(lst); // Uses auto internally as specified

    cout << "=======\n";

    
    // 12. Write a function find that takes a list and value to search for.
    cout << "Task 12:\n";
    list<int>::const_iterator found = ourFind(lst, 5);
    if (found != lst.end()) {
        cout << "Found: " << *found << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    found = ourFind(lst, 99);
    if (found != lst.end()) {
        cout << "Found: " << *found << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "=======\n";

    // 13. Write a function find that takes a list and value to search for.
    cout << "Task 13:\n";
    auto foundAuto = ourFindAuto(lst, 5); // AUTO allowed here as specified
    if (foundAuto != lst.end()) {
        cout << "Found: " << *foundAuto << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator result = find(lst.begin(), lst.end(), 5);
    if (result != lst.end()) {
        cout << "Found: " << *result << endl;
    } else {
        cout << "Not found" << endl;
    }

    result = find(lst.begin(), lst.end(), 99);
    if (result != lst.end()) {
        cout << "Found: " << *result << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    vector<int>::iterator evenResultVec = find_if(vec.begin(), vec.end(), isEven);
    if (evenResultVec != vec.end()) {
        cout << "First even in vector: " << *evenResultVec << endl;
    } else {
        cout << "No even number found in vector" << endl;
    }

    list<int>::iterator evenResultList = find_if(lst.begin(), lst.end(), isEven);
    if (evenResultList != lst.end()) {
        cout << "First even in list: " << *evenResultList << endl;
    } else {
        cout << "No even number found in list" << endl;
    }

    cout << "=======\n";

    // 16. Lambda
    cout << "Task 16:\n";
    auto evenLambda = find_if(vec.begin(), vec.end(), // AUTO allowed with lambdas
                             [](int n) { return n % 2 == 0; });
    if (evenLambda != vec.end()) {
        cout << "First even (lambda): " << *evenLambda << endl;
    } else {
        cout << "No even number found" << endl;
    }

    cout << "=======\n";

    // 17. Lambda capture
    cout << "Task 17:\n";
    int divisor;
    cout << "Enter a divisor to check divisibility: ";
    cin >> divisor;
    
    auto divisibleResult = find_if(vec.begin(), vec.end(), // AUTO allowed with lambdas
                                  [divisor](int n) { return n % divisor == 0; });
    if (divisibleResult != vec.end()) {
        cout << "First number divisible by " << divisor << ": " << *divisibleResult << endl;
    } else {
        cout << "No number divisible by " << divisor << " found" << endl;
    }

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[vec.size()];
    copy(vec.begin(), vec.end(), arr);
    
    cout << "Array contents: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Use find on array
    int* arrResult = find(arr, arr + vec.size(), 5);
    if (arrResult != arr + vec.size()) {
        cout << "Found in array: " << *arrResult << endl;
    } else {
        cout << "Not found in array" << endl;
    }
    
    delete[] arr;

    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    found = ourFindList(lst, 5);
    if (found != lst.end()) {
        cout << "Found: " << *found << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    vector<int>::iterator templateResult = ourFindTemplate(vec.begin(), vec.end(), 5);
    if (templateResult != vec.end()) {
        cout << "Found in vector: " << *templateResult << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    list<int>::iterator templateResult2 = ourFindTemplate(lst.begin(), lst.end(), 5);
    if (templateResult2 != lst.end()) {
        cout << "Found in list: " << *templateResult2 << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> words;
    ifstream file("pooh-nopunc.txt");
    if (!file) {
        cerr << "Error: Could not open pooh-nopunc.txt" << endl;
        return 1;
    }
    
    string word;
    while (file >> word) {
        if (find(words.begin(), words.end(), word) == words.end()) {
            words.push_back(word);
        }
    }
    file.close();
    
    cout << "Distinct words: " << words.size() << endl;

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> wordSet;
    file.open("pooh-nopunc.txt");
    if (!file) {
        cerr << "Error: Could not open pooh-nopunc.txt" << endl;
        return 1;
    }
    
    while (file >> word) {
        wordSet.insert(word);
    }
    file.close();
    
    cout << "Distinct words: " << wordSet.size() << endl;

    cout << "=======\n";

    // 23. Word co-occurrence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    file.open("pooh-nopunc.txt");
    if (!file) {
        cerr << "Error: Could not open pooh-nopunc.txt" << endl;
        return 1;
    }
    
    int position = 1;
    while (file >> word) {
        wordMap[word].push_back(position);
        ++position;
    }
    file.close();
    
    for (const auto& entry : wordMap) { // AUTO allowed with ranged-for over map
        cout << entry.first << ": ";
        for (int pos : entry.second) {
            cout << pos << " ";
        }
        cout << endl;
    }

    cout << "=======\n";
}