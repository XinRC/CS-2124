#include <iostream>
#include <vector>
#include <string>
using namespace std;

// YOUR CODE GOES HERE - Implement these classes:
/*
Books have title, author, ISBN, and availability status
Members have name, ID, and can borrow/return books
Track which books are borrowed by which members
Prevent borrowing if book is already taken -> ptr 
*/

class Book {
    friend ostream& operator<<(ostream& os, const Book& rhs) {
        os << rhs.title << " by " << rhs.author << "(" << rhs.ISBN << ") - ";
        if (rhs.borrowed_by == nullptr) {
            os << "Avaliable";
        } else {
            os << rhs.borrowed_by; // ===============================Get name of nonavaliable 
        }
    }
    private: 
        string title;
        string author;
        const string& ISBN;
        Member* borrowed_by = nullptr; 
    public:
        Book(const string& title, const string& author, const string& ISBN) 
            : title(title), author(author), ISBN(ISBN) {}
        
};
class Member {
    friend ostream& operator<<(ostream& os, const Member& rhs) {
        os << rhs.name << " (ID:" << rhs.id << ")";
    }
    private:
        string name;
        string id; 
        int borrowed_amount;
    public:
        Member(const string& name, const string& id) 
            : name(name), id(id), borrowed_amount(0) {}
        // getter / setters:
        const string& getName() const { return name; }
        int getBorrowed() const { return borrowed_amount; }
        
}; 
class Library {
    private:
        vector<Book*> bookLibrary;
        vector<Member*> memberList; 
    public:
        Library() {}
        // addBook
        void addBook(const string& name, const string& author, const string& ISBN) {
            Book* book = new Book(name, author, ISBN);
            bookLibrary.push_back(book); 
        }
        // registerMember
        void registerMember(const string& name, const string id) {
            Member* member = new Member(name, id);
            memberList.push_back(member);
        }
        // borrowBook
        // displayAllBooks
        void displayAllBooks() {
            cout << "BOOKS" << endl;
            for(size_t i = 0; i < bookLibrary.size(); ++i) {
                cout << i << ". " << *bookLibrary[i] << endl; 
            }
        }
        // displayAllMembers
        void displayAllMembers() {
            cout << "MEMBERS:" << endl;
            for(size_t i = 0; i < memberList.size() << ++i) {
                cout << memberList[i] << ""
            }
        }
        // returnBook
};

int main() {
    // Create library
    Library library;
    
    // Add books to library -> void
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "12345");
    library.addBook("1984", "George Orwell", "67890");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "11121");
    
    // Register members -> void
    library.registerMember("Alice Johnson", "M001");
    library.registerMember("Bob Smith", "M002");
    
    // Test operations
    cout << "=== LIBRARY STATUS ===" << endl;
    library.displayAllBooks();
    library.displayAllMembers();
    
    cout << "\n=== BORROWING BOOKS ===" << endl;
    library.borrowBook("M001", "12345");  // Alice borrows Gatsby
    library.borrowBook("M002", "67890");  // Bob borrows 1984
    
    cout << "\n=== ATTEMPT DUPLICATE BORROW ===" << endl;
    library.borrowBook("M001", "67890");  // Try to borrow already taken book
    
    cout << "\n=== CURRENT STATUS ===" << endl;
    library.displayAllBooks();
    
    cout << "\n=== RETURNING BOOK ===" << endl;
    library.returnBook("M001", "12345");  // Alice returns Gatsby
    
    cout << "\n=== FINAL STATUS ===" << endl;
    library.displayAllBooks();
    library.displayAllMembers();
    
    return 0;
}


/* OUTPUT
=== LIBRARY STATUS ===
BOOKS:
1. The Great Gatsby by F. Scott Fitzgerald (ISBN: 12345) - Available
2. 1984 by George Orwell (ISBN: 67890) - Available  
3. To Kill a Mockingbird by Harper Lee (ISBN: 11121) - Available

MEMBERS:
Alice Johnson (ID: M001) - 0 books borrowed
Bob Smith (ID: M002) - 0 books borrowed

=== BORROWING BOOKS ===
Alice Johnson borrowed 'The Great Gatsby'
Bob Smith borrowed '1984'

=== ATTEMPT DUPLICATE BORROW ===
Cannot borrow '1984' - Book already borrowed by Bob Smith

=== CURRENT STATUS ===
BOOKS:
1. The Great Gatsby by F. Scott Fitzgerald (ISBN: 12345) - Borrowed by Alice Johnson
2. 1984 by George Orwell (ISBN: 67890) - Borrowed by Bob Smith
3. To Kill a Mockingbird by Harper Lee (ISBN: 11121) - Available

=== RETURNING BOOK ===
Alice Johnson returned 'The Great Gatsby'

=== FINAL STATUS ===
BOOKS:
1. The Great Gatsby by F. Scott Fitzgerald (ISBN: 12345) - Available
2. 1984 by George Orwell (ISBN: 67890) - Borrowed by Bob Smith
3. To Kill a Mockingbird by Harper Lee (ISBN: 11121) - Available

MEMBERS:
Alice Johnson (ID: M001) - 0 books borrowed
Bob Smith (ID: M002) - 1 books borrowed

*/