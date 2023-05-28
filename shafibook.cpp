
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class BookShop {
public:
    void controlPanel();
    void addBook();
    void showBooks();
    void checkBook();
    void updateBook();
    void deleteBook();
};

void BookShop::controlPanel() {
    system("cls");
    cout << "___________________________________________________" << endl;
    cout << "|                BOOKSHOP MANAGEMENT               |" << endl;
    cout << "|_________________________________________________|" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                   1. Add Book                    |" << endl;
    cout << "|                   2. Show Books                  |" << endl;
    cout << "|                   3. Check Book                  |" << endl;
    cout << "|                   4. Update Book                 |" << endl;
    cout << "|                   5. Delete Book                 |" << endl;
    cout << "|                   6. Exit                        |" << endl;
    cout << "|_________________________________________________|" << endl;
}

void BookShop::addBook() {
    system("cls");
    ofstream file("books.txt", ios::out|ios::app);
    if (!file) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string bookId, bookTitle, authorName;
    int quantity;

    cout << "Add New Book" << endl;
    cout << "------------" << endl;

    cout << "Book ID: ";
    cin >> bookId;

    cout << "Book Title: ";
    cin.ignore();
    getline(cin, bookTitle);

    cout << "Author Name: ";
    getline(cin, authorName);

    cout << "Quantity: ";
    cin >> quantity;

    file << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;

    file.close();
    cout << "Book added successfully!" << endl;
}

void BookShop::showBooks() {
    system("cls");
    ifstream file("books.txt");
    if (!file) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string bookId, bookTitle, authorName;
    int quantity;

    cout << "Display Books" << endl;
    cout << "-------------" << endl;

    cout << setw(12) << left << "Book ID" << setw(30) << left << "Book Title" << setw(25) << left << "Author Name" << setw(10) << left << "Quantity" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    while (file >> bookId >> bookTitle >> authorName >> quantity) {
        cout << setw(12) << left << bookId << setw(30) << left << bookTitle << setw(25) << left << authorName << setw(10) << left << quantity << endl;
    }

    file.close();
}



void BookShop::checkBook() {
    system("cls");
    ifstream file("books.txt");
    if (!file) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string bookId, bookTitle, authorName, searchId;
    int quantity;
    bool found = false;

    cout << "Check Specific Book" << endl;
    cout << "--------------------" << endl;

    cout << "Enter Book ID: ";
    cin >> searchId;

    while (file >> bookId >> bookTitle >> authorName >> quantity) {
        if (searchId == bookId) {
            cout << "Book ID: " << bookId << endl;
            cout << "Book Title: " << bookTitle << endl;
            cout << "Author Name: " << authorName << endl;
            cout << "Quantity: " << quantity << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Book ID not found!" << endl;
    }
}

void BookShop::updateBook() {
    system("cls");
    ifstream inputFile("books.txt");
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error opening the file." << endl;
        inputFile.close();
        return;
    }

    string bookId, bookTitle, authorName, searchId;
    int quantity;
    bool found = false;

    cout << "Update Book Record" << endl;
    cout << "------------------" << endl;

    cout << "Enter Book ID to update: ";
    cin >> searchId;

    while (inputFile >> bookId >> bookTitle >> authorName >> quantity) {
        if (searchId == bookId) {
            found = true;

            cout << "Enter New Book Title: ";
            cin.ignore();
            getline(cin, bookTitle);

            cout << "Enter New Author Name: ";
            getline(cin, authorName);

            cout << "Enter New Quantity: ";
            cin >> quantity;

            tempFile << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
            cout << "Book updated successfully!" << endl;
        } else {
            tempFile << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cout << "Book ID not found!" << endl;
        remove("temp.txt");
    } else {
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
}

void BookShop::deleteBook() {
    system("cls");
    ifstream inputFile("books.txt");
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error opening the file." << endl;
        inputFile.close();
        return;
    }

    string bookId, bookTitle, authorName, searchId;
    int quantity;
    bool found = false;

    cout << "Delete Book Record" << endl;
    cout << "------------------" << endl;

    cout << "Enter Book ID to delete: ";
    cin >> searchId;

    while (inputFile >> bookId >> bookTitle >> authorName >> quantity) {
        if (searchId == bookId) {
            found = true;
            cout << "Book deleted successfully!" << endl;
        } else {
            tempFile << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cout << "Book ID not found!" << endl;
        remove("temp.txt");
    } else {
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
}


int main() {
    BookShop bookShop;
    int choice;

    while (true) {
        bookShop.controlPanel();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookShop.addBook();
                break;
            case 2:
                bookShop.showBooks();
                break;
            case 3:
                bookShop.checkBook();
                break;
            case 4:
                bookShop.updateBook();
                break;
            case 5:
                bookShop.deleteBook();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice. Please try again!" << endl;
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
