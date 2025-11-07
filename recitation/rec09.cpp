#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    virtual void displayNumPages() const = 0; 
    /* would not compile since cant create objects of an abstract class
    but does not have an overrider for novel/some dervied classes
    */
private:
    unsigned numOfPages; // can also make this item a protected
}; // PrintedMaterial

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
} // PrintedMaterial's displayNumPages

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
    void displayNumPages() const {
        cout << "Magazine's virtual override: ";
        PrintedMaterial::displayNumPages();
    }
private:
}; // Magazine

class Book : public PrintedMaterial {
public:
    // Book(unsigned numPages) : PrintedMaterial(numPages) {}
    using PrintedMaterial::PrintedMaterial;
private:
}; // Book

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs ) 
        : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "Textbook's virtual override:" << endl;
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
}; // Textbook

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
    void displayNumPages() const {
        cout << "Novel's virtual override: ";
        PrintedMaterial::displayNumPages();
    }
private:
}; // Novel


// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);
    // cannot create a Book object since no virtual override

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "\n===========\n\n";

    // cout << "\n A PrintedMaterial material object!\n" << endl;
    // cant do 
    //PrintedMaterial pm(2345);
    //pm.displayNumPages();
    //pm = text; // like putting a Textbook into a PrintedMaterial
    //pm.displayNumPages();

    // vectors:
    vector <PrintedMaterial*> pmVector;
    pmVector.push_back(&text);
    pmVector.push_back(&novel);
    pmVector.push_back(&mag);

    // for index-based:
    for (size_t i = 0; i < pmVector.size(); i++) {
        pmVector[i]->displayNumPages();
    }

    cout << endl;
    cout << "=====================\n";

    // range-for loop:
    for (PrintedMaterial* index : pmVector) {
        index->displayNumPages();
    }


}


/* UML 

[Printed Material]
        ^/      ^\
[Magazine]      [Book]
                ^/  ^\
          [Novel]    [Textbook]

*/

/* Pure Virtual Function Notes: 
> It disallows objects to be created unless the derived class of the object has an
override for specific virtual function. If it doesn't, you can't create an object of
that class.

> No need for a body {}, just put the = 0; after the () or const

*/

/* Slicing Notes:
> When not everything is copied over from base to derived. 
> Occurs when pass by value in vector, we can use pointers instead

*/