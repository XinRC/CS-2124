#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility> 
using namespace std;


// structure of Hydrocarbon
struct Hydrocarbon {
    vector<string> names;  
    int carbon;
    int hydrogen;
};


// protoyping functions
void openFile(ifstream& file);
void fillVector(ifstream& file, vector<Hydrocarbon>& hydrocarbons);
void insertInformation(vector<Hydrocarbon>& hydrocarbons, const string& name, int carbon, int hydrogen);
size_t findFormula(const vector<Hydrocarbon>& hydrocarbons, int carbon, int hydrogen);
void printVector(const vector<Hydrocarbon>& hydrocarbons);
void sortVector(vector<Hydrocarbon>& hydrocarbons);
void printFormula(const Hydrocarbon& formula);

// main function:
int main(){
    ifstream file;
    vector<Hydrocarbon> hydrocarbon; 
    
    //Filename: hydrocarbs.txt 
    //hydrocarbs.txt
    openFile(file);
    fillVector(file, hydrocarbon);
    file.close();
    cout << endl;

    // unsorted:
    cout << "Unsorted: \n" << endl;
    printVector(hydrocarbon);
    cout << endl;

    cout << "Sorted: \n" << endl;
    // sorted:
    sortVector(hydrocarbon);
    printVector(hydrocarbon);

    return 0;
}


// function to open file
void openFile(ifstream& file){
    string filename;
    cout << "File name: ";
    cin >> filename;

    file.open(filename);
    while (!file.is_open()) {
        cout << "File cannot be opened. Retry: ";
        cin >> filename;
        file.open(filename);
    }
}


// function to in fill vector
void fillVector(ifstream& file, vector<Hydrocarbon>& hydrocarbons) {
    string name;
    char carbon_char, hydrogen_char;
    int carbon_int, hydrogen_int;

    // Seperates text file to str, char, int, char, int
    while (file >> name >> carbon_char >> carbon_int >> hydrogen_char >> hydrogen_int) {
        // initializes carbon and hydrogen values


        insertInformation(hydrocarbons, name, carbon_int, hydrogen_int);
    }
}

// function to create new hydrocarbon or push back
void insertInformation(vector<Hydrocarbon>& hydrocarbons, const string& name, int carbon, int hydrogen) {
    int index = findFormula(hydrocarbons, carbon, hydrogen);

    if (index < hydrocarbons.size()) {
        // forumla exists already: 
        hydrocarbons[index].names.push_back(name);
    } else {
        // create a new entry if curr does not exist
        Hydrocarbon newEntry;
        newEntry.names.push_back(name);
        newEntry.carbon = carbon;
        newEntry.hydrogen = hydrogen;
        hydrocarbons.push_back(newEntry);
    }
}

// ensures vector[i] of C/H is equal to return the i -> formual
size_t findFormula(const vector<Hydrocarbon>& hydrocarbons, int carbon, int hydrogen) {
    for (int i = 0; i < hydrocarbons.size(); ++i) {
        if (hydrocarbons[i].carbon == carbon && hydrocarbons[i].hydrogen == hydrogen) {
            return i;
        }
    }
    return hydrocarbons.size(); // return size if none found
}


// prints out amt of C/H 
void printFormula(const Hydrocarbon& formula) {
    cout << "C" << formula.carbon << "H" << formula.hydrogen << "  ";
    
    for (int i = 0; i < formula.names.size(); ++i) {
        cout << formula.names[i];

        if (i < formula.names.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// calls previous function 
void printVector(const vector<Hydrocarbon>& hydrocarbons) {
    for (int i = 0; i < hydrocarbons.size(); ++i) {
        printFormula(hydrocarbons[i]);
    }

}


void sortVector(vector<Hydrocarbon>& hydrocarbons) {
    // Use selection sort
    for (int i = 0; i < hydrocarbons.size() - 1; ++i) {
        int min_index = i;
        for ( int j = i + 1; j < hydrocarbons.size(); ++j) {
            // comparing carbons
            if (hydrocarbons[j].carbon < hydrocarbons[min_index].carbon) {
                min_index = j;
            } else if (hydrocarbons[j].carbon == hydrocarbons[min_index].carbon) { 
                // comparing hydrogens if carbons is the same
                if (hydrocarbons[j].hydrogen < hydrocarbons[min_index].hydrogen) {
                    min_index = j;
                } 
            }
        }
    if (min_index != i) {
        swap(hydrocarbons[i], hydrocarbons[min_index]);
    }
    }
}


// Code Reading Question:
// 1 4 9 16