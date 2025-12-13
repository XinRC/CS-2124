// map
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> name_ages;
    name_ages["Leon"] = 21;
    name_ages["Ada"] = 24;
    name_ages.insert({"Claire", 19});

    // accessing element:
    cout << "Leon's age: " << name_ages["Leon"] << "\n" << endl;

    cout << "// ==================== // \n" << endl;
    for (const auto& pair : name_ages) {
        cout << pair.first << " is " << pair.second << " years old." << endl;
    }
}