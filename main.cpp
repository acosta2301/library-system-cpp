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
        isAvailable = true;
        cout << "Book returned successfully." << endl;
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

    cout << "Library Book List:" << endl;
    cout << "============================" << endl;

    for (int i = 0; i < 5; i++) {
        library[i].displayBookDetails();
    }

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program terminated." << endl;
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                library[i].borrowBook();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found." << endl;
        }
    }

    return 0;
}
