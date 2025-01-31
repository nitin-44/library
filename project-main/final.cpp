#include <iostream>
using namespace std;

class Library {
private:
    struct Book {
        int id;
        string name, author;
        Book* next;
    };

    Book* head = nullptr;

public:
    void menu();
    void insertBook();
    void searchBook();
    void updateBook();
    void deleteBook();
    void displayBooks();
    void sortBooks();
};

void Library::menu() {
    while (true) {
        system("cls");
        int choice;

        cout << "==============================================" << endl;
        cout << "         LIBRARY MANAGEMENT SYSTEM           " << endl;
        cout << "==============================================" << endl;
        cout << "1. Insert New Book" << endl;
        cout << "2. Search for a Book" << endl;
        cout << "3. Update Book Information" << endl;
        cout << "4. Delete a Book" << endl;
        cout << "5. Display All Books" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                sortBooks();
                displayBooks();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Library::insertBook() {
    Book* newBook = new Book;
    
    cout << "Enter Book ID: ";
    cin >> newBook->id;
    cin.ignore(); 
    cout << "Enter Book Name: ";
    getline(cin, newBook->name);
    cout << "Enter Author Name: ";
    getline(cin, newBook->author);

    newBook->next = nullptr;

    if (!head) {
        head = newBook;
    } else {
        Book* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newBook;
    }

    cout << "Book added successfully!" << endl;
}

void Library::searchBook() {
    int searchId;
    cout << "Enter Book ID to search: ";
    cin >> searchId;

    Book* current = head;
    bool found = false;

    while (current) {
        if (current->id == searchId) {
            cout << "Book ID: " << current->id << endl;
            cout << "Book Name: " << current->name << endl;
            cout << "Author: " << current->author << endl;
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Book not found with ID " << searchId << endl;
    }
}

void Library::updateBook() {
    int updateId;
    cout << "Enter Book ID to update: ";
    cin >> updateId;

    Book* current = head;
    bool found = false;

    while (current) {
        if (current->id == updateId) {
            cout << "Enter New Book Name: ";
            cin.ignore();
            getline(cin, current->name);
            cout << "Enter New Author Name: ";
            getline(cin, current->author);
            cout << "Book information updated successfully!" << endl;
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Book not found with ID " << updateId << endl;
    }
}

void Library::deleteBook() {
    int deleteId;
    cout << "Enter Book ID to delete: ";
    cin >> deleteId;

    if (!head) {
        cout << "Library is empty." << endl;
        return;
    }

    if (head->id == deleteId) {
        Book* temp = head;
        head = head->next;
        delete temp;
        cout << "Book deleted successfully!" << endl;
        return;
    }

    Book* current = head->next;
    Book* previous = head;

    while (current) {
        if (current->id == deleteId) {
            previous->next = current->next;
            delete current;
            cout << "Book deleted successfully!" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }

    cout << "Book not found with ID " << deleteId << endl;
}

void Library::displayBooks() {
    if (!head) {
        cout << "Library is empty." << endl;
        return;
    }

    cout << "List of Books:" << endl;
    Book* current = head;

    while (current) {
        cout << "Book ID: " << current->id << endl;
        cout << "Book Name: " << current->name << endl;
        cout << "Author: " << current->author << endl;
        cout << "--------------------------" << endl;
        current = current->next;
    }
}

void Library::sortBooks() {

    if (!head || !head->next) {
        return; 
    }

    bool swapped;
    do {
        swapped = false;
        Book* current = head;
        Book* nextNode = head->next;
        while (nextNode) {
            if (current->id > nextNode->id) {
                
                int tempId = current->id;
                string tempName = current->name;
                string tempAuthor = current->author;

                current->id = nextNode->id;
                current->name = nextNode->name;
                current->author = nextNode->author;

                nextNode->id = tempId;
                nextNode->name = tempName;
                nextNode->author = tempAuthor;

                swapped = true;
            }
            current = current->next;
            nextNode = nextNode->next;
        }
    } while (swapped);
}

int main() {
    Library library;
    library.menu();
    return 0;
}