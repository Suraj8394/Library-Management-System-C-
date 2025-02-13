#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book Class
class Book {
public:
    string title, author;
    int copies;

    Book(string t, string a, int c) {
        title = t;
        author = a;
        copies = c;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;

public:
    // Add a new book
    void addBook(string title, string author, int copies) {
        books.push_back(Book(title, author, copies));
        cout << "Book added successfully!\n";
    }

    // Search for a book
    void searchBook(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                cout << "Book Found!\nTitle: " << book.title 
                     << "\nAuthor: " << book.author 
                     << "\nCopies Available: " << book.copies << "\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Borrow a book
    void borrowBook(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                if (book.copies > 0) {
                    book.copies--;
                    cout << "Book borrowed successfully! Remaining copies: " << book.copies << "\n";
                } else {
                    cout << "Book is out of stock!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Return a book
    void returnBook(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                book.copies++;
                cout << "Book returned! Total copies: " << book.copies << "\n";
                return;
            }
        }
        cout << "Book not found in our records!\n";
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library!\n";
            return;
        }

        cout << "Available Books:\n";
        for (auto &book : books) {
            cout << "Title: " << book.title 
                 << ", Author: " << book.author 
                 << ", Copies: " << book.copies << "\n";
        }
    }
};

// Main Program
int main() {
    Library lib;
    int choice;
    string title, author;
    int copies;

    while (true) {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n2. Search Book\n3. Borrow Book\n4. Return Book\n5. Display All Books\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Author Name: ";
                getline(cin, author);
                cout << "Enter Number of Copies: ";
                cin >> copies;
                lib.addBook(title, author, copies);
                break;
            case 2:
                cout << "Enter book title to search: ";
                getline(cin, title);
                lib.searchBook(title);
                break;
            case 3:
                cout << "Enter book title to borrow: ";
                getline(cin, title);
                lib.borrowBook(title);
                break;
            case 4:
                cout << "Enter book title to return: ";
                getline(cin, title);
                lib.returnBook(title);
                break;
            case 5:
                lib.displayBooks();
                break;
            case 6:
                cout << "Exiting Library Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
