
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

void printList(const list<int>& lst);
void printListRangedFor(const list<int>& lst);
void printOtherAuto(const list<int>& lst);
list<int>::const_iterator finder(const list<int>& lst, int value);
bool isEven(int value);
list<int>::const_iterator ourFind(const list<int>& lst, int value); 


// apparently cannot forward declare auto -> still statically typed but cleaner to look at
auto autoFinder(const list<int>& lst, int value) { // apparently cannot forward declare auto
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return lst.end();
}

template <typename T, typename U> 
T ourFindTemplate(T start, T end, U value) {
    cout << "Xin's TEMPLATE ourFind" << endl;
    for (T iter = start; iter != end; ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return end;
}


// =========================== MAIN =========================== //
int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec = {3,7,10,9,5,6,2,8,4,1};
    for (int value : vec) {
        cout << value << " "; 
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> lst(vec.begin(), vec.end());
    for (int value : lst) {
        cout << value << " ";
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec.begin(), vec.end());
    cout << "Sorted Vector: ";
    for (int value : vec) {
        cout << value << " ";
    }
    cout << "\nList: ";
    for (int value : lst) {
        cout << value << " "; 
    }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < vec.size(); i += 2) {
        cout << vec[i] << " "; 
    }
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    /* Can't use [] (aka indexing) with a linked list
    for (size_t i = 0; i < lst.size(); i += 2) {
        cout << lst[i] << " ";
    }
    */
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = vec.begin(); iter < vec.end(); iter += 2) {
        cout << *iter << " "; 
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    bool to_print = true;
    for (list<int>::iterator iter = lst.begin(); iter != lst.end(); ++++iter) {
        cout << *iter << " "; 
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    cout << "Before sort: ";
    for (int val : lst) {
        cout << val << " ";
    }
    lst.sort();
    cout << "\nAfter sort: ";
    for (int val : lst) {
        cout << val << " ";
    }
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

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printOtherAuto(lst); 
    cout << "=======\n";

    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator found = finder(lst, 5);
    // test one
    if (found != lst.end()) {
        cout << "FOUND: " << *found << endl;
    } else {
        cout << "NOT FOUND" << endl; 
    }
    // test two
    found = finder(lst, 55);
    if (found != lst.end()) {
        cout << "FOUND: " << *found << endl;
    } else {
        cout << "NOT FOUND" << endl; 
    }

    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto auto_found = autoFinder(lst, 6);
    if (auto_found != lst.end()) {
        cout << "FOUND: " << *auto_found << endl;
    } else {
        cout << "NOT FOUND";
    }
    auto_found = autoFinder(lst, 19);
    if (auto_found != lst.end()) {
        cout << "FOUND: " << *auto_found << endl;
    } else {
        cout << "NOT FOUND" << endl; 
    }
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator find_result = find(lst.begin(), lst.end(), 5);
    if (find_result != lst.end()) {
        cout << "FOUND: " << *find_result << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
    find_result = find(lst.begin(), lst.end(), 66);
    if (find_result != lst.end()) {
        cout << "FOUND: " << *find_result << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    vector<int>::iterator find_if_result = find_if(vec.begin(), vec.end(), isEven);
    if (find_if_result != vec.end()) {
        cout << "FIRST EVEN IN VECTOR: " << *find_if_result << endl;
    } else {
        cout << "NO EVEN" << endl;
    }
    cout << "=======\n";

    // 16. Lambda
    cout << "Task 16:\n";
    [] { cout << "Hello Lambda!\n"; }(); // [captured] (parameters) {code} (inputted parameteres)
    vector<int>::iterator evenLambda = find_if(vec.begin(), vec.end(), [](int n){ return n % 2 == 0; });
    if (evenLambda != vec.end()) {
        cout << "FIRST EVEN IN VECTOR (using lambda): " << *evenLambda;
    } else {
        cout << "NO EVEN" << endl;
    }
    cout << "\n=======\n";

    // 17. Lambda capture
    cout << "Task 17:\n";
    int divisor;
    cout << "What divisor to use: ";
    cin >> divisor;
    vector<int>::iterator divisor_result = find_if(vec.begin(), vec.end(),
                            [divisor](int n){ return n % divisor == 0; });
    if (divisor_result != vec.end()) {
        cout << "1ST NUMBER DIVIDED BY " << divisor << " RESULTS IN: " 
            << *divisor_result << endl;
    } else {
        cout << "NO NUMBER CAN BE DIVIDED BY " << divisor << endl;
    }
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[vec.size()];
    copy(vec.begin(), vec.end(), arr);
    cout << "Array Elements: " << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << arr[i] << " "; 
    }
    cout << endl;

    int* t18_find_result = find(arr, arr + vec.size(), 5);
    if (t18_find_result != (arr + vec.size())) {
        cout << "FOUND IN ARR: " << *t18_find_result << endl;
    } else {
        cout << "NOT FOUND IN ARR: " << endl; 
    }
    delete[] arr;
    
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::const_iterator our_result = ourFind(lst, 7);
    if (our_result != lst.end()) {
        cout << "FOUND: " << *our_result << endl;
    } else {
        cout << "NOT FOUND" << endl; 
    }

    our_result = ourFind(lst, 24);
    if (our_result != lst.end()) {
        cout << "FOUND: " << *our_result << endl;
    } else {
        cout << "NOT FOUND" << endl; 
    }
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    vector<int>::iterator our_template_result = ourFindTemplate(vec.begin(), vec.end(), 5);
    if (our_template_result != vec.end()) {
        cout << "FOUND: " << *our_template_result << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    vector<int>::iterator our_template2_result = ourFindTemplate(vec.begin(), vec.end(), 55);
    if (our_template2_result != vec.end()) {
        cout << "FOUND: " << *our_template2_result << endl;
    } else {
        cout << "NOT FOUND" << endl;
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
        cerr << "No file read" << endl; // just error checking
        return -1;
    }

    string word;
    while (file >> word) {
        if (find(words.begin(), words.end(), word) == words.end()) { // if cant find word
            words.push_back(word);
        }
    } file.close(); 

    cout << "First 30 words: ";
    for (size_t i = 0; i < min(words.size(), size_t(30)); ++i) {
        cout << words[i] << " ";
    }
    cout << endl;

    // special words:
    cout << "Unique Words: " << words.size() << endl; 

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> setWords;
    file.open("pooh-nopunc.txt");

    if (!file) {
        cerr << "No file found" << endl;
        return -1;
    }
    while (file >> word) {
        setWords.insert(word);
    } file.close();


    cout << "First 30 words: ";
    for (size_t i = 0; i < min(setWords.size(), size_t(30)); ++i) {
        cout << words[i] << " ";
    }
    cout << endl;

    cout << "Unique words: " << setWords.size() << endl; 

    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    file.open("pooh-nopunc.txt");
    if (!file) {
        cerr << "Cannot open file" << endl;
        return -1;
    }

    int position = 1;
    while (file >> word) {
        wordMap[word].push_back(position);
        ++position;
    } file.close();

    
    for (const auto& key : wordMap) {
        cout << key.first << ": ";
        for (int position : key.second) {
            cout << position << " ";
        }
        cout << endl;
     }
     

    cout << "=======\n";
}  // main


void printList(const list<int>& lst) {
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

void printListRangedFor(const list<int>& lst) {
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

void printOtherAuto(const list<int>& lst) {
    for (auto iter = lst.begin(); iter != lst.end(); ++++iter) {
        cout << *iter << " "; 
    }
    cout << endl;
}

list<int>::const_iterator finder(const list<int>& lst, int value) { 
    // using the const_iterator ensures will not modify content 
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return lst.end();
}

bool isEven(int value) { return value % 2 == 0; }

list<int>::const_iterator ourFind(const list<int>& lst, int value){
    cout << "Xin's ourFind func" << endl;
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return lst.end();
}