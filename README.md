# **📌 Library Management System (C++)**  

A **simple and interactive Library Management System** built using **C++**, allowing users to **add books, search for books, borrow books, return books, and display available books** through a **menu-driven** interface.  

---

## **🚀 Features**  
✔️ **Add new books** to the library  
✔️ **Search for books** by title or author  
✔️ **Borrow books** (reduces available copies)  
✔️ **Return books** (increases available copies)  
✔️ **Display all available books**  
✔️ **User-friendly menu-driven system**  

---

## **📂 Project Structure**  
📦 Library Management System  


## **📌 Code Breakdown**

### **1️⃣ Book Class (Represents an individual book)**
This class contains **private attributes** for book details and **public methods** to access and modify them.

```cpp
class Book {
private:
    string title;
    string author;
    int copies;
```
- **`title`** → Stores the book’s name.  
- **`author`** → Stores the book’s author.  
- **`copies`** → Keeps track of available copies.  

```cpp
public:
    Book(string t, string a, int c) : title(t), author(a), copies(c) {}
```
- **Constructor** initializes a book object with a title, author, and number of copies.  

```cpp
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getCopies() { return copies; }
```
- **Getter functions** return book details.

```cpp
    void borrowBook() {
        if (copies > 0) {
            copies--;
            cout << "Book borrowed successfully!\n";
        } else {
            cout << "Book is out of stock!\n";
        }
    }
```
- **`borrowBook()`** → Decreases `copies` by 1 if available; otherwise, shows an error message.

```cpp
    void returnBook() {
        copies++;
        cout << "Book returned successfully!\n";
    }
```
- **`returnBook()`** → Increases `copies` when a book is returned.

---

### **2️⃣ Library Class (Manages the collection of books)**
This class maintains a **vector** of `Book` objects and provides functions to **add, search, borrow, return, and display books**.

```cpp
class Library {
private:
    vector<Book> books;
```
- **`vector<Book>`** → Stores all books in a dynamic list.

```cpp
public:
    void addBook(string title, string author, int copies) {
        books.push_back(Book(title, author, copies));
        cout << "Book added successfully!\n";
    }
```
- **`addBook()`** → Adds a new book to the library.

```cpp
    void searchBook(string title) {
        for (auto &book : books) {
            if (book.getTitle() == title) {
                cout << "Book Found: " << book.getTitle() << " by " << book.getAuthor() << " | Copies: " << book.getCopies() << "\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }
```
- **`searchBook()`** → Finds a book by title and displays its details.

```cpp
    void borrowBook(string title) {
        for (auto &book : books) {
            if (book.getTitle() == title) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }
```
- **`borrowBook()`** → Searches for the book and calls `borrowBook()` to reduce available copies.

```cpp
    void returnBook(string title) {
        for (auto &book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }
```
- **`returnBook()`** → Searches for the book and calls `returnBook()` to increase available copies.

```cpp
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available!\n";
            return;
        }
        for (auto &book : books) {
            cout << "Title: " << book.getTitle() << " | Author: " << book.getAuthor() << " | Copies: " << book.getCopies() << "\n";
        }
    }
};
```
- **`displayBooks()`** → Displays details of all available books.

---

### **3️⃣ Main Function (User Interaction)**
Handles user input and controls the program flow.

```cpp
int main() {
    Library lib;
    int choice;
```
- **Creates a `Library` object** and a menu system.

```cpp
    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n2. Search Book\n3. Borrow Book\n4. Return Book\n5. Display Books\n6. Exit\nEnter your choice: ";
        cin >> choice;
```
- **Displays a menu for user operations.**

```cpp
        string title, author;
        int copies;
        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                lib.addBook(title, author, copies);
                break;
```
- **Case 1**: Adds a new book with user input.

```cpp
            case 2:
                cout << "Enter title to search: ";
                cin.ignore();
                getline(cin, title);
                lib.searchBook(title);
                break;
```
- **Case 2**: Searches for a book by title.

```cpp
            case 3:
                cout << "Enter title to borrow: ";
                cin.ignore();
                getline(cin, title);
                lib.borrowBook(title);
                break;
```
- **Case 3**: Allows users to borrow a book.

```cpp
            case 4:
                cout << "Enter title to return: ";
                cin.ignore();
                getline(cin, title);
                lib.returnBook(title);
                break;
```
- **Case 4**: Allows users to return a book.

```cpp
            case 5:
                lib.displayBooks();
                break;
```
- **Case 5**: Displays all available books.

```cpp
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
```
- **Case 6**: Exits the program.  
- **Default**: Handles invalid inputs.

---


## **🛠 How It Works**
- Users **add books** with title, author, and number of copies.
- They can **search for a book** by title.
- They can **borrow a book** (decreasing available copies).
- They can **return a book** (increasing available copies).
- They can **view all books** in the library.
- The menu runs **in a loop** until the user exits.

---

## **🛠 Example Usage**  
### **📚 Adding a Book**  
**Input:**  
```
Enter Book Title: C++ Programming  
Enter Author Name: Bjarne Stroustrup  
Enter Number of Copies: 5  
```
**Output:**  
```
✅ Book added successfully!
```

### **🔍 Searching for a Book**  
**Input:**  
```
Enter book title to search: C++ Programming  
```
**Output:**  
```
✅ Book Found!  
Title: C++ Programming  
Author: Bjarne Stroustrup  
Copies Available: 5  
```

### **📖 Borrowing a Book**  
**Input:**  
```
Enter book title to borrow: C++ Programming  
```
**Output:**  
```
✅ Book borrowed successfully! Remaining copies: 4  
```

### **📖 Returning a Book**  
**Input:**  
```
Enter book title to return: C++ Programming  
```
**Output:**  
```
✅ Book returned! Total copies: 5  
```

---

## **⏳ Time Complexity Analysis**  
- **Adding a book:** O(1)  
- **Searching for a book:** O(N) (Linear Search)  
- **Borrowing/Returning a book:** O(N)  

---

## **💡 Why This Project?**  
This project is a **great beginner-friendly project** to learn about:  
✔ **C++ Classes and Objects**  
✔ **Vectors for dynamic book storage**  
✔ **File Handling (optional extension for saving book data)**  




---

## **📧 Contact & Contribution**  
📩 **Email:** surajpratap469@gmail.com  
⭐ **If you found this project useful, please star the repository on GitHub!** 🚀  
