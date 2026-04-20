#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    void setBookDetails(string t, string a, string i, bool available) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = available;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "--------------------------" << endl;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "This book is already borrowed." << endl;
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "This book was not borrowed." << endl;
        }
    }

    string getISBN() {
        return isbn;
    }
};

int main() {
    Book library[5];

    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "111", true);
    library[1].setBookDetails("1984", "George Orwell", "222", true);
    library[2].setBookDetails("To Kill a Mockingbird", "Harper Lee", "333", true);
    library[3].setBookDetails("Pride and Prejudice", "Jane Austen", "444", true);
    library[4].setBookDetails("Moby Dick", "Herman Melville", "555", true);

    int choice;
    string inputISBN;

    do {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < 5; i++) {
                library[i].displayBookDetails();
            }
            break;

        case 2:
            cout << "Enter ISBN to borrow: ";
            cin >> inputISBN;
            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    library[i].borrowBook();
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter ISBN to return: ";
            cin >> inputISBN;
            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    library[i].returnBook();
                    break;
                }
            }
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option." << endl;
        }

    } while (choice != 4);

    return 0;
}
