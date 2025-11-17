#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Member;

class Book {
    friend ostream& operator<<(ostream& os, const Book& rhs) {
        os << rhs.title << " by " << rhs.author;
        return os;
    }
    private: 
        string title;
        string author;
        string ISBN;
        Member* borrowed_by = nullptr; 
    public:
        Book(const string& title, const string& author, const string& ISBN) 
            : title(title), author(author), ISBN(ISBN) {}
        const string& getISBN() const { return ISBN; }
        Member* getBorrowedBy() const { return borrowed_by; } //
        void setBorrowedBy(Member* member) { borrowed_by = member ; }
        const string& getTitle() const { return title; }
        
};
class Member {
    friend ostream& operator<<(ostream& os, const Member& rhs) {
        os << rhs.name;
        return os;
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
        const string& getID() const { return id; }
        int getBorrowed() const { return borrowed_amount; }
        void add_borrowed_amount(int value) { borrowed_amount += value; }
        
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
        // displayAllBooks
        void displayAllBooks() {
            cout << "BOOKS" << endl;
            for(size_t i = 0; i < bookLibrary.size(); ++i) {
                cout << i+1 << ". " << *bookLibrary[i] << " (ISBN: " 
                << bookLibrary[i]->getISBN() << ") - ";
                if (bookLibrary[i]->getBorrowedBy() == nullptr) {
                    cout << "Avaliable" << endl;
                } else {
                    cout << "Borrowed by " << bookLibrary[i]->getBorrowedBy()->getName() << endl;
                }
            }
            cout << endl; 
        }

        // displayAllMembers
        void displayAllMembers() {
            cout << "MEMBERS:" << endl;
            for(size_t i = 0; i < memberList.size(); ++i) {
                cout << *memberList[i] << " (ID: " << memberList[i]->getID() 
                    << ")" << " - " << memberList[i]->getBorrowed() 
                    << " books borrowed" << endl;
            }
        }
        // borrowBook
        void borrowBook(const string& id, const string& ISBN) {
            int index_of_borrower = -1;
            for (size_t i = 0; i < memberList.size(); ++i) {
                if (memberList[i]->getID() == id) {
                    index_of_borrower = i;
                }
            }

            for (size_t i = 0; i < bookLibrary.size(); ++i) {
                if (bookLibrary[i]->getISBN() == ISBN) {
                    if (bookLibrary[i]->getBorrowedBy() == nullptr) {
                        memberList[index_of_borrower]->add_borrowed_amount(1);
                        bookLibrary[i]->setBorrowedBy(memberList[index_of_borrower]);
                        cout << memberList[index_of_borrower]->getName() << " borrowed '" 
                            << bookLibrary[i]->getTitle() << "'" << endl; 
                    } else {
                        cout << "Cannot borrow '" << bookLibrary[i]->getTitle()
                            << "' - Book already borrowed by " << *(bookLibrary[i]->getBorrowedBy()) << endl;
                    }
                }
            }
        }

        // returnBook
        void returnBook(const string& id, const string& ISBN) {
            int index_of_borrower;
            for (size_t i = 0; i < memberList.size(); ++i) {
                if (memberList[i]->getID() == id) {
                    if(memberList[i]->getBorrowed() == 0) { return; }
                    index_of_borrower = i; 
                }
            }

            for (size_t i = 0; i < bookLibrary.size(); ++i) {
                if (bookLibrary[i]->getISBN() == ISBN) {
                    if (bookLibrary[i]->getBorrowedBy() == nullptr) { return; }
                    if (bookLibrary[i]->getBorrowedBy() == memberList[index_of_borrower]) {
                        bookLibrary[i]->setBorrowedBy(nullptr); 
                        memberList[index_of_borrower]->add_borrowed_amount(-1);

                        cout << memberList[i]->getName() << " returned '" 
                            << bookLibrary[i]->getTitle() << "'" << endl;
                    }
                }
            }
        }


        ~Library() {
            for (size_t i = 0; i < memberList.size(); ++i) {
                delete memberList[i];
            }
            for (size_t i = 0; i < bookLibrary.size(); ++i) {
                delete bookLibrary[i];
            }

            memberList.clear();
            bookLibrary.clear();
        } 
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
